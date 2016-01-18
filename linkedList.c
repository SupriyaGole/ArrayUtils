#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

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
	void *value;
	if(index<0 || index>list->length){
		return NULL;
	}
	if(index>=1){
		for(int i=0;i<index-1;i++){
			if(head!=NULL){
				head = head->next;
			}
		}
		value = head->next->value;
		head->next = head->next->next;
	}
	else{
		value = head->value;
		list->first = head->next;
	}
	list->length--;
	return value;
}

int asArray(LinkedList list, void **destination, int maxElements){
	ELEMENT *ele = list.first;
	for(int i=0;i<maxElements;i++){
		if(ele!=NULL){
			destination[i]=ele->value;
		}
	}
	return maxElements;
}

LinkedList filter(LinkedList list,MatchFunc match,void *hint){
	LinkedList newList = createList();
	ELEMENT *head = list.first;
	for(int i=0;i<list.length;i++){
		if(match(hint,head->value)==1){
			add_to_list(&newList,head->value);
		}
		head = head->next;
	}
	return newList;
}

int isDivisible(void *hint,void *item){
	int Hint = *(int *)hint;
	int Item = *(int *)item;
	return Item%Hint==0;
}

LinkedList reverse(LinkedList list){
	LinkedList reverseList = createList();
	for(int i=list.length-1;i>=0;i--){
		void *ele = getElementAt(list,i);
		add_to_list(&reverseList,ele);
	}
	return reverseList;
}

void square(void *hint,void *sourceItem,void *destinationItem){
	int Hint = *(int *)hint;
	int item = *(int *)sourceItem;
	*(int *)destinationItem = pow(item,Hint);
}

void *sum(void *hint,void *previousValue,void *item){
	int previous = *(int *)previousValue;
	int Item = *(int *)item;
	*(int *)previousValue = previous+Item;
	return previousValue;
}

LinkedList map(LinkedList list,ConvertFunc convert,void *hint){
	ELEMENT *head = list.first;
	LinkedList mapper = createList();
	void *ele = calloc(list.length,sizeof(void *));
	for(int i=0;i<list.length;i++){
		add_to_list(&mapper,ele);
		ele = ele+8;
		convert(hint,head->value,(mapper.last->value));
		head = head->next;
	}
	return mapper;
}

void * reduce(LinkedList list,Reducer func,void *hint,void *initialValue){
	ELEMENT *head = list.first;
	for(int i=0;i<list.length;i++){
		if(head!=NULL){
			void *previousValue = func(hint,initialValue,head->value);
			initialValue = previousValue;
		}
		head = head->next;
	}
	return initialValue;
}

void getNextChar(void *letter){
	char next = *(char *)letter;
	int ascii = (int) next;
	ascii++;
	char new = ascii;
	*(char *)letter = new; 
}

void toLowerCase(void *str){
	char *new = (char *)str;
	char lower[10];
	for(int i=0;i<strlen(new);i++){
		lower[i] = tolower(new[i]);
	}
	*(char *)str = *lower;
}

void initializeList(LinkedList *marks_of_student){
	int number=13;
	for(int i=0;i<5;i++){
		int * num1 = (int *)malloc(sizeof(int));
		number+=10;
		*num1 = number;
		add_to_list(marks_of_student,num1);
	}
}

void initializeListOfChar(LinkedList *marks_of_student){
	for(int i=65;i<70;i++){
		char *a = (char *)malloc(sizeof(char));
		*a=i;
		add_to_list(marks_of_student,a);
	}
}

void printValue(LinkedList list){
	ELEMENT *ele = list.first;
	while(ele!=NULL){
		printf("%d\n",*(int *)ele->value);
		ele = ele->next;
	}
}

void printChar(LinkedList list){
	ELEMENT *ele = list.first;
	while(ele!=NULL){
		printf("%c\n",*(char *)ele->value);
		ele = ele->next;
	} 
}

void printString(LinkedList list){
	ELEMENT *ele = list.first;
	while(ele!=NULL){
		printf("%s\n",ele->value);
		ele = ele->next;
	}
}

