/* Frequency_Table to Huffman Tree */
// let a 14 b 3 c 2 d 1
//table size = 5| 1 | 2 | 3 | 14|
//Hff 001 010 00011 001 001
//그래서 [0]에는 다음 삽입 될 index의 번호를 가지고 있ㅅ븐디ㅏ.
//그래서 DS[0]에는 마지막 데이터의 인덱스 +1 의 값
// 그래서 데이터의 갯수 -1 의 값을 가지고잇습니다
//순회시에 for(i =1 i<ds[0].key_cnt; i++)
#include "frequency_table.h"
/*func that read file or String, and return vector*/
// if vector Full, realloc array
NODE * mk_node(char key_ch, int key_cnt, NODE* vleft, NODE* vright){
	NODE * tnode = (NODE *)malloc(sizeof(NODE) * 1);
	tnode->left = vleft;
	tnode->right = vright;
	tnode->key_ch = key_ch;
	tnode->key_cnt = key_cnt;
	return tnode;
}
int vectorFULL(NODE ** table, int * capacity){
	// make table capacity double. and return it
	int s = *capacity;
	int i = 0;
	if (!(table = (NODE **)realloc(table, sizeof(NODE*) * (*capacity) * 2))){ printf("Memory is Full.. \n"); exit(-30); }
	(*capacity) *= 2;
	for (i = s; i<*capacity; i++){
		table[i] = malloc(sizeof(NODE) * 1);
	}
	return;
}
/*mktree <-> pushback <-> freq_table*/
// need synchronized!
void push_back(NODE ** table, int * capacity, char ch){
	int i = 0;
	if (table[0]->key_cnt == 1) {//table is empty
		table[1] = mk_node(ch, 1, NULL, NULL);
		table[0]->key_cnt += 1;
		return;
	}
	else if (table[0]->key_cnt == *capacity) {// table if Full
		//let capacity = 6 
		// 6 | 1 | 2 | 3 | 4 | 5 |
		// ^ then 0.keyint is capacity . 
		vectorFULL(table, capacity);
	}
	//body : do push_back the node to vector(table).
	//1. just input it and no collaborate
	//2. traverse table and insert it.
	//  Answer?
	for (i = table[0]->key_cnt - 1; i >= 1; i--){
		if (table[i]->key_ch == ch){
			table[i]->key_cnt++;
			break;
		}
		else if (i == 1){
			//no such char in table
			table[table[0]->key_cnt] = mk_node(ch, 1, NULL, NULL);
			table[0]->key_cnt++;
		}
	}//sudo for 1
	//ds[0] has a location of new node.
	//ds[ds[0].key_cnt] = mk_node() 
	//ds[0].key_cnt ++ ;
	//sudo for 2
	//loop from last.
	//loop til ds[0].key_cnt -1 to 1
	//if ds[i].key_ch is equal to ch?
	//then ds[i].key_cnt ++;
	//break loop
	//else if i ==1 so no such ch in table 
	//push it in back 
	//ds[ds[0].key_cnt] = mk_node(ch, 1, NULL,NULL);
	//ds[0].key_cnt++;
	//break loop;
	//loop end.

}
NODE ** Eat_String_Return_Table(char * line){
	NODE ** freq_table = (NODE **)malloc(sizeof(NODE *) * 80); /// capacity = 30;
	int table_capa =80;
	int i = 0;
	char ch;
	for (i = 0; i<table_capa; i++){
		freq_table[i] = malloc(sizeof(NODE) * 1);
	}
	freq_table[0]->key_cnt = 1; // table 에있는 데이터 갯수 +1
	i = 0;
	while (ch = line[i]){
		push_back(freq_table, &table_capa, ch);
		i++;
	}
	/*exepcted table now*/
	/* | key =10 | 7 | 6 | 9 | 9 | 1 | 2 | 3 | 4 | 5 | */
	/*need to sort in acending order*/
	/*|key =10 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 9 | 9 |*/
	/*so we select ^ ^ [1]and [2] to minimum node of table */
	//sort the table ()
	sort_table_acend(freq_table);
	//****IDEA
	// ds[0].left = ds[1]
	// ds[0].rig2ht = ds[2]
	freq_table[0]->left = freq_table[1];
	freq_table[0]->right = freq_table[2];
	return freq_table;
	//return table.
}


 void sort_table_acend(NODE ** ds){
	 //sort table in acending order.
 int size = ds[0]->key_cnt;
 int i=1;
 bool move = false;
 int j, key;
 NODE * keynode;
 //expect N is less than 100
 // 1. quick merge
 // 2. insert
 // 3. select & bubble.

 for (i = 2; i<ds[0]->key_cnt; i++){
	 key = ds[i]->key_cnt;
	 keynode = ds[i];
	 j = i;
	 if (ds[j - 1]->key_cnt > key)
		 move = 1; //true
	 else move = 0; //false
	 while (move){
			 ds[j] = ds[j - 1];
		 j = j - 1;
		 if (j > 1 && key < ds[j - 1]->key_cnt)
			 move = 1; //true
		 else move = 0; //false
	 }
	 ds[j] = keynode;
 }
 return;


 }
/*how to make tree according to freq_table?*/
//1. Array
//2. linear list.