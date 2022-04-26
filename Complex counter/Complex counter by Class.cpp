#include "stdafx.h"
#include<iostream>



using namespace std;

class CCOMPLEX{
private:
	double real,image;
public:
	CCOMPLEX (){
		real=0.0;
		image=0.0;	
	}
	CCOMPLEX (double r,double i){
		real=r;
		image=i;			
	}
	void vShow(){
		cout<<"("<<real<<(image>=0?"+":"")<<image<<"i)\0";
	
	}
	CCOMPLEX adder(CCOMPLEX c){
		CCOMPLEX temp;
		temp.real=real+c.real;
		temp.image= image+c.image;
		return temp;
	}
	CCOMPLEX miners(CCOMPLEX c){
		return CCOMPLEX(real-c.real,image-c.image);
	}

};

int main(array<System::String ^> ^args)
{
    CCOMPLEX cpxA,cpxB(1.0,2.3),cpxC(1.5,-7.3);
	cpxA.vShow();
	cpxB.vShow();
	cpxC.vShow();
	cpxC.adder(cpxB).vShow();
	cpxC.miners(cpxB).vShow();
	system("pause");
    return 0;
}