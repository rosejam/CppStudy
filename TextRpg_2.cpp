#include <iostream>
using namespace std;

// 포인터 실습
// 전역변수 말고 지역변수를 사용한다

struct StatInfo
{
    int hp; // +0
    int attack; // +4
    int defence; // +8 오프셋
};

void EnterLobby();

StatInfo CreatePlayer(); // 포인터를 배우기 이전 버전 (리턴 값으로 받아 복사)
void CreateMonster(StatInfo* info); // 포인터를 배운 이후 버전! (포인터를 받아 직접 수정)

void StartBattle();


int main()
{
    EnterLobby();
    
    return 0;
}

void EnterLobby()
{
    cout << "로비에 입장했습니다" << endl;

    StatInfo player;
    player.hp = 0xbbbbbbbb;
    player.attack = 0xbbbbbbbb;
    player.defence = 0xbbbbbbbb;
    // [매개변수][RET][지역변수(temp, player)] [매개변수(&temp)][RET][지역변수(ret)]
    // 1. 지역변수 temp를 만들고 주소인 &temp를 매개변수에 전달
    player = CreatePlayer(); // 4. player에 temp를 복사

    StatInfo monster;
    monster.hp = 0xbbbbbbbb;
    monster.attack = 0xbbbbbbbb;
    monster.defence = 0xbbbbbbbb;
    // [매개변수][RET][지역변수(monster)] [매개변수(&monster)][RET][지역변수()]
    CreateMonster(&monster); // 1. 지역변수 monster의 주소 &monster를 매개변수에 전달

    // 번외 1)
    // 구조체끼리 복사할 때 무슨 일이 벌어질까?
    // player = monster;
    // 내부적으로 각 요소를 하나하나 복사한다!! 
    // player.hp = monster.hp;
    // player.attack = monster.attack;
    // player.defence = monster.defence;

    StartBattle();
}

StatInfo CreatePlayer() // &temp
{
    StatInfo ret; 

    cout << "플레이어 생성"  << endl;
    
    // 2. 지역변수 ret를 만들고 값 변경
    ret.hp = 100;
    ret.attack = 10;
    ret.defence = 2;

    // 3. temp에 ret을 복사
    return ret; 
}

void CreateMonster(StatInfo* info)
{
    cout << "몬스터 생성"  << endl;

    // 2. 직접 monster의 값 변경
    info->hp = 40;
    info->attack = 8;
    info->defence =1;
}