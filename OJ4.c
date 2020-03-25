#include <stdbool.h>

/*4. 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k) : 构造器，设置队列长度为 k 。
Front : 从队首获取元素。如果队列为空，返回 - 1 。
Rear : 获取队尾元素。如果队列为空，返回 - 1 。
enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty() : 检查循环队列是否为空。
isFull() : 检查循环队列是否已满。
*/

// 循环队列
// 存放元素的时候 元素的大小是固定的, 物理的存放形式仍是一个线性的结构, 都相当于是一个顺序表(数组)
// 有队头和队尾 
// 删除一个元素 头往后走一个 插入一个元素 尾往前走
// 当删完到front = rear时 为空队列. 再插入一个元素 rear
// 有7个元素 但实际有8个位置 有一个位置用来判断空队列(rear=front)或者满(rear+1=front)的状态
// 对头队尾的位置以及data在时刻发生变化( 用数组来实现简单 )
// 循环队列: 一般在初始化时 队列大小就已确定
// 逻辑上循环 物理上线性的结构

typedef struct {
	int* _array;
	int _front;
	int _rear;
	int _k;
} MyCircularQueue;

// 初始化, 设置队列长度为k,
MyCircularQueue* myCircularQueueCreate(int k) {
	// 
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	// 申请数组大小为 k+1 的空间  (k+1)是能最大能存放的元素个数
	int* _array = (int*)malloc(sizeof(int)* (k + 1));
	// 空队列
	q->_front = q->_rear = 0;
	// 队列长度为k
	q->_k = k;
}

// 向循环队列中插入一个元素, 如果成功插入 则返回真
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(&obj))
		return false;
	obj->_array[obj->_rear++] = value;
	// 判断队尾是否已越界
	if (obj->_rear == obj->_k + 1)
		obj->_rear = 0;
	return true;
}

// 从循环队列中删除一个元素, 如果删除成功, 则返回真
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	++obj->_front;
	//判断队头是否越界
	if (obj->_front == obj->_k + 1)
		obj->_front = 0;
	return true;
}

// 从队首获取元素, 如果队列为空, 返回-1
int myCircularQueueFront(MyCircularQueue* obj) {

}

// 获取队尾元素, 如果队列为空, 返回-1,
int myCircularQueueRear(MyCircularQueue* obj) {

}

// 判断队列是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

}

// 判断队列是否已满
bool myCircularQueueIsFull(MyCircularQueue* obj) {

}

void myCircularQueueFree(MyCircularQueue* obj) {

}