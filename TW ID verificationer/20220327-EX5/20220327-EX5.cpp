// 20220327-EX5.cpp: �D�n�M���ɡC

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
#include "ID.h"


int main(array<System::String ^> ^args)
{
	ID myID;
	string myString;
	while(!myID.chkID()||!myID.verID()){
		cout<<"ID=";
		cin>>myString;
		myID.setID(myString);
	}
		
	system("pause");
    return 0;
}
