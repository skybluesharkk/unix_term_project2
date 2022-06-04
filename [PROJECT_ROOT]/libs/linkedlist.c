
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "linkedlist.h"

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

static bool isInit = false;

void init(){
	isInit = true;
	_head = malloc(sizeof(Node));
	_tail = malloc(sizeof(Node));
	_cur_node = _head;

	_head->next = _tail;
	_tail->prev = _head;
}

bool empty(){
	return _head == NULL;
}

size_t size(){
	size_t count = 0;
	Node *now = _head;

	while(now != NULL){
		now = now->next;
		count++;
	}
	return count;
}

void print(){
	Node *now = _head;
	printf("LinkedList [ ");
	while(now != NULL){
		printf("%s ", now->data);
		now = now->next;
	}
	printf("]\n");
}

void print_file(FILE* stream){
	Node *now = _head;
	fprintf(stream, "[ ");
	while(now!=NULL){
		fprintf(stream,"%s ", now->data);
		now = now->next;
	}
	fprintf(stream,"]\n");
}

void clear(){
	Node* now = NULL;
	if(empty())
		return;
	
	now = _tail;
	while(now != _head){
		now = now->prev;
		free(now->next->data);
		free(now->next);
	}
	free(now->data);
	free(now);

	_tail = NULL;
	_head = NULL;
	_cur_node = NULL;
}

Node* insert_after(Node* cur_node, Node* new_node){
	if(cur_node == _tail)
		return new_node;
	new_node->next = cur_node->next;
	new_node->prev = cur_node;
	cur_node->next = new_node;
	new_node->next->prev = new_node;

	return new_node;
}
Node* append_left(size_t n, char new_data[n]){
	Node* new = (Node *)malloc(sizeof(Node));
	new->data = new_data;
	insert_after(_head,new);
}

Node* append(size_t n, char new_data[n]){
	if(!isInit)
		init();
	Node* new = (Node *)malloc(sizeof(Node));
	new->data = new_data;
	insert_after(_tail->prev,new);
}

Node* _insert_after(Node* cur_node, size_t n, char new_data[]){

}


Node* pop_left(){

}

Node* pop(){

}

Node* delete_node(Node* cur_node){
	if(cur_node == _head || cur_node == _tail)
		return _tail;
	Node* s = cur_node->next;
	cur_node->prev->next = cur_node->next;
	cur_node->next->prev = cur_node->prev;
	free(cur_node);

	return s;
}

Node* delete_by_data(char* data){
	Node *now = _head;

	while(now != NULL){
		if(strcmp(now->data, data) == 0)
			return delete_node(now);

		now = now->next;
	}
	return NULL;
}

Node* next(){
	Node* s = _cur_node->next;
	if(_cur_node == _tail)
		s = _tail->next;
	return s;
}

Node* prev(){
	Node* s = _cur_node->prev;
	if(_cur_node == _head)
		s = _head->prev;
	return s;
}

Node* first_node(){
	return _head;
}

Node* last_node(){
	return _tail;
}

Node* get_node(size_t index){
	int count = 0;

	Node *now = _head;
	while(count != index){
		now = now->next;
		count++
	}
	return now;
}


