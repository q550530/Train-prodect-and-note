#include "stdafx.h"
#include <iostream>
#include <cmath>  

using namespace std;

int getArea(int);				
int getArea(int, int);			
float getArea(float);			
float getArea(int, int, int);	 

int main()
{
	cout << "正方形 : " << getArea(5) << endl;
	cout << "矩形形 : " << getArea(5, 6) << endl;
	cout << "三角形 : " << getArea(5, 6, 7) << endl;
	cout << "圓形 : " << getArea(5.6f) << endl;
	cout << "三角形 : " << getArea(5.1f, 6.2f, 7.3f) << endl;

	system("pause");
    return 0;
}
int getArea(int e){
	return e * e;
}
int getArea(int e1, int e2){
	return e1 * e2;
}
float getArea(float r){
	return (3.14 * r * r);
}
float getArea(int a, int b, int c){
	
	if(a + b > c && b + c > a && c + a > b){
		//海龍公式
		float s = (a+b+c)/2.0f;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}else{
		cout << "不是三角形，無法求面積\n";
	}
}