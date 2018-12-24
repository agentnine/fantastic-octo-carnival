/* 
 * File:   pointtd.c
 * Author: cisituplusnobel
 *
 * Created on November 26, 2018, 4:40 AM
 */

/*FILE ADT DRIVER POINT*/

#include "../include/point.h"
#include <stdio.h>

int main(){
    //Kamus
    int X,Y,dx,dy;
    POINT P,dP;
    //Algoritma
    printf("X ; ");
    scanf("%d",&X);
    printf("Y ; ");
    scanf("%d",&Y);
    printf("dx ; ");
    scanf("%d",&dx);
    printf("dy ; ");
    scanf("%d",&dy);
    P = MakePOINT(X,Y);
    dP = PlusDelta(P,dx,dy);
    Geser(&P,dx,dy);
    printf("EQP(P,dP) : %d\n",EQP(P,dP));
    return 0;
}
