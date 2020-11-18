#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VALUE 10001

void radixSort(int *a, int n) {
	int res[MAX_VALUE], maxValue = 0;
	int exp = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) maxValue = a[i];
	}
	while (maxValue / exp > 0) {
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++;
		for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0; i--) {
			res[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (int i = 0; i < n; i++) a[i] = res[i];
		exp *= 10;
	}
}

int main(void) {
	int a[MAX_VALUE];
	int i, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	radixSort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}