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