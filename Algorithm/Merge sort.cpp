#include <iostream>

using namespace std;

void Merge(int A[],int firstM,int endM,int midM) {

	int leftCount = midM - firstM + 1;
	int rightCount = endM - midM;
	int lArr[leftCount+1];
	int rArr[rightCount+1];
	lArr[leftCount + 1] = 2147483647;
	rArr[leftCount + 1] = 2147483647;
	for (size_t i = 0; i < leftCount; i++)
	{
		lArr[i] = A[firstM + i];
	}
	for (size_t i = 0; i < leftCount; i++)
	{
		rArr[i] = A[midM+ i+1];
	}
	int i=0, j=0;
	for (size_t k = firstM; k <= endM; k++)
	{
		if (lArr[i]<=rArr[j]) 
			A[k] = lArr[i++];
		else
			A[k] = rArr[j++];
		
	}

}

void Merge_sort(int A[],int first,int end) {

	if (first<end)
	{
		int mid = (first + end) / 2;
		Merge_sort(A, first, mid);//left recursive
		Merge_sort(A, mid+1, end); //right recursive
		Merge(A,first,end,mid);
	}

}



int main()
{
	int Arr[10] = {23,5,7,9,8,15,17,52,3,77};
	for (size_t i = 0; i <10 ; i++)
	{
		cout << "befor sort:";
		cout << Arr[i] << '\0';
	}
	cout << endl;
	Merge_sort(Arr,0,9);
	for (size_t i = 0; i < 10; i++)
	{
		cout << "After sort:";
		cout << Arr[i] << '\0';
	}
	system("pause");
	return 0;
}

