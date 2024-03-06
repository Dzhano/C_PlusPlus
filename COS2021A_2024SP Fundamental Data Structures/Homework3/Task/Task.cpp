#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum DiscountType { amount, percentage };

vector<string> GUIDs;

class Division {
private:
    string GUID;
    string Name;
    string PhoneNumber;
    string Description;
    Division* Parent;

    void checkGUID(string guid) {
        if (find(GUIDs.begin(), GUIDs.end(), guid) != GUIDs.end())
            throw invalid_argument("There is already a division with this GUID.");
        else {
            GUIDs.push_back(guid);
            this->GUID = guid;
        }
    }
public:
    // Constructors
    Division() {
        checkGUID("ABCD-EFGH-1234");
        Name = "Electronics";
        PhoneNumber = "0888 123456";
        Description = "";
        Parent = nullptr;
    }

    Division(const string& guid, const string& name, const string& phoneNumber, const string& description, Division* parent = nullptr) {
        checkGUID(guid);
        this->Name = name;
        this->PhoneNumber = phoneNumber;
        this->Description = description;
        this->Parent = parent;
    }


    Division(const Division& other) { // Copy constructor
        if (this != &other) {
            this->GUID = other.GUID;
            this->Name = other.Name;
            this->PhoneNumber = other.PhoneNumber;
            this->Description = other.Description;
            this->Parent = other.Parent;
        }
    }

    const Division& operator=(const Division& other) { // assignment operator
        if (this != &other) {
            this->GUID = other.GUID;
            this->Name = other.Name;
            this->PhoneNumber = other.PhoneNumber;
            this->Description = other.Description;
            this->Parent = other.Parent;
        }
        return *this;
    }
};

class Item { // Abstract class
public:
    virtual double GetTotalPrice() const = 0;
    virtual string GetName() const = 0;
    virtual string GetCategory() const = 0;
};

class Artifact : public Item {
protected:
    string GUID;
    string Name;
    string Description;
    string Category;
    Division* division;
    double Price;
    double Discount;
    DiscountType discountType;
    int Quantity;
public:
    // Constructors
    Artifact() {
        this->GUID = "";
        this->Name = "Sony Vaio";
        this->Description = "";
        this->Category = "Laptop";
        this->division = new Division();
        this->Price = 185.99;
        this->Discount = 30;
        this->discountType = amount;
        this->Quantity = 0;
    }

    Artifact(const string& guid, const string& name, const string& description, const string& category,
        Division* div, const double& price, const double& discount, const DiscountType& newDiscountType, const int& quantity) {
        this->GUID = guid;
        this->Name = name;
        this->Description = description;
        this->Category = category;
        this->division = div;

        if (price < 0) throw invalid_argument("Price cannot be negative");
        else this->Price = price;

        if (discount < 0) throw invalid_argument("Discount cannot be negative");
        else this->Discount = discount;

        this->discountType = newDiscountType;

        if (quantity < 0) throw invalid_argument("Quantity cannot be negative");
        else this->Quantity = quantity;
    }

    Artifact(const Artifact& other) { // Copy constructor
        if (this != &other) {
            this->GUID = other.GUID;
            this->Name = other.Name;
            this->Description = other.Description;
            this->Category = other.Category;
            this->division = other.division;
            this->Price = other.Price;
            this->Discount = other.Discount;
            this->discountType = other.discountType;
            this->Quantity = other.Quantity;
        }
    }

    const Artifact& operator=(const Artifact& other) { // assignment operator
        if (this != &other) {
            this->GUID = other.GUID;
            this->Name = other.Name;
            this->Description = other.Description;
            this->Category = other.Category;
            this->division = other.division;
            this->Price = other.Price;
            this->Discount = other.Discount;
            this->discountType = other.discountType;
            this->Quantity = other.Quantity;
        }
        return *this;
    }


    // Methods
    double GetEffectivePrice() const {
        double EffectivePrice;
        if (discountType == amount) EffectivePrice = Price - Discount;
        else EffectivePrice = Price - (Price * Discount) / 100;

        if (EffectivePrice < 0) throw invalid_argument("The effective price cannot be negative");
        else return EffectivePrice;
    }

    double GetTotalPrice() const {
        double TotalPrice = Quantity * GetEffectivePrice();

        if (TotalPrice < 0) throw invalid_argument("The total price cannot be negative");
        else return TotalPrice;
    }

    string GetName() const {
        return Name;
    }

    string GetCategory() const {
        return Category;
    }
};

class Service : public Artifact {
private:
    double Duration;
    double Rate;
    double RateDiscount;
    DiscountType RateDiscountType;
public:
    // Constructors
    Service() : Artifact() {
        Duration = 1.5;
        Rate = 8.50;
        RateDiscount = 30;
        RateDiscountType = percentage;
    }

    Service(const string& guid, const string& name, const string& description, const string& category,
        Division* div, const double& price, const double& discount, const DiscountType& newDiscountType, const int& quantity,
        const double& duration, const double& rate, const double& rateDiscount, const DiscountType& newRateDiscountType)
        : Artifact(guid, name, description, category, div, price, discount, newDiscountType, quantity) {
        if (duration < 0) throw invalid_argument("Duration cannot be negative");
        else this->Duration = duration;

        if (rate < 0) throw invalid_argument("Rate cannot be negative");
        else this->Rate = rate;

        if (rateDiscount < 0) throw invalid_argument("RateDiscount cannot be negative");
        else this->RateDiscount = rateDiscount;

        this->RateDiscountType = newRateDiscountType;
    }

    Service(const Service& other) : Artifact(other) { // Copy constructor
        if (this != &other) {
            this->Duration = other.Duration;
            this->Rate = other.Rate;
            this->RateDiscount = other.Rate;
            this->RateDiscountType = other.RateDiscountType;
        }
    }

    const Service& operator=(const Service& other) { // assignment operator
        if (this != &other) {
            this->GUID = other.GUID;
            this->Name = other.Name;
            this->Description = other.Description;
            this->Category = other.Category;
            this->division = other.division;
            this->Price = other.Price;
            this->Discount = other.Discount;
            this->discountType = other.discountType;
            this->Quantity = other.Quantity;
            this->Duration = other.Duration;
            this->Rate = other.Rate;
            this->RateDiscount = other.Rate;
            this->RateDiscountType = other.RateDiscountType;
        }
        return *this;
    }


    // Methods
    double GetEffectiveRate() const {
        double EffectiveRate;
        if (RateDiscountType == amount) EffectiveRate = Rate - RateDiscount;
        else EffectiveRate = Rate - (Rate * RateDiscount) / 100;

        if (EffectiveRate < 0) throw invalid_argument("The effective rate cannot be negative");
        else return EffectiveRate;
    }

    double GetTotalPrice() const {
        double TotalPrice = Artifact::GetTotalPrice() + GetEffectiveRate() * Duration;

        if (TotalPrice < 0) throw invalid_argument("The total price cannot be negative");
        else return TotalPrice;
    }
};



// ID: 200203987 = Quicksort algorithm
void insertionSort(vector<Item*>& a)
{
    for (int p = 1; p < a.size(); p++) {
        Item* tmp = a[p];
        int j;

        for (j = p; j > 0 && tmp->GetTotalPrice() < a[j - 1]->GetTotalPrice(); j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

void quicksort(vector<Item*>& a, int low, int high)
{
    if (low + 10 > high) {   // Call insertion sort for small subarrays
        insertionSort(a);
    }
    else {
        int middle = (low + high) / 2;   // Sort low, middle, high
        if (a[middle]->GetTotalPrice() < a[low]->GetTotalPrice()) swap(a[low], a[middle]);
        if (a[high]->GetTotalPrice() < a[low]->GetTotalPrice()) swap(a[low], a[high]);
        if (a[high]->GetTotalPrice() < a[middle]->GetTotalPrice()) swap(a[middle], a[high]);
        Item* pivot = a[middle];
        swap(a[middle], a[high - 1]);

        // Begin partitioning  
        int i, j;
        for (i = low, j = high - 1; ;) {
            while (a[++i]->GetTotalPrice() < pivot->GetTotalPrice()) {
                // Empty loop body, just incrementing i
            }
            while (pivot->GetTotalPrice() < a[--j]->GetTotalPrice()) {
                // Empty loop body, just incrementing j
            }

            if (i < j) swap(a[i], a[j]);
            else break;
        }
        swap(a[i], a[high - 1]);    // Restore the pivot

        quicksort(a, low, i - 1);   // Sort small elements
        quicksort(a, i + 1, high);  // Sort large elements
    }
}

void quicksort(vector<Item*>& a) {
    quicksort(a, 0, a.size() - 1);
}


int main()
{
    vector<Item*> Items;

    Division* division1 = new Division("D447-45A2-0000", "Electronics", "+359882720200", "TV, PC, consoles, household appliances, etc.");
    Division* division2 = new Division("D447-45A3-0000", "Smartphones", "+359888803991", "iPhone, Xiaomi, Huawei, etc.", division1);
    Division* division3 = new Division("ABD9-84F9-0000", "Cars", "+359886848483", "Mercedes, Ford, Tesla, Volkswagen, etc.");

    Artifact* artifact1 = new Artifact("D447-45A2-8481", "Samsung Smart TV", "Model: QLED 4K TV Q80C (2023)", "TV", division1, 8499, 15, percentage, 2);
    Artifact* artifact2 = new Artifact("D447-45A3-8490", "iPhone", "Model: iPhone 15 Plus (2023)", "Apple", division2, 2699, 200, amount, 3);
    Artifact* artifact3 = new Artifact("ABD9-84F9-4545", "Ford", "Model: S Max (2016)", "Family cars", division3, 15000, 10, percentage, 1);

    Service* service1 = new Service("D447-45A2-2056", "Sport channels", "Diema Sport (1, 2, 3, HD)", "Channels", division1, 0.029, 3, percentage, 1, 20, 1, 2, percentage);
    Service* service2 = new Service("D447-45A2-1231", "Phone Services", "Phone Calls and Text Messages", "Mobile operators", division2, 10, 5, amount, 3, 30, 2, 5, percentage);
    Service* service3 = new Service("ABD9-84F9-1111", "Car insurance", "Insurance for family-sized car covering most traffic accidents.", "Car services", division3, 0.031, 50, percentage, 1, 100, 5, 23, percentage);


    Items.push_back(artifact1);
    Items.push_back(artifact2);
    Items.push_back(artifact3);
    Items.push_back(service1);
    Items.push_back(service2);
    Items.push_back(service3);

    quicksort(Items);
    //quicksort(Items, 0, Items.size() - 1);

    for (int i = 0; i < Items.size(); i++)
    {
        cout << "Item " << i + 1 << ":" << endl;
        cout << "Name: " << Items[i]->GetName() << endl;
        cout << "Category: " << Items[i]->GetCategory() << endl;
        cout << "Total Price: $" << round(Items[i]->GetTotalPrice() * 100.0) / 100.0 << endl;
        cout << endl;
    }

    Items.clear(); // Clearing the vector

    delete division1, division2, division3, // Deallocating memory
        artifact1, artifact2, artifact3,
        service1, service2, service3, Items;
}