/* 
 * File:   graphd.c
 * Author: cisituplusnobel
 *
 * Created on November 26, 2018, 4:40 AM
 */

/*File driver ADT Graph*/

#include <stdio.h>
#include "../include/boolean.h"
#include "../include/graph.h"

int main(){
    Graph G1;
    int X=1;
    int input;
    int prec=1;
    int succ=2;
    adrNode HasilN;
    adrSuccNode HasilE;
    LOC asal,tujuan;
    char key;
    asal.room=1;
    tujuan.room=2;

    printf("Tester\n");
    printf("----------\n");
    while (true){
        printf("1 = SearchNode\n2 = SearchEdge\n3 = InsertNode\n4 = CreatePintu\n5 = CariEdgePintu");
        scanf("%d",&input);
        CreateGraph(X,&G1);
         CreatePintu(&G1,asal,tujuan,key);
        switch(input){
            case 1:
                HasilN=SearchNode(G1,X);
                printf("%d\n",Id(HasilN));
            break;
            case 2:
                HasilE=SearchEdge(G1,prec,succ);
                printf("%d\n",Succ(HasilE));
            break;
            case 3:
                InsertNode(&G1,X,&HasilN);
                printf("%d\n",Id(HasilN));
            break;
            case 4:
                scanf("%c\n",key);
                InsertEdge(&G1,prec,succ,asal,tujuan,key);
                HasilE=SearchEdge(G1,prec,succ);
                printf("%d\n",Succ(HasilE));
            break;
            case 5:
                CariEdgePintu(G1,asal,&tujuan,key);
                printf("%d\n",tujuan.room);
            break;
        }
    }
    return 0;
}