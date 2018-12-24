/* Kelompok    : CisituPlusNobel
/* File        : jam.c */
/* Tanggal     : 29 Oktober 2018 */

/* *** IMPLEMENTASI DARI HEADER *** */

#include "../include/boolean.h"
#include "../include/jam.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

{
   // KAMUS LOKAL
   JAM J;
   // ALGORIMA
   Hour(J) = HH;
   Minute(J) = MM;
   Second(J) = SS;
   return(J);
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */

void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
  if (Hour(J)<10) printf("0%d:",Hour(J));
  else printf("%d:",Hour(J));
  if (Minute(J)<10) printf("0%d:",Minute(J));
  else printf("%d:",Minute(J));
  if (Second(J)<10) printf("0%d",Second(J));
  else printf("%d",Second(J));
}


/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
int JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
   return((Hour(J)*3600)+(Minute(J)*60)+(Second(J)));
}


JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
   // KAMUS
   JAM J;
   int sisa;
   // ALGORITMA
   N = N % 86400;
   Hour(J) = N / 3600;
   sisa = N % 3600;
   Minute(J) = sisa / 60;
   Second(J) = sisa % 60;
   return(J);
}


/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
   return (DetikToJAM(JAMToDetik(J)+1));
}


JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
   return (DetikToJAM(JAMToDetik(J)-1));
}