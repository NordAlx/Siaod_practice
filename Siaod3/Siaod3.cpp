#include <iostream>

using namespace std;

void sift(int* x, int n, int i) {
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && x[left] > x[max])
		max = left;
	if (right < n && x[left] > x[max])
		max = right;
	if (max != i) {
		swap(x[i], x[max]);
		sift(x, n, max);
	}
}

void algnxderevo(int* x, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		sift(x, n, i);
	for (int i = n - 1; i >= 0; i--) {
		swap(x[0], x[i]);
		sift(x, i, 0);
	}
}

void alg(int* x, int n) {
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = x[i];
		j = i - 1;
		while (j >= 0 && x[j] > key) {
			x[j + 1] = x[j];
			j--;
		}
		x[j + 1] = key;
	}
}

int main()
{
	int n = 0;
	cin >> n;
	int* lst = new int[n];
	for (int i = 0; i < n; i++)
		cin >> lst[i];
	algnxderevo(lst, n);
	for (int i = 0; i < n; i++)
		cout << lst[i] << "  ";
	delete[] lst;
}