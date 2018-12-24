//Graph berarah diimplementasi sebagai multilist
/* Kelompok    : CisituPlusNobel
/* File        : graph.h */
/* Tanggal     : 29 Oktober 2018 */

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "point.h"
#include "boolean.h"
#include "datatype.h"
//#include "listlinier.h"

#define NilGraph NULL

typedef struct tNodeGraph *adrNode;
typedef struct tSuccNode *adrSuccNode;
typedef struct tNodeGraph{
    int Id;
    int NPred;
    adrSuccNode Trail;
    adrNode Next;
} Node;
typedef struct tSuccNode{
    LOC asal;
    LOC tujuan;
    char key;
    adrNode Succ;
    adrSuccNode Next;
}SuccNode;

typedef struct{
    adrNode FirstG;
} Graph;

/*** Selektor ***/
#define FirstG(G) (G).FirstG
#define Id(Pn) (Pn)->Id
#define Asal(Pn) (Pn)->asal
#define Key(Pn) (Pn)->key
#define Tujuan(Pn) (Pn)->tujuan
#define NPred(Pn) (Pn)->NPred
#define Trail(Pn) (Pn)->Trail
#define Succ(Pn) (Pn)->Succ
#define Next(Pn) (Pn)->Next

/*** Konstruktor ***/
void CreateGraph (int X, Graph *G);
/*I.S. Sembarang
  F.S. Terbentuk graph*/

/*** Manajemen Memori List Simpul (Leader) ***/
adrNode AlokNode (int X);
/* Mengembalikan address hasil alokasi Simpul X. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,
dan Next(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */
void DealokNode (adrNode P);
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */

/*** Manajemen Memory List Successor (Trailer) ***/
adrSuccNode AlokSuccNode (adrNode Pn, LOC asal, LOC tujuan, char key);
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=Nil. Jika
alokasi gagal, mengembalikan Nil. */
void DealokSuccNode (adrSuccNode P);
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */

/*** Fungsi/Prosedur Lain ***/ 
adrNode SearchNode (Graph G, int X);
/*Mengembalikan address simpul dengan Id=X jika sudah ada pada Graph, 
  Nil jika belum*/
adrSuccNode SearchEdge (Graph G, int prec, int succ);
/*Mengembalikan address trailer dengan busur yang menyimpan info busur 
  (prec,succ) jika sudah ada pada graph, Nil jika belum*/
void InsertNode (Graph *G, int X, adrNode *Pn);
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G */
/* F.S. JIka alokasi berhasil, X menjadi elemen terakhir G */
/* Pn berisi address simpul X. */
/* Jika alokasi gagal G tetap, Pn berisi Nil */
void InsertEdge (Graph *G, int prec, int succ, LOC asal, LOC tujuan,char key);
/* Menambahkan busur dari prec menuju succ ke dalam G */
/* I.S. G, prec, succ terdefinisi */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur (prec,succ) ke G */
/* Jika simpul prec/succ belum ada pada G, tambahkan simpul tersebut dahulu */
/* Jika sudah ada busur (prec,succ) di G, maka G tetap */
void DeleteNode (Graph *G, int X);
/* Menghapus simpul X dari G */
/* I.S. G terdefinisi, X terdefinisi dan ada pada G, jumlah simpul pada G lebih dari 1 */
/* F.S. Simpul X dan semua busur yang terhubung ke X dihapus dari G */

void CreatePintu(Graph* G, LOC asal, LOC tujuan, char key);
/* Membuat graf yang mengubungkan dua pintu dan key yang menghubungkannya*/

void CariEdgePintu(Graph G, LOC asal, LOC *tujuan, char key);
/* Mencari edge graf yang asalnya sama dengan masukan*/
#endif