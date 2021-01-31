#include <iostream>
using namespace std;

// 데이터 연산
// 데이터를 가공하는 방법에 대해서 알아봅시다

unsigned char flag; // 부호를 없애야 >>를 하더라도 부호비트가 딸려오지 않음!

// const : 한번 정해지면 절대 바뀌지 않을 것들. 이후에 수정되지 않음
// constant의 약자(변수를 상수화 한다고 함!)
// const를 붙였으면 초기값을 반드시 지정해야 함

// 0b0000 [무적][공포][변이][스턴][띄워짐]
// 이 부분을 하드코딩 하지 않기 위해 const 사용!!
const int INVINCIBLE = 4;
const int FEAR = 3;
const int POLYMORPH = 2;
const int STUN = 1;
const int AIRBORNE = 0;

int main() 
{
#pragma region 비트 연산
    // 언제 필요한가? (사실 많이는 필요없음)
    // 비트 단위의 조작이 필요할 때
    // - 대표적으로 BitFlag (각 비트 위치에 의미 부여하는 것!!!)

    // ~ (bitwise not, 모든 비트를 toggle)
    // 단일 숫자의 모든 비트를 대상으로 0 <-> 1로 뒤바꿈

    // & bitwise and
    // 두 숫자의 모든 비트 쌍을 대상으로 and

    // | bitwise or
    // 두 숫자의 모든 비트 쌍을 대상으로 or

    // ^ bitwise xor
    // 두 숫자의 모든 비트 쌍을 대상으로 xor (다르면 1, 그 외 0)
    // 같은 숫자끼리 xor하면 모두 0이 됨!
    int a = 1;
    int b = 123;
    a = a ^ b;
    a = a ^ b; // 같은 수로 두번 xor하면 원래대로 돌아옴!!

    // << 비트 좌측 시프트
    // 비트열을 N만큼 왼쪽으로 이동
    // 왼쪽의 넘치는 N개의 비트는 버린다(복원되지 않음). 오른쪽에 새로 생성되는 N개의 비트는 0.
    // *2를 할 때 컴파일러가 자주 보이는 패턴

    // >> 비트 우측 시프트
    // 비트열을 N만큼 오른쪽으로 이동
    // 오른쪽의 넘치는 N개의 비트는 버린다(복원되지 않음).
    // 왼쪽에 새로 생성되는 N개의 비트는
    // - signed인 경우 부호비트를 복사하여 채워짐!!!!
    // - unsigned인 경우 0

    // BitFlag실습
    // // 0b0000 [무적][변이][스턴][띄워짐]
    // const int INVINCIBLE = 3;
    // const int POLYMORPH = 2;
    // const int STUN = 1;
    // const int AIRBORNE = 0;

    // 무적 상태로 만든다
    flag = (1 << INVINCIBLE);  //0b1000
    
    // 변이 상태를 추가한다
    flag |= (1 << POLYMORPH);

    // 무적인지 확인하고 싶다
    // bitmask
    bool invincible = ((flag & (1 << INVINCIBLE)) != 0); // flag의 무적 비트만 남기고 다 0으로 만드는 마스크를 씌우고 해당 비트 확인

    // 무적이거나 스턴 상태인지 확인하고 싶다
    int mask = (1 << INVINCIBLE) | (1 << STUN);
    bool stunOrInvincible = ((flag & mask) != 0);

#pragma endregion
}