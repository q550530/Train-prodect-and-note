#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;
class STU{
private:
	string	sName;
	bool BG;
	int iCh;
	int iMa;
	int iEn;
public:
	STU(string Name="",bool bg=0,int c = 0,int m=0,int e=0 ):sName(Name),BG(bg),iCh(c),iMa(m),iEn(e){}
	friend ostream& operator<<(ostream&,const STU &);
	friend istream& operator>>(istream&,STU &);
};
ostream& operator<<(ostream& out,const STU & P){
	out<<P.sName<<'\0'<<(P.BG?"Boy":"Girl")<<'\0'<<P.iCh<<'\0'<<P.iMa<<'\0'<<P.iEn<<endl;
	return out;


}
istream& operator>>(istream& in, STU & P){
	cout<<"姓名:";
	in>>P.sName;
	cout<<"性別:";
	in>>P.BG;
	cout<<"國文:";
	in>>P.iCh;
	cout<<"數學:";
	in>>P.iMa;
	cout<<"英文";
	in>>P.iEn;
	return in;
}


int main(array<System::String ^> ^args)
{	

	 int iUserInput;
	 STU temp;
	 ofstream fout("data.txt");
	 vector<STU> data;
	 vector<STU>::iterator itr;
	 do{
		cout << "1. 輸入資料\n";
		cout << "2. 顯示資料\n";
		cout << "3. 寫入檔案\n";
		cout << "4. 結束\n";
		cout << "\t請選擇 : ";
		cin >> iUserInput;
		switch(iUserInput){
			case 1:
				cin >> temp;
				data.push_back(temp);
				break;
			case 2:
				for(itr = data.begin(); itr != data.end(); ++itr){
					cout << *itr << '\0';
				}
				cout << endl;
				break;
			case 3:
				for(itr = data.begin(); itr != data.end(); ++itr){
					fout << *itr << '\0';
				}
				fout << endl;
				break;
			case 4:		
				fout.close();
				return 0;
		}
	
	}while(1);
    system("pause");
    return 0;
}