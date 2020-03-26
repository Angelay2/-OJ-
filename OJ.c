#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>   bool函数的头文件

/*1. 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
    有效字符串需满足：

	左括号必须用相同类型的右括号闭合。
	左括号必须以正确的顺序闭合。
	注意空字符串可被认为是有效字符串。
*/

/* 遇到第一个右括号时, 应该让它去和最后一个左括号去匹配(后进先出)
用栈: 
	遇到左括号依次入栈, 
	一遇到右括号时, 就取出栈顶元素, 与之匹配.
	最终栈为空, 说明是正确的.
*/

// 搭建栈的结构
typedef char Datatype;

typedef struct Stack{
	Datatype* _array; // 给动态数组
	size_t _size;// 元素个数
	size_t _capacity;// 容量
}Stack;

void stackInit(Stack* st, size_t n){
	st->_array = (Datatype*)malloc(sizeof(Datatype)* n);
	st->_size = 0;
	st->_capacity = n;
}
void stackPush(Stack* st, Datatype data){
	if (st->_size == st->_capacity){
		st->_array = (Datatype*)realloc(st->_array, 2 * (st->_capacity) * sizeof(Datatype));
		st->_capacity *= 2;
	}
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st){
	if (st->_size > 0)
		--st->_size;
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

int isValid(char* s){
	static char array[][2] = { { '(', ')' },
							   { '[', ']' },
						       { '{', '}' } };
	// 先创建栈, 然后初始化,
	Stack st;
	stackInit(&st, 10);
	// 遍历当前的字符串, 同时使遇到的左括号入栈(stackPush)
	// i为行, [i][0]代表第一列的所有元素(即左括号),
	while (*s){

		int i = 0;
		// 左括号入栈
		for (; i < 3; ++i){

			if (*s == array[i][0]){
				stackPush(&st, *s);// 一个字符入栈
				++s;// 首元素地址+1
				break;
			}
		}
		// 左括号入栈完毕
		// 右括号入栈 j也为行数 [j][1]
		if (i == 3){
			// 如果栈本身是空的 直接返回
			if (stackEmpty(&st))
				return 0;
			// 获取栈顶元素, 拿到之后删除
			char topChar = stackTop(&st);
			stackPop(&st);
			// 找到是哪一个是右括号
			for (int j = 0; j < 3; j++){
				// 若字符为右括号, 
				if (*s == array[j][1]){
					// 则比较第一个左括号和
					if (topChar != array[j][0])
						return 0;

					++s;
					break;
				}
			}
		}
	}
	// 判断栈是否为空
	if (stackEmpty(&st))
		return 1;
	return 0;
}
int main(){
	char* s = "{[]}";
	//printf("%d\n",isValid(s));
	if (isValid(s) != 1){
		printf("false\n");
	}
	else{
		printf("true\n");
	}

	system("pause");
	return 0;
}