#pragma once
#include <string>

class CaesarCipher {
public:
    static std::string encrypt(const std::string& text, int shift);
    static std::string decrypt(const std::string& text, int shift);

    static char shiftChar(char c, int shift);
};
