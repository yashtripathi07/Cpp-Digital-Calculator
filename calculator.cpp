#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <limits>

// Function to clear the console screen
void clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

// Function to calculate the square root
double calculateSqrt(double num)
{
    if (num < 0)
        throw std::runtime_error("Invalid input. Square root of a negative number is undefined.");

    return sqrt(num);
}

// Function to calculate the n-th root
double calculateRoot(double num, double root)
{
    if (root == 0)
        throw std::runtime_error("Invalid input. Root must be non-zero.");

    if (num < 0 && fmod(root, 2) == 0)
        throw std::runtime_error("Invalid input. Cannot calculate even root of a negative number.");

    return pow(num, 1 / root);
}

// Function to calculate the power of a number
double calculatePower(double base, double exponent)
{
    return pow(base, exponent);
}

// Function to calculate the sine
double calculateSin(double angle)
{
    return sin(angle);
}

// Function to calculate the cosine
double calculateCos(double angle)
{
    return cos(angle);
}

// Function to calculate the tangent
double calculateTan(double angle)
{
    return tan(angle);
}

// Function to calculate the logarithm
double calculateLog(double num, double base)
{
    return log(num) / log(base);
}

// Function to calculate the exponential
double calculateExp(double num)
{
    return exp(num);
}

// Function to calculate the percentage
double calculatePercentage(double num, double percent)
{
    return (num * percent) / 100.0;
}

// Function to convert currency
double convertCurrency(double amount, const std::string& fromCurrency, const std::string& toCurrency,
    const std::map<std::string, double>& exchangeRates)
{
    if (exchangeRates.count(fromCurrency) == 0 || exchangeRates.count(toCurrency) == 0)
        throw std::runtime_error("Currency not found in exchange rates.");

    double conversionRate = exchangeRates.at(toCurrency) / exchangeRates.at(fromCurrency);
    return amount * conversionRate;
}

// Function to convert units
double convertUnits(double value, const std::string& fromUnit, const std::string& toUnit,
    const std::map<std::string, double>& conversionRates)
{
    if (conversionRates.count(fromUnit) == 0 || conversionRates.count(toUnit) == 0)
        throw std::runtime_error("Unit not found in conversion rates.");

    double conversionRate = conversionRates.at(toUnit) / conversionRates.at(fromUnit);
    return value * conversionRate;
}

// Function to convert mass units
double convertMass(double value, const std::string& fromUnit, const std::string& toUnit,
    const std::map<std::string, double>& conversionRates)
{
    if (conversionRates.count(fromUnit) == 0 || conversionRates.count(toUnit) == 0)
        throw std::runtime_error("Unit not found in mass conversion rates.");

    double conversionRate = conversionRates.at(toUnit) / conversionRates.at(fromUnit);
    return value * conversionRate;
}

// Function to convert temperature units
double convertTemperature(double value, const std::string& fromUnit, const std::string& toUnit)
{
    if (fromUnit == "Celsius" && toUnit == "Fahrenheit")
        return (value * 9.0 / 5.0) + 32.0;
    else if (fromUnit == "Fahrenheit" && toUnit == "Celsius")
        return (value - 32.0) * 5.0 / 9.0;
    else if (fromUnit == "Celsius" && toUnit == "Kelvin")
        return value + 273.15;
    else if (fromUnit == "Kelvin" && toUnit == "Celsius")
        return value - 273.15;
    else if (fromUnit == "Fahrenheit" && toUnit == "Kelvin")
        return (value + 459.67) * 5.0 / 9.0;
    else if (fromUnit == "Kelvin" && toUnit == "Fahrenheit")
        return (value * 9.0 / 5.0) - 459.67;

    throw std::runtime_error("Invalid temperature units.");
}

// Function to display the menu and get user's choice
std::string getMenuChoice()
{
    std::string choice;

    std::cout << "=======================" << std::endl;
    std::cout << "Scientific Calculator" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Square Root" << std::endl;
    std::cout << "6. N-th Root" << std::endl;
    std::cout << "7. Exponentiation" << std::endl;
    std::cout << "8. Sine" << std::endl;
    std::cout << "9. Cosine" << std::endl;
    std::cout << "10. Tangent" << std::endl;
    std::cout << "11. Logarithm" << std::endl;
    std::cout << "12. Exponential" << std::endl;
    std::cout << "13. Percentage" << std::endl;
    std::cout << "14. Currency Conversion" << std::endl;
    std::cout << "15. Unit Conversion (Length)" << std::endl;
    std::cout << "16. Unit Conversion (Mass)" << std::endl;
    std::cout << "17. Unit Conversion (Temperature)" << std::endl;
    std::cout << "18. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::getline(std::cin, choice);

    return choice;
}

int main()
{
    // Exchange rates for currency conversion
    std::map<std::string, double> exchangeRates{
        {"USD", 1.0},
        {"EUR", 0.82},
        {"GBP", 0.71},
        {"JPY", 110.21},
        {"IND", 74.0},
        // Add more exchange rates as needed
    };

    // Conversion rates for unit conversion
    std::map<std::string, double> conversionRates{
        {"meter", 1.0},
        {"foot", 3.28084},
        {"inch", 39.3701},
        {"km",0.001},
        {"miles",0.0016},
        // Add more conversion rates as needed
    };

    // Conversion rates for mass unit conversion
    std::map<std::string, double> massConversionRates{
        {"kilogram", 1.0},
        {"gram", 1000.0},
        {"pound", 2.20462},
        // Add more mass conversion rates as needed
    };

    std::string choice;
    double num1, num2;

    while (true)
    {
        clearScreen();
        choice = getMenuChoice();
        std::cout << std::endl;

        if (choice == "18")
        {
            std::cout << "Exiting the calculator..." << std::endl;
            break;
        }

        try
        {
            

                if (choice == "1"){std::cout << "Enter the first number: ";
                std::cin >> num1;
                std::cout << "Enter the second number: ";
                std::cin >> num2;
                    std::cout << "Result: " << num1 + num2 << std::endl;
            }    else if (choice == "2")
    {std::cout << "Enter the first number: ";
                std::cin >> num1;
                std::cout << "Enter the second number: ";
                std::cin >> num2;                std::cout << "Result: " << num1 - num2 << std::endl;
        }        else if (choice == "3")
                 {std::cout << "Enter the first number: ";
                std::cin >> num1;
                std::cout << "Enter the second number: ";
                std::cin >> num2;   std::cout << "Result: " << num1 * num2 << std::endl;
              }  else if (choice == "4")
                {std::cout << "Enter the first number: ";
                std::cin >> num1;
                std::cout << "Enter the second number: ";
                std::cin >> num2;
                    if (num2 == 0)
                        throw std::runtime_error("Division by zero is undefined.");

                    std::cout << "Result: " << num1 / num2 << std::endl;
                }
            
            else if (choice == "5")
            {
                std::cout << "Enter the number: ";
                std::cin >> num1;
                std::cout << "Result: " << calculateSqrt(num1) << std::endl;
            }
            else if (choice == "6")
            {
                std::cout << "Enter the number: ";
                std::cin >> num1;
                std::cout << "Enter the root: ";
                std::cin >> num2;
                std::cout << "Result: " << calculateRoot(num1, num2) << std::endl;
            }
            else if (choice == "7")
            {
                std::cout << "Enter the base: ";
                std::cin >> num1;
                std::cout << "Enter the exponent: ";
                std::cin >> num2;
                std::cout << "Result: " << calculatePower(num1, num2) << std::endl;
            }
            else if (choice == "8")
            {
                std::cout << "Enter the angle in radians: ";
                std::cin >> num1;
                std::cout << "Result: " << calculateSin(num1) << std::endl;
            }
            else if (choice == "9")
            {
                std::cout << "Enter the angle in radians: ";
                std::cin >> num1;
                std::cout << "Result: " << calculateCos(num1) << std::endl;
            }
            else if (choice == "10")
            {
                std::cout << "Enter the angle in radians: ";
                std::cin >> num1;
                std::cout << "Result: " << calculateTan(num1) << std::endl;
            }
            else if (choice == "11")
            {
                std::cout << "Enter the number: ";
                std::cin >> num1;
                std::cout << "Enter the base of the logarithm: ";
                std::cin >> num2;
                std::cout << "Result: " << calculateLog(num1, num2) << std::endl;
            }
            else if (choice == "12")
            {
                std::cout << "Enter the number: ";
                std::cin >> num1;
                std::cout << "Result: " << calculateExp(num1) << std::endl;
            }
            else if (choice == "13")
            {
                std::cout << "Enter the number: ";
                std::cin >> num1;
                std::cout << "Enter the percentage: ";
                std::cin >> num2;
                std::cout << "Result: " << calculatePercentage(num1, num2) << std::endl;
            }
            else if (choice == "14")
            {
                std::string fromCurrency, toCurrency;
                double amount;

                std::cout << "Enter the amount: ";
                std::cin >> amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter the currency to convert from (e.g., USD, EUR, GBP, JPY, IND): ";
                std::getline(std::cin, fromCurrency);
                std::cout << "Enter the currency to convert to (e.g., USD, EUR, GBP, JPY, IND): ";
                std::getline(std::cin, toCurrency);

                double convertedAmount = convertCurrency(amount, fromCurrency, toCurrency, exchangeRates);
                std::cout << "Result: " << convertedAmount << " " << toCurrency << std::endl;
            }
            else if (choice == "15")
            {
                std::string fromUnit, toUnit;

                std::cout << "Enter the value: ";
                std::cin >> num1;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter the unit to convert from (e.g., meter, foot, inch, km, miles): ";
                std::getline(std::cin, fromUnit);
                std::cout << "Enter the unit to convert to (e.g., meter, foot, inch, km, miles): ";
                std::getline(std::cin, toUnit);

                double convertedValue = convertUnits(num1, fromUnit, toUnit, conversionRates);
                std::cout << "Result: " << convertedValue << " " << toUnit << std::endl;
            }
            else if (choice == "16")
            {
                std::string fromUnit, toUnit;

                std::cout << "Enter the value: ";
                std::cin >> num1;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter the unit to convert from (e.g., kilogram, gram, pound): ";
                std::getline(std::cin, fromUnit);
                std::cout << "Enter the unit to convert to (e.g., kilogram, gram, pound): ";
                std::getline(std::cin, toUnit);

                double convertedValue = convertMass(num1, fromUnit, toUnit, massConversionRates);
                std::cout << "Result: " << convertedValue << " " << toUnit << std::endl;
            }
            else if (choice == "17")
            {
                std::string fromUnit, toUnit;

                std::cout << "Enter the value: ";
                std::cin >> num1;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter the unit to convert from (e.g., Celsius, Fahrenheit, Kelvin): ";
                std::getline(std::cin, fromUnit);
                std::cout << "Enter the unit to convert to (e.g., Celsius, Fahrenheit, Kelvin): ";
                std::getline(std::cin, toUnit);

                double convertedValue = convertTemperature(num1, fromUnit, toUnit);
                std::cout << "Result: " << convertedValue << " " << toUnit << std::endl;
            }
            else
            {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }

    return 0;
}
