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