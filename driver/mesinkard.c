/* 
 * File:   mesinkard.c
 * Author: cisituplusnobel
 *
 * Created on November 26, 2018, 4:40 AM
 */

/*FILE DRIVER MESINKAR.C*/

#include "../include/mesinkar.h"
#include <stdio.h>

int main(){
    //KAMUS
    char* FileName;
    //ALGORITMA
    FileName = "pitadriver.txt";
    START(FileName);
    while(!EOP){
        printf("%c\n",CC);
        ADV();
    }

    return 0;
}