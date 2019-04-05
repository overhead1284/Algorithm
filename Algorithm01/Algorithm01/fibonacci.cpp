#include <cstdio>
#include <windows.h>

int fib(int n) { //피보나치 재귀적 구현
	if (n <= 1) return n;
	else return fib(n - 1) + fib(n - 2);
}

int fib2(int n) { //피보나치 반복적 구현
	int f[100];
	f[0] = 0;
	if (n > 0) {
		f[1] = 1;
		for (int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}


void main() {
	int n = 5, f1[10], f2[10];
	double t1[10], t2[10];
	LARGE_INTEGER liCounter1, liCounter2, liFrequency;

	for (int i = 0; i < 8; i++) {// N이 5, 10, 15, 20, 25, 30, 35, 40일 때 실행 시간을 측정
		QueryPerformanceFrequency(&liFrequency);
		QueryPerformanceCounter(&liCounter1);
		f1[i] = fib(n);
		QueryPerformanceCounter(&liCounter2);
		t1[i] = 1000 * (double)(liCounter2.QuadPart - liCounter1.QuadPart) / (double)liFrequency.QuadPart;

		QueryPerformanceFrequency(&liFrequency);
		QueryPerformanceCounter(&liCounter1);
		f2[i] = fib2(n);
		QueryPerformanceCounter(&liCounter2);
		t2[i] = 1000 * (double)(liCounter2.QuadPart - liCounter1.QuadPart) / (double)liFrequency.QuadPart;
		n += 5;
	}

	for (int i = 0; i < 8; i++) {
		printf("N : %d\n", (i + 1) * 5);
		printf("피보나치(재귀적) : %d, %lf ms\n", f1[i], t1[i]);
		printf("피보나치(반복적) : %d, %lf ms\n\n", f2[i], t2[i]);
	}
	getchar();
	getchar();
}