#include <iostream>
using namespace std;

// 포인터 vs 배열 : 같은 것 같지만 완전히 다름!!!

void Test(int a)
{
    a++;
}

// 배열을 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 받는다 (TYPE[] -> TYPE*) !!!!!!!
// 즉, 배열의 내용 전체를 넘긴 것이 아니라 시작 주소(포인터)만 넘긴 것
void Test(char a[]) // void Test(char* a)로 알아서 바뀐다!
{
    a[0] = 'X'; // 따라서 원본을 수정한다!
}

int main()
{
    // 문자열 = 문자 배열 = "const" char[] !!!
    // (C스타일의 문자열은 '\0' 널로 끝난다)
    cout << "Hello" << endl;
    const char msg[] = { 'H','e','l','l','o','\0' }; // 아스키 코드의 값이 정수로 들어있음. 위와 동일!
    // msg[1] = 'x'; // const에 막힘 
    cout << msg << endl;


    // 포인터는 [주소를 담는 바구니] 즉, 바구니 모음의 시작 주소를 담는다 !!!
    // test1[ 주소 ]  ----------가리킴---------->  (.rodata영역의 ) 주소[H][e][l][l][o][][W][o][r][l][d][\0]
    const char* test1 = "Hello World"; // test1은 8바이트 고정
    
    // 배열은 [닭장] 즉, 그 자체로 같은 데이터끼리 붙어있는 [바구니 모음] !!!
    // test2 -----> 주소[][][][][][][][][][][][]  <-값복사-  (.rodata영역의 ) [H][e][l][l][o][][W][o][r][l][d][\0]
    char test2[] = "Hello World"; // test2는 문자열의 길이 크기 (12바이트)
    // 다만 C++ 문법에서 [배열 이름]은 <바구니 모음의 시작주소>를 가지는 포인터로 변환된다!!!!!
    // 즉, test2는 주소 !!!!!!! (디버거에서도 &test2뿐만 아니라 test2도!!! 배열의 주소값을 나타냄)
    // test2[ 주소 ] // <- 그러나 이런건 없음 !!!!!!! test2가 주소를 담는 바구니는 아니니까!

    // test1[0] = 'R'; // const에 막힘
    test2[0] = 'R';
    cout << test2 << endl;
    cout << endl;


    // 배열을 함수의 인자로 넘기게 되면?
    int a = 0;
    // [매개변수][RET][지역변수(a=0)] [매개변수(a=1)][RET][지역변수]
    Test(a); // 복사를 통해 전달
    cout << a << endl;

    // test2가 바뀔까? 안바뀔까? -> 바뀐다!
    Test(test2); // 배열을 인자로 넘길 때는 "시작 주소값"만 넘긴다!
    cout << test2 << endl;
    cout << endl;


    char test3[12];
    // test3 = test2; // 바구니가 아니고 둘다 주소이기 때문에 복사가 안됨!!!!
    *(test3 + 0) = *(test2 + 0);
    *(test3 + 1) = *(test2 + 1);
    cout << test3 << endl;

    return 0;
}