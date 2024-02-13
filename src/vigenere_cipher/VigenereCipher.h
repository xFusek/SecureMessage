#pragma once
#include <string>

class VigenereCipher {
public:
    static std::string encrypt(const std::string& text, const std::string& key);
    static std::string decrypt(const std::string& text, const std::string& key);
private:
    static char shiftChar(char c, int shift);
};
