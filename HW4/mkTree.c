//we have table already so we have to make tree based on the table
//1. make tree using ARRAY
//2. make tree using LINEAR LIST

//NODE * mk_tree_ARRAY(NODE * table){
/*How to make table array to tree?*/
//NODE * arr_tree = ;
/*algorithm locates here*/
// rule number that parent node index (1) (3) = left's index/2 (2,3) (6,7).5버림ceiling.
// so you want to make heirachy , myleft = my index *2 with ceiling, myright = mindex *2 +1;
// regarding this tree is full_binary tree.

//algorithm goes down to top. leaf node to root node.
// array node must allocate pretend this is full binary tree.

//return arr_tree;}
#include "frequency_table.h"
#include "Huffman_Tree.h"
void push_back_NODE(struct NODE ** ds, struct NODE * node){
	//자료구조의 특성상 삽입이 굉장히 까다롭다.
	//-> 해결 table 을 리스트로 쓴다?

	//앞에두개를 지우고 미루는 과정에서 node를 삽입하려고 한다,
	if (ds[0]->key_cnt == 3) {
		//then special case : table has only two node
		//and temp node is parent node.
		ds[1] = node;
		ds[2] = NULL;
		ds[0]->key_cnt = 2;
		return;
	}
	//미루기
	int i;
	for (i = ds[0]->key_cnt - 1; i >= 3;){
		if (ds[i]->key_cnt < node->key_cnt){
			break; // then ds[i] -> node -> ds[i+1]
		}i--;
	}

	if (i + 1 == ds[0]->key_cnt){
		ds[ds[0]->key_cnt] = node;
		ds[0]->key_cnt++;
		ds[ds[0]->key_cnt] =NULL;
		//return ds;
	}
	else{
		//then i is inside of table 
		int j = i + 1;
		for (i = ds[0]->key_cnt - 1; i >= j; i--){
			ds[i + 1] = ds[i];
		}
		ds[j] = node;
		ds[0]->key_cnt++;
	}
	// after loop, j became node location

	// do 1pushback -> node 97
	// 4 | 45 | 52 | 97 | 
	// 2 | 97 |
	for (i = 1; i < ds[0]->key_cnt - 2; i++){
		ds[i] = ds[i + 2];
	}
	ds[i] = NULL;
	ds[0]->key_cnt -= 2; //11 -> 12 -> 10
	ds[0]->left = ds[1];
	ds[0]->right = ds[2];
	return ds;
}
struct TWOREE * mk_tree_LIST(struct NODE ** table){
	TWOREE * list_tree = (TWOREE *)malloc(sizeof(TWOREE));
	int s = table[0]->key_cnt - 1; //문자열의 문자 갯수
	list_tree->size = s; //in tree , 10개의 리프노드를 가지고 있다는 뜻
	/*algorithm here */
	NODE * Left = (NODE *)malloc(sizeof(NODE));
	NODE * Right = (NODE *)malloc(sizeof(NODE));
	int i = 1;
	/*now table
	11| 1 | 1| 2 | 4 | 6 | 7 | 8 | 8 | 10 | 11 |
	size = 10
	*/
	while (1){
		int size = table[0]->key_cnt - 1;
		//pop minimum two and add to table.
		if (size< 0){ //then table is empty
			printf("table is empty ");
			return NULL;
		}
		if (size == 1){
			//then only one left
			// 2 | 97 |
			list_tree->root = table[1];
			break;
		}
		else {
			Left = table[0]->left;
			Right = table[0]->right;
			NODE * temp = mk_node('\0', table[0]->left->key_cnt + table[0]->right->key_cnt, Left, Right);
			push_back_NODE(table, temp);
		}
	}
	return list_tree;
}

// 0 loop
//1 if table element only 1 then tree is set
//2 pop the minimum two from table.
//3 make it one node and push back(insert it)
//4 // key_cnt -- and go to //1 loop
// list_tree->root = table[1]

//++
//eax = 1;
//1 loop i =eax; i<[0].cnt && i+1< [0].cnt; i++ <- need another exception
//     1 pop 2 nodes -> how?
//     2 node1= [0].left
//     3 node2= [0].right
//     4 increase top  3, 4
//     5 now [0].left = [eax]
//     6 [0].right = [eax+1]
//     7 newnode = mk_node ('\0', left.cnt+right.cnt , node1 , node2)
//     7 push back newnode 
//     8 set [0].cnt
//     9 set eax +=2;
//2 loop end

//case 1: no node exist in table(예쁘게 트리가 완성)
//case 2: one node exist in table(트리에 추가할 노드 1개남음.)