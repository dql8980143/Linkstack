#include "Linkstack.h"

//��ջ�ĳ�ʼ������
void Linkstack::initStart()
{
	cout<<"ִ����ջ�ĳ�ʼ������"<<endl;
	Top=NULL;
}

//��ջ��������ջ����
void Linkstack::pushLotdata(int num)
{
	cout<<"ִ����ջ��������ջ����"<<endl;
	initStart();
	int i;
	linkstacknode* p;
	for(i=0;i<num;i++)
	{
		p=new linkstacknode;
		printf_s("�������%d������:",i+1);
		scanf_s("%d",&p->data);
		p->next=Top;
		Top=p;
	}
}

//��ջ������˳���ջ����
void Linkstack::popLotdata()
{
	cout<<"ִ����ջ������˳���ջ����"<<endl;
	if(!Top)
	{
		cout<<"��ջ��"<<endl;
		Sleep(1000);
		exit(1);
	}
	int i=0;
	linkstacknode* p;
	do
	{
		i++;
		printf_s("��%d����ջ����:%d\n",i,Top->data);
		p=Top;
		Top=Top->next;
		delete p;
	}while(Top);
}

//��ջ��������ջ����
void Linkstack::pushData(int e)
{
	cout<<"ִ����ջ��������ջ����"<<endl;
	linkstacknode* p;
	p=new linkstacknode;
	p->data=e;
	p->next=Top;
	Top=p;
}

//��ջ�����ݳ�ջ����
int Linkstack::popData()
{
	cout<<"ִ����ջ�����ݳ�ջ����"<<endl;
	if(!Top)
	{
		cout<<"��ջ��"<<endl;
		Sleep(1000);
		exit(2);
	}
	linkstacknode* p;
	p=Top;
	int e=Top->data;
	Top=Top->next;
	delete p;
	return e;
}

//������ջ������������
int Linkstack::getStacknum()const
{
	cout<<"ִ�м�����ջ������������"<<endl;
	linkstack p=Top;
	int i=0;
	do
	{
		i++;
		p=p->next;
	}while(p);
	return i;
}

//�洢��ջ�������ı��ļ�����
void Linkstack::storeDatatofile()const
{
	cout<<"ִ�д洢��ջ�������ı��ļ�����"<<endl;
	if(!Top)
	{
		cout<<"��ջ��"<<endl;
		Sleep(1000);
		exit(3);
	}
	ofstream outfile;
	outfile.open("Data.txt",ios::out);
	if(!outfile)
	{
		cerr<<"�ļ���ʧ��"<<endl;
		Sleep(1000);
		exit(4);
	}
	int num=getStacknum();
	linkstack p=Top;
	do
	{
		outfile<<"The"<<num<<"PushData:"<<p->data<<endl;
		num--;
		p=p->next;
	}while(p);
	outfile.close();
}

//�����ı����ݴ�����ջ����
void Linkstack::getDatafromfile()
{
	cout<<"ִ�е����ı����ݴ�����ջ����"<<endl;
	ifstream infile;
	infile.open("Data.txt",ios::in);
	if(!infile)
	{
		cerr<<"�ļ���ʧ��"<<endl;
		Sleep(1000);
		exit(5);
	}
	initStart();
	char Array[MAX];
	int i,data;
	linkstacknode* p;
	bool key=true;
	int count=0;
	do
	{
		infile.seekg(0,ios::end);
		count++;
		infile.seekg(-16*count,ios::cur);
		{
			if(!infile.tellg())
			{
				key=false;
			}
		}
		infile.getline(Array,sizeof(Array));
		sscanf(Array,"The%dPushData:%d\n",&i,&data);
		p=new linkstacknode;
		p->data=data;
		p->next=Top;
		Top=p;
	}while(key);
	infile.close();
}

//��ջ���ܲ˵���ӡ�������
void Linkstack::displayFunction()
{
	string str(20,'=');
	cout<<str<<endl;
	cout<<"    ��ջ���ܲ˵�    "<<endl;
	char* p[]={"1-��ջ��������ջ����","2-��ջ������˳���ջ����",
		"3-��ջ��������ջ����","4-��ջ�����ݳ�ջ����",
		"5-�洢��ջ�������ı��ļ�����","6-�������ݴ�����ջ����"};
	int count=sizeof(p)/sizeof(char*);
	int i;
	for(i=0;i<count;i++)
	{
		cout<<p[i]<<endl;
	}
	cout<<str<<endl;
}




