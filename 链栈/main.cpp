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
		cout<<"������ִ�еĹ��ܱ��function:";
		cin>>function;
		switch(function)
		{
		case 1:
			cout<<"��������ջ����������:";
			cin>>num;
			L.pushLotdata(num);break;
		case 2:
			L.popLotdata();break;
		case 3:
			cout<<"�����뵥����ջ����e:";
			cin>>e;
			L.pushData(e);break;
		case 4:
			printf_s("������ջ����:%d\n",L.popData());break;
		case 5:
			L.storeDatatofile();break;
		case 6:
			L.getDatafromfile();break;
		default:
			cout<<"����Ĺ��ܱ��function ������"<<endl;
		}
		cout<<"�Ƿ����ִ����������? 1-���� 0-�˳� :";
		cin>>key;
		system("cls");
	}while(key);

	system("pause");
	return 0;
}