/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 - Foundation of Algorithm
 *   Hari dan Tanggal    : Selasa, 12 Mei 2026
 *   Nama (NIM)          : Fayyadh Ramadhan (13224077)
 *   Nama File           : soal2.c
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

int pangkat(int eksponen)
{
    int jumlah=1, i=0;
    
    if(eksponen==0)
    {
        return 1;
    }
    else
    {
        while(i<eksponen)
        {
            jumlah*=2;
            i+=1;
        }
        return jumlah;
    }
}

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
    else if(i>6 && i<=8)
    {
        nodeBaru->parent = familyNode[3];
    }
    else if(i>8 && i<=10)
    {
        nodeBaru->parent = familyNode[4];
    }
    return nodeBaru;
}

int hitungLevel(int N)
{
    int tempPow=0, tempTotal=0;
    for(int i=0;i<N;i++)
    {
        tempPow = pangkat(i);
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
        printf("\nLEVEL %d:", i);
        if(i%2==0)
        {
            for(j=lastIndeks;j<lastIndeks+pangkat(i);j++)
            {
                if(j>=N)
                {
                    return 0;
                }
                printf(" %d",familyNode[j]->Nomor);
            }
            // printf("jjj %d", j);
            lastIndeks = j;
        }
        else if(i%2==1)
        {
            if(pangkat(i)<N)
            {
                for(j=pangkat(i);j>=lastIndeks;j--)
                {
                    printf(" %d",familyNode[j]->Nomor);
                }
                lastIndeks = pangkat(i)+1;
            }
            else if(pangkat(i)>=N)
            {
                for(j=N-1;j>=lastIndeks;j--)
                {
                    // printf("jjj %d", j);
                    printf(" %d",familyNode[j]->Nomor);
                }
                return 0;
            }
        }

        // if(i!=jumlahLevel)
        // {
        //     printf("\n");
        // }
    }

    return 0;
}

// Referensi
// https://www.geeksforgeeks.org/c/power-function-c-cpp/