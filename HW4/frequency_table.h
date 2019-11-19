#ifndef _FREQ_H_
#define _FREQ_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct NODE * pNODE;
typedef struct NODE ** ppNODE;
typedef struct NODE {
	char key_ch; int key_cnt;
	pNODE  left;
	pNODE  right;
}NODE; //Node
typedef struct TWOREE * pTWOREE;
typedef struct TWOREE ** ppTWOREE;
typedef struct TWOREE {
	pNODE  root;
	int size;
}TWOREE;
void sort_table_acend(NODE **);
pNODE mk_node(char, int k, pNODE vleft, pNODE vright);
int vectorFULL(ppNODE  table, int * capacity);
void push_back(ppNODE  table, int * capacity, char ch);
ppNODE  Eat_String_Return_Table(char * line);
#endif