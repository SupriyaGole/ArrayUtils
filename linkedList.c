#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

LinkedList createList(void){
	LinkedList marks_of_students;
	marks_of_students.first = NULL;
	marks_of_students.last = NULL;
	marks_of_students.length=0;
	return marks_of_students;
}

int add_to_list(LinkedList *list,void *element){
	ELEMENT *ele  = malloc(sizeof(ELEMENT));
	ele->value = element;
	ele->next = NULL;
	if(list->first==NULL){
		list->first = ele;
		list->last = ele;
	}
	else{
		list->last->next = ele;
		list->last = ele;
	}
	list->length++;
	return list->length;
}

void *get_first_element(LinkedList list){
	if(list.first!=NULL){
		return list.first->value;
	}
	else
		return NULL;
}

void *get_last_element(LinkedList list){
	if(list.last!=NULL){
		return list.last->value;
	}
	else
		return NULL;
}
void increment(void *number){
	int element = *(int *)number;
	element++;
	*(int *)number = element; 
}

void forEach(LinkedList *list,ElementProcessor processor){
	ELEMENT *ele = list->first;
	while(ele!=NULL){
		processor(ele->value);
		ele = ele->next;
	}
}


void storeValue(LinkedList list,int *destination){
	int count=0;
	ELEMENT *ele = list.first;
	while(ele!=NULL){
		destination[count]=*(int *)ele->value;
		ele = ele->next;
		count++;
	}
}

void printValue(LinkedList list){
	ELEMENT *ele = list.first;
	while(ele!=NULL){
		printf("%d\n",*(int *)ele->value);
		ele = ele->next;
	}
}

void *getElementAt(LinkedList list,int index){
	ELEMENT *head = list.first;
	if(index>list.length)
		return NULL;
	while(index>0){
		if(head!=NULL){
			head = head->next;
		}
		index--;
	}
	return head->value;
}

int indexOf(LinkedList list,void *value){
	ELEMENT *head = list.first;
	for(int i=0;i<list.length;i++){
		if(head!=NULL){
			if(head->value==value)
				return i;			
		}
		head = head->next;
	}
	return -1;
}

void * deleteElementAt(LinkedList *list, int index){
	ELEMENT *head = list->first;
	for(int i=0;i<index-1;i++){
		if(head!=NULL){
			head = head->next;
		}
	}
	void *value = head->next->value;
	head->next = head->next->next;
	list->length--;
	return value;
}






