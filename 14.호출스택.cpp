#include <iostream>
using namespace std;

// 함수 호출 : 인셉션의 꿈꾸는 것과 유사
// - 디버거에서 호출 스택!!!!을 보면 "현재 함수의 호출 경로"를 한눈에 추적 가능!!
//      (= 현재 스택 메모리의 ret주소값들을 모두 순서대로 나열!!)


// 함수 선언 (보통 별도의 파일에 관리함)
// 함수이름 / input / output 데이터 타입 정의만 해둠
void Func1();
void Func2(int c, int d);
void Func3(float);  // 매개변수 이름은 생략 가능
// 선언을 하면 함수 호출 시 ip가 이동할 구현부분 코드의 위치를 알 수 있다!!!

// 구현 안할 경우 error: linker command failed (코드의 위치를 알 수 없다)
// 선언 안할 경우 error: use of undeclared identifier (식별자를 찾을 수 없습니다)

// 함수 구현
void Func1() 
{
    cout << "Func1" << endl;
    
    Func2(1, 2);  // error (이 코드 위에 해당 함수에 대한 언급이 없기 때문)

    Func3(10.0f); // error
}
void Func2(int a, int b) 
{
    cout << "Func2" << endl;
    Func3(10);  // error
}
void Func3(float a) 
{
    cout << "Func3" << endl; // 여기에 bp를 잡고 실행 시키면 처음엔 Func2, 그다음엔 Func1에서 호출된 것 확인 가능!!
}

int main()
{
    cout << "main" << endl;
    Func1();

    return 0;
}