#include <iostream>

std::string convertMonth(int); // Prototype

int main() // Invocation
{
	int months; // The variable that contains how many months will be readed.
	// The program asks the user to enter how many months they would like to process by reading his initial input.
	do
	{
		std::cout << "Please enter how many months would you like to process: "; // This message will be shown every time the user enters a invalid number of months until a correct value (bigger than 0) is assigned.
		std::cin >> months; // The initial input
	} while (months <= 0); // This loop will be executed at least once.

	// After that the user will be asked for "months" times to enter a number of month by his choise for convertion.
	int invalidMonths = 0; // Here will be collected the number of all invalid months that the user might enter in the for-loop.
	for (int i = 0; i < months; i++)
	{
		int month; // Here will be stored the value of the month.
		std::cout << "Please enter a month to convert: ";
		std::cin >> month; // The user enters the month he wants to be converted.

		std::string output = convertMonth(month); // This variable will contain the returned string result from the created function "convertMonth".
		if (output == "error") invalidMonths++; // If the value of the month is not in the correct boundaries (from 1 to 12 inclusively), the number of invalid months will rise and the variable "invalidMonths" will get bigger with 1.

		std::cout << output << std::endl; // The result of the convertion will be displayed through this command.
	}

	std::cout << "All " << months << " months were processed, only " << months - invalidMonths << " were valid."; // The final output with all results.
}

std::string convertMonth(int month)  // Signature/Header
{
	switch (month) // This statement will check whether the input month is correct or not.
	{
	case 1: // January
	case 2: // February
	case 3: // March
	case 4: // April
	case 5: // May
		return "spring semester";
	case 6: // June
	case 7: // July
	case 8: // August
		return "summer vacation";
	case 9: // September
	case 10: // October
	case 11: // November
	case 12: // December
		return "fall semester";
	default: // the month is not correct (less than 0 or bigger than 12)
		return "error";
	}
}