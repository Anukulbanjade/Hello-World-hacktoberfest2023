#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a message using the Caesar Cipher
string caesarCipherEncrypt(string message, int shift) {
    string encryptedMessage = "";
    for (char c : message) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encryptedMessage += static_cast<char>((c - base + shift) % 26 + base);
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

// Function to decrypt a message using the Caesar Cipher
string caesarCipherDecrypt(string ciphertext, int shift) {
    return caesarCipherEncrypt(ciphertext, 26 - shift); // Decryption is just shifting in the opposite direction.
}

int main() {
    int shift = 3; // Shift value for the Caesar Cipher
    string message = "Hello, World!";
    
    string encryptedMessage = caesarCipherEncrypt(message, shift);
    cout << "Encrypted: " << encryptedMessage << endl;

    string decryptedMessage = caesarCipherDecrypt(encryptedMessage, shift);
    cout << "Decrypted: " << decryptedMessage << endl;

    return 0;
}
