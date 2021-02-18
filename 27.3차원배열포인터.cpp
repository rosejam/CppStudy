#include <iostream>
using namespace std;

int main()
{
    // int[2]의 3개짜리가 n개 있음
    // int[3][2]가 n개 있음
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

    int(*ptr)[3][2] = arr; // arr은 int(*)[3][2] 타입!!!!

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

    return 0;
}