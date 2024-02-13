#pragma once
#include <string>
#include <unordered_map>

class InputValidation {
public:
    static bool isValidVigenereKey(const std::string& key);
    static bool isValidCaesarShift(int shift);
    static bool isValidSubstitutionKey(const std::unordered_map<char, char>& key);
    static bool isValidXORKey(char key);
    // Inne metody walidacji
};