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
		switch(__commands(ch)){
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
				printf("LinkedList [ ");
				while (tmp->next!=_tail){
					printf("%s ", tmp->data);
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

int __commands(char ch[]){
	if (strcmp(ch, "add")==0)
		return 1;
	else if (strcmp(ch,"del")==0)
		return 2;
	else if (strcmp(ch,"list")==0)
		return 3;
	else if (strcmp(ch,"next")==0)
		return 4;
	else if (strcmp(ch,"prev")==0)
		return 5;
	else if (strcmp(ch,"move")==0)
		return 6;
	else if (strcmp(ch,"play")==0)
		return 7;
	else if (strcmp(ch,"clear")==0)
		return 8;
	else if (strcmp(ch,"quit")==0)
		return 9;
	else if (strcmp(ch,"load")==0)
		return 10;
	else if (strcmp(ch,"save")==0)
		return 11;
	else 
		return 12;
}
