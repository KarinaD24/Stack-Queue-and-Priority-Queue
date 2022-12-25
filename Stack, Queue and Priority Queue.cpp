#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	
	Node *next, *previous;
} *top, *first, *last;

Node *createNode(int num){
	Node *temp = (Node*) malloc(sizeof(Node));
	
	temp->num = num;
	temp->next = temp->previous = NULL;
	
	return temp;
}

// stack
void insert_stack(int num){
	Node *temp = createNode(num);
	
	if(!top){ // kalau tidak ada node
		top = temp;
	}
	else{
		top->previous = temp;
		temp->next = top;
		top = temp;
	}
}

void delete_stack(){
	if(!top){ // kalau tidak ada node
		return;
	}
	else if(top->next == NULL){ // kalau ada 1 node
		free(top);
		top = NULL;
	}
	else{
		Node *newTop = top->next;
		top->next = newTop->previous = NULL;
		free(top);
		top = newTop;
	}
}

void display_stack(){
	Node *current = top;
	
	printf("Stack now\n");
	
	while(current){
		printf("%d\n", current->num);
		current = current->next;
	}
	printf("NULL\n");
}

// queue
void insertQ(int num){
	Node *temp = createNode(num);
	
	if(!first){ // kalau tidak ada node
		first = last = temp;
	}
	else{
		last->next = temp;
		temp->previous = last;
		last = temp;
	}
}

void deleteQ(){
	if(!first){ // kalau tidak ada node
		return;
	}
	else if(first == last){ // kalau ada 1 node
		first = last = NULL;
	}
	else{
		Node *newFirst = first->next;
		first->next = newFirst->previous = NULL;
		free(first);
		first = newFirst;
	}
}

void displayQ(){
	Node *current = first;
	
	printf("The queue now\n");
	
	while(current){
		printf("%d->", current->num);
		current = current->next;
	}
	printf("NULL\n");
}

// priority queue
void insert_priorityQ(int num){
	Node *newNode = createNode(num);
	
	if(!first){
		first = last = newNode;
	}
	else if(num > first->num){
		newNode->next = first;
		first->previous = newNode;
		first = newNode;
	}
	else if(num < last->num){
		last->next = newNode;
		newNode->previous = last;
		last = newNode;
	}
	else{
		Node *current = first;
		
		while(num < current->num){
			current = current->next;
		}
		
		newNode->next = current;
		newNode->previous = current->previous;
		current->previous->next = newNode;
		current->previous = newNode;
	}
}

void delete_priorityQ(){
	if(!first){ // kalau tidak ada node
		return;
	}
	else if(first == last){ // kalau ada 1 node
		first = last = NULL;
	}
	else{
		Node *xFirst = first->next;
		first->next = xFirst->previous = NULL;
		free(first);
		first = xFirst;
	}
}

void display_priorityQ(){
	Node *current = first;
	
	printf("The priority queue now\n");
	
	while(current){
		printf("%d->", current->num);
		current = current->next;
	}
	printf("NULL\n");
}

int main(){
	
	puts("[STACK]");
	insert_stack(23);
	insert_stack(13);
	insert_stack(21);
	insert_stack(3);
	insert_stack(94);
	insert_stack(1);
	display_stack();
	
	printf("\n// after removing the top node\n");
	delete_stack();
	display_stack();
	
	puts("");
	
	puts("[QUEUE]");
	insertQ(100);
	insertQ(12);
	insertQ(78);
	insertQ(99);
	insertQ(23);
	displayQ();
	
	puts("");
	
	printf("// after removing the first node\n");
	deleteQ();
	displayQ();
	
	puts("");
	
	puts("[PRIORITY QUEUE]");
	
	insert_priorityQ(11);
	insert_priorityQ(22);
	insert_priorityQ(33);
	insert_priorityQ(44);
	insert_priorityQ(55);
	display_priorityQ();
	
	puts("");
	
	printf("// after removing the first node\n");
	delete_priorityQ();
	delete_priorityQ();
	display_priorityQ();
	
	puts("");
	
	return 0;
}
