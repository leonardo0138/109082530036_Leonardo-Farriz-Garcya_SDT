#include <iostream>
using namespace std;
int main() {
    int angka;
    cin >> angka;
    string kata[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan"
    };
    if (angka < 10) {
        cout << kata[angka];
    } else if (angka < 20) {
        if (angka == 10)
            cout << "sepuluh";
        else if (angka == 11)
            cout << "sebelas";
        else
            cout << kata[angka - 10] << " belas";
    } else if (angka < 100) {
        cout << kata[angka / 10] << " puluh";

        if (angka % 10 != 0)
            cout << " " << kata[angka % 10];
    } else {
        cout << "seratus";
    }
    return 0;
}