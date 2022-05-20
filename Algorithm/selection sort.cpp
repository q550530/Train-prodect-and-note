#include<iostream>
using namespace std;

void selection_sort(int *arr,int size){
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(arr[i]>arr[j])
				swap(arr[i],arr[j]);			
			
		}
	}
	
	
}

void PrintArray(int *arr,int size){
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int array[6] = { 5, 3, 1, 2, 6, 4 };
	cout << "original:\n";
	PrintArray(array,6);
	selection_sort(array,6);
	PrintArray(array,6);

}