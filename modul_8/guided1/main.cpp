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