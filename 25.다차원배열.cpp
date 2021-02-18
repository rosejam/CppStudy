#include <iostream>
using namespace std;

int main()
{
    // [4] [2] [3] [4] [1] << 0층
    // [1] [1] [5] [2] [2] << 1층

    int first[5] = { 4, 2, 3, 4, 1 };
    int second[5] = { 1, 1, 5, 2, 2 };

    // 5칸짜리가 2개 있어 2*5*4개의 메모리 공간 차지
    int apartment2D[2][5] = { { 4, 2, 3, 4, 1 }, { 1, 1, 5, 2, 2 } }; // 메모리 상에서 실제로 이렇게 1차원으로 쭉 나열되어 존재!!!
    
    for (int floor = 0; floor < 2; floor++)
    {
        for (int room = 0; room < 5; room++)
        {
            // 왼쪽!! 인덱스부터 차례대로 접근한다!!
            int num = apartment2D[floor][room];
            cout << num <<  " ";
        }
        cout << endl;
    }

    int apartment1D[10] = { 4, 2, 3, 4, 1, 1, 1, 5, 2, 2 };

    for (int floor = 0; floor < 2; floor++)
    {
        for (int room = 0; room < 5; room++)
        {   
            int index = (floor * 5) + room; // !!
            int num = apartment1D[index];
            cout << num <<  " ";
        }
        cout << endl;
    }
    // 어셈블리언어에서는 1D, 2D의 과정이 거의 동일하다! (메모리 구조 상, 성능 상으로도 동일)

    cout << endl;
    // 2차 배열은 언제 사용할까? 대표적으로 2D 로그라이크 맵
    int map[5][5] =
    {
        { 1, 1, 1, 1, 1 }, 
        { 1, 0, 0, 1, 1 }, 
        { 0, 0, 0, 0, 1 }, 
        { 1, 0, 0, 0, 0 }, 
        { 1, 1, 1, 1, 1 },
    };

    for (int y=0; y<5; y++)
    {
        for (int x=0; x<5; x++)
        {
            int info = map[y][x];
            cout << info;
        }
        cout << endl;
    }

    return 0;
}