/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/22/2015 06:24:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ahmed Abd-El Mawgood (oddcoder), Ahmedsoliman0x666@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "sudoku.h"
int main(){
    char puzzle [9][9];
    int i,j;
//    for(i=0;i<9;i++)for(j=0;j<9;j++){while((puzzle[i][j]=getchar())=='\n');puzzle[i][j]-='0';}
    fill(puzzle);
    solve(puzzle);
    digEvil(puzzle);
    //printing
    for (i=0;i<9;i++){
    for(j=0;j<9;j++) printf("%i ",puzzle[i][j]);
    puts("");
    }   
    return 0;
}
