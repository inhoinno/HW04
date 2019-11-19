/*with huff man table and tree we decode string that we input*/

#include "Hdecode.h"

char * decode_string(HUFFMAN_TABLE ** Htable ,char * line);
char * decode_HuffmanCode(TWOREE * Htree ,char * code);


char * decode_string(HUFFMAN_TABLE ** Htable ,char * line){
    char * Hcode = (char *)malloc(sizeof(char) * 1024);
    int size= atoi(Htable[0]->code)+1;
    int i=0;
    int k=0;
    int j;
    int l=0;
    char ch;
    while(ch = line[i++]){
        for(j=size-1; j > 0; ){
            if(Htable[j]->ch == ch) break;
            j--;
                //write huffman code
                // input ' '
        }
        char * ccode = Htable[j]->code;
        for(k =0; ccode[k] != '\0'; k++){
            Hcode[l++] = ccode[k];
        }
    }
    Hcode[l]='\0';
    printf("String ---> Huffman Code\n ");puts(Hcode);
    return Hcode;

}
char * decode_HuffmanCode(TWOREE * Htree ,char * code){
    char * string = (char *)malloc(sizeof(char)*256);
    NODE * tnode = Htree->root;
    int i=0,j=0; char k;
    //based on Huffman tree, we decide left 0 right 1
    //loop til code end
    //if reached leaf, then string[k] = tnode->key_ch;
    //tnode = H->root;
    //loop end
    while(k = code[i]){
        if(tnode->left == NULL && tnode->right ==NULL){
            //leaf node
            if(tnode->key_ch != '\0' && j<256){
                string[j++] = tnode->key_ch;
                tnode = Htree->root;
                continue;
                } else if (tnode->key_ch == '\0'){
                    printf("Wrong Huffman Code. leaf node does not have charactor\n"); exit(-1);
                } else{
                    printf("Too much string.. MAX 256\n"); exit(-1);
                }
        }
        else if(k == '1'){
            tnode = tnode->right;
        }
        else {
            tnode = tnode->left;
        }
        i++;
    }
    string[j] ='\0'
    printf("HuffmanCode ----> String \n ");puts(string);
    return string;
}