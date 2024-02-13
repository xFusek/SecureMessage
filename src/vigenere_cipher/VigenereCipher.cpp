#include "VigenereCipher.h"
#include <cctype>  // Dla std::toupper
#include <algorithm>  // Dla std::transform

std::string VigenereCipher::encrypt(const std::string& text, const std::string& key) {
    std::string upperText = text;
    std::string upperKey = key;

    // Konwersja tekstu i klucza na wielkie litery
    std::transform(upperText.begin(), upperText.end(), upperText.begin(), ::toupper);
    std::transform(upperKey.begin(), upperKey.end(), upperKey.begin(), ::toupper);

    std::string encryptedText;
    size_t keyIndex = 0;
    for (char c : upperText) {
        if (isalpha(c)) {
            int shift = upperKey[keyIndex % upperKey.length()] - 'A';
            encryptedText += (char)(((c - 'A' + shift) % 26) + 'A');
            keyIndex++;
        } else {
            encryptedText += c;
        }
    }
    return encryptedText;
}

std::string VigenereCipher::decrypt(const std::string& text, const std::string& key) {
    std::string upperText = text;
    std::string upperKey = key;

    // Konwersja tekstu i klucza na wielkie litery
    std::transform(upperText.begin(), upperText.end(), upperText.begin(), ::toupper);
    std::transform(upperKey.begin(), upperKey.end(), upperKey.begin(), ::toupper);

    std::string decryptedText;
    size_t keyIndex = 0;
    for (char c : upperText) {
        if (isalpha(c)) {
            int shift = upperKey[keyIndex % upperKey.length()] - 'A';
            decryptedText += (char)(((c - 'A' - shift + 26) % 26) + 'A');
            keyIndex++;
        } else {
            decryptedText += c;
        }
    }
    return decryptedText;
}
