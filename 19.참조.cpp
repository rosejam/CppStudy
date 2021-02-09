#include <iostream>
using namespace std;

struct StatInfo
{
    int hp; // +0
    int attack; // +4
    int defence; // +8 오프셋
};

// [매개변수][RET][지역변수(monster)] [매개변수(&monster)][RET][지역변수()]
void CreateMonster(StatInfo* info) // info = &monster
{
    info->hp = 40;
    info->attack = 8;
    info->defence =1;
}

// 참고용) CreateMonster(monster); 해서 매개변수를 StatInfo타입으로 전달한다면?!
// [매개변수][RET][지역변수(monster)] [매개변수(monster)][RET][지역변수()]
void CreateMonster(StatInfo info) // info = monster (monster의 값이 통째로 복사되어 info에 전달된다!!!!)
{
    // 지역변수 monster가 아닌 매개변수 info를 수정하고 있다.
    info.hp = 40;
    info.attack = 8;
    info.defence =1;
}

// 원본값을 수정하지 않는다면, 양쪽 다 일단 문제 없음

// 1) 값 전달 방식 : 원본을 매개변수에 복사해서 복사본을 print
// [매개변수][RET][지역변수(monster)] [매개변수(monster)][RET][지역변수]
void PrintInfoByCopy(StatInfo info) // info = monster 복사
{
    cout << "--------------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATT : " << info.attack << endl;
    cout << "DEF : " << info.defence << endl;
    cout << "--------------------" << endl;
}

// 2) 주소 전달 방식 : 주소를 통해 원본에 접근해서 원본을 print
// [매개변수][RET][지역변수(monster)] [매개변수(&monster)][RET][지역변수]
void PrintInfoByPtr(StatInfo* info) // info = &monster
{
    cout << "--------------------" << endl;
    cout << "HP : " << info->hp << endl;
    cout << "ATT : " << info->attack << endl;
    cout << "DEF : " << info->defence << endl;
    cout << "--------------------" << endl;
}

// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사되는 오버헤드가 발생
// - (주소 전달) StatInfo*는 8바이트(주소값)
// - (참조 전달) StatInfo&는 8바이트(주소값)

// 3) 참조 전달 방식 (c에는 없음)
// 값 전달처럼 편리하게 사용하고!
// 주소 전달처럼 주소값을 이용해 원본에 접근하는!
// 일석 이조의 방식!
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
    int number = 1;
    int value = 0;

    int* pointer = &number;

    value = *pointer;
    *pointer = 2;
    
    // 참조 //

    // 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음 
    // 실제로 실행해보면 포인터와 어셈블리 코드가 100% 똑같다!!!! 표현만 다른 것!
    int& reference = number; // 참조변수 reference는 마찬가지로 number의 주소값을 들고 있다!!!

    // C++ 관점에서는 number라는 바구니에 또 다른 이름(reference)을 부여한 것!!!!
    // 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면,
    // 실제 number바구니에다가 그 값을 꺼내거나 넣으면 됨!
    value = reference;
    reference = 3;

    // 그런데 귀찮게 또 다른 이름을 짓는 이유는?
    // number = 3;이라고 해도 똑같은데...
    // 참조 전달 때문!!!!

    // 참고)
    // &를 변수 앞에 쓸 경우 : 주소값을 리턴하라는 뜻
    // &를 변수 선언 시 쓸 경우 : 참조type 변수를 선언하는 것

    StatInfo monster;
    CreateMonster(&monster);

    PrintInfoByCopy(monster);
    PrintInfoByPtr(&monster);
    PrintInfoByRef(monster); // 참조 전달

    return 0;
}