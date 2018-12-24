/* Kelompok    : CisituPlusNobel
/* File        : function.h */
/* Tanggal     : 29 Oktober 2018 */

#include "datatype.h"
#include "point.h"
#include "jam.h"
#include "queue.h"
#include "stackf.h"
#include "stackt.h"
#include "array.h"
#include "boolean.h"
#include "room.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "pohonbiner.h"
#include "graph.h"

void Interface(char* name, ROOM R, LOC L, Queue Q, Stack Hand, StackFood Food, TabInt orders, JAM J, int life, int money);
/* Menulis Interface*/

void Go(ROOM *R, char C, LOC *L, Graph G);
/*  Procesure Go terdiri dari 4 perintah yaitu Go Up, Go Down, Go Left, Go Right */

void Place(Queue *Q, ROOM *R, LOC L, TabInt *tables);
/* Menempatkan pelangan dengan Top of Queue ke dalam meja yang kososng */

void Take(LOC L, Stack *S, TabInt kitchen);
/*Mengambil bahan makanan di dekat player */

void CAH(Stack *S);
/* Membuang semua bahan makanan yang ada di tangan */

void COH(Stack *S);
/* Membuang satu bahan makanan yang ada di tangan */

void CAT(StackFood *S);
/* Membuang semua makanan yang ada di nampan */

void COT(StackFood *S);
/* Membuang satu bahan makanan yang ada di nampan */

void Order(LOC L, TabInt *orders, TabInt *tables);
/* Mengambil order dari meja yang bersebelahan */

void AddRemove(TabInt *orders, Queue *Q, ROOM *R, int *life, TabInt *tables, int *Add, int *custs);
/*Menambah/mengurangi array order, antrian, array table jika waktu tunggu sudah habis
  serat melaukan penambahan waktu */

void Recipe(BinTree P);
/*Mencetak Resep yang digunakan pada Engi's Kitchen */

/*FUNGSI PEMBANTU AMBIL BAHAN MAKANAN */
boolean IsPlateExist(Stack S);
/* Mengembalikan true apabila pada Stack Hand sudah terdapat piring */

void SearchBranch(BinTree *P, Stack * StackIn, Stack * StackOut);
/*FUNGSI PEMBANTU PUT */

void Put(BinTree P, Stack *Bahan, StackFood *Food, LOC L, POINT N);
/* I.S P, Bahan, dan Food semuanya harus sudah terdefinisi */
/* Prosedur ini mengecek apakah urutan bahan dalam Stack sudah benar dari bawah ke atas */
/* Jika benar , F.S semua bahan berurutan yang sesuai dengan resep yang ada pada BinTree dihilangkan,*/
/* dan makanan jadi ditambahkan pada Stack Food */
/* Jika tidak ada urutan bahan yang benar, tidak merubah apa-apa pada stack bahan dan stack food*/

void Inisialisasi(LOC *L, int *custs, ROOM *R, POINT *N, JAM *J, int *Add, Queue *Q, Stack *Hand, StackFood *Food, TabInt *orders, TabInt *tables, TabInt *kitchen, StatusTable *emptyOrder, int *life, int *money, BinTree *Resep, Graph *G);
/*  Melakukan inisiaisasi state pada program bentuk setiap room yaitu ruangan dalam representasi matriks, 
    koordinat pemain, waktu pemain, antrian, stack of foods, stack of hand, arrayorders, arraytables, arraykitchen, dll */

void Give(LOC L, StackFood *Food, ROOM *R,TabInt *tables, TabInt *orders, int *money);
/*Memberikan makanan ke pengguna. Jika user sedang di sekitar meja dan pesanan sesuai maka
  pesanan akan diberikan dan uang akan bertambah*/

void LoadRoom (ROOM *R, TabInt *tables, TabInt *kitchen, POINT *N, StatusTable status, Graph *G);
/*Melakukan pembacaan yang berisi informasi mengenai bentuk ruangan untuk pertama kali
  Procedure ini akan dipanggil saat progra melakukan inisialisasi state*/

void SaveGame(char name[20], LOC L, int custs, POINT N, JAM J, int Add, Queue Q, Stack Hand, StackFood Food, TabInt orders, TabInt tables, TabInt kitchen, int life, int money, Graph G);
/* Menyimpan semua informasi state game pada file eksternal */

void LoadGame(char name[20], LOC *L, int *custs, ROOM *R, POINT *N, JAM *J, int *Add, Queue *Q, Stack *Hand, StackFood *Food, TabInt *orders, TabInt *tables, TabInt *kitchen, StatusTable *status, int *life, int *money, BinTree *Resep, Graph *G);
/*  Melakukan pembacaan state pada file dan melakukan load pada bentuk setiap room yaitu ruangan dalam representasi matriks, 
    koordinat pemain, waktu pemain, antrian, stack of foods, stack of hand, arrayorders, arraytables, arraykitchen, dll */