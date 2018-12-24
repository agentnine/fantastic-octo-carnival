/* Kelompok    : CisituPlusNobel
/* File        : mwnu.c */
/* Tanggal     : 29 Oktober 2018 */

#include "datatype.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "boolean.h"

int getch(void);
/*Procedur buatan yang menggantikan getch() pada library conio.h yang tidak ada di linux
  didapat dari https://stackoverflow.com/questions/29612201/implicit-declaration-of-function-getch*/

void Load(char nama[20], boolean *baru, boolean *load);
/* Proses : Melakukan proses Load pada Game */

void menu(char nama[20], boolean *baru, boolean *load);
/*Melakukan tampilan awal seta menerima input di awal permainan. Setelah melewati procedure ini
  programa baru dapat untuk memainkan permainan dan perintah untuk melakuakn new game atau load
  game ditampung pada boolean new dan load*/

void CekCommand(int *i, char* command);
/*Procedur ini akan mengecek apakah string input yang dimasukkan pengguna terdapat pada
  pita command. Jika terdapat, maka akan ditampung padacvariabel i dan nilainya adalah
  nomor urut command tersebut di file namun,cjika tidak terdapat maka akan menghasilkan DataUUndef*/