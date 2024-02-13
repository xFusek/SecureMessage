#pragma once
#include <string>
#include <unordered_map>

class SubstitutionCipher {
public:
    static std::string encrypt(const std::string& text, const std::unordered_map<char, char>& key);
    static std::string decrypt(const std::string& text, const std::unordered_map<char, char>& key);
};
