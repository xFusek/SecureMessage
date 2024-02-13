#include "../src/caesar_cipher/CaesarCipher.h"
#include "../src/vigenere_cipher/VigenereCipher.h"
#include "../src/substitution_cipher/SubstitutionCipher.h"
#include "../src/xor_cipher/XORCipher.h"
#include <gtest/gtest.h>

// Testy dla Szyfru Cezara
TEST(CaesarCipherTest, EncryptDecrypt) {
std::string original = "HelloWorld";
int shift = 3;
std::string encrypted = CaesarCipher::encrypt(original, shift);
std::string decrypted = CaesarCipher::decrypt(encrypted, shift);
EXPECT_EQ(original, decrypted);
}

// Testy dla Szyfru Vigenere'a
TEST(VigenereCipherTest, EncryptDecrypt) {
std::string original = "TEST";
std::string key = "KEY";
std::string encrypted = VigenereCipher::encrypt(original, key);
std::string decrypted = VigenereCipher::decrypt(encrypted, key);
EXPECT_EQ(original, decrypted);
}

// Testy dla Szyfru Podstawieniowego
TEST(SubstitutionCipherTest, EncryptDecrypt) {
    std::string original = "HELLOWORLD";
    std::unordered_map<char, char> key = {{'A', 'Q'}, {'B', 'W'}, {'C', 'E'}, {'D', 'R'}, {'E', 'T'},
                                          {'F', 'Y'}, {'G', 'U'}, {'H', 'I'}, {'I', 'O'}, {'J', 'P'},
                                          {'K', 'A'}, {'L', 'S'}, {'M', 'D'}, {'N', 'F'}, {'O', 'G'},
                                          {'P', 'H'}, {'Q', 'J'}, {'R', 'K'}, {'S', 'L'}, {'T', 'Z'},
                                          {'U', 'X'}, {'V', 'C'}, {'W', 'V'}, {'X', 'B'}, {'Y', 'N'},
                                          {'Z', 'M'}};

    std::string encrypted = SubstitutionCipher::encrypt(original, key);
    std::string decrypted = SubstitutionCipher::decrypt(encrypted, key);
    EXPECT_EQ(original, decrypted);
}


// Testy dla Szyfru XOR
TEST(XORCipherTest, EncryptDecrypt) {
    std::string original = "HELLOWORLD";
    char key = 'K';

    std::string encrypted = XORCipher::encryptDecrypt(original, key);
    std::string decrypted = XORCipher::encryptDecrypt(encrypted, key);
    EXPECT_EQ(original, decrypted);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
