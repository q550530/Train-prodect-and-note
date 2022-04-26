#include "stdafx.h"
#include <iostream>
#include <ctime>
#define N 5

using namespace std;

int main(array<System::String ^> ^args)
{
    int iA[N];
	int *ptr=&iA[0];
	srand(unsigned(time(NULL)));

	for(int i =0;i<N;i++){
		*(ptr+i)=rand()%10+1;
		
	}
	cout<<"Sorting before"<<endl;
	for(int i =0;i<N;i++){
		cout<<*(ptr+i)<<'\0';
		
	}
	cout<<"Sorting after"<<endl;
	for(int o=0;o<N;o++){
		for(int g=0;g<N;g++){
			if(*(ptr+o)<*(ptr+g))
				swap((*(ptr+o)),(*(ptr+g)));
		}
	}

	for(int i =0;i<N;i++){
		cout<<iA[i]<<'\0';
	}

	system("pause");
    return 0;
}