/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 - Foundation of Algorithm
 *   Hari dan Tanggal    : Selasa, 12 Mei 2026
 *   Nama (NIM)          : Fayyadh Ramadhan (13224077)
 *   Nama File           : soal1.c
 *   Deskripsi           : 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node{
    int Nomor;
    struct Node *parent;
} Node;

Node *tambahNode(int tempInput, int N, int i, Node *familyNode[])
{
    Node *nodeBaru = (Node*)malloc(sizeof(Node));
    nodeBaru->Nomor = tempInput;
    if(i==0)
    {
        nodeBaru->parent = NULL;
    }
    else if(i<=2)
    {
        nodeBaru->parent = familyNode[0];
    }
    else if(i>2 && i<=4)
    {
        nodeBaru->parent = familyNode[1];
    }
    else if(i>4 && i<=6)
    {
        nodeBaru->parent = familyNode[2];
    }
    return nodeBaru;
}

int hitungLevel(int N)
{
    int tempPow=0, tempTotal=0;
    for(int i=0;i<N;i++)
    {
        tempPow = pow(2, i);
        tempTotal += tempPow;
        if(N-tempTotal <= 0)
        {
            return i;
        }
    }
}

int main()
{
    int N, i, tempInput, j, tempPangkat, jumlahLevel, lastIndeks=0;

    scanf("%d", &N);
    Node *familyNode[N];
    for(i=0;i<N;i++)
    {
        scanf(" %d", &tempInput);
        familyNode[i] = tambahNode(tempInput, N, i, familyNode); 
    }
    // printf("test %d %d %d", familyNode[0]->Nomor, familyNode[3]->Nomor, familyNode[6]->Nomor);

    jumlahLevel = hitungLevel(N);
    // printf("level %d", jumlahLevel);

    for(i=0;i<=jumlahLevel;i++)
    {
        printf("LEVEL %d:", i);
        if(i%2==0)
        {
            for(j=lastIndeks;j<lastIndeks+pow(2, i);j++)
            {
                printf(" %d",familyNode[j]->Nomor);
            }
            lastIndeks = j;
        }
        else if(i%2==1)
        {
            for(j=pow(2, i);j>=lastIndeks;j--)
            {
                printf(" %d",familyNode[j]->Nomor);
            }
            lastIndeks = pow(2, i)+1;
        }

        if(i!=jumlahLevel)
        {
            printf("\n");
        }
    }
}

// Referensi
// https://www.geeksforgeeks.org/c/power-function-c-cpp/
