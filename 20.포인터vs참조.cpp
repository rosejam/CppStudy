#include <iostream>
using namespace std;

struct StatInfo
{
    int hp; // +0
    int attack; // +4
    int defence; // +8 오프셋
};

void CreateMonster(StatInfo* info) // info = &monster
{
    info->hp = 40;
    info->attack = 8;
    info->defence =1;
}

void PrintInfoByPtr(StatInfo* info) // info = &monster
{
    cout << "--------------------" << endl;
    cout << "HP : " << info->hp << endl;
    cout << "ATT : " << info->attack << endl;
    cout << "DEF : " << info->defence << endl;
    cout << "--------------------" << endl;
}

void PrintInfoByRef(StatInfo& info)
{
    cout << "--------------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATT : " << info.attack << endl;
    cout << "DEF : " << info.defence << endl;
    cout << "--------------------" << endl;
}

int main()
{
    StatInfo monster;
    CreateMonster(&monster);

    PrintInfoByPtr(&monster);
    PrintInfoByRef(monster);

    return 0;
}