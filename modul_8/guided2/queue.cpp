
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
