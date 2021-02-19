#include <iostream>
using namespace std;

// 문제1) 문자열 길이를 출력하는 함수
int StrLen(const char* str)
{
    int count = 0;

    while (str[count] != '\0')
        count++;

    return count;
}

// 문자2) 문자열 복사 함수
// dst[ 주소1 ] src[ 주소2 ]
// 주소1[H][e][l][l][o][\0][][][][][][][][][][][][][][][][]...[][][][][][][]
// 주소2[H][e][l][l][o][\0][][][][][][][][][][][][][][][][]...[][][][][][][]
// src가 끝날 때까지 복사
char* StrCpy(char* dst, char* src)
{
    /* int i = 0;
    // while (src[i] != '\0')
    // while (src[i] != 0)
    while (src[i]) // 위 두줄과 동일한 표현
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    
    return dst; */

    // 배열 대신 포인터를 활용하는 방법
    char* ret = dst;

    while (*src != '\0')
    // while (*src)
    {
        // *dst = *src;
        // dst++;
        // src++;
        *dst++ = *src++; // 이렇게 한줄로 줄일 수도 있음!!!
    }
    *dst = '\0';

    return ret; // dst는 수정되었으므로 저장해놓은 초기값을 리턴
}

// 문제3) 문자열 덧붙이는 함수
// dst[ 주소1 ] src[ 주소2 ]
// 주소1[H][e][l][l][o][W][o][r][l][d][\0][][][][][][][][][][][]...[][][][][][][]
// 주소2[W][o][r][l][d][\0][][][][][][][][][][][][][][][][]...[][][][][][][]
// src가 끝날 때까지 복사
char* StrCat(char* dst, char* src)
{
    /* int len = StrLen(dst);

    int i = 0;
    while (src[i])
    {
        dst[len + i] = src[i];
        i++;
    }
    dst[len + i] = '\0';

    return dst; */

    // 배열 대신 포인터를 활용하는 방법
    char* ret = dst;

    while (*dst)
        dst++;
    // for (; *dst; ++dst); // 이렇게 한줄로 줄일 수 있다!
    
    while (*src)
    {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';

    return ret;
}
// 문제4) 두 문자열을 비교하는 함수
// [H][e][l][l][o][\0][][][][][][][][][][][][][][][][]...[][][][][][][]
// [H][e][l][l][\0][][][][][][][][][][][][][][][][][]...[][][][][][][]
int StrCmp(char *a, char *b)
{
    int i = 0;
    
    while (a[i] == b[i])
    {
        if(a[i] == '\0') // while안이므로 ||대신 한가지만 체크해도 됨!
            return 0;
        i++;
    }
    
    return (a[i] < b[i] ? -1 : +1);
    // return a[i] - b[i];
}

// 문제5) 문자열을 뒤집는 함수
void ReverseStr(char* str)
{
    int len = StrLen(str);
    for(int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

#pragma warning(disable: 4996)

int main()
{
    const int BUF_SIZE = 100;

    // [H][e][l][l][o][\0][][][][][][][][][][][][][][][][]...[][][][][][][]
    char d[BUF_SIZE] = "Hello";
    char e[BUF_SIZE];

    // sizeof(d)를 하면 BUF_SIZE가 될 것임
    // int len = strlen(d); // '\0'제외한 길이를 반환해줌 or '\0'의 인덱스를 반환해줌
    int len = StrLen(d);
    cout << len << endl;

    // dst e에 src b를 복사
    // e = d; // 배열에 배열을 이렇게 대입하면 에러
    // 하나하나씩 복사를 해줘야 함!
    // strcpy(e, d); // warning : 목적지 e의 버퍼가 작을 경우 버퍼 오버플로우가 발생!!!
    // strcpy_s(e, d); // 이건 길이 체크해줘서 괜찮음
    StrCpy(e, d);

    // dst의 끝에 src를 덧붙이기
    char c[BUF_SIZE] = " World";
    // strcat(e, c);
    StrCat(e, c);
    
    // 문자열 비교
    char a[BUF_SIZE] = "Hello";
    char b[BUF_SIZE] = "Hella";
    
    if (a == b) // 값 비교가 아니고 주소 비교임!!!
        cout << "같다" << endl;
    else
        cout << "다르다" << endl; // a와 b의 주소값은 당연히 무조건 다르다!!!
    cout << endl;

    int value = StrCmp(a, b); // 한글자씩 모두 비교해야함
    // 둘의 ASCII순서를 리턴!!!! a-b <:음수 =:0 >:양수
    cout << value << endl;

    ReverseStr(e); // 헬로월드 뒤집기
    cout << e << endl;

    return 0;
}