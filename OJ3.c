#include <stdbool.h>


/*使用栈实现队列的下列操作：

push(x) --将一个元素放入队列的尾部。
pop() --从队列首部移除元素。
peek() --返回队列首部的元素。
empty() --返回队列是否为空
*/

// 栈只是一端开口 4321  又要先出1 需用两个栈 
// 一个实现入队 一个实现出队
// 每次进行入队时 把元素放在栈1,出队时 先看栈2 有没有元素 没有全部导过去 
// 此时栈2 里刚好就是要出队的元素
typedef struct {
	Stack1 pushst;
	Stack2 popst;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	stackInit(&mq->pushst);
	stackInit(&mq->popst);
	return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {

}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {

}

void myQueueFree(MyQueue* obj) {

}