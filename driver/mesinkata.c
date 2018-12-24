/* Kelompok    : CisituPlusNobel
/* File        : mesinkata.c*/
/* Tanggal     : 29 Oktober 2018 */

#include "../include/mesinkata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
  while ((CC == BLANK) && (CC != MARK)){
    ADV();
  }
}

void STARTKATA(char* file)
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  START(file);
  IgnoreBlank();
  if (CC == MARK){
    EndKata = true;
  } else{
    EndKata = false;
    SalinKata();
  }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  IgnoreBlank();
  if (CC == MARK){
    EndKata = true;
  } else{
    SalinKata();
    IgnoreBlank();
  }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  // KAMUS LOKAL
  int i;

  // ALGORITMA
  i = 1;
  for(;;){
    CKata.TabKata[i] = CC;
    //printf("%c\n", CC);
    ADV();
    if ((CC == MARK) || (CC == BLANK)){
      break;
    } else{
      i++;
    }
  }
  //printf("%c\n", CKata.TabKata[3]);
  if (CKata.Length > NMax){
    CKata.Length = NMax;
  } else{
    CKata.Length = i;
  }
}
