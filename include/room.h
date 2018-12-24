/* Kelompok    : CisituPlusNobel
/* File        : room.h */
/* Tanggal     : 29 Oktober 2018 */

#include "datatype.h"
#include "point.h"
#include "jam.h"
#include "queue.h"
#include "stackt.h"
#include "array.h"
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "pohonbiner.h"

int Random(int awal, int akhir);
/*Fungs untuk mengembalikan nilai random. Didapat dari
  https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm*/

void MakeEmptyTable(ROOM *R, TabInt *tables, int table);
/*  Membuat meja menjadi kosong. Meja kosong ditandai dengan X. Procedure ini hanya merubah
    tampilan pada matriks saja.*/

void MakeFullTable(ROOM *R, TabInt *tables, int table, Customer X, int num);
/*  Membuat meja yang kapasitasnya 4 menjadi penuh. Meja penuh ditandai dengan C. Procedure 
    ini hanya merubah tampilan pada matriks saja.*/

void MakeKitchen(ROOM *R, TabInt kitchen, POINT N);
/*  Membuat bentuk denah kitchen. Setiap tempat bahan makanan ditandai dengan M dan nampan ditandai
    dengan T */

void CekKosong4(TabInt tables, int *table);
/*  Melakukan pengecekan apakah terdapat meja dengan kapasitas 4 yang kosong. Pengeekan masih
    dilakukan primitif karena hanya meihat isi matriksnya saja (X atau C). Jika terdapat meja
    dengan kapasitas 4 yang kosong, maka room dan table akan diisi dengan ruangan dan nomor meja
    ditemukannya meja kosong. Jika tidak room dan table akan diisi dengan -999 */

void CekKosong2(TabInt tables, int *table);
/*  Melakukan pengecekan apakah terdapat meja dengan kapasitas 2 yang kosong. Pengeekan masih
    dilakukan primitif karena hanya meihat isi matriksnya saja (X atau C). Jika terdapat meja
    dengan kapasitas 2 yang kosong, maka room dan table akan diisi dengan ruangan dan nomor meja
    ditemukannya meja kosong. Jika tidak room dan table akan diisi dengan -999 */

void CekSebelahan(LOC L,int *meja, TabInt tables);
/*  Melakukan oengecekan apakah koordinat player (P) bersebelahan dengan salah satu meja
    Jika bersebelahan maka meja akan diisi dengan nomor meja yang bersebelahan*/

void CekSebelahanDapur(TabInt kitchen, POINT P, int *X);
/*  Melakukan oengecekan apakah koordinat player (P) bersebelahan dengan salah satu meja
    Jika bersebelahan maka X akan diisi dengan isi dari meja yang bersebelahan*/
