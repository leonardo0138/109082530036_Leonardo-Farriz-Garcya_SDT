# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Pertama)</h1> 

<p align="center">Leonardo Farriz Garcya - 109082530036</p>

# Dasar Teori
#### A. Konsep Dasar Doubly Linked List<br/>

Doubly linked list merupakan pengembangan dari singly linked list yang setiap elemennya memiliki dua penunjuk, sehingga list dapat ditelusuri ke dua arah.

#### 1. Pengertian dan Struktur Elemen

Doubly linked list adalah struktur data yang tersusun dari elemen-elemen yang saling terhubung melalui dua pointer, yaitu prev yang menunjuk ke elemen sebelumnya dan next yang menunjuk ke elemen sesudahnya. Karena setiap elemen menyimpan alamat kedua tetangganya, penelusuran list dapat dilakukan maju maupun mundur [1]. Pada implementasi C++, elemen didefinisikan dengan struct elmlist yang berisi field info, next, dan prev.

#### 2. Komponen List

List dikelola melalui dua pointer utama, yaitu first yang menunjuk ke elemen pertama dan last yang menunjuk ke elemen terakhir. Elemen pertama memiliki prev bernilai Nil, sedangkan elemen terakhir memiliki next bernilai Nil, dan list dinyatakan kosong jika L.first bernilai Nil. Adanya pointer last membuat penambahan elemen di akhir list tidak perlu menelusuri list dari awal.

#### 3. Kelebihan dan Konsekuensi

Dibandingkan singly linked list, doubly linked list lebih fleksibel dalam penyisipan dan penghapusan karena akses dua arah memungkinkan sebuah elemen dihapus hanya dengan mengetahui pointer ke elemen tersebut, tanpa menelusuri list dari awal [2]. Perpindahan ke elemen sebelum atau sesudahnya juga berlangsung dalam waktu konstan, dan penghapusan elemen di tengah tidak memerlukan pergeseran elemen lain seperti pada array [3]. Konsekuensinya, setiap elemen membutuhkan memori tambahan untuk pointer prev dan setiap perubahan list harus memperbarui dua tautan sekaligus [2].

#### B. Operasi Insert dan Delete pada Doubly Linked List<br/>

Setiap operasi insert diawali dengan mengalokasikan elemen baru melalui P = alokasi(X) dengan next dan prev bernilai Nil, sedangkan operasi delete diakhiri dengan memutus pointer elemen yang dilepas lalu mengembalikannya atau men-dealokasikannya.

#### 1. Insert First dan Insert Last

Pada insert first, elemen baru dikaitkan ke elemen pertama lewat P→next = L.first, elemen pertama lama dikaitkan balik lewat (L.first)→prev = P, lalu L.first dipindahkan ke P. Insert last bekerja simetris, yaitu P→prev = L.last, (L.last)→next = P, dan L.last = P. Pada kedua operasi, pointer ujung list berpindah ke elemen baru [2]. Jika list masih kosong, tidak ada elemen lama yang perlu dikaitkan, sehingga first dan last langsung diarahkan ke elemen baru.

#### 2. Insert After dan Insert Before

Insert after menyisipkan elemen P setelah elemen acuan R dengan empat langkah, yaitu P→next = R→next, P→prev = R, (R→next)→prev = P, kemudian R→next = P. Urutan langkah ini penting agar elemen setelah R tidak kehilangan tautannya sebelum dikaitkan ke P. Insert before merupakan kebalikan dari insert after, dan perbedaannya hanya terletak pada cara mencari elemen acuan [2].

#### 3. Delete First dan Delete Last

Delete first dilakukan dengan menyimpan elemen pertama ke P, memajukan L.first ke elemen berikutnya, lalu memutus P→next dan (L.first)→prev. Delete last dilakukan dengan menyimpan elemen terakhir ke P, memundurkan L.last ke elemen sebelumnya, lalu memutus P→prev dan (L.last)→next. Apabila list hanya memiliki satu elemen, first dan last diubah menjadi Nil [2].

#### 4. Delete After dan Delete Before

Pada delete after, elemen sebelum dan sesudah P disambungkan langsung lewat R→next = P→next dan (P→next)→prev = R, kemudian pointer P diputus dan elemennya di-dealokasikan. Dengan cara ini penghapusan elemen di tengah list hanya membutuhkan penyesuaian pointer next dan prev tanpa penelusuran panjang [2]. Delete before adalah kebalikan dari delete after, dengan perbedaan pada pencarian elemennya.

#### C. Operasi Pendukung dan ADT Doubly Linked List dalam C++<br/>

#### 1. Searching, Update, dan View

Proses searching, update, dan view pada dasarnya sama dengan singly linked list. Perbedaannya, penelusuran dapat dimulai dari first untuk bergerak maju atau dari last untuk bergerak mundur [2]. Fungsi findElm() mengembalikan alamat elemen yang nilai info-nya sesuai atau Nil jika tidak ditemukan, dan hasilnya menjadi acuan bagi operasi seperti insert after dan delete after.

#### 2. ADT Doubly Linked List

ADT doubly linked list didefinisikan pada file header Doublylist.h yang memuat tipe infotype, address sebagai pointer ke elmlist, struct elmlist (info, prev, next), struct list (first, last), serta prototipe fungsi primitif. Primitif yang digunakan pada praktikum ini meliputi CreateList(), alokasi(), dealokasi(), printInfo(), insertLast(), findElm(), deleteFirst(), deleteLast(), dan deleteAfter(). Implementasinya ditulis pada Doublylist.cpp dan diuji melalui main.cpp, dengan infotype berupa data kendaraan yang terdiri dari nopol, warna, dan thnBuat.



```

## Guided

### 1. 

## listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include <iostream>
using namespace std;

struct makanan
{
    string nama;
    string jenis;
    float harga;
    float rating;
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node
{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist
{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif

```

## listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List)
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

void createList(linkedlist &List)
{
    List.first = Nil;
    List.last = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis;
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating = rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodePrev != Nil)
        {
            if (nodePrev == List.last)
            {
                insertLast(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodeNext != Nil)
        {
            if (nodeNext == List.first)
            {
                insertFirst(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl;
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); // menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); // menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); // menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodeNext != Nil && nodeNext->prev != Nil)
        {
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); // menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.nama == nama)
        {
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.jenis == jenis)
        {
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.rating >= minRating)
        {
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if (List.first == List.last)
    {
        List.first = List.last = Nil;
    }
    else
    {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if (List.first == List.last)
    {
        List.first = List.last = Nil;
    }
    else
    {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (Prev == Nil || Prev->next == Nil)
    {
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if (Prev->next == List.last)
    {
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (nodeNext == Nil || nodeNext->prev == Nil)
    {
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if (nodeNext->prev == List.first)
    {
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target)
{
    if (isEmpty(List) == true || target == Nil)
    {
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if (target == List.first)
    {
        deleteFirst(List);
    }
    else if (target == List.last)
    {
        deleteLast(List);
    }
    else
    {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama)
{
    if (isEmpty(List))
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while (target != Nil && target->isidata.nama != nama)
    {
        target = target->next;
    }
    if (target == Nil)
    {
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}

```
## main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    // D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");
    findByMinRating(List, 9.0);

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl
         << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```

<p>Program ini membuat doubly linked list untuk menyimpan data makanan, dan kodenya dibagi menjadi tiga file: `listMakanan.h`, `listMakanan.cpp`, dan `main.cpp`. Di `listMakanan.h` terdapat `struct makanan` yang berisi atribut `nama`, `jenis`, `harga`, dan `rating`. Data tersebut disimpan di dalam `struct node` bersama pointer `next` yang menunjuk ke node berikutnya dan `prev` yang menunjuk ke node sebelumnya. Karena memiliki dua pointer penghubung, list ini termasuk doubly linked list. `struct linkedlist` memiliki `first` sebagai penunjuk node pertama dan `last` sebagai penunjuk node terakhir, sedangkan `address` merupakan alias untuk pointer ke `node` dan `Nil` digunakan sebagai penanda pointer kosong (`NULL`). Header ini juga memuat deklarasi fungsi dasar, operasi insert, print, update, searching, dan delete.</p>

<p>Di `listMakanan.cpp`, fungsi `createList()` menginisialisasi `first` dan `last` menjadi `Nil`, `isEmpty()` mengecek apakah list kosong melalui `first`, `alokasi()` membuat node baru menggunakan `new` dan mengisi data makanan, sedangkan `dealokasi()` menghapus node dari memori. Untuk menambahkan data tersedia `insertFirst()` (di awal), `insertLast()` (di akhir), `insertAfter()` (setelah node tertentu), dan `insertBefore()` (sebelum node tertentu). Karena list memiliki pointer `first` dan `last`, penambahan di awal maupun akhir dapat dilakukan tanpa menelusuri seluruh node. Pada penyisipan di tengah, pointer `next` dan `prev` dari node baru serta node di sekitarnya harus disesuaikan agar hubungan list tetap terhubung. Lalu `printList()` menelusuri list mulai dari `first` sampai `Nil` dan menampilkan nama, jenis, harga, serta rating setiap makanan.</p>

<p>Bagian update digunakan untuk mengubah data makanan yang sudah ada. `updateFirst()` mengubah data pada node pertama, `updateLast()` mengubah node terakhir, `updateAfter()` mengubah node setelah `nodePrev`, dan `updateBefore()` mengubah node sebelum `nodeNext`. Input nama dan jenis menggunakan `getline()` agar dapat menerima lebih dari satu kata, sedangkan `cin.ignore()` digunakan untuk membuang karakter newline setelah input angka. Bagian searching terdiri dari `findByName()` untuk mencari berdasarkan nama, `findByJenis()` berdasarkan jenis, dan `findByMinRating()` berdasarkan rating minimal. Ketiganya menelusuri list dari depan, tetapi hanya menampilkan data pertama yang cocok karena menggunakan `return` setelah data ditemukan. Pada bagian delete, `deleteFirst()` dan `deleteLast()` menghapus node di awal atau akhir, `deleteAfter()` dan `deleteBefore()` menghapus node berdasarkan posisi relatif, `deleteNode()` menghapus node berdasarkan alamat, sedangkan `deleteByName()` mencari node berdasarkan nama lalu menghapusnya melalui `deleteNode()`. Setiap node yang dihapus kemudian di-dealokasi agar memorinya dikembalikan ke sistem. Namun, alamat pointer node yang sudah dihapus tidak boleh digunakan kembali, dan beberapa prosedur posisi mengasumsikan alamat node yang diberikan memang berasal dari list tersebut.</p>

<p>Di `main()`, dibuat sebuah list kosong dan lima node (`nodeA` sampai `nodeE`) yang berisi Nasi Rames, Ayam Geprek, Risol Mayo, Mie Ayam, dan Donat. Node dimasukkan dengan urutan `insertFirst(D)`, `insertLast(E)`, `insertAfter(A, D)`, `insertBefore(C, E)`, dan `insertLast(B)`, sehingga urutan awal list menjadi D - A - C - E - B, yaitu Mie Ayam, Nasi Rames, Risol Mayo, Donat, dan Ayam Geprek. Setelah isi list ditampilkan, program menjalankan `updateFirst()`, `updateLast()`, `updateBefore(List, nodeC)`, dan `updateAfter(List, nodeA)`. Artinya, data yang diubah berturut-turut adalah node D, B, A, dan C, sedangkan node E tidak diubah. Program kemudian mencari nama `"Nasgor"` dan makanan dengan rating minimal 9,0. Terakhir, `deleteByName(List, "Nasgor")` menghapus node bernama Nasgor jika ditemukan, `deleteFirst()` menghapus node yang saat itu berada di awal list, dan `deleteBefore(List, nodeE)` menghapus node yang berada tepat sebelum node E jika node sebelumnya masih ada. Karena data hasil update bergantung pada input pengguna, hasil searching dan urutan akhir list juga bergantung pada data yang dimasukkan. Program lalu menampilkan isi list setelah penghapusan dan berakhir dengan `return 0`.</p>

## Unguided

### soal1.

## doublyList.h
```C++
  #ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

address findElm(List L, infotype x);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif

```
## doublyList.cpp
```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {          
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        (L.Last)->next = P;
        L.Last = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P == Nil) return;
    if (L.First == L.Last) {      
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = (L.First)->next;
        (L.First)->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (P == Nil) return;
    if (L.First == L.Last) {       
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = (L.Last)->prev;
        (L.Last)->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    if (P == Nil) return;
    Prec->next = P->next;
    (P->next)->prev = Prec;
    P->prev = Nil;
    P->next = Nil;
}

```
## main.cpp
```C++
#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    for (int i = 0; i < 4; i++) {
        infotype x;
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);
    cout << endl;

    infotype cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari.nopol;
    address P = findElm(L, cari);
    if (P != Nil) {
        cout << endl;
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
    cout << endl;

    infotype hapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapus.nopol;
    address Q = findElm(L, hapus);
    if (Q == Nil) {
        cout << "Data dengan nomor polisi " << hapus.nopol << " tidak ditemukan." << endl;
    } else {
        address del;
        if (Q == L.First) {
            deleteFirst(L, del);
        } else if (Q == L.Last) {
            deleteLast(L, del);
        } else {
            deleteAfter(Q->prev, del);
        }
        dealokasi(del);
        cout << "Data dengan nomor polisi " << hapus.nopol << " berhasil dihapus." << endl;
    }
    cout << endl << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}

```

### Output Unguided 1 :
<img src = "" >
 
<p>Doubly Linked List merupakan struktur data berupa kumpulan node yang saling terhubung menggunakan dua pointer, yaitu next untuk menunjuk node berikutnya dan prev untuk menunjuk node sebelumnya. Pada file doublyList.h, terdapat struktur kendaraan yang menyimpan informasi berupa nopol, warna, dan thnBuat, kemudian didefinisikan sebagai infotype. Tipe address digunakan sebagai pointer yang menunjuk ke elemen ElmList, sedangkan ElmList memiliki tiga bagian, yaitu info untuk menyimpan data kendaraan, next untuk menunjuk elemen selanjutnya, dan prev untuk menunjuk elemen sebelumnya. Selanjutnya, struktur List memiliki First sebagai penunjuk elemen pertama dan Last sebagai penunjuk elemen terakhir. File header juga berisi deklarasi fungsi yang digunakan untuk membuat list, mengalokasikan dan menghapus memori, menampilkan data, mencari elemen, serta melakukan operasi penyisipan dan penghapusan elemen.</p>

<p>Pada file doublyList.cpp, fungsi CreateList digunakan untuk menginisialisasi list dalam keadaan kosong dengan mengatur First dan Last menjadi Nil. Fungsi alokasi digunakan untuk membuat node baru menggunakan new ElmList, kemudian mengisi bagian info dengan data kendaraan dan mengatur pointer next serta prev menjadi Nil. Fungsi dealokasi digunakan untuk menghapus node dari memori menggunakan delete, kemudian mengatur pointer menjadi Nil. Fungsi insertLast digunakan untuk menambahkan elemen baru pada posisi terakhir. Jika list masih kosong, node baru akan menjadi First sekaligus Last. Namun, jika list sudah memiliki elemen, pointer prev dari node baru diarahkan ke Last sebelumnya, kemudian pointer next dari elemen terakhir diarahkan ke node baru dan Last diperbarui. Fungsi printInfo digunakan untuk menampilkan seluruh data kendaraan dengan memulai traversal dari Last dan bergerak menggunakan pointer prev, sehingga data ditampilkan dari elemen terakhir menuju elemen pertama.</p>

<p>Fungsi findElm digunakan untuk mencari data kendaraan berdasarkan nomor polisi (nopol) dengan melakukan traversal mulai dari First menggunakan pointer next. Jika nomor polisi ditemukan, fungsi mengembalikan alamat node tersebut, sedangkan jika tidak ditemukan akan mengembalikan Nil. Untuk proses penghapusan, terdapat tiga fungsi, yaitu deleteFirst untuk menghapus elemen pertama, deleteLast untuk menghapus elemen terakhir, dan deleteAfter untuk menghapus elemen setelah node tertentu. Ketiganya memperbarui hubungan pointer agar elemen yang tersisa tetap terhubung dengan benar. Pada kondisi list hanya memiliki satu elemen, penghapusan akan membuat First dan Last kembali menjadi Nil. Perlu diperhatikan bahwa deleteAfter mengasumsikan node yang dihapus masih memiliki elemen setelahnya, karena kode (P->next)->prev = Prec akan mengalami kesalahan jika P->next bernilai Nil. Pada program ini, kondisi tersebut dihindari karena penghapusan elemen terakhir sudah ditangani oleh deleteLast.</p>

<p>Pada file main.cpp, program diawali dengan membuat variabel List L dan memanggil CreateList(L) untuk menginisialisasi list. Selanjutnya, dilakukan perulangan sebanyak empat kali untuk memasukkan data kendaraan berupa nomor polisi, warna, dan tahun pembuatan. Sebelum data dimasukkan, fungsi findElm digunakan untuk memeriksa apakah nomor polisi sudah terdaftar. Jika ditemukan, program menampilkan pesan bahwa nomor polisi sudah terdaftar, sedangkan jika belum ditemukan, data akan dialokasikan menggunakan alokasi dan dimasukkan ke bagian akhir list menggunakan insertLast. Setelah proses input selesai, fungsi printInfo dipanggil untuk menampilkan seluruh data kendaraan. Program kemudian meminta nomor polisi yang ingin dicari dan menggunakan findElm untuk menampilkan informasi kendaraan jika data ditemukan. Selanjutnya, pengguna memasukkan nomor polisi yang ingin dihapus. Program kembali menggunakan findElm untuk mendapatkan alamat node yang akan dihapus, kemudian menentukan fungsi penghapusan berdasarkan posisi node, yaitu deleteFirst jika berada di awal, deleteLast jika berada di akhir, atau deleteAfter jika berada di tengah. Setelah node dilepaskan dari hubungan list, fungsi dealokasi dipanggil untuk membebaskan memori node tersebut. Terakhir, printInfo dipanggil kembali untuk menampilkan kondisi list setelah proses penghapusan selesai.</p>

## Kesimpulan
<p>Jadi Doubly Linked List merupakan pengembangan dari Singly Linked List yang memiliki dua pointer, yaitu `next` dan `prev`, sehingga proses penelusuran data dapat dilakukan dari dua arah. Melalui praktikum ini, saya juga mempelajari bagaimana mengelola data menggunakan berbagai operasi, mulai dari menambahkan, mencari, memperbarui, hingga menghapus node berdasarkan posisi atau data tertentu. Setiap operasi membutuhkan pengaturan pointer yang tepat agar hubungan antar-node tetap terjaga dan tidak menyebabkan kesalahan pada list. Selain itu, penggunaan `new` dan `delete` membantu memahami bagaimana alokasi dan dealokasi memori dilakukan pada struktur data dinamis. Dari praktikum ini, saya menjadi lebih memahami cara kerja Doubly Linked List serta perbedaannya dengan Singly Linked List, terutama dari segi fleksibilitas dalam mengakses dan mengelola data.</p>

## Referensi

<br> [1] R. D. Setiyawan, D. Hermawan, A. F. Abdillah, A. Mujayanah, dan R. Vindua, "Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List," Jutech (Jurnal Teknologi), Universitas Pamulang, vol. 5, no. 2, hlm. 484–498, Desember 2024.

<br> [2] A. Wijoyo, A. Farhan, L. A. Prayudi, M. Fiqih, R. D. Santoso, R. T. S. Putra, dan T. Arifin, "Penggunaan Algoritma Doubly Linked List untuk Insertion dan Deletion," JRIIN (Jurnal Riset Informatika dan Inovasi), vol. 1, no. 12, hlm. 1329–1331, Mei 2024.

<br> [3] T. R. Y. Saketang, G. R. Pandiangan, F. A. Matondang, dan R. I. Situmorang, "Implementasi Struktur Data Stack pada Sistem Recently Played Music Streaming Berbasis Prinsip LIFO," JPIM (Jurnal Penelitian Ilmiah Multidisipliner), Universitas Negeri Medan, vol. 2, no. 3, hlm. 1192–1197, 2025.
