#include <iostream>
using namespace std;

struct StatInfo
{
    int hp; // +0
    int attack; // +4
    int defence; // +8 오프셋
};

void CreateMonster(StatInfo* info)
{
    info->hp = 40;
    info->attack = 8;
    info->defence =1;
}

// 특정 조건을 만족하는 몬스터를 찾는 함수
StatInfo* FindMonster()
{
    // TODO : Heap 영역에서 뭔가를 찾아봄
    // 찾았다
    // return monster;
    // 아니면
    return nullptr;
}

StatInfo globalInfo;
void PrintInfoByPtr(StatInfo* info)
{
    if (info == nullptr) // if (!info)
        return; // 포인터 이므로 널 체크 안해주면 크래시 발생 가능


    // info [  &monster  ]    ------->    monster [  데이터  ]

    // StatInfo* const info
    // 별 뒤에 붙인다면? 아래 명령이 막힘
    // info = &globalInfo; // 다른 주소값으로 변경. 포인터가 다른 곳을 가리키게 됨
    // info라는 바구니의 내용물(주소)를 바꿀 수 없음
    // info안의 주소값이 고정이다! (포탈이 도달하는 곳을 바꿀 수 없음!)

    // const StatInfo* info
    // 별 앞에 붙인다면? 아래 명령이 막힘
    // info->attack = 1000000; // 주소값에 찾아간 데이터를 변경.
    // info가 '가리키고 있는' 바구니의 내용물을 바꿀 수 없음
    // '원격' 바구니의 내용물을 바꿀 수 없음 (포탈을 타고 가서 거기값을 바꿀 수 없음!)

    // 별 양쪽에 둘다 붙여도 됨

    cout << "--------------------" << endl;
    cout << "HP : " << info->hp << endl;
    cout << "ATT : " << info->attack << endl;
    cout << "DEF : " << info->defence << endl;
    cout << "--------------------" << endl;
}

void PrintInfoByRef(const StatInfo& info) // const를 붙였기 때문에 여기선 원본을 수정 불가!!!
{
    // 신입이 왔다
    // info.attack = 100000; // 원본을 막 수정하는 것 방지
    // info = globalInfo; // 레퍼런스가 가리키는 변수 바꾸는 것 방지

    cout << "--------------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATT : " << info.attack << endl;
    cout << "DEF : " << info.defence << endl;
    cout << "--------------------" << endl;
}

#define OUT // 그냥 표시용
void ChangeInfo(OUT StatInfo& info)
{
    info.attack = 100000;
}

int main()
{
    StatInfo monster;
    CreateMonster(&monster);

    // 포인터 vs 참조
    // 성능 : 똑같음!
    // 편의성 : 참조 승!
    
    // 1) 편의성 관련
    // 편의성이 좋다는게 꼭 장점만은 아니다.
    // 포인터는 주소를 넘기니 확실하게 '원본'을 넘긴다는 힌트를 줄 수 있는데,
    // 참조는 자연스럽게 모르고 지나칠 수 있음!
    // ex) 마음대로 고친다면?
    // 레퍼런스에 const를 사용해서 이런 마음대로 고치는 부분 개선 가능

    // 참고로 포인터도 const를 사용 가능
    // * 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라진다!!!!


    // 2) 초기화 여부
    // 참조 타입은 바구니의 2번째 이름
    // 어떤 유효한 대상을 가리키고 있어야 한다는 제약 사항이 있다고 보면 됨
    // -> 참조하는 대상이 없으면 안됨!!
    // 반면 포인터는 그냥 어떤 주소 라는 의미
    // -> 대상이 실존하지 않을 수도 있음

    StatInfo* pointer; //가능
    pointer = &monster;
    PrintInfoByPtr(pointer);
    pointer++; // 가능

    // StatInfo& reference; // 이건 안됨!
    // reference = monster;
    StatInfo& reference = monster;
    PrintInfoByRef(reference); // 원본을 넘긴다는게 티가 안난다는 단점!!
    // reference++; // 이것도 안됨!!

    // 포인터에서 '없다, 아무것도 안가리키고 있다'는 의미로?
    pointer = nullptr; // 0x0, 주소 0

    pointer = FindMonster(); // 장점 : 주소가 있는지 없는지, 상태를 구분할 수 있음!!!!
    PrintInfoByPtr(pointer); // 단점 : 유효하지 않은 주소 접근 시 에러 발생!!!! (pointer->hp 등)

    // 참조타입은 이런 nullptr의 개념이 없다.
    // 단점 : '없다'를 표현할 수 없음
    // 장점 : 유효하지 않은 주소로 인한 에러X


    // 그래서 결론은?
    // 사실 Team By Team... 정해진 답은 없다
    // ex) 구글에서 만든 오픈소스를 보면 거의 무조건 포인터 사용
    // ex) 언리얼 엔진에선 reference도 애용

    // - 없는 경우도 고려해야 한다면 ptr
    // - 바뀌지 않고 읽는 용도만(read only)만 사용하면 const ref&
    // - 명시적으로 ref를 전달하여 값을 수정할 때 OUT을 붙이면 가독성이 좋아진다.
    ChangeInfo(OUT reference);
    
    // 가독성을 위해, ptr과 ref를 섞어 사용하지 않도록 한다.

    pointer = &monster;
    // pointer [ &monster ] -----> reference, monster[ 데이터 ]
    // Bonus) 포인터로 사용하던걸 참조로 넘겨주려면?
    PrintInfoByRef(*pointer);
    // Bonus) 참조로 사용하던결 포인터로 넘겨주려면?
    PrintInfoByPtr(&reference);

    return 0;
}