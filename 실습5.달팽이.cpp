#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
    for (int y=0; y<N; y++)
    {
        for (int x=0; x<N; x++)
        {
            cout << setfill('0') << setw(2) << board[y][x] << " "; // iomanip으로 출력 자리수 형식을 맞춰주기
        }
        cout << endl;
    }
}

enum DIR
{
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3,
};

void SetBoard()
{
    int dir = RIGHT;
    int dy[] = {0, 1, 0, -1};
    int dx[] = {1, 0, -1, 0};
    int num = 1;
    int y=0;int x=-1;
    int count = N;
    bool toggle = true;
    while (count)
    {  
        for(int i=0; i<count; i++)
        {
            y += dy[dir];
            x += dx[dir];
            board[y][x] = num++;
        }
        
        dir += 1;
        if (dir == 4)
            dir = 0;
        if (toggle)
            count--;
        toggle = !toggle;
    }
}

int main()
{
    cin >> N; // 전역 변수에 받는다!

    SetBoard();

    PrintBoard();

    return 0;
}