/* Kelompok    : CisituPlusNobel
/* File        : menu.c */
/* Tanggal     : 29 Oktober 2018 */

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"

int getch(void)
/*Procedur buatan yang menggantikan getch() pada library conio.h yang tidak ada di linux
  didapat dari https://stackoverflow.com/questions/29612201/implicit-declaration-of-function-getch*/
{
	struct termios oldt, newt;
	int ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

	return ch;
}

void Load(char nama[20], boolean *new, boolean *load)
/* Proses : Melakukan proses Load pada Game */
{
  //KAMUS LOKAL
  int j;
  char namafile[25],file[35];
  FILE *fptr;
  char C;

  //ALGORITMA
  printf("--- Load Game! ---\n");
  printf("Enter Your Name : ");
  scanf("%s", nama);
  j=0;
  while (nama[j] != '\0'){
    namafile[j] = nama[j];
    j++;
  }
  file[0]='.';
  file[1]='.';
  file[2]='/';
  file[3]='s';
  file[4]='a';
  file[5]='v';
  file[6]='e';
  file[7]='/';
  file[8]='\0';
  strcat(namafile, ".txt");
  strcat(file, namafile);
  fptr = fopen(file, "r");
  if(fptr == NULL){
    printf("%s Belum Tersimpan\n", nama);
    scanf("%c", &C);
    nama[0] = '\0';
  } else{
    *load = true;
    *new = false;
  }
}

void menu(char nama[20], boolean *new, boolean *load)
/*Melakukan tampilan awal seta menerima input di awal permainan. Setelah melewati procedure ini
  programa baru dapat untuk memainkan permainan dan perintah untuk melakuakn new game atau load
  game ditampung pada boolean new dan load*/
{
  //KAMUS LOKAL
  int i,j;
  boolean found,sama,start;
  int key;
  boolean move, input;
  boolean EOProgram;
  char C;
  char namafile[25], command[10];

  //ALGORITMA
  start = false;
  *load = false;
  *new = false;
  EOProgram = false;
  nama[0] = '\0';
  while (!start && !EOProgram){
    system("clear");
    printf(" /$$$$$$$$                     /$$ /$$ /$$$$$$        /$$   /$$ /$$   /$$               /$$                          \n");
    printf("| $$_____/                    |__/| $//$$__  $$      | $$  /$$/|__/  | $$              | $$                          \n");
    printf("| $$       /$$$$$$$   /$$$$$$  /$$|_/| $$  `__/      | $$ /$$/  /$$ /$$$$$$    /$$$$$$$| $$$$$$$   /$$$$$$  /$$$$$$$ \n");
    printf("| $$$$$   | $$__  $$ /$$__  $$| $$   |  $$$$$$       | $$$$$/  | $$|_  $$_/   /$$_____/| $$__  $$ /$$__  $$| $$__  $$\n");
    printf("| $$__/   | $$  ` $$| $$  ` $$| $$    `____  $$      | $$  $$  | $$  | $$    | $$      | $$  ` $$| $$$$$$$$| $$  ` $$\n");
    printf("| $$      | $$  | $$| $$  | $$| $$    /$$  ` $$      | $$`  $$ | $$  | $$ /$$| $$      | $$  | $$| $$_____/| $$  | $$\n");
    printf("| $$$$$$$$| $$  | $$|  $$$$$$$| $$   |  $$$$$$/      | $$ `  $$| $$  |  $$$$/|  $$$$$$$| $$  | $$|  $$$$$$$| $$  | $$\n");
    printf("|________/|__/  |__/ `____  $$|__/    `______/       |__/  `__/|__/   `___/   `_______/|__/  |__/ `_______/|__/  |__/\n");
    printf("                     /$$  ` $$                                                                                       \n");
    printf("                    |  $$$$$$/                  __ __ __(_)| |_ | |_    ___ __ __ _ __  __ _  _ _   ___(_) ___  _ _  \n");
    printf("                     `______/                   ` V  V /| ||  _|| ' `  / -_)` ` /| '_ `/ _` || ' ` (_-<| |/ _ `| ' ` \n");
    printf("                                                 `_/`_/ |_| `__||_||_| `___|/_`_`| .__/`__,_||_||_|/__/|_|`___/|_||_|\n");
    printf("                                                                                 |_|                                 \n");
    printf("\n");
    if (nama[0] != '\0'){
      printf("Selamat Datang %s!\n", nama);
    } else{
      printf("\n");
    }
    printf("╔╦╗╔═╗╦╔╗╔  ╔╦╗╔═╗╔╗╔╦ ╦\n");
    printf("║║║╠═╣║║║║  ║║║║╣ ║║║║ ║\n");
    printf("╩ ╩╩ ╩╩╝╚╝  ╩ ╩╚═╝╝╚╝╚═╝\n");
    printf(">> START\n");
    printf(">> NEW\n");
    printf(">> LOAD\n");
    printf(">> EXIT\n");
    printf("COMMAND : ");
    scanf("%s", command);
    scanf("%c", &C);
    STARTKATA("../pita/pitacommand.txt");
    i = 1;
    found = false;
    while (!found && i<=4){
      sama = true;
      j = 1;
      while (j<=CKata.Length && sama){
        if (CKata.TabKata[j] == command[j-1]){
          j++;
        } else{
          sama = false;
        }
      }
      if (sama){
        found = true;
      } else{
        i++;
        ADVKATA();
      }
    }
    if (!found){
      i = DataUndef;
    }
    switch (i){
      case 1: //START
        if (*load || *new){
          start = true;
        } else{
          printf("Silahkan Pilih New Game Atau Load Game Terlebih Dahulu");
          scanf("%c", &C);
        }
        break;
      case 2: //NEW
        printf("--- New Game ---\n");
        printf("Enter Your Name : ");
        scanf("%s", nama);
        *new = true;
        *load = false;
        break;
      case 3: //LOAD
        Load(nama, new, load);
        break;
      case 4: //EXIT
        EOProgram = true;
        break;
      default:
        printf("Masukan Salah!\n");
        scanf("%c", &C);
    }
  }
}

void CekCommand(int *i, char* command)
/*Procedur ini akan mengecek apakah string input yang dimasukkan pengguna terdapat pada
  pita command. Jika terdapat, maka akan ditampung padacvariabel i dan nilainya adalah
  nomor urut command tersebut di file namun,cjika tidak terdapat maka akan menghasilkan DataUUndef*/
{
  //KAMUS LOKAL
  int j;
  boolean found, sama;

  //ALGORITMA  
  STARTKATA("../pita/pitacommand.txt");
  *i = 1;
  found = false;
  while (!found && !EndKata){
    sama = true;
    j = 1;
    while (j<=CKata.Length && sama){
      if (CKata.TabKata[j] == command[j-1]){
        j++;
      } else{
        sama = false;
      }
    }
    if (sama){
      found = true;
    } else{
      (*i)++;
      ADVKATA();
    }
  }
  *i = *i-4;
  if (!found && (*i<-1)){
    *i = DataUndef;
  }
}