#include <iostream>
using namespace std;

// 데이터 연산
// 데이터를 가공하는 방법에 대해서 알아봅시다

// 함수 밖의 전역 변수
// [데이터 영역]

// .data (초기값있는 경우)
int a = 2;
// .bss (초기값없는 경우, 초기값이 0인 경우)
int b;
// .rodata (읽기 전용 데이터)
const char* msg = "Hello World";

// 그러면 const도 바뀌지 않는 읽기 전용 .rodata?
// 사실 C++표준에서 꼭 그렇게 하라는 말은 없음
// 그냥 컴파일러 마음대로
// .rodata로 메모리에 할당 될 수도, 컴파일러가 INVINCIBLE을 모두 3으로 바꿔치기 해둘 수도 있음
// (gcc에선 바꿔치기 하는 듯)
const int INVINCIBLE = 3;

int main()  // 메인 함수
{
    // const를 함수 내부에서 만들 경우, 스택 영역에 할당된다
    // const int INVINCIBLE = 3;

    // 함수 안의 지역 변수
    // [스택 영역]
    int c = 3;

    int d = 2;
    for(int i=0;i<10;i++)
    {
        d =2;
        d++;
    }
}
