#include <stdio.h>
#include <stdlib.h>


// 用队列实现栈(先进先出 --> 后进先出)
/*使用队列实现栈的下列操作：

push(x) --元素 x 入栈
pop() --移除栈顶元素
top() --获取栈顶元素
empty() --返回栈是否为空
注意 :

你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
*/

// 用一个队列实现一个栈(把一个实现好的队列变成一个栈 )
// 1. 把元素放进队列后也就相当于把元素放进栈里
// 2. 把队列中的元素删除(Pop)后重新又放进去(Push) 直到把想要Pop的元素删除掉等同于出栈,然后再Push新的
// 3. 
typedef int Datatype;
// 定义结点
typedef struct Node{
	Datatype _data;
	struct Node* _next;
}Node;

// 定义队列
typedef struct Queue{
	// 头尾指针
	Node* _front;
	Node* _rear;
	size_t _size;
}Queue; 

typedef struct {
	Queue _q;
}MyStack;

void queueInit(Queue* q){
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
void queuePush(Queue* q, Datatype data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;

	if (q->_front == NULL){
		q->_front = q->_rear = node;
	}
	else{
		q->_rear->_next = node;
		node->_next = NULL;
	}
	q->_rear = node;
	++q->_size;
}
void queuePop(Queue* q){
	if (q->_front != NULL){
		Node* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL)
			q->_rear = NULL;
		--q->_size;
	}
}
Datatype queueFront(Queue* q){
	return q->_front->_data;
}
Datatype queueBack(Queue* q){
	return q->_rear->_data;
}
int queueEmpty(Queue* q){
	if (q->_front == NULL)
		return 1;
	return 0;
}
size_t queueSize(Queue* q){
	return q->_size;
}
void queueDestory(Queue* q){
	Node* cur = q->_front;
	while (cur){
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_rear = q->_front = NULL;
	q->_size = 0;
}

//typedef struct Queue{
//	Datatype* _array;
//	size_t _size;
//	size_t _capacity;
//}Queue;
// 用一个队列实现栈


/** Initialize your data structure here. */
// 返回的是一个指针 所以需要动态的创建一个栈 
MyStack* myStackCreate(MyStack* obj) {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	queueInit(&obj->_q);
	return ms;
}

/** Push element x onto stack. */

void myStackPush(MyStack* obj, Datatype x) {
	queuePush(&obj->_q, x);
}

/** Removes the element on top of the stack and returns that element. */
// 先拿到队列的大小, 先循环size-1次,把除了最后一个元素其他的全部元素执行先出队再入队操作
// 把出队的元素先保存起来, 然后再插入
// 最后再单独把最后一个元素删除
int myStackPop(MyStack* obj) {
	int sz = queueSize(&obj->_q);
	while (sz > 1){
		int tmp = queueFront(&obj->_q);
		queuePop(&obj->_q);
		queuePush(&obj->_q, tmp);
		--sz;
	}
	int ret = queueFront(&obj->_q);
	queuePop(&obj->_q);
	return ret;
}

/** Get the top element. */
// 获取队列的队尾元素 即为栈的栈顶元素
int myStackTop(MyStack* obj) {
	return queueBack(&obj->_q);
}
/** Returns whether the stack is empty. */
int myStackEmpty(MyStack* obj) {
	if (queueEmpty(&obj->_q))
		return 1;
	return 0;
}

void myStackFree(MyStack* obj) {
	queueDestory(&obj->_q);
	free(obj);
}
void test(){
	MyStack obj;
	myStackCreate(&obj);
	myStackPush(&obj, 1);
	myStackPush(&obj, 2);
	myStackPush(&obj, 3);
	myStackPush(&obj, 4);
	myStackPush(&obj, 5);
	while (myStackEmpty(&obj) != 1){
		printf("%d ", myStackTop(&obj));
		myStackPop(&obj);
	}
	printf("\n");
}
int main(){
	test();
	system("pause");
	return 0;
}