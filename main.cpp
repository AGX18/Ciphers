#include <iostream>
#include <string>

char symbols[83] =  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'Z', '0', '1', '2', '3',
                     '4', '5', '6', '7', '8', '9', '.', ',', '?', '!',
                     '(', ')', '-', '_', '+', '=', '*', '&', '^', '%',
                     '$', '#', '@', '/', '\\', '<', '>', '|', '[', ']',
                     '{', '}', '"', '\'', ':', ';', ' ','a', 'b', 'c',
                     'd','e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o',
                     'p', 'q','r', 's', 't', 'u', 'v', 'z' };

// Function to map Italian characters to integers
int charToInt(char c) {
    for(int i =0; i < 83; i++) {
        if (symbols[i] == c) {
            return i;
        }
    }
    return -1;
}

char intToChar(int i) {
    return symbols[i];
}

// Function to encrypt a character
char AffineEncryptCharacter(char c, int a, int b) {
    int i = charToInt(c);
    if (i == -1) {
        return c;
    }
    int newIndex = (a * i + b) % 83;
    return intToChar(newIndex);
}

// Function to encrypt a string
std::string AffineCipher(std::string message, int a, int b) {
    std::string encryptedMessage;
    for (char c : message) {
        encryptedMessage += AffineEncryptCharacter(c, a, b);
    }
    return encryptedMessage;
}


int main() {
    std::string message = "CRIPTA QUESTO TESTO";
    int a = 7;
    int b = 7;

    // Encrypt the message
    std::string encryptedMessage = AffineCipher(message, a, b);

    //result
    std::cout << encryptedMessage << std::endl;

    return 0;
}



