#include <stdio.h>
#include <stdlib.h>

// 用栈实现对列(先进后出实现先进先出)
/*使用栈实现队列的下列操作：

push(x) --将一个元素放入队列的尾部。
pop() --从队列首部移除元素。
peek() --返回队列首部的元素。
empty() --返回队列是否为空
*/

// 不能用一个栈实现队列, 栈只是一端开口 
// 比如: 4321(栈顶为4) 又要先出1 要让432出来 又不能丢掉, 需要保存这些元素, 所以需用两个栈 
// 一个栈实现入队 一个栈实现出队
// 每次进行入队时 把元素(321)放在栈1, 出队时 先看栈2有没有元素 没有的全部导过去(123)
// 入队栈的栈底元素 就变成了 出队栈的栈顶元素 ---> 刚好就是要出队的元素(先进先出) --> 出1
// 下次给入队栈插入新的元素, 然后看出队栈有无元素, 若有, 则直接把出队栈的栈顶元素继续出栈, 直到为空,
// 等到为空时, 再把入队栈元素导入到出队栈 再通过让'出队栈'的栈顶元素出栈实现出队,

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

// 用两个栈实现队列;
typedef struct {
	Stack pushst;// 入队
	Stack popst;// 出队
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate(MyQueue* obj) {
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	stackInit(&obj->pushst, 10);
	stackInit(&obj->popst, 10);
	return mq;
}

/** Push element x to the back of queue. */
// 用入队栈进行入队
void myQueuePush(MyQueue* obj, int x) {
	stackPush(&obj->pushst, x);
}

/** Removes the element from in front of queue and returns that element. */
// 首先判断出队栈是否为空, 为空的话, 把入队栈元素导入出队栈
int myQueuePop(MyQueue* obj) {
	// 出队栈为空 则插入入队栈元素, 再出栈; 若不为空 直接出栈
	if (stackEmpty(&obj->popst)){
	
		while (stackEmpty(&obj->pushst) != 1){
			// 获取入队栈的元素
			int e = stackTop(&obj->pushst);
			stackPop(&obj->pushst);
			// 插入到出队栈
			stackPush(&obj->popst, e);
		}
	}
	// 获取出队栈的元素
	int ret = stackTop(&obj->popst);
	stackPop(&obj->popst);
	return ret;
	
}

/** Get the front element. */
// 就是拿到出队栈的元素
// 最后一个元素不需要出栈, 只需要获取元素即可
int myQueuePeek(MyQueue* obj) {
	if (stackEmpty(&obj->popst)){
		while (stackEmpty(&obj->pushst) != 1){
			// 入队栈不为空, 则获取入队栈的元素
			int e = stackTop(&obj->pushst);
			stackPop(&obj->pushst);
			// 插入到出队栈
			stackPush(&obj->popst, e);
		}
	}
	// 直接拿出队栈栈顶元素
	return stackTop(&obj->popst);
}

/** Returns whether the queue is empty. */
int myQueueEmpty(MyQueue* obj) {
	if (stackEmpty(&obj->pushst) && stackEmpty(&obj->popst))
		// 为空
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
		printf("%d ", myQueuePeek(&q));// 打印出1 2 3 4 5 
		myQueuePop(&q);
	}
	printf("\n");
}
int main(){
	testQueue();
	system("pause");
	return 0;
}