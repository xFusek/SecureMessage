#include "XORCipher.h"

std::string XORCipher::encryptDecrypt(const std::string& text, char key) {
    std::string output = text;
    for (size_t i = 0; i < text.size(); ++i) {
        output[i] = text[i] ^ key;
    }
    return output;
}
