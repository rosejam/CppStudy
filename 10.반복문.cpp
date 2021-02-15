#include <iostream>
using namespace std;

// 오늘의 주제 : 반복문
// 데이터를 메모리에 할당하고 가공하는 방법에 대해 알아봄
// 가공한 데이터를 이용해서 무엇인가를 하고 싶다면?
// 어셈블리어에선 cmp와 jmp를 이용

int main()
{
    // while
    // ex) 게임을 끌 때 까지 계속 게임을 실행해라
    // ex) 목적지에 도달할 때 까지 계속 이동하라
    // "조건식 체크 시, false나 0이면 루프 탈출"!!

    int count = 0;
    while (count < 3)
    {
        cout << "Hello World" << endl;
        count++;
    }

    cout << endl;

    count = 0;
    // do-while
    // 잘안씀
    do // 처음에 조건 확인 안하고 무조건 한번 실행 한 후에 조건체크
    {
        cout << "Hello World" << endl;
        count++;
    } while (count < 3);
    
    cout << endl;

    // for
    // 맨 위 while문과 동일한 프로세스!!!
    // 실수를 줄일 수 있고 가독성이 좋아짐
    // 정해진 횟수를 돌릴 때 자주 사용
    for (int count = 0; count < 3; count++)  // 한눈에 초기식; 조건식; 제어식을 확인할 수 있음
    {
        cout << "Hello World" << endl;
    }

    cout << endl;

    // 루프문의 흐름 제어, break; 와 continue;
    // break : 무조건 빠져나가기 (break가 포함되어 있는 "바로 안쪽의 그 반복문만"!!)
    int round = 1;
    int hp = 100;
    int damage = 25;

    // 무한 루프 : 전투 시작 (while문 안에서 종료 조건 만들어주기)
    while (true)
    {
        hp -= damage;
        if (hp<0)
            hp = 0; // 음수 체력을 0으로 보정

        // 시스템 메시지
        cout << "Round " << round << " 몬스터 체력 " << hp << endl;

        if(hp==0)
        {
            cout << "몬스터 처치" << endl;
            break;  // 전투 종료
        }

        if (round==5)
        {
            cout << "제한 라운드 종료" << endl;
            break; // 전투 종료
        }

        round++;
    }

    // continue : 무조건 다음 조건식 체크로 이동 (=이 코드 아래를 스킵한다)
    // 1~10사이의 홀수만 출력하기
    for (int count=1; count<=10; count++)
    {
        bool isEven = ((count%2)==0);
        if(isEven)
            continue; // 짝수면 아래를 스킵

        cout << count << endl;
    }
}