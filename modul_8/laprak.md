# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1> 

<p align="center">Leonardo Farriz Garcya - 109082530036</p>

# Dasar Teori
### A. Konsep dan Operasi Dasar Queue<br/>
 
Queue merupakan salah satu bentuk struktur data turunan dari linked list, yang penerapannya banyak dijumpai pada kasus antrean sehari-hari.
 
#### 1. Pengertian dan Prinsip FIFO pada Queue
 
Queue merupakan struktur data yang dapat diumpamakan seperti sebuah antrean, di mana elemen yang pertama kali masuk adalah elemen yang pertama kali keluar atau diakses, prinsip ini biasa disebut FIFO (*First In First Out*). Berbeda dengan stack yang hanya mengakses satu ujung saja, queue justru mengakses kedua ujungnya sekaligus: penghapusan selalu dilakukan pada bagian depan (*head*), sedangkan penyisipan selalu dilakukan pada bagian belakang (*tail*) [2].
 
#### 2. Komponen Queue dan Representasinya dengan Pointer
 
Dalam implementasinya, queue dapat direpresentasikan dengan singly linked list maupun doubly linked list, dan komponennya pada dasarnya tidak jauh berbeda dengan list biasa. Perbedaannya terletak pada struct queue itu sendiri, yang memiliki dua field pointer sekaligus, yaitu *head* yang menunjuk elemen pertama dan *tail* yang menunjuk elemen terakhir, sehingga kedua ujung queue dapat diakses langsung tanpa perlu menelusuri list dari awal [3].
 
#### 3. Operasi Enqueue dan Dequeue
 
Terdapat dua operasi utama dalam queue, yaitu *enqueue* untuk menyisipkan elemen dan *dequeue* untuk mengambil elemen. Operasi *enqueue* selalu meletakkan elemen baru di posisi *tail*, dengan menyambungkan `next` milik elemen *tail* lama ke elemen baru lalu memperbarui *tail* pada queue. Sebaliknya, operasi *dequeue* selalu mengambil elemen pada posisi *head*, kemudian memindahkan *head* ke elemen berikutnya, sehingga urutan antrean tetap terjaga sesuai waktu kedatangannya [2].
 
### B. Implementasi Queue dengan Representasi Tabel<br/>
 
Selain dengan pointer, queue juga biasa direpresentasikan dengan tabel, dengan beberapa alternatif mekanisme yang masing-masing punya kelebihan dan keterbatasannya sendiri.
 
#### 1. Perbedaan Representasi Tabel dan Pointer pada Queue
 
Selain dengan pointer, queue juga bisa direpresentasikan dengan tabel (*array*). Perbedaan mendasarnya terletak pada manajemen memori dan keterbatasan jumlah antreannya: representasi pointer bersifat dinamis dan memerlukan manajemen memori lewat alokasi serta dealokasi, sedangkan representasi tabel memiliki jumlah antrean yang terbatas sesuai kapasitas array, namun tidak membutuhkan proses manajemen memori tersebut [1].
 
#### 2. Alternatif Mekanisme Head dan Tail
 
Representasi tabel pada queue dapat diterapkan dengan beberapa alternatif mekanisme. Alternatif pertama membiarkan *head* tetap diam pada posisi 1 selama queue tidak kosong, sementara *tail* bergerak maju setiap kali ada penyisipan; namun saat penghapusan dilakukan, seluruh elemen perlu digeser agar susunannya tetap merapat ke depan, sehingga caranya mencerminkan antrean di dunia nyata tetapi kurang efisien. Alternatif kedua membiarkan *head* dan *tail* sama-sama bergerak maju tanpa pergeseran elemen, yang lebih efisien namun dapat menimbulkan kondisi "queue penuh semu" ketika *tail* sudah mencapai indeks maksimum meski sebenarnya masih ada ruang kosong di depan. Alternatif ketiga mengatasi hal ini dengan membiarkan *head* dan *tail* "berputar" kembali ke indeks awal setelah mencapai indeks maksimum, sehingga tabel dipakai layaknya buffer melingkar (*circular buffer*) dan tidak memerlukan pergeseran elemen sama sekali.
 
#### 3. Primitif-primitif dalam Queue Representasi Tabel
 
Primitif-primitif pada queue representasi tabel pada dasarnya serupa dengan representasi pointer, hanya saja ditambah fungsi `isFull()` untuk mengecek apakah antrean sudah mencapai kapasitas maksimumnya, mengingat representasi tabel memiliki keterbatasan jumlah elemen yang tidak dimiliki oleh representasi pointer.


## guided

### guided_1

### 1.

## queue.h
```C++


#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<string>
using namespace std;

struct Node
{
    string nama;
    Node *next;
};

struct queue
{
    Node *head, *tail;
};

void CreateQueue (queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue (queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);
#endif

```

## queue.cpp
```C++
#include "queue.h"
void CreateQueue(queue &Q)
{
    Q.head = Q.tail = nullptr;
}

bool isEmpty(queue Q)
{
    return Q.head == nullptr && Q.tail == nullptr;
}

bool isFull(queue Q)
{
    int maxQueue = 20;
    int counter = 0;
    Node *nodeBantu = Q.head;
    while (nodeBantu != Q.tail)
    {
        counter++;
        nodeBantu->next;
    }
    return counter >= maxQueue;
}

void enQueue(queue &Q, const string &nama)
{
    if (isEmpty(Q)){
        Node *nodeBaru = new Node{nama, nullptr};
        Q.head = Q.tail= nodeBaru;
    }else{
        Node *nodeBaru = new Node{nama, nullptr};
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
}

void deQueue (queue &Q){
    if (isEmpty(Q))
    { 
        cout<<"Queue kosong";
    }else{
        Node *nodehapus = Q.head;
        Q.head = Q.head -> next;
        delete nodehapus;
    }
}

void viewQueue (queue Q)
{
    if (isEmpty(Q))
    {
        cout<<"Queue Kosong";
    }else{
        Node *nodeBantu = Q.head;

        while (nodeBantu != nullptr)
        {
            cout<<"Nama: " <<nodeBantu-> nama;
            nodeBantu = nodeBantu ->next;
        }
    }
}

void clearQueue(queue &Q){
    if (isEmpty(Q)){
        cout<<"Queue Kosong";
    }else{
        Node *nodehapus = Q.head;
        while (nodehapus != nullptr){
            nodehapus= nodehapus -> next;
            deQueue(Q);
        }
    }
}

```
## main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    queue Q;
    CreateQueue (Q);

    enQueue(Q, "aedil ");
    enQueue(Q, "aflah ");
    enQueue(Q, "leo ");
    enQueue(Q, "garcya ");
    enQueue(Q, "zaky ");
    enQueue(Q, "gaza ");
    cout<<endl;

    cout<<"---Isi Queue Setelah enQueue---"<<endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout<<endl;

    cout<<"--- Isi Queue Setelah Dequeue---"<<endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0; 
}
```

<p>Program ini membuat queue (antrian) yang disimpan dalam bentuk linked list, dan kodenya dibagi jadi tiga file: `queue.h`, `queue.cpp`, dan `main.cpp`. Queue bekerja dengan prinsip FIFO (*First In First Out*), artinya data yang masuk paling awal adalah data yang keluar paling awal, seperti antrean di loket. Di `queue.h`, `struct Node` berisi `nama` bertipe `string` dan pointer `next` yang menunjuk ke node setelahnya. `struct queue` hanya punya dua pointer, yaitu `head` yang menunjuk ke node paling depan (tempat data keluar) dan `tail` yang menunjuk ke node paling belakang (tempat data masuk). Header ini juga memuat deklarasi tujuh fungsi: `CreateQueue()`, `isEmpty()`, `isFull()`, `enQueue()`, `deQueue()`, `viewQueue()`, dan `clearQueue()`. Baris `#ifndef`, `#define`, dan `#endif` mencegah header terbaca dua kali, dan `using namespace std;` membuat `cout`, `endl`, dan `string` bisa ditulis tanpa `std::`.</p>
 
<p>Di `queue.cpp`, `CreateQueue()` membuat queue kosong dengan mengisi `head` dan `tail` dengan `nullptr`, dan `isEmpty()` mengecek apakah keduanya masih `nullptr`. `isFull()` dimaksudkan untuk menghitung jumlah node dan membandingkannya dengan batas `maxQueue` yaitu 20, tetapi fungsi ini tidak dipanggil di `main()`. `enQueue()` membuat node baru dengan `new` lalu menaruhnya di belakang: kalau queue masih kosong, `head` dan `tail` sama-sama menunjuk ke node baru, dan kalau tidak, `next` milik `tail` diarahkan ke node baru lalu `tail` dipindah ke node baru itu. `deQueue()` menghapus node paling depan dengan menyimpan alamat `head` di `nodehapus`, memindahkan `head` ke node berikutnya, lalu menghapus node lama dengan `delete`. Kalau queue kosong, akan muncul pesan "Queue kosong".</p>
 
<p>`viewQueue()` menampilkan isi queue dengan menelusuri dari `head` sampai `nullptr` sambil mencetak `nama` tiap node, atau menampilkan "Queue Kosong" kalau queue kosong. `clearQueue()` mengosongkan seluruh queue: ia menelusuri node dengan `nodehapus` sambil memanggil `deQueue()` pada tiap putaran, sehingga semua node terhapus satu per satu dari depan. Parameter `queue &Q` memakai `&` (*call by reference*) pada fungsi yang mengubah queue supaya yang berubah adalah queue aslinya, sedangkan `isEmpty()`, `isFull()`, dan `viewQueue()` yang hanya membaca cukup memakai `queue Q`.</p>
 
<p>Di `main()`, queue dibuat dengan `CreateQueue()`, lalu enam nama dimasukkan berurutan dengan `enQueue()`: aedil, aflah, leo, garcya, zaky, dan gaza. Setelah `viewQueue()` menampilkan semuanya sesuai urutan masuk, `deQueue()` dipanggil empat kali sehingga empat nama paling depan (aedil, aflah, leo, garcya) keluar lebih dulu, dan tersisa zaky dan gaza. Setelah isi queue ditampilkan lagi, `clearQueue()` dipanggil untuk menghapus sisa node. Spasi di akhir tiap nama (misalnya `"aedil "`) sengaja ditulis supaya antarnama pada output tidak menempel.</p>

### guided_2

### 2.

## queue.h
```C++



#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

struct queue {
    string nama[MAX];
    int head;
    int tail;
};

bool isEmpty(queue Q);
bool isFull(queue Q);
void createQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif

```

## queue.cpp
```C++

#include "queue.h"
#include <iostream>

using namespace std;

// isEmpty
bool isEmpty(queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

// isFull implementasi 1 & 2
bool isFull(queue Q) {
    return (Q.tail == MAX - 1);
}

// createQueue
void createQueue(queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

// enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama) {
    if (isFull(Q)) {
        cout << "Queue sudah penuh!" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }

        Q.nama[Q.tail] = nama;

        cout << "Nama " << nama
             << " berhasil ditambahkan ke dalam queue!"
             << endl;
    }
}

// dequeue implementasi 1
void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Menghapus data "
             << Q.nama[Q.head] << "..." << endl;

        for (int i = 0; i < Q.tail; i++) {
            Q.nama[i] = Q.nama[i + 1];
        }

        Q.tail--;

        if (Q.tail < 0) {
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// viewQueue implementasi 1 & 2
void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << i - Q.head + 1
                 << ". " << Q.nama[i] << endl;
        }
    }

    cout << endl;
}


```
## main.cpp
```C++

#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    queue Q;

    createQueue(Q);

    enQueue(Q, "Dimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");

    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);

    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}

```
<p>Program ini membuat queue (antrian) menggunakan array dengan kapasitas maksimal 5 data. Queue bekerja dengan prinsip FIFO (First In First Out), artinya data yang pertama masuk akan menjadi data pertama yang keluar. Kode dibagi menjadi tiga file, yaitu queue.h, queue.cpp, dan main.cpp. Di queue.h, terdapat konstanta MAX bernilai 5 dan struct queue yang memiliki tiga atribut, yaitu array nama untuk menyimpan data bertipe string, head untuk menunjukkan posisi data paling depan, dan tail untuk menunjukkan posisi data paling belakang. Nilai awal head dan tail adalah -1 yang menandakan queue kosong. Header ini juga berisi deklarasi enam fungsi, yaitu isEmpty(), isFull(), createQueue(), enQueue(), deQueue(), dan viewQueue(). Sementara itu, #ifndef, #define, dan #endif digunakan untuk mencegah header terbaca lebih dari satu kali.</p>

<p>Di queue.cpp, isEmpty() memeriksa apakah queue kosong dengan mengecek nilai head dan tail, sedangkan isFull() memeriksa apakah posisi tail sudah mencapai indeks terakhir array (MAX - 1). createQueue() menginisialisasi queue dengan mengatur head dan tail menjadi -1. enQueue() menambahkan data ke belakang queue, dengan mengecek kapasitas terlebih dahulu. Jika queue kosong, head dan tail diatur menjadi 0, sedangkan jika sudah berisi, tail bertambah satu. deQueue() menghapus data paling depan dengan menggeser seluruh data setelahnya satu posisi ke depan, kemudian mengurangi nilai tail. Jika seluruh data sudah keluar, head dan tail dikembalikan menjadi -1. Sementara itu, viewQueue() menampilkan seluruh isi queue dari posisi head sampai tail. Fungsi yang mengubah isi queue menggunakan parameter queue &Q (call by reference) agar perubahan diterapkan langsung pada queue aslinya, sedangkan fungsi yang hanya membaca data menggunakan queue Q.</p>

<p>Di main.cpp, program membuat queue bernama Q dan menginisialisasinya menggunakan createQueue(). Selanjutnya, enam nama dimasukkan secara berurutan, yaitu Dimas, Arvin, Rizal, Hafizh, Fathur, dan Daffa. Karena kapasitas queue hanya 5 data, Daffa tidak berhasil dimasukkan dan muncul pesan bahwa queue sudah penuh. Setelah isi queue ditampilkan menggunakan viewQueue(), fungsi deQueue() dipanggil sebanyak empat kali sehingga Dimas, Arvin, Rizal, dan Hafizh keluar secara berurutan. Ketika viewQueue() dipanggil kembali, hanya Fathur yang tersisa.</p>

<p>Jadi, program ini menerapkan Queue Linear Statis menggunakan array dengan kapasitas tetap. Setiap kali deQueue() dilakukan, data yang tersisa digeser satu posisi ke depan sehingga head tetap berada di indeks 0 selama queue masih berisi data.</p>


## unguided

### soal 1. Alternatif 1

## queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```
## queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}

```

## main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout << "----------------------" << endl;
    cout << " H - T \t | info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    return 0;
}
```
### Output soal 1 :
<img src = "" >

<p>Program ini membuat ADT Queue menggunakan array dengan tipe data integer dan kapasitas maksimal 5 elemen. Queue bekerja dengan prinsip FIFO (First In First Out). Program menerapkan mekanisme Queue Alternatif 1, yaitu posisi head tetap diam di indeks 0, sedangkan tail bergerak mengikuti penambahan dan pengurangan data. Di queue.h, terdapat konstanta MAX bernilai 5, typedef int infotype untuk menentukan tipe data elemen berupa integer, serta struct Queue yang memiliki array info untuk menyimpan data dan dua variabel, yaitu head dan tail sebagai penanda posisi depan dan belakang queue. Header ini juga berisi deklarasi enam fungsi, yaitu createQueue(), isEmptyQueue(), isFullQueue(), enqueue(), dequeue(), dan printInfo(). Baris #ifndef, #define, dan #endif digunakan untuk mencegah header terbaca lebih dari satu kali.</p>

<p>Di queue.cpp, createQueue() menginisialisasi queue dengan mengatur head dan tail menjadi -1 sebagai tanda bahwa queue masih kosong. isEmptyQueue() memeriksa kondisi queue kosong dengan mengecek apakah kedua variabel tersebut bernilai -1, sedangkan isFullQueue() memeriksa apakah tail sudah mencapai indeks terakhir array (MAX - 1). enqueue() digunakan untuk menambahkan data ke belakang queue. Jika queue kosong, head dan tail diatur menjadi 0, sedangkan jika sudah berisi, posisi tail bertambah satu sebelum data disimpan ke dalam array. dequeue() mengeluarkan data paling depan dengan menyimpannya terlebih dahulu ke variabel x, kemudian menggeser seluruh elemen setelahnya satu posisi ke depan dan mengurangi nilai tail. Jika seluruh data sudah dikeluarkan, head dan tail dikembalikan menjadi -1. Fungsi ini mengembalikan nilai data yang berhasil dikeluarkan, sedangkan jika queue kosong akan mengembalikan -1. Sementara itu, printInfo() menampilkan posisi head, tail, dan seluruh isi queue. Jika tidak ada data, fungsi akan menampilkan pesan "empty queue".</p>

<p>Di main.cpp, program membuat variabel Q bertipe Queue, kemudian menginisialisasinya menggunakan createQueue(). Selanjutnya, printInfo() dipanggil untuk menampilkan kondisi awal queue yang masih kosong. Program kemudian memasukkan angka 5, 2, dan 7 secara berurutan menggunakan enqueue(), dengan setiap perubahan kondisi ditampilkan melalui printInfo(). Setelah itu, dequeue() dipanggil untuk mengeluarkan angka 5, kemudian angka 4 dimasukkan ke dalam queue. Selanjutnya, dequeue() dipanggil dua kali untuk mengeluarkan angka 2 dan 7. Pada akhir program, angka 4 masih tersisa di dalam queue.</p>

<p>Jadi, program ini menerapkan Queue Alternatif 1 dengan mekanisme head tetap berada di indeks 0 selama queue berisi data, sedangkan tail bergerak mengikuti jumlah elemen. Setiap proses dequeue() menyebabkan elemen yang tersisa bergeser satu posisi ke depan agar urutan FIFO tetap terjaga. Mekanisme ini sesuai dengan implementasi Queue Linear menggunakan array pada soal nomor 1.</p>

## Unguided 2

### soal 2. Alternatif 2 (head bergerak, tail bergerak).

## queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

## queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.head == 0 && Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        if (Q.tail == MAX - 1) {
            int n = Q.tail - Q.head + 1;
            for (int i = 0; i < n; i++) {
                Q.info[i] = Q.info[Q.head + i];
            }
            Q.head = 0;
            Q.tail = n - 1;
        }
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```

## main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout << "----------------------" << endl;
    cout << " H - T \t | info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    return 0;
}
```
### Output soal 2 :
<img src = "" >

<p>Program menerapkan mekanisme Queue Alternatif 2, yaitu posisi `head` dan `tail` sama-sama bergerak mengikuti proses penambahan dan penghapusan data. Di `queue.h`, terdapat konstanta `MAX` bernilai 5, `typedef int infotype` untuk menentukan tipe data elemen berupa integer, serta `struct Queue` yang memiliki array `info` untuk menyimpan data dan dua variabel, yaitu `head` dan `tail` sebagai penanda posisi depan dan belakang queue. Header ini juga berisi deklarasi enam fungsi, yaitu `createQueue()`, `isEmptyQueue()`, `isFullQueue()`, `enqueue()`, `dequeue()`, dan `printInfo()`. Baris `#ifndef`, `#define`, dan `#endif` digunakan untuk mencegah header terbaca lebih dari satu kali.</p>

<p>Di `queue.cpp`, `createQueue()` menginisialisasi queue dengan mengatur `head` dan `tail` menjadi -1 sebagai tanda queue kosong. `isEmptyQueue()` memeriksa apakah queue kosong dengan mengecek kedua variabel tersebut, sedangkan `isFullQueue()` memeriksa apakah `head` berada di indeks 0 dan `tail` sudah mencapai indeks terakhir array (`MAX - 1`). `enqueue()` digunakan untuk menambahkan data ke belakang queue. Jika queue kosong, `head` dan `tail` diatur menjadi 0. Namun, jika posisi `tail` sudah mencapai indeks terakhir, elemen yang masih tersimpan akan digeser ke depan menggunakan perulangan `for`, kemudian posisi `head` diatur kembali menjadi 0 dan `tail` disesuaikan dengan jumlah elemen yang tersisa. Setelah itu, `tail` bertambah satu dan data baru disimpan. Sementara itu, `dequeue()` digunakan untuk mengeluarkan data paling depan dengan mengambil nilai pada posisi `head`. Jika hanya tersisa satu elemen, `head` dan `tail` dikembalikan menjadi -1. Jika masih ada elemen lain, posisi `head` bertambah satu tanpa menggeser data. Fungsi `printInfo()` digunakan untuk menampilkan posisi `head`, `tail`, dan seluruh isi queue. Jika queue kosong, akan ditampilkan pesan "empty queue".</p>

<p>Di `main.cpp`, program membuat variabel `Q` bertipe `Queue`, kemudian menginisialisasinya menggunakan `createQueue()`. Selanjutnya, `printInfo()` dipanggil untuk menampilkan kondisi awal queue. Program memasukkan angka 5, 2, dan 7 secara berurutan menggunakan `enqueue()`, kemudian mengeluarkan angka 5 menggunakan `dequeue()`. Setelah itu, angka 4 dimasukkan kembali ke dalam queue. Proses berikutnya adalah memanggil `dequeue()` sebanyak dua kali untuk mengeluarkan angka 2 dan 7. Setiap proses penambahan dan penghapusan diikuti dengan `printInfo()` untuk melihat perubahan posisi `head`, `tail`, dan isi queue. Pada akhir program, angka 4 masih tersisa di dalam queue.</p>

<p>Jadi, program ini menerapkan Queue Alternatif 2 dengan posisi `head` dan `tail` yang sama-sama bergerak. Berbeda dengan Alternatif 1, proses `dequeue()` tidak menggeser elemen yang tersisa, melainkan cukup memindahkan posisi `head` ke indeks berikutnya. Jika `tail` sudah mencapai batas akhir array tetapi masih terdapat ruang di bagian depan, elemen yang tersisa akan digeser ke depan agar data baru dapat dimasukkan. Mekanisme ini membuat penggunaan array lebih efisien dibandingkan Alternatif 1 karena tidak perlu menggeser elemen setiap kali terjadi penghapusan.</p>

<p>Perbedaan Utama Soal 1 dan Soal 2

| Aspek | Alternatif 1 | Alternatif 2 |
|---|---|---|
| Head | Tetap di indeks 0 | Bergerak |
| Tail | Bergerak | Bergerak |
| Dequeue | Menggeser elemen | Head bertambah |
| Pergeseran data | Setiap dequeue | Saat tail mentok dan masih ada ruang di depan |
</p>

## Unguided 3

### soal 3.  Alternatif 3 (head dan tail berputar).

## queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

## queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return !isEmptyQueue(Q) && (Q.tail + 1) % MAX == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % MAX;
        }
    }
    cout << endl;
}
```

## main.cpp
```C++
#include "queue.h"

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout << "----------------------" << endl;
    cout << " H - T \t | info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    return 0;
}
```


### Output soal 3 :
<img src = "" >

<p>Program menerapkan mekanisme Queue Alternatif 3 atau *Queue Circular*, yaitu posisi `head` dan `tail` bergerak secara melingkar sehingga dapat kembali ke indeks awal ketika mencapai batas akhir array. Di `queue.h`, terdapat konstanta `MAX` bernilai 5, `typedef int infotype` untuk menentukan tipe data elemen berupa integer, serta `struct Queue` yang memiliki array `info` untuk menyimpan data dan dua variabel, yaitu `head` dan `tail` sebagai penanda posisi depan dan belakang queue. Header ini juga berisi deklarasi enam fungsi, yaitu `createQueue()`, `isEmptyQueue()`, `isFullQueue()`, `enqueue()`, `dequeue()`, dan `printInfo()`. Baris `#ifndef`, `#define`, dan `#endif` digunakan untuk mencegah header terbaca lebih dari satu kali.</p>

<p>Di `queue.cpp`, `createQueue()` menginisialisasi queue dengan mengatur `head` dan `tail` menjadi -1 sebagai tanda queue kosong. `isEmptyQueue()` memeriksa apakah kedua variabel tersebut bernilai -1, sedangkan `isFullQueue()` memeriksa apakah posisi berikutnya dari `tail` sama dengan `head` menggunakan operasi modulo (`% MAX`). `enqueue()` digunakan untuk menambahkan data ke dalam queue. Jika queue kosong, `head` dan `tail` diatur menjadi 0. Namun, jika sudah berisi, posisi `tail` digeser menggunakan rumus `(Q.tail + 1) % MAX` agar dapat kembali ke indeks 0 ketika mencapai batas akhir array. Selanjutnya, data disimpan pada posisi `tail`. Sementara itu, `dequeue()` digunakan untuk mengeluarkan data paling depan dengan mengambil nilai pada posisi `head`. Jika hanya tersisa satu elemen, `head` dan `tail` dikembalikan menjadi -1. Jika masih terdapat elemen lain, posisi `head` digeser menggunakan rumus `(Q.head + 1) % MAX`. Fungsi `printInfo()` menampilkan posisi `head`, `tail`, dan seluruh isi queue. Untuk menampilkan data secara melingkar, fungsi ini menggunakan perulangan `while` dan operasi modulo agar indeks dapat kembali ke awal array setelah mencapai batas akhir.</p>

<p>Di `main.cpp`, program membuat variabel `Q` bertipe `Queue`, kemudian menginisialisasinya menggunakan `createQueue()`. Selanjutnya, `printInfo()` dipanggil untuk menampilkan kondisi awal queue yang masih kosong. Program memasukkan angka 5, 2, dan 7 secara berurutan menggunakan `enqueue()`, kemudian mengeluarkan angka 5 menggunakan `dequeue()`. Setelah itu, angka 4 dimasukkan kembali ke dalam queue. Proses berikutnya adalah memanggil `dequeue()` sebanyak dua kali untuk mengeluarkan angka 2 dan 7. Setiap proses penambahan dan penghapusan diikuti dengan `printInfo()` untuk melihat perubahan posisi `head`, `tail`, dan isi queue. Pada akhir program, angka 4 masih tersisa di dalam queue.</p>

<p>Jadi, program ini menerapkan Queue Circular dengan posisi `head` dan `tail` yang bergerak secara melingkar menggunakan operasi modulo (`%`). Berbeda dengan Alternatif 1 dan 2, Queue Circular tidak memerlukan pergeseran elemen ketika data dikeluarkan maupun ketika `tail` mencapai batas akhir array. Posisi indeks dapat kembali ke awal selama masih tersedia ruang, sehingga penggunaan kapasitas array menjadi lebih optimal.</p>

<p>Perbedaan Ketiga Implementasi Queue

| Aspek | Alternatif 1 | Alternatif 2 | Alternatif 3 |
|---|---|---|---|
| Head | Tetap di indeks 0 | Bergerak | Bergerak melingkar |
| Tail | Bergerak | Bergerak | Bergerak melingkar |
| Dequeue | Menggeser elemen ke depan | Head bertambah | Head berputar |
| Enqueue | Tail bertambah | Bisa menggeser elemen ke depan | Tail berputar |
| Penggunaan modulo (`%`) | Tidak | Tidak | Ya |
| Pemanfaatan array | Kurang efisien | Lebih efisien | Lebih optimal |
 </p>

## Kesimpulan

<p>Berdasarkan praktikum Modul 8, dapat dipahami bahwa Queue merupakan struktur data yang menerapkan prinsip FIFO (*First In First Out*), yaitu data yang pertama masuk akan menjadi data pertama yang keluar. Queue memiliki dua operasi utama, yaitu `enqueue()` untuk menambahkan data dan `dequeue()` untuk mengeluarkan data. Dalam implementasinya, Queue dapat dibuat menggunakan Linked List maupun Array, yang masing-masing memiliki cara kerja dan karakteristik berbeda. Linked List menggunakan pointer `head` dan `tail` serta alokasi memori secara dinamis, sedangkan Array memiliki kapasitas penyimpanan yang tetap.</p>

<p>Pada praktikum ini, terdapat tiga alternatif implementasi Queue menggunakan Array. Alternatif 1 menggunakan `head` yang tetap dan `tail` yang bergerak, sehingga setiap proses `dequeue()` memerlukan pergeseran elemen ke depan. Alternatif 2 menggunakan `head` dan `tail` yang sama-sama bergerak, sehingga penghapusan tidak memerlukan pergeseran elemen, tetapi pergeseran tetap diperlukan ketika `tail` mencapai batas akhir array dan masih tersedia ruang di depan. Sementara itu, Alternatif 3 menggunakan konsep *Circular Queue* yang memungkinkan `head` dan `tail` bergerak secara melingkar dengan bantuan operasi modulo (`%`), sehingga elemen tidak perlu digeser ketika terjadi penambahan maupun penghapusan data.</p>

<p>Dari hasil praktikum, setiap implementasi memiliki kelebihan dan keterbatasannya masing-masing, terutama dalam pengelolaan memori dan efisiensi operasi. Praktikum ini membantu memahami bahwa pemilihan struktur data dan mekanisme Queue perlu disesuaikan dengan kebutuhan program. Selain memahami konsep FIFO, saya juga menjadi lebih memahami cara kerja `head`, `tail`, serta penerapan operasi `enqueue()` dan `dequeue()` dalam beberapa bentuk implementasi Queue menggunakan C++.</p>

## Referensi

<br> [1] R. D. Setiyawan, D. Hermawan, A. F. Abdillah, A. Mujayanah, dan R. Vindua, "Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List," Jutech (Jurnal Teknologi), Universitas Pamulang, vol. 5, no. 2, hlm. 484–498, Desember 2024.

<br> [2] A. Wijoyo, A. R. Prasetiyo, A. A. Salsabila, K. Nife, Murni, dan P. B. Nadapdap, "Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian," JRIIN (Jurnal Riset Informatika dan Inovasi), vol. 1, no. 12, hlm. 1244–1246, Juni 2024.

<br> [3] M. R. A. Fitra, A. A. S. Effendi, dan F. Ramadhani, "Implementasi Python dalam Pengolahan Data Pribadi Mahasiswa Ilmu Komputer Angkatan 23 pada Universitas Negeri Medan Menggunakan Struktur Data Linked List," JATI (Jurnal Mahasiswa Teknik Informatika), vol. 9, no. 1, hlm. 51–58, Februari 2025. 
 
