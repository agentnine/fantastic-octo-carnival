/* Kelompok    : CisituPlusNobel
/* File        : main.c */
/* Tanggal     : 29 Oktober 2018 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/matriks.h"
#include "../include/point.h"
#include "../include/jam.h"
#include "../include/queue.h"
#include "../include/stackt.h"
#include "../include/stackf.h"
#include "../include/array.h"
#include "../include/room.h"
#include "../include/function.h"
#include "../include/boolean.h"
#include "../include/mesinkata.h"
#include "../include/mesinkar.h"
#include "../include/pohonbiner.h"
#include "../include/graph.h"
#include "../include/datatype.h"
#include "../include/menu.h"

int main(){
  //KAMUS LOKAL
  ROOM R;
  POINT N;
  LOC L;
  BinTree Resep;
  JAM J;
  Graph G;
  int Add, custs, life, money, cmd;
  Queue Q;
  Stack Hand;
  StackFood Food;
  char command[12], name[20];
  char C;
  TabInt orders,tables,kitchen;
	StatusTable status;
  boolean EOProgram, tick, load, new;
  int key;
  boolean move, input;

  //ALGORITMA
  menu(name,&new,&load);
  if (new){
    Inisialisasi(&L, &custs, &R, &N, &J, &Add, &Q, &Hand, &Food, &orders, &tables, &kitchen, &status, &life, &money, &Resep, &G);
    EOProgram = false;
  } else if (load){
    EOProgram = false;
    LoadGame(name, &L, &custs, &R, &N, &J, &Add, &Q, &Hand, &Food, &orders, &tables, &kitchen, &status, &life, &money, &Resep, &G);
  }

  move = true;
  input = false;
  EOProgram = false;
  system("clear");
  Interface(name, R, L, Q, Hand, Food, orders, J, life, money);
  while(life>0 && (EOProgram == false)){
    if (move){
      while (move){
        tick = true;
        key = getch();
        if (key == 87){
          Go(&R, 'U', &L, G);
        } else if (key == 65){
          Go(&R, 'L', &L, G);
        } else if (key == 83){
          Go(&R, 'D', &L, G);
        } else if (key == 68){
          Go(&R, 'R', &L, G);
        } else if (key == 69){
          move = false;
          input = true;
          tick = false;
        } else{
          tick = false;
          printf("Masukan Salah!\n");
        }
        if (tick){
          J = NextDetik(J);
          AddRemove(&orders, &Q, &R, &life, &tables, &Add, &custs);
        }
        system("clear");
        Interface(name, R, L, Q, Hand, Food, orders, J, life, money);
        if (life == 0){
          EOProgram = true;
          move = false;
        }
      }
    } else if (input){
      while (input){
        tick = true;
        printf("COMMAND = \n>> ");
        scanf("%s", command);
        CekCommand(&cmd, command);
        switch (cmd){
          case 1: //GD
            Go(&R, 'D', &L, G);
            break;
          case 2: //GU
            Go(&R, 'U', &L, G);
            break;
          case 3: //GL
            Go(&R, 'L', &L, G);
            break;
          case 4: //GR
            Go(&R, 'R', &L, G);
            break;
          case 5: //ORDER
            Order(L, &orders, &tables);
            break;
          case 6: //PUT
            Put(Resep, &Hand, &Food, L, N);
            break;
          case 7: //TAKE
            Take(L, &Hand, kitchen);
            break;
          case 8: //CAH
            CAH(&Hand);
            break;
          case 9: //COH
            COH(&Hand);
            break;
          case 10: //CAT
            CAT(&Food);
            break;
          case 11: //COT
            COT(&Food);
            break;
          case 12: //PLACE
            Place(&Q, &R, L, &tables);
            break;
          case 13: //GIVE
            Give(L, &Food, &R, &tables, &orders, &money);
            break;
          case 14: //RECIPE
            Recipe(Resep);
            tick = false;
            break;
          case 15: //SAVE
            SaveGame(name,L,custs,N,J,Add,Q,Hand,Food,orders,tables,kitchen,life,money,G);
            tick = false;
            printf("Game Berhasil Di-save! ");
            break;
          case 16: //MOVE
            move = true;
            input = false;
            tick = false;
            break;
          case 0: //EXIT
            printf("Game Belum Di-Save, Save Sekarang? (Y/N)\n");
            scanf("%c", &C);
            scanf("%c", &C);
            if (C == 'Y' || C == 'y'){
              SaveGame(name,L,custs,N,J,Add,Q,Hand,Food,orders,tables,kitchen,life,money,G);
            }
            EOProgram = true;
            input = false;
            tick = false;
            break;
          case -1: //LOAD
            printf("Game Belum Di-Save, Save Sekarang? (Y/N)\n");
            scanf("%c", &C);
            scanf("%c", &C);
            if (C == 'Y' || C == 'y'){
              SaveGame(name,L,custs,N,J,Add,Q,Hand,Food,orders,tables,kitchen,life,money,G);
            } else if (C == 'N' || C == 'n'){
              Load(name, &new, &load);
              if (load){
                LoadGame(name, &L, &custs, &R, &N, &J, &Add, &Q, &Hand, &Food, &orders, &tables, &kitchen, &status, &life, &money, &Resep, &G);
              } else{
                printf("Load Gagal! Nama yang Anda Masukkan Belum Tersimpan ");
              }  
              tick = false; 
            }
            break;
          default :
            printf("Perintah Yang Dimasukkan Salah! ");
            scanf("%c", &C);
            tick = false;
            break;
        }
        if (tick){
          J = NextDetik(J);
          AddRemove(&orders, &Q, &R, &life, &tables, &Add, &custs);
        }
        if (life == 0){
          EOProgram = true;
          input = false;
        }
        if (!EOProgram){
          system("clear");
          Interface(name, R, L, Q, Hand, Food, orders, J, life, money);
        }
      }
    }
  }
  if (life==0 || EOProgram){
    //system("clear");
    Interface(name, R, L, Q, Hand, Food, orders, J, life, money);
    printf("GAME BERAKHIR\n");
    printf("\nCreated By : \n");
    printf("Cisitu Plus Nobel Team\n");
    printf("\n13517021 Abda Shaffan Diva\n");
    printf("13517042 Muhamad Nobel Fauzan\n");
    printf("13517069 Didik Supriadi\n");
    printf("13517075 Juniardi Akbar\n");
    printf("13517081 Nurul Utami\n");
  }
  return 0;
}

// gcc main.c point.c queue.c stackt.c stackf.c array.c matriks.c jam.c function.c datatype.c room.c pohonbiner.c mesinkar.c mesinkata.c graph.c -o main