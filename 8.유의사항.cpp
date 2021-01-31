#include <iostream>
using namespace std;

// 1) 변수의 유효 범위

// 함수 밖의 전역 변수
// 어디서든 접근할 수 있다
// int hp = 10;

// 함수 안의 지역 변수. 스택
// { } 중괄호의 범위가 생존 범위
// 같은 이름 두번 사용할 때 문제 발생

int main()
{
    int hp = 10;
    cout << hp << endl;




    // int hp = 100; // error: redefinition. 재정의 (위의 변수와 유효 범위가 겹친다.)
    // 다른 바구니에 같은 이름을 붙일 수 없다!!

    hp = 100;
}

void Test()
{

}