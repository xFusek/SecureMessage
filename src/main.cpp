#include <iostream>
#include "caesar_cipher/CaesarCipher.h"
#include "vigenere_cipher/VigenereCipher.h"
#include "substitution_cipher/SubstitutionCipher.h"
#include "xor_cipher/XORCipher.h"
#include "input_validation/InputValidation.h"
#include <unordered_map>
#include <algorithm>

int main() {
    int cipherChoice, actionChoice;
    std::string text, key;
    int shift;
    char xorKey;

    std::cout << "Which cipher do you want to use?\n";
    std::cout << "[1] Caesar\n[2] Vigenere\n[3] Substitution\n[4] XOR\n";
    std::cout << "Choose and enter number between [1-4]: ";
    std::cin >> cipherChoice;

    // Walidacja wyboru szyfru
    if (cipherChoice < 1 || cipherChoice > 4) {
        std::cerr << "Invalid input.\n";
        std::cerr << "Choose and enter number between [1-4]";
        return 1;
    }

    std::cout << "\nDo you want to Encrypt or Decrypt?: \n";
    std::cout << "[1] Encrypt\n[2] Decrypt\n";
    std::cout << "Choose and enter [1-2]: ";
    std::cin >> actionChoice;

    // Walidacja wyboru szyfr/deszyfr
    if (actionChoice < 1 || actionChoice > 2) {
        std::cerr << "Invalid input.\n";
        std::cerr << "Choose and enter number between [1-2]";
        return 1;
    }

    std::cout << "\nWhat message do you want to " << (actionChoice == 1 ? "encrypt" : "decrypt") << "? ";
    std::cin.ignore();
    std::getline(std::cin, text);

    switch (cipherChoice) {
        case 1: // Caesar
            std::cout << "Enter shift value: ";
            std::cin >> shift;
            if (!InputValidation::isValidCaesarShift(shift)) {
                std::cerr << "Invalid shift value.\n";
                return 1;
            }
            std::cout << (actionChoice == 1 ? "Encrypted" : "Decrypted") << " Text: "
                      << (actionChoice == 1 ? CaesarCipher::encrypt(text, shift) : CaesarCipher::decrypt(text, shift))
                      << std::endl;
            break;

        case 2: // Vigenere
            std::cout << "Enter key: ";
            std::cin >> key;
            if (!InputValidation::isValidVigenereKey(key)) {
                std::cerr << "Invalid key.\n";
                return 1;
            }

            // Konwersja tekstu i klucza na duże litery
            std::transform(text.begin(), text.end(), text.begin(),
                           [](unsigned char c){ return std::toupper(c); });
            std::transform(key.begin(), key.end(), key.begin(),
                           [](unsigned char c){ return std::toupper(c); });


            std::cout << (actionChoice == 1 ? "Encrypted" : "Decrypted") << " Text: "
                      << (actionChoice == 1 ? VigenereCipher::encrypt(text, key) : VigenereCipher::decrypt(text, key))
                      << std::endl;
            break;

        case 3: { // Substitution
            std::unordered_map<char, char> substitutionKey;
            std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            std::string permutedAlphabet;

            std::cout << "Enter permutation of the alphabet (26 letters): ";
            std::cin >> permutedAlphabet;

            if (permutedAlphabet.length() != 26) {
                std::cerr << "Invalid key length. It must be 26 characters long.\n";
                return 1;
            }

            for (size_t i = 0; i < alphabet.length(); ++i) {
                substitutionKey[alphabet[i]] = permutedAlphabet[i];
            }

            if (!InputValidation::isValidSubstitutionKey(substitutionKey)) {
                std::cerr << "Invalid substitution key.\n";
                return 1;
            }


            // Konwersja tekstu i klucza na duże litery
            std::transform(text.begin(), text.end(), text.begin(),
                           [](unsigned char c){ return std::toupper(c); });
            std::transform(key.begin(), key.end(), key.begin(),
                           [](unsigned char c){ return std::toupper(c); });



            std::cout << (actionChoice == 1 ? "Encrypted" : "Decrypted") << " Text: "
                      << (actionChoice == 1 ? SubstitutionCipher::encrypt(text, substitutionKey) : SubstitutionCipher::decrypt(text, substitutionKey))
                      << std::endl;
            break;
        }

        case 4: // XOR
            std::cout << "Enter key (single character): ";
            std::cin >> xorKey;
            if (!InputValidation::isValidXORKey(xorKey)) {
                std::cerr << "Invalid key.\n";
                return 1;
            }
            std::cout << "XOR " << (actionChoice == 1 ? "Encrypted" : "Decrypted") << " Text: "
                      << XORCipher::encryptDecrypt(text, xorKey) << std::endl;
            break;

        default:
            std::cerr << "Invalid choice.\n";
            return 1;
    }

    return 0;
}
