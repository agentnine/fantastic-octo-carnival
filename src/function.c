/* Kelompok    : CisituPlusNobel
/* File        : function.c */
/* Tanggal     : 29 Oktober 2018 */

#include "../include/function.h"
#include "../include/datatype.h"
#include <stdio.h>
#include <string.h>

char C;

void Interface(char* name, ROOM R, LOC L, Queue Q, Stack Hand, StackFood Food, TabInt orders, JAM J, int life, int money)
/* Menulis Interface*/
{
  //KAMUS LOKAL
  int i;

  //ALGORITMA
  printf("\n%s | ", name);
  printf("MONEY : %d | ", money);
  printf("LIFE : %d | ", life);
  printf("TIME : ");
  TulisJAM(J);
  printf("\n");

  TulisMATRIKS(Elm(R,Room(L))); printf("\n");
  
  if (!IsEmptyQueue(Q)){
    printf("\nWAITING CUST : \n");
    PrintQueue(Q);
  }

  if (!IsEmptyStackt(Hand)){
    printf("\nHAND : \n");
    PrintStackt(Hand);
  }

  if (!IsEmptyStackFood(Food)){
    printf("\nFOOD STACK: \n");
    PrintStackFood(Food);
  }

  if (!IsEmpty(orders)){
    printf("\nORDER : \n");
    TulisIsiTab(orders);
  }

  printf("\n");
}

void Go(ROOM *R, char C, LOC *L, Graph G)
/*  Procesure Go terdiri dari 4 perintah yaitu Go Up, Go Down, Go Left, Go Right */
{
  //KAMUS LOKAL
  POINT temp;
  LOC tempL;

  //ALGORITMA
  Absis(temp) = Absis(Point(*L));
  Ordinat(temp) = Ordinat(Point(*L));
  switch (C){
    case 'D':
      CariEdgePintu(G,*L,&tempL,C);
      if (Room(tempL) != DataUndef){
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = ' ';
        Room(*L) = Room(tempL);
        Point(*L) = Point(tempL);
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = 'P';
      }
      else if (ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L))+1,Ordinat(Point(*L))) == ' '){
        temp = PlusDelta(Point(*L),1,0);
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = ' ';
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(temp),Ordinat(temp)) = 'P';
        Point(*L) = temp;
      }
      break;
    case 'U':
      CariEdgePintu(G,*L,&tempL,C);
      if (Room(tempL) != DataUndef){
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = ' ';
        Room(*L) = Room(tempL);
        Point(*L) = Point(tempL);
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = 'P';
      }
      else if (ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L))-1,Ordinat(Point(*L))) == ' '){
        temp = PlusDelta(Point(*L),-1,0);
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = ' ';
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(temp),Ordinat(temp)) = 'P';
        Point(*L) = temp;
      }
      break;
    case 'L':
      CariEdgePintu(G,*L,&tempL,C);
      if (Room(tempL) != DataUndef){
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = ' ';
        Room(*L) = Room(tempL);
        Point(*L) = Point(tempL);
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = 'P';
      }
      else if (ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))-1) == ' '){
        temp = PlusDelta(Point(*L),0,-1);
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = ' ';
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(temp),Ordinat(temp)) = 'P';
        Point(*L) = temp;
      }
      break;
    case 'R':
      CariEdgePintu(G,*L,&tempL,C);
      if (Room(tempL) != DataUndef){
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = ' ';
        Room(*L) = Room(tempL);
        Point(*L) = Point(tempL);
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = 'P';
      }
      else if (ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))+1) == ' '){
        temp = PlusDelta(Point(*L),0,1);
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = ' ';
        ElmtMATRIKS(Elm(*R,Room(*L)),Absis(temp),Ordinat(temp)) = 'P';
        Point(*L) = temp;
      }
      break;
  }
}

void Place(Queue *Q, ROOM *R, LOC L, TabInt *tables)
/* Menempatkan pelangan dengan Top of Queue ke dalam meja yang kososng */
{
  //KAMUS LOKAL
  int meja, table, i, j;
  Customer X;
  boolean found;
  StatusTable T;

  //ALGORITMA
  if (!IsEmptyQueue(*Q)){
    CekSebelahan(L, &table, *tables);
    if (table != -999){
      T = (ElmtArray(*tables,table));
      if (InfoHead(*Q).NbPeople == 4){
        CekKosong4(*tables, &meja);
        if ((meja != -999) && (T.Kapasitas==4) && (T.IsKosong)) {
          printf("Mengisi Meja Nomor %d! ", table);
          DelQueue(Q, &X);
          MakeFullTable(R, tables, table, X, 4);
        } else if (meja == -999){
          CekKosong2(*tables, &meja);
          if ((meja != -999) && (table != -999) && (T.IsKosong)){
            i = Head(*Q);
            found = false;
            j = Tail(*Q) + 1;
            if (j > MaxEl(*Q)) {
              j = j - MaxEl(*Q);
            }
            while ((i != j) && !found) {
              if (Cust(*Q, i) == 2) {
                printf("Mengisi Meja Nomor %d! ", table);
                DelEliQueue(Q,i,&X);
                MakeFullTable(R, tables, table, X, 2);
                found = true;
              }
              i++;
              if (i > MaxEl(*Q)) {
                i = i - MaxEl(*Q);
              }
            }
          }
        } else if (!(T.IsKosong)){
          printf("Meja Penuh! ");
        } else if (T.Kapasitas != 4){
          printf("Kapasitas Meja Tidak Cukup! ");
        }
      } else {
        CekKosong2(*tables, &meja);
        if ((meja != -999) && ((table != -999)) && (T.IsKosong)){
          printf("Mengisi Meja Nomor %d! ", table);
          DelQueue(Q, &X);
          MakeFullTable(R, tables, table, X, 2);
        } else if (!T.IsKosong){
          printf("Meja Penuh! ");
        }
      }
    } else{
      printf("Tidak Ada Meja Di Sekitar Anda! ");
    }
  } else{
    printf("Antrian Kosong! ");
  }
  
}

void Take(LOC L, Stack *S, TabInt kitchen)
/*Mengambil bahan makanan di dekat player */
{
  //KAMUS LOKAL
  int X;
  
  //ALGORITMA
  if (Room(L) == 4){
    CekSebelahanDapur(kitchen,Point(L),&X);
    if (X != -999){
      if (!IsFullStackt(*S)){
        printf("Mengambil %s! ", bahan[X]);
        Push(S,X);
      } else{
        printf("Tangan Anda Sudah Penuh Dengan Bahan Makanan! ");
      }
    }
  }
  
}

void CAH(Stack *S)
/* Membuang semua bahan makanan yang ada di tangan */
{
  if(!IsEmptyStackt(*S)){
    CreateEmptyStackt(S);
    printf("Membuang Semua Bahan Makanan Dari Tangan! ");
  } else{
    printf("Tidak Ada Bahan Makanan Di Tangan! ");
  }
  
}

void COH(Stack *S)
/* Membuang semua bahan makanan yang ada di tangan */
{
  //KAMUS LOKAL
  infotypeStackt X;

  //ALGORITMA
  if(!IsEmptyStackt(*S)){
    Pop(S,&X);
    printf("Membuang %s Dari Tangan! ", bahan[X]);
  } else{
    printf("Tidak Ada Bahan Makanan Di Tangan! ");
  }
  
}

void CAT(StackFood *S)
/* Membuang semua bahan makanan yang ada di tangan */
{
  if(!IsEmptyStackFood(*S)){
    CreateEmptyStackFood(S);
    printf("Membuang Semua Makanan Dari Nampan! ");
  } else{
    printf("Tidak Ada Makanan Di Nampan! ");
  }
  
}

void COT(StackFood *S)
/* Membuang semua bahan makanan yang ada di tangan */
{
  //KAMUS LOKAL
  infotypeStackFood X;

  //ALGORITMA
  if(!IsEmptyStackFood(*S)){
    Popf(S,&X);
    printf("Membuang %s Dari Nampan! ", bahan[X]);
  } else{
    printf("Tidak Ada Makanan Di Nampan! ");
  }
}

void Order(LOC L, TabInt *orders, TabInt *tables)
/* Mengambil order dari meja yang bersebelahan */
{
  //KAMUS LOKAL
  int meja;
  ElTypeArray X;

  //ALGORITMA
  CekSebelahan(L,&meja,*tables);
  if (meja != -999){
    X = ElmtArray(*tables,meja);
    if (X.IsOrdered == false && X.IsKosong == false){
      AddAsLastEl(orders,X);
      ElmtArray(*tables,meja).IsOrdered = true;
      printf("Order Berhasil! ");
    } else{
      if (X.IsOrdered){
        printf("Order Sudah Dilakukan! ");
      } else if (X.IsKosong){
        printf("Meja Kosong! ");
      }
    }
  } else{
    printf("Tidak Ada Meja Di Sekitar Anda! ");
  }
  
}

void Recipe (BinTree P)
/*Mencetak Resep yang digunakan pada Engi's Kitchen */
{
  ShowBranch(P);
  scanf("%c",&C);
  scanf("%c",&C);
}

/*FUNGSI PEMBANTU AMBIL BAHAN MAKANAN */
boolean IsPlateExist (Stack S)
/* Mengembalikan true apabila pada Stack Hand sudah terdapat piring */
{
  //Kamus
  Stack STemp;
  infotypeStackt X;
  //Algoritma
  CreateEmptyStackt(&STemp);
  if (IsEmptyStackt(S))
    return false;
  else{
    while (!IsEmptyStackt(S) && (InfoTop(STemp) != 1)){
      Pop(&S,&X);
      Push(&STemp,X);
    }
    if (InfoTop(STemp) == 1)
      return true;
    else 
      return false;
  }
}

void SearchBranch(BinTree *P, Stack * StackIn, Stack * StackOut)
/*FUNGSI PEMBANTU PUT */
{
  //KAMUS
  infotypeStackt X;
  boolean match = true;
  
  //ALGORITMA
  while ((match) && (!IsOneElmt(*P))){
    if (!IsEmptyStackt(*StackIn)){
      Pop(StackIn,&X);
      Push(StackOut,X);
    }
    if (IsUnerRight(*P)){
      if (InfoTop(*StackIn) != Akar(Right(*P))){
        match = false;
      }
      *P = Right(*P); //kasus bahan akhir uner
    }
    else if (IsUnerLeft(*P)){
      if (InfoTop(*StackIn) != Akar(Left(*P))){
        match = false;
      }
      *P = Left(*P); //kasus bahan akhir uner
    }
    else{
      if (InfoTop(*StackIn) == Akar(Right(*P))){
        *P = Right(*P);
      }
      else if (InfoTop(*StackIn) == Akar(Left(*P))){
        *P = Left(*P);
      }
      else{
        match = false;
      }
    }
  } 
}

void Put (BinTree  P, Stack *Bahan, StackFood *Food, LOC L, POINT N)
/* I.S : P, Bahan, dan Food semuanya harus sudah terdefinisi */
/* Prosedur ini mengecek apakah urutan bahan dalam Stack sudah benar dari bawah ke atas */
/* Jika benar , F.S semua bahan berurutan yang sesuai dengan resep yang ada pada BinTree dihilangkan,*/
/* dan makanan jadi ditambahkan pada Stack Food */
/* Jika tidak ada urutan bahan yang benar, tidak merubah apa-apa pada stack bahan dan stack food*/
{
  //Kamus
  Stack SIn,SOut;
  infotypeStackt X;
  BinTree Px;
  boolean can;

  //Algoritma

  can = false;
  if (Room(L) == 4){
    if (Absis(Point(L)) == Absis(N)){
      if ((Ordinat(Point(L)) == Ordinat(N)-1) || (Ordinat(Point(L)) == Ordinat(N)+1)){
        can = true;
      }
    } else if (Ordinat(Point(L)) == Ordinat(N)){
      if ((Absis(Point(L)) == Absis(N)+1) || (Absis(Point(L)) == Absis(N)-1)){
        can = true;
      }
    }
  }
  if (can){
    CreateEmptyStackt(&SIn);
    //Cari piring di tumpukan stack
    while ((InfoTop(*Bahan) != 1) && (!IsEmptyStackt(*Bahan))){
      Pop(Bahan,&X);
      Push(&SIn,X);
    }
    PrintStackt(*Bahan);
    if (InfoTop(*Bahan) == 1) { //Nemu piring di bahan
      CreateEmptyStackt(&SOut);
      Pop(Bahan,&X); //taro piring di SIn
      Push(&SIn,X);
      if (IsEmptyStackt(*Bahan)){
        Px = P; 
        SearchBranch(&Px, &SIn, &SOut);
        if ((IsOneElmt(Px)) && (IsEmptyStackt(SIn))){ //harus persis resep
          Pushf(Food,Akar(Px));
          printf("Berhasil membuat %s ! ", bahan[Akar(Px)]);
        }
        else{ //balikin semula
          while(!IsEmptyStackt(SOut)){
            Pop(&SOut,&X);
            Push(&SIn,X);
          }
          while (!IsEmptyStackt(SIn)){ 
            Pop(&SIn,&X);
            Push(Bahan,X);
          }
          printf("Resep Tidak Sesuai ! ");
        }
      }
      else { //Gak ada piring di stack Bahan ,balikin
        while (!IsEmptyStackt(SIn)){ 
          Pop(&SIn,&X);
          Push(Bahan,X);
        }
        printf("Resep Tidak Sesuai ! ");
      }
    }
    else { //Gak ada piring di stack Bahan ,balikin
      while (!IsEmptyStackt(SIn)){ 
        Pop(&SIn,&X);
        Push(Bahan,X);
      }
      printf("Resep Tidak Sesuai ! ");
    }
  }
}

void Give(LOC L, StackFood *Food, ROOM *R, TabInt *tables, TabInt *orders, int *money)
/*Memberikan makanan ke pengguna. Jika user sedang di sekitar meja dan pesanan sesuai maka
  pesanan akan diberikan dan uang akan bertambah*/
{
  //KAMUS LOKAL
  int meja, i;
  boolean found;
  StatusTable status;
  infotypeStackt X;

  //ALGORITMAa
  CekSebelahan(L,&meja,*tables);
  if (meja != -999 && !IsEmptyStackFood(*Food)){
    if (InfoTopf(*Food) == ElmtArray(*tables,meja).Pesanan){
      Popf(Food,&X);
      MakeEmptyTable(R, tables, meja);
      *money = *money + harga[X-16];
      i = GetFirstIdx(*orders);
      found = false;
      while (!found){
        if (meja == ElmtArray(*orders,i).NbTable){
          found = true;
          DelEli(orders,i,&status);
        } else{
          i++;
        }
      }
      printf("Pesanan Diterima! ");
    } else{
      printf("Pesanan Tidak Sesuai! ");
    }
  } else{
    if (meja == -999){
      printf("Tidak Ada Meja Di Sekitar Anda! ");
    } else{
      printf("Tidak Ada Makanan Di Nampan! ");
    }
  }
}

void AddRemove(TabInt *orders, Queue *Q, ROOM *R, int *life, TabInt *tables, int *Add, int *custs)
/*Menambah/mengurangi array order, antrian, array table jika waktu tunggu sudah habis
  serat melaukan penambahan waktu */
{
  //KAMUS LOKAL
  int i,j,meja;
  boolean found;
  boolean nl;
  char nomor;
  Customer cust,X;
  StatusTable status;

  //ALGORITMA
  for (i=1; i<=12; i++){
    if (ElmtArray((*orders),i).WaitTime != DataUndef){
      ElmtArray((*orders),i).WaitTime--;
    }
    if (ElmtArray((*tables),i).WaitTime != DataUndef){
      ElmtArray((*tables),i).WaitTime--;
    }
    if (ElmtArray((*tables),i).WaitTime == 0){
      meja = ElmtArray((*tables),i).NbTable;
      nomor = no[meja];
      printf("Pengunjung Meja %c Telah Pergi! ", nomor);
      nl = true;
      MakeEmptyTable(R,tables,meja);
      j = GetFirstIdx(*orders);
      found = false;
      while (!found){
        if (meja == ElmtArray(*orders,j).NbTable){
          found = true;
          DelEli(orders,j,&status);
        } else{
          j++;
        }
      }
      (*life)--;
    } else if (ElmtArray((*tables),i).WaitTime <= 10 && ElmtArray((*tables),i).WaitTime >= 0){
      meja = ElmtArray((*tables),i).NbTable;
      nomor = no[meja];
      printf("Kesabaran Pengunjung Meja %c Hampir Habis! ", nomor);
    }
  }

  if (!IsEmptyQueue(*Q)){
    if (Tail(*Q) >= Head(*Q)){
      for (i=Head(*Q); i<=Tail(*Q); i++){
        WT(*Q,i)--;
      }
    } else{
      i=Head(*Q);
      while (i!=Tail(*Q)){
        WT(*Q,i)--;
        i++;
        if (i>MaxEl(*Q)){
          i = i-MaxEl(*Q);
        }
      }
    }
  }

  if (!IsEmptyQueue(*Q)){
    if (WT(*Q, Head(*Q)) == 0) {
      DelQueue(Q, &X);
      (*life)--;
      printf("Antrian Terdepan Telah Pergi! ");
    } else if (WT(*Q, Head(*Q)) <= 10) {
      printf("Kesabaran Antrian Terdepan Hampir Habis! ");
    }
  }
  (*Add)++;
  if (*Add == 35){
    *Add = Random(5,10);
    cust.NbPeople = Random(1,2)*2;
    cust.Pesanan = Random(17,24);
    if (*custs % 10 == 0){
      cust.star = true;
      cust.WaitTime = 15;
    }else{
      cust.star = false;
      cust.WaitTime = 30;
    }
    AddQueue(Q, cust);
    (*custs)++;
    printf("Antrian Bertambah! ");
  }
}

int chartoint (char a){
/* Mengubah angka yang direpresentasikan oleh char ke int */
  switch (a) {
    case '0' : return 0;
    case '1' : return 1;
    case '2' : return 2;
    case '3' : return 3;
    case '4' : return 4;
    case '5' : return 5;
    case '6' : return 6;
    case '7' : return 7;
    case '8' : return 8;
    case '9' : return 9;
  }
}

void LoadRoom (ROOM *R, TabInt *tables, TabInt *kitchen, POINT *N, StatusTable status, Graph *G)
/*Melakukan pembacaan yang berisi informasi mengenai bentuk ruangan untuk pertama kali
  Procedure ini akan dipanggil saat progra melakukan inisialisasi state*/
{
  //KAMUS LOKAL
  int i, j, xp, yp, k;
  LOC A,B;

  //ALGORITMA
  START("../pita/pitakar.txt");
  FirstG(*G) = Nil;
  while (CC != ','){ 
    xp = chartoint(CC);
    ADV(); IgnoreBlank();
    yp = chartoint(CC);
    ADV(); IgnoreBlank();
    Point(A) = MakePOINT(xp,yp);
    Room(A) = chartoint(CC);
    ADV(); IgnoreBlank();
    xp = chartoint(CC);
    ADV(); IgnoreBlank();
    yp = chartoint(CC);
    ADV(); IgnoreBlank();
    Point(B) = MakePOINT(xp,yp);
    Room(B) = chartoint(CC);
    ADV(); IgnoreBlank();
    CreatePintu(G,A,B,CC);
    ADV(); IgnoreBlank(); 
  }
  ADV(); IgnoreBlank();
  ADV(); IgnoreBlank();
  j = 1;
  for (i=1;i<=3;i++) {
    while (CC!=',') {
      status.NbTable = j;
      xp = chartoint(CC);
      Absis(status.PTable) = xp;
      ADV(); IgnoreBlank();
      yp = chartoint(CC);
      Ordinat(status.PTable) = yp;
      ADV(); IgnoreBlank();
      k = chartoint(CC);
      status.Kapasitas = k;
      AddEli(tables,status,j);
      ADV(); IgnoreBlank();
      j++;
    }
    ADV();ADV(); IgnoreBlank();
    status.Kapasitas = DataUndef;
    status.NbTable = DataUndef;
    status.PTable = MakePOINT(-999,-999);
  }
  i = 1;
  while (CC!='.')
  {
    xp = chartoint(CC);
    Absis(status.PTable) = xp;
    ADV(); IgnoreBlank();
    yp = chartoint(CC);
    Ordinat(status.PTable) = yp;
    ADV(); IgnoreBlank();
    k = chartoint(CC);
    ADV();
    if (CC != ' '){
      k = k*10 + chartoint(CC);
      status.Isi = k;
      AddEli(kitchen,status,i);
      ADV(); IgnoreBlank();
    }else{
      if (k!=0){
        status.Isi = k;
        AddEli(kitchen,status,i);
      }else{
        Absis(*N) = xp;
        Ordinat(*N) = yp;
      }
      ADV(); IgnoreBlank();
    }
    i++;
  }
}

void Inisialisasi(LOC *L, int *custs, ROOM *R, POINT *N, JAM *J, int *Add, Queue *Q, Stack *Hand, StackFood *Food, TabInt *orders, TabInt *tables, TabInt *kitchen, StatusTable *status, int *life, int *money, BinTree *Resep, Graph *G)
/*  Melakukan inisiaisasi state pada program bentuk setiap room yaitu ruangan dalam representasi matriks, 
    koordinat pemain, waktu pemain, antrian, stack of foods, stack of hand, arrayorders, arraytables, arraykitchen, dll */
{  
  //KAMUS LOKAL
  int i,j,k;
  Customer cust;

  //ALGORITMA
  Room(*L) = 1;
  *custs = 0;

  for (i=1; i<=4; i++){
    MakeMATRIKS(8,8,&(Elm(*R,i)));
  }

  Point(*L) = MakePOINT(4,4);
  *J = MakeJAM(0,0,0);
  
  *Add = Random(5,10);
  
  CreateEmptyQueue(Q,10);
  cust.NbPeople = Random(1,2)*2; 
  cust.WaitTime = 30;
  cust.Pesanan = Random(17,24);
  cust.star = false;

  AddQueue(Q, cust);
  (*custs)++;
  
  CreateEmptyStackFood(Food);
  CreateEmptyStackt(Hand);
  
  (*status).WaitTime = DataUndef;
  (*status).NbTable = DataUndef;
  (*status).Kapasitas = DataUndef;
  (*status).Pesanan = DataUndef;
  (*status).PTable = MakePOINT(-999,-999);
  (*status).IsKosong = true;
  (*status).Isi = DataUndef;
  (*status).IsOrdered = false;
  
  MakeEmpty(orders);
  MakeEmpty(tables);
  MakeEmpty(kitchen);
  LoadRoom(R,tables,kitchen,N,*status,G);
  
  for (i=1; i<=4; i++){
    for (j=1; j<=8; j++){
      for (k=1; k<=8; k++){
        ElmtMATRIKS(Elm(*R,i),j,k) = ' ';
      }
    }
  }

  ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = 'P';

  for (j=1; j<=12; j++){
    MakeEmptyTable(R,tables,j);
  }
  
  MakeKitchen(R, *kitchen, *N);

  *life = 999;
  *money = 0;

  LoadTree(Resep);
}

void SaveGame(char name[20], LOC L, int custs, POINT N, JAM J, int Add, Queue Q, Stack Hand, StackFood Food, TabInt orders, TabInt tables, TabInt kitchen, int life, int money, Graph G)
/* Menyimpan semua informasi state game pada file eksternal */
{
  //KAMUS LOKAL
  FILE *f;
  int i, id;
  char namafile[25], file[35];
  infotype XQ;
  infotypeStackt XS;
  StatusTable T;
  adrNode P;
  adrSuccNode Pn;

  //ALGORITMA
  i=0;
  while (name[i] != '\0'){
    namafile[i] = name[i];
    i++;
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
  f = fopen(file, "w");
  fprintf(f, "%s ",name);
  fprintf(f, "%d ", money);
  fprintf(f, "%d ", life);
  fprintf(f, "%d ", JAMToDetik(J));
  fprintf(f, "%d %d ", Absis(Point(L)), Ordinat(Point(L)));
  fprintf(f, "%d ", Room(L));
  fprintf(f, "%d %d ,\n", custs, Add);
  
  while (!IsEmptyQueue(Q)){
    DelQueue(&Q, &XQ);
    fprintf(f, "%d %d %d %d ", XQ.NbPeople, XQ.WaitTime, XQ.Pesanan, XQ.star);
    if (!IsEmptyQueue(Q)){
      fprintf(f, "| ");
    }
  }
  fprintf(f,",\n");
  
  while (!IsEmptyStackt(Hand)){
    Pop(&Hand, &XS);
    fprintf(f, "%d ", XS);
  }
  fprintf(f,",\n");
  
  while (!IsEmptyStackFood(Food)){
    Popf(&Food, &XS);
    fprintf(f, "%d ", XS);
  }
  fprintf(f,",\n");

  for (i=GetFirstIdx(tables); i<=GetLastIdx(tables); i++){
    T = tables.TI[i];
    if (T.IsKosong){
      fprintf(f, "%d %d %d %d %d ", T.IsKosong, T.NbTable, T.Kapasitas, Absis(T.PTable), Ordinat(T.PTable));
    } else{ 
      fprintf(f, "%d %d %d %d %d %d %d %d ", T.IsKosong, T.NbTable, T.Kapasitas, Absis(T.PTable), Ordinat(T.PTable), T.Pesanan, T.WaitTime, T.IsOrdered);
    }
    if (i != GetLastIdx(tables)){
      fprintf(f, "| ");
    }
  }
  fprintf(f,",\n");

  for (i=GetFirstIdx(kitchen); i<=GetLastIdx(kitchen); i++){
    T = kitchen.TI[i]; 
    fprintf(f, "%d %d %d ", T.Isi, Absis(T.PTable), Ordinat(T.PTable));
    fprintf(f, "| ");
  }

  fprintf(f, "0 %d %d", Absis(N), Ordinat(N));
  fprintf(f, " ,\n");


  for (i=GetFirstIdx(orders); i<=GetLastIdx(orders); i++){
    T = orders.TI[i]; 
    fprintf(f, "%d %d %d ",T.NbTable, T.Pesanan, T.WaitTime);
    if (i != GetLastIdx(orders)){
      fprintf(f, "| ");
    }
  }
  fprintf(f,",\n");

  P = FirstG(G);
  while(P != NilGraph)
  {
    id = Id(P);
    Pn = Trail(P);
    while(Pn != NilGraph)
    {
        fprintf(f, "%d %d %d ",Absis(Point(Asal(Pn))),Ordinat(Point(Asal(Pn))),id);
        fprintf(f, "%d %d %d %c ",Absis(Point(Tujuan(Pn))),Ordinat(Point(Tujuan(Pn))), Id(Succ(Pn)), Key(Pn));
        Pn = Next(Pn);
    }
    P = Next(P);
  }
  fprintf(f, ",\n");
  fprintf(f,".\n");
  fclose(f);
}

void LoadGame(char name[20], LOC *L, int *custs, ROOM *R, POINT *N, JAM *J, int *Add, Queue *Q, Stack *Hand, StackFood *Food, TabInt *orders, TabInt *tables, TabInt *kitchen, StatusTable *status, int *life, int *money, BinTree *Resep, Graph *G)
/*  Melakukan pembacaan state pada file dan melakukan load pada bentuk setiap room yaitu ruangan dalam representasi matriks, 
    koordinat pemain, waktu pemain, antrian, stack of foods, stack of hand, arrayorders, arraytables, arraykitchen, dll */
{
  //KAMUS LOKAL
  FILE *f;
  char namafile[25],file[35];
  int i, j, k, xp, yp, temp;
  int kosong;
  Customer XQ;
  infotypeStackt XS;
  infotypeStackFood XF;
  StatusTable statusT;
  TabInt dummy;
  LOC A,B;

  //ALGORITMA
  MakeEmpty(&dummy);
  i=0;
  while (name[i] != '\0'){
    namafile[i] = name[i];
    i++;
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
  START(file);
  i=0;
  while (CC != ' '){
    name[i] = CC;
    i++;
    ADV();
  }
  name[i] = '\0'; ADV(); IgnoreBlank();
  *money = 0;
  while (CC != ' '){
    *money = (*money)*10 + chartoint(CC);
    ADV();
  }
  ADV(); IgnoreBlank();
  *life = chartoint(CC);
  ADV(); IgnoreBlank();
  temp = 0;
  while (CC != ' '){
    temp = temp*10 + chartoint(CC);
    ADV();
  }
  *J = DetikToJAM(temp);
  ADV(); IgnoreBlank();
  Absis(Point(*L)) = chartoint(CC);
  ADV(); IgnoreBlank();
  Ordinat(Point(*L)) = chartoint(CC);
  ADV(); IgnoreBlank();
  Room(*L) = chartoint(CC);
  ADV(); IgnoreBlank();  
  *custs = 0;
  while (CC != ' '){
    *custs = (*custs)*10 + chartoint(CC);
    ADV();
  }
  ADV(); IgnoreBlank();
  *Add = 0;
  while (CC != ' '){
    *Add = (*Add)*10 + chartoint(CC);
    ADV();
  }
  IgnoreBlank();
  ADV(); IgnoreBlank();
  ADV(); IgnoreBlank();
  
  //QUEUE

  CreateEmptyQueue(Q, 10);
  while (CC != ','){
    while (CC != '|' && CC != ','){
      XQ.NbPeople = chartoint(CC);
      ADV(); IgnoreBlank();
      XQ.WaitTime = 0;
      while (CC != ' '){
        XQ.WaitTime = XQ.WaitTime*10 + chartoint(CC);
        ADV();
      }
      ADV(); IgnoreBlank();
      XQ.Pesanan = 0;
      while (CC != ' '){
        XQ.Pesanan = XQ.Pesanan*10 + chartoint(CC);
        ADV();
      }
      ADV(); IgnoreBlank();
      XQ.star = chartoint(CC);
      ADV(); IgnoreBlank();
      AddQueue(Q,XQ);
    }
    if (CC == '|'){
      ADV(); IgnoreBlank();
    }
  }
  ADV();
  ADV(); IgnoreBlank();

  //STACK OF HAND

  CreateEmptyStackt(Hand);
  while (CC != ','){
    XS = 0;
    while (CC != ' '){
      XS = XS*10 + chartoint(CC);
      ADV();
    }
    Push(Hand, XS);
    ADV(); IgnoreBlank();
  }
  ADV();
  ADV(); IgnoreBlank();
  *Hand = Reverse(*Hand);

  //STACK OF FOOD

  CreateEmptyStackFood(Food);
  while (CC != ','){
    XF = 0;
    while (CC != ' '){
      XF = XF*10 + chartoint(CC);
      ADV();
    }
    Pushf(Food, XF);
    ADV(); IgnoreBlank();
  }
  ADV();
  ADV(); IgnoreBlank();
  *Food = Reversef(*Food);

  for (i=1; i<=4; i++){
    MakeMATRIKS(8,8,&(Elm(*R,i)));
  }
  for (i=1; i<=4; i++){
    for (j=1; j<=8; j++){
      for (k=1; k<=8; k++){
        ElmtMATRIKS(Elm(*R,i),j,k) = ' ';
      }
    }
  }
  ElmtMATRIKS(Elm(*R,Room(*L)),Absis(Point(*L)),Ordinat(Point(*L))) = 'P';
  
  (*status).WaitTime = DataUndef;
  (*status).NbTable = DataUndef;
  (*status).Kapasitas = DataUndef;
  (*status).Pesanan = DataUndef;
  (*status).PTable = MakePOINT(-999,-999);
  (*status).IsKosong = true;
  (*status).Isi = DataUndef;
  (*status).IsOrdered = false;
  
  //ARRAY TABLE
  
  MakeEmpty(tables);
  while (CC != ','){
    while (CC!=',' && CC != '|'){
      statusT = *status;
      kosong =  chartoint(CC);
      statusT.IsKosong = kosong;
      ADV(); IgnoreBlank();
      statusT.NbTable = 0;
      while (CC != ' '){
        statusT.NbTable = statusT.NbTable*10 + chartoint(CC);
        ADV();
      }
      ADV(); IgnoreBlank();
      statusT.Kapasitas = chartoint(CC);
      ADV(); IgnoreBlank();
      Absis(statusT.PTable) = chartoint(CC);
      ADV(); IgnoreBlank();
      Ordinat(statusT.PTable) = chartoint(CC);
      ADV(); IgnoreBlank();
      if (kosong == 0){
        statusT.Pesanan = 0;
        while (CC != ' '){
          statusT.Pesanan = statusT.Pesanan*10 + chartoint(CC);
          ADV();
        }
        ADV(); IgnoreBlank();
        statusT.WaitTime = 0;
        while (CC != ' '){
          statusT.WaitTime = statusT.WaitTime*10 + chartoint(CC);
          ADV();
        }
        ADV(); IgnoreBlank();
        statusT.IsOrdered = chartoint(CC);
        ADV(); IgnoreBlank();
      }
    }
    if (CC == '|'){
      ADV(); IgnoreBlank();
    }
    AddEli(tables,statusT,statusT.NbTable);
  }
  printf(",\n");
  ADV();
  ADV(); IgnoreBlank();
  CopyTab(*tables,&dummy);
  for (j=1; j<=12; j++){
    statusT = ElmtArray(*tables,j);
    if (statusT.IsKosong == 1){
      MakeEmptyTable(R,&dummy,j);
    } else{
      MakeFullTable(R,&dummy,j,XQ,statusT.Kapasitas);
    }
  }

  //ARRAY KITCHEN

  MakeEmpty(kitchen);
  statusT = *status;
  while (CC != ','){
    while (CC!=',' && CC != '|'){
      statusT.Isi = 0;
      while (CC!=' '){
        statusT.Isi = statusT.Isi*10 + chartoint(CC);
        ADV();
      }
      ADV(); IgnoreBlank();
      Absis(statusT.PTable) = chartoint(CC);
      ADV(); IgnoreBlank();
      Ordinat(statusT.PTable) = chartoint(CC);
      ADV(); IgnoreBlank();
    }
    if (CC == '|'){
      ADV(); IgnoreBlank();
    }
    if (statusT.Isi != 0){
      AddAsLastEl(kitchen,statusT);
    } else{
      *N = statusT.PTable;
    }
  }
  MakeKitchen(R,*kitchen,*N);
  ADV();
  ADV(); IgnoreBlank();
  
  //ARRAY ORDERES

  MakeEmpty(orders);
  statusT = *status;
  while (CC != ','){
    while (CC!=',' && CC != '|'){
      statusT.NbTable = 0;
      while (CC != ' '){
        statusT.NbTable = statusT.NbTable*10 + chartoint(CC);
        ADV();
      }
      ADV(); IgnoreBlank();
      statusT.Pesanan = 0;
      while (CC!=' '){
        statusT.Pesanan = statusT.Pesanan*10 + chartoint(CC);
        ADV();
      }
      ADV(); IgnoreBlank();
      statusT.WaitTime = 0;
      while (CC!=' '){
        statusT.WaitTime = statusT.WaitTime*10 + chartoint(CC);
        ADV();
      }
      ADV(); IgnoreBlank();
    }
    if (CC == '|'){
      ADV(); IgnoreBlank();
    }
    AddAsLastEl(orders,statusT);
  }
  ADV();
  ADV(); IgnoreBlank();

  FirstG(*G) = Nil;
  while (CC != ','){ 
    xp = chartoint(CC);
    ADV(); IgnoreBlank();
    yp = chartoint(CC);
    ADV(); IgnoreBlank();
    Point(A) = MakePOINT(xp,yp);
    Room(A) = chartoint(CC);
    ADV(); IgnoreBlank();
    xp = chartoint(CC);
    ADV(); IgnoreBlank();
    yp = chartoint(CC);
    ADV(); IgnoreBlank();
    Point(B) = MakePOINT(xp,yp);
    Room(B) = chartoint(CC);
    ADV(); IgnoreBlank();
    CreatePintu(G,A,B,CC);
    ADV(); IgnoreBlank(); 
  }
  ADV(); IgnoreBlank();
  ADV(); IgnoreBlank();

  //fclose(f);

  LoadTree(Resep);
}