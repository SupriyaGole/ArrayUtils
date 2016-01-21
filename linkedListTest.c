#include "linkedList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_for_create_list(){
	LinkedList marks_of_student = createList();
	assert(marks_of_student.length==0);
	assert(marks_of_student.first==NULL);
	assert(marks_of_student.last==NULL);
}

void test_for_add_int_to_List(){
	LinkedList marks_of_student = createList();
	int no1 = 23;
	int length = add_to_list(&marks_of_student,&no1);
	assert(length==1);
	int no2=33;
	int nextLength = add_to_list(&marks_of_student,&no2);
	assert(nextLength==2);
}

void test_for_add_char_to_List(){
	LinkedList marks_of_student = createList();
	char a1 = 'A';
	int length = add_to_list(&marks_of_student,&a1);
	assert(length==1);
	char a2 = 'B';
	int nextLength = add_to_list(&marks_of_student,&a2);
	assert(nextLength==2);
}

void test_for_add_Strings_to_List(){
	LinkedList marks_of_student = createList();
	char *a1 = "Anu";
	int length = add_to_list(&marks_of_student,a1);
	assert(length==1);
	char *a2 = "Supu";
	int nextLength = add_to_list(&marks_of_student,a2);
	assert(nextLength==2);
}

void test_for_get_first_element_from_list_of_characters(){
	LinkedList marks_of_student = createList();
	initializeListOfChar(&marks_of_student);
	void *first = get_first_element(marks_of_student);
	assert(*(char *)first=='A');	
}

void test_for_get_first_element_from_list_of_strings(){
	LinkedList marks_of_student = createList();
	char *a1 = "Anu";
	char *a2 = "Supu";
	add_to_list(&marks_of_student,a1);
	add_to_list(&marks_of_student,a2);
	char *first = (char *)get_first_element(marks_of_student);
	assert(strcmp(first,"Anu")==0);	
}

void test_for_get_first_element_from_list_of_integers(){
	LinkedList marks_of_student = createList();
	initializeList(&marks_of_student);
	void *first = get_first_element(marks_of_student);
	assert(*(int *)first==23);	
}

void test_for_get_last_element_from_integers(){
	LinkedList marks_of_student = createList();
	void *lastEle = get_last_element(marks_of_student);
	assert(lastEle==NULL);
	initializeList(&marks_of_student);
	void *last = get_last_element(marks_of_student);
	assert(*(int *)last==63);	
}

void test_for_get_last_element_from_characters(){
	LinkedList marks_of_student = createList();
	void *lastEle = get_last_element(marks_of_student);
	assert(lastEle==NULL);
	initializeListOfChar(&marks_of_student);
	char *last = (char *)get_last_element(marks_of_student);
	assert(*(char *)last=='E');	
}

void test_for_get_last_element_from_list_of_strings(){
	LinkedList marks_of_student = createList();
	char *a1 = "Anu";
	char *a2 = "Supu";
	add_to_list(&marks_of_student,a1);
	add_to_list(&marks_of_student,a2);
	char *last = (char *)get_last_element(marks_of_student);
	assert(strcmp(last,"Supu")==0);	
}

void test_for_forEach_on_increment_function(){
	LinkedList marks_of_student = createList();
	initializeList(&marks_of_student);
	int destination[marks_of_student.length];
	forEach(&marks_of_student,&increment);
	storeValue(marks_of_student,destination);
	ELEMENT *ele = marks_of_student.first;
	for(int i=0;i<marks_of_student.length;i++){
		assert(destination[i]==*(int *)ele->value);
		ele=ele->next;
	}
}

void test_for_forEach_to_Give_next_character_of_given_character(){
	LinkedList initialsOfName = createList();
	initializeListOfChar(&initialsOfName);
	forEach(&initialsOfName,&getNextChar);
	assert(strcmp((char *)initialsOfName.first->value,"B")==0);
	assert(strcmp((char *)initialsOfName.last->value,"F")==0);
}

void test_for_forEach_to_convert_given_string_into_lowerCase(){
	LinkedList initialsOfName = createList();
	char a1[] = "Anu";
	char a2[] = "Supu";
	add_to_list(&initialsOfName,a1);
	add_to_list(&initialsOfName,a2);
	forEach(&initialsOfName,&toLowerCase);
	assert(strcmp((char *)initialsOfName.first->value,"anu")==0);
	assert(strcmp((char *)initialsOfName.last->value,"supu")==0);
}

void test_for_getElementAt_of_integers(){
	LinkedList marks_of_student = createList();
	initializeList(&marks_of_student);
	int index = 2;
	int element =*(int *) getElementAt(marks_of_student,index);
	assert(element==43);
	int index1=3;
	int element1 =*(int *) getElementAt(marks_of_student,index1);
	assert(element1==53);
	int invalidIndex = 7;
	void *nullValue =getElementAt(marks_of_student,invalidIndex);
	assert(NULL==nullValue);
}

void test_for_getElementAt_of_characters(){
	LinkedList marks_of_student = createList();
	initializeListOfChar(&marks_of_student);
	int index = 2;
	char element =*(char *) getElementAt(marks_of_student,index);
	assert(element=='C');
	int index1=3;
	char element1 =*(char *) getElementAt(marks_of_student,index1);
	assert(element1=='D');
	int invalidIndex = 7;
	void *nullValue =getElementAt(marks_of_student,invalidIndex);
	assert(NULL==nullValue);
}

void test_for_getting_first_elements_from_list_of_strings(){
	LinkedList initialsOfName = createList();
	char a1[] = "Anu";
	char a2[] = "Supu";
	add_to_list(&initialsOfName,a1);
	add_to_list(&initialsOfName,a2);
	char *ele1 = (char *)getElementAt(initialsOfName,0);
	assert(strcmp(ele1,"Anu")==0);
	char *ele2 = (char *)getElementAt(initialsOfName,1);
	assert(strcmp(ele2,"Supu")==0);
}

void test_to_find_indexOf_list_of_integers(){
	LinkedList marks_of_students = createList();
	int no1=10;
	int no2=20;
	int no3=30;
	int no4=40;
	int no5=50;
	add_to_list(&marks_of_students,&no1);	
	add_to_list(&marks_of_students,&no2);	
	add_to_list(&marks_of_students,&no3);	
	add_to_list(&marks_of_students,&no4);	
	add_to_list(&marks_of_students,&no5);
	int no1Index = indexOf(marks_of_students,&no1);
	assert(no1Index==0);
	int no4Index = indexOf(marks_of_students,&no4);
	assert(no4Index==3);
}

void test_to_find_indexOf_string_in_given_List(){
	LinkedList initialsOfName = createList();
	char a1[] = "Anu";
	char a2[] = "Supu";
	add_to_list(&initialsOfName,a1);
	add_to_list(&initialsOfName,a2);
	int firstIndex = indexOf(initialsOfName,a1);
	assert(firstIndex==0);
	int secondIndex = indexOf(initialsOfName,a2);
	assert(secondIndex==1);
}

void test_to_find_indexOf_characters_in_given_List(){
	LinkedList initialsOfName = createList();
	char a1 = 'A';
	char a2 = 'S';
	add_to_list(&initialsOfName,&a1);
	add_to_list(&initialsOfName,&a2);
	int firstIndex = indexOf(initialsOfName,&a1);
	assert(firstIndex==0);
	int secondIndex = indexOf(initialsOfName,&a2);
	assert(secondIndex==1);
}

void test_for_deleteElementAt_of_list_of_integers(){
	LinkedList marks_of_student = createList();
	initializeList(&marks_of_student);
	int index=0;
	int *deletedElement = (int *)deleteElementAt(&marks_of_student,index);
	assert(23==*deletedElement);
	int nullIndex=7;
	void *nullValue = deleteElementAt(&marks_of_student,nullIndex);
	assert(nullValue == NULL);
}

void test_for_deleteElementAt_of_list_of_characters(){
	LinkedList marks_of_student = createList();
	initializeListOfChar(&marks_of_student);
	int index=0;
	char *deletedElement = (char *)deleteElementAt(&marks_of_student,index);
	assert('A'==*deletedElement);
	int nullIndex=7;
	void *nullValue = deleteElementAt(&marks_of_student,nullIndex);
	assert(nullValue == NULL);
}

void test_to_deleteElementAt_specific_positions_from_list_of_strings(){
	LinkedList list = createList();
	char a1[] = "Anu";
	char a2[] = "Supu";
	char a3[] = "Supriya";
	add_to_list(&list,a1);
	add_to_list(&list,a2);
	add_to_list(&list,a3);
	char *new1 = (char *)deleteElementAt(&list,0);
	assert(strcmp(new1,"Anu")==0);
	char *new2 = (char *)deleteElementAt(&list,0);
	assert(strcmp(new2,"Supu")==0);
}

void test_for_asArray_which_will_put_Integer_Elements_from_list_into_an_array(){
	LinkedList marks_of_students = createList();
	initializeList(&marks_of_students);
	int maxLength = marks_of_students.length;
	void *destination[maxLength];
	int count = asArray(marks_of_students,destination,maxLength);
	assert(count==maxLength);
}

void test_for_asArray_which_will_put_Character_Elements_from_list_into_an_array(){
	LinkedList initialsOfName = createList();
	initializeListOfChar(&initialsOfName);
	int maxLength = initialsOfName.length;
	void *destination[maxLength];
	int count = asArray(initialsOfName,destination,maxLength);
	assert(count==maxLength);
}

void test_will_return_new_LinkedList_of_filtered_integer_elements(){
	LinkedList marks_of_students = createList();
	initializeList(&marks_of_students);
	int hint=3; 
	LinkedList newList = filter(marks_of_students,&isDivisible,&hint);
	assert(newList.length==2);
}

void test_which_will_return_all_characters_which_are_in_capital_letter(){
	LinkedList initialsOfName = createList();
	initializeListOfChar(&initialsOfName);
	LinkedList newList = filter(initialsOfName,&isCapitalLetter,0);
	assert(newList.length==5);
}

void test_will_return_all_strings_which_contains_letter_a(){
	LinkedList list = createList();
	char a1[] = "Anu";
	char a2[] = "Supu";
	char a3[] = "Supriya";
	add_to_list(&list,a1);
	add_to_list(&list,a2);
	add_to_list(&list,a3);
	char hint='a';
	LinkedList newList = filter(list,&hasLetter,&hint);
	assert(newList.length==1);
}

void test_will_return_one_new_reverse_linkedList(){
	LinkedList marks_of_students = createList();
	initializeList(&marks_of_students);
	LinkedList reverseList = reverse(marks_of_students);	
}

void test_for_map(){
	LinkedList marks_of_students = createList();
	initializeList(&marks_of_students);
	int length = marks_of_students.length;
	int dest1[length];
	int dest2[length];
	int hint=2;
	LinkedList convertedList = map(marks_of_students,square,&hint);
	storeValue(marks_of_students,dest1);
	storeValue(convertedList,dest2);
	for(int i=0;i<sizeof(dest1)/4;i++){
		assert(dest1[i]*dest1[i]==dest2[i]);
	}
}

void test_for_implementing_reduce(){
	LinkedList marks_of_students = createList();
	initializeList(&marks_of_students);
	int hint=0;
	int initialValue = 2;
	int *addition = (int *)reduce(marks_of_students,sum,&hint,&initialValue);
	assert(*addition == 217);
}





