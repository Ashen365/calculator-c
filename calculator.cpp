#include <iostream>
#include <limits>
#include <cmath>
#include <string>

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    char operation;
    double number1, number2, result;
    double memory = 0;
    bool continueCalculating = true;

    std::cout << "Simple Calculator App\n";
    std::cout << "=====================\n";
    std::cout << "Supported operations: +, -, *, /, ^ (power), s (sqrt), M (store), R (recall), C (clear memory)\n";

    while (continueCalculating)
    {
        // Get first number (or recall from memory)
        std::cout << "\nEnter first number (or type 'R' to recall memory): ";
        std::string input1;
        std::cin >> input1;
        if (input1 == "R" || input1 == "r")
        {
            number1 = memory;
            std::cout << "Recalled: " << memory << std::endl;
        }
        else
        {
            try
            {
                number1 = std::stod(input1);
            }
            catch (...)
            {
                std::cout << "Invalid input. Please enter a number." << std::endl;
                clearInputBuffer();
                continue;
            }
        }

        // Get operation
        std::cout << "Enter operation (+, -, *, /, ^, s, M, R, C): ";
        std::cin >> operation;

        // Handle single-operand and memory operations
        if (operation == 's')
        {
            // Square root
            if (number1 >= 0)
            {
                result = sqrt(number1);
                std::cout << "sqrt(" << number1 << ") = " << result << std::endl;
            }
            else
            {
                std::cout << "Error: Negative input for square root." << std::endl;
            }
        }
        else if (operation == 'M' || operation == 'm')
        {
            memory = number1;
            std::cout << "Stored " << number1 << " in memory." << std::endl;
        }
        else if (operation == 'R' || operation == 'r')
        {
            std::cout << "Memory: " << memory << std::endl;
        }
        else if (operation == 'C' || operation == 'c')
        {
            memory = 0;
            std::cout << "Memory cleared." << std::endl;
        }
        else if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^')
        {
            // Get second number (or recall from memory)
            std::cout << "Enter second number (or type 'R' to recall memory): ";
            std::string input2;
            std::cin >> input2;
            if (input2 == "R" || input2 == "r")
            {
                number2 = memory;
                std::cout << "Recalled: " << memory << std::endl;
            }
            else
            {
                try
                {
                    number2 = std::stod(input2);
                }
                catch (...)
                {
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                    clearInputBuffer();
                    continue;
                }
            }

            // Perform calculation
            switch (operation)
            {
            case '+':
                result = number1 + number2;
                std::cout << number1 << " + " << number2 << " = " << result << std::endl;
                break;
            case '-':
                result = number1 - number2;
                std::cout << number1 << " - " << number2 << " = " << result << std::endl;
                break;
            case '*':
                result = number1 * number2;
                std::cout << number1 << " * " << number2 << " = " << result << std::endl;
                break;
            case '/':
                if (number2 != 0)
                {
                    result = number1 / number2;
                    std::cout << number1 << " / " << number2 << " = " << result << std::endl;
                }
                else
                {
                    std::cout << "Error: Division by zero is not allowed." << std::endl;
                }
                break;
            case '^':
                result = pow(number1, number2);
                std::cout << number1 << " ^ " << number2 << " = " << result << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Error: Invalid operation." << std::endl;
        }

        // Ask if user wants to continue
        char choice;
        std::cout << "\nDo you want to perform another calculation? (y/n): ";
        std::cin >> choice;
        continueCalculating = (choice == 'y' || choice == 'Y');
    }

    std::cout << "\nThank you for using the calculator app!\n";
    return 0;
}