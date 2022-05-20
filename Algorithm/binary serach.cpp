#include <iostream>

using namespace std;
int binarysearch(int*, int, int);

int main()
{
	int search, ans;
	int data[] = { 3, 7, 14, 20, 23, 32, 41, 44, 56, 57, 73, 89, 93 };

	cout << "Enter which num u wanna search:";
	cin >> search;
	ans = binarysearch(data, search, sizeof(data) / sizeof(int));

	if (ans < 0)
	{
		cout << search << "it can not be find \n ";
	}
	else
	{
		cout << search << "\0 be find in " << ans + 1 << endl;
	}

	system("pause");
}

int binarysearch(int *data, int search, int n)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (data[mid] == search)
		{
			return mid;
		}
		else if (data[mid] > search)
		{
			high = mid - 1;
		}
		else if (data[mid] < search)
		{
			low = mid + 1;
		}
	}

	return -1;
}