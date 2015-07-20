/*
 * =====================================================================================
 *
 *       Filename:  sudoku.h
 *
 *    Description:  header file for sudoku.c
 *
 *        Version:  1.0
 *        Created:  06/24/2015 12:10:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ahmed Abd-El Mawgood (oddcoder), Ahmedsoliman0x666@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
extern int solve (char puzzle[][9]);
extern void fill(char puzzle[][9]);
extern void digEvil (char puzzle[][9]);
