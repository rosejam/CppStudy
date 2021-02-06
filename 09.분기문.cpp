#include <iostream>
using namespace std;

// 오늘의 주제 : 분기문
// 데이터를 메모리에 할당하고 가공하는 방법에 대해 알아봄
// 가공한 데이터를 이용해서 무엇인가를 하고 싶다면?
// 어셈블리어에선 cmp와 jmp를 이용

int main()
{
    // if-else문
    int hp = 100; // 몬스터 HP
    int damage = 90; // 플레이어 데미지

    hp -= damage; // 피격 판정
    bool isDead = (hp <= 0); // 처치 여부 판정

    // 몬스터가 죽었으면 경험치 추가
    // if문은 조건문이 0이 아닌 경우!!!!(bool이 참인 경우 포함) 실행
    // = 0이면 실행안한다

    // if (isDead) // isDead == true
    //     cout << "몬스터를 처치했습니다" << endl;
    // if (!isDead) // isDead == false // 두번째 체크
    //     cout << "몬스터가 반격했습니다" << endl;

    if (isDead)
        cout << "몬스터를 처치했습니다" << endl;
    else if(hp<=20) // if else 중첩하는 대신 가독성을 위해 else if를 이용한다!
        cout << "몬스터가 도망갔습니다" << endl;
    else
        cout << "몬스터가 반격했습니다" << endl;

    
    // switch-case-break문
    // - 정수 계열 타입과 열거형 타입만 조건문에 넣을 수 있다!!!!
    // 참고) C샵과 자바에서는 스트링도 넣을 수 있음
    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSORS = 2;

    int input = ROCK;

    // 가독성과 코드반복을 줄이기 위함
    switch(input)
    {
    case ROCK:
        cout << "바위를 냈습니다" << endl;
        break; // switch를 빠져나감
    case PAPER:
        cout << "보를 냈습니다" << endl;
        break;
    case SCISSORS:
        cout << "가위를 냈습니다" << endl;
        break;
    default: // else
        cout << "뭘 낸겁니까?" << endl;
    }
}