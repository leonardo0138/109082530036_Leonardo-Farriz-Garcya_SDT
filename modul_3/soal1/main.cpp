#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa data[MAX]; 
    int n;

    do {
        cout << "Jumlah mahasiswa (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        inputMhs(data[i]);
    }

    cout << "\n=== DATA MAHASISWA ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        tampilkanMhs(data[i]);
    }

    return 0;
}