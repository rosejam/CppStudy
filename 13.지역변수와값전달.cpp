#include <iostream>
using namespace std;

// 전역 변수
// 함수 밖에서 정의
// "데이터 영역"에 들어감!!
// 참고) 초기화 여부, const 등 .rodata .data .bss
// 모든 함수가 접근해서 수정할 수 있으므로 에러 추적이 어려울 수도있음
int globalValue = 0;

void Test()
{
    cout << "전역 변수의 값은 : " << globalValue << endl;
    globalValue++;
}

void IncreaseHp(int hp)
{
    hp = hp + 1; // 전달받은 매개 변수를 수정 (main의 지역변수인 hp를 수정하는 것이 아님!!!!)
    // int finalHp = hp + 1; // 이 함수의 지역 변수를 수정
}

int main()
{
    cout << "전역 변수의 값은 : " << globalValue << endl;
    globalValue++;
    Test();

    cout << endl;

    // 지역 변수
    // 함수 안에서 정의
    // "스택 영역"에 들어감!!
    int hp = 1;

    cout << "Increase 호출 전 : " << hp << endl;
    // [매개변수][ret할주소][이전bp값][지역변수(hp=1)] [매개변수(hp=2)][ret할주소][이전bp값][지역변수]
    IncreaseHp(hp); // 지역변수 "hp안의 값"을 push해서 매개변수로 전달!!!!
    // [매개변수][ret할주소][이전bp값][지역변수(hp=1)]
    cout << "Increase 호출 후 : " << hp << endl;

    return 0;
}