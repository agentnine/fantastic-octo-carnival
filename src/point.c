/* Kelompok    : CisituPlusNobel
/* File        : point.c */
/* Tanggal     : 29 Oktober 2018 */

#include "../include/point.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	//KAMUS LOKAL
	POINT P;
	//ALGORITMA
	Absis(P) = X;
	Ordinat(P) = Y;
	return(P);
}

POINT PlusDelta (POINT P, int deltaX, int deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
	Absis(P) += deltaX;
	Ordinat(P) += deltaY;
	return(P);
}

void Geser (POINT *P, int deltaX, int deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
	Absis(*P) += deltaX;
	Ordinat(*P) += deltaY;
}

boolean EQP (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}