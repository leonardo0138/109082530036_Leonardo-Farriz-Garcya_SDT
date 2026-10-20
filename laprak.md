# <h1 align="center">Laporan Praktikum Modul 4  - Singly Linked List </h1>

<p align="center">Leonardo Farriz Garcya - 109082530036</p>

# Dasar Teori
 
### A. Konsep Linked List dan ADT Linked List<br/>
 
Linked list merupakan salah satu bentuk struktur data yang representasinya berupa rangkaian elemen saling berkait dan bersifat fleksibel karena dapat tumbuh maupun mengerut sesuai kebutuhan program.
 
#### 1. Pengertian dan Representasi Linked List
 
Data yang disimpan dalam linked list bisa berupa data tunggal, yaitu data yang hanya terdiri dari satu variabel (misalnya nama bertipe string), maupun data majemuk berupa record yang di dalamnya memuat beberapa data sekaligus, misalnya data mahasiswa yang terdiri dari nama, NIM, dan alamat. Linked list dapat diimplementasikan dengan dua cara, yakni memakai array atau pointer, namun pointer lebih banyak dipilih karena sifatnya dinamis dan lebih mudah menangani keterkaitan antarelemen, sementara array bersifat statis dan hanya cocok dipakai ketika jumlah data maksimalnya sudah diketahui sejak awal [1].
 
#### 2. Model dan Operasi Dasar ADT Linked List
 
ADT linked list memiliki beberapa model yang disesuaikan dengan karakteristik dan kebutuhan pemakaiannya, di antaranya singly linked list, doubly linked list, circular linked list, hingga bentuk turunannya seperti stack, queue, tree, dan graph. Walaupun modelnya beragam, operasi dasar yang diterapkan pada list umumnya relatif sama, yaitu penciptaan dan inisialisasi list, penyisipan elemen (*insert*), penghapusan elemen (*delete*), penelusuran dan penampilan elemen (*view*), pencarian elemen (*searching*), serta pengubahan isi elemen (*update*) [2].
 
#### 3. Istilah dan Komponen dalam Singly Linked List
 
Singly linked list adalah model linked list yang hanya memiliki satu arah pointer, sehingga pembacaan datanya cuma bisa dilakukan maju dan pencarian elemen dilakukan secara sekuensial jika data tidak terurut. Tiap elemen (*node*) dalam singly linked list terdiri dari dua bagian, yaitu data yang menyimpan informasi utama dan *successor* (*next*) yang menyimpan alamat elemen berikutnya. Beberapa istilah yang menyertainya adalah *first*/*head* sebagai pointer yang menunjuk elemen pertama list, serta NULL atau Nil yang menandakan suatu pointer tidak mengacu ke mana pun, biasa dipakai untuk menandai elemen terakhir dalam list [3].
 
### B. Implementasi Singly Linked List dalam Bahasa C++<br/>
 
Pada praktiknya, ADT singly linked list di C++ direpresentasikan lewat dua struct, yaitu struct elemen yang menyimpan data beserta pointer penghubungnya, dan struct list yang menyimpan pointer menuju elemen pertama.
 
#### 1. Deklarasi Struktur dan Pembentukan List
 
Pembuatan list baru dilakukan lewat fungsi `createList()`, yang bertugas mengeset nilai awal `first` menjadi Nil sehingga list dianggap kosong. Untuk menambah elemen baru ke dalamnya, diperlukan proses pengalokasian memori lewat fungsi `alokasi()`, yang pada bahasa C memakai `malloc()`, sedangkan pada C++ dapat dipersingkat memakai operator `new`. Sebaliknya, ketika sebuah elemen tidak lagi dipakai, memorinya perlu dibebaskan lewat proses dealokasi, yang pada C memakai `free()` dan pada C++ memakai `delete`. Tersedia pula fungsi `isEmpty()` untuk mengecek status list, yang berguna sebelum menjalankan operasi lain seperti penghapusan [1].
 
#### 2. Operasi Penyisipan dan Penelusuran Elemen
 
Penyisipan elemen baru ke dalam list dapat dilakukan pada tiga posisi berbeda, yaitu *insert first* untuk meletakkan elemen di awal list, *insert last* untuk meletakkan di akhir list, dan *insert after* untuk meletakkan setelah node tertentu. Pada *insert first*, pointer `next` milik elemen baru diarahkan ke elemen yang sebelumnya menjadi `first`, lalu `first` pada list diperbarui agar menunjuk ke elemen baru tersebut; pola serupa, dengan urutan penyambungan pointer yang berbeda, juga berlaku pada *insert last* dan *insert after*. Setelah elemen-elemen tersusun, operasi *view* dipakai untuk menelusuri list mulai dari elemen pertama hingga elemen terakhir sembari menampilkan data yang tersimpan pada tiap node yang dikunjungi.
 
#### 3. Operasi Penghapusan dan Pembaruan Data
 
Operasi penghapusan (*delete*) mengenal variasi posisi yang sama dengan penyisipan, yaitu *delete first*, *delete last*, dan *delete after*, yang pada dasarnya bekerja dengan menyambungkan kembali pointer `next` di sekitar elemen yang akan dihapus agar list tetap tersambung, sebelum memori milik elemen tersebut dibebaskan lewat fungsi dealokasi. Sementara itu, operasi *update* dipakai untuk mengubah isi data pada node tertentu di dalam list, dan biasanya diawali dengan proses pencarian lebih dulu untuk menemukan node yang datanya hendak diubah. Seluruh primitif tersebut, mulai dari pembuatan list, penyisipan, penelusuran, penghapusan, hingga pembaruan data, pada praktiknya tetap disimpan terpisah dalam file header (*.h) dan file body (*.cpp), sejalan dengan prinsip modular yang juga diterapkan pada ADT secara umum.

```

## Guided

### 1. 

## list.h
```C++
#ifndef List_h
#define List_h
#define Nil nullptr

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedList
{
    address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi (string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);
#endif
```

## list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List)
{
    if (List.first == Nil){
        return true;
    }else{
        return false;
    }
}

void createList(linkedList &List)
{
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &list, address nodeBaru)
{
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedList &list, address nodeBaru, address prev)
{
    if (prev != Nil)
    {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    }else{
        cout<< "Node sebelumnya tidak valid"<< endl;
    }
}

void insertLast(linkedList &list, address nodeBaru)
{
    if (isEmpty(list))
    {
        list.first = nodeBaru;
    }else
    {
        address nodeBantu = list.first;
        while(nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedList &list)
{
    address nodeHapus;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }else
    {
        cout<<"List Kosong" << endl;
    }
}

void delLast(linkedList &list)
{
    address nodeHapus, nodePrev;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first; 
        if(nodeHapus->next == Nil)
        {
            list.first->next = Nil;
            dealokasi(nodeHapus);
        }else
        {
            while(nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }else
    {
        cout<<"List kosong"<< endl;
    }
}

void delAfter(linkedList &list, address nodeHapus, address nodePrev)
{
    if(isEmpty(list) == true)
    {
        cout<< "List kosong"<<endl;
    }else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }else
        {
            cout<<"Node sebelumnya (prev) tidak valid"<< endl;
        }
    }
}

void printList(linkedList list)
{
    if(isEmpty(list))
    {
        cout<< "List kosong." << endl;
    }else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}


int nbList(linkedList list)
{
    int count = 0;
    address nodeBantu = list.first;
    while(nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedList &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;

    while(nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout<< "List sudah terhapus"<< endl;
}
```
## main.cpp
```C++
#include "list.h"
using namespace std;

int main()
{
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
}
```

<p>Program ini membuat linked list satu arah untuk menyimpan data mahasiswa, dan kodenya dibagi jadi tiga file: `list.h`, `list.cpp`, dan `main.cpp`. Di `list.h` ada `struct mahasiswa` yang isinya `nama`, `nim`, dan `umur`. Data itu dibungkus lagi dalam `struct node` bersama pointer `next` yang menunjuk ke node setelahnya. Ada juga `struct linkedList` yang hanya punya `first`, yaitu penunjuk ke node paling depan. `address` adalah nama lain untuk pointer ke `node`, dan `Nil` dipakai sebagai tanda bahwa tidak ada node lagi (nilainya `nullptr`). Baris `#ifndef`, `#define`, dan `#endif` di awal dan akhir file berguna supaya header tidak terbaca dua kali saat di-include.
Di `list.cpp`, isi semua fungsi yang dideklarasikan tadi ditulis. `createList()` membuat list kosong dengan mengisi `first` dengan `Nil`, dan `isEmpty()` mengecek apakah `first` masih `Nil`. `alokasi()` membuat node baru dengan `new` lalu mengisinya dengan data, sedangkan `dealokasi()` menghapus node dari memori dengan `delete`.</p>
 
<p>Untuk menambah data ada tiga cara. `insertFirst()` menaruh node baru di depan, `insertLast()` berjalan sampai node terakhir lalu menyambungkan node baru di belakangnya, dan `insertAfter()` menyisipkan node baru tepat setelah node `prev`. Untuk menghapus juga ada tiga: `delFirst()` memindahkan `first` ke node berikutnya lalu menghapus node yang lama, `delLast()` berjalan sampai node terakhir sambil mengingat node sebelumnya, lalu memutus sambungannya dan menghapus node terakhir, dan `delAfter()` menghapus node yang ada setelah `nodePrev`. Ketiga fungsi hapus ini akan menampilkan pesan kalau list kosong atau node yang dimaksud tidak valid. Sisanya, `printList()` mencetak semua node dari depan sampai `Nil`, `nbList()` menghitung jumlah node, dan `deleteList()` menghapus semua node lalu mengembalikan `first` ke `Nil`. Pada prosedur yang mengubah isi list, parameternya memakai `&` supaya yang berubah adalah list aslinya, bukan salinannya.</p>
 
<p>Di `main()`, pertama dibuat list kosong dan lima node, yaitu `nodeA` sampai `nodeE`. Lalu node-node itu dimasukkan satu per satu. Setelah `insertFirst(A)` isinya A. Setelah `insertLast(B)` jadi A, B. Setelah `insertAfter(C, A)` jadi A, C, B. Setelah `insertAfter(D, C)` jadi A, C, D, B. Terakhir `insertLast(E)` membuat urutannya A, C, D, B, E. Program lalu mencetak isi list dan jumlah node, yaitu 5. Di akhir, `delFirst()` dipanggil dan node A terhapus, tapi hasilnya tidak terlihat di layar karena setelah itu tidak ada `printList()` lagi.</p>

## Unguided

### soal1.

## singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
#include <iostream>

#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif
```
## singlylist.cpp
```C++
#include "Singlylist.h"
 
void createList(List &L) {
    L.first = Nil;
}
 
address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}
 
void dealokasi(address &P) {
    delete P;
    P = Nil;
}
 
void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}
 
void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```
## main.cpp
```C++
#include <iostream>
#include "Singlylist.h"
 
using namespace std;
 
int main() {
    List L;
    address P1, P2, P3, P4, P5;
 
    createList(L);
 
    P1 = alokasi(2);
    insertFirst(L, P1);
 
    P2 = alokasi(0);
    insertFirst(L, P2);
 
    P3 = alokasi(8);
    insertFirst(L, P3);
 
    P4 = alokasi(12);
    insertFirst(L, P4);
 
    P5 = alokasi(9);
    insertFirst(L, P5);
 
    printInfo(L);
 
    return 0;
}
```

### Output Unguided 1 :
<img src = "" >
 
<p>Program ini membuat linked list satu arah yang menyimpan bilangan bulat, dan kodenya dibagi jadi tiga file: singlylist.h, singlylist.cpp, dan main.cpp. Di singlylist.h, infotype adalah nama lain untuk int, jadi data yang disimpan berupa angka. Setiap elemen list dibuat dengan struct elmlist yang berisi info (angkanya) dan next (penunjuk ke elemen setelahnya). address adalah nama lain untuk pointer ke elmlist, dan Nil dipakai sebagai tanda bahwa tidak ada elemen lagi (nilainya NULL). Ada juga struct List yang hanya punya first, yaitu penunjuk ke elemen paling depan. Baris #ifndef, #define, dan #endif berguna supaya header tidak terbaca dua kali saat di-include, dan using namespace std; membuat cout dan endl bisa ditulis tanpa std::.</p>

<p>Di singlylist.cpp, isi kelima fungsi ditulis. createList() membuat list kosong dengan mengisi first dengan Nil. alokasi() membuat elemen baru dengan new, mengisi info dengan angka yang diberikan, lalu mengisi next dengan Nil sebelum mengembalikan alamatnya. dealokasi() menghapus elemen dari memori dengan delete dan mengubah pointernya menjadi Nil. insertFirst() menaruh elemen baru di depan list: next elemen baru diarahkan ke first yang lama, lalu first dipindah ke elemen baru. printInfo() mencetak semua isi list dengan menelusuri dari first sampai bertemu Nil. Parameter List &L dan address &P memakai & supaya yang berubah adalah variabel aslinya, bukan salinannya.</p>

<p>Di main(), list dibuat kosong, lalu lima angka dimasukkan satu per satu dengan alokasi() dan insertFirst(), yaitu 2, 0, 8, 12, dan 9. Karena insertFirst() selalu menaruh elemen di depan, angka yang masuk terakhir justru muncul paling awal, jadi urutan di list terbalik dari urutan masuknya. Setelah semua masuk, printInfo() mencetak isi list.</p>

## Kesimpulan

<p>Jadi singly linked list adalah struktur data yang tiap elemennya (node) menyimpan data dan pointer <code>next</code> ke elemen berikutnya. Karena itu ukuran list bisa bertambah dan berkurang sesuai kebutuhan, berbeda dengan array yang ukurannya tetap. Pada bagian guided, ADT singly linked list untuk data mahasiswa berhasil diimplementasikan dengan memisahkan deklarasi (<code>list.h</code>) dan definisi fungsi (<code>list.cpp</code>) dari program utama (<code>main.cpp</code>). Operasi dasarnya, yaitu pembuatan list, alokasi dan dealokasi memori, penyisipan (<code>insertFirst</code>, <code>insertLast</code>, <code>insertAfter</code>), penghapusan (<code>delFirst</code>, <code>delLast</code>, <code>delAfter</code>), serta penelusuran dan penghitungan node, semuanya bekerja dengan cara menyambungkan ulang pointer <code>next</code>. Urutan penyambungan pointer menentukan hasil akhir list, seperti pada <code>insertAfter</code> yang harus mengarahkan <code>next</code> node baru ke node setelah <code>prev</code> terlebih dahulu sebelum <code>prev</code> diarahkan ke node baru.</p>

<p>Pada bagian unguided, list bilangan bulat dibuat dengan <code>createList()</code>, <code>alokasi()</code>, <code>insertFirst()</code>, dan <code>printInfo()</code>. Karena <code>insertFirst()</code> selalu menaruh elemen baru di depan list, angka yang dimasukkan paling akhir muncul paling awal, sehingga urutan tampilan (9, 12, 8, 0, 2) berkebalikan dengan urutan pemasukannya (2, 0, 8, 12, 9). Praktikum ini juga menunjukkan pentingnya pengelolaan memori, yaitu setiap node yang dialokasikan dengan <code>new</code> harus dibebaskan dengan <code>delete</code> lewat dealokasi, serta penggunaan parameter referensi (<code>&</code>) agar perubahan pada list dan pointer berlaku pada variabel aslinya. Dengan demikian, pemahaman tentang konsep node, pointer, dan urutan penyambungan elemen menjadi dasar penting untuk mempelajari struktur data lanjutan seperti doubly linked list, stack, dan queue.</p>


## Referensi

 
<br> [1] R. D. Setiyawan, D. Hermawan, A. F. Abdillah, A. Mujayanah, dan R. Vindua, "Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List," *Jutech (Jurnal Teknologi)*, Universitas Pamulang, vol. 5, no. 2, hlm. 484–498, Desember 2024.
 
<br> [2] A. Wijoyo, A. R. Prasetiyo, A. A. Salsabila, K. Nife, Murni, dan P. B. Nadapdap, "Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian," *JRIIN (Jurnal Riset Informatika dan Inovasi)*, vol. 1, no. 12, hlm. 1244–1246, Juni 2024.
 
<br> [3] M. R. A. Fitra, A. A. S. Effendi, dan F. Ramadhani, "Implementasi Python dalam Pengolahan Data Pribadi Mahasiswa Ilmu Komputer Angkatan 23 pada Universitas Negeri Medan Menggunakan Struktur Data Linked List," *JATI (Jurnal Mahasiswa Teknik Informatika)*, vol. 9, no. 1, hlm. 51–58, Februari 2025.
