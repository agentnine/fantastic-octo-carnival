/* Kelompok    : CisituPlusNobel
/* File        : queue.c*/
/* Tanggal     : 29 Oktober 2018 */

/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmptyQueue(Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */ {
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFullQueue(Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */ {
    if (Head(Q) > Tail(Q)) {
        return (Head(Q) - Tail(Q) == 1);
    } else {
        return (Tail(Q) - Head(Q) + 1 == MaxEl(Q));
    }
}

int NBElmtQueue(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */ {
    if (IsEmptyQueue(Q) == true) {
        return (0);
    } else {
        if (Tail(Q) > Head(Q)) {
            return (Tail(Q) - Head(Q) + 1);
        } else {
            return (MaxEl(Q)-(Head(Q) - Tail(Q) - 1));
        }
    }
}

/* *** Kreator *** */
void CreateEmptyQueue(Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */ {
    (*Q).T = (infotype *) malloc((Max + 1) * sizeof (infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */ 
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void AddQueue(Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */ 
{

    //KAMUS LOKAL
    int i,j;
    char C;

    //ALGORITMA
    if (!(X.star)){
        if (IsEmptyQueue(*Q)) {
            Head(*Q) = 1;
        }
        Tail(*Q)++;
        if (Tail(*Q) > MaxEl(*Q)) {
            Tail(*Q) -= MaxEl(*Q);
        }
        InfoTail(*Q) = X;
    } else{
        if (IsEmptyQueue(*Q)) {
            Head(*Q) = 1;
        }
        Tail(*Q)++;
        if (Tail(*Q) > MaxEl(*Q)) {
            Tail(*Q) -= MaxEl(*Q);
        }
        i = Tail(*Q);
        while (i != Head(*Q)){
            j = i-1;
            if (j == 0){
                j = MaxEl(*Q);
            }
            (*Q).T[i] = (*Q).T[j];
            i=j;
        }
        InfoHead(*Q) = X;
    }
}

void DelQueue(Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */ {
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q)++;
        if (Head(*Q) > MaxEl(*Q)) {
            Head(*Q) -= MaxEl(*Q);
        }
    }
}

void DelEliQueue(Queue * Q, address i, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen urutan ke i pd I.S.,; 
        Q mungkin kosong */
{
    //KAMUS LOKAL
    boolean found;
    int j;

    //ALGORITMA
    found = true;
    *X = (*Q).T[i];
    while (i != Tail(*Q)) {
        j = i + 1;
        if (j > MaxEl(*Q)) {
            j = j - MaxEl(*Q);
        }
        (*Q).T[i] = (*Q).T[j];
        i = j;
    }
    Tail(*Q)--;
    if (Tail(*Q) < 1) {
        Tail(*Q) = MaxEl(*Q);
    }
}

void PrintQueue(Queue Q)
/* Poses : Menampilkan antrian hanya dalam representasi NbPeeoplenya saja*/
{
  //KAMUS LOKAL
  int i;

  //ALGORITMA
  if (!IsEmptyQueue(Q)){
    if (Tail(Q) >= Head(Q)){
      for (i=Head(Q); i<= Tail(Q); i++){
        if (Q.T[i].star){
            printf("*");
        }
        printf("%d\n", Cust(Q,i));
      }
    } else{
      i=Head(Q);
      while (i!=Tail(Q)){
        if (Q.T[i].star){
            printf("*");
        }
        printf("%d\n", Cust(Q,i));
        i++;
        if (i>MaxEl(Q)){
          i = i-MaxEl(Q);
        }
      }
    }
  }
}