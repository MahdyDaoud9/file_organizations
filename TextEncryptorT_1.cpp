#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// دالة لتشفير النص باستخدام تشفير قيصر
string caesarEncrypt(const string& text, int shift) {
    string encryptedText = text;
    for (char& c : encryptedText) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }
    return encryptedText;
}

// دالة لفك تشفير النص باستخدام تشفير قيصر
string caesarDecrypt(const string& text, int shift) {
    return caesarEncrypt(text, 26 - shift);
}

int main() {
    string filePath;
    cout << "Enter the path to the text file: ";
    cin >> filePath;

    ifstream inputFile(filePath);
    if (!inputFile) {
        cerr << "Unable to open file: " << filePath << endl;
        return 1;
    }

    string text((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    int shift;
    cout << "Enter the shift value for Caesar Cipher: ";
    cin >> shift;

    string encryptedText = caesarEncrypt(text, shift);
    cout << "Encrypted Text: " << endl << encryptedText << endl;

    string decryptedText = caesarDecrypt(encryptedText, shift);
    cout << "Decrypted Text: " << endl << decryptedText << endl;

    return 0;
}