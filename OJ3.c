#include <stdbool.h>


/*ʹ��ջʵ�ֶ��е����в�����

push(x) --��һ��Ԫ�ط�����е�β����
pop() --�Ӷ����ײ��Ƴ�Ԫ�ء�
peek() --���ض����ײ���Ԫ�ء�
empty() --���ض����Ƿ�Ϊ��
*/

// ջֻ��һ�˿��� 4321  ��Ҫ�ȳ�1 ��������ջ 
// һ��ʵ����� һ��ʵ�ֳ���
// ÿ�ν������ʱ ��Ԫ�ط���ջ1,����ʱ �ȿ�ջ2 ��û��Ԫ�� û��ȫ������ȥ 
// ��ʱջ2 ��պþ���Ҫ���ӵ�Ԫ��
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