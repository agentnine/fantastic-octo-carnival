/* 
 * File:   arrayd.c
 * Author: cisituplusnobel
 *
 * Created on November 26, 2018, 4:40 AM
 */

/*File Driver ADT Array*/
#include <stdio.h>
#include "../include/boolean.h"
#include "../include/array.h"

int main(){
    TabInt T1,T2;
    int input,ip,i;
    ElTypeArray X;
    X.WaitTime = DataUndef;
    X.Kapasitas = DataUndef;
    X.PTable = MakePOINT(-999,-999);
    X.IsKosong = true;
    X.Isi = DataUndef;
    X.IsOrdered = false;

    printf("Tester\n");
    printf("----------\n");
    MakeEmpty(&T1);
    MakeEmpty(&T2);
    while(true){
        printf("1 = Output\n2 = Is2\n3 = CopyTab\n4 = Operasi\n");
        scanf("%d",&input);
        switch(input){
            case 1:
                printf("[T1] \n");
                TulisIsiTab(T1);
                printf("\n");
                break;
            case 2:
                printf("IsEmpty(T1) = %d\n",IsEmpty(T1));
                printf("IsFull(T1) = %d\n",IsFull(T1));
                printf("NbElmtArray(T1) = %d\n",NbElmtArray(T1));
                printf("MaxNbEl(T1) = %d\n",MaxNbEl(T1));
                printf("GetFirstIdx(T1) = %d\n",GetFirstIdx(T1));
                printf("GetLastIdx(T1) = %d\n",GetLastIdx(T1));
            break;
            case 3:
                CopyTab(T1,&T2);
                printf("Hasil Copy T1\n");
                TulisIsiTab(T2);
                printf("\n");
            break;
            case 4:
                printf("1 = addlast\n2 = addeli\n3 = dellast\n4 = deleli\n5 = ubaheli\n");
                scanf("%d",&ip);
                printf("%d\n", ip);
                switch(ip){
                    case 1:
                        printf("Pesanan ; ");
                        scanf("%d", &X.Pesanan);
                        printf("NbTable ; ");
                        scanf("%d", &X.NbTable);
                        printf("Kesini\n");
                        printf("%s, %c\n", bahan[X.Pesanan],no[X.NbTable]);
                        AddAsLastEl(&T1,X);
                    break;
                    case 2:
                        printf("Pesanan ; ");
                        scanf("%d", &X.Pesanan);
                        printf("NbTable ; ");
                        scanf("%d", &X.NbTable);
                        printf("i : ");
                        scanf("%d", &i);
                        AddEli(&T1,X,i);
                    break;
                    case 3:
                        DelLastEl(&T1,&X);
                    break;
                    case 4:
                        DelEli(&T1,i,&X);
                    break;
                    case 5:
                        printf("Pesanan ; ");
                        scanf("%d", &X.Pesanan);
                        printf("NbTable ; ");
                        scanf("%d", &X.NbTable);
                        UbahEli(&T1,i,X);
                }
                printf("\n");
            break;
        }
    }
    return 0;
}