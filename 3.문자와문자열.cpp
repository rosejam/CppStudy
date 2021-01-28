#include <iostream>
using namespace std;

// Character
// char도 마찬가지로 '그냥 1바이트 정수' 지만, '문자' 의미를 나타내기 위해 사용한다.

// char : 알파벳/숫자 문자를 나타낸다
// wchar_t : 유니코드 문자를 나타낸다

// ASCII (American Standard Code for Information Interchange)
// 숫자를 문자로 매핑하는 규칙
// '문자'의 의미로 작은 따옴표 '' 사용
// char ch = 97; // a
char ch = 'a'; // 97
char ch2 = '1'; // 1이라는 문자에 해당하는 숫자, 49
char ch3 = 'a' + 1; // 98

// Unicode
// 국제화 시대에는 영어만으로 서비스할 수 없음
// 전세계 모든 문자에 대해 유일한 코드를 부여하는 것이 유니코드(unicode)
// 참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어 ㅋㅋ (한글 조합이 다양해서)

// 유니코드 표기 방식이 여러가지가 있는데 대표적으로 UTF8 UTF16 2가지 인코딩 방법을 많이 사용
// UTF8 (영어권 나라에서 유리함)
// - 알파벳, 숫자 1바이트 (ASCII와 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등은 3바이트
// UTF16 (MS사에서 많이 사용)
// - 거의 대부분의 문자를 2바이트로 고정
// - 매우 예외적인 고대 문자만 4바이트 (사실상 무시해도 됨)

// UTF16 방식!
wchar_t wch = 0xc548; // L'안';  // 앞에 L을 꼭 붙여줘야 wchar_t 타입으로 캐스팅 된다!! //0xc548
wchar_t wch2 = L'\''; // 작은 따옴표

// Escape Sequence
// 표기하기 애매한 특수문자들을 표현하는 char
// \0 = 아스키코드0 = Null
// \t = 아스키코드9 = Tab
// \n = 아스키코드10 = LineFeed (한줄 아래로)
// \r = 아스키코드13 = CarriageReturn (커서 맨앞으로)
//      참고) 엔터키 : windows \r\n, linux \n -> Java에선 %n
// \' = 작은 따옴표

// C스타일 문자열
// 문자들이 열을 지어서 모여 잇는 것 (문자 배열)
// 문자열의 맨 끝은 NULL(아스키코드 0x00)로 한다!!! 이렇게 가변 길이 배열 처럼 표현
char str[] = {'H', 'e', 'l', 'l', 'o','\0'};
char str2[] = "Hello"; // 맨 뒤의 '\0'이 포함되어 길이가 6임! // 위와 동일
wchar_t str3[] = L"Hello";


int main() {
    
    cout << ch << endl;
    cout << ch2 << endl;
    cout << ch3 << endl;

    // cout << wch << endl;  //50504 라는 이상한 숫자
    // cout은 char 전용이므로 wchar_t는 wcout 사용
    wcout.imbue(locale("ko_KR")); // wcout기본으로는 한글 인식 못하므로 추가해주기 //windows에선 kor
    wcout << wch << endl;
    wcout << wch2 << endl;

    cout << str << endl;
    cout << str2 << endl;
}