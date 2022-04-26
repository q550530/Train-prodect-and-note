#include "stdafx.h"
#include <iostream>
using namespace std;

class FRACTION{
private:
	int num, den;
public:
	FRACTION();
	FRACTION(int, int);
	void printFRACTION();
	FRACTION ADD(FRACTION);
	FRACTION SUB(FRACTION);
	friend ostream& operator<<(ostream&, const FRACTION &);
};