#include <iostream>
using namespace std;

// 함수 (프로시저, 메소드, 루틴)

/*
input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다

반환타입 함수이름( [인자타입 매개변수] )
{
    함수 내용

    return 반환내용;
}
*/

// return할 것이 없으면 void
// 매개변수가 없을 경우 void 또는 비워두기
void PrintHelloWorld()
{
    cout << "Hello World" << endl;
    // return; // ret인스트럭션. 즉시 함수에서 빠져나감!!
}

// 입력을 매개변수 number로 전달받아 출력
void PrintNumber(int number) 
{
    cout << "넘겨주신 숫자는 " << number << "입니다" << endl;
}

int MultiplyBy2(int a)
{
    return a * 2;  // 반환타입에 맞게 꼭 리턴을 해줘야 한다.
}

int Calc (int a, int b) // 함수에서 매개변수 이름은 전달받은 인자에 접근하기 위한 명명일 뿐!!
{
    int c = a * 2 + b;
    return c;
}

int main()
{
    PrintHelloWorld(); // 함수 호출 // 기능 단위로 함수로 묶어두면 편리

    int result = MultiplyBy2(3);
    PrintNumber(result);

    int b = 5;
    int a = 3;
    result = Calc(b, a);
    PrintNumber(result);

    // return 0; // 생략
}