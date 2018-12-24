/* Kelompok    : CisituPlusNobel
/* File        : StackFood.h*/
/* Tanggal     : 29 Oktober 2018 */

/* File : StackFood.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef StackFood_H
#define StackFood_H

#include "boolean.h"
#include "datatype.h"

#define Nilf 0
#define MaxElStackFood 5
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef int infotypeStackFood;
typedef int addressf;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
	infotypeStackFood T[MaxElStackFood+1]; /* tabel penyimpan elemen */
	addressf TOPf;  /* alamat TOP: elemen puncak */
} StackFood;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Topf(S) (S).TOPf
#define InfoTopf(S) (S).T[(S).TOPf]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackFood (StackFood * S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackFood (StackFood S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStackFood (StackFood S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Pushf (StackFood * S, infotypeStackFood X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Popf (StackFood * S, infotypeStackFood * X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void PrintStackFood(StackFood S);
/*Menampilkan Stack di mulai dari paling Top of Stack sampai
  sampai ke paling bawah*/

StackFood Reversef(StackFood S);
/*Membalikkan urutan Stack sehingga Top of Stack akan berada di posisi
  yang paling bawah dan Stack mungkin kosong*/

#endif
