/* Kelompok    : CisituPlusNobel
/* File        : matriks.c */
/* Tanggal     : 29 Oktober 2018 */

/* *** IMPLEMENTASI DARI HEADER *** */

#include "../include/matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS(int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */ {
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrsMATRIKS(MATRIKS M)
/* Mengirimkan indeks baris terkecil M */ {
    return BrsMin;
}

indeks GetFirstIdxKolMATRIKS(MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */ {
    return KolMin;
}

indeks GetLastIdxBrsMATRIKS(MATRIKS M)
/* Mengirimkan indeks baris terbesar M */ {
    return (GetFirstIdxBrsMATRIKS(M) + NBrsEff(M) - 1);
}

indeks GetLastIdxKolMATRIKS(MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */ {
    return (GetFirstIdxKolMATRIKS(M) + NKolEff(M) - 1);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS(MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */ {
    //KAMUS LOKAL
    indeks i, j;

    //ALGORITMA
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    for (i = GetFirstIdxBrsMATRIKS(MIn); i <= GetLastIdxBrsMATRIKS(MIn); i++) {
        for (j = GetFirstIdxKolMATRIKS(MIn); j <= GetLastIdxKolMATRIKS(MIn); j++) {
            ElmtMATRIKS(*MHsl, i, j) = ElmtMATRIKS(MIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisMATRIKS(MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
 */ 
{
    //KAMUS LOKAL
    indeks i, j;

    //ALGORITMA
    for (i = GetFirstIdxBrsMATRIKS(M); i <= GetLastIdxBrsMATRIKS(M); i++) {
        for (j = GetFirstIdxKolMATRIKS(M); j <= GetLastIdxKolMATRIKS(M); j++) {
            if (j != GetLastIdxKolMATRIKS(M)) {
                printf("%c ", ElmtMATRIKS(M, i, j));
            } else if (i != GetLastIdxBrsMATRIKS(M)) {
                printf("%c\n", ElmtMATRIKS(M, i, j));
            } else {
                printf("%c", ElmtMATRIKS(M, i, j));
            }
        }
    }
}