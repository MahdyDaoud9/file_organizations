#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void processBuffer(const vector<char>& buffer) {
    // مثال بسيط لمعالجة البيانات: حساب عدد الأحرف
    size_t charCount = 0;
    for (char c : buffer) {
        if (isalpha(c)) {
            ++charCount;
        }
    }
    cout << "Number of alphabetic characters in buffer: " << charCount << endl;
}

void readFileWithBuffer(const string& filePath, size_t bufferSize) {
    ifstream inputFile(filePath, ios::binary);
    if (!inputFile) {
        cerr << "Unable to open file: " << filePath << endl;
        return;
    }

    vector<char> buffer(bufferSize);
    while (inputFile) {
        inputFile.read(buffer.data(), bufferSize);
        streamsize bytesRead = inputFile.gcount();
        if (bytesRead > 0) {
            buffer.resize(bytesRead);  // ضبط حجم المخزن المؤقت لعدد البايتات المقروءة
            processBuffer(buffer);
        }
    }

    inputFile.close();
}

int main() {
    string filePath;
    cout << "Enter the path to the file: ";
    cin >> filePath;

    size_t bufferSize;
    cout << "Enter the buffer size: ";
    cin >> bufferSize;

    readFileWithBuffer(filePath, bufferSize);

    return 0;
}