#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#define MAX 100
using namespace std;

typedef struct linkstacknode
{
	int data;
	linkstacknode* next;
}*linkstack;

class Linkstack
{

private:

	linkstack Top;

public:

	void initStart();//链栈的初始化函数

	void pushLotdata(int num);//链栈多数据入栈函数

	void popLotdata();//链栈总数据顺序出栈函数

	void pushData(int e);//链栈单数据入栈函数

	int popData();//链栈单数据出栈函数

	int getStacknum()const;//计算链栈数据总数函数

	void storeDatatofile()const;//存储链栈数据至文本文件函数

	void getDatafromfile();//导入数据创建链栈函数

	void displayFunction();//链栈功能菜单打印输出函数
};
