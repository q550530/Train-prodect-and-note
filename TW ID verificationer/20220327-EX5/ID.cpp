#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
#include "ID.h"
ID::ID(){
	id = "";
}
bool ID::chkID(){
	if(id.size() != 10){
		cout << "��J���צ��~\n";
		return false;
	}
	
	if(!(id[0]>='A' && id[0]<='Z')){
		cout << "�Ĥ@�Ӧr���������j�g�^��r��\n";
		return false;
	}
	int iSum = 0;
	for(int i = 1; i<10; ++i){
		if(id[i]>='0' && id[i]<='9'){
			iSum++;
		}
	}
	if(iSum != 9){
		cout << "��2~10�ӥ��������ԧB�Ʀr\n";
		return false;
	}
	return true;
}

void ID::setID(string _id){
	id=_id;

}
string ID::getID(){
	return id;

}

bool ID::verID(){
	int iSum=0;
	string sArea[] = {"�O�_��","�O����","�򶩥�","�O�n��","������","�s�_��","�y����","��饫","�Ÿq��","�s�˿�","�]�߿�","", "�n�뿤","���ƿ�","�s�˥�","���L��","�Ÿq��","", "","�̪F��","�Ὤ��","�O�F��","������","���","","�s����"};
	int iArea[]    = {  10,      11,      12,       13,      14,     15,       16,      17,      34,      18,      19,   0,    21,       22,      35,      23,      24,    0,  0,   27,      28,      29,      32,     30,    0,   33};

	cout << sArea[id[0] -'A'] << endl;
	cout << iArea[id[0] -'A'] << endl;
	iSum += (iArea[id[0] -'A'] / 10 * 1);
	iSum += (iArea[id[0] -'A'] % 10 * 9);

	for(int i =1;i<9;i++)
	{
		iSum+= (id[i]-'0')*(9-i);
	}
	iSum+= (id[9]-'0')*1;

	cout<<iSum<<endl;
	if(iSum%10==0){
		cout<<"ID True"<<endl;
		return true;
	}
	else
	{
		cout<<"ID false"<<endl;
		return false;
	}

}