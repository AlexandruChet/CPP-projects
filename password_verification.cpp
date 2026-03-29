#include <iostream>
#include <string>
#include <vector>
#include <chrono>

void pas_loop(const std::string& pas) {
    static const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ?!@#$%^&*()_+-=";

    std::string result;
    result.reserve(pas.length());

    auto start = std::chrono::high_resolution_clock::now();
    long long total_attempts = 0;

    std::ios_base::sync_with_stdio(false);

    for (const char c : pas) {
        bool found = false;
        for (size_t i = 0; i < charset.length(); ++i) {
            total_attempts++;
            if (charset[i] == c) {
                result += c;
                found = true;
                break;
            }
        }
        if (!found) result += 'not found ERROR!!!';
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end - start;

    std::cout << "\nResult: " << result 
              << "\nAttempts: " << total_attempts 
              << "\nTime: " << time.count() << " seconds" << std::endl;
}

bool check_characters(std::string password) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (unsigned char p : password) {
        if (std::isupper(p)) hasUpper = true;
        else if (std::islower(p)) hasLower = true;
        else if (std::isdigit(p)) hasDigit = true;
        else if (std::ispunct(p)) hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

void password_verification(std::string pas) {
    bool is_length_ok = (pas.size() >= 12);
    bool is_chars_ok = check_characters(pas);

    if (!is_length_ok)
        std::cout << "Error: Password is too short min 12 chars" << std::endl;

    if (!is_chars_ok)
        std::cout << "Error: Password must contain upper, lower, digits and special chars" << std::endl;

    if (is_length_ok && is_chars_ok)
        std::cout << "Your password is completely correct" << std::endl;
}

void help(std::vector<std::string> password_rules) {
    for (std::string rule : password_rules)
        std::cout << "-> " << rule << "\n";
}

int main() {
    std::string input;
    std::vector<std::string> my_rules = {
        "Minimum length: 12 symbols",
        "At least one uppercase letter",
        "At least one lowercase letter",
        "At least one digit",
        "At least one special character"
    };

    while(true) {
        std::cout << "Please write your password, and write exit to to exit the program, and help to see good password rules, If you want to see how much it will cost to find your password, type check: ";
        std::cin >> input;
        password_verification(input);

        if (input == "exit") {
            std::cout << "Exiting the program..." << std::endl;
            exit(0);
        }

        if (input == "help") {
            help(my_rules);
            continue;
        }

        if (input == "check") {
            std::string target_pas;
            std::cout << "Please write your password: " << std::endl;
            std:: cin >> target_pas;
            pas_loop(target_pas);
        }
    }

    return 0;
}
