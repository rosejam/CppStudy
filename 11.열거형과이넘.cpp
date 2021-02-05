#include <iostream>
using namespace std;

// 상수인건 알겠는데 너무 따로 노는 느낌?
// 나중에 값을 지정할 수도 없음
const int CONST_SCISSORS = 1;
const int CONST_ROCK = 2;
const int CONST_PAPER = 3;
// 경우에 따라서 메모리에 올라갈 수도, 그냥 상수로 치환될 수도 있다.

// 하나의 enum으로 관리되는 정수들
// 숫자를 지정 안하면 첫 값은 0
// 그 다음 값들은 이전 값 +1 
enum SRP // (enum 이름)
{
    ENUM_SCISSORS = 1,
    ENUM_ROCK, //2
    ENUM_PAPER //3
}; // 여기 ;빼먹지 말기!!!
// 컴파일 단계에서 완벽하게 치환된다!! (메모리에 올라가지 않음) -> 추천!

// #이 붙은거 -> 전처리 지시문
// 빌드 : 1)전처리-기초작업 2)컴파일-통역 3)링크-파일단위로엮기

// #include <iostream> : iostream이라는 파일을 찾아서 해당 내용을 그냥 복붙해주세요!
// #define 은 코드 매크로! 코드를 그대로 복붙 하는 기능
// 그대로 복붙이라 애매해 질 수 있으므로 상수에는 사용 지양
#define DEFINE_SCISSORS 1
#define DEFINE_ROCK 2
#define DEFINE_PAPER 1+2 // (1+2)
#define DEFINE_TEST cout << "Hello World" << endl;

int main()
{
    // auto a = &CONST_SCISSORS; // CONST_SCISSORS가 메모리에 올라가게 된다
    int value = ENUM_ROCK;

    DEFINE_TEST
    int result = DEFINE_PAPER * 2; // 6이 아닌 5가 된다!!! // 코드가 그대로 바꿔치기 되었기 때문
}