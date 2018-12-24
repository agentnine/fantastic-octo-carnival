/* 
 * File:   jamd.c
 * Author: cisituplusnobel
 *
 * Created on November 26, 2018, 4:40 AM
 */

/*Driver dari ADT JAM*/

#include "../include/jam.h"
#include <stdio.h>

int main(){
    //Kamus
    int H,M,S;
    long second;
    JAM Jam1,Jam2;

    //Algoritma
    printf("Enter Hour : ");
    scanf("%d",&H);
    printf("Enter Minute : ");
    scanf("%d",&M);
    printf("Enter Second : ");
    scanf("%d",&S);
    Jam1 = MakeJAM(H,M,S);
    printf("Tulis Jam\n");
    TulisJAM(Jam1);
    printf("\nJam to Detik = %d\n",JAMToDetik(Jam1));
    printf("Enter Selisih : ");
    scanf("%ld",&second);
    Jam2 = DetikToJAM(second);
    JAM NextJam1 = NextDetik(Jam1);
    JAM PrevJam1 = PrevDetik(Jam1);
    printf("Dikurangin Selisih Setelah ditambah satu jam : ");
    printf("%d\n",JAMToDetik(NextJam1));
    printf("Ditambahin Selisih Setellah dikurang satu jam: ");
    printf("%d\n",JAMToDetik(PrevJam1));
    return 0;
}