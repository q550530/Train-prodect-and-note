#include "stdafx.h"
#include <iostream>
#include <vector>
#define Max 214783647
using namespace std;
int binarysearch(int*, int, int);

using namespace std;

void Merge(int A[], int firstM, int endM, int midM) {

	int leftCount = midM - firstM + 1;
	int rightCount = endM - midM;
	
	vector<int>leftArr(A+firstM,A+midM+1), rightArr(A+midM+1,A+endM+1);
	leftArr.insert(leftArr.end(), Max);
	rightArr.insert(rightArr.end(), Max);
	//int lArr[leftCount + 1]; //Just C99 complier can be complied
	//int rArr[rightCount + 1];
	//lArr[leftCount + 1] = 2147483647;
	//rArr[leftCount + 1] = 2147483647;
	for (size_t i = 0; i < leftCount; i++)
	{
		leftArr[i] = A[firstM + i];
	}
	for (size_t i = 0; i < leftCount; i++)
	{
		rightArr[i] = A[midM + i + 1];
	}
	int i = 0, j = 0;
	for (size_t k = firstM; k <= endM; k++)
	{
		if (leftArr[i] <= rightArr[j])
			A[k] = leftArr[i++];
		else
			A[k] = rightArr[j++];

	}

}

void Merge_sort(int A[], int first, int end) {

	if (first<end)
	{
		int mid = (first + end) / 2;
		Merge_sort(A, first, mid);//left recursive
		Merge_sort(A, mid + 1, end); //right recursive
		Merge(A, first, end, mid);
	}

}



int main()
{
	int Arr[10] = { 23, 5, 7, 9, 8, 15, 17, 52, 3, 77 };
	cout << "befor sort:";
	for (size_t i = 0; i <10; i++)
	{
		
		cout << Arr[i] << '\0';
	}
	cout << endl;
	Merge_sort(Arr, 0, 9);
	cout << "After sort:";
	for (size_t i = 0; i < 10; i++)
	{
		
		cout << Arr[i] << '\0';
	}
	system("pause");
	return 0;
}
