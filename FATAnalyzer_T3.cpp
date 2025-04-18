#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct FATEntry {
    uint16_t nextCluster;
};

void readFAT(const string& filePath) {
    ifstream file(filePath, ios::binary);
    if (!file) {
        cerr << "Unable to open file: " << filePath << endl;
        return;
    }

    // Assuming a simple FAT12/FAT16 structure for demonstration
    vector<FATEntry> fatTable;

    // Read the FAT table (this is a simplified example)
    while (file) {
        FATEntry entry;
        file.read(reinterpret_cast<char*>(&entry.nextCluster), sizeof(entry.nextCluster));
        if (file) {
            fatTable.push_back(entry);
        }
    }

    file.close();

    // Display the FAT table entries
    for (size_t i = 0; i < fatTable.size(); ++i) {
        cout << "Cluster " << i << ": Next Cluster = " << fatTable[i].nextCluster << endl;
    }
}

int main() {
    string filePath;
    cout << "Enter the path to the FAT image file: ";
    cin >> filePath;

    readFAT(filePath);

    return 0;
}