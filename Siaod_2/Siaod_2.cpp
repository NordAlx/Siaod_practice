#include <iostream>
#include <random>
#include <ctime>

using namespace std;
void Exchange_sort(int *x, int n) {
    int a;
    //long long count = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            //count++;
            if (x[j] > x[j + 1]) {
                a = x[j];
                x[j] = x[j + 1];
                x[j + 1] = a;
                //count+=3;
            }
        }
    }
    //cout << count << endl;
}

void Insertion_sort(int *x, int n) {
    int a;
    long long count = 0;
    for (int i = 1; i < n; i++) {
        count++;
        for (int j = i; j > 0 && x[j - 1] > x[j]; j--) {
            count += 3;
            a = x[j - 1];
            x[j - 1] = x[j];
            x[j] = a;
        }
    }
    cout << count;
}

int main()
{
    int n;
    cin >> n;
    int* x = new int[n];
    for (int i = 0; i < n; i++) {
        x[i] = i;
    }
    //time_t begin = clock();
    Insertion_sort(x, n);
    //time_t end = clock();
    //double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //cout << time_spent;
    delete[] x;
    return 0;
}
