#include <iostream>
using namespace std;

// int playerType;
// int hp;
// int attack;
// int defence;

// int monsterType;
// int monsterHp;
// int monsterAttack;
// int monsterDefence;

// 아래와 같이 플레이어, 몬스터 정보들을 한번에 묶어서 관리!
// (어셈블리어에선 따로 변수를 만드는 것과 크게 다르지 않다!)
// 컴퓨터가 연산을 위해 패딩을 넣기 때문에 구조체의 크기는 내용의 합보다 같거나 클 수 있다!
struct ObjectInfo
{
    int type; // +0 (구조체 시작주소를 기준으로, 요소의 시작주소의 위치 (=오프셋)!!!!)
    int hp; // +4
    int attack; // +8
    int defence; // +12
}; // 총 16바이트 크기
// 구조체도 변수

ObjectInfo playerInfo; // 전역 변수와 같이 접근한다 (ptr [rip+_playerInfo])
ObjectInfo monsterInfo;

int main()
{
    ObjectInfo playerInfo2; // 지역 변수와 같이 접근한다 (ptr [rbp - 16])

    playerInfo.type = 11;
    playerInfo2.type = 12;
    cout << playerInfo.type << " " << playerInfo2.type << endl;

    playerInfo = playerInfo2; // 구조체는 일반 변수와 마찬가지로 복사가 된다 !!!!!
    playerInfo.type = 13;
    cout << playerInfo.type << " " << playerInfo2.type << endl;
}