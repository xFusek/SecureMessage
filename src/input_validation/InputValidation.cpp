#include "InputValidation.h"
#include <cctype>
#include <unordered_map>

bool InputValidation::isValidVigenereKey(const std::string& key) {
    if (key.empty()) return false;
    for (char c : key) {
        if (!isalpha(c)) return false;
    }
    return true;
}

bool InputValidation::isValidCaesarShift(int shift) {
    return shift > 0 && shift < 26;
}

bool InputValidation::isValidSubstitutionKey(const std::unordered_map<char, char>& key) {
    return key.size() == 26; // Zakładając, że klucz zawiera mapowanie dla każdej litery alfabetu
}

bool InputValidation::isValidXORKey(char key) {
    return key != 0; // Upewniamy się, że klucz nie jest równy 0
}

