# <h1 align="center">Laporan Praktikum Modul 3 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>

<p align="center">Leonardo Farriz Garcya - 109082530036</p>

# Dasar Teori
 
### A. Konsep Abstract Data Type (ADT)<br/>
 
Abstract Data Type (ADT) merupakan konsep dalam pemrograman yang mendefinisikan suatu tipe data beserta sekumpulan operasi dasar (primitif) yang dapat dilakukan terhadap tipe data tersebut, tanpa perlu memperlihatkan bagaimana tipe data itu direpresentasikan secara internal [3].
 
#### 1. Pengertian ADT
 
ADT pada dasarnya adalah definisi TYPE beserta sekumpulan PRIMITIF yang berlaku terhadap type tersebut, dan bersifat statik karena hanya mendefinisikan spesifikasi, bukan implementasi fisiknya. Satu ADT bahkan bisa memuat definisi ADT lain di dalamnya — misalnya ADT Waktu yang tersusun dari ADT Jam dan ADT Tanggal, atau ADT Garis yang tersusun dari dua buah ADT Point.
 
#### 2. Primitif dalam ADT
 
Primitif adalah kumpulan operasi dasar yang mendefinisikan perilaku suatu ADT, meliputi konstruktor untuk membentuk nilai type baru, selector untuk mengakses komponen di dalamnya, prosedur pengubah nilai, validator untuk menguji batasan type, destruktor untuk menghapus nilai objek, serta operasi baca/tulis, relasional, aritmatika, dan konversi tipe. Dalam konteks prosedural seperti C++, primitif-primitif ini umumnya diterjemahkan menjadi kumpulan fungsi atau prosedur yang bekerja terhadap sebuah struct.
 
#### 3. ADT sebagai Dasar Pemrograman Modular
 
Penerapan ADT sejalan dengan prinsip pemrograman modular, di mana program besar dipecah menjadi bagian-bagian kecil yang saling independen agar lebih mudah dipahami dan dikembangkan [2]. Dengan ADT, detail representasi data disembunyikan dari bagian program lain, sehingga perubahan pada implementasi internal tidak akan memengaruhi cara ADT tersebut dipakai.
 
### B. Implementasi ADT dalam Bahasa C++<br/>
 
Dalam praktiknya, ADT di C++ umumnya diimplementasikan dengan memisahkan definisi tipe data beserta deklarasi fungsinya dari realisasi (isi) fungsi tersebut ke dalam file yang berbeda.
 
#### 1. Pemisahan Modul Header dan Body
 
Implementasi ADT biasanya dipecah menjadi dua modul utama, yaitu file header (.h) yang berisi spesifikasi type dan deklarasi/*prototype* dari primitif-primitifnya, serta file body (.cpp) yang berisi realisasi kode program dari primitif tersebut. Satu modul tambahan berupa program utama (*driver*) kemudian memanggil kedua modul tersebut untuk menjalankan program secara keseluruhan.
 
#### 2. Peran Struct sebagai Representasi Type
 
Representasi suatu ADT di C++ umumnya dibuat menggunakan `struct`, yang dipakai untuk mengelompokkan beberapa data menjadi satu kesatuan tipe baru. Pendekatan ini banyak dipakai dalam praktik, misalnya pada implementasi struktur data seperti stack, di mana sebuah `struct` dipakai untuk menyimpan data sekaligus informasi lain yang dibutuhkan (seperti indeks *top* atau pointer ke elemen berikutnya), sebelum kemudian dioperasikan lewat kumpulan fungsi seperti `push()` dan `pop()` [1].
 
#### 3. Penerapan ADT pada Studi Kasus
 
Pada praktiknya, realisasi fungsi dan prosedur suatu ADT sedapat mungkin tetap memanfaatkan konstruktor dan selector yang telah didefinisikan, bukan mengakses langsung komponen di dalam struct. Dengan pola seperti ini, suatu ADT — misalnya ADT Mahasiswa yang memuat NIM dan nilai, atau ADT Pelajaran yang memuat nama dan kode mata kuliah — dapat dipakai secara konsisten dari program utama tanpa perlu mengetahui detail penyimpanan datanya secara internal.

```

## Guided

### 1. 

## buku.h
```C++
#ifndef BUKU_H
#define BUKU_H
#include <iostream>

using namespace std;

struct buku
{
  string judul;
  int halaman;
  string penulis;
};

void editIsi(string judul, int halaman, string penulis, buku &buku);
void tampilkanIsiBuku(buku buku);
bool checkPenulis(buku buku);

#endif
```

## buku.cpp
```C++
#include "buku.h"

void editIsi(string judul, int halaman, string penulis, buku &buku)
{
  buku.judul = judul;
  buku.halaman = halaman;
  buku.penulis = penulis;
}

void tampilkanIsiBuku(buku buku)
{
  cout << "Judul buku   : " << buku.judul << endl;
  cout << "Halaman buku : " << buku.halaman << endl;
  cout << "Penulis buku : " << buku.penulis << endl;
}

bool checkPenulis(buku buku)
{
  return buku.penulis == " ";
}
```
## main.cpp
```C++
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
```

<p>Program ini menyimpan data sebuah buku ke dalam `struct` dan mengelolanya dengan fungsi, menggunakan konsep ADT dalam tiga file. File `buku.h` berisi `struct buku` dengan *field* `judul` dan `penulis` (`string`) serta `halaman` (`int`), dan deklarasi `editIsi()`, `tampilkanIsiBuku()`, `checkPenulis()`. Baris `#ifndef BUKU_H`, `#define BUKU_H`, `#endif` mencegah *header* ter-*include* berulang, `#include <iostream>` memuat `cin` dan `cout`, dan `using namespace std;` membuatnya bisa ditulis tanpa `std::`.</p>
 
<p>File `buku.cpp` berisi isi fungsi. `editIsi()` memasukkan `judul`, `halaman`, dan `penulis` ke *field* variabel `buku`; parameter `buku` memakai `&` (*call by reference*) agar perubahan tersimpan di variabel asli. `tampilkanIsiBuku()` mencetak ketiga data dan cukup memakai *call by value*. `checkPenulis()` mengembalikan `bool` hasil `buku.penulis == " "` (dibandingkan dengan satu spasi), yaitu 1 jika penulis hanya spasi dan 0 jika tidak.</p>

<p>Di `main()`, variabel `novel` bertipe `buku` diisi dari input `cin >>`, disimpan lewat `editIsi()`, ditampilkan dengan `tampilkanIsiBuku()`, lalu `cout << checkPenulis(novel);` mencetak 0 atau 1. Karena `cin >>` membuang spasi, hasilnya selalu 0 (misalnya penulis "tereliye"), dan judul maupun penulis hanya bisa satu kata.</p>

## Unguided

### soal1.

## mahasiswa.h
```C++
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
```
## mahasiswa.cpp
```C++
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
```
## main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa data[MAX]; 
    int n;

    do {
        cout << "Jumlah mahasiswa (1-" << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        inputMhs(data[i]);
    }

    cout << "\n=== DATA MAHASISWA ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        tampilkanMhs(data[i]);
    }

    return 0;
}
```

### Output Unguided 1 :

#### Output 1
<img src = "" >

#### Output 2
<img src = "" >

 
<p>Program ini menyimpan data maksimal 10 mahasiswa ke dalam *array* of `struct`, dengan penerapan konsep ADT yang dipisah menjadi tiga file. File `mahasiswa.h` berisi konstanta `MAX` bernilai 10 sebagai batas jumlah data dan `struct mahasiswa` dengan enam *field*. Field `nama` dan `nim` bertipe `string`, sedangkan `uts`, `uas`, `tugas`, dan `nilaiAkhir` bertipe `float`. File ini juga memuat deklarasi tiga fungsi: `inputMhs()`, `hitungNilaiAkhir()`, dan `tampilkanMhs()`. Baris `#ifndef MAHASISWA_H`, `#define MAHASISWA_H`, dan `#endif` mencegah file *header* ter-*include* berulang kali, sedangkan `using namespace std;` membuat `cout`, `cin`, `endl`, dan `string` dapat ditulis tanpa awalan `std::`.</p>
 
<p>File `mahasiswa.cpp` berisi isi dari ketiga fungsi tersebut. Fungsi `hitungNilaiAkhir()` menerima nilai `uts`, `uas`, dan `tugas`, lalu mengembalikan hasil rumus `0.3 * uts + 0.4 * uas + 0.3 * tugas`. Prosedur `inputMhs()` meminta pengguna memasukkan nama, NIM, UTS, UAS, dan tugas dengan `cin >>`, kemudian mengisi field `nilaiAkhir` dengan memanggil `hitungNilaiAkhir()`. Parameter `m` pada `inputMhs()` memakai tanda `&` (*call by reference*) agar perubahan isinya tersimpan pada variabel aslinya di `main()`. Prosedur `tampilkanMhs()` mencetak seluruh field, dan parameternya cukup dikirim dengan nilai karena isinya hanya dibaca.</p>
 
<p>Di dalam fungsi `main()`, dideklarasikan *array* `data[MAX]` bertipe `mahasiswa` dan variabel `n` untuk jumlah mahasiswa yang akan diinput. Perulangan `do...while` meminta `n` terus-menerus sampai bernilai antara 1 dan `MAX`, sehingga data tidak pernah melebihi kapasitas *array*. Perulangan `for` pertama memanggil `inputMhs(data[i])` untuk mengisi data tiap mahasiswa, lalu perulangan `for` kedua memanggil `tampilkanMhs(data[i])` untuk menampilkannya. Sebagai contoh, jika UTS 80, UAS 90, dan tugas 70, nilai akhirnya adalah 0.3×80 + 0.4×90 + 0.3×70 = 81. Karena input dibaca dengan `cin >>`, nama hanya bisa berupa satu kata. Program berakhir dengan `return 0;`.</p>

### soal2.

### pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>

using namespace std;

struct pelajaran
{
    string namaMapel;
    string kodeMapel;
};
pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif
```
### pelajaran.cpp
```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel)
{
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel)
{
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

#### Output 1
<img src = "" >

#### Output 2
<img src = "" >

<p>Program ini menerapkan ADT `pelajaran` sesuai spesifikasi pada soal, juga dalam tiga file. File `pelajaran.h` berisi `struct pelajaran` dengan dua *field* bertipe `string`, yaitu `namaMapel` dan `kodeMapel`, serta deklarasi fungsi `create_pelajaran()` dan prosedur `tampil_pelajaran()`. Komentar pada deklarasi menuliskan domain dan *range* untuk fungsi, serta *initial state* dan *final state* untuk prosedur, sesuai kaidah spesifikasi primitif pada materi ADT.</p>
 
<p>File `pelajaran.cpp` berisi realisasi kedua primitif tersebut. Fungsi `create_pelajaran()` berperan sebagai konstruktor: ia membuat variabel `p` bertipe `pelajaran`, mengisi `namaMapel` dan `kodeMapel` dari parameter `namapel` dan `kodepel`, lalu mengembalikan `p`. Prosedur `tampil_pelajaran()` mencetak nama dan kode pelajaran ke layar. Label kedua pada `cout` ditulis `nilai :` agar outputnya sama persis dengan contoh pada soal, padahal isi yang dicetak adalah kode mapel.</p>
 
<p>Di dalam fungsi `main()`, variabel `namapel` diisi "Struktur Data" dan `kodepel` diisi "STD". Keduanya dikirim ke `create_pelajaran()`, dan hasilnya disimpan di variabel `pel`. Variabel `pel` kemudian ditampilkan dengan `tampil_pelajaran()`, sehingga output yang muncul adalah `nama pelajaran : Struktur Data` dan `nilai : STD`. Program berakhir dengan `return 0;`.</p>

```
### soal3.

### tukar.h
```C++
#ifndef TUKAR_H
#define TUKAR_H
#include <iostream>

using namespace std;

const int BARIS = 3;
const int KOLOM = 3;

void tampilArray(int arr[BARIS][KOLOM]);
void tukarArray(int arr1[BARIS][KOLOM], int arr2[BARIS][KOLOM], int baris, int kolom);
void tukarPointer(int *p1, int *p2);

#endif
```

### tukar.cpp
```C++
#include "tukar.h"

void tampilArray(int arr[BARIS][KOLOM])
{
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[BARIS][KOLOM], int arr2[BARIS][KOLOM], int baris, int kolom)
{
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}
void tukarPointer(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```

### main.cpp
```C++
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
```


### Output Unguided 3 :
#### Output 1
<img src = "" >

#### Output 2
<img src = "" >



<P>Program ini menunjukkan penggunaan *array* 2D dan *pointer* pada tiga prosedur yang dipisah dalam file `tukar.h`, `tukar.cpp`, dan `main.cpp`. File `tukar.h` mendefinisikan konstanta `BARIS` dan `KOLOM` yang keduanya bernilai 3, sehingga ukuran *array* 3x3 dapat dipakai konsisten di seluruh program. File ini juga memuat deklarasi `tampilArray()`, `tukarArray()`, dan `tukarPointer()` beserta *initial state* dan *final state* masing-masing.</p>
 
<p>File `tukar.cpp` berisi realisasi ketiga prosedur. Prosedur `tampilArray()` memakai dua perulangan `for` bersarang untuk mencetak seluruh elemen *array* per baris, dengan `"\t"` sebagai pemisah antarkolom. Prosedur `tukarArray()` menukar elemen `arr1[baris][kolom]` dengan `arr2[baris][kolom]` memakai variabel sementara `temp`. Karena *array* yang dikirim ke fungsi otomatis berupa alamat, perubahan langsung terjadi pada *array* aslinya tanpa perlu tanda `&`. Prosedur `tukarPointer()` menerima dua *pointer* `p1` dan `p2`, lalu menukar isi variabel yang ditunjuk keduanya lewat `*p1` dan `*p2`. Yang bertukar adalah nilai pada variabel tujuan, bukan alamat yang disimpan *pointer*.</p>
 
<p>Di dalam fungsi `main()`, dideklarasikan dua *array* 2D `A` dan `B` berukuran 3x3 yang langsung diisi nilai awal, serta dua variabel `x` dan `y`. *Pointer* `p1` diarahkan ke `x` dan `p2` ke `y` dengan operator `&`. Program menampilkan kedua *array* sebelum ditukar, lalu memanggil `tukarArray(A, B, 1, 2)` sehingga elemen pada baris 1 kolom 2 saling bertukar (6 pada `A` dan 60 pada `B`), dan menampilkannya lagi. Setelah itu `tukarPointer(p1, p2)` dipanggil sehingga `x` yang semula 100 menjadi 200 dan `y` yang semula 200 menjadi 100. Program berakhir dengan `return 0;`.</p>

## Kesimpulan
<p>Dari praktikum Modul 3 ini ADT bukan cuma soal bikin struct, melainkan soal memisahkan "apa yang bisa dilakukan terhadap data" dari "bagaimana data itu sebenarnya disimpan". Pada program buku, hal ini kelihatan jelas lewat tiga primitif yang berbeda peran: editIsi() sebagai pengubah nilai memakai parameter &buku supaya perubahannya ikut tersimpan di variabel aslinya, sementara tampilkanIsiBuku() dan checkPenulis() cukup memakai call by value karena keduanya hanya membaca data, tidak mengubah apa pun. Perbedaan kecil semacam ini sebenarnya mencerminkan cara ADT bekerja — tiap primitif punya tugas spesifik, dan cara ia menerima parameter mengikuti tugas tersebut.</p>

<p>Pola yang sama lalu muncul lagi di bagian unguided dengan variasi yang lebih kaya. Pada program mahasiswa, inputMhs() berperan sebagai mutator yang memanggil hitungNilaiAkhir() di dalamnya, jadi satu primitif bisa memanfaatkan primitif lain tanpa perlu menulis ulang logikanya. Pada program pelajaran, create_pelajaran() justru menunjukkan sisi lain dari konstruktor: ia tidak mengubah objek yang sudah ada lewat referensi, melainkan membangun objek baru dari nol dan langsung mengembalikannya sebagai hasil fungsi. Sementara itu, program tukar array dan pointer memperlihatkan bahwa prinsip modular ini sebenarnya tidak terbatas pada struct saja — memisahkan deklarasi dan realisasi ke file berbeda tetap berlaku meski yang dioperasikan hanya array dua dimensi dan pointer biasa.</p>


## Referensi

 
<br> [1] R. D. Setiyawan, D. Hermawan, A. F. Abdillah, A. Mujayanah, dan R. Vindua, "Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List," *Jutech (Jurnal Teknologi)*, Universitas Pamulang, vol. 5, no. 2, hlm. 484–498, Desember 2024.
 
<br> [2] N. N. Azzahrani dan D. R. Susanti, "Perancangan dan Implementasi Program Penjualan Produk Matcha Menggunakan Bahasa Pemrograman C++ pada Matchuchu Griya," *Jukompak (Jurnal Komputasi dan Pengembangan Aplikasi)*, vol. 1, no. 4, hlm. 11–21, Oktober 2025.
 
<br> [3] J. Wahyudi, Berlian, dan Rosdiana, "Instruksi Bahasa Pemrograman ADT (Abstract Data Type) pada Virus dan Loop Batch," *Jurnal Media Infotama*, vol. 9, no. 2, 2015.
