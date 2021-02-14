#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Sort(int numbers[], int count)
{
    
}

int main()
{
    // 1) Swap 함수 만들기
    int a = 1;
    int b = 2;
    Swap(&a, &b);
    cout << a << " " << b << endl;
    Swap(a, b);
    cout << a << " " << b << endl;

    // 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
    int numbers[6] = { 1, 42, 3, 15, 5, 6 };

    // int size1 = sizeof(numbers); // 6*4
    // int size2 = sizeof(int); // 4
    Sort(numbers, sizeof(numbers)/sizeof(int) ); // 배열과 배열의 길이 전달


    return 0;
}