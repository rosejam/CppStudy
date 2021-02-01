#include <iostream>
using namespace std;

int main() 
{
    // 랜덤 by 난수생성기
    // 어떤 숫자를 기반으로 다음 숫자를 연산

    srand(time(0)); // 시드값을 설정함. 시드값이 같으면 같은 랜덤값이 생성됨!!! (현재 초를 주로 시드로 사용한다)
                    // 0~32767 (0x7FFF)
    int value = 1 + (rand() % 3); // 1,2,3


    const int SCISSORS = 1;
    const int ROCK = 2;
    const int PAPER = 3;
    int wins = 0;
    int total = 0;
    cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
    cout << "> 현재 승률 : 없음" << endl;
    while(true)
    {
        int computerValue = 1 + (rand() % 3);

        int userInput;
        cin >> userInput;
        switch(userInput)
        {
            case SCISSORS:
                cout << "가위(님) vs ";
                break;
            case ROCK:
                cout << "바위(님) vs ";
                break;
            case PAPER:
                cout << "보(님) vs ";
                break;
            default:
                cout << "뭘 내신거죠?" << endl; 
                // break game;
        }
        switch(computerValue)
        {
            case SCISSORS:
                cout << "가위(컴퓨터) ";
                break;
            case ROCK:
                cout << "바위(컴퓨터) ";
                break;
            case PAPER:
                cout << "보(컴퓨터) ";
                break;
            default:
                cout << "에러" << endl;
                // break game;
        }

        if(userInput == computerValue)
            cout << "비겼습니다!" << endl;
        else if((userInput==1&&computerValue==3) || userInput == computerValue+1)
        {
            cout << "이겼습니다!" << endl;
            total++; wins++;
        }
        else
        {
            cout << "졌습니다!" << endl;
            total++;
        }
        
        int winPercentage = (wins * 100) / total; // 이런 식으로 *100을 먼저 하면 float없이 확률 계산 가능!
        cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
        cout << "> 현재 승률 : " << winPercentage << endl;
    }
}