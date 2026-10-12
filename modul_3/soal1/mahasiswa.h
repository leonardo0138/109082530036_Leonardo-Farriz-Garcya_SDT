#ifndef MAHASISWA_H
#define MAHASISWA_H
#include <iostream>

using namespace std;

const int MAX = 10;

struct mahasiswa
{
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};
void inputMhs(mahasiswa &m);

float hitungNilaiAkhir(float uts, float uas, float tugas);
void tampilkanMhs(mahasiswa m);

#endif