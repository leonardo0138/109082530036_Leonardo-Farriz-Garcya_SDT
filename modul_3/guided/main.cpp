#include <iostream>
#include "buku.h"

using namespace std;

int main() {
    buku novel;

    string judul, penulis;
    int halaman;

    cout << "Masukkan judul buku: ";
    cin >> judul;
    cout << "Masukkan halaman buku: ";
    cin >> halaman;
    cout << "Masukkan penulis buku: ";
    cin >> penulis;

    editIsi(judul, halaman, penulis, novel);
    tampilkanIsiBuku(novel);

    cout << checkPenulis(novel);
    
    return 0;
}