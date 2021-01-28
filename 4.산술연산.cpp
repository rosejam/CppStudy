#include <iostream>
using namespace std;

// 데이터 연산
// 데이터를 가공하는 방법에 대해서 알아봅시다

int a = 1;  // a[1] : a라는 이름의 바구니를 메모리에 할당하고 안에 1을 넣는다.
int b = 2;

int main() 
{
#pragma region 산술 연산 접기
    // 산술 연산자

    // a에 b를 대입하고 a를 반환하라
    // -> b라는 바구니 안에 있는 값을, a라는 바구니 안에다 복사한다
    // 대입연산
    a = b;
    
    // 사칙연산
    // 언제 필요한가?
    // ex) 데이미 계산. 공격, 힐 등
    // ex) 루프문에서 카운터를 1 증가시킨다거나
    a = b + 3; // add
    a = b - 3; //sub
    a = b * 3; //mul
    a = b / 3; //div몫
    a = b % 3; //div나머지
    a += 3;    // a = a + 3;

    // 증감 연산자 (연산자가 앞에 오면 먼저 연산, 뒤에 오면 나중에 연산!!)
    //inc
    b=a++;b=++a;
    //dec
    b=a--;b=--a;

    // 연산자들간 우선순위가 존재
#pragma endregion
}