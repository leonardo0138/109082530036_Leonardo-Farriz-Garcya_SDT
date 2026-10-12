#include "mahasiswa.h"

float hitungNilaiAkhir(float uts, float uas, float tugas)
{
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

void inputMhs(mahasiswa &m)
{
    cout << "nama   : ";
    cin >> m.nama;
    cout << "NIM    : ";
    cin >> m.nim;
    cout << "Nilai UTS    : ";
    cin >> m.uts;
    cout << "Nilai UAS    : ";
    cin >> m.uas;
    cout << "Nilai tugas  : ";
    cin >> m.tugas;
    m.nilaiAkhir = hitungNilaiAkhir(m.uts, m.uas, m.tugas);
}

void tampilkanMhs(mahasiswa m)
{
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "UTS         : " << m.uts << endl;
    cout << "UAS         : " << m.uas << endl;
    cout << "Tugas       : " << m.tugas << endl;
    cout << "Nilai akhir : " << m.nilaiAkhir << endl;
}