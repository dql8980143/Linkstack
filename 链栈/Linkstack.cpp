#include "Linkstack.h"

//链栈的初始化函数
void Linkstack::initStart()
{
	cout<<"执行链栈的初始化功能"<<endl;
	Top=NULL;
}

//链栈多数据入栈函数
void Linkstack::pushLotdata(int num)
{
	cout<<"执行链栈多数据入栈功能"<<endl;
	initStart();
	int i;
	linkstacknode* p;
	for(i=0;i<num;i++)
	{
		p=new linkstacknode;
		printf_s("请输入第%d个数据:",i+1);
		scanf_s("%d",&p->data);
		p->next=Top;
		Top=p;
	}
}

//链栈总数据顺序出栈函数
void Linkstack::popLotdata()
{
	cout<<"执行链栈总数据顺序出栈功能"<<endl;
	if(!Top)
	{
		cout<<"链栈空"<<endl;
		Sleep(1000);
		exit(1);
	}
	int i=0;
	linkstacknode* p;
	do
	{
		i++;
		printf_s("第%d个出栈数据:%d\n",i,Top->data);
		p=Top;
		Top=Top->next;
		delete p;
	}while(Top);
}

//链栈单数据入栈函数
void Linkstack::pushData(int e)
{
	cout<<"执行链栈单数据入栈功能"<<endl;
	linkstacknode* p;
	p=new linkstacknode;
	p->data=e;
	p->next=Top;
	Top=p;
}

//链栈单数据出栈函数
int Linkstack::popData()
{
	cout<<"执行链栈单数据出栈功能"<<endl;
	if(!Top)
	{
		cout<<"链栈空"<<endl;
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

//计算链栈数据总数函数
int Linkstack::getStacknum()const
{
	cout<<"执行计算链栈数据总数功能"<<endl;
	linkstack p=Top;
	int i=0;
	do
	{
		i++;
		p=p->next;
	}while(p);
	return i;
}

//存储链栈数据至文本文件函数
void Linkstack::storeDatatofile()const
{
	cout<<"执行存储链栈数据至文本文件功能"<<endl;
	if(!Top)
	{
		cout<<"链栈空"<<endl;
		Sleep(1000);
		exit(3);
	}
	ofstream outfile;
	outfile.open("Data.txt",ios::out);
	if(!outfile)
	{
		cerr<<"文件打开失败"<<endl;
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

//导入文本数据创建链栈函数
void Linkstack::getDatafromfile()
{
	cout<<"执行导入文本数据创建链栈功能"<<endl;
	ifstream infile;
	infile.open("Data.txt",ios::in);
	if(!infile)
	{
		cerr<<"文件打开失败"<<endl;
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

//链栈功能菜单打印输出函数
void Linkstack::displayFunction()
{
	string str(20,'=');
	cout<<str<<endl;
	cout<<"    链栈功能菜单    "<<endl;
	char* p[]={"1-链栈多数据入栈功能","2-链栈总数据顺序出栈功能",
		"3-链栈单数据入栈功能","4-链栈单数据出栈功能",
		"5-存储链栈数据至文本文件功能","6-导入数据创建链栈功能"};
	int count=sizeof(p)/sizeof(char*);
	int i;
	for(i=0;i<count;i++)
	{
		cout<<p[i]<<endl;
	}
	cout<<str<<endl;
}




