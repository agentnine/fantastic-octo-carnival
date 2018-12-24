/* Kelompok    : CisituPlusNobel
/* File        : array.c */
/* Tanggal     : 29 Oktober 2018 */

/* *** IMPLEMENTASI DARI HEADER *** */

#include "../include/array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  if (IsEmpty(T))
    return 0;
  else
    return(Neff(T));
}

int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return(IdxMax);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return(IdxMin);
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return(GetFirstIdx(T)+Neff(T)-1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
  return(Neff(T) == 0);
}

boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return(Neff(T) == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */


void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan new line */
{
  //KAMUS LOKAL
  IdxType i;

  //ALGORITMA
  if (!IsEmpty(T)){
    for (i=GetFirstIdx(T); i<=(GetLastIdx(T)); i++){
      if (ElmtArray(T,i).Pesanan != -999){
        printf("%s, %c\n", bahan[ElmtArray(T,i).Pesanan],no[ElmtArray(T,i).NbTable]);
      }
    }
  }
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  //KAMUS LOKAL
  int i;

  //ALGORITMA
  Neff(*Tout) = Neff(Tin);
  for(i=GetFirstIdx(Tin); i<=GetLastIdx(Tin); i++){
    ElmtArray(*Tout,i) = ElmtArray(Tin,i);
  }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElTypeArray X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  ElmtArray(*T,GetLastIdx(*T)+1) = X;
  Neff(*T)++;
}

void AddEli (TabInt * T, ElTypeArray X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
	//KAMUS LOKAL
	IdxType j;
	
	//ALGORITMA
  Neff(*T)++;
  for(j=GetLastIdx(*T); j>=i+1; j--){
    ElmtArray(*T,j) = ElmtArray(*T,j-1);
  }
  ElmtArray(*T,i) = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElTypeArray * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  *X = ElmtArray(*T,GetLastIdx(*T)); 
  Neff(*T)--;
}

void DelEli (TabInt * T, IdxType i, ElTypeArray * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	//KAMUS LOKAL
	IdxType j;
	
	//ALGORITMA
  *X = ElmtArray(*T,i);
  for(j=i; j<=GetLastIdx(*T)-1; j++){
    ElmtArray(*T,j) = ElmtArray(*T,j+1);
  }
  Neff(*T)--;
}

void UbahEli (TabInt * T, IdxType i, ElTypeArray X)
/* Proses : Mengubahh elemen ke-i tabel tanpa mengganggu elemen yang lain*/
{	
	//ALGORITMA
  ElmtArray((*T),i) = X;
}

