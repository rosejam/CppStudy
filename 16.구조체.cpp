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
// 컴퓨터가 연산을 위해 패딩을 넣기 때문에 구조체의 크기는 내용의 합보다 같거나 클 수 있다!
struct ObjectInfo
{
    int type;
    int hp;
    int attack;
    int defence;
};
ObjectInfo playerInfo; // 전역 변수와 같이 접근한다 (ptr [rip+_playerInfo])
ObjectInfo monsterInfo;

int main()
{
    ObjectInfo playerInfo2; // 지역 변수와 같이 접근한다 (ptr [rbp - 16])
    // cout << playerInfo.type << " " << playerInfo2.type;
}