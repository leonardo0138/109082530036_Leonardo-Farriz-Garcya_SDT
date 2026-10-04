#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    int pilih;

    cout << "Masukkan matriks A" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "Masukkan matriks B" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    do {
        cout << "\n--- Menu Matriks ---" << endl;
        cout << "1. Penjumlahan" << endl;
        cout << "2. Pengurangan" << endl;
        cout << "3. Perkalian" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Hasil A + B:" << endl;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    C[i][j] = A[i][j] + B[i][j];
                    cout << C[i][j] << "\t";
                }
                cout << endl;
            }
        }

        if (pilih == 2) {
            cout << "Hasil A - B:" << endl;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    C[i][j] = A[i][j] - B[i][j];
                    cout << C[i][j] << "\t";
                }
                cout << endl;
            }
        }

        if (pilih == 3) {
            cout << "Hasil A * B:" << endl;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    C[i][j] = 0;

                    for (int k = 0; k < 3; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }

                    cout << C[i][j] << "\t";
                }
                cout << endl;
            }
        }

    } while (pilih != 0);

    return 0;
}