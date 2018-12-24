/* 
 * File:   pohonbinerd.c
 * Author: cisituplusnobel
 *
 * Created on November 26, 2018, 4:40 AM
 */

/*DRIVER header pohonbiner.h Kelompok Cisitu plus Nobel */

#include "../include/pohonbiner.h"
#include <stdio.h>

int main(){
    //Kamus
    BinTree Tree;
    //Algoritma
    LoadTree(&Tree);
    ShowBranch(Tree);
    printf("\n");
    printf("IsTreeEmpty(Tree) : %d\n",IsTreeEmpty(Tree));
    printf("IsOneElmt(Tree) : %d\n",IsOneElmt(Tree));
    printf("IsUnerRight(Tree) : %d\n",IsUnerRight(Tree));
    printf("IsUnerLeft(Tree) : %d\n",IsUnerLeft(Tree));
    printf("IsBiner(Tree) : %d\n",IsBiner(Tree));
    return 0;
}
    

