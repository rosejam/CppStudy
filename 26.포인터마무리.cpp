#include <iostream>
using namespace std;

// 1) 포인터 vs 배열 2탄
// 2) 주의사항 (마음가짐?)

int& TestRef()
{
    int a = 1;
    return a; // warning
}
int* TestPtr()
{
    int a = 1;
    return &a; // warning
}
void TestWrong(int* pointer) // pointer = &a
{
    int b[100]  = {};
    b[99] = 0xBBBBBBBB;

    *pointer = 0x12341234; // 의도치 않게 자신의 스택프레임 안의 값을 건드리게 될 확률이 높다!!!
    // (디버그모드에선 컴파일러가 스택프레임을 0xCCCCCCCC로 채워두어서 메모리가 오염corrupt되는지 확인할 수도 있다
    //  그러나 릴리즈 모드에선 이것이 확인되지 않는다..)
}

int main()
{
    // 주소를 담는 바구니
    // 진퉁은 저멀리 어딘가에 있음
    // pointer는 단지 그 곳으로 워프하는 포탈
    int *pointer;

    // 진짜배기 원조 데이터
    // 닭장과 같은 데이터의 묶음 (엄청 많고 거대함!)
    int array[10] = { 1,2,3,4,5,6,7,8 };

    // 그런데 상당히 많은 사람들이 [배열 = 포인터]라 착각하는 경향이 있음!

    // - [배열의 이름]은 "배열의 첫번째 원소"!!!!!!!를 가리키는 TYPE*형 포인터로 '항상' 암묵적으로 캐스팅된다 !!!!!!!!!!
    // - 이를 decay된다고 함. [배열] 그 자체는 길이 정보도 포함한 TYPE[]형 !!!!!!!
    // - 단, sizeof(), typeid(), &주소연산자와 사용할 때 등등.. decay에는 예외 상황이 있음 !!!!!!!
    // - 참고로 constant pointer 즉, 가리키고 있는 주소값이 고정된 포인터 !!!!! (array++같은거 안됨)
    // - (이 때 TYPE은 배열 원소의 타입을 의미한다.)
    pointer = array;
    // -- (배열을 함수 인자로 넘길 때도 자연스럽게 포인터 타입으로만 받는다!!!!)

    // - [TYPE형 1차원 배열]과 [TYPE*형 포인터]는 완전히 호환이 된다!!
    cout << pointer[0] << endl;
    cout << array[0] << endl;
    cout << *pointer << endl; // pointer[0]과 동일
    cout << *array << endl;
    cout << pointer[5] << endl;
    cout << array[5] << endl;
    cout << *(pointer + 5) << endl; // pointer[5]와 동일
    cout << *(array + 5) << endl;
    cout << endl;
    cout << pointer[100] << endl; // 범위 밖도 접근 가능;!!!
    cout << array[100] << endl;
    // -- (C++ 문법 상 똑같이 사용 가능)

    
    // 지옥을 보여드리겠습니다. (2차원 배열 vs 다중 포인터)
    // arr2 -----> 주소[1][2][3][4][5][6]
    int arr2[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    
    // (int**) pp[ 주소 ] -----> (int*) 주소[ 0x200000001(주소2?라고 주장) ] -----> (int) 0x200000001[ ??? ](4바이트 정수의 바구니)
    int** pp = (int**)arr2; // 강제로 캐스팅(형변환)해서 넣어보면
    // cout << **pp << endl; // 메모리 액세스(접근) 예외 발생!
    // 2차원 배열과 다중포인터는 호환되지 않는다!
    // (C++에서 다중포인터는 포인터의 포인터이고 다차원 배열은 배열의 배열이기 때문 : 정적배열!!!!)

    // (int*) p[ 주소 ] -----> (int) 주소[1][2][3][4] (4바이트 정수의 바구니)
    int* p = (int*)arr2;
    cout << *p << endl; // 1
    cout << endl;

    // arr2는 int(*)[2] 타입 !!!!!!!
    // int(*)[2] 는 int[2] 배열을 가리키는 포인터 타입!!!! (사실상 "int[2] *"의 의미. 오른쪽부터 대신 괄호 안부터 분석하기!!!!!)
    // pointer to array(배열 포인터) 
    // arr2는 2차원 배열의 첫번째 행인 int[2] 배열을 가리킨다!!!!
    // (int(*)[]) p2[ 주소 ]  -----> (int[]) 주소[1][2]
    int(*p2)[2] = arr2;
    
    cout << (*p2)[0] << endl;
    cout << p2[0][0] << endl;
    cout << (*p2)[1] << endl;
    cout << p2[0][1] << endl;
    // 포인터 산술 연산으로 p2에 +1을 하면 실제로는 +sizeof(int[2]) 즉, +8이 된다!!
    // p2+1은 다음 int[2]인 [3][4] 를 가리키게 된다!!
    // *(p2+1)은 int[2]의 시작 위치를 가리키는 포인터로 변환된다!!!
    cout << (*(p2 + 1))[0] << endl;
    cout << (*(arr2 + 1))[0] << endl; // 배열이름에도 포인터 산술 연산이 똑같이 적용된다!! (실제로는 주소값에 +8이 된다!)
    cout << p2[1][0] << endl;
    cout << (*(p2 + 1))[1] << endl;
    cout << (*(arr2 + 1))[1] << endl;
    cout << p2[1][1] << endl;
    // p2+2와 arr2+2는 다음 int[2]인 [5][6]을 가리키게 된다 (p2값에 +16을 하여 포탈탐)
    cout << (*(p2 + 2))[0] << endl;
    cout << (*(p2 + 2))[1] << endl;


    // 포인터, 참조, 배열 등
    // 메모리에 직접 접근해서 다룰 수 있는 도구 사용 시에는 조심해아함
    // 프로그램이 바로 크래시나지는 않지만 엉뚱한 메모리를 조작해서 점점 데이터가 오염되어 어느날 갑자기 크래시 날 수 있음 
    
    // [매개변수][RET][지역변수] [매개변수][RET][지역변수(a)]
    // '지역변수' a의 주소를 리턴함...(값을 효율적으로 전달하려다 실수해서?) - 금지!!!!! (매개변수로 전달받은 주소 였으면 리턴 가능했음)
    // [매개변수][RET][지역변수]
    // 이 주소는 스택 프레임이 위와 같이 정리되며 "유효하지 않은 메모리"를 가리키게 된다...!
    int* ptr = TestPtr();
    int& ref = TestRef();

    // [매개변수][RET][지역변수] [매개변수(&a)][RET][지역변수(b)]
    // TestWrong(ptr);

    return 0;
}