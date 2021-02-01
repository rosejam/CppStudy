#include <iostream>
using namespace std;

int main() 
{
    // 어떤 정수를 입력하면
    // N*N개의 별을 찍기
    int input;
    cin >> input;
    for (int i=0;i<input;i++)
    {
        for (int j=0;j<input;j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    // 1개부터 N개로 늘어나게
    for (int i=0;i<input;i++)
    {
        for (int j=0;j<i+1;j++) // 각 줄마다 i+1개 만큼만 찍기
        {
            cout << "*";
        }
        cout << endl;
    }
    // 줄어들게
    for (int i=0;i<input;i++)
    {
        for (int j=0;j<(input-i);j++) // 각 줄마다 input-i개 만큼만 찍기
        {
            cout << "*";
        }
        cout << endl;
    }
    // 구구단
    for(int i=2;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            int answer = i*j;
            cout << i << "X" << j << "=" << answer << endl;
        }
    }
}