#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    // [4] [2] [3] [4] [1] << 0층
    // [1] [1] [5] [2] [2] << 1층

    int first[5] = { 4, 2, 3, 4, 1 };
    int second[5] = { 1, 1, 5, 2, 2 };

    // 5칸짜리 배열이 2개 나열되어 있어 5*2*4개의 메모리 공간 차지
    int apartment2D[][5] = { { 4, 2, 3, 4, 1 }, { 1, 1, 5, 2, 2 } }; // 메모리 상에서 실제로 이렇게 1차원으로 쭉 나열되어 존재!!!
    
    for (int floor = 0; floor < 2; floor++)
    {
        for (int room = 0; room < 5; room++)
        {
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
            int index = (floor * 5) + room; // !!!
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

    
    // 3차원 배열 (직접 작성해서 추가함)
    // int[2]의 3개짜리 배열이 4개 있는 배열
    // int[3][2] 2차원 배열이 4개 있는 배열. 
    // 즉, n차원 배열은 n-1차원의 1차원 배열 !!!!!
    // 맨 앞[]을 제외하고는 크기를 정확하게 지정해 주어야 한다
    // (배열[]은 포인터*와 반대로 왼쪽부터 추가하고 접근한다!!!!)
    int arr[][3][2] =
    {
        {
            { 1, 2},
            { 3, 4},
            { 5, 6},
        },
        {
            { 7, 8},
            { 9,10},
            {11,12},
        },
        {
            {13,14},
            {15,16},
            {17,18},
        },
        {
            {19,20},
            {21,22},
            {23,24},
        },
    };
    
    for(int z=0; z<4; z++)
    {
        for (int y=0; y<3; y++)
        {
            for (int x=0; x<2; x++)
            {
                int info = arr[z][y][x];
                cout.width(2);
                cout << info << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    int(*ptr)[3][2] = arr; // 2차원 배열이름 arr은 int(*)[3][2] 타입인 포인터로 변환됨!

    for(int z=0; z<4; z++)
    {
        for (int y=0; y<3; y++)
        {
            for (int x=0; x<2; x++)
            {
                int info = ptr[z][y][x];
                cout.width(2);
                cout << info << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    cout << typeid(&ptr).name() << endl; // 얘만 다른 주소!!!
    cout << typeid(&arr).name() << endl;
    cout << endl;
    cout << typeid(ptr).name() << endl;
    cout << typeid(arr).name() << endl;
    cout << typeid(&ptr[0]).name() << endl;
    cout << typeid(&arr[0]).name() << endl;
    cout << endl;
    cout << typeid(ptr[0]).name() << endl;
    cout << typeid(arr[0]).name() << endl;
    cout << typeid(&ptr[0][0]).name() << endl;
    cout << typeid(&arr[0][0]).name() << endl;
    cout << endl;
    cout << typeid(ptr[0][0]).name() << endl;
    cout << typeid(arr[0][0]).name() << endl;
    cout << typeid(&ptr[0][0][0]).name() << endl;
    cout << typeid(&arr[0][0][0]).name() << endl;
    cout << endl;
    cout << typeid(ptr[0][0][0]).name() << endl; // 값
    cout << typeid(arr[0][0][0]).name() << endl; // 값

    return 0;
}