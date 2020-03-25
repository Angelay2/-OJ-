#include <stdbool.h>

/*4. ������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������

ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��

���ʵ��Ӧ��֧�����²�����

MyCircularQueue(k) : �����������ö��г���Ϊ k ��
Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
isFull() : ���ѭ�������Ƿ�������
*/

// ѭ������
// ���Ԫ�ص�ʱ�� Ԫ�صĴ�С�ǹ̶���, ����Ĵ����ʽ����һ�����ԵĽṹ, ���൱����һ��˳���(����)
// �ж�ͷ�Ͷ�β 
// ɾ��һ��Ԫ�� ͷ������һ�� ����һ��Ԫ�� β��ǰ��
// ��ɾ�굽front = rearʱ Ϊ�ն���. �ٲ���һ��Ԫ�� rear
// ��7��Ԫ�� ��ʵ����8��λ�� ��һ��λ�������жϿն���(rear=front)������(rear+1=front)��״̬
// ��ͷ��β��λ���Լ�data��ʱ�̷����仯( ��������ʵ�ּ� )
// ѭ������: һ���ڳ�ʼ��ʱ ���д�С����ȷ��
// �߼���ѭ�� ���������ԵĽṹ

typedef struct {
	int* _array;
	int _front;
	int _rear;
	int _k;
} MyCircularQueue;

// ��ʼ��, ���ö��г���Ϊk,
MyCircularQueue* myCircularQueueCreate(int k) {
	// 
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	// ���������СΪ k+1 �Ŀռ�  (k+1)��������ܴ�ŵ�Ԫ�ظ���
	int* _array = (int*)malloc(sizeof(int)* (k + 1));
	// �ն���
	q->_front = q->_rear = 0;
	// ���г���Ϊk
	q->_k = k;
}

// ��ѭ�������в���һ��Ԫ��, ����ɹ����� �򷵻���
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(&obj))
		return false;
	obj->_array[obj->_rear++] = value;
	// �ж϶�β�Ƿ���Խ��
	if (obj->_rear == obj->_k + 1)
		obj->_rear = 0;
	return true;
}

// ��ѭ��������ɾ��һ��Ԫ��, ���ɾ���ɹ�, �򷵻���
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	++obj->_front;
	//�ж϶�ͷ�Ƿ�Խ��
	if (obj->_front == obj->_k + 1)
		obj->_front = 0;
	return true;
}

// �Ӷ��׻�ȡԪ��, �������Ϊ��, ����-1
int myCircularQueueFront(MyCircularQueue* obj) {

}

// ��ȡ��βԪ��, �������Ϊ��, ����-1,
int myCircularQueueRear(MyCircularQueue* obj) {

}

// �ж϶����Ƿ�Ϊ��
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

}

// �ж϶����Ƿ�����
bool myCircularQueueIsFull(MyCircularQueue* obj) {

}

void myCircularQueueFree(MyCircularQueue* obj) {

}