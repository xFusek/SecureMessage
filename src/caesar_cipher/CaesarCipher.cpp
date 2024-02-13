#include <string>
#include "CaesarCipher.h"

std::string CaesarCipher::encrypt(const std::string& text, int shift) {
    std::string encryptedText = text;
    for (char &c : encryptedText) {
        c = shiftChar(c, shift);
    }
    return encryptedText;
}

std::string CaesarCipher::decrypt(const std::string& text, int shift) {
    return encrypt(text, -shift);
}

char CaesarCipher::shiftChar(char c, int shift) {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        c = static_cast<char>(((c - base + shift) % 26) + base);
    }
    return c;
}
