#include <stdio.h>
#define N 10
double a[N] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f};

int main()
{
	int st = 3;
	double x = 2.0f;
	double sum = a[st - 1];
	int i;
	for	(i = st - 2; i >= 0; --i) {
		sum = sum * x + a[i];
	}

	printf("%f\n", sum);

	return 0;
}
