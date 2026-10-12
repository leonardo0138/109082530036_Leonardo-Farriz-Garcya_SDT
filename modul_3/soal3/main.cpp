#include <iostream>
#include "tukar.h"

using namespace std;

int main() {
    int A[BARIS][KOLOM] = {{5, 1, 9}, {3, 7, 2}, {8, 4, 6}};
    int B[BARIS][KOLOM] = {{11, 22, 33}, {44, 55, 66}, {77, 88, 99}};

    int x = 15, y = 42;
    int *p1 = &x;
    int *p2 = &y;

    cout << " Array sebelum ditukar " << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    tukarArray(A, B, 2, 0);

    cout << "\n Array setelah ditukar pada posisi [2][0] " << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    cout << "\n Pointer sebelum ditukar " << endl;
    cout << "x = " << *p1 << ", y = " << *p2 << endl;

    tukarPointer(p1, p2);

    cout << " Pointer setelah ditukar " << endl;
    cout << "x = " << *p1 << ", y = " << *p2 << endl;

    return 0;
}