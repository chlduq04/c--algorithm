#include "includes.h"

typedef void(*FP)(int);

void int1(int *p){
	*p = 0;
}

void display(int *arr){
	//~~~~

}

void displays(int (*arr)[3]){

}


void init1(int *p){
	*p = 0;
}

void init2(int **pp){
	*pp = 0;
}

void insertName(char ***names){

	char buff[1024];
	
	for(int i=0;i<3;i++){
		printf("input your name :"), scanf("%s", buff);
		(*names)[i] = (char*)malloc(strlen(buff) + 1);
		strcpy((*names)[i],buff);
	}
}

void foo(int a){printf("called foo %d\n",a);}
//void goo(void(*fp)(int), int a){
//	fp(a);
//}

void goo(FP fp, int a){
	fp(a);
}


// 함수를 읽다가 symbol을 확인(hoo), 그리고 파라미터가 없는 함수인데 포인터를 반환한다. 근데 void형이고 파라미터는 int이다
//void(* hoo())(int){
//	return foo;
//}

FP foo(){
	return foo;
}
int main(){
	
#if 0
	int arr[5] = {1,2,3,4,5};
	int *p = arr + ((arr+4) - arr)/2;

	
	int n=30;
	/*
	const int *p = &n; // 포인터는 변수, 대상체는 상수
	*p = 0;
	p = 0;
	int const *q = &n; // 포인터는 변수, 대상체는 상수
	*q = 0;
	q = 0;
	int * const r = &n; // 포인터는 상수, 대상체는 변수
	*r = 0;
	r = 0;
	const int * const o = &n; //포인터는 상수, 대상체는 상수
	*o = 0;
	o = 0;
	*/
	
	
	printf("%d\n",*p);
	
	display(arr);
	//decay : 배열 전체 타입이 첫 번째 원소의 타입으로 퇴화

	/*
	배열은 함수에 특화된 문법이다
	배열명의 의미 : 배열 자신의 첫 번째 원소의 시작 주소를 의미하는 상수 포이터
	*/


	
	int *p[5];
	p = arr;

	int *test1 = arr;
	int *test2 = &arr;
	//c언어는 100%개발자를 믿는다. 그래서 되는데 c++은 안된다.
	//그러래서 자동으로 decay되기 때문에 c에서는 작동하고 c++은 오류가 난다
	int *test3 = arr;

	//이건 decay가 안된다 그래서 [5]부터 해석되어 포인터 배열이 다섯개 생긴다
	int *test4[5] = &arr;
	//그렇기 때문에 배열인 포인터로 마꿔줘야한다
	int (*test5)[5] = &arr; 



	// arr: 배열의 시작 주소, 타입은 원소의 첫 번째 원소의 타입
	//&arr: 배열의 시작 주소, 타입은 배열 전체의 타입 길이

	//int[3] arr[2];와 같다
	int arr1[2][3] = {1,2,3,4,5,6};
	int arr2[2][3] = {{1,2,3},{4,5,6}};


	//포인터라고 알려줘야한다
	displays(arr2);
	

	int (*arr5)[3] = (int(*)[3])malloc(sizeof(int) * 2 * 3);
//	int (*arr5)[3] = static_cast<int(*)[3]>malloc(sizeof(int) * 2 * 3);


	printf("%d\n",arr[3]);
	printf("%d\n",*(arr+3));
	
	int (*pp)[3] = 0;	
	printf("%d\n",p + 1); // 12이동
	//2차원 배열에 연산을 하게되면 행단위로 계산됩니다,

	//arr[i] == *(arr + i); => *(arr+sizeof(*arr)*i)



	int arrr1[2][3] = {1,2,3,4,5,6}; 
	printf("%d",arrr1[1][2]);
	//*(arrr+1)[2]
	printf("%d",(*(arrr1+1))[2]);
	printf("%d",*(*(arrr1+1)+2));

#endif

#if 0
	int arr1[3] = {1,2,3};
	int arr2[2][3] = {1,2,3,4,5,6};

	int **pp = (int(**))malloc(sizeof(int*)*2*3);

	pp[1][2] = 0;

	printf("%d\n",*(arr1 + 0));
	printf("%d\n",*(*(arr2 + 0)+0));
# endif
# if 0
	char *names[3] = {"aaa","bbb","ccc"};

	int name[3][32];

	for(int i=0;i<3;i++)
		printf("input your name :"), scanf("%s", name[i]);

	for(int i=0;i<3;i++)
		printf("your name is %s\n",name[i]);
	return 0;
# endif

# if 0
	int i;
	int (**name);
	name = (int(**))malloc(sizeof(char)*3);

	for(int i=0;i<3;i++)
		name[i] = (int(*))malloc(sizeof(char));
		printf("input your name :"), scanf("%s", name[i]);

	for(int i=0;i<3;i++)
		printf("your name is %s\n",name[i]);

	free(arr);
	return 0;
#endif

#if 0
	char buff[1024];
	char *names[3];

	for(int i=0;i<3;i++){
		printf("input your name :"), scanf("%s", buff);
		names[i] = (char*)malloc(strlen(buff) + 1);
		strcpy(names[i],buff);
	}

	for(int i=0;i<3;i++){
		printf("your name is %s\n",names[i]);
		free(names[i]);
	}
	return 0
#endif

# if 0
	char **names;
	//char * *names
	int n = 20;
	int *p;
	init1(&n);
	init2(&p);

	names = (char**)malloc(sizeof(char*)*3);

	insertName(&names);

	for(int i=0;i<3;i++){
		printf("your name is %s\n",names[i]);
		free(names[i]);
	}
	free(names);

	return 0;
#endif

	void (*fp)(int) = foo;
	//void *fp(int)는 왜 안되는가?
	//int부터 연산이 되기 때문에 그렇다
	fp(2);
	//()이건 함수 호출이다
	return 0;
}

//in paramter out parameter

