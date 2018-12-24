//NIM/Nama : 13513017/miftahul mahfuzh
//Nama file : pohonbiner.h
//Topik : Pohon Biner 
//Tanggal : 27 November 2014
//Deskripsi : Pohon Biner dengan list

/**********************ADT Pohon Biner*******************/

#ifndef pohonbiner_h
#define pohonbiner_h
#include <stdio.h>
#include <stdlib.h>
#include "mesinkar.h"
#include "boolean.h"
#include "datatype.h"

#define NilTree NULL

/*** Definisi Type Pohon Biner ***/
typedef struct tNode *paddress;
typedef struct tNode {
	int Info;
	paddress Left;
	paddress Right;
} node;
typedef paddress BinTree;

/*** Definisi Type List of Node ***/
//typedef List ListOfNode;

/*** Selektor ***/
#define Akar(P) (P)->Info
//Mengirimkan nilai Akar pohon biner P
#define Left(P) (P)->Left
//Mengirimkan Anak Kiri pohon biner P
#define Right(P) (P)->Right
//Mengirimkan Anak Kanan pohon biner P

/*** Konstruktor ***/
void Allocate (paddress *P);
/* I.S. sembarang */
/* F.S. mengalokasi P, menghasilkan Nil jika gagal */
BinTree Tree (int A, BinTree L, BinTree R);
//Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil
//Menghasilkan pohon kosong (Nil) jika alokasi gagal

void MakeTree (int Akar, BinTree L, BinTree R, BinTree *P);
//I.S. Sembarang 
//F.S. Menghasilkan sebuah pohon P 
//Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil 
//Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal 

void LoadTree(BinTree *P);
/* Membaca Kode Resep yang ada pada file eksternal */

void BuildTree (BinTree *P);
//Membentuk sebuah pohon biner P dari pita karakter yang dibaca }
//I.S. Pita berisi "konstanta" pohon dalam bentuk prefix.
//Memori pasti cukup, alokasi pasti berhasil. }
//F.S. P dibentuk dari ekspresi dalam pita }

/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (BinTree P);
//Mengirimkan true jika P adalah pohon biner kosong

boolean IsOneElmt (BinTree P);
//Mengirimkan true jika P adalah pohon biner tidak kosong dan
//hanya memiliki 1 elemen

boolean IsUnerLeft (BinTree P);
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon unerleft: hanya mempunyai subpohon kiri

boolean IsUnerRight (BinTree P);
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon unerright: hanya mempunyai subpohon kanan

boolean IsBiner (BinTree P);
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon biner: mempunyai subpohon kiri dan subpohon kanan

/*** Traversal ***/
void PrintPreorder (BinTree P);
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().

void PrintInorder (BinTree P);
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().

void PrintPostorder (BinTree P);
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan
//akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
void ShowBranch (BinTree P);
/*Menunjukkan cabang resep yang tersedia */
void PrintBranch(int h, int * ArrSlash);
/* Fungsi Pembantu PrintTree() */
/* Menunjukkan alur dari semua cabang pohon biner */
void PrintTree (BinTree P, int dh, int hc, int * ArrSlash);
//I.S. P terdefinisi, h adalah jarak indentasi
//F.S. Semua simpul P sudah ditulis dengan indentasi
/*** Searching ***/
BinTree SearchPBCode (BinTree P, int X);
/* Mencari dan mengembalikan nilai alamat akar tempat X ditemukan dalam P */

BinTree isNextRoot (BinTree P, int X);
/* Mengecek apakah X adalah anak akar dari BinTree P */

boolean SearchPB (BinTree P, int X);
//Mengirimkan true jika ada node dari P yang bernilai X

/*** Fungsi-Fungsi Lain ***/
int NbElmtPB (BinTree P);
//Mengirimkan banyaknya elemen (node) pohon biner P

int NbDaun (BinTree P);
//Mengirimkan banyaknya daun (node) pohon biner P

boolean IsSkewLeft (BinTree P);
//Mengirimkan true jika P adalah pohon condong kiri 

boolean IsSkewRight (BinTree P);
//Mengirimkan true jika P adalah pohon condong kiri

int Level (BinTree P, int X);
//Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner
//P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }

/*** Operasi lain ***/
void AddDaunTerkiri (BinTree *P, int X);
//I.S. P boleh kosong 
//F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri

void AddDaun (BinTree *P, int X, int Y, boolean Kiri);
//I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P 
//F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
//sebagai anak Kanan X (jika Kiri = false) 

void DelDaunTerkiri (BinTree *P, int *X);
//I.S. P tidak kosong 
//F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
//disimpan pada daun terkiri yang dihapus 

void DelDaun (BinTree *P, int X);
//I.S. P tidak kosong, X adalah salah satu daun 
//F.S. Semua daun bernilai X dihapus dari P 

/*** Balanced tree ***/
BinTree BuildBalanceTree (int n);
//Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca

/*** Binary Search Tree ***/
boolean BSearch (BinTree P, int X);
//Mengirimkan true jika ada node dari P yang bernilai X

BinTree InsSearch (BinTree P, int X);
//Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum
//ada simpul P yang bernilai X.

void DelBtree (BinTree *P, int X);
//I.S. Pohon P tidak kosong 
//F.S. Nilai X yang dihapus pasti ada 
//Sebuah node dengan nilai X dihapus 

void DelNode (BinTree *P);

#endif
