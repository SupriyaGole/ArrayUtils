#include <stdio.h>
#include "ArrayUtil.h"
#include <assert.h>
#include <stdlib.h>

void test_are_equal(){
	ArrayUtil marks=create(4,10);
	ArrayUtil scores=create(4,8);
	assert(areEqual(marks,scores)==0);
	assert(areEqual(scores,marks)==0);
	assert(areEqual(marks,marks)==1);
	assert(areEqual(scores,scores)==1);
}

void test_for_resize_array(){
	ArrayUtil marks=create(4,10);
	int length=20;
	ArrayUtil new = resize(marks,length);
	assert(new.length ==length);
}

void test_for_findIndex(){
	ArrayUtil array;
	array = create(1,10);
	char b='c';
	char *numbers;
	numbers = (char *)array.base;
	numbers[4] = 'c';
	assert(findIndex(array,&b)==4);
}

void test_for_free(){
	ArrayUtil array;
	array=create(1,10);
	dispose(array);
}

int isEven(void *hint,void *num){
	int number=*(int *)num;
	return number%2==0;	
};

int isDivisible(void *hint,void *num){
	int Hint = *(int *)hint;
	int Number = *(int *)num;
	return Number%Hint==0; 
};	


void test_for_find_first_in_isEven(){
	ArrayUtil array;
	array=create(4,5);
	int *elements = (int *)array.base;
	elements[0]=12;
	elements[1]=11;
	elements[2]=14;
	elements[3]=15;
	int a=00;
	void *hint=&a;
	void *answer = findFirst(array,&isEven,hint);
	int forNull = *(int *)(answer);
	if(forNull == 0x0){
		assert(forNull == 0x0);
	}
	else
		assert(12==*(int *)answer);
}

void test_for_find_first_in_isDivisible(){
	ArrayUtil array;
	array = create(4,5);
	int *elements = (int *)array.base;
	elements[0]=10;
	elements[1]=20;
	elements[2]=30;
	elements[3]=40;
	int h=20;
	void *hint=&h;
	void *answer = findFirst(array,&isDivisible,hint);
	int forNull = *(int *)(answer);
	if(forNull == 0x0){
		assert(forNull == 0x0);
	}
	else
		assert(20==*(int *)answer);
}

void test_for_find_last_in_isEven(){
	ArrayUtil array;
	array=create(4,5);
	int *elements = (int *)array.base;
	elements[0]=12;
	elements[1]=11;
	elements[2]=14;
	elements[3]=15;
	int a=00;
	void *hint=&a;
	void *answer = findLast(array,&isEven,hint);
	int forNull = *(int *)(answer);
	if(forNull == 0x0){
		assert(forNull == 0x0);
	}
	else
		assert(14==*(int *)answer);
}

void test_for_find_last_in_isDivisible(){
	ArrayUtil array;
	array = create(4,5);
	int *elements = (int *)array.base;
	elements[0]=10;
	elements[1]=20;
	elements[2]=30;
	elements[3]=40;
	int h=20;
	void *hint=&h;
	void *answer = findLast(array,&isDivisible,hint);
	int forNull = *(int *)(answer);
	if(forNull == 0x0){
		assert(forNull == 0x0);
	}
	else
		assert(40==*(int *)answer);
}

void test_for_count_matched_elements(){
	ArrayUtil util=create(4,5);
	int *elements = (int *)util.base;
	elements[0]=10;
	elements[1]=20;
	elements[2]=30;
	elements[3]=40;
	elements[4]=50;
	int h=20;
	void *hint=&h;
	int noOfEle1 = count(util,&isDivisible,hint);
	int noOfEle2 = count(util,&isEven,hint);
	assert(noOfEle1==2);
	assert(noOfEle2==5);
}

void test_for_filter_elements(){
	ArrayUtil util = create(4,6);
	int *elements = (int *)util.base;
	elements[0]=10;
	elements[1]=20;
	elements[2]=30;
	elements[3]=40;
	elements[4]=50;
	elements[5]=60;
	int a=2;
	void *hint=&a;
	void *dest = calloc(util.length,util.typeSize);
	void **destination = &dest;
	int answerDiv = filter(util,&isDivisible,hint,destination,util.length);
	int answerEven = filter(util,&isEven,hint,destination,util.length);
	assert(answerDiv==6);
	assert(answerEven==6);
}

int main(){
	test_are_equal();
	test_for_resize_array();
	test_for_findIndex();
	test_for_free();
	test_for_find_first_in_isEven();
	test_for_find_first_in_isDivisible();
	test_for_find_last_in_isEven();
	test_for_find_last_in_isDivisible();
	test_for_count_matched_elements();
	test_for_filter_elements();
	return 0;
} 