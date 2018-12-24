/* Kelompok    : CisituPlusNobel
/* File        : datatype.h */
/* Tanggal     : 29 Oktober 2018 */

#ifndef DATATYPE_H
#define DATATYPE_H 

#include "matriks.h"
#include "point.h"

/* DAFTAR TIPE BENTUKAN */

/*Customer adalah satu kelompok orang yang datang bersama*/
#define DataUndef -999

typedef struct{
    int NbPeople; //Jumlah orang dalam suatu kelompok
    int WaitTime; //Waktu menunggu di antrian
    int Pesanan;
    boolean star;
} Customer;

typedef struct{
    int NbTable; //Nomor meja, jika belum mendapat meja maka bernilai TableUndef
    int Kapasitas;
    int Pesanan;
    int WaitTime;
    int Isi;
    POINT PTable;
    boolean IsKosong;
    boolean IsOrdered;
} StatusTable;

#define RMax 4
typedef struct{
  MATRIKS Mem[RMax+1];
  POINT door1[RMax+1];
  POINT door2[RMax+1];
  int dest1[RMax+1];
  int dest2[RMax+1];
} ROOM;

#define Elm(R,i) (R).Mem[(i)]

typedef struct{
  POINT P;
  int room;
} LOC;

#define Point(L) (L).P
#define Room(L) (L).room

char bahan[25][20];

int harga[9];

char no[13];


#endif


