#include <iostream>
using namespace std;

// 오버로딩 (중복 정의 : 함수 이름의 재사용)
// - 호출하는 쪽에서 어느 함수를 호출할지 분명히 구분할 수 있어야함!
// - 매개변수 갯수가 다르거나
// - 매개변수 타입이 다르거나 (순서가 다른걸 포함)
// 참고) return type만 다른 건 안된다!!!!

int Add(int a, int b=0)
{
    int result = a + b;
    return result;
}
// int Add(int a) { // 애매함
//     int result = a + 1;
//     return result;
// }
float Add(float a, float b) 
{
    float result = a + b;
    return result;
}

// 기본 인자값 세팅 (매개변수 중 마지막에 와야 함)
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0, int castleId = 0)
{
    // 앞의 세 인자만 들어올 경우, 그 뒤의 것들은 기본 인자값으로 세팅!!
}

// 스택 오버 플로우
int Factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * Factorial(n - 1); // n! = n * (n-1)!
}

int main()
{
    float result = Add(1.5f, 2.1f); // 매개변수를 보고 두번째 함수가 호출됨
    cout << result << endl;

    SetPlayerInfo(100, 40, 10);

    int facto = Factorial(1000000); // Exception has occurred (처리되지 않은 예외가 있습니다)
                                    // 로직으로는 맞지만 재귀를 너무많이 해서 스택 메모리를 초과해 버림
    cout << facto << endl;

    return 0;
}