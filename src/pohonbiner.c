/* Kelompok    : CisituPlusNobel
/* File        : pohonbiner.c */
/* Tanggal     : 29 Oktober 2018 */

#include "../include/pohonbiner.h"


/***********************ADT POHON BINER********************************/
/*** Konstruktor ***/
void Allocate (paddress *P)
{
	//Kamus Lokal
	
	//Algoritma
	*P =(paddress) malloc(sizeof(node));
}

BinTree Tree (int A, BinTree L, BinTree R)
//Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil
//Menghasilkan pohon kosong (NilTree) jika alokasi gagal
{
	//Kamus Lokal
	paddress P;
	//Algoritma
	Allocate (&P);
	if (P!=NilTree) {
		Akar(P) = A;
		Left(P) = L;
		Right(P) = R;
	}
	return P;
}
void MakeTree (int Akar, BinTree L, BinTree R, BinTree *P)
//I.S. Sembarang 
//F.S. Menghasilkan sebuah pohon P 
//Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil 
//Menghasilkan pohon P yang kosong (NilTree) jika alokasi gagal 
{
	//Kamus Lokal
	
	//Algoritma
	Allocate(P);
	if (*P!=NilTree) {
		Akar(*P)=Akar;
		Left(*P) = L;
		Right(*P) = R;
	} 
}
void LoadTree(BinTree *P)
/* Membaca Kode Resep yang ada pada file eksternal */
{	
	START("../pita/pitaresep.txt");
	BuildTree(P);
}
void BuildTree (BinTree *P)
//Membentuk sebuah pohon biner P dari pita karakter yang dibaca }
//I.S. Pita berisi "konstanta" pohon dalam bentuk prefix.
//Memori pasti cukup, alokasi pasti berhasil. }
//F.S. P dibentuk dari ekspresi dalam pita }
{
	//Kamus Lokal
	char Num[256];
	int i;
	//Algoritma
	ADV();
	if (CC==')')
		(*P)=NilTree;
	else {
		Allocate(P);
		for (i=0; i<256; i++)
			Num[i] = 0;
		i = 0;
		while ((CC !='(')&&(CC != ')')) {
			Num[i] = CC;
			ADV();
			i++;
		}
		Akar(*P) = atoi(Num);
		BuildTree(&Left(*P));
		BuildTree(&Right(*P));
	}
	ADV();
}

/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (BinTree P)
//Mengirimkan true jika P adalah pohon biner kosong
{
	//Kamus Lokal
	
	//Algoritma
	return (P==NilTree);
}
boolean IsOneElmt (BinTree P)
//Mengirimkan true jika P adalah pohon biner tidak kosong dan
//hanya memiliki 1 elemen
{
	//Kamus Lokal
	
	//Algoritma
	return ((!IsTreeEmpty(P))&&(IsTreeEmpty(Left(P)))&&(IsTreeEmpty(Left(P))));
}
boolean IsUnerLeft (BinTree P)
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon unerleft: hanya mempunyai subpohon kiri
{
	//Kamus Lokal
	
	//Algoritma
	return ((Right(P) == NilTree) && (Left(P) != NilTree));
}
boolean IsUnerRight (BinTree P)
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon unerright: hanya mempunyai subpohon kanan
{
	//Kamus Lokal
	
	//Algoritma
	return ((Right(P) != NilTree) && (Left(P) == NilTree));
}
boolean IsBiner (BinTree P)
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon biner: mempunyai subpohon kiri dan subpohon kanan
{
	//Kamus Lokal
	
	//Algoritma
	return ((Right(P) != NilTree) && (Left(P) != NilTree));
}

/*** Traversal ***/
void PrintPreorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	//Kamus Lokal
	
	//Algoritma
	if (P!=NilTree)  {
		printf("%d\n", Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
}
void PrintInorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	//Kamus Lokal
	
	//Algoritma
	if (P!=NilTree)  {
		PrintInorder(Left(P));
		printf("%d\n", Akar(P));
		PrintInorder(Right(P));
	}
}
void PrintPostorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan
//akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	//Kamus Lokal
	puts(bahan[Akar(P)]);
	//Algoritma
	if (P!=NilTree)  {
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d\n", Akar(P));
	}
}
void ShowBranch (BinTree P)
/* Menunjukkan alur dari semua cabang pohon biner */
{
	//Kamus
	int Slash[100]; //Index yang menyimpan posisi tempat mencetak '|'
	//Algoritma
	for (int i = 0;i < 100; i++)
		Slash[i] = 0;
	PrintTree (P, 7, 5,Slash);
}
void PrintBranch(int h, int * ArrSlash)
/* Fungsi Pembantu PrintTree() */
{
	for (int i = 1; i < h; i++){
		boolean found = false;
		int j = 0;
		while ((!found) && (j < 100)) {
			if ( ArrSlash[j] == i)
				found = true;
			else
				j += 1;
		}
		if (found)
			printf("|");
		else
			printf(" ");
	}
}
void PrintTree (BinTree P, int dh, int hc, int * ArrSlash)
//I.S. P terdefinisi, h adalah jarak indentasi
//F.S. Semua simpul P sudah ditulis dengan indentasi
{
	//Kamus Lokal
	int i,j;
	int slashtemp = hc + dh/2;
	//Algoritma
	if (!IsTreeEmpty(P)) {
		if (Akar(P) == 1){
			for (int k = 1;k < dh;k++)
				printf(" ");
		}
		printf("(%d)", Akar(P));
		puts(bahan[Akar(P)]);
		if (!IsTreeEmpty(Left(P))) {
			PrintBranch(slashtemp,ArrSlash);
			i = 0;
			while ((ArrSlash[i] != 0) && (ArrSlash[i] != slashtemp)){
				i += 1;
			}
			if(ArrSlash[i] == 0){
				ArrSlash[i] = slashtemp;
			}
			printf("|");
			for (int j = 1; j < dh/2; j++){
				printf("-");
			} 
			printf(">");
			j = 1;
			PrintTree(Left(P), dh, hc+dh, ArrSlash);
		}
		if (!IsTreeEmpty(Right(P))) {
			PrintBranch(slashtemp,ArrSlash);
			i = 0;
			while ((ArrSlash[i] != 0) && (ArrSlash[i] != slashtemp)){
				i += 1;
			}
			if(ArrSlash[i] == 0){
				ArrSlash[i] = slashtemp;
			}
			printf("|");
			for (j = 1; j < dh/2; j++){
				printf("-");
			} 
			printf(">");
			j = 0;
			/*Delete "|" setelah melewati cabang kanan */
			while (ArrSlash[j] != 0){
				if (ArrSlash[j] == slashtemp){
					ArrSlash[j] = -999;
				}
				j += 1;
			}	
			PrintTree(Right(P), dh, hc+dh, ArrSlash);
		}
	}
}
/*** Searching ***/

//BinTree SearchPBCode (BinTree P, int X)
/* Mencari dan mengembalikan nilai alamat akar tempat X ditemukan dalam P */
/*{
	//Kamus Lokal
	BinTree PTempA,PTempB;
	//Algoritma
	if (IsTreeEmpty(P)){
		return NilTree;
	}
	else{
		if (X == Akar(P)){
			return P;
		}
		else{
			PTempA = SearchPBCode(Left(P),X);
			if (PTempA == NilTree){
				PTempB = SearchPBCode(Right(P),X);
				return PTempB;
			}
			else{
				return PTempA;
			}
		}
	}
}*/
boolean SearchPB (BinTree P, int X)
//Mengirimkan true jika ada node dari P yang bernilai X
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P)) {
		return false;
	}
		if (X==Akar(P)) {
			return true;
		}
		else {
			return (SearchPB(Left(P), X) || SearchPB(Right(P), X));
		}
}
/*** Fungsi-Fungsi Lain ***/
int NbElmtPB (BinTree P)
//Mengirimkan banyaknya elemen (node) pohon biner P
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		return 1+NbElmtPB(Left(P))+NbElmtPB(Right(P));
	}
}
int NbDaun (BinTree P)
//Mengirimkan banyaknya daun (node) pohon biner P
{
	//Kamus Lokal
	
	//Algoritma
	if ((Left(P)==NilTree)&&(Right(P)==NilTree)) {
		return 1;
	}
	else {
		if ((Left(P)!=NilTree)&&(Right(P)==NilTree)) {
			return NbDaun(Left(P));
		}
		else if ((Left(P)==NilTree)&&(Right(P)!=NilTree)) {
			return NbDaun(Right(P));
		}
		else if ((Left(P)!=NilTree)&&(Right(P)!=NilTree)) {
			return NbDaun(Left(P))+NbDaun(Right(P));
		}
	}
}
boolean IsSkewLeft (BinTree P)
//Mengirimkan true jika P adalah pohon condong kiri 
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P))
		return false;
	else {
		if (IsOneElmt(P)) {
			return true;
		}
		else 
			if (IsUnerLeft(P)) {
				return IsSkewLeft(Left(P));
			}
			else {
				return false;
			}
		}
}
boolean IsSkewRight (BinTree P)
//Mengirimkan true jika P adalah pohon condong kiri
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P))
		return false;
	else {
		if (IsOneElmt(P)) {
			return true;
		}
		else 
			if (IsUnerRight(P)) {
				return IsSkewRight(Right(P));
			}
			else {
				return false;
			}
		}
}
int Level (BinTree P, int X)
//Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner
//P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }
{
	//Kamus Lokal
	
	//Algoritma
	if (X==Akar(P)){
		return 1;
	}
	else 
		if (SearchPB(Left(P), X)) {
			return 1+Level(Left(P), X);
		}
		else {
			return 1+Level(Right(P), X);
		}
}
/*** Operasi lain ***/
void AddDaunTerkiri (BinTree *P, int X)
//I.S. P boleh kosong 
//F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri
{
	//Kamus Lokal
	paddress Pk;
	//Algoritma
	if (IsTreeEmpty(*P)) {
		printf("kosong\n");
		Allocate(P);
		if(P == NilTree) printf("kosong\n");
		Akar (*P) = X;
	}
	else {
		if (IsTreeEmpty(Left(*P))) {
			Allocate(&Pk);
			Left(*P) = Pk;
			Akar (Pk) = X;
		}
		else {
			AddDaunTerkiri(&Left(*P), X);
		}
	}
}
void AddDaun (BinTree *P, int X, int Y, boolean Kiri)
//I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P 
//F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
//sebagai anak Kanan X (jika Kiri = false) 
{
	//Kamus Lokal
	paddress Pk;
	//Algoritma
	if (X==Akar(*P)) {
		Allocate(&Pk);
		Akar(Pk) = Y;
		if (Kiri) {
			Left(*P) = Pk;
		}
		else {
			Right(*P) = Pk;
		}
	}
	else {
		if (SearchPB(Left(*P), X)) {
			AddDaun(&Left(*P), X, Y, Kiri);
		}
		else {
			AddDaun(&Right(*P),X,Y,Kiri);
		}
	}
}
void DelDaunTerkiri (BinTree *P, int *X)
//I.S. P tidak kosong 
//F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
//disimpan pada daun terkiri yang dihapus 
{
	//Kamus Lokal
	
	//Algoritma
	if (Left(*P)==NilTree) {
		if (Right(*P)==NilTree) {
			(*X) = Akar(*P);
			(*P) = NilTree;
			free(*P);
		}
		else {
			DelDaunTerkiri(&Right(*P), X);
		}
	}
	else {
		DelDaunTerkiri(&Left(*P), X);
	}
}
void DelDaun (BinTree *P, int X)
//I.S. P tidak kosong, X adalah salah satu daun 
//F.S. Semua daun bernilai X dihapus dari P 
{
	//Kamus Lokal
	
	//Algoritma
	if ((X==Akar(*P))&&(IsOneElmt(*P))) {
		free(*P);
	}
	else {
		if (SearchPB(Left(*P), X)) {
			DelDaun(&Left(*P), X);
		}
		if (SearchPB(Right(*P), X)) {
			DelDaun(&Right(*P), X);
		}
	}
}

/*** Balanced tree ***/
BinTree BuildBalanceTree (int n)
//Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca
{
	//Kamus Lokal
	paddress P;
	int nL, nR;
	int X;
	BinTree R, L;
	//Algoritma
	if (n==0) {
		return NilTree;
	}
	else {
		scanf("%d", &X);
		Allocate(&P);
		if (P!=NilTree) {
			Akar(P) = X;
			nL = n/2; nR = n-nL-1;
			L = BuildBalanceTree(nL);
			R = BuildBalanceTree(nR);
			Left(P) = L; 
			Right(P) = R;
		}
		return P;
	}
}
/*** Binary Search Tree ***/
boolean BSearch (BinTree P, int X);
//Mengirimkan true jika ada node dari P yang bernilai X

BinTree InsSearch (BinTree P, int X)
//Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. 
//Belum ada simpul P yang bernilai X.
{
	//Kamus Lokal
	BinTree Pout;
	
	//Algoritma
	if (IsTreeEmpty(P)) {
		MakeTree(X, NilTree, NilTree, &Pout);
	}
	else {
		if (X>Akar(P)) {
			Pout = InsSearch(Right(P), X);
		}
		else if (X<Akar(P)) {
			Pout = InsSearch(Left(P),X);
		}
	}
	return Pout;
}
void DelBtree (BinTree *P, int X)
//I.S. Pohon P tidak kosong 
//F.S. Nilai X yang dihapus pasti ada 
//Sebuah node dengan nilai X dihapus 
{
	//Kamus Lokal
	paddress q;
	//Algoritma
	if (X<Akar(*P)) {
		DelBtree(&Left(*P), X);
	}
	else if (X>Akar(*P)) {
		DelBtree(&Right(*P),X);
	}
	else if (X==Akar(*P)) {
		q = Tree(Akar(*P), Left(*P), Right(*P));
		if (Right(q) == NilTree) {
			(*P) = Left(q);
		}
		else if (Left(q)==NilTree) {
			(*P) = Right(q);
		}
		else {
			DelNode(&Left(q));
			free(q);
		}
	}
}


void DelNode (BinTree *P) {
	//Kamus Lokal
	paddress q;
	//Algoritma
	if (Right(*P)!=NilTree) {
		DelNode(&Right(*P));
	}
	else {
		q = *P;
		*P = Left(*P);
	}
}


//Driver
/*
int main(){
	//kamus
	BinTree Resep;
	//algoritma
	LoadTree(&Resep);
	ShowBranch(Resep);
	return 0;
}*/