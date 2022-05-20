#include <iostream>

using namespace std;

void InsertionSort(int *arr,int size){

	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (key < arr[j] && j >= 0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
void PrintArray(int *arr,int size){
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {

	int array[6] = { 5, 3, 1, 2, 6, 4 };
	cout << "original:\n";
	PrintArray(array,6);

	InsertionSort(array,6);

	cout << "sorted:\n";
	PrintArray(array,6);
	return 0;
}