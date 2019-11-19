#ifndef _HUFFTABLE_
#define _HUFFTABLE_


typedef struct HUFFMAN_TABLE *pHUFFMAN_TABLE;
typedef struct HUFFMAN_TABLE **ppHUFFMAN_TABLE;
typedef struct HUFFMAN_TABLE{
	char ch;
	char * code;
}HUFFMAN_TABLE;

void _zero_to_code(char * code);
void _delete_last(char *code);
void _one_to_code(char * code);
void mk_strcpy(char * target, char* code);
void mk_hufftable(pNODE  node, ppHUFFMAN_TABLE Htable, int * forH, char * code);
ppHUFFMAN_TABLE mk_huffcode(pTWOREE  tree, char * line);
void search_hufftree(pNODE * node, char ch, char * code);
#endif