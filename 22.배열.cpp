#include <iostream>
using namespace std;

struct StatInfo
{
    int hp = 0xAAAAAAAA;
    int attack = 0xBBBBBBBB;
    int defence = 0xDDDDDDDD; // 초기값 세팅
};

int main()
{
    // StatInfo monster_1;
    // StatInfo monster_2;
    // StatInfo monster_3;
    // 근데 몬스터가 최대 1만 마리라면!
    // 반복문을 활용할 수 있어야 함
    // 같은 타입의 데이터들을 묶어서 한방에 관리

    // 배열
    // TYPE 이름[개수]
    // 배열의 크기(개수/길이)는 상수여야 함 (VC 컴파일러 기준)
    const int monsterCount = 10;
    StatInfo monsters[monsterCount];

    // 여태껏 변수들의 이름은 바구니의 이름이었음
    // 그런데 배열은 '이름'이 조금 다르게 동작한다
    // StatInfo players[10];
    // players = monsters; // 에러!!

    // 그럼 "배열의 이름"은 뭐지?
    // 곧 배열의 시작 주소
    // 정확히는 <배열의 시작 위치를 가리키는 TYPE* 포인터> !!!!!
    auto WhoAmI = monsters; // (auto는 자동으로 맞춰주는 타입)

    StatInfo* monster_0 = monsters; // 맨 처음 StatInfo 바구니를 가리킨다
    // 주소[ (100,10,1) ] StatInfo[  ] ... StatInfo[  ] StatInfo[  ]  : 연속된 10개의 StatInfo바구니
    // monster_0[ 주소 ]
    monster_0->hp = 100;
    monster_0->attack = 10;
    monster_0->defence = 1;
    
    // 포인터의 산술연산!!!
    // 진짜 1을 더하라는게 아니라, StatInfo타입 바구니 한개(12Byte)씩 이동하라는 의미
    StatInfo* monster_1 = monsters + 1; // 다음 StatInfo 바구니를 가리킨다
    // StatInfo[  ] 주소[ (200,20,2) ] ... StatInfo[  ] StatInfo[  ] 
    // monster_1[ 주소 ]
    monster_1->hp = 200;
    monster_1->attack = 20;
    monster_1->defence = 2;

    // 포인터와 참조는 자유자재로 변환 가능하다
    StatInfo& monster_2 = *(monsters + 2);
    // StatInfo[  ] StatInfo[  ] monster_2,주소[ (300,30,3) ] ... StatInfo[  ] StatInfo[  ] 
    // monster_2[ 주소 ]
    monster_2.hp = 300;
    monster_2.attack = 30;
    monster_2.defence = 3;

    // [주의] 위와 이거는 완전 다른 의미이다
    StatInfo temp = *(monsters + 2); // 내용물 복사!!!!
    // StatInfo[  ] StatInfo[  ] 주소[ (300,30,3) ] ... StatInfo[  ] StatInfo[  ] 
    // temp[ (400,40,4) ] : (원본은 바뀌지 않음)
    temp.hp = 400;
    temp.attack = 40;
    temp.defence = 4;
    

    // 배열 순회를 자동화 한다
    for (int i = 0; i < 10; i++)
    {
        StatInfo& monster = *(monsters + i);
        monster.hp = 100 * (i + 1);
        monster.attack = 10 * (i + 1);
        monster.defence = 1 * (i + 1);
    }
    // 참고) i가 유효한 배열 범위를 벗어나면 오류를 발생시킬 수 있다!

    // 근데 *(monsters + i) 부분은 너무 불편하고 가독성이 떨어진다... 더 편한 방법?
    // 인덱스!!
    // 배열은 0번부터 시작. N번 인덱스에 해당하는 데이터에 접근하려면 : 배열이름[N]
    // *(monsters + i) 와  monsters[i] 는 완전히 동일한 의미 !!!!!
    // 둘다 i번 인덱스의 데이터에 접근!
    monsters[0].hp = 100;
    monsters[0].attack = 10;
    monsters[0].defence = 1;
    int hp = monsters[0].hp;

    for (int i = 0; i < 10; i++)
    {
        StatInfo& monster = monsters[i];
        monster.hp = 100 * (i + 1);
        monster.attack = 10 * (i + 1);
        monster.defence = (i + 1);
    }

    // 배열 초기화 문법 몇가지
    // int numbers[5]; // 영역만 할당, 초기화는 안되어있음
    int numbers[5] = {}; // 하나하나 0으로 밀어버린다
    int numbers1[10] = { 1,2,3,4,5 }; // 앞에 부터 설정한 애들은 설정한 값들로, 나머지 값들은 0으로 초기화
    int numbers2[] = { 1,2,3,4,11,24,124,14,1 }; // 데이터 개수만큼의 크기에 해당하는 배열로 만들어준다
    char helloStr[] = { 'H','e','l','l','o','\0'};
    cout << helloStr << endl;

    // 배열 요약 : 
    // 1) 선언한다
    int arr[10] = { };

    // 2) 인덱스로 접근해서 사용
    arr[1] = 1;
    cout << arr[1] << endl;

    return 0;
}