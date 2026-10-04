# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>

<p align="center">Leonardo Farriz Garcya - 109082530036</p>

# Dasar Teori

### A. Array dan Pointer<br/>
Array dan pointer merupakan dua konsep yang saling berkaitan erat dalam bahasa C++, karena keduanya sama-sama berhubungan dengan cara data disimpan dan diakses di dalam memori komputer [2], [3].
 
#### 1. Array Satu, Dua, dan Berdimensi Banyak
Array adalah kumpulan elemen data yang tersimpan secara berurutan di lokasi memori dan dapat diakses secara langsung menggunakan indeks, sehingga memberikan kecepatan akses data dalam waktu konstan O(1) [2]. Bentuk paling sederhana adalah array satu dimensi, yang hanya terdiri dari satu larik data. Selain itu ada juga array dua dimensi yang bisa dipakai untuk menyimpan data berbentuk tabel, serta array berdimensi banyak (lebih dari dua) yang jumlah indeksnya menunjukkan jumlah dimensi array tersebut — semakin banyak dimensinya, semakin sulit juga membayangkan strukturnya.

#### 2. Alamat Memori dan Pointer
Semua data yang dipakai program disimpan di memori (RAM), yang bisa dibayangkan sebagai array raksasa berukuran sangat besar, di mana tiap sel memori punya alamat uniknya sendiri. Berbeda dengan array yang elemennya ditempatkan pada alamat memori yang berdekatan, pointer justru menyimpan alamat dari suatu data dan menautkannya menggunakan referensi tersebut [3]. Supaya pointer bisa menunjuk ke suatu variabel, ia harus diisi dulu dengan alamat variabel tersebut menggunakan operator `&`, dan nilai yang ditunjuknya bisa diakses kembali lewat operator `*`.
 
#### 3. Hubungan Pointer dengan Array dan String
Array dan pointer punya keterkaitan yang kuat, karena nama suatu array sebenarnya adalah alamat dari elemen pertamanya. Karena itu, hampir semua operasi yang bisa dilakukan lewat indeks array juga bisa dilakukan lewat pointer, meskipun keduanya berbeda dalam hal fleksibilitas: array bersifat statis dengan ukuran tetap, sedangkan pointer memungkinkan pengalokasian data secara lebih dinamis [2], [3]. Hal serupa berlaku untuk string, yang pada dasarnya merupakan array karakter yang diakhiri tanda null (`\0`), sehingga string juga dapat diakses menggunakan pointer karakter.
 
### B. Fungsi dan Prosedur<br/>
Fungsi dan prosedur sama-sama dipakai untuk memecah program menjadi bagian-bagian kecil yang lebih terstruktur dan mudah dikembangkan [1].

#### 1. Fungsi
Fungsi merupakan unit dasar modularitas dalam pemrograman yang mengenkapsulasi sekumpulan instruksi untuk menjalankan tugas spesifik, biasanya menerima masukan berupa parameter dan menghasilkan sebuah nilai balik [1]. Keberadaan fungsi membuat program lebih modular sekaligus mengurangi duplikasi kode, karena bagian yang sama bisa dipanggil berulang kali tanpa perlu ditulis ulang, sejalan dengan prinsip *Don't Repeat Yourself* (DRY) dalam rekayasa perangkat lunak [1].
 
#### 2. Prosedur
Berbeda dengan fungsi, prosedur adalah blok kode yang tidak mengembalikan nilai apa pun. Dalam bahasa C++, prosedur ini dikenal sebagai fungsi bertipe `void`, yang tetap menjalankan suatu tugas tapi tidak memberi nilai balik ke pemanggilnya.
 
#### 3. Parameter Fungsi
Parameter dalam fungsi terbagi menjadi parameter formal, yaitu variabel yang dideklarasikan saat fungsi dibuat, dan parameter aktual, yaitu nilai yang dipakai saat fungsi dipanggil. Cara melewatkan parameter ini ada tiga: *call by value*, di mana nilai parameter aktual hanya disalin ke parameter formal sehingga nilai aslinya tidak ikut berubah; serta *call by pointer* dan *call by reference*, yang sama-sama melewatkan alamat variabel ke dalam fungsi sehingga perubahan di dalamnya ikut mengubah nilai variabel asli di luar fungsi [3].
---

## Guided

### 1. 

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main()
{
  int i, j;
  float nilai_total, rata_rata;
  float nilai[MAX];
  static int nilai_tahun[MAX][MAX] =
      {   {0, 2, 2, 0, 0},
          {0, 1, 1, 1, 0},
          {0, 3, 3, 3, 0},
          {4, 4, 0, 0, 4},
          {5, 0, 0, 0, 5}
      };

  for (i = 0; i < MAX; i++)
  {
    cout << "masukkan nilai ke-" << i + 1 << endl;
    cin >> nilai[i];
  }
  cout << "\ndata nilai siswa :\n";

  for (i = 0; i < MAX; i++)
    cout << "nilai k-" << i + 1 << "=" << nilai[i] << endl;
  cout << "\n nilai tahunan : \n";

  for (i = 0; i < MAX; i++)
  {
    for (j = 0; j < MAX; j++)
      cout << nilai_tahun[i][j];
    cout << "\n";
  }
  return 0;
}
```

<p>Penjelasan</p>

### 2.

```C++
#include <iostream>
using namespace std;
int main()
{

  int x, y;
  int *px;

  x = 87;
  px = &x;
  y = *px;

  cout << "Alamat x= " << &x << endl;
  cout << "Isi px= " << px << endl;
  cout << "Isi X= " << x << endl;
  cout << "Nilai yang ditunjuk px= " << *px << endl;
  cout << "Nilai y= " << y << endl;
  return 0;
}
```

<p>Penjelasan</p>

### 3.

```C++
#include <iostream>
using namespace std;
int maks3(int a, int b, int c);
int main(){
  int x, y, z;
  cout << "masukkan nilai bilangan ke-1 =";
  cin >> x;
  cout << "masukkan nilai bilangan ke-2 =";
  cin >> y;
  cout << "masukkan nilai bilangan ke-3 =";
  cin >> z;
  cout << "nilai maksimumnya adalah = " << maks3(x, y, z);
  return 0;
}

int maks3(int a, int b, int c){

  int temp_max = a;
  if (b > temp_max)
    temp_max = b;
  if (c > temp_max)
    temp_max = c;
  return (temp_max);
}
```
<p>Penjelasan</p>

### 4.

```C++
#include <iostream>
using namespace std;

void tulis(int x);
int main(){
    int jum;

    cout << "jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;
}
void tulis(int x){
    for (int i = 0; i < x; i++)
        cout << "baris ke-" << i + 1 << endl;
}
```
<p>Penjelasan</p>

### 5.

```C++
#include <iostream>
using namespace std;

void tukar(int x, int y);
int main(){
    int a, b;
    a = 4;
    b = 6;

    cout << "kondisi sebelum ditukar\n";
    cout << "a = " << a << " b = " << b << endl;

    tukar(a, b);

    cout << "kondisi setelah ditukar\n";
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}
void tukar(int x, int y){
    int temp;

    temp = x;
    x = y;
    y = temp;

    cout << "nilai akhir pada fungsi tukar\n";
    cout << "x = " << x << " y = " << y << endl;
}
```
<p>Penjelasan</p>



## Unguided

### 1.

```C++
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
```

### Output Unguided 1 :

#### Output 1
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_2/output/output1.1.png" >

#### Output 2
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_2/output/output1.2.png" >

<p>Program ini digunakan untuk melakukan beberapa operasi pada dua buah matriks berukuran 3×3, yaitu matriks A dan matriks B. Hasil dari setiap operasi disimpan dalam matriks C. Pengisian dilakukan menggunakan dua perulangan <code>for</code>, yaitu untuk menentukan posisi baris dan kolom setiap elemen matriks.</p>Setelah kedua matriks dimasukkan, program menampilkan menu yang berisi pilihan penjumlahan, pengurangan, perkalian, dan keluar. Menu tersebut berada dalam perulangan <code>do-while</code>, sehingga pengguna dapat memilih operasi lebih dari satu kali sampai memilih angka 0.</p>

<p>Jika pengguna memilih penjumlahan, setiap elemen pada posisi yang sama dari matriks A dan B dijumlahkan. Jika memilih pengurangan, elemen matriks A dikurangi dengan elemen matriks B pada posisi yang sama. Hasil dari kedua operasi tersebut kemudian disimpan ke matriks C dan ditampilkan dalam bentuk matriks.Untuk pilihan perkalian, program menggunakan tiga perulangan <code>for</code>. Setiap elemen matriks C dihitung dengan mengalikan elemen pada baris matriks A dengan elemen pada kolom matriks B, kemudian seluruh hasil perkalian tersebut dijumlahkan. Setelah selesai, hasil perkalian matriks A dan B ditampilkan.</p>

### 2.

```C++
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
```

### Output Unguided 2 :

#### Output 1
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_2/output/output2.1.png" >

#### Output 2
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_2/output/output2.2.png" >

<p>Program ini digunakan untuk menukar nilai tiga variabel <code>a</code>, <code>b</code>, dan <code>c</code> dengan dua cara, yaitu menggunakan <strong>pointer</strong> dan <strong>reference</strong>. Program terlebih dahulu meminta pengguna memasukkan nilai untuk ketiga variabel tersebut.Setelah nilai dimasukkan, program menampilkan kondisi awal dari <code>a</code>, <code>b</code>, dan <code>c</code>. Selanjutnya, fungsi <code>tukarPointer</code> dipanggil dengan mengirimkan alamat dari ketiga variabel menggunakan operator <code>&amp;</code>. Fungsi tersebut menggunakan alamat memori untuk mengakses dan menukar nilai ketiga variabel dengan bantuan variabel sementara <code>temp</code>.</p>

<p>Setelah proses penukaran menggunakan pointer selesai, nilai <code>a</code>, <code>b</code>, dan <code>c</code> ditampilkan kembali. Program kemudian menjalankan fungsi <code>tukarReference</code>, yang menggunakan reference sehingga fungsi dapat langsung mengakses variabel yang dikirimkan tanpa perlu mengirimkan alamatnya secara eksplisit.</p>

<p>Di dalam kedua fungsi tersebut, proses penukaran dilakukan dengan pola yang sama, yaitu nilai <code>a</code> disimpan sementara, nilai <code>b</code> dipindahkan ke <code>a</code>, nilai <code>c</code> dipindahkan ke <code>b</code>, kemudian nilai awal <code>a</code> dipindahkan ke <code>c</code>. Hasilnya, nilai ketiga variabel bergeser dari <strong>a → c, b → a, dan c → b</strong>.Setelah fungsi <code>tukarReference</code> selesai, program kembali menampilkan nilai <code>a</code>, <code>b</code>, dan <code>c</code>. Jadi, program ini sekaligus memperlihatkan cara melakukan perubahan nilai variabel melalui pointer dan reference.</p>

### 3.

```C++
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
```

### Output Unguided 3 :
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_2/output/output3.png" >



<p>Program ini digunakan untuk mengolah data pada sebuah array yang berisi 10 bilangan. Terdapat beberapa pilihan yang bisa digunakan, yaitu menampilkan isi array, mencari nilai terbesar, mencari nilai terkecil, dan menghitung nilai rata-rata.Data pada array <code>arrA</code> sudah ditentukan sejak awal, yaitu <code>48, 2, 7, 21, 5, 20, 77, 9, 10, 1</code>. Program kemudian menampilkan menu menggunakan perulangan <code>do-while</code>. Pengguna dapat memilih menu sesuai operasi yang ingin dilakukan, dan menu akan terus muncul selama pengguna belum memilih 0.</p>

<p>Pada menu pertama, seluruh nilai dalam array ditampilkan menggunakan perulangan <code>for</code>. Menu kedua menggunakan fungsi <code>maksimum</code> untuk mencari nilai terbesar dengan membandingkan setiap elemen array. Menu ketiga menggunakan fungsi <code>minimum</code> untuk mencari nilai terkecil dengan proses yang hampir sama.Pada menu keempat, fungsi <code>rataRata</code> menjumlahkan seluruh nilai array terlebih dahulu. Jumlah tersebut kemudian dibagi dengan 10 untuk mendapatkan nilai rata-rata. Hasil perhitungan dikembalikan melalui parameter <code>hasil</code> dan disimpan pada variabel <code>hasilRataRata</code>.Jika pengguna memilih menu 0, program menampilkan pesan <strong>“Program selesai.”</strong> dan perulangan berhenti. Jika pilihan yang dimasukkan tidak tersedia, program akan memberi tahu bahwa pilihan tersebut tidak tersedia.</p>

## Kesimpulan
Dari praktikum Modul 2 menunjukkan bagaimana pointer bekerja menyimpan dan mengakses alamat memori lewat operator & dan *, serta kaitannya yang erat dengan array — karena ternyata nama array itu sendiri sebenarnya sudah merupakan alamat dari elemen pertamanya. Pemahaman ini makin jelas saat membandingkan cara pengiriman parameter pada fungsi: dengan call by value, nilai asli tidak ikut berubah karena yang dikirim hanya salinannya, sedangkan dengan pointer atau reference, fungsi langsung memegang alamat variabel aslinya sehingga perubahan di dalam fungsi juga mengubah nilai di luar fungsi, seperti terlihat pada program tukar tiga variabel di bagian unguided.
Secara keseluruhan, praktikum ini berhasil membuka pemahaman soal pointer, alamat memori, serta cara membuat dan memakai fungsi maupun prosedur dengan benar, bekal penting sebelum masuk ke materi seperti linked list yang banyak mengandalkan konsep pointer.

## Referensi
<br> [1] N. N. Azzahrani dan D. R. Susanti, "Perancangan dan Implementasi Program Penjualan Produk Matcha Menggunakan Bahasa Pemrograman C++ pada Matchuchu Griya," Jukompak (Jurnal Komputasi dan Pengembangan Aplikasi), vol. 1, no. 4, hlm. 11–21, Oktober 2025.

<br> [2] A. Rizky, D. A. Prasetyo, D. R. K. Sari, dan G. E. O. Zeflin, "Penerapan Konsep Array pada Struktur Data untuk Peningkatan Efisiensi Pencarian dan Penyimpanan Data," Jurnal Sains Informatika Terapan (JSIT), vol. 4, no. 3, hlm. 706–709, 2025.

<br>[3] M. R. A. Fitra, A. A. S. Effendi, dan F. Ramadhani, "Implementasi Python dalam Pengolahan Data Pribadi Mahasiswa Ilmu Komputer Angkatan 23 pada Universitas Negeri Medan Menggunakan Struktur Data Linked List," JATI (Jurnal Mahasiswa Teknik Informatika), vol. 9, no. 1, hlm. 51–58, Februari 2025.
