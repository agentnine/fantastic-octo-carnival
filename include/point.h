/* Kelompok    : CisituPlusNobel
/* File        : point.h */
/* Tanggal     : 29 Oktober 2018 */

/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
       
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */
POINT PlusDelta (POINT P, int deltaX, int deltaY);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
void Geser (POINT *P, int deltaX, int deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
boolean EQP (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

#endif