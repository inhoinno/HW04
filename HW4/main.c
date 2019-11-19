
#include "frequency_table.h"
#include "Huffman_Tree.h"
#include "Huffman_table.h"
#include "Hdecode.h"
#define MAX_BUF 256
int main(){
	char buf[MAX_BUF];int i = 0;
	FILE * fp = fopen("favorite.txt", "r");
	if (fp<0){ printf("file open error! \n"); exit(-1); }
	if (fgets(buf, sizeof(buf), fp) == NULL){ printf("FILE READ ERROR. donot put '/n' in file \n"); exit(-2); }
	fclose(fp);
	
	for (i = 0; buf[i] != '\0'; i++);
	if (i - 1 < 100){
		printf("Input String is less than 100. please input more\n");
		exit(-1);
	}
	printf("input size : %d \n", i - 1);
	
	//NOW BUF has string.

	NODE ** myfreq_table = Eat_String_Return_Table(buf);
	pTWOREE myhuffman_tree = mk_tree_LIST(myfreq_table);
	ppHUFFMAN_TABLE  myhuffman_table = mk_huffcode(myhuffman_tree, buf);

	printf("Origin String :\n %s\n", buf);
	char * myHuffmanCode = decode_string(myhuffman_table, buf);
	char * HuffString = decode_HuffmanCode(myhuffman_tree, myHuffmanCode);

	printf("String Compare Origin , HuffString : ");
	if (strcmp(buf, HuffString) != 0){
		printf("FALSE\n");
	}
	else {
		printf("TRUE \n");
	}
	int cnt = 0;
	
	printf("\n\n컴퓨터에서 실제 비트의 표현. \n");
	for (i = 0; buf[i] != '\0'; i++);
	printf("--+    Original     +-- 1char -> 0000 0000 --+ fixed size +---\n");
	printf("--+ Huffman encoded +-- 1char -> 00 , or 001 --+ VARIABLE size +---\n");
	printf("Actual Bits \n buf = 8 * %d = %d \n", i - 1, 8 * (i - 1));
	cnt = 8 * (i - 1);
	for (i = 0; myHuffmanCode[i] != '\0'; i++);
	printf(" HuffCode = %d\n", i-1);

	printf("----+ Compressn Rate(%) :  about %f %%  (%d / %d *100)  +------\n", (float)cnt / (i - 1) * 100, cnt, i - 1);

	free(HuffString);
	free(myHuffmanCode);
	//destroy_tree
	//destroy_hufftable
	return 0;
}