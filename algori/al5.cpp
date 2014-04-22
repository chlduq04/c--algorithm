#include "includes.h"

#if 0

typedef struct __NODE{
	int data;
	struct __NODE *next;
} NODE;

NODE *head,*tail;

void init_list(){
	head = (NODE*)malloc(sizeof(NODE));
	tail = (NODE*)malloc(sizeof(NODE));
	head->next = tail;
	head->next = tail;
}

void insert_data(int data){
	NODE *node = (NODE*)malloc(sizeof(NODE));
	node->data = data;
	node->next = head->next;
	head->next = node;
}

void insert_end(int data){
	NODE *cur = head;
	NODE *node = (NODE*)malloc(sizeof(NODE));
	node->data = data;

	while(cur->next != tail){
		cur = cur->next;
	}

	node->next = cur->next;
	cur->next = node;
}

void display_data(){
	NODE *node;

	system("cls");
	printf("[head]");
	for(node = head->next;node != tail;node = node->next){
		printf("->[%d]",node->data);
	}
	getchar();
}

void delete_data(int data){
}

void main(){

	
	init_list();
	display_data();
	for(int i=0;i<5;i++){
		insert_end(i);
		display_data();
	}
}


//tail node는 자기자신을 가리키는 것이 좋다.
//왜냐하면 프로세스가 죽고나서 요류를 고치는 것 보다 무한루프에 빠진 프로세스를 디버깅하며 찾는것이 낫기 때문이다.
//

#endif


#if 0
typedef struct __NODE{
	int data;
	struct __NODE *next;
} NODE;



void init_list(NODE *head, NODE *tail){
	head->next = tail;
	head->next = tail;
}

void insert_data(NODE *head, NODE *tail, NODE *node){
	node->next = head->next;
	head->next = node;
}

void insert_end(NODE *head, NODE *tail, NODE *node){
	NODE *cur = head;

	while(cur->next != tail){
		cur = cur->next;
	}

	node->next = cur->next;
	cur->next = node;
}

void display_data(NODE *head, NODE *tail){
	NODE *node;

	system("cls");
	printf("[head]");
	for(node = head->next;node != tail;node = node->next){
		printf("->[%d]",node->data);
	}
	printf("->[tail]");
	getchar();
}

void delete_data(int data){
}

void main(){

	NODE nodes[5];;
	NODE head, tail;
	init_list(&head, &tail);
	display_data(&head, &tail);

	for(int i=0;i<5;i++){
		nodes[i].data = i;
		insert_end(&head, &tail, &nodes[i]);
		display_data(&head, &tail);
	}
}

#endif

# if 0
typedef struct __NODE{
	int data;

	struct __NODE *next;
	struct __NODE *prev;
} NODE;



void init_list(NODE *head){
	head->next = head;
	head->prev = head;
}

void insert_data(NODE *head, NODE *node){
	node->next = head->next;
	head->next = node;

	node->prev = node->next->prev;
	node->next->prev = node;
}

void insert_end(NODE *head, NODE *node){
	NODE *cur = head;

	while(cur->next != head){
		cur = cur->next;
	}

	node->next = cur->next;
	cur->next = node;
}

void reverse(NODE *head){
	
	NODE *prev = head;
	NODE *curr = head->next;
	NODE *next;

	while(curr != head){
		next = curr ->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	curr->next = prev;
}
/*
void reverse_display(NODE *head, NODE *tail){
	NODE *node;

	system("cls");
	printf("[head]");
	for(node = tail->next;node != head;node = node->next){
		printf("->[%d]",node->data);
	}
	printf("->[tail]");
	getchar();
}
*/
void display_data(NODE *head){
	NODE *node;

	system("cls");
	printf("[head]");
	for(node = head->next;node != head;node = node->next){
		printf("->[%d]",node->data);
	}
	printf("->[head]");
	getchar();
}

void delete_data(int data){
}

void main(){

	NODE nodes[5];;
	NODE head, tail;
	init_list(&head);
	display_data(&head);

	for(int i=0;i<5;i++){
		nodes[i].data = i;
		insert_end(&head, &nodes[i]);
		display_data(&head);
	}

	reverse(&head);
	display_data(&head);

	reverse(&head);
	display_data(&head);

	reverse(&head);
	display_data(&head);
}

//tail node는 자기자신을 가리키는 것이 좋다.
//왜냐하면 프로세스가 죽고나서 요류를 고치는 것 보다 무한루프에 빠진 프로세스를 디버깅하며 찾는것이 낫기 때문이다.
//

#endif
#if 0
typedef struct __NODE{
	int data;

	struct __NODE *next;
	struct __NODE *prev;
} NODE;



void init_list(NODE *head){
	head->next = head;
	head->prev = head;
}

void insert_data(NODE *node, NODE *prev, NODE *next){
	node->next = next;
	node->prev = prev;
	prev->next = node;
	next->prev = node;
}

void insert_front(NODE *node, NODE *head){
	insert_data(node,head,head->next);
}

void insert_end(NODE *node, NODE *head){
	insert_data(node, head->prev, head);
}


void reverse(NODE *head){
	
	NODE *prev = head;
	NODE *curr = head->next;
	NODE *next;

	while(curr != head){
		next = curr ->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	curr->next = prev;
}
/*
void reverse_display(NODE *head, NODE *tail){
	NODE *node;

	system("cls");
	printf("[head]");
	for(node = tail->next;node != head;node = node->next){
		printf("->[%d]",node->data);
	}
	printf("->[tail]");
	getchar();
}
*/
void display_data(NODE *head){
	NODE *node;

	system("cls");
	printf("[head]");
	for(node = head->next;node != head;node = node->next){
		printf("->[%d]",node->data);
	}
	printf("->[head]");
	getchar();
}

void delete_data(int data){
}

void main(){

	NODE nodes[5];;
	NODE head, tail;
	init_list(&head);
	display_data(&head);

	for(int i=0;i<5;i++){
		nodes[i].data = i;
		insert_end(&head, &nodes[i]);
		display_data(&head);
	}

	reverse(&head);
	display_data(&head);

	reverse(&head);
	display_data(&head);

	reverse(&head);
	display_data(&head);
}

//tail node는 자기자신을 가리키는 것이 좋다.
//왜냐하면 프로세스가 죽고나서 요류를 고치는 것 보다 무한루프에 빠진 프로세스를 디버깅하며 찾는것이 낫기 때문이다.
//

#endif

typedef struct{
	char name[32];
	int age;
} PERSON;

typedef struct __NODE{
	void* data;

	struct __NODE *next;
	struct __NODE *prev;
} NODE;



void init_list(NODE *head){
	head->next = head;
	head->prev = head;
}

void insert_data(NODE *node, NODE *prev, NODE *next){
	node->next = next;
	node->prev = prev;
	prev->next = node;
	next->prev = node;
}

void insert_front(NODE *head, NODE *node){
	insert_data(node,head,head->next);
}

void insert_end(NODE *head, NODE *node){
	insert_data(node, head->prev, head);
}


void reverse(NODE *head){
	
	NODE *prev = head;
	NODE *curr = head->next;
	NODE *next;

	while(curr != head){
		next = curr ->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	curr->next = prev;
}
/*
void reverse_display(NODE *head, NODE *tail){
	NODE *node;

	system("cls");
	printf("[head]");
	for(node = tail->next;node != head;node = node->next){
		printf("->[%d]",node->data);
	}
	printf("->[tail]");
	getchar();
}
*/
void display_data(NODE *head){
	NODE *node;
	PERSON *p;
	system("cls");
	printf("[head]");
	for(node = head->next;node != head;node = node->next){
		p = (PERSON*)node->data;
		printf("->[%s][%d]",p->name,p->age);
	}
	printf("->[head]");
	getchar();
}

void delete_data(int data){
}

void main(){

	NODE nodes[5];;
	NODE head, tail;
	
	PERSON people[5] = {{"kkk",6},{"kak",2},{"kergk",3},{"khttyk",1},{"khk",7}};
	
	init_list(&head);
	display_data(&head);

	for(int i=0;i<5;i++){
		nodes[i].data = &people[i];
		insert_end(&head, &nodes[i]);
		display_data(&head);
	}

	reverse(&head);
	display_data(&head);

	reverse(&head);
	display_data(&head);

	reverse(&head);
	display_data(&head);
}

//list entry를 한번 배워봐라