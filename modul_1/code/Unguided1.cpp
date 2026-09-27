#include <iostream>
using namespace std;

int main() {
    float a, b;
    cin >> a >> b;
    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian = " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian = " << a / b << endl;
    } else {
        cout << "Pembagian = Tidak dapat dilakukan" << endl;
    }
    return 0;
}