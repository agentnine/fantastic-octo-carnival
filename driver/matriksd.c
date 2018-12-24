/* 
 * File:   matriksd.c
 * Author: cisituplusnobel
 *
 * Created on November 26, 2018, 4:40 AM
 */

/*File Driver ADT MATRIKS*/

#include "../include/matriks.h"
#include <stdio.h>

int main(){
    //Kamus
    MATRIKS M,MCopy;
    int Bar,Kol;
    int X;
    int i,j,k;

    //Algoritma
    scanf("%d",&Bar);
    scanf("%d",&Kol);
    MakeMATRIKS(Bar,Kol,&M);
    MakeMATRIKS(Bar,Kol,&MCopy);
    for (i=1; i<=4; i++){
        for (j=1; j<=8; j++){
            for (k=1; k<=8; k++){
                ElmtMATRIKS(M,j,k) = 'X';
            }
        }
    }
    TulisMATRIKS(M);
    printf("\n");
    CopyMATRIKS(M,&MCopy);
    TulisMATRIKS(MCopy);
    printf("\n");
    return 0;
}