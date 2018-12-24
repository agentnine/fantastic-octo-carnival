/* 
 * File:   mesinkatad.c
 * Author: cisituplusnobel
 *
 * Created on November 26, 2018, 4:40 AM
 */

/*FILE DRIVER ADT MESIN KATA*/

#include "../include/mesinkata.h"
#include <stdio.h>

int main(){
    //Kamus
    char* FileName;
    //Algoritma
    FileName = "pitakatadriver.txt";
    STARTKATA(FileName);
    while (!EndKata){
        for (int i = 1; i <= CKata.Length; i++)
            printf("%c",CKata.TabKata[i]);
        printf(" ");
        ADVKATA();
    }
    printf("\n");
    return 0;
}