/* Kelompok    : CisituPlusNobel
/* File        : room.c */
/* Tanggal     : 29 Oktober 2018 */

#include "../include/room.h"
#include <stdio.h>
#include <stdlib.h>

int Random(int awal, int akhir)
/*Fungs untuk mengembalikan nilai random. Didapat dari
  https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm*/
{
  //KAMUS LOKAL
  time_t t;
  int random;
  
  //ALGORITMA 
  /* Intializes random number generator */
  srand((unsigned) time(&t));
  akhir++;
  random = (rand() % (akhir-awal));
  return (awal + random);
}

static FILE * pita;

void MakeEmptyTable(ROOM *R, TabInt *tables, int table)
/*  Membuat meja menjadi kosong. Meja kosong ditandai dengan X. Procedure ini hanya merubah
    tampilan pada matriks saja.*/
{
  // KAMUS LOKAL
  int ruang;
  int x,y;

  //ALGORITMA
  table--;
  ruang = (table/4)+1;
  table++;
  x = Absis(ElmtArray(*tables,table).PTable);
  y = Ordinat(ElmtArray(*tables,table).PTable);

  if (ElmtArray(*tables,table).Kapasitas == 4){
    ElmtMATRIKS(Elm(*R,ruang),x,y+1) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),x,y-1) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),x+1,y) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),x-1,y) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),x,y) = no[table];
  } else{
    ElmtMATRIKS(Elm(*R,ruang),x,y+1) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),x,y-1) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),x,y) = no[table];
  }
  ElmtArray(*tables,table).IsKosong = true;
  ElmtArray(*tables,table).IsOrdered = false;
  ElmtArray(*tables,table).Pesanan = DataUndef;
  ElmtArray(*tables,table).WaitTime = DataUndef;
}

void MakeFullTable(ROOM *R, TabInt *tables, int table, Customer X, int num)
/*  Membuat meja yang kapasitasnya 4 menjadi penuh. Meja penuh ditandai dengan C. Procedure 
    ini hanya merubah tampilan pada matriks saja.*/
{
  // KAMUS LOKAL
  int ruang;
  int x,y;

  //ALGORITMA
  table--;
  ruang = (table/4)+1;
  table++;
  x = Absis(ElmtArray(*tables,table).PTable);
  y = Ordinat(ElmtArray(*tables,table).PTable);

  if (num == 4){
    ElmtMATRIKS(Elm(*R,ruang),x,y+1) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),x,y-1) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),x+1,y) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),x-1,y) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),x,y) = no[table];
  } else{
    if (ElmtArray(*tables,table).Kapasitas == 4){
      ElmtMATRIKS(Elm(*R,ruang),x,y+1) = 'C';
      ElmtMATRIKS(Elm(*R,ruang),x,y-1) = 'C';
      ElmtMATRIKS(Elm(*R,ruang),x+1,y) = 'X';
      ElmtMATRIKS(Elm(*R,ruang),x-1,y) = 'X';
      ElmtMATRIKS(Elm(*R,ruang),x,y) = no[table];
    } else{
      ElmtMATRIKS(Elm(*R,ruang),x,y+1) = 'C';
      ElmtMATRIKS(Elm(*R,ruang),x,y-1) = 'C';
      ElmtMATRIKS(Elm(*R,ruang),x,y) = no[table];
    }
  }
  ElmtArray(*tables,table).Pesanan = X.Pesanan;
  ElmtArray(*tables,table).WaitTime = Random(120,150);
  ElmtArray(*tables,table).IsKosong = false;
}

void MakeKitchen(ROOM *R, TabInt kitchen, POINT N)
/*  Membuat bentuk denah kitchen. Setiap tempat bahan makanan ditandai dengan M dan nampan ditandai
    dengan T */
{
  //KAMUS LOKAL
  int i,x,y;

  //ALGORITMA
  //printf("%d\n", NbElmtArray(kitchen));
  for (i=1; i<=NbElmtArray(kitchen); i++){
    x = Absis(ElmtArray(kitchen,i).PTable);
    y = Ordinat(ElmtArray(kitchen,i).PTable);
    ElmtMATRIKS(Elm(*R,4),x,y) = 'M';
  }
  ElmtMATRIKS(Elm(*R,4),Absis(N), Ordinat(N)) = 'T';
}

void CekKosong4(TabInt tables, int *table)
/*  Melakukan pengecekan apakah terdapat meja dengan kapasitas 4 yang kosong. Pengeekan masih
    dilakukan primitif karena hanya meihat isi matriksnya saja (X atau C). Jika terdapat meja
    dengan kapasitas 4 yang kosong, maka room dan table akan diisi dengan ruangan dan nomor meja
    ditemukannya meja kosong. Jika tidak room dan table akan diisi dengan -999 */
{
  //KAMUS LOKAL
  int i;
  boolean kosong;

  //ALGORITMA
  i=1;
  kosong = false;
  *table = -999;
  while (i<=12 && !kosong){
    if (ElmtArray(tables,i).IsKosong && ElmtArray(tables,i).Kapasitas == 4){
      kosong = true;
      *table = i;
    } else{
      i++;
    }
  }
}

void CekKosong2(TabInt tables, int *table)
/*  Melakukan pengecekan apakah terdapat meja dengan kapasitas 2 yang kosong. Pengeekan masih
    dilakukan primitif karena hanya meihat isi matriksnya saja (X atau C). Jika terdapat meja
    dengan kapasitas 2 yang kosong, maka room dan table akan diisi dengan ruangan dan nomor meja
    ditemukannya meja kosong. Jika tidak room dan table akan diisi dengan -999 */
{
  //KAMUS LOKAL
  int i;
  boolean kosong;

  //ALGORITMA
  i=1;
  while (i<=12 && !kosong){
    if (ElmtArray(tables,i).IsKosong && ElmtArray(tables,i).Kapasitas == 2){
      kosong = true;
      *table = i;
    } else{
      i++;
    }
  }
  i=1;
  while (i<=12 && !kosong){
    if (ElmtArray(tables,i).IsKosong && ElmtArray(tables,i).Kapasitas == 4){
      kosong = true;
      *table = i;
    } else{
      i++;
    }
  }
}

void CekSebelahan(LOC L,int *table, TabInt tables)
/*  Melakukan oengecekan apakah koordinat player (P) bersebelahan dengan salah satu meja
    Jika bersebelahan maka akan meja akan diisi dengan nomor meja yang bersebelahan*/
{
  //KAMUS LOKAL
  int x,y;
  int i;
  StatusTable T;

  //ALGORITMA
  *table = -999;
  i = ((Room(L)-1)*4)+1;
  while (i <= ((Room(L)-1)*4)+4 && *table==-999){
    T = ElmtArray(tables,i);
    x = Absis(T.PTable);
    y = Ordinat(T.PTable);
    if (Room(L) != 4){
      if (((Ordinat(Point(L)) == y) || (Ordinat(Point(L)) == y-1)) || (Ordinat(Point(L)) == y+1)){
        if (T.Kapasitas == 2){
          if (Absis(Point(L)) == (x+1) || Absis(Point(L)) == (x-1)){
            *table = i;
          }
        } else if (T.Kapasitas == 4){
          if (Ordinat(Point(L)) == y){
            if (Absis(Point(L)) == (x+2) || Absis(Point(L)) == (x-2)){
              *table = i;
            }
          } else if ((Ordinat(Point(L)) == y+1) || (Ordinat(Point(L)) == y-1)){
            if (Absis(Point(L)) == (x+1) || Absis(Point(L)) == (x-1)){
              *table = i;
            }
          }
        }
      } else if (Absis(Point(L)) == x){
        if (Ordinat(Point(L)) == y+2 || Ordinat(Point(L)) == y-2){
          *table = i;
        }
      }
    }
    i++;
  }
}

void CekSebelahanDapur(TabInt kitchen, POINT P, int *X)
/*  Melakukan oengecekan apakah koordinat player (P) bersebelahan dengan salah satu meja
    Jika bersebelahan maka X akan diisi dengan isi dari meja yang bersebelahan*/
{
  //KAMUS LOKAL
  int i;
  int x,y;
  //ALGORITMA
  i = 1;
  *X = -999;
  while ((*X == -999) && i<=NbElmtArray(kitchen)){
    x = Absis(ElmtArray(kitchen,i).PTable);
    y = Ordinat(ElmtArray(kitchen,i).PTable);
    if (Absis(P) == x){
      if (Ordinat(P) == y+1 || Ordinat(P) == y-1){
        *X = ElmtArray(kitchen,i).Isi;
      }
    } else if (Ordinat(P) == y){
      if (Absis(P) == x+1 || Absis(P) == x-1){
        *X = ElmtArray(kitchen,i).Isi;
      }
    }
    i++;
  }
}
