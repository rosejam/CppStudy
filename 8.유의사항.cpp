#include <iostream>
using namespace std;

// 1) 변수의 유효 범위

// 함수 밖의 전역 변수
// 어디서든 접근할 수 있다
int hp = 10;

// 함수 안의 지역 변수. 스택
// { } 중괄호의 범위가 생존 범위
// 같은 이름 두번 사용할 때 문제 발생

// 2) 연산 우선순위
// ( ) 소괄호로 확실하게 지정 가능

// 3) 타입 변환
// 바구니 교체
// 캐스팅

// 4) 사칙 연산 관련
// 곱셈
// - 오버플로우 (ex) int*int = int )
// - 애초에 long long 끼리 곱하거나, 연산 중간에 캐스팅 하거나 해야 함!!
// 나눗셈
// - 0으로 나누기 조심
// - 실수 관련 (ex) int/int = int로 소숫점 버림 )

int main()
{
    //1)
    { // 중괄호를 사용해서 변수의 생존 범위를 지정할 수 있음
        int hp = 100;
        cout << hp << endl;
    }
    int hp = -1; // 전역변수와 이름 겹치지만 허용되긴 한다 (권장X)
    // int hp = 100; // error: redefinition. 재정의 (위 변수와 유효 범위가 겹친다.)
    // 같은 함수 내에서 '다른 바구니에 같은 이름을 붙일 수 없다'!!

    //2)
    bool isEven = ((hp % 2) == 0);
    bool isEvenOrDivBy3 = ((hp % 2) == 0) || ((hp % 3) == 0);

    //3)
    short hp2 = hp; // 큰->작은 바구니 : 상위 비트가 짤린 상태로 저장
    float hp3 = hp; // 실수로 변환할 때 정밀도 차이가 있기 때문에 어느정도 데이터 손실!!!
    unsigned int hp4 = hp; // 비트단위로 보면 똑같은데(모두 1인 4바이트), 분석하는 방법이 달라져서 
                           // -1 또는 2^32-1 로 볼 수 있다

    //4)
    hp = 123;
    maxHp = 1000;
    float ratio = hp / maxHp; // 0.0 (int끼리 나누기면 결과도 int)
    ratio = hp / (float)maxHp;
}

void Test()
{

}