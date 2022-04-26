#include <iostream>
#include <ctime>
#define N 5305

using namespace std;
struct POINT {
	double x;
	double y;
};

int main()
{
	srand(unsigned(time(NULL)));
	POINT p[N];
	int iSum = 0;
	
	for (int i = 0; i < N; ++i) {
		p[i].x = rand() % 10000 / 10000.0; 
		p[i].y = rand() % 10000 / 10000.0;
		if (p[i].x * p[i].x + p[i].y * p[i].y <= 1) {
			iSum++;
		}
	}
	double gg = N;
	cout << iSum * 4 / gg << endl;
	system("pause");

	return 0;
}