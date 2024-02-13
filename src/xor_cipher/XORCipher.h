#pragma once
#include <string>

class XORCipher {
public:
    static std::string encryptDecrypt(const std::string& text, char key);
};
