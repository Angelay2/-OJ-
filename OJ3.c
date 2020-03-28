#include <stdio.h>
#include <stdlib.h>

// ��ջʵ�ֶ���(�Ƚ����ʵ���Ƚ��ȳ�)
/*ʹ��ջʵ�ֶ��е����в�����

push(x) --��һ��Ԫ�ط�����е�β����
pop() --�Ӷ����ײ��Ƴ�Ԫ�ء�
peek() --���ض����ײ���Ԫ�ء�
empty() --���ض����Ƿ�Ϊ��
*/

// ������һ��ջʵ�ֶ���, ջֻ��һ�˿��� 
// ����: 4321(ջ��Ϊ4) ��Ҫ�ȳ�1 Ҫ��432���� �ֲ��ܶ���, ��Ҫ������ЩԪ��, ������������ջ 
// һ��ջʵ����� һ��ջʵ�ֳ���
// ÿ�ν������ʱ ��Ԫ��(321)����ջ1, ����ʱ �ȿ�ջ2��û��Ԫ�� û�е�ȫ������ȥ(123)
// ���ջ��ջ��Ԫ�� �ͱ���� ����ջ��ջ��Ԫ�� ---> �պþ���Ҫ���ӵ�Ԫ��(�Ƚ��ȳ�) --> ��1
// �´θ����ջ�����µ�Ԫ��, Ȼ�󿴳���ջ����Ԫ��, ����, ��ֱ�Ӱѳ���ջ��ջ��Ԫ�ؼ�����ջ, ֱ��Ϊ��,
// �ȵ�Ϊ��ʱ, �ٰ����ջԪ�ص��뵽����ջ ��ͨ����'����ջ'��ջ��Ԫ�س�ջʵ�ֳ���,

typedef int Datatype;
typedef struct Stack{
	Datatype* _array;
	size_t _size;
	size_t _capacity;
}Stack;
void stackInit(Stack* st, size_t n){
	st->_array = (Datatype*)malloc(sizeof(Datatype)* n);
	st->_size = 0;
	st->_capacity = n;
}
void stackPush(Stack* st, Datatype data){
	if (st->_size == st->_capacity){
		st->_array = (Datatype*)realloc(st->_array, 2 * st->_capacity * sizeof(Datatype));
		st->_capacity *= 2;
	}
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st){
	if (st->_size > 0){
		--st->_size;
	}
}
Datatype stackTop(Stack* st){
	return st->_array[st->_size - 1];
}
size_t stackSize(Stack* st){
	return st->_size;
}
int stackEmpty(Stack* st){
	if (st->_size == 0)
		return 1;
	return 0;
}
void stackDestory(Stack* st){
	if (st->_array){
		free(st->_array);
		st->_size = st->_capacity = 0;
	}
}

// ������ջʵ�ֶ���;
typedef struct {
	Stack pushst;// ���
	Stack popst;// ����
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate(MyQueue* obj) {
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	stackInit(&obj->pushst, 10);
	stackInit(&obj->popst, 10);
	return mq;
}

/** Push element x to the back of queue. */
// �����ջ�������
void myQueuePush(MyQueue* obj, int x) {
	stackPush(&obj->pushst, x);
}

/** Removes the element from in front of queue and returns that element. */
// �����жϳ���ջ�Ƿ�Ϊ��, Ϊ�յĻ�, �����ջԪ�ص������ջ
int myQueuePop(MyQueue* obj) {
	// ����ջΪ�� ��������ջԪ��, �ٳ�ջ; ����Ϊ�� ֱ�ӳ�ջ
	if (stackEmpty(&obj->popst)){
	
		while (stackEmpty(&obj->pushst) != 1){
			// ��ȡ���ջ��Ԫ��
			int e = stackTop(&obj->pushst);
			stackPop(&obj->pushst);
			// ���뵽����ջ
			stackPush(&obj->popst, e);
		}
	}
	// ��ȡ����ջ��Ԫ��
	int ret = stackTop(&obj->popst);
	stackPop(&obj->popst);
	return ret;
	
}

/** Get the front element. */
// �����õ�����ջ��Ԫ��
// ���һ��Ԫ�ز���Ҫ��ջ, ֻ��Ҫ��ȡԪ�ؼ���
int myQueuePeek(MyQueue* obj) {
	if (stackEmpty(&obj->popst)){
		while (stackEmpty(&obj->pushst) != 1){
			// ���ջ��Ϊ��, ���ȡ���ջ��Ԫ��
			int e = stackTop(&obj->pushst);
			stackPop(&obj->pushst);
			// ���뵽����ջ
			stackPush(&obj->popst, e);
		}
	}
	// ֱ���ó���ջջ��Ԫ��
	return stackTop(&obj->popst);
}

/** Returns whether the queue is empty. */
int myQueueEmpty(MyQueue* obj) {
	if (stackEmpty(&obj->pushst) && stackEmpty(&obj->popst))
		// Ϊ��
		return 1;
	return 0;
}

void myQueueFree(MyQueue* obj) {
	stackDestory(&obj->pushst);
	stackDestory(&obj->popst);
	free(obj);
}
void testQueue(){
	MyQueue q;
	myQueueCreate(&q);
	myQueuePush(&q, 1);
	myQueuePush(&q, 2);
	myQueuePush(&q, 3);
	myQueuePush(&q, 4);
	myQueuePush(&q, 5);
	while (myQueueEmpty(&q) != 1){
		printf("%d ", myQueuePeek(&q));// ��ӡ��1 2 3 4 5 
		myQueuePop(&q);
	}
	printf("\n");
}
int main(){
	testQueue();
	system("pause");
	return 0;
}