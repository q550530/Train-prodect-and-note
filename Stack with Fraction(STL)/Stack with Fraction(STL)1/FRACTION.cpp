#include "stdafx.h"
#include "FRACTION.h"
#include <iostream>
using namespace std;

FRACTION::FRACTION(){
	num = 0;
	den = 1;
}
FRACTION::FRACTION(int n, int d){
	num = n;
	if(d != 0){
		den = d;
	}else{
		cout << "請檢查，分母不能為0\n";
		den = 1;
	}
	
}

void FRACTION::printFRACTION(){
	cout << " (" << num << "/" << den << ") ";
}
FRACTION FRACTION::ADD(FRACTION f){
	return FRACTION(num*f.den+den*f.num, den*f.den);
}
FRACTION FRACTION::SUB(FRACTION f){
	return FRACTION(num*f.den-den*f.num, den*f.den);
}


ostream& operator<<(ostream& out, const FRACTION &f){ 
	out << " (" << f.num << "/" << f.den << ") ";
	return out;
}