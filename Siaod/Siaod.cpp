#include <iostream>
#include <random>

using namespace std;

void delFirstMetod(int *x, int &n, int key) {
    int i = 0, count = 2;
    while (i < n) {
        count+=2;
        if (x[i] == key) {
            count++;
            for (int j = i; j <= n - 1; j++) {
                x[j] = x[j + 1];
                count+=2;
            }
            n--;
            count++;
        }
        else {
            i++;
            count++;
        }
    }
    cout << "T1 = " << count << endl;
}

void delOtherMetod(int *x, int &n, int key) {
    int j = 0, count = 3;
    for (int i = 0; i < n; i++) {
        count+=3;
        x[j] = x[i];
        if (x[i] != key) {
            count++;
            j++;
        }
    }
    n = j - 1;
    cout << "T2 = " << count << endl;
}

void randomList(int *x, int n) {
    for (int i = 0; i < n; i++)
        x[i] = (rand() + 3) % 10;
}

void print(int *x, int n) {
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void sum(int **a, int **b, int n, int m) {
    int count = 1;
    for (int i = 0; i < n; i++) {
        count += 2;
        for (int j = 0; j < m; j++) {
            a[i][j] += b[i][j];
            count+=2;
        }
    }
    cout << endl;
    cout << "T(n, m) =" << count << endl;;
}

void printMatrix(int **x, int n, int m) {
    int i = 0, j = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, m;
    cout << "Введите размер матрицы" << endl;
    cin >> n >> m;
    int** matrix1 = new int* [n];
    int** matrix2 = new int* [n];
    for (int i = 0; i < n; i++)
        matrix1[i] = new int[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix1[i][j] = rand() % 15;
    cout << "Первая матрица:" << endl;
    printMatrix(matrix1, n, m);
    for (int i = 0; i < n; i++)
        matrix2[i] = new int[m];
    cout << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix2[i][j] = rand() % 30;
    cout << "Вторая матрица:" << endl;
    printMatrix(matrix2, n, m);
    sum(matrix1, matrix2, n, m);
    cout << "Результат сложения:" << endl;
    printMatrix(matrix1, n, m);
    delete[] matrix1;
    delete[] matrix2;
}
