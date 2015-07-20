/*
 * =====================================================================================
 *
 *       Filename:  sudoku.c
 *
 *    Description:  library for handling basic sudoku generators and solvers
 *
 *        Version:  1.0
 *        Created:  06/24/2015 12:04:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ahmed Abd-El Mawgood (oddcoder), Ahmedsoliman0x666@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include "sudoku.h"
static int comp(const void *a, const void *b){
    // this functuion is passed an an argument to qsort to suduku row or 
    // line in ascending order this is usefull to look for dublicates
    return ( *(char*)a - *(char*)b );

}
static int testing( char puzzle[][9],int i,int j ){
    //this function looks for dublicates by sorting a row or colomn or block
    //and looking for 2 adjacent numbers with the same value
    int x,k=i/3*3+3,l=j/3*3+3;
    char unit[9];
    for(x=0;x<9;x++) unit[x] = puzzle[i][x];
    qsort(unit,9,sizeof(char),comp);
    for(x=0;unit[x]==0;x++);
    for(;x<9;x++) if(unit[x] == unit[x-1]) return 1;
    for(x=0;x<9;x++) unit[x] = puzzle[x][j];
    qsort(unit,9,sizeof(char),comp);
    for(x=0;unit[x]==0;x++);
    for(;x<9;x++) if(unit[x] == unit[x-1]) return 1;
    x=0;
    for(i = i/3*3,j = j/3*3;i<k;i++){
        for(;j<l;j++){
            unit[x] = puzzle[i][j];
            x++;
        }
        j-=3;
    }
    qsort(unit,9,sizeof(char),comp);
    for(x=0;unit[x]==0;x++);
    for(;x<9;x++) if(unit[x] == unit[x-1]) return 1;
    return 0;
}

extern int solve(char puzzle[][9]){
    // this function solves a 9x9 puzzle by backtracking
    char map[9][9];
    int i,j;
    for (i=0;i<9;i++) for(j=0;j<9;j++){
        if(puzzle[i][j]!=0) map[i][j] = 1 ;
        else map[i][j] = 0;
        }
    for(i=0;i<9;i++) for(j=0;j<9;j++){
        if (map[i][j]) continue;
        do{
greater9:if(puzzle[i][j]>9){
             puzzle[i][j] =0;
             do{
                 if(j==0){
                     if (i==0) return 1;
                     j=9;
                     i--;
                 }
                 j--;
             }while(map[i][j] ==1);
         }
         puzzle[i][j]++;
         if (puzzle[i][j] >9) goto greater9;
        }while(testing(puzzle,i,j)!=0);
    }
    return 0;
}
extern void fill(char puzzle[][9]){
    int i,j,counter;
    for(i=0;i<9;i++)for(j=0;j<9;j++)puzzle[i][j]=0;
    srand(time(NULL));
    for(counter=0;counter<11;counter++){
        do{
            i = rand()%9;
            j = rand()%9;
          }while(puzzle[i][j] !=0);
        
        do{
           puzzle[i][j] = rand()%9+1;
        }while(testing(puzzle,i,j)!=0);
    }
}
static int solveConstrain(char constpuzzle[][9], int fixedi, int fixedj, int val){
    char map[9][9],puzzle[9][9];
    int i,j;
    for (i=0;i<9;i++) for(j=0;j<9;j++){
        puzzle[i][j] = constpuzzle[i][j];
        if(puzzle[i][j]!=0) map[i][j] = 1 ;
        else map[i][j] = 0;
        }
    for(i=0;i<9;i++) for(j=0;j<9;j++){
        if (map[i][j]) continue;
        do{
greater9:if(puzzle[i][j]>9){
             puzzle[i][j] =0;
             do{
                 if(j==0){
                     if (i==0) return 1;
                     j=9;
                     i--;
                 }
                 j--;
             }while(map[i][j] ==1);
         }
         puzzle[i][j]++;
         if(puzzle[fixedi][fixedj]==val) puzzle[fixedi][fixedj]++;
         if (puzzle[i][j] >9) goto greater9;
        }while(testing(puzzle,i,j)!=0);
    }
    return 0;

}
extern void digEvil (char puzzle[][9]){
    int i,j,upperj[9] = {0},upperi[9]={0};
    for(i=0;i<9;i++){
            srand(time(NULL));
            int randupperi = rand()%4+4;
            int randupperj = rand()%4+4;
            for(j=0;j<9;j++){
                if(upperi[i]>randupperi || upperj[j]>randupperj) continue;
                int temp = puzzle[i][j];
                puzzle[i][j] =0;
                if(solveConstrain(puzzle,i,j,temp)==0){
                    puzzle[i][j]=temp;
                }
                else {
                    puzzle[i][j] = 0;
                    upperi[i]++;
                    upperj[j]++;
                }
            }
    }

}
