#include <string>
#include "SubstitutionCipher.h"
#include <unordered_map>

std::string SubstitutionCipher::encrypt(const std::string& text, const std::unordered_map<char, char>& key) {
    std::string encryptedText = text;
    for (char &c : encryptedText) {
        if (key.find(c) != key.end()) {
            c = key.at(c);
        }
    }
    return encryptedText;
}

std::string SubstitutionCipher::decrypt(const std::string& text, const std::unordered_map<char, char>& key) {
    std::string decryptedText = text;
    // Tworzymy odwrotną mapę dla deszyfracji
    std::unordered_map<char, char> reverseKey;
    for (const auto& pair : key) {
        reverseKey[pair.second] = pair.first;
    }

    for (char &c : decryptedText) {
        if (reverseKey.find(c) != reverseKey.end()) {
            c = reverseKey[c];
        }
    }
    return decryptedText;
}

