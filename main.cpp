#include <iostream>
#include <string>



// Function to encrypt a message using the affine cipher
std::string encryptAffineCipher(const std::string& message, int a, int b) {
    std::string encryptedMessage = "";
    int m = 26; // Assuming an alphabet size of 26 (English alphabet)

    for (char c : message) {
        if (isalpha(c)) {
            char encryptedChar = ((a * (c - 'A') + b) % m) + 'A';
            encryptedMessage += encryptedChar;
        } else {
            encryptedMessage += c; // Non-alphabetic characters remain unchanged
        }
    }

    return encryptedMessage;
}



int main() {
    std::string message = "CRIPTA QUESTO TESTO";
    int a = 7; // Key parameter 1
    int b = 7; // Key parameter 2

    std::string encryptedMessage = encryptAffineCipher(message, a, b);
    std::cout << encryptedMessage << std::endl;



    return 0;
}
