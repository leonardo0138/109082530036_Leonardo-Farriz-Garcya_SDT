# <h1 align="center">Laporan Praktikum Modul 5  - Singly Linked List (bagian kedua)</h1>

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
#define Nil NULL

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
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertLast(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address prev);
void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

address FindNodebyData(linkedList List, string data);
void FindNodebyAddress(linkedList List, address node);
void FindNodeByRange(linkedList List, int nilaiAwal, int nilaiAkhir);

void updateFirst(linkedList &list);
void updateLast(linkedList &list);
void updateAfter(linkedList &list, address &prev);
void updateByNim(linkedList &list, string nim);

#endif
```

## list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedList &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List)
{
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List)
{
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev)
{
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedList List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedList List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedList &list)
{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;
    list.first->isidata = newData;
}

void updateLast(linkedList &list)
{
    if (isEmpty(list))
    {
        cout << "List kosong!" << endl;
    }
    else
    {
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama ;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    address nodeBantu = list.first;
    while (nodeBantu->next != Nil)
    {
        nodeBantu = nodeBantu->next;
    }

    nodeBantu->isidata = newData;
    }
}

void updateAfter(linkedList &list, address &prev)
{
    if (isEmpty(list))
    {
        cout << "List kosong!" << endl;
    }
    else
    {
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama ;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    prev->next->isidata = newData;
    }
}

void updateByNim(linkedList &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = FindNodebyData(list, nim);

        if (nodeBantu != Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> newData.nama;
            cout << "Masukan nim baru : ";
            cin >> newData.nim;
            cout << "Masukan umur baru : ";
            cin >> newData.umur;

            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// prosedur-prosedur untuk searching data didalam list
address FindNodebyData(linkedList List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodebyAddress(linkedList List, address node)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedList List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur > nilaiAwal && umur < nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```
## main.cpp
```C++
#include <iostream>
#include "list.h"
using namespace std;

int main(){
		linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
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

    updateAfter(List, nodeC);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER ---" << endl;
    printList(List);

    updateByNim(List, "2211110014");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);
    
    return 0;
}
```

<p>Program ini membuat linked list satu arah untuk menyimpan data mahasiswa, dan kodenya dibagi jadi tiga file: `list.h`, `list.cpp`, dan `main.cpp`. Di `list.h` ada `struct mahasiswa` yang isinya `nama`, `nim`, dan `umur`. Data itu dibungkus dalam `struct node` bersama pointer `next` yang menunjuk ke node setelahnya, dan `struct linkedList` hanya punya `first`, yaitu penunjuk ke node paling depan. `address` adalah nama lain untuk pointer ke `node`, dan `Nil` dipakai sebagai tanda bahwa tidak ada node lagi (nilainya `NULL`). Selain deklarasi fungsi dasar (insert, delete, print), header ini juga memuat deklarasi fungsi pencarian (`FindNodebyData`, `FindNodebyAddress`, `FindNodeByRange`) dan fungsi update (`updateFirst`, `updateLast`, `updateAfter`, `updateByNim`).
Di `list.cpp`, fungsi dasarnya sama seperti linked list biasa. `createList()` membuat list kosong, `isEmpty()` mengecek apakah `first` masih `Nil`, `alokasi()` membuat node baru dengan `new`, dan `dealokasi()` menghapus node dari memori. Untuk menambah data ada `insertFirst()` (di depan), `insertLast()` (di belakang, dengan menelusuri sampai node terakhir), dan `insertAfter()` (setelah node `Prev`). Untuk menghapus ada `delFirst()`, `delLast()`, dan `delAfter()`, yang menampilkan pesan kalau list kosong atau node tidak valid. Lalu `printList()` mencetak semua node, `nbList()` menghitung jumlah node, dan `deleteList()` menghapus seluruh node. Pada prosedur yang mengubah list, parameternya memakai `&` supaya yang berubah adalah list aslinya, bukan salinannya. Setiap prosedur juga diberi komentar *I.S.* (initial state) dan *F.S.* (final state) untuk menjelaskan kondisi sebelum dan sesudah prosedur berjalan.</p>
 
<p>Bagian pencarian menelusuri list dari depan sambil menghitung posisi node. `FindNodebyData()` mencari node yang `nama` atau `nim`-nya sama dengan data yang dicari, lalu menampilkan posisi dan isinya, atau pesan "tidak ditemukan" kalau tidak ada. Namun fungsi ini selalu mengembalikan `Nil` di akhir, jadi hasil pencariannya hanya ditampilkan di layar dan tidak bisa dipakai sebagai alamat node. `FindNodebyAddress()` mencari node berdasarkan alamatnya dan menampilkan posisi, alamat, dan isinya. `FindNodeByRange()` menampilkan semua node yang umurnya lebih besar dari `nilaiAwal` dan lebih kecil dari `nilaiAkhir` (batasnya tidak ikut dihitung).
 
<p>Bagian update meminta pengguna memasukkan nama, NIM, dan umur baru dengan `cin >>`, lalu menimpa `isidata` pada node yang dituju. `updateFirst()` mengubah node pertama, `updateLast()` menelusuri sampai node terakhir lalu mengubahnya, `updateAfter()` mengubah node yang ada setelah `prev` (`prev->next`), dan `updateByNim()` mencari node dengan `FindNodebyData()` lalu mengubahnya jika ditemukan. Karena `FindNodebyData()` selalu mengembalikan `Nil`, kondisi `nodeBantu != Nil` di `updateByNim()` tidak pernah terpenuhi, sehingga data tidak berubah. Karena memakai `cin >>`, nama hanya bisa diisi satu kata.</p>
 
<p>Di `main()`, dibuat list kosong dan lima node (`nodeA` sampai `nodeE`), lalu dimasukkan dengan urutan `insertFirst(A)`, `insertLast(B)`, `insertAfter(C, A)`, `insertAfter(D, C)`, dan `insertLast(E)`, sehingga urutan list menjadi A, C, D, B, E. Program mencetak isi list dan jumlah node (5). Setelah itu `updateAfter(List, nodeC)` dipanggil, yang mengubah node setelah C, yaitu `nodeD` (Satrio), dengan data yang diketik pengguna. Terakhir `updateByNim(List, "2211110014")` dipanggil: Arvin ditemukan di posisi ke-4 dan datanya ditampilkan, tetapi isi list tetap sama saat dicetak lagi.</p>

## Unguided

### soal1.

## singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
#include <cstddef>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif 
```
## singlylist.cpp
```C++
#include "Singlylist.h"

void CreateList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

int totalInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}

```
## main.cpp
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    CreateList(L);

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

    address hasil = findElm(L, 8);
    if (hasil != Nil) {
        cout << hasil->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    cout << "Total info dari kelima elemen adalah " << totalInfo(L) << endl;

    return 0;
}
```

### Output Unguided 1 :
<img src = "" >
 
<p>Program ini membuat linked list satu arah yang menyimpan bilangan bulat, dan kodenya dibagi jadi tiga file: `singlylist.h`, `singlylist.cpp`, dan `main.cpp`. Di `singlylist.h`, `infotype` adalah nama lain untuk `int`, jadi data yang disimpan berupa angka. Setiap elemen list dibuat dengan `struct ElmList` yang berisi `info` (angkanya) dan `next` (penunjuk ke elemen setelahnya). `address` adalah nama lain untuk pointer ke `ElmList`, dan `Nil` dipakai sebagai tanda bahwa tidak ada elemen lagi (nilainya `NULL`, yang didapat dari `<cstddef>`). Ada juga `struct List` yang hanya punya `first`, yaitu penunjuk ke elemen paling depan. Baris `#ifndef`, `#define`, dan `#endif` berguna supaya header tidak terbaca dua kali saat di-include, dan `using namespace std;` membuat `cout` dan `endl` bisa ditulis tanpa `std::`.Di `singlylist.cpp`, isi ketujuh fungsi ditulis. `CreateList()` membuat list kosong dengan mengisi `first` dengan `Nil`. `alokasi()` membuat elemen baru dengan `new`, mengisi `info` dengan angka yang diberikan, lalu mengisi `next` dengan `Nil` sebelum mengembalikan alamatnya. `dealokasi()` menghapus elemen dari memori dengan `delete` dan mengubah pointernya menjadi `Nil`. `insertFirst()` menaruh elemen baru di depan list: `next` elemen baru diarahkan ke `first` yang lama, lalu `first` dipindah ke elemen baru. `printInfo()` mencetak semua isi list dengan menelusuri dari `first` sampai bertemu `Nil`.</p>
 
<p>Dua fungsi tambahan juga menelusuri list dengan cara yang sama. `findElm()` mencari elemen yang `info`-nya sama dengan `x`: kalau ketemu, fungsi langsung mengembalikan alamat elemen itu, dan kalau sampai ujung list tidak ketemu, fungsi mengembalikan `Nil`. `totalInfo()` menjumlahkan seluruh `info` di dalam list dengan variabel `total` yang diawali 0, lalu mengembalikan hasilnya. Parameter `List &L` dan `address &P` memakai `&` supaya yang berubah adalah variabel aslinya, sedangkan fungsi yang hanya membaca list (`printInfo()`, `findElm()`, `totalInfo()`) cukup menerima `List L` tanpa `&`.</p>
 
<p>Di `main()`, list dibuat kosong, lalu lima angka dimasukkan satu per satu dengan `alokasi()` dan `insertFirst()`, yaitu 2, 0, 8, 12, dan 9. Karena `insertFirst()` selalu menaruh elemen di depan, angka yang masuk terakhir muncul paling awal, jadi urutan di list terbalik dari urutan masuknya. Setelah `printInfo()` mencetak isi list, `findElm(L, 8)` dipanggil dan alamat hasilnya disimpan di `hasil`. Kalau `hasil` bukan `Nil`, program mencetak isi elemen itu beserta tulisan "ditemukan dalam list", dan kalau `Nil`, program mencetak "8 tidak ditemukan dalam list". Terakhir, `totalInfo(L)` dipanggil untuk menjumlahkan semua angka: 9 + 12 + 8 + 0 + 2 = 31.</p>

## Kesimpulan

Dari praktikum ini dapat disimpulkan bahwa singly linked list adalah struktur data dinamis yang tersusun dari node-node yang saling terhubung lewat pointer `next`, dengan `first` sebagai penanda node paling depan dan `Nil` sebagai penanda akhir list. Pada bagian guided, operasi dasar list berhasil dibuat dan dijalankan, yaitu penyisipan (`insertFirst`, `insertLast`, `insertAfter`), penghapusan (`delFirst`, `delLast`, `delAfter`), pencarian, dan pembaruan data. Setiap operasi bekerja dengan menelusuri list dari `first` dan menyambungkan ulang pointer `next` di sekitar node yang dituju. Pemakaian `new` pada `alokasi()` dan `delete` pada `dealokasi()` juga menunjukkan bahwa memori pada linked list harus dikelola sendiri. Dari fungsi `updateByNim()` terlihat juga bahwa fungsi pencarian sebaiknya mengembalikan alamat node yang ditemukan, karena alamat itulah yang dibutuhkan oleh operasi lain seperti update.

Pada unguided, singly linked list dipakai untuk menyimpan bilangan bulat dengan tambahan fungsi `findElm()` dan `totalInfo()`. Karena `insertFirst()` selalu menaruh elemen di depan, angka 2, 0, 8, 12, dan 9 yang dimasukkan berurutan tersimpan dengan urutan terbalik, yaitu 9 12 8 0 2. Angka 8 berhasil ditemukan oleh `findElm()`, dan `totalInfo()` menghasilkan jumlah 31. Selain itu, pemisahan kode menjadi file header (`.h`), body (`.cpp`), dan `main.cpp` membuat program lebih terstruktur dan mudah dikembangkan.

## Referensi

 
<br> [1] R. D. Setiyawan, D. Hermawan, A. F. Abdillah, A. Mujayanah, dan R. Vindua, "Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List," *Jutech (Jurnal Teknologi)*, Universitas Pamulang, vol. 5, no. 2, hlm. 484–498, Desember 2024.
 
<br> [2] A. Wijoyo, A. R. Prasetiyo, A. A. Salsabila, K. Nife, Murni, dan P. B. Nadapdap, "Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian," *JRIIN (Jurnal Riset Informatika dan Inovasi)*, vol. 1, no. 12, hlm. 1244–1246, Juni 2024.
 
<br> [3] M. R. A. Fitra, A. A. S. Effendi, dan F. Ramadhani, "Implementasi Python dalam Pengolahan Data Pribadi Mahasiswa Ilmu Komputer Angkatan 23 pada Universitas Negeri Medan Menggunakan Struktur Data Linked List," *JATI (Jurnal Mahasiswa Teknik Informatika)*, vol. 9, no. 1, hlm. 51–58, Februari 2025.
