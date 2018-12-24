/* 
 * File:   queued.c
 * Author: cisituplusnobel
 *
 * Created on November 26, 2018, 4:40 AM
 */

/*FILE DRIVER ADT QUEUE.H*/

#include "../include/queue.h"
#include <stdio.h>


int main(){
    //Kamus
    Queue Q;
    infotype X;
    int MaxQ = 10;
    //Algoritma
    CreateEmptyQueue(&Q,MaxQ);
    printf("IsEmptyQueue(Q) = %d",IsEmptyQueue(Q));
    printf("IsFullQueue(Q) = %d",IsFullQueue(Q));
    X.star = true;
    X.WaitTime = 10;
    X.NbPeople = 2;
    AddQueue(&Q,X);
    printf("%d\n",Cust(Q,1));
    printf("%d\n",WT(Q,1));
    for (int i = 2; i <= 10;i ++){
        X.star = false;
        X.WaitTime = 10;
        X.NbPeople = 3;
        AddQueue(&Q,X);
    }
    PrintQueue(Q);
    DelEliQueue(&Q,1,&X);
    while(!IsEmptyQueue(Q)){
        DelQueue(&Q,&X);
    }
    if (IsEmptyQueue(Q))
        printf("Queue Q sekarang kosong !\n");
    return 0;
}