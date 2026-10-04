#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp;
    temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}
void tukarReference(int &a, int &b, int &c) {
    int temp;
    temp = a;
    a = b;
    b = c;
    c = temp;
}
int main() {
    int a, b, c;

    cout << "Masukkan nilai a, b, c: ";
    cin >> a >> b >> c;

    cout << "\nSebelum ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    tukarPointer(&a, &b, &c);
    cout << "\nSetelah ditukar dengan pointer:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    tukarReference(a, b, c);
    cout << "\nSetelah ditukar dengan reference:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}