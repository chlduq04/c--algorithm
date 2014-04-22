#include "includes.h"

enum {ADD,SUB,MUL};

int add(int a, int b){return a+b;}
int sub(int a, int b){return a-b;}
int mul(int a, int b){return a*b;}

void main(){

	int n1 = 1, n2 = 1;
	int cmd = ADD;
	int ret;

	//int(int,int) *calc[3] = {add,sub,mul}; Æ²¸²
	int (*calc[3])(int,int) = {add,sub,mul};

	ret = calc[cmd](n1,n2);

	printf("%d",ret);

}