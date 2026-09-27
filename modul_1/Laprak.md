# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>

<p align="center">Leonardo Farriz Garcya - 109082530036</p>

# Dasar Teori

### A. Integrated Development Environment (IDE) Code::Blocks<br/>

 IDE atau *Integrated Development Environment* adalah paket lengkap dalam pemrograman, di mana teks editor, compiler, linker, sampai debugger sudah tergabung dalam satu aplikasi saja, sehingga programmer tidak perlu membuka banyak aplikasi terpisah hanya untuk menulis dan menjalankan program [4].

#### 1. Pengertian dan Karakteristik Code::Blocks

Salah satu contoh IDE yang cukup populer adalah Code::Blocks. IDE ini bersifat gratis (*free*) dan *open-source*, serta ditujukan khusus untuk bahasa C, C++, dan Fortran. Karena sifatnya yang *cross-platform*, Code::Blocks bisa dipasang di berbagai sistem operasi, mulai dari Windows, Linux, hingga MacOS [4].

#### 2. Fitur-fitur Code::Blocks

Dalam satu kali instalasi saja, pengguna sudah mendapatkan teks editor, compiler, linker, sekaligus debugger [1]. Beberapa fitur pendukung yang cukup membantu di antaranya *syntax highlighting* yang mewarnai kode agar lebih mudah dibaca, *code completion* yang memberi saran penulisan kode, dan *real-time debugging* yang bisa mendeteksi kesalahan bahkan sebelum program di-*compile*.

#### 3. Penerapan Code::Blocks dalam Pembelajaran Pemrograman

Dalam akademik, Code::Blocks sering dipakai untuk kegiatan praktikum maupun penelitian. Karena fitur seperti *autocompletion* dan debugger bawaan membuat proses menulis serta menguji program C++ menjadi lebih cepat dan efisien [2].

### B. Bahasa Pemrograman C++<br/>

C++ pada dasarnya merupakan pengembangan dari bahasa C, dengan tambahan dukungan konsep berorientasi objek atau *Object Oriented Programming* (OOP) [3].

#### 1. Sejarah Perkembangan Bahasa C++

Bahasa ini pertama kali diciptakan oleh Bjarne Stroustrup di AT&T Bell Laboratories pada awal 1980-an. Awalnya, C++ hanyalah bahasa C yang ditambah fasilitas kelas (*class*), sehingga sempat dikenal dengan sebutan "C with Classes". Barulah pada tahun 1998, C++ resmi menjadi standar ISO dengan nama C++98, dan sejak itu terus diperbarui lewat standar-standar berikutnya seperti C++11 sampai C++20 [3]. Menariknya, mempelajari C++ tidak hanya soal menulis kode, tetapi juga dapat melatih kemampuan berpikir kritis [3].

#### 2. Struktur Program, Tipe Data, dan Operator dalam C++

Secara garis besar, sebuah program C++ biasanya diawali dengan bagian `#include` untuk memanggil pustaka yang dibutuhkan, dilanjutkan dengan deklarasi konstanta dan variabel, lalu ditutup dengan fungsi `main()` yang menjadi titik awal program dijalankan. Variabel berfungsi menampung data yang nilainya bisa berubah sewaktu-waktu, sementara konstanta justru sebaliknya, nilainya tetap dan dideklarasikan dengan kata kunci `const` [1], [5]. Baik variabel maupun konstanta perlu memiliki tipe data, misalnya *integer*, *float*, *double*, atau *char*, tergantung jenis nilai yang akan disimpan [5]. Untuk mengolah data-data tersebut, C++ menyediakan operator, yakni simbol yang dipakai untuk melakukan suatu operasi [6]. Beberapa contohnya adalah operator aritmatika seperti penjumlahan, pengurangan, perkalian, pembagian, dan modulus [1], operator *assignment*, operator logika, hingga operator *increment*/*decrement* [6].

#### 3. Input, Output, dan Struktur Kondisional dalam C++

Agar program bisa berinteraksi dengan penggunanya, C++ menyediakan pustaka `<iostream>` yang berisi dua fungsi utama: `cout()` untuk menampilkan data ke layar menggunakan operator `<<`, dan `cin()` untuk menerima input dari pengguna lewat operator `>>`. Di sisi lain, ada juga struktur kondisional yang berguna untuk menentukan pernyataan mana yang akan dijalankan tergantung kondisi yang terpenuhi. Bentuknya bisa berupa `if` untuk satu kondisi saja, `if-else` untuk dua kemungkinan hasil, atau `switch-case` bila pilihannya lebih dari dua. Struktur semacam ini banyak dipakai saat merancang menu program yang berjalan berulang, seperti pada sistem berbasis C++ yang dibahas dalam salah satu penelitian [2].

---

## Guided

### 1. 

```C++
#include <iostream>
using namespace std;
int main(){
  int W, X, Y; float Z;
    X = 7; Y = 3; W = 1;
    Z = (X + Y)/(Y + W);
    cout<< "Nilai z = " << Z << endl;
    
return 0;
}
```

<p>Program ini digunakan untuk menghitung nilai Z berdasarkan tiga variabel bilangan bulat, yaitu W, X, dan Y. Nilai awal yang diberikan adalah W = 1, X = 7, dan Y = 3. Kemudian program menghitung nilai Z dengan rumus (X + Y) / (Y + W). Berdasarkan nilai yang telah ditentukan, perhitungannya menjadi (7 + 3) / (3 + 1) = 10 / 4. Karena X, Y, dan W bertipe integer, operasi pembagian 10 / 4 dilakukan sebagai pembagian bilangan bulat terlebih dahulu sehingga menghasilkan nilai 2. Hasil tersebut kemudian disimpan ke variabel Z yang bertipe float.</p>

<p>Pada akhir program, nilai Z ditampilkan menggunakan <code>cout</code> dengan format “Nilai z = 2”. Jadi output program adalah <strong>Nilai z = 2</strong>.</p>

### 2.

```C++
#include <iostream>
using namespace std;
int main(){
  int r = 10;
  int s;
    s=10 + ++r;
      cout<< "Nilai r= "<<r<<endl;
     cout<< "Nilai s= "<<s<<endl;
  return 0;
}
```

<p>Program ini digunakan untuk menunjukkan penggunaan operator <code>++r</code> atau pre-increment dalam operasi aritmatika. Pada awal program, variabel <code>r</code> diberi nilai 10, sedangkan variabel <code>s</code> digunakan untuk menyimpan hasil perhitungan.Selanjutnya program menjalankan perintah <code>s = 10 + ++r</code>. Operator <code>++r</code> akan menaikkan nilai <code>r</code> terlebih dahulu dari 10 menjadi 11, kemudian nilai 11 tersebut digunakan dalam perhitungan. Jadi, nilai <code>s</code> menjadi 10 + 11 = 21. Setelah proses perhitungan selesai, program menampilkan nilai akhir dari <code>r</code> dan <code>s</code> menggunakan <code>cout</code>. Nilai <code>r</code> adalah 11, sedangkan nilai <code>s</code> adalah 21.</p>

<p>Maka, output program adalah <strong>Nilai r = 11</strong> dan <strong>Nilai s = 21</strong>. Hal ini terjadi karena <code>++r</code> menaikkan nilai variabel terlebih dahulu sebelum nilainya digunakan dalam operasi.</p>

### 3.

```C++
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
  int r = 10;
  int s;
    s=10 + r++;
      cout<< "Nilai r= "<<r<<endl;
      cout<< "Nilai s= "<<s<<endl;
  return 0;
}
```
<p>Program ini digunakan untuk menunjukkan penggunaan operator <code>r++</code> atau post-increment dalam operasi aritmatika. Pada awal program, variabel <code>r</code> diberi nilai 10, sedangkan variabel <code>s</code> digunakan untuk menyimpan hasil perhitungan.Selanjutnya, program menjalankan perintah <code>s = 10 + r++</code>. Berbeda dengan <code>++r</code>, operator <code>r++</code> menggunakan nilai <code>r</code> terlebih dahulu dalam perhitungan, kemudian baru menaikkan nilainya. Jadi, nilai 10 digunakan untuk menghitung <code>s</code>, sehingga <code>s = 10 + 10 = 20</code>. Setelah itu, nilai <code>r</code> bertambah menjadi 11.</p>

<p>Setelah proses perhitungan selesai, program menampilkan nilai akhir dari <code>r</code> dan <code>s</code> menggunakan <code>cout</code>. Nilai <code>r</code> adalah 11, sedangkan nilai <code>s</code> adalah 20. Maka, output program adalah <strong>Nilai r = 11</strong> dan <strong>Nilai s = 20</strong>. Hal ini terjadi karena <code>r++</code> menaikkan nilai variabel setelah nilai awalnya digunakan dalam operasi.</p>

### 4.

```C++
#include <iostream>
using namespace std;
int main(){
  double tot_pembelian, diskon;
    cout<<"total pembelian: Rp";
    cin>>tot_pembelian;
    diskon = 0;
  if(tot_pembelian >= 100000)
    diskon = 0.05*tot_pembelian;
      cout<<"besar diskon = Rp" <<diskon;
}
```
<p>Program ini digunakan untuk menghitung besar diskon berdasarkan total pembelian. Program menggunakan variabel <code>tot_pembelian</code> untuk menyimpan total harga pembelian dan variabel <code>diskon</code> untuk menyimpan jumlah diskon yang diperoleh.Pertama, program meminta pengguna memasukkan total pembelian. Setelah itu, nilai <code>diskon</code> diatur menjadi 0 sebagai nilai awal, sehingga pembeli tidak mendapatkan diskon jika belum memenuhi syarat.</p>

<p>Selanjutnya program memeriksa apakah total pembelian lebih besar atau sama dengan Rp100.000. Jika memenuhi syarat tersebut, diskon dihitung sebesar 5% dari total pembelian menggunakan rumus <code>0.05 * tot_pembelian</code>. Jika total pembelian kurang dari Rp100.000, nilai diskon tetap 0. Pada akhir program, besar diskon ditampilkan ke layar. Program akan memberikan diskon sebesar 5% untuk pembelian minimal Rp100.000 dan tidak memberikan diskon untuk pembelian di bawah Rp100.000.</p>

### 5.

```C++
#include <iostream>
using namespace std;
int main(){
  double tot_pembelian, diskon;
   cout<<"total pembelian: Rp";
  cin>>tot_pembelian;
    diskon = 0;
  if(tot_pembelian >= 100000)
    diskon = 0.05*tot_pembelian;
   else
    diskon = 0;
      cout<<"besar diskon = Rp" <<diskon;
}
```
<p>Program ini digunakan untuk menghitung besar diskon berdasarkan total pembelian. Program menggunakan variabel <code>tot_pembelian</code> untuk menyimpan total harga pembelian dan variabel <code>diskon</code> untuk menyimpan jumlah diskon yang diperoleh. Program terlebih dahulu meminta pengguna memasukkan total pembelian. Setelah itu, nilai <code>diskon</code> diberikan nilai awal 0.Kemudian program menggunakan percabangan <code>if-else</code> untuk menentukan apakah pembelian mendapatkan diskon. Jika total pembelian lebih besar atau sama dengan Rp100.000, maka diskon dihitung sebesar 5% dari total pembelian. Jika total pembelian kurang dari Rp100.000, maka nilai diskon tetap 0.</p>

<p>Pada akhir program, besar diskon ditampilkan menggunakan <code>cout</code>. Dengan demikian, program dapat menentukan secara otomatis apakah pembeli mendapatkan diskon 5% atau tidak berdasarkan total pembeliannya.</p>


### 6.

```C++
#include <iostream>
using namespace std;
int main(){
  int kode_hari;
    puts("Menentukan hari kerja/libur\n");
    puts("1=Senin 3=Rabu 5=Jumat 7=Minggu ");
    puts("2=Selasa 4=Kamis 6=Sabtu ");
  cin>>kode_hari;

  switch(kode_hari){
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
  cout<<"Hari Kerja"<<endl;
break;
    case 6:
    case 7:
  cout<<"Hari Libur"<<endl;
break;
default:
  cout<<"Kode masukan salah!!!"<<endl;
}
return 0;
}
```
<p>Program ini digunakan untuk menentukan apakah suatu kode hari termasuk hari kerja atau hari libur. Program menggunakan <code>switch</code> untuk memeriksa nilai dari variabel <code>kode_hari</code>. Jika <code>kode_hari</code> bernilai 1 sampai 5, program akan masuk ke <code>case</code> yang sesuai dan menampilkan tulisan <strong>“Hari Kerja”</strong>. Beberapa <code>case</code> tersebut tidak memiliki <code>break</code>, sehingga semuanya akan menuju perintah output yang sama.</p>

<p>Jika <code>kode_hari</code> bernilai 6 atau 7, program akan menampilkan tulisan <strong>“Hari Libur”</strong>. Kedua kode tersebut juga dikelompokkan dengan cara menggunakan beberapa <code>case</code> yang menuju satu perintah output.Apabila kode yang dimasukkan tidak berada pada rentang 1 sampai 7, program menjalankan <code>default</code> dan menampilkan pesan <strong>“Kode masukan salah!!!”</strong>.</p>

<p>Jadi, program membagi kode 1–5 sebagai hari kerja, kode 6–7 sebagai hari libur, dan kode selain itu dianggap sebagai masukan yang tidak valid.</p>


### 7.

```C++
#include <iostream>
using namespace std;
int main(){
  int jum;
  cout<<"jumlah perulangan: ";
  
  cin>>jum;
  for(int i=0; i<jum; i++){
    cout<<"saya pintar\n";
}
return 0;
}
```
<p>Program ini digunakan untuk menampilkan tulisan <code>"saya pintar"</code> secara berulang sesuai dengan jumlah yang dimasukkan oleh pengguna. Variabel <code>jum</code> digunakan untuk menyimpan jumlah perulangan. Program terlebih dahulu meminta pengguna memasukkan jumlah perulangan melalui <code>cin</code>. Nilai tersebut kemudian digunakan sebagai batas perulangan pada <code>for</code>. Perulangan dimulai dari nilai <code>i = 0</code> dan akan terus berjalan selama <code>i &lt; jum</code>. Setiap kali perulangan berjalan, program menampilkan tulisan <code>"saya pintar"</code>, kemudian nilai <code>i</code> bertambah satu.</p>

<p>Jadi, jika pengguna memasukkan angka 5, tulisan <strong>“saya pintar”</strong> akan muncul sebanyak 5 kali. Setelah jumlah perulangan tercapai, program berhenti dan selesai dijalankan.</p>

### 8.

```C++
#include <iostream>
using namespace std;
int main(){
  int i=1;
  int jum;
    cout<<"masukan banyak baris: ";
    
  cin>>jum;
  while(i<=jum){
    cout<<"baris ke-"<<i<<endl;
      i++;
    }
    return 0;
}
```
<p>Program ini digunakan untuk menampilkan nomor baris berdasarkan jumlah baris yang dimasukkan oleh pengguna. Variabel <code>jum</code> menyimpan banyaknya baris, sedangkan <code>i</code> digunakan sebagai penghitung yang dimulai dari 1. Program meminta pengguna memasukkan banyak baris. Setelah nilai tersebut diterima, program menggunakan perulangan <code>while</code> untuk menampilkan nomor baris satu per satu.</p>

<p>Selama nilai <code>i</code> masih kurang dari atau sama dengan <code>jum</code>, program akan menampilkan tulisan <code>"baris ke-"</code> diikuti nilai <code>i</code>. Setelah satu baris ditampilkan, nilai <code>i</code> ditambah satu agar perulangan dapat lanjut ke baris berikutnya. Jadi, jika pengguna memasukkan angka 4, program akan menampilkan <strong>baris ke-1</strong>, <strong>baris ke-2</strong>, <strong>baris ke-3</strong>, dan <strong>baris ke-4</strong>, lalu perulangan berhenti.</p>

### 9.

```C++
#include <iostream>
using namespace std;
int main(){
  int i = 1;
  int jum;

  cin >> jum;
  do{
    cout << "baris ke-" <<(i+1)<<endl;
    i++;
  } while(i<jum);
  return 0;
}
```
<p>Program ini digunakan untuk menampilkan nomor baris berdasarkan jumlah yang dimasukkan oleh pengguna. Variabel <code>jum</code> menyimpan jumlah baris, sedangkan variabel <code>i</code> digunakan sebagai penghitung yang dimulai dari 1. Setelah pengguna memasukkan nilai <code>jum</code>, program menjalankan perulangan <code>do-while</code>. Berbeda dengan <code>while</code>, perintah di dalam <code>do</code> akan dijalankan terlebih dahulu sebelum kondisi diperiksa. Di dalam perulangan, program menampilkan tulisan <code>"baris ke-"</code> diikuti dengan nilai <code>i + 1</code>. Setelah itu, nilai <code>i</code> ditambah satu. Program kemudian memeriksa kondisi <code>i &lt; jum</code> untuk menentukan apakah perulangan masih dilanjutkan.</p>

<p>Karena yang ditampilkan adalah <code>i + 1</code>, hasilnya dimulai dari <strong>baris ke-2</strong>. Misalnya, jika pengguna memasukkan <strong>5</strong>, program akan menampilkan baris ke-2, baris ke-3, baris ke-4, dan baris ke-5. Perulangan berhenti ketika nilai <code>i</code> sudah tidak memenuhi kondisi <code>i &lt; jum</code>.</p>

### 10.

```C++
#include <iostream>
#define MAX 5
using namespace std;
int main(){
  int i;
  struct data{
    char nama[40];    
    int nilai;
  };
  data siswa[MAX];
  for(i=0; i<MAX; i++){
    cout<<"masukkan data ke-"<<i+1<<endl;
    cout<<"nama = ";
    cin>>siswa[i].nama;
    cout<<"nilai = ";
    cin>>siswa[i].nilai;
  }
  cout<<"\ndata siswa\n";
  cout<<"=======";
  for(i=0; i<MAX; i++){
    cout<<"\n\ndata ke-"<<i+1;
    cout<<"\n\nnama="<<siswa[i].nama;
    cout<<"\n\nnilai="<<siswa[i].nilai;
  }
  return 0;
}
```
<p>Program ini digunakan untuk memasukkan dan menampilkan data siswa menggunakan <code>struct</code> dan array. Variabel <code>MAX</code> menentukan jumlah data siswa yang akan dimasukkan, yaitu 5 siswa, sedangkan variabel <code>i</code> digunakan sebagai penghitung sekaligus indeks array.Program membuat <code>struct data</code> yang memiliki dua bagian, yaitu <code>nama</code> untuk menyimpan nama siswa dan <code>nilai</code> untuk menyimpan nilai siswa. Setelah itu, <code>data siswa[MAX]</code> digunakan untuk membuat array yang dapat menyimpan data dari 5 siswa.</p>

<p>Program kemudian menjalankan perulangan <code>for</code> sebanyak 5 kali untuk memasukkan data siswa. Pada setiap perulangan, pengguna diminta memasukkan nama dan nilai yang kemudian disimpan pada <code>siswa[i].nama</code> dan <code>siswa[i].nilai</code>.</p>

<p>Setelah semua data dimasukkan, program menjalankan perulangan <code>for</code> kembali untuk menampilkan data setiap siswa. Program menampilkan nomor data, nama, dan nilai berdasarkan indeks <code>i</code>. Jadi, program ini menggunakan <code>struct</code> untuk mengelompokkan data nama dan nilai, kemudian array untuk menyimpan data dari 5 siswa.</p>

### 11.

```C++
#include <iostream>
using namespace std;
float ctof(float celcius);
int main() {
  float celcius, fahrenheit;
  cout <<"nilai Celcius? ";
  cin >> celcius;
  fahrenheit = ctof(celcius);
  cout<<celcius<<" Celcius adalah "<<fahrenheit<<" Fahrenheit"<<endl;
  return 0;
}
float ctof(float celcius){
  return (celcius * 1.8) + 32;
}
```
<p>Program ini digunakan untuk mengubah suhu dari satuan <code>Celcius</code> ke <code>Fahrenheit</code> menggunakan sebuah fungsi. Variabel <code>celcius</code> menyimpan suhu yang dimasukkan pengguna, sedangkan <code>fahrenheit</code> menyimpan hasil konversi. Program membuat deklarasi fungsi <code>ctof()</code> yang menerima nilai <code>celcius</code> bertipe <code>float</code> dan menghasilkan nilai bertipe <code>float</code>. Setelah pengguna memasukkan suhu Celcius, fungsi <code>ctof()</code> dipanggil dan hasilnya disimpan ke dalam variabel <code>fahrenheit</code>.</p>

<p>Di dalam fungsi <code>ctof()</code>, konversi dilakukan menggunakan rumus <code>(celcius * 1.8) + 32</code>. Nilai hasil perhitungan kemudian dikembalikan menggunakan <code>return</code> dan ditampilkan sebagai hasil konversi dari Celcius ke Fahrenheit.Jadi, program ini menerapkan konsep <code>function</code> untuk memisahkan proses perhitungan konversi suhu dari bagian utama program.</p>

## Unguided

### 1.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;
    cin >> a >> b;
    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian = " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian = " << a / b << endl;
    } else {
        cout << "Pembagian = Tidak dapat dilakukan" << endl;
    }
    return 0;
}
```

### Output Unguided 1 :

#### Output 1
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_1/output/output1.png" >

#### Output 2
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_1/output/output1.png" >

<p>Program ini digunakan untuk melakukan operasi aritmatika terhadap dua bilangan yang dimasukkan oleh pengguna. Variabel <code>a</code> dan <code>b</code> digunakan untuk menyimpan kedua bilangan tersebut. Setelah pengguna memasukkan nilai <code>a</code> dan <code>b</code>, program menghitung hasil <strong>penjumlahan</strong>, <strong>pengurangan</strong>, dan <strong>perkalian</strong> menggunakan operator aritmatika <code>+</code>, <code>-</code>, dan <code>*</code>.</p>

<p>Jadi, program ini digunakan untuk menghitung empat operasi aritmatika dasar dengan memastikan operasi pembagian hanya dilakukan ketika pembaginya tidak bernilai 0.</p>

### 2.

```C++
#include <iostream>
using namespace std;
int main() {
    int angka;
    cin >> angka;
    string kata[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan"
    };
    if (angka < 10) {
        cout << kata[angka];
    } else if (angka < 20) {
        if (angka == 10)
            cout << "sepuluh";
        else if (angka == 11)
            cout << "sebelas";
        else
            cout << kata[angka - 10] << " belas";
    } else if (angka < 100) {
        cout << kata[angka / 10] << " puluh";

        if (angka % 10 != 0)
            cout << " " << kata[angka % 10];
    } else {
        cout << "seratus";
    }
    return 0;
}
```

### Output Unguided 2 :

#### Output 1
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_1/output/output2.png" >

#### Output 2
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_1/output/output2.png" >

<p>Program ini digunakan untuk mengubah bilangan bulat dari <strong>0 sampai 100</strong> menjadi bentuk tulisan dalam bahasa Indonesia. Variabel <code>angka</code> menyimpan bilangan yang dimasukkan pengguna, sedangkan array <code>kata</code> digunakan untuk menyimpan tulisan angka dari nol sampai sembilan.</p>

<p>Jika angka kurang dari 10, program langsung mengambil tulisan dari array <code>kata</code>. Jika angka berada pada 10 sampai 19, program menangani angka 10 sebagai <code>sepuluh</code>, angka 11 sebagai <code>sebelas</code>, dan angka lainnya menggunakan pola <code>belas</code>.</p>

<p>Untuk angka 20 sampai 99, program menggunakan <code>angka / 10</code> untuk mendapatkan angka puluhan dan <code>angka % 10</code> untuk mendapatkan angka satuan. Jika angka satuannya tidak 0, tulisan angka satuan akan ditambahkan setelah kata <code>puluh</code>.</p>

<p>Jika nilai <code>angka</code> adalah 100, program masuk ke bagian <code>else</code> dan menampilkan <code>seratus</code>. Jadi, program menggunakan array, pembagian, modulus, dan percabangan untuk mengubah angka 0 sampai 100 menjadi bentuk tulisan.</p>

### 3.

```C++
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
```

### Output Unguided 3 :

#### Output 1
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_1/output/output3.png" >

#### Output 2
<img src = "https://github.com/leonardo0138/109082530036_Leonardo-Farriz-Garcya_SDT/blob/main/modul_1/output/output3.png" >

<p>Program ini digunakan untuk menampilkan pola angka berbentuk segitiga dengan tanda <code>*</code> di bagian tengah. Program menggunakan perulangan <code>for</code> untuk membuat baris dari nilai <code>n</code> sampai 0. Pada setiap baris, perulangan <code>j</code> pertama digunakan untuk memberikan jarak di bagian awal agar pola membentuk posisi seperti segitiga.</p>

<p>Jika nilai <code>i</code> sama dengan 0, program hanya menampilkan tanda <code>*</code>. Jika tidak, program menampilkan angka dari <code>i</code> turun sampai 1, kemudian tanda <code>*</code>, lalu angka dari 1 naik sampai <code>i</code>. Susunan tersebut membuat tanda <code>*</code> berada di tengah pola dan angka di sebelah kiri serta kanan memiliki urutan yang berlawanan.</p>

<p>Setelah seluruh bagian pada satu baris selesai ditampilkan, <code>cout &lt;&lt; endl</code> digunakan untuk berpindah ke baris berikutnya. Perulangan terus berjalan sampai <code>i</code> bernilai 0 sehingga seluruh pola selesai ditampilkan.</p>

## Kesimpulan

<p>Pada praktikum Modul 1 ini menunjukkan bahwa Code::Blocks adalah salah satu IDE yang memadai untuk pengembangan program C++, karena mendukung keseluruhan siklus pemrograman mulai dari penulisan kode, kompilasi, eksekusi, hingga penelusuran kesalahan melalui pesan error yang informatif. Pemahaman terhadap lingkungan kerja ini menjadi fondasi penting agar proses belajar pemrograman tidak terhambat oleh kendala teknis di luar logika program itu sendiri.</p>
<p>Praktikum ini memperlihatkan bahwa pemahaman terhadap tipe data, variabel, dan operator sangat menentukan ketepatan hasil suatu program. Hal ini terlihat pada perbedaan hasil antara operator pre-increment dan post-increment, yang membuktikan bahwa urutan eksekusi suatu operator dapat mengubah nilai akhir meskipun operasinya tampak sederhana. Begitu juga dengan struktur kondisional seperti if, if-else, dan switch-case menunjukkan bahwa program tidak hanya berjalan secara berurutan, tetapi juga mengambil keputusan berdasarkan suatu kondisi, sehingga lebih fleksibel dalam menyelesaikan berbagai kasus nyata.</p>

## Referensi

<br> [1] G. Fathonia dan Y. Yahfizham, "Analisis Studi Literatur Penyelesaian Operator Aritmatika Serta Bilangan Bulat dengan Code Sederhana pada Bahasa Pemrograman C++," *SABER: Jurnal Teknik Informatika, Sains dan Ilmu Komunikasi*, vol. 2, no. 1, hlm. 9–16, 2024. 
 
<br> [2] R. A. Maylova, N. Noviana, Abdussalam, E. R. Pramudya, dan Muslih, "Sistem Manajemen Data Mahasiswa Berbasis Pemrograman C++ untuk Efisiensi Administrasi Akademik," *Jatekom (Jurnal Aplikasi Teknologi dan Komputasi)*, vol. 1, no. 3, hlm. 24–33, 2025.
 
<br> [3] Q. M. F. Z. Effendi, T. R. Zuhura, M. S. A. F. Amrulloh, F. Y. Arafat, M. Haris, N. R. Wahyudi, I. M. Putra, dan K. Ramadhan, "Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik Elektro Fakultas Teknik," *Jurnal Majemuk*, vol. 3, no. 1, hlm. 143–151, 2024.
 
<br> [4] A. Ma'arif, *Dasar Pemrograman C++*, Program Studi Teknik Elektro, Universitas Ahmad Dahlan, Yogyakarta.
 
<br> [5] Jurusan Teknik Elektro, *Modul Praktikum Dasar Pemrograman Komputer: Pengenalan Bahasa C++, Algoritma Pemrograman, dan Integrated Development Environment (IDE)*, Universitas Negeri Malang, Malang.
 
<br>[6] Program Studi Informatika, *Modul Praktikum Dasar-Dasar Pemrograman: Operator*, Universitas Pembangunan Jaya, Tangerang Selatan.