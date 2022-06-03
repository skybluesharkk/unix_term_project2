#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
//#include "node.h"
//#include "linkedlist.h"
//#include "textfilewriter.h"

int main(){
	
	int a,b;
	scanf("%d", &a);
	char _tmp_data[100];
	char new_data[10][100];
	append(100,_tmp_data);
	for (int i=0;i<a;i++){
		scanf("%s", new_data[a-i-1]);
		append_left(100, new_data[a-i-1]);
	}

	scanf("%d", &b);
	for (int j=0;j<b;j++){
				
		char ch[30];
		scanf("%s", &ch);
		__commands(ch);
		Node* s = _cur_node;
		switch(__cur_node (ch)){
			case 1:{
				char title[100];
				scanf("%s",title);
				append_left(100, title);
				break;
			       }
			case 2:
				printf("this is commands del 2\n");	
			        break;
			case 3:{
				Node *tmp;
				tmp = _head->next;
				printf("LinkedList [");
				while (tmp->next!=_tail){
					printf("%s", tmp->data);
					tmp = tmp->next;
				}
				printf("]\n");
				break;
			       }
			case 4:
			       {
			       	next();
				break;
			       }
			case 7:{
				printf("%s", s->next->data);
				printf(" is now playing!");
				break;
			       }
			case 12:
			       printf("It is the wrong command. \n");
				break;
		}
	}
}
