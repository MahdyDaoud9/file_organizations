#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void replaceWordInFile(const string& filePath, const string& oldWord, const string& newWord) {
    ifstream fileIn(filePath);
    if (!fileIn) {
        cerr << "Unable to open file for reading: " << filePath << endl;
        return;
    }

    string tempFilePath = "temp.txt";
    ofstream fileOut(tempFilePath);
    if (!fileOut) {
        cerr << "Unable to open file for writing: " << tempFilePath << endl;
        return;
    }

    string line;
    while (getline(fileIn, line)) {
        size_t pos = 0;
        while ((pos = line.find(oldWord, pos)) != string::npos) {
            line.replace(pos, oldWord.length(), newWord);
            pos += newWord.length();
        }
        fileOut << line << endl;
    }

    fileIn.close();
    fileOut.close();

    // Replace the original file with the modified file
    if (remove(filePath.c_str()) != 0) {
        cerr << "Error deleting original file" << endl;
        return;
    }
    if (rename(tempFilePath.c_str(), filePath.c_str()) != 0) {
        cerr << "Error renaming temporary file" << endl;
    }
}

int main() {
    string filePath, oldWord, newWord;
    cout << "Enter the file path: ";
    cin >> filePath;
    cout << "Enter the word to be replaced: ";
    cin >> oldWord;
    cout << "Enter the new word: ";
    cin >> newWord;

    replaceWordInFile(filePath, oldWord, newWord);

    cout << "Word replacement completed." << endl;
    return 0;
}