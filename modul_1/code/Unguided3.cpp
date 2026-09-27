#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < n - i; j++) {
            cout << "  ";
        }
        if (i == 0) {
            cout << "*";
        } else {
            for (int j = i; j >= 1; j--) {
                cout << j << " ";
            }
            cout << "*";
            for (int j = 1; j <= i; j++) {
                cout << " " << j;
            }
        }
        cout << endl;
    }
    return 0;
}