#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <time.h> 
#include <math.h>
using namespace std;

int grade(int a, int n) {
    if (n == 0)
        return 1;
    for (int i = 0; i < n - 1; i++)
        a *= 2;
    return a;
}

int findGrade(int x) {
    int n = 0;
    while (grade(2, n) < x)
        n++;
    return n;
}

int readerNumber(string line) {
    string x = "";
    for (char c : line) {
        if (c == ' ')
            return stoi(x);
        x += c;
    }
    return INT_MAX;
}

void sort(string* buf, int n) {
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && readerNumber(buf[j - 1]) > readerNumber(buf[j]); j--)
            swap(buf[j - 1], buf[j]);
}

void A_to_BC(int x) {
    ifstream A;
    ofstream B, C;
    A.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/A_file.txt");
    B.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/B.txt");
    C.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/C.txt");
    string line;
    int a = 0;
    if (A.is_open()) {
        while (getline(A, line)) {
            if (a % grade(2, x) < grade(2, x) / 2)
                B << line << endl;
            else
                C << line << endl;
            a++;
        }
    }
    A.close();
    B.close();
    C.close();
}

void BC_to_A(int n) {
    ofstream A;
    ifstream B;
    ifstream C;
    string line1 = "", line2 = "";
    int count1, count2;
    A.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/A_file.txt");
    B.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/B.txt");
    C.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/C.txt");
    if (B.is_open() && C.is_open()) {
        for (int i = 0; i < 32 / n; i++) {
            count1 = n;
            count2 = n;
            for (int i = 0; i < 2 * n; i++) {
                if (line1 == "" && count1 != 0)
                    getline(B, line1);
                if (line2 == "" && count2 != 0)
                    getline(C, line2);
                if (readerNumber(line1) < readerNumber(line2)) {
                    A << line1 << endl;
                    line1 = "";
                    count1--;
                }
                else {
                    A << line2 << endl;
                    line2 = "";
                    count2--;
                }
            }
        }
    }
    A.close();
    B.close();
    C.close();
}

void algorithm1() {
    cout << "Input the number of lines:" << endl;
    int a;
    cin >> a;
    clock_t start = clock();
    int n = findGrade(a);
    for (int i = 1; i <= n; i++) {
        A_to_BC(i);
        BC_to_A(grade(2, i - 1));
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << seconds;
}

void preparation1() {
    ifstream A;
    ofstream B, C;
    A.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/A_file.txt");
    B.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/B.txt");
    C.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/C.txt");
    string line;
    int a = 0, who = 0;
    string* buf = new string[5];
    if (A.is_open()) {
        while (getline(A, line)) {
            if (a == 5) {
                sort(buf, a);
                a = 0;
                if (who % 2 == 0)
                    for (int i = 0; i < 5; i++)
                        B << buf[i] << endl;
                else
                    for (int i = 0; i < 5; i++)
                        C << buf[i] << endl;
                who++;
            }
            buf[a] = line;
            a++;
        }
    }
    if (a != 0) {
        a;
        sort(buf, a);
        if (who % 2 == 0)
            for (int i = 0; i < a; i++)
                B << buf[i] << endl;
        else
            for (int i = 0; i < a; i++)
                C << buf[i] << endl;
    }
    A.close();
    B.close();
    C.close();
    delete[] buf;
}

void preparation2() {
    ofstream A;
    ifstream B, C;
    A.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/A_file.txt");
    B.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/B.txt");
    C.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/C.txt");
    string line;
    while (getline(B, line))
        A << line << endl;
    while (getline(C, line))
        A << line << endl;
    A.close();
    B.close();
    C.close();
}

void division() {
    ifstream A;
    ofstream B, C;
    A.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/A_file.txt");
    B.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/B.txt");
    C.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/C.txt");
    string line;
    int last = -1, who = 0;
    if (A.is_open()) {
        while (getline(A, line)) {
            if (last > readerNumber(line)) {
                last = -1;
                who++;
            }
            if (who % 2 == 0) {
                B << line << endl;
                last = readerNumber(line);
            }
            else {
                C << line << endl;
                last = readerNumber(line);
            }
        }
    }
    A.close();
    B.close();
    C.close();
}

void unite() {
    ofstream A;
    ifstream B, C;
    A.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/A_file.txt");
    B.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/B.txt");
    C.open("C:/Users/Polie/source/repos/Siaod_practice/Siaod4/C.txt");
    string line1 = "", line2 = "";
    bool t1 = true, t2 = true;
    int last1 = -1, last2 = -1;
    if (B.is_open() && C.is_open()) {
        while (true) {
            if (line1 == "") {
                getline(B, line1);
                if (readerNumber(line1) < last1 || readerNumber(line1) == INT_MAX) {
                    last1 = -1;
                    t1 = false;
                }
            }
            if (line2 == "") {
                getline(C, line2);
                if (readerNumber(line2) < last2 || readerNumber(line2) == INT_MAX) {
                    last2 = -1;
                    t2 = false;
                }
            }
            if (line1 == "" && line2 == "")
                break;
            if (!(t1 || t2)) {
                t1 = true;
                t2 = true;
            }
            if (readerNumber(line1) <= readerNumber(line2) && t1 || !t2) {
                last1 = readerNumber(line1);
                A << line1 << endl;
                line1 = "";
            }
            else if (readerNumber(line2) <= readerNumber(line1) && t2 || !t1) {
                last2 = readerNumber(line2);
                A << line2 << endl;
                line2 = "";
            }
        }
    }
    A.close();
    B.close();
    C.close();
}

void algorithm2() {
    int n = 0, a = 5;
    cin >> n;
    clock_t start = clock();
    preparation1();
    preparation2();
    division();
    cout << 3;
    unite();
    cout << 2;
    while (a <= n) {
        division();
        cout << 1;
        unite();
        a *= 2;
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << seconds;
}

int main()
{
    setlocale(LC_ALL, "RU");
    //algorithm1();
    algorithm2();
    return 0;
}