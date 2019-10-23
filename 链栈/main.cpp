#include "Linkstack.h"

int main()
{
	Linkstack L;
	int function;
	bool key;
	do
	{
		L.displayFunction();
		int num;
		int e;
		cout<<"请输入执行的功能编号function:";
		cin>>function;
		switch(function)
		{
		case 1:
			cout<<"请输入入栈的总数据数:";
			cin>>num;
			L.pushLotdata(num);break;
		case 2:
			L.popLotdata();break;
		case 3:
			cout<<"请输入单个入栈数据e:";
			cin>>e;
			L.pushData(e);break;
		case 4:
			printf_s("单个出栈数据:%d\n",L.popData());break;
		case 5:
			L.storeDatatofile();break;
		case 6:
			L.getDatafromfile();break;
		default:
			cout<<"输入的功能编号function 不合理"<<endl;
		}
		cout<<"是否继续执行其他功能? 1-继续 0-退出 :";
		cin>>key;
		system("cls");
	}while(key);

	system("pause");
	return 0;
}