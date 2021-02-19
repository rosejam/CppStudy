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

void MySetBoard()
{
    int dir = 0;
    int num = 1;
    int y=0;
    int x=-1;

    int dy[] = {0, 1, 0, -1};
    int dx[] = {1, 0, -1, 0};

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
        
        dir++;
        if (dir == 4)
            dir = 0;
        
        if (toggle)
            count--;
        toggle = !toggle;
    }
}

enum DIR
{
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3,
};

bool CanGo(int y, int x)
{
    if (y < 0 || y >= N)
        return false;
    if (x < 0 || x >= N)
        return false;
    if (board[y][x] != 0)
        return false;
    return true;
}

void SetBoard()
{
    int dir = RIGHT;
    int num = 1;
    int y=0;
    int x=0;
    
    int dy[] = {0, 1, 0, -1};
    int dx[] = {1, 0, -1, 0};
    
    board[y][x] = num;
    while (true)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        /*int nextY;
        int nextX;
        switch (dir)
        {
        case RIGHT:
            nextY = y;
            nextX = x+1;
            break;
        case DOWN:
            nextY = y+1;
            nextX = x;
            break;
        case LEFT:
            nextY = y;
            nextX = x-1;
            break;
        case UP:
            nextY = y-1;
            nextX = x;
            break;
        }*/

        if (CanGo(nextY, nextX)) // 이동
        {
            y = nextY;
            x = nextX;
            
            num++;
            board[y][x] = num;
            if (num == N*N)
                break;
        }
        else // 회전
        {   
            dir = (dir+1) % 4;
            /*switch (dir)
            {
            case RIGHT:
                dir = DOWN;
                break;
            case DOWN:
                dir = LEFT;
                break;
            case LEFT:
                dir = UP;
                break;
            case UP:
                dir = RIGHT;
                break;
            }*/
        }
    }
}

int main()
{
    cin >> N; // 전역 변수에 받는다!

    SetBoard();
    PrintBoard();

    cout << endl;

    MySetBoard();
    PrintBoard();

    return 0;
}