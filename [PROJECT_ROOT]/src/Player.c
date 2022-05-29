#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "node.h"
//#include "linkedlist.h"
//#include "textfilewriter.h"

int main(){
	
	int a,b;
	scanf("%d", &a);
	char new_data[100];
	for (int i=0;i<a;i++){
		scanf("%s", new_data);
		append(100, new_data);
	}

	scanf("%d", &b);
	for (int j=0;j<b;j++){
		char ch;
		scanf("%c", &ch);
		switch (ch){
			case 'add':
				char title[100];
				scanf("%s",title);
				append_left(100, title);
				break;
			case 'del':
				char title[100];
				scanf("%s",title);
				delete(title);
				break;
			case 'list':
				print();
				break;
			case 'next':
				next();
				break;
			case 'prev':
				prev();
				break;
		}
	}
}
