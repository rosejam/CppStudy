#include <iostream>
using namespace std;

// 데이터 연산
// 데이터를 가공하는 방법에 대해서 알아봅시다

int a = 1;  // a[1] : a라는 이름의 바구니를 메모리에 할당하고 안에 1을 넣는다.
int b = 2;

bool isSame;
bool isDifferent;
bool isGreater;
bool isLesser;

bool test;

int hp = 100;
bool isInvincible = true;

int main() {
#pragma region 비교 연산
    // 언제 필요한가?
    // ex) 체력이 0이 되면 사망
    // ex) 체력이 30% 이하이면 궁극기를 발동 (100* hp / maxHp)
    // ex) 경험치가 100 이상이며 레벨업
    
    // 참이면 1 거짓이면 0의 bool값을 리턴함!!
    isSame = (a == b);  // a의 값과 b의 값이 같은가?
    isDifferent = (a != b); // a의 값과 b의 값이 다른가??
    isGreater = (a > b);
    isLesser = (a < b);

    // 비교연산의 결과는 bool
#pragma endregion

#pragma region 논리 연산
    // 언제 필요한가?
    // ex) 로그인할 때 아이디도 같고 AND 비밀번호도 같아야 한다
    // ex) 길드 마스터 이거나 OR 운영자 계정이면 길드 해산 가능

    // ! (not, 논리 toggle)
    // 0이면 1, 그 외 0
    test = !isSame; // 사실상 isDifferent의 의미

    // && and
    // 둘다 1이면 1, 그 외 0
    test = (hp <= 0 && isInvincible == false); // 죽음

    // || or
    // 둘다 0이면 0, 그 외 1
    test = (hp > 0 || isInvincible == true); // 살았음(사실상 !죽음과 같다)

    // &&의 앞이 0이면 바로 0, ||의 앞이 1이면 바로 1 (뒤는 확인안하고 그대로 패스!)
#pragma endregion
}