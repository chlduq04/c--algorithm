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


// �Լ��� �дٰ� symbol�� Ȯ��(hoo), �׸��� �Ķ���Ͱ� ���� �Լ��ε� �����͸� ��ȯ�Ѵ�. �ٵ� void���̰� �Ķ���ʹ� int�̴�
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
	const int *p = &n; // �����ʹ� ����, ���ü�� ���
	*p = 0;
	p = 0;
	int const *q = &n; // �����ʹ� ����, ���ü�� ���
	*q = 0;
	q = 0;
	int * const r = &n; // �����ʹ� ���, ���ü�� ����
	*r = 0;
	r = 0;
	const int * const o = &n; //�����ʹ� ���, ���ü�� ���
	*o = 0;
	o = 0;
	*/
	
	
	printf("%d\n",*p);
	
	display(arr);
	//decay : �迭 ��ü Ÿ���� ù ��° ������ Ÿ������ ��ȭ

	/*
	�迭�� �Լ��� Ưȭ�� �����̴�
	�迭���� �ǹ� : �迭 �ڽ��� ù ��° ������ ���� �ּҸ� �ǹ��ϴ� ��� ������
	*/


	
	int *p[5];
	p = arr;

	int *test1 = arr;
	int *test2 = &arr;
	//c���� 100%�����ڸ� �ϴ´�. �׷��� �Ǵµ� c++�� �ȵȴ�.
	//�׷����� �ڵ����� decay�Ǳ� ������ c������ �۵��ϰ� c++�� ������ ����
	int *test3 = arr;

	//�̰� decay�� �ȵȴ� �׷��� [5]���� �ؼ��Ǿ� ������ �迭�� �ټ��� �����
	int *test4[5] = &arr;
	//�׷��� ������ �迭�� �����ͷ� ��������Ѵ�
	int (*test5)[5] = &arr; 



	// arr: �迭�� ���� �ּ�, Ÿ���� ������ ù ��° ������ Ÿ��
	//&arr: �迭�� ���� �ּ�, Ÿ���� �迭 ��ü�� Ÿ�� ����

	//int[3] arr[2];�� ����
	int arr1[2][3] = {1,2,3,4,5,6};
	int arr2[2][3] = {{1,2,3},{4,5,6}};


	//�����Ͷ�� �˷�����Ѵ�
	displays(arr2);
	

	int (*arr5)[3] = (int(*)[3])malloc(sizeof(int) * 2 * 3);
//	int (*arr5)[3] = static_cast<int(*)[3]>malloc(sizeof(int) * 2 * 3);


	printf("%d\n",arr[3]);
	printf("%d\n",*(arr+3));
	
	int (*pp)[3] = 0;	
	printf("%d\n",p + 1); // 12�̵�
	//2���� �迭�� ������ �ϰԵǸ� ������� ���˴ϴ�,

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
	//void *fp(int)�� �� �ȵǴ°�?
	//int���� ������ �Ǳ� ������ �׷���
	fp(2);
	//()�̰� �Լ� ȣ���̴�
	return 0;
}

//in paramter out parameter

