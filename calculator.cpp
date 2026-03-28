#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Calculator {
public:
    void logarithms() {
        double num, value;
        std::cout << "Please enter base: ";
        std::cin >> num;
        std::cout << "Please enter value: ";
        std::cin >> value;

        if (num <= 0 || num == 1 || value <= 0) {
            std::cout << "Invalid input for logarithm." << std::endl;
            return;
        }
        else {
            double result = std::log(value) / std::log(num);
            std::cout << "The answer is: " << result << std::endl;
        }
    }

    void figure_area() {
        std::vector<std::string> areas = {"square", "triangle", "rectangle", "rhomb", "trapezoid"};
        std::cout << "Available figures: ";
        for (const auto &e : areas)
            std::cout << e << " ";

        std::cout << "\nChoose variant: ";

        std::string variant;
        std::cin >> variant;

        if (variant == "square" || variant == "rectangle") {
            double h, w;
            std::cout << "Enter length and width: ";
            std::cin >> h >> w;
            std::cout << "Area: " << h * w << std::endl;
        }
        else if (variant == "triangle") {
            double b, h;
            std::cout << "Enter base and height: ";
            std::cin >> b >> h;
            std::cout << "Area: " << 0.5 * b * h << std::endl;
        }
        else if (variant == "rhomb") {
            double d1, d2;
            std::cout << "Enter diagonals: ";
            std::cin >> d1 >> d2;
            std::cout << "Area: " << (d1 * d2) / 2.0 << std::endl;
        }
        else if (variant == "trapezoid") {
            double a, b, h;
            std::cout << "Enter bases (a, b) and height (h): ";
            std::cin >> a >> b >> h;
            std::cout << "Area: " << ((a + b) / 2.0) * h << std::endl;
        }
        else {
            std::cout << "Error invalid command" << std::endl;
        }
    }

    void bank_calculation() {
        std::vector<std::string> variants = {"time", "default_value", "end_value"};
        for (const auto &e : variants)
            std::cout << e << " ";

        std::string variant;
        std::cout << "\nPlease write command: ";
        std::cin >> variant;

        if (variant == "time") {
            double percent, start, end;
            std::cout << "Start value: ";
            std::cin >> start;
            std::cout << "End value: ";
            std::cin >> end;
            std::cout << "Percent: ";
            std::cin >> percent;

            double q = 1.0 + (percent / 100.0);
            double result = std::log(end / start) / std::log(q);
            std::cout << "Time needed: " << result << std::endl;
        }
        else if (variant == "default_value") {
            double percent, end, time;
            std::cout << "End value: ";
            std::cin >> end;
            std::cout << "Percent: ";
            std::cin >> percent;
            std::cout << "Time: ";
            std::cin >> time;

            double q = 1.0 + (percent / 100.0);
            double result = end / std::pow(q, time);
            std::cout << "Original value: " << result << std::endl;
        }
        else if (variant == "end_value") {
            double percent, start, time;
            std::cout << "Start value: ";
            std::cin >> start;
            std::cout << "Percent: ";
            std::cin >> percent;
            std::cout << "Time: ";
            std::cin >> time;

            double q = 1.0 + (percent / 100.0);
            double result = start * std::pow(q, time);
            std::cout << "Future value: " << result << std::endl;
        }
    }

    void default_math() {
        double first_num, second_num;
        char op;

        std::cout << "Write first number: ";
        std::cin >> first_num;

        std::cout << "Write operator (+, -, *, /, ^ for power, s for square root): ";
        std::cin >> op;

        if (op != 's'){
            std::cout << "Write second number: ";
            std::cin >> second_num;
        }

        switch (op)
        {
        case '+':
            std::cout << "Result: " << first_num + second_num << std::endl;
            break;
        case '-':
            std::cout << "Result: " << first_num - second_num << std::endl;
            break;
        case '*':
            std::cout << "Result: " << first_num * second_num << std::endl;
            break;
        case '/':
            if (second_num == 0) {
                std::cout << "Error: division by zero" << std::endl;
            }
            else {
                std::cout << "Result: " << first_num / second_num << std::endl;
            }
            break;
        case '^':
            std::cout << "Result: " << pow(first_num, second_num) << std::endl;
            break;
        case 's':
            if (first_num < 0) {
                std::cout << "Error: negative number under sqrt" << std::endl;
            }
            else {
                std::cout << "Result: " << sqrt(first_num) << std::endl;
            }
            break;
        default:
            std::cout << "Unknown operator" << std::endl;
        }
    }
};

int main() {
    Calculator calc;
    int choice;

    std::cout << "1. Basic Math\n2. Logarithms\n3. Area\n4. Bank math\n0. Exit\nChoice: ";
    std::cin >> choice; 

    while (true) {
        if (choice == 0) break;

        switch (choice) {
            case 1: calc.default_math(); break;
            case 2: calc.logarithms(); break;
            case 3: calc.figure_area(); break;
            case 4: calc.bank_calculation(); break;
            default: std::cout << "Try again and write default command" << std::endl;
        }
    }

    return 0;
}