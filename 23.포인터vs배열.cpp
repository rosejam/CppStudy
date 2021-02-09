#include <iostream>
using namespace std;

// 포인터 vs 배열 : 다름!!!

void Test(int a)
{
    a++;
}

// 배열을 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환한다 (char[] -> char*) !!!
// 즉, 배열의 내용 전체를 넘긴 것이 아니라 시작 주소(포인터)만 넘긴 것
void Test(char a[]) // void Test(char *a) 로 알아서 바뀐다
{
    a[0] = 'X';
}

int main()
{
    // 문자열 = 문자 배열 const char[]
    // (C스타일의 문자열은 '\0'로 끝난다)
    cout << "Hello" << endl;
    const char msg[] = { 'H','e','l','l','o','\0' }; // 아스키 코드의 값이 정수로 들어있음
    // msg[1] = 'x'; // const에 막힘 
    cout << msg << endl;

    // 포인터는 [주소를 담는 바구니]
    // test1[ 주소 ]  ------->  (.rodata영역) 주소[H][e][l][l][o][][W][o][r][l][d][\0]
    const char* test1 = "Hello World";
    // test1[0] = 'R';
    
    // 배열은 [닭장] 즉, 그 자체로 같은 데이터끼리 붙어있는 [바구니 모음] !!!
    // test2, 주소[][][][][][][][][][][][]  <-복사-  (.rodata영역) [H][e][l][l][o][][W][o][r][l][d][\0]
    // - 다만 [배열 이름]은 "바구니 모음의 시작 주소"
    // test2[ 주소 ] // 이건 없다!!!!
    char test2[] = "Hello World";
    test2[0] = 'R';
    

    // 배열을 함수의 인자로 넘기게 되면?
    int a = 0;
    // [매개변수][RET][지역변수(a=0)] [매개변수(a=1)][RET][지역변수]
    Test(a); // 복사를 통해 전달
    cout << a << endl;

    // test2가 바뀔까? 안바뀔까? -> 바뀐다!
    Test(test2); // 배열을 인자로 넘길 때는 시작 주소(test2)만 넘긴다
    cout << test2 << endl;

    return 0;
}