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

	void initStart();//��ջ�ĳ�ʼ������

	void pushLotdata(int num);//��ջ��������ջ����

	void popLotdata();//��ջ������˳���ջ����

	void pushData(int e);//��ջ��������ջ����

	int popData();//��ջ�����ݳ�ջ����

	int getStacknum()const;//������ջ������������

	void storeDatatofile()const;//�洢��ջ�������ı��ļ�����

	void getDatafromfile();//�������ݴ�����ջ����

	void displayFunction();//��ջ���ܲ˵���ӡ�������
};
