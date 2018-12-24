/* Kelompok    : CisituPlusNobel
/* File        : stackt.c*/
/* Tanggal     : 29 Oktober 2018 */

#include "../include/stackt.h"
#include <stdio.h>
#include <stdlib.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackt (Stack * S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
	Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackt (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	return(Top(S) == Nil);
}

boolean IsFullStackt (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	return(Top(S) == MaxElStackt);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotypeStackt X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	Top(*S)++;
	InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotypeStackt* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	*X = InfoTop(*S);
	Top(*S)--;
}

void PrintStackt(Stack S)
/*Menampilkan Stack di mulai dari paling Top of Stack sampai
  sampai ke paling bawah*/
{
  //KAMUS LOKAL
  int i;

  //ALGORITMA
  if (!IsEmptyStackt(S)){
    for (i=Top(S);i>=1;i--){
      printf("%s\n",bahan[S.T[i]]);
    }
  }
}

Stack Reverse(Stack S)
/**/
{
  //KAMUS LOKAL
  Stack temp;
  infotypeStackt X;

  //ALGORITMA
  CreateEmptyStackt(&temp);
  while (!IsEmptyStackt(S)){
    Pop(&S,&X);
    Push(&temp,X);
  }
  return temp;
}