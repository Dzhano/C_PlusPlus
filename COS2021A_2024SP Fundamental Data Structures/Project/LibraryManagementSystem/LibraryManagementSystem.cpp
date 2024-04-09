#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "KMP.cpp"

using namespace std;

// Data collections
enum Condition { New, Good, Average, Bad, OnTheVergeOfCollapsing, Stolen};
enum Subscription { Free, Basic, Standard, Premium};

vector<string> IDs;

// Functions
void separateDate(string date, int& month, int& day, int& year) {

    // Create a string stream from the date string
    istringstream ss(date);

    // Parsing the date string
    char delimiter = '/';
    ss >> month >> delimiter >> day >> delimiter >> year;
}

void checkYear(int year, string date) {
    if (year < 0000) throw invalid_argument("The year cannot be a negative number.");
    else if (year > 2024) throw invalid_argument("The applied year cannot be in the future!");

    int month, day, otherYear;
    separateDate(date, month, day, otherYear);
    if (otherYear != year) throw invalid_argument("The year cannot be different from the release date's one.");
}

int daysInMonth(int month, int year) {
    if (month == 2)
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

int daysBetweenTwoDates(string oldDate, string laterDate) {
    int oldMonth, oldDay, oldYear;
    separateDate(oldDate, oldMonth, oldDay, oldYear);
    int laterMonth, laterDay, laterYear;
    separateDate(laterDate, laterMonth, laterDay, laterYear);

    int days = 0;
    for (int year = oldYear; year < laterYear; ++year)
        days += ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 366 : 365;

    for (int month = 1; month < laterMonth; ++month) {
        days -= daysInMonth(month, oldYear);
    }
    days -= oldDay;
    for (int month = 1; month < laterMonth; ++month) {
        days += daysInMonth(month, laterYear);
    }
    days += laterDay;
    return days;
}

Condition ConditionFromString(string conditionStr) {
    if (conditionStr == "New") return New;
    else if (conditionStr == "Good") return Good;
    else if (conditionStr == "Average") return Average;
    else if (conditionStr == "Bad") return Bad;
    else if (conditionStr == "OnTheVergeOfCollapsing") return OnTheVergeOfCollapsing;
    else if (conditionStr == "Stolen") return Stolen;
    else throw new invalid_argument("There is no such type of condition for the physical item!");
}


// Classes
class Item { // Abstract class
protected:
    string name;
    string type;
    string ID, description;
    string releaseDate, dateOfReservation, dateOfReturn;

    bool physical;

    void checkID(string id) {
        if (find(IDs.begin(), IDs.end(), id) != IDs.end())
            throw invalid_argument("There is already an item with this ID.");
        else {
            IDs.push_back(id);
            this->ID = id;
        }
    }
public:
    // Constructors
    Item() {
        this->name = "";
        this->type = "item";
        checkID("");
        this->description = "";
        this->releaseDate = "";
        this->dateOfReservation = "";
        this->dateOfReturn = "";

        this->physical = true;
    }

    Item(const string& name, const string& ID, const string& description,
        const string& releaseDate, const string& dateOfReservation, const string& dateOfReturn) {
        this->name = name;
        checkID(ID);
        this->type = "Item";
        this->description = description;
        this->releaseDate = releaseDate;
        this->dateOfReservation = dateOfReservation;
        this->dateOfReturn = dateOfReturn;

        this->physical = true;
    }

    Item(const Item& other) { // Copy constructor
        if (this != &other) {
            this->name = other.name;
            this->ID = other.ID;
            this->type = other.type;
            this->description = other.description;
            this->releaseDate = other.releaseDate;
            this->dateOfReservation = other.dateOfReservation;
            this->dateOfReturn = other.dateOfReturn;

            this->physical = other.physical;
        }
    }

    const Item& operator=(const Item& other) { // assignment operator
        if (this != &other) {
            this->name = other.name;
            this->ID = other.ID;
            this->type = other.type;
            this->description = other.description;
            this->releaseDate = other.releaseDate;
            this->dateOfReservation = other.dateOfReservation;
            this->dateOfReturn = other.dateOfReturn;

            this->physical = other.physical;
        }
        return *this;
    }

    // Methods
    string GetName() const { return name; }
    string GetID() const { return ID; }
    string GetItemType() const { return type; }
    string GetDescription() const { return description; }
    string GetReleaseDate() const { return releaseDate; }
    string GetDateOfReservation() const { return dateOfReservation; }
    string GetDateOfReturn() const { return dateOfReturn; }

    bool IsItPhysicalOrElectronic() const { return physical; }

    bool isLate(string currentDate) {
        // Date format: MM/DD/Year
        int returnMonth, returnDay, returnYear;
        separateDate(dateOfReturn, returnMonth, returnDay, returnYear);
        int currentMonth, currentDay, currentYear;
        separateDate(currentDate, currentMonth, currentDay, currentYear);
        if (currentYear < returnYear) return false;
        else if (currentYear > returnYear) return true;
        else {
            if (currentMonth < returnMonth) return false;
            else if (currentMonth > returnMonth) return true;
            else {
                if (currentDay <= returnDay) return false;
                else return true;
            }
        }
    }
    virtual string CalculateLateFee(string) = 0; // in percentages // Abstract method
};

class Physical : public Item {
protected:
    Condition condition;
public:
    // Constructors
    Physical() : Item() {
        this->condition = New;

        this->type = "Physical";
        this->physical = true;
    }

    Physical(const string& name, const string& ID, const string& description, 
        const string& releaseDate, const string& dateOfReservation, const string& dateOfReturn, const Condition& condition)
        : Item(name, ID, description, releaseDate, dateOfReservation, dateOfReturn) {
        this->type = "Physical";
        this->physical = true;

        this->condition = condition;
    }

    Physical(const Physical& other) : Item(other) { // Copy constructor
        if (this != &other) {
            this->condition = other.condition;
        }
    }

    const Physical& operator=(const Physical& other) { // assignment operator
        if (this != &other) {
            Item::operator=(other);
            this->condition = other.condition;
        }
        return *this;
    }

    // Methods
    string GetPhysicalCondition() const {
        // I tried to find another way without using switch-case but there is no direct way of converting enum variable into a string.
        switch (condition)
        {
            case New:
                return "New";
            case Good:
                return "Good";
            case Average:
                return "Average";
            case Bad:
                return "Bad";
            case OnTheVergeOfCollapsing:
                return "On the verge of collapsing";
            case Stolen:
                return "Stolen";
            // There is no need for a default. The condition cannot be wrong. Especially if it has reached the stage of being inside a physical item.
        }
    }
    void DegradeCondition() {
        switch (condition)
        {
            case New:
                condition = Good;
                break;
            case Good:
                condition = Average;
                break;
            case Average:
                condition = Bad;
                break;
            case Bad:
                condition = OnTheVergeOfCollapsing;
                break;
        }
    }
    void DegradeCondition(Condition newCondition) {
        if (condition < newCondition) condition = newCondition;
        else throw new exception("You can't upgrade the condition of a physical item!");
    }

    void GetsStolen() { this->condition = Stolen; }
    bool isStolen() { return this->condition == Stolen ? true : false; }

    string CalculateLateFee(string currentDate) {
        // Date format: MM/DD/Year
        double fee = 0;

        if (isLate(currentDate))
        {
            // Depending on for how long the item was reserved for, the bigger the tax will be for not returning it.
            int daysDuringReservation = daysBetweenTwoDates(dateOfReservation, dateOfReturn);
            if (daysDuringReservation <= 7) fee = 5; // 5%
            else if (daysDuringReservation <= 14) fee = 10; // 10%
            else if (daysDuringReservation <= 28) fee = 25; // 25%
            else if (daysDuringReservation <= 40) fee = 40; // 40%
            else fee = 55; // 55%

            // Depending on how long the item has not been return for, the closer the tax rate to the initial will be.
            int daysOfBeingLate = daysBetweenTwoDates(dateOfReturn, currentDate);
            if (daysOfBeingLate <= 2) fee = 0; // no tax at all
            else if (daysOfBeingLate <= 5) fee /= 4; // a quarter of the tax
            else if (daysOfBeingLate <= 7) fee /= 3; // a third of the tax
            else if (daysOfBeingLate <= 10) fee /= 2; // half of the tax
        }
        else return "The physical item is not late. Therefore, there is no fee.";
        
        stringstream stream;
        stream << std::fixed << setprecision(2) << fee;
        return stream.str() + "%";
    }
};

class Electronical : public Item {
protected:
    string expirationDate;
public:
    // Constructors
    Electronical() {
        this->expirationDate = "";

        this->type = "Electronic";
        this->physical = false;
    }

    Electronical (const string& name, const string& ID, const string& description,
        const string& releaseDate, const string& dateOfReservation, const string& dateOfReturn, const string& expirationDate)
        : Item(name, ID, description, releaseDate, dateOfReservation, dateOfReturn) {
        this->expirationDate = expirationDate;

        this->type = "Electronic";
        this->physical = false;
    }

    Electronical(const Electronical& other) : Item(other) { // Copy constructor
        if (this != &other) {
            this->expirationDate = other.expirationDate;
        }
    }

    const Electronical& operator=(const Electronical& other) { // assignment operator
        if (this != &other) {
            Item::operator=(other);
            this->expirationDate = other.expirationDate;
        }
        return *this;
    }

    // Methods
    string GetCodeExpirationDate() const { return expirationDate; }

    string CalculateLateFee(string currentDate) {
        // Date format: MM/DD/Year
        double fee = 0;

        if (isLate(currentDate))
        {
            // Depending on for how long the program was reserved for, the bigger the tax will be for not returning it.
            int daysDuringReservation = daysBetweenTwoDates(dateOfReservation, dateOfReturn);
            if (daysDuringReservation <= 7) fee = 3; // 3%
            else if (daysDuringReservation <= 14) fee = 7; // 7%
            else if (daysDuringReservation <= 28) fee = 15; // 15%
            else if (daysDuringReservation <= 40) fee = 25; // 25%
            else fee = 40; // 40%

            // Depending on how long the program has not been return for, the closer the tax rate to the initial will be.
            int daysOfBeingLate = daysBetweenTwoDates(dateOfReturn, currentDate);
            if (daysOfBeingLate <= 2) fee = 0; // no tax at all assuming that the software is returned quickly
        }
        else return "The electronical item is not late. Therefore, there is no fee.";
        
        stringstream stream;
        stream << std::fixed << setprecision(2) << fee;
        return stream.str() + "%";
    }
};

class Book : public Physical {
private:
    string author, genre;
    int year;
public:
    // Constructors
    Book(): Physical() {
        this->author = "";
        this->genre = "";
        this->year = 2024;
        this->type = "Book";
    }

    Book(const string& name, const string& ID, const string& description,
        const string& author, const string& genre, const int& year,
        const string& releaseDate, const string& dateOfReservation, const string& dateOfReturn, const Condition& condition)
        : Physical(name, ID, description, releaseDate, dateOfReservation, dateOfReturn, condition) {
        this->author = author;
        this->genre = genre;
        checkYear(year, releaseDate);
        this->year = year;
        this->type = "Book";
    }

    Book(const Book& other) : Physical(other) { // Copy constructor
        if (this != &other) {
            this->author = other.author;
            this->genre = other.genre;
            this->year = other.year;
        }
    }

    const Book& operator=(const Book& other) { // assignment operator
        if (this != &other) {
            Physical::operator=(other);
            this->author = other.author;
            this->genre = other.genre;
            this->year = other.year;
        }
        return *this;
    }

    // Methods
    string GetAuthor() const { return author; }
    string GetGenre() const { return genre; }
    int GetYear() const { return year; }
};

class Ebook : public Electronical {
private:
    string author, genre;
    int year;
public:
    // Constructors
    Ebook() : Electronical() {
        this->author = "";
        this->genre = "";
        this->year = 2024;
        this->type = "Ebook";
    }

    Ebook(const string& name, const string& ID, const string& description,
        const string& author, const string& genre, const int& year,
        const string& releaseDate, const string& dateOfReservation, const string& dateOfReturn, const string& expirationDate)
        : Electronical(name, ID, description, releaseDate, dateOfReservation, dateOfReturn, expirationDate) {
        this->author = author;
        this->genre = genre;
        checkYear(year, releaseDate);
        this->year = year;
        this->type = "Ebook";
    }

    Ebook(const Ebook& other) : Electronical(other) { // Copy constructor
        if (this != &other) {
            this->author = other.author;
            this->genre = other.genre;
            this->year = other.year;
        }
    }

    const Ebook& operator=(const Ebook& other) { // assignment operator
        if (this != &other) {
            Electronical::operator=(other);
            this->author = other.author;
            this->genre = other.genre;
            this->year = other.year;
        }
        return *this;
    }

    // Methods
    string GetAuthor() const { return author; }
    string GetGenre() const { return genre; }
    int GetYear() const { return year; }
};

class Magazine : public Physical {
private:
    string Publisher;
    string IssueNumber;
public:
    // Constructors
    Magazine() : Physical() {
        this->Publisher = "";
        this->IssueNumber = "";
        this->type = "Magazine";
    }

    Magazine(const string& name, const string& ID, const string& description,
        const string& publisher, const string& issueNumber,
        const string& releaseDate, const string& dateOfReservation, const string& dateOfReturn, const Condition& condition)
        : Physical(name, ID, description, releaseDate, dateOfReservation, dateOfReturn, condition) {
        this->Publisher = publisher;
        this->IssueNumber = issueNumber;
        this->type = "Magazine";
    }

    Magazine(const Magazine& other) : Physical(other) { // Copy constructor
        if (this != &other) {
            this->Publisher = other.Publisher;
            this->IssueNumber = other.IssueNumber;
        }
    }

    const Magazine& operator=(const Magazine& other) { // assignment operator
        if (this != &other) {
            Physical::operator=(other);
            this->Publisher = other.Publisher;
            this->IssueNumber = other.IssueNumber;
        }
        return *this;
    }

    // Methods
    string GetPublisher() const { return Publisher; }
    string GetIssueNumber() const { return IssueNumber; }
};

class DVD : public Physical {
private:
    string director, genre;
    int year;
    double duration; // in minutes
public:
    // Constructors
    DVD() : Physical() {
        this->director = "";
        this->genre = "";
        this->year = 2024;
        this->duration = 0;
        this->type = "DVD";
    }

    DVD(const string& name, const string& ID, const string& description,
        const string& director, const string& genre, const int& year, const double& duration,
        const string& releaseDate, const string& dateOfReservation, const string& dateOfReturn, const Condition& condition)
        : Physical(name, ID, description, releaseDate, dateOfReservation, dateOfReturn, condition) {
        this->director = director;
        this->genre = genre;
        checkYear(year, releaseDate);
        this->year = year;
        this->duration = duration;
        this->type = "DVD";
    }

    DVD(const DVD& other) : Physical(other) { // Copy constructor
        if (this != &other) {
            this->director = other.director;
            this->genre = other.genre;
            this->year = other.year;
            this->duration = other.duration;
        }
    }

    const DVD& operator=(const DVD& other) { // assignment operator
        if (this != &other) {
            Physical::operator=(other);
            this->director = other.director;
            this->genre = other.genre;
            this->year = other.year;
            this->duration = other.duration;
        }
        return *this;
    }
    
    // Methods
    string GetDirector() const { return director; }
    string GetGenre() const { return genre; }
    int GetYear() const { return year; }
    double GetDuration() const { return duration; }
};

class Software : public Electronical {
private:
    string username;
    Subscription SubscriptionPlan;
    double usageTime; // in minutes
public:
    // Constructors
    Software() : Electronical() {
        this->username = "";
        this->SubscriptionPlan = Free;
        this->usageTime = 0;
        this->type = "Software";
    }

    Software(const string& name, const string& ID, const string& description, const string& releaseDate, 
        const string& username, const Subscription& plan, const double& usageTime,
        const string& dateOfReservation, const string& dateOfReturn, const string& expirationDate)
        : Electronical(name, ID, description, releaseDate, dateOfReservation, dateOfReturn, expirationDate) {
        this->username = username;
        this->SubscriptionPlan = plan;
        this->usageTime = usageTime;
        this->type = "Software";
    }

    Software(const Software& other) : Electronical(other) { // Copy constructor
        if (this != &other) {
            this->username = other.username;
            this->SubscriptionPlan = other.SubscriptionPlan;
            this->usageTime = other.usageTime;
        }
    }

    const Software& operator=(const Software& other) { // assignment operator
        if (this != &other) {
            Electronical::operator=(other);
            this->username = other.username;
            this->SubscriptionPlan = other.SubscriptionPlan;
            this->usageTime = other.usageTime;
        }
        return *this;
    }

    // Methods
    string GetUsername() const { return username; }
    string GetSubscriptionPlan() const { 
        // I tried to find another way without using switch-case but there is no direct way of converting enum variable into a string.
        switch (SubscriptionPlan)
        {
            case Free:
                return "Free";
            case Basic:
                return "Basic";
            case Standard:
                return "Standard";
            case Premium:
                return "Premium";
                // There is no need for a default. The plan cannot be wrong. Especially if it has reached the stage of being inside a software class.
        }
    }
    double GetUsageTime() const { return usageTime; }
};


// Main functions for the program
void KMPcommand(vector<Item*>& Items, string searchString) {
    vector<pair<int, Item*>> itemsWithMatches;

    // Perform pattern matching
    KMP matcher;
    for (Item* item : Items) {
        string itemName = item->GetName();
        int matches = matcher.SearchString(itemName, searchString);
        if (matches > 0) itemsWithMatches.push_back(make_pair(matches, item));
    }

    sort(itemsWithMatches.begin(), itemsWithMatches.end(), greater<pair<int, Item*>>());


    cout << endl << "Sorting complete!" << endl
        << "Would you want to display the collected items with certain match?" << endl
        << "Or would you rather they completely replace whole list with all items?" << endl
        << "Select: \"Display\" or \"Replace\" (Make sure you write it as it is said, or else the program will continue to the next command.): ";
    string choice;
    cin >> choice;
    if (choice == "Display") {
        cout << "Items containing \"" << searchString << "\" in their name:" << endl;
        int i = 0;
        for (; i < itemsWithMatches.size(); i++) {
            cout << "Item " << i + 1 << ":" << endl;
            cout << "Name: " << itemsWithMatches[i].second->GetName() << endl;
            cout << "ID: " << itemsWithMatches[i].second->GetID() << endl;
            cout << endl;
        }
        if (i == 0) cout << "None" << endl;
    }
    else if (choice == "Replace") {
        Items.clear(); // Clearing the vector
        for (int i = 0; i < itemsWithMatches.size(); i++)
            Items.push_back(itemsWithMatches[i].second);
    }
};

void displayEverything(vector<Item*>& Items) {
    for (int i = 0; i < Items.size(); i++)
    {
        string type = Items[i]->GetItemType();

        cout << "Item " << i + 1 << ":" << endl;
        cout << "Name: " << Items[i]->GetName() << endl;
        cout << "ID: " << Items[i]->GetID() << endl;
        cout << "Type: " << type << endl;
        cout << "Description: " << Items[i]->GetDescription() << endl;

        if (type == "Book") {
            Book* book = dynamic_cast<Book*>(Items[i]);
            cout << "Author: " << book->GetAuthor() << endl;
            cout << "Genre: " << book->GetGenre() << endl;
            cout << "Year: " << book->GetYear() << endl;
            cout << "Physical condition: " << book->GetPhysicalCondition() << endl;
        }
        else if (type == "Ebook") {
            Ebook* ebook = dynamic_cast<Ebook*>(Items[i]);
            cout << "Author: " << ebook->GetAuthor() << endl;
            cout << "Genre: " << ebook->GetGenre() << endl;
            cout << "Year: " << ebook->GetYear() << endl;
            cout << "Digital code's expiration date: " << ebook->GetCodeExpirationDate() << endl;
        }
        else if (type == "Magazine") {
            Magazine* magazine = dynamic_cast<Magazine*>(Items[i]);
            cout << "Publisher: " << magazine->GetPublisher() << endl;
            cout << "Issue Date: " << magazine->GetIssueNumber() << endl;
            cout << "Physical condition: " << magazine->GetPhysicalCondition() << endl;
        }
        else if (type == "DVD") {
            DVD* dvd = dynamic_cast<DVD*>(Items[i]);
            cout << "Director: " << dvd->GetDirector() << endl;
            cout << "Genre: " << dvd->GetGenre() << endl;
            cout << "Year: " << dvd->GetYear() << endl;
            cout << "Duration: " << dvd->GetDuration() << endl;
            cout << "Physical condition: " << dvd->GetPhysicalCondition() << endl;
        }
        else if (type == "Software") {
            Software* software = dynamic_cast<Software*>(Items[i]);
            cout << "Username: " << software->GetUsername() << endl;
            cout << "Subscription plan: " << software->GetSubscriptionPlan() << endl;
            cout << "Usage time: " << software->GetUsageTime() << endl;
            cout << "Digital code's expiration date: " << software->GetCodeExpirationDate() << endl;
        }

        cout << "Release date: " << Items[i]->GetReleaseDate() << endl;
        cout << "Date of reservation: " << Items[i]->GetDateOfReservation() << endl;
        cout << "Date of return: " << Items[i]->GetDateOfReturn() << endl;

        cout << endl;
    }
}

void display(vector<Item*>& Items, string type) {
    vector<Item*> FilteredForDisplay;
    if (type == "physicals")
        copy_if(Items.begin(), Items.end(), back_inserter(FilteredForDisplay), [](Item* i) { return i->IsItPhysicalOrElectronic() == true; });
    else if (type == "electronics")
        copy_if(Items.begin(), Items.end(), back_inserter(FilteredForDisplay), [](Item* i) { return i->IsItPhysicalOrElectronic() == false; });
    else if (type == "books")
        copy_if(Items.begin(), Items.end(), back_inserter(FilteredForDisplay), [](Item* i) { return i->GetItemType() == "Book"; });
    else if (type == "ebooks")
        copy_if(Items.begin(), Items.end(), back_inserter(FilteredForDisplay), [](Item* i) { return i->GetItemType() == "Ebook"; });
    else if (type == "magazines")
        copy_if(Items.begin(), Items.end(), back_inserter(FilteredForDisplay), [](Item* i) { return i->GetItemType() == "Magazine"; });
    else if (type == "DVDs")
        copy_if(Items.begin(), Items.end(), back_inserter(FilteredForDisplay), [](Item* i) { return i->GetItemType() == "DVD"; });
    else if (type == "softwares")
        copy_if(Items.begin(), Items.end(), back_inserter(FilteredForDisplay), [](Item* i) { return i->GetItemType() == "Software"; });
    /*else if (type == "late")
        copy_if(Items.begin(), Items.end(), back_inserter(FilteredForDisplay), [](Item i) { return i.isLate() == true; });*/ // potential idea
    else if (type == "all" || type == "everything") FilteredForDisplay = Items;
    // else copy_if(Items.begin(), Items.end(), back_inserter(FilteredForDisplay), [](Item* i) { return i->GetID() == type; }); // Potential idea. Doesn't work for some reason.

    displayEverything(FilteredForDisplay);
}

// Test the two for this approach
void degradingCondition(vector<Item*>& Items, string target, string newCondition) {
    if (target == "all")
    {
        for (Item* i : Items)
        {
            if (i->IsItPhysicalOrElectronic() == true)
            {
                if (newCondition == ".")
                    dynamic_cast<Physical*>(i)->DegradeCondition();
                else dynamic_cast<Physical*>(i)->DegradeCondition(ConditionFromString(newCondition));
            }
        }
    }
    else
    {
        if (find(IDs.begin(), IDs.end(), target) != IDs.end())
        {
            bool noItem = true;
            for (Item* i : Items) {
                if (i->GetID() == target)
                {
                    if (newCondition == ".")
                        dynamic_cast<Physical*>(i)->DegradeCondition();
                    else dynamic_cast<Physical*>(i)->DegradeCondition(ConditionFromString(newCondition));

                    noItem = false;

                    break;
                }
            }
            if (noItem) cout << "The item is not physical." << endl;
        }
        else cout << "There is no such item in our library." << endl;
    }
}

void LateFeeCalculating(vector<Item*>& Items, string target, string date) {
    if (target == "all") for (int i = 0; i < Items.size(); i++)
    {
        cout << "Item " << i + 1 << ":" << endl;
        cout << "Name: " << Items[i]->GetName() << endl;
        cout << "ID: " << Items[i]->GetID() << endl;
        cout << "Type: " << Items[i]->GetItemType() << endl;
        cout << "Late fee for " << date << ": " << Items[i]->CalculateLateFee(date) << endl;
        cout << endl;
    }
    else
    {
        if (find(IDs.begin(), IDs.end(), target) != IDs.end())
        {
            for (Item* i : Items) {
                if (i->GetID() == target)
                {
                    cout << "Name: " << i->GetName() << endl;
                    cout << "ID: " << i->GetID() << endl;
                    cout << "Type: " << i->GetItemType() << endl;
                    cout << "Late fee for " << date << ": " << i->CalculateLateFee(date) << endl;
                    cout << endl;

                    break;
                }
            }
        }
        else cout << "There is no such item in our library." << endl;
    }
}

// Test the two for this approach
void ItemExpirationDate(vector<Item*>& ElectronicItems, string target) {
    if (target == "all") for (int i = 0; i < ElectronicItems.size(); i++)
    {
        
        cout << "Item " << i + 1 << ":" << endl;
        cout << "Name: " << ElectronicItems[i]->GetName() << endl;
        cout << "ID: " << ElectronicItems[i]->GetID() << endl;
        cout << "Type: " << ElectronicItems[i]->GetItemType() << endl;

        Electronical* eItem = dynamic_cast<Electronical*>(ElectronicItems[i]);
        cout << "Expiration date: " << eItem->GetCodeExpirationDate() << endl;
        cout << endl;
    }
    else
    {
        if (find(IDs.begin(), IDs.end(), target) != IDs.end())
        {
            bool noItem = true;
            for (Item* i : ElectronicItems) {
                if (i->GetID() == target)
                {
                    cout << "Name: " << i->GetName() << endl;
                    cout << "ID: " << i->GetID() << endl;
                    cout << "Type: " << i->GetItemType() << endl;

                    Electronical* eItem = dynamic_cast<Electronical*>(i);
                    cout << "Expiration date: " << eItem->GetCodeExpirationDate() << endl;
                    cout << endl;

                    noItem = false;
                    break;
                }
            }
            if (noItem) cout << "The item is not electronic." << endl;
        }
        else cout << "There is no such electronic item in our library." << endl;
    }
}

void Stealing(vector<Item*>& StolenItems, string target) {
    if (target == "all") for (Item* i : StolenItems) {
        Physical* physicalItem = dynamic_cast<Physical*>(i);
        physicalItem->GetsStolen();
    }
    else
    {
        if (find(IDs.begin(), IDs.end(), target) != IDs.end())
        {
            bool noItem = true;
            for (Item* i : StolenItems) {
                if (i->GetID() == target)
                {
                    Physical* physicalItem = dynamic_cast<Physical*>(i);
                    physicalItem->GetsStolen();

                    noItem = false;
                    break;
                }
            }
            if (noItem) cout << "The item is not physical." << endl;
        }
        else cout << "There is no such item in our library." << endl;
    }
}


// Main program
int main()
{
    cout << "Welcome to our library program! Here you can upload the collection of items contained in your library." << endl
        << "In order to add items to the system you need to fill the \"items.txt\" file with the information regarding each physical and electronical item or put your file following the following instructions." << endl
        << "WARNING! Read the instructions beforehand in the above mentioned file to avoid any unnecessary program exceptions. Also, please fill an appropriate data (no negative years, unallowed conditions, etc.)." << endl
        << endl
        << "Thank you for buying our program!" << endl
        << "If there are any problems, feel free to contact our support team :)" << endl
        << endl;

    string fileChoice = "items.txt";
    while (fileChoice != "items.txt" && fileChoice != "another")
    {
        cout << "What file would you want to use? \"items.txt\" or another? Answer explicitly: ";
        cin >> fileChoice;
    }
    if (fileChoice == "another")
    {
        cout << "Please enter the location of the file with all of the necessary parts. Including slashes (/) if the file is not in the same folder as \"items.txt\". As well as the \".txt\" so that it can be read by the program." << endl
                << "File name: ";
        cin >> fileChoice;
        string choice = "No";
        while (true)
        {
            cout << "Are you sure this is the file you want to use? Yes or No (answer explicitly, if you do not, the program will ask you again): ";
            cin >> choice;
            if (choice == "Yes") break;
            if (choice == "No") {
                cout << "Enter the file name again: ";
                cin >> fileChoice;
            }
        }
    }
    
    vector<Item*> Items;
    string line;

    ifstream itemsFile("items.txt");
    while (getline(itemsFile, line))
    {
        stringstream iss(line);
        vector<string> elements;

        // Collect the data separated by commas
        string element;
        getline(iss, element, ',');
        if ((element.find("//") != string::npos) || element.empty()) continue;
        elements.push_back(element); // for item's type

        for (int i = 0; i < 2; i++) // for item's name and ID
        {
            getline(iss, element, ',');
            element.erase(0, 1);
            if (i == 0) element = element.substr(1, element.size() - 2); // Removing the "" from the item's name.
            elements.push_back(element);
        }

        getline(iss, element, '\"'); // Removing the first " of the item's description.
        getline(iss, element, '\"'); // for item's description
        elements.push_back(element);

        getline(iss, element, ','); // To clean the useless comma.
        while (getline(iss, element, ',')) { // for item's other data
            element.erase(0, 1);
            elements.push_back(element);
        }
        if (elements.size() == 0) continue;
        string type, name, ID, description;

        // Assign elements to variables
        type = elements[0];
        name = elements[1];
        ID = elements[2];
        description = elements[3];
        
        string releaseDate, dateOfReservation, dateOfReturn, conditionStr;

        if (type == "Book" || type == "Ebook") {
            string author, genre;
            int year;
            
            author = elements[4];
            genre = elements[5];
            year = stoi(elements[6]);
            releaseDate = elements[7];
            dateOfReservation = elements[8];
            dateOfReturn = elements[9];
            conditionStr = elements[10];
            
            if (type == "Book") {
                Condition condition = ConditionFromString(conditionStr);

                Book* newBook = new Book(name, ID, description, author, genre, year, releaseDate, dateOfReservation, dateOfReturn, condition);
                Items.push_back(newBook);
            }
            else if (type == "Ebook") {
                Ebook* newEbook = new Ebook(author, ID, description, author, genre, year, releaseDate, dateOfReservation, dateOfReturn, conditionStr);
                Items.push_back(newEbook);
            }
        }
        else if (type == "Magazine") {
            string publisher, issueNumber;

            publisher = elements[4];
            issueNumber = elements[5];
            releaseDate = elements[6];
            dateOfReservation = elements[7];
            dateOfReturn = elements[8];
            conditionStr = elements[9];

            Condition condition = ConditionFromString(conditionStr);

            Magazine* newMagazine = new Magazine(name, ID, description, publisher, issueNumber, releaseDate, dateOfReservation, dateOfReturn, condition);
            Items.push_back(newMagazine);
        }
        else if (type == "DVD") {
            string director, genre;
            int year;
            double duration;

            director = elements[4];
            genre = elements[5];
            year = stoi(elements[6]);
            duration = stod(elements[7]);
            releaseDate = elements[8];
            dateOfReservation = elements[9];
            dateOfReturn = elements[10];
            conditionStr = elements[11];

            Condition condition = ConditionFromString(conditionStr);

            DVD* newDVD = new DVD(director, ID, description, director, genre, year, duration, releaseDate, dateOfReservation, dateOfReturn, condition);
            Items.push_back(newDVD);
        }
        else if (type == "Software") {
            string username, plan;
            double usageTime;

            releaseDate = elements[4];
            username = elements[5];
            plan = elements[6];
            usageTime = stod(elements[7]);
            dateOfReservation = elements[8];
            dateOfReturn = elements[9];
            conditionStr = elements[10];

            Subscription SubscriptionPlan;
            if (plan == "Free") SubscriptionPlan = Free;
            else if (plan == "Basic") SubscriptionPlan = Basic;
            else if (plan == "Standard") SubscriptionPlan = Standard;
            else if (plan == "Premium") SubscriptionPlan = Premium;
            else throw new invalid_argument("There is no such type of subscription plan for the software \"" + name + "\" rented by " + username + "!");

            Software* program = new Software(name, ID, description, releaseDate, username, SubscriptionPlan, usageTime, dateOfReservation, dateOfReturn, conditionStr);
            Items.push_back(program);
        }
    }
    itemsFile.close();

    cout << "How would you like to send commands to the program?" << endl
        << "With the \"commands.txt\" file (beforehand prepared) or from the command window directly (at the moment)?" << endl;
    string commandOption = "Window";
    while (commandOption != "File" && commandOption != "Window")
    {
        cout << "Please select \"File\" or \"Window\": ";
        cin >> commandOption;
    }

    if (commandOption == "File")
    {
        ifstream commandsFile("commands.txt");
        while (getline(commandsFile, line)) {
            stringstream iss(line);
            string command, element;
            iss >> command >> element;

            if (command == "//") continue;

            if (command == "CheckIfLate") {
                // Date format: MM/DD/Year
                string date;
                iss >> date;
                for (int i = 0; i < Items.size(); i++)
                {
                    cout << Items[i]->GetName() << ": ";

                    string late = Items[i]->isLate(date) ? "Late" : "Still on time";
                    cout << late << endl;
                }
                cout << endl;
            }
            else if (command == "CalculateLateFee")
            {
                // Date format: MM/DD/Year
                string date;
                iss >> date;
                LateFeeCalculating(Items, element, date);
            }
            else if (command == "KMP") KMPcommand(Items, element);
            else if (command == "GetCodeExpirationDate") {
                vector<Item*> ElectronicItems;
                copy_if(Items.begin(), Items.end(), back_inserter(ElectronicItems), [](Item* i) { return i->IsItPhysicalOrElectronic() == false; });
                ItemExpirationDate(ElectronicItems, element);
            }
            else if (command == "GetsStolen") {
                vector<Item*> StolenItems;
                copy_if(Items.begin(), Items.end(), back_inserter(StolenItems), [](Item* i) { return i->IsItPhysicalOrElectronic() == true; });
                Stealing(StolenItems, element);
            }
            else if (command == "DegradeCondition") {
                vector<Item*> PhysicalItems;
                copy_if(Items.begin(), Items.end(), back_inserter(PhysicalItems), [](Item* i) { return i->IsItPhysicalOrElectronic() == true; });

                string newCondition;
                iss >> newCondition;

                degradingCondition(PhysicalItems, element, newCondition);
            }
            else if (command == "Show" || command == "Display") display(Items, element);
            else if (command == "End" && element == "program") break;
        }
    }
    else if (commandOption == "Window")
    {
        string commands = "\nYou can enter the following types of commands:\n\n"

            "\"CheckIfLate {MM/DD/YYYY}\" - checks whether each item is late depending on the provided date\n"
            "\"KMP {searchString}\" - sorts the elements through KMP matching algorithm with provided search string\n"
            "\"DegradeCondition all/{specific ID} ./{type of Condition}\" - degrades the condition of a specific physical item or all of them\n"
            // Fix the date calculation.
            "\"CalculateLateFee {specific ID}/all {MM/DD/YYYY}\" - calculates the late fee of a specific item or all of them\n"
            "\"GetCodeExpirationDate {specific ID}/all\"\n"
            "\"GetsStolen {specific ID}/all\"\n"

            "\"Display physicals / electronics / books / ebooks / magazines / DVDs / softwares / all / everything\" - displays on the command window the desired output of data\n"
            "\"Show / electronics / books / ebooks / magazines / DVDs / softwares / all / everything\" - displays on the command window the desired output of data\n\n" // Same as the previous one
            "\"Show commands\" - display the current commands again. Useful if you do not want to scroll all the way up to see what functions you can do.\n"
            "\"End program\" - stops the acceptance of new commands\n"
            "Anything else written will not be accepted and the program will ask you for a new commands without doing anything beforehand.\n\n";
        cout << commands;

        string command = "";
        while (true)
        {
            string value = "";
            cout << "Command: ";
            cin >> command >> value;

            if (command == "CheckIfLate") {
                // Date format: MM/DD/Year
                for (int i = 0; i < Items.size(); i++)
                {
                    cout << Items[i]->GetName() << ": ";

                    string late = Items[i]->isLate(value) ? "Late" : "Still on time";
                    cout << late << endl;
                }
            }
            else if (command == "CalculateLateFee")
            {
                // Date format: MM/DD/Year
                string date;
                cin >> date;
                LateFeeCalculating(Items, value, date);
            }
            else if (command == "KMP") KMPcommand(Items, value);
            else if (command == "GetCodeExpirationDate") {
                vector<Item*> ElectronicItems;
                copy_if(Items.begin(), Items.end(), back_inserter(ElectronicItems), [](Item* i) { return i->IsItPhysicalOrElectronic() == false; });
                ItemExpirationDate(ElectronicItems, value);
            }
            else if (command == "GetsStolen") {
                vector<Item*> StolenItems;
                copy_if(Items.begin(), Items.end(), back_inserter(StolenItems), [](Item* i) { return i->IsItPhysicalOrElectronic() == true; });
                Stealing(StolenItems, value);
            }
            else if (command == "DegradeCondition") {
                vector<Item*> PhysicalItems;
                copy_if(Items.begin(), Items.end(), back_inserter(PhysicalItems), [](Item* i) { return i->IsItPhysicalOrElectronic() == true; });
                                
                string newCondition;
                cin >> newCondition;

                degradingCondition(PhysicalItems, value, newCondition);
            }
            else if (command == "Show" && value == "commands") cout << commands;
            else if (command == "Show" || command == "Display") display(Items, value);
            else if (command == "End" && value == "program") break;
        }
    } 

    cout << "Would you want to export the items' data in another file? Yes or No (answer explicitly - if not, it will be considered as \"No\"): ";
    string exporting;
    cin >> exporting;
    if (exporting == "Yes")
    {
        ofstream outputFile("OutputData.txt");
        if (outputFile.is_open())
        {
            for (int i = 0; i < Items.size(); i++)
            {
               string type = Items[i]->GetItemType();

                outputFile << "Item " << i + 1 << ":" << endl;
                outputFile << "Name: " << Items[i]->GetName() << endl;
                outputFile << "ID: " << Items[i]->GetID() << endl;
                outputFile << "Type: " << type << endl;
                outputFile << "Description: " << Items[i]->GetDescription() << endl;

                if (type == "Book") {
                    Book* book = dynamic_cast<Book*>(Items[i]);
                    outputFile << "Author: " << book->GetAuthor() << endl;
                    outputFile << "Genre: " << book->GetGenre() << endl;
                    outputFile << "Year: " << book->GetYear() << endl;
                    outputFile << "Physical condition: " << book->GetPhysicalCondition() << endl;
                }
                else if (type == "Ebook") {
                    Ebook* ebook = dynamic_cast<Ebook*>(Items[i]);
                    outputFile << "Author: " << ebook->GetAuthor() << endl;
                    outputFile << "Genre: " << ebook->GetGenre() << endl;
                    outputFile << "Year: " << ebook->GetYear() << endl;
                    outputFile << "Digital code's expiration date: " << ebook->GetCodeExpirationDate() << endl;
                }
                else if (type == "Magazine") {
                    Magazine* magazine = dynamic_cast<Magazine*>(Items[i]);
                    outputFile << "Publisher: " << magazine->GetPublisher() << endl;
                    outputFile << "Issue Date: " << magazine->GetIssueNumber() << endl;
                    outputFile << "Physical condition: " << magazine->GetPhysicalCondition() << endl;
                }
                else if (type == "DVD") {
                    DVD* dvd = dynamic_cast<DVD*>(Items[i]);
                    outputFile << "Director: " << dvd->GetDirector() << endl;
                    outputFile << "Genre: " << dvd->GetGenre() << endl;
                    outputFile << "Year: " << dvd->GetYear() << endl;
                    outputFile << "Duration: " << dvd->GetDuration() << endl;
                    outputFile << "Physical condition: " << dvd->GetPhysicalCondition() << endl;
                }
                else if (type == "Software") {
                    Software* software= dynamic_cast<Software*>(Items[i]);
                    outputFile << "Username: " << software->GetUsername() << endl;
                    outputFile << "Subscription plan: " << software->GetSubscriptionPlan() << endl;
                    outputFile << "Usage time: " << software->GetUsageTime() << endl;
                    outputFile << "Digital code's expiration date: " << software->GetCodeExpirationDate() << endl;
                }

                outputFile << "Release date: " << Items[i]->GetReleaseDate() << endl;
                outputFile << "Date of reservation: " << Items[i]->GetDateOfReservation() << endl;
                
                outputFile << endl;
            }
        }

        outputFile.close();
    }

    Items.clear(); // Clearing the vector
};