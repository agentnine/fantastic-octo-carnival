/* Kelompok    : CisituPlusNobel
/* File        : stackf.c*/
/* Tanggal     : 29 Oktober 2018 */

#include "../include/stackf.h"
#include <stdio.h>
#include <stdlib.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackFood (StackFood * S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
	Topf(*S) = Nilf;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackFood (StackFood S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	return(Topf(S) == Nilf);
}

boolean IsFullStackFood (StackFood S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	return(Topf(S) == MaxElStackFood);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Pushf (StackFood * S, infotypeStackFood X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	Topf(*S)++;
	InfoTopf(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Popf (StackFood * S, infotypeStackFood* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	*X = InfoTopf(*S);
	Topf(*S)--;
}

void PrintStackFood(StackFood S)
/*Menampilkan Stack di mulai dari paling Top of Stack sampai
  sampai ke paling bawah*/
{
  //KAMUS LOKAL
  int i;

  //ALGORITMA
  if (!IsEmptyStackFood(S)){
    for (i=Topf(S);i>=1;i--){
      printf("%s\n",bahan[S.T[i]]);
    }
  }
}

StackFood Reversef(StackFood S)
/*Membalikkan urutan Stack sehingga Top of Stack akan berada di posisi
  yang paling bawah dan Stack mungkin kosong*/
{
  //KAMUS LOKAL
  StackFood temp;
  infotypeStackFood X;

  //ALGORITMA
  CreateEmptyStackFood(&temp);
  while (!IsEmptyStackFood(S)){
    Popf(&S,&X);
    Pushf(&temp,X);
  }
  return temp;
}
