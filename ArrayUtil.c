#include <stdio.h>
#include "ArrayUtil.h"
#include <assert.h>
#include <stdlib.h>
#include <math.h>


int isTry(void* hint, void* item){
	return 1;
};
int isOdd(void* hint,void* item){
	return !isEven(hint,item);
};

void multiply(void* hint, void* sourceItem, void* destinationItem){
	int *passed_hint=(int *)hint;
	int *passed_source_item=(int *)sourceItem;
	*(int *)destinationItem = (*passed_hint * *passed_source_item);
}

void test_create(){
	ArrayUtil array1 = create(4,5), array2 = create(4,2),array3 = create(4,5);
	assert(array1.length==5);
	assert(array2.length==2);
	assert(array3.length==5);
};

void test_areEqual(){
	ArrayUtil array1 = create(4,5), array2 = create(4,2),array3 = create(4,5);
	assert(areEqual(array1,array3)==1);
	assert(areEqual(array1,array2)==0);
	assert(areEqual(array1,array1)==1);
};

void test_findIndex_char(){
	ArrayUtil array4 = create(1,9);
	char characters[]= {'A','c','P','Y'};
	char *characterArray = (char *)array4.base;
	characterArray[8] = 'A';
	characterArray[7] = 'B';
	characterArray[6] = 'C';
	characterArray[3] = 'g';
	characterArray[5] = 'k';
	characterArray[4] = 's';
	characterArray[0] = 'u';

	assert(8==findIndex(array4,&characters[0]));
	assert(-1==findIndex(array4,&characters[3]));

};

void test_findFirst(){
	ArrayUtil array5=create(4,8);
	int *base = (int *)array5.base;
	for (int i = 0; i < 8; ++i)
		base[i]=i+31;
	int *evenNum = (int *)findFirst(array5,&isEven,0);
	assert(*evenNum==32); 
};

void test_findLast(){
	ArrayUtil array5=create(4,8);
	int *base = (int *)array5.base;
	for (int i = 0; i < 8; ++i)
		base[i]=i+31;
	int *lastEvenNum = (int *)findLast(array5,&isEven,0);
	assert(*lastEvenNum==38); 
}

void test_findIndex_int(){
	ArrayUtil array2 = create(sizeof(int),9);
	int intigerArray[]={1,2,78,3,65};
	int *y = (int *)array2.base;
	y[0] = 78;
	y[2] = 65;
	assert(0==findIndex(array2,&intigerArray[2]));
	assert(2==findIndex(array2,&intigerArray[4]));
	assert(-1==findIndex(array2,&intigerArray[1]));
};

void test_count(){
	ArrayUtil array5=create(4,9);
	int *base = (int *)array5.base;
	for (int i = 0; i < array5.length; ++i)
		base[i]=i+31;
	assert(4==count(array5,&isEven,0));
	assert(5==count(array5,&isOdd,0));
	int divisibleBy = 3;
	assert(3==count(array5,&isDivisible,&divisibleBy));

};

void test_filter(){
	ArrayUtil array5=create(sizeof(int),10),array6=create(sizeof(int *),10);
	int *base = (int *)array5.base;
	for (int i = 0; i < array5.length; ++i)
		base[i]=(i)+200;
	int divisibleBy = 3;
	int result_length = filter(array5,&isDivisible,&divisibleBy,array6.base,array6.length);
	int **dest_base=(int **)array6.base;
	printf("=====>%d\n", *(dest_base)[1]);
	assert(result_length==3);
	assert(201==*(dest_base)[0]);
	assert(204==*(dest_base)[1]);
	assert(207==*(dest_base)[2]);
};

void test_map(){
	ArrayUtil array5=create(sizeof(int),7), array6=create(sizeof(int),7);
	int *base = (int *)array5.base;
	for (int i = 0; i < array5.length; ++i)
		base[i]=(i+1)+2;
	int multiply_by = 3;
	map(array5,array6,multiply,&multiply_by);
	int *dest_base=(int *)array6.base;
	for(int i=3,j=0;i<(array6.length+3);i++,j++){
		assert(i*3==dest_base[j]);
	}
}

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
	int answerDiv = filter(util,&isDivisible,hint,destination,4);
	int answerEven = filter(util,&isEven,hint,destination,4);
	assert(answerDiv==4);
	assert(answerEven==4);
}

void test_for_map_elements(){
	ArrayUtil source = create(4,6);
	ArrayUtil destination = create(4,6);
	int *elements = (int *)source.base;
	elements[0]=10;
	elements[1]=20;
	elements[2]=30;
	elements[3]=40;
	elements[4]=50;
	elements[5]=60;
	int power=2;
	void *hint = &power;
	map(source,destination,&square,hint);
	int *squares =(int *) destination.base;
	assert(100==squares[0]);
	assert(400==squares[1]);
	assert(900==squares[2]);
	assert(1600==squares[3]);
	assert(2500==squares[4]);
	assert(3600==squares[5]);
}

void test_for_forEach(){
	ArrayUtil util = create(4,5);
	int *elements = (int *)util.base;
	elements[0]=10;
	elements[1]=20;
	elements[2]=30;
	elements[3]=40;
	elements[4]=50;
	int h = 2;
	void *hint = &h;
	forEach(util,&addNoWithHint,hint);
	int *numbers = (int *)util.base;
	assert(12==numbers[0]);
	assert(22==numbers[1]);
	assert(32==numbers[2]);
	assert(42==numbers[3]);
	assert(52==numbers[4]);
}

void test_for_reduce_function(){
	ArrayUtil util = create(4,4);
	int *elements = (int *)util.base;
	elements[0]=100;
	elements[1]=200;
	elements[2]=300;
	elements[3]=400;
	int clue = 100;
	void *hint = &clue;
	int a=0;
	void *initialValue = &a;
	void *answer = reduce(util,&greaterNumber,hint,initialValue);
	assert(*(int *)answer==400);
}
