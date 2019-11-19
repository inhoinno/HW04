/* make huffman code with huffman tree we already created. */

#include "frequency_table.h"
#include "Huffman_Tree.h"
#include "Huffman_table.h"
void _zero_to_code(char * code){
	int i = 0;
	for (i = 0; code[i] != '\0'; i++);
	//code[i] == '\0'
	code[i] = '0';
	code[i + 1] = '\0';
	return;
}
void _delete_last(char *code){
	int i = 0;
	for (i = 0; code[i] != '\0'; i++);
	//code[i] = '\0';
	code[i - 1] = '\0';
	return;
}
void _one_to_code(char * code){
	int i;
	for (i = 0; code[i] != '\0'; i++);
	code[i] = '1';
	code[i + 1] = '\0';
	return;
}
void mk_strcpy(char * target, char* code){
	int i = 0;
	for (i = 0; code[i] != '\0'; i++){
		target[i] = code[i];
	}
	target[i] = '\0';
	return;


}
void mk_hufftable(pNODE  node, HUFFMAN_TABLE ** Htable, int * forH, char * code){
	//BACK TRACKING ALGORITHM.?......and   recursive
	if (node->left == NULL && node->right == NULL){
		//leaf node
		char* hufcode = (char *)malloc(sizeof(char) * 128);
		mk_strcpy(hufcode, code);
		int k = *(forH);
		Htable[k]->ch = node->key_ch;
		Htable[k]->code = hufcode;
		*forH += 1;
		return;

	}
	//so it is not leaf node..
	//code += 0
	_zero_to_code(code);
	mk_hufftable(node->left, Htable, forH, code);
	_delete_last(code);
	_one_to_code(code);
	mk_hufftable(node->right, Htable, forH, code);
	_delete_last(code);
	return;
	//sudo
	//recursive
	// if this is leaf node, 
	//then mark down code and char to HUFFTABLE
	//go left code+0
	// code -0
	//go right code+1

}
ppHUFFMAN_TABLE mk_huffcode(pTWOREE tree, char * line){
	//번호 주기 001 어떻게 할래???????
	//in linear list. 
	int i;
	NODE * tnode = tree->root;
	HUFFMAN_TABLE ** huffman_table = (HUFFMAN_TABLE**)malloc(sizeof(HUFFMAN_TABLE *)*(tree->size + 1));
	for (i = 0; i<tree->size + 1; i++){
		huffman_table[i] = (HUFFMAN_TABLE*)malloc(sizeof(HUFFMAN_TABLE) * 1);
	}
	//a23 b12 c7 d6 e5 f4
	int index = 1;
	char * ptr = malloc(sizeof(char) * 32);
	ptr[0] = '\0';
	mk_hufftable(tnode, huffman_table, &index, ptr);
	free(ptr);
	huffman_table[0]->ch = (char)tree->size;
	for (i = 1; i < tree->size + 1; i++){
		printf(" %c : %s \n", huffman_table[i]->ch, huffman_table[i]->code);
	}
	return huffman_table;
}


void search_hufftree(pNODE  node, char ch, char * code){
	//BACK TRACKING ALGORITHM.?......and   recursive
	if (node->left == NULL && node->right == NULL){
		if (node->key_ch == ch){
			//find key
		}
		else{ return; }
	}
	//so it is not leaf node..
	//code += 0
	_zero_to_code(code);
	search_hufftree(node->left, ch, code);
	_delete_last(code);
	_one_to_code(code);
	search_hufftree(node->right, ch, code);
	_delete_last(code);
	return;
	//sudo
	//recursive
	// if this is leaf node, 
	//then mark down code and char to HUFFTABLE
	//go left code+0
	// code -0
	//go right code+1

}