#include <iostream>
using namespace std;

// 포인터 실습!!!!
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

bool StartBattle(StatInfo* player, StatInfo* monster); // player승리 시 true, 아니면 false


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
    // [매개변수][RET][지역변수(player, temp)] [매개변수(&temp)][RET][지역변수(ret)]
    player = CreatePlayer(); // 1. 지역변수 temp의 주소 &temp를 매개변수에 전달
    // 4. player에 temp를 복사 ( player = (temp2 = temp); )
    // 복사가 여러번 일어남ㅜ

    StatInfo monster;
    monster.hp = 0xbbbbbbbb;
    monster.attack = 0xbbbbbbbb;
    monster.defence = 0xbbbbbbbb;
    // [매개변수][RET][지역변수(monster)] [매개변수(&monster)][RET][지역변수()]
    CreateMonster(&monster); // 1. 지역변수 monster의 주소 &monster를 매개변수에 전달
    // 포인터를 직접 사용하면 훨씬 빠르고 간단!

    // 번외 1)
    // 구조체끼리 복사할 때 무슨 일이 벌어질까?
    // player = monster;
    // 내부적으로 각 요소를 하나하나 복사한다!
    // player.hp = monster.hp;
    // player.attack = monster.attack;
    // player.defence = monster.defence;


    bool victory = StartBattle(&player, &monster);

    if (victory)
        cout << "승리!" << endl;
    else 
        cout << "패배!" << endl;
}

StatInfo CreatePlayer() // &temp
{
    StatInfo ret; 

    cout << "플레이어 생성"  << endl;
    
    // 2. 지역변수 ret의 값 변경
    ret.hp = 100;
    ret.attack = 10;
    ret.defence = 2;

    // 3. temp에 ret를 복사 (*(&temp) = ret;)
    // 참고) x64에선 매개변수 &temp를 전달받지 않고 지역변수 temp에서 지역변수 temp로 복사한다.
    return ret;
}

void CreateMonster(StatInfo* info) // info = &monster
{
    cout << "몬스터 생성"  << endl;

    // 2. 직접 monster의 값 변경
    info->hp = 40;
    info->attack = 8;
    info->defence =1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
    while (true) // 방어가 너무 높을 경우 영영 벗어나지 못할 수 있다
    {
        int damage = player->attack - monster->defence;
        if (damage < 0)
            damage = 0;
    
        monster->hp -= damage;
        if (monster->hp < 0)
            monster->hp = 0;
        
        cout << "몬스터 HP : " << monster->hp << endl;

        if (monster->hp ==0)
            return true;
        
        damage = monster->attack - player->defence;
        if (damage < 0)
            damage = 0;
        
        player->hp -= damage;
        if(player->hp < 0)
            player->hp = 0;
        
        cout << "플레이어 HP : " << player->hp << endl;

        if (player->hp == 0)
            return false;
    }
}