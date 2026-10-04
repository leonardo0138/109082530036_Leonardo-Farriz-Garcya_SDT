#include <iostream>
using namespace std;

const int N = 10;

int maksimum(int arr[]) {
    int max = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}
int minimum(int arr[]) {
    int min = arr[0];

    for (int i = 1; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void rataRata(int arr[], float &hasil) {
    int jumlah = 0;

    for (int i = 0; i < N; i++) {
        jumlah += arr[i];
    }

    hasil = (float)jumlah / N;
}

int main() {
    int arrA[N] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int pilihan;
    float hasilRataRata;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nIsi array: ";

                for (int i = 0; i < N; i++) {
                    cout << arrA[i] << " ";
                }

                cout << endl;
                break;
            case 2:
                cout << "\nNilai maksimum = "
                     << maksimum(arrA) << endl;
                break;
            case 3:
                cout << "\nNilai minimum = "
                     << minimum(arrA) << endl;
                break;
            case 4:
                rataRata(arrA, hasilRataRata);

                cout << "\nNilai rata-rata = "
                     << hasilRataRata << endl;
                break;
            case 0:
                cout << "\nProgram selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak tersedia." << endl;
        }

    } while (pilihan != 0);

    return 0;
}