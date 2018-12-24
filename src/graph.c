/* Kelompok    : CisituPlusNobel
/* File        : graph.c */
/* Tanggal     : 29 Oktober 2018 */

//Graph berarah diimplementasi sebagai multilist

#include "../include/graph.h"
#include <stdio.h>
#include <stdlib.h>


/*** Konstruktor ***/
void CreateGraph (int X, Graph *G)
/*I.S. Sembarang
  F.S. Terbentuk graph dengan X sebagai First element dari graph*/
{
    FirstG(*G) = NilGraph;
    adrNode temp;
    InsertNode(G,X,&temp);
}

/*** Manajemen Memori List Simpul (Leader) ***/
adrNode AlokNode (int X)
/* Mengembalikan address hasil alokasi Simpul X. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,
dan Next(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */
{
    adrNode P;
    P = (adrNode) malloc(sizeof(Node));
    if (P!=NilGraph){
        Id(P)=X;
        NPred(P)=0;
        Trail(P)=NilGraph;
        Next(P)=NilGraph;
    }
    return P;
}
void DealokNode (adrNode P)
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
{
    free(P);
}

/*** Manajemen Memory List Successor (Trailer) ***/
adrSuccNode AlokSuccNode (adrNode Pn, LOC asal, LOC tujuan, char key)
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=Nil. Jika
alokasi gagal, mengembalikan Nil. */
{
    adrSuccNode Pt;
    Pt = (adrSuccNode) malloc(sizeof(SuccNode));
    if (Pt != NilGraph){
        Asal(Pt) = asal;
        Key(Pt) = key;
        Tujuan(Pt) = tujuan;
        Succ(Pt) = Pn;
        Next(Pt) = NilGraph;
    }
    return Pt;
}
void DealokSuccNode (adrSuccNode P)
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
{
    free(P);
}

/*** Fungsi/Prosedur Lain ***/ 
adrNode SearchNode (Graph G, int X)
/*Mengembalikan address simpul dengan Id=X jika sudah ada pada Graph, 
  Nil jika belum*/
{
    adrNode P = FirstG(G);
    while(P != NilGraph && Id(P) != X)
    {
        P = Next(P);
    }
    return P;
}
adrSuccNode SearchEdge (Graph G, int prec, int succ)
/*Mengembalikan address trailer dengan busur yang menyimpan info busur 
  (prec,succ) jika sudah ada pada graph, Nil jika belum*/
{
    adrNode PPrec = SearchNode(G,prec);
    adrNode PSucc = SearchNode(G,succ);
    if(PPrec != NilGraph && PSucc != NilGraph){
        adrSuccNode Pn = Trail(PPrec);
        while(Pn != NilGraph && Succ(Pn)!=PSucc)
        {
            Pn = Next(Pn);
        }
        return Pn;
    }else{
        return NilGraph;
}
}
void InsertNode (Graph *G, int X, adrNode *Pn)
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G */
/* F.S. JIka alokasi berhasil, X menjadi elemen terakhir G */
/* Pn berisi address simpul X. */
/* Jika alokasi gagal G tetap, Pn berisi Nil */
{
    adrNode prevP = NilGraph;
    *Pn = FirstG(*G);
    while(*Pn != NilGraph)
    {
        prevP = *Pn;
        *Pn = Next(*Pn);
    }
    *Pn = AlokNode(X);
    if(*Pn != NilGraph)
    {
        if(prevP == NilGraph)
        {
            FirstG(*G) = *Pn;
        }else{
            Next(prevP) = *Pn;
        }
}
}
void InsertEdge (Graph *G, int prec, int succ, LOC asal, LOC tujuan, char key)
/* Menambahkan busur dari prec menuju succ ke dalam G */
/* I.S. G, prec, succ terdefinisi */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur (prec,succ) ke G */
/* Jika simpul prec/succ belum ada pada G, tambahkan simpul tersebut dahulu */
/* Jika sudah ada busur (prec,succ) di G, maka G tetap */
{
    adrNode PPrec,PSucc;
    if(SearchNode(*G,prec) == NilGraph)
    {
        InsertNode(G,prec,&PPrec);
    }else{
        PPrec = SearchNode(*G,prec);
    }
    if(SearchNode(*G,succ) == NilGraph)
    {
        InsertNode(G,succ,&PSucc);
    }else{
        PSucc = SearchNode(*G,succ);
    }
    if(SearchEdge(*G,Id(PPrec),Id(PSucc)) == NilGraph)
    {
        adrSuccNode prevPn = NilGraph;
        adrSuccNode Pn = Trail(PPrec);
        while(Pn != NilGraph)
        {
            prevPn = Pn;
            Pn = Next(Pn);
        }
        if(prevPn == NilGraph)
        {
            Trail(PPrec) = AlokSuccNode(PSucc,asal,tujuan,key);
        }else{
            Next(prevPn) = AlokSuccNode(PSucc,asal,tujuan,key);
        }
        NPred(PSucc) += 1;
    }
}

void CreatePintu(Graph* G, LOC asal, LOC tujuan, char key)
/*Membuat graf yang mengubungkan dua pintu dan key yang menghubungkannya*/
{
    InsertEdge(G,Room(asal),Room(tujuan),asal,tujuan, key);
}

void CariEdgePintu(Graph G,LOC asal, LOC *tujuan, char key)
/* Mencari edge graf yang asalnya sama dengan masukan*/
{
    adrNode roomA = SearchNode(G,Room(asal));
    adrSuccNode Pn = Trail(roomA);
    boolean ketemu = false;
    Room(*tujuan) = DataUndef;
    Point(*tujuan) = MakePOINT(-1,-1);
    while(Pn != NilGraph && !ketemu)
    {
        if(EQP(Point(Asal(Pn)),Point(asal)) && (Key(Pn) == key))
        {
            ketemu = true;
            Room(*tujuan) = Id(Succ(Pn));
            Point(*tujuan) = MakePOINT(Absis(Point(Tujuan(Pn))),Ordinat(Point(Tujuan(Pn))));
        }else{
            Pn = Next(Pn);
        }
    }
    
}