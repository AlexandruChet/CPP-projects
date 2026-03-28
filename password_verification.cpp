#include <iostream>
#include <string>
#include <cctype>

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

    if (!is_length_ok) {
        std::cout << "Error: Password is too short min 12 chars" << std::endl;
    }
    
    if (!is_chars_ok) {
        std::cout << "Error: Password must contain upper, lower, digits and special chars" << std::endl;
    }

    if (is_length_ok && is_chars_ok) {
        std::cout << "Your password is completely correct" << std::endl;
    }
}

int main() {
    std::string password;
    std::cout << "Please write your password: ";
    std::cin >> password;
    password_verification(password);
    return 0;
}
