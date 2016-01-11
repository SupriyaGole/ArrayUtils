#include "linkedList.h"
#include <assert.h>
#include <stdio.h>

void test_for_create_list(){
	LinkedList marks_of_student = createList();
	assert(marks_of_student.length==0);
	assert(marks_of_student.first==NULL);
	assert(marks_of_student.last==NULL);
}

void test_for_add_to_List(){
	LinkedList marks_of_student = createList();
	int element = 23;
	int length = add_to_list(&marks_of_student,&element);
	assert(length==1);
	char a='c';
	int nextLength = add_to_list(&marks_of_student,&a);
	assert(nextLength==2);
}

void test_for_get_first_element(){
	LinkedList marks_of_student = createList();
	void *firstEle = get_first_element(marks_of_student);
	assert(firstEle==0);
	int ele = 23;
	char initial = 'S';
	float temp = 23.78;
	double d = 89.00;
	add_to_list(&marks_of_student,&ele);
	add_to_list(&marks_of_student,&initial);
	add_to_list(&marks_of_student,&temp);
	add_to_list(&marks_of_student,&d);
	void *first = get_first_element(marks_of_student);
	assert(*(int *)first==23);	
}

void test_for_get_last_element(){
	LinkedList marks_of_student = createList();
	void *lastEle = get_last_element(marks_of_student);
	assert(lastEle==0);
	int ele = 23;
	char initial = 'S';
	float temp = 23.78;
	double d = 89.00;
	add_to_list(&marks_of_student,&ele);
	add_to_list(&marks_of_student,&temp);
	add_to_list(&marks_of_student,&d);
	add_to_list(&marks_of_student,&initial);
	void *last = get_last_element(marks_of_student);
	assert(*(char *)last=='S');	
}

void test_for_forEach(){
	LinkedList marks_of_student = createList();
	int num1 = 23;
	int num2 = 33;
	int num3 = 43;
	int num4 = 53;
	int num5 = 63;
	add_to_list(&marks_of_student,&num1);
	add_to_list(&marks_of_student,&num2);
	add_to_list(&marks_of_student,&num3);
	add_to_list(&marks_of_student,&num4);
	add_to_list(&marks_of_student,&num5);
	int destination[marks_of_student.length];
	forEach(&marks_of_student,&increment);
	storeValue(marks_of_student,destination);
	ELEMENT *ele = marks_of_student.first;
	for(int i=0;i<marks_of_student.length;i++){
		assert(destination[i]==*(int *)ele->value);
		ele=ele->next;
	}
}





