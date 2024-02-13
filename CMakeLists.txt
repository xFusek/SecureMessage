cmake_minimum_required(VERSION 3.27)
project(SecureMessage)

set(CMAKE_CXX_STANDARD 17)

add_executable(SecureMessage src/main.cpp
        src/caesar_cipher/CaesarCipher.cpp
        src/caesar_cipher/CaesarCipher.h
        src/vigenere_cipher/VigenereCipher.cpp
        src/vigenere_cipher/VigenereCipher.h
        src/input_validation/InputValidation.cpp
        src/input_validation/InputValidation.h
        src/substitution_cipher/SubstitutionCipher.cpp
        src/substitution_cipher/SubstitutionCipher.h
        src/xor_cipher/XORCipher.cpp
        src/xor_cipher/XORCipher.h
)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(SecureMessageTests
        tests/TestCases.cpp
        src/caesar_cipher/CaesarCipher.cpp
        src/vigenere_cipher/VigenereCipher.cpp
        src/substitution_cipher/SubstitutionCipher.cpp
        src/xor_cipher/XORCipher.cpp

)
target_link_libraries(SecureMessageTests gtest_main)

target_include_directories(SecureMessage PRIVATE ${CMAKE_SOURCE_DIR}/src)
