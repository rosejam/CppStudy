#include <iostream>
using namespace std;

void SetHp(int* hp)
{
    *hp = 100; // 매개변수로 전달된 주소로 찾아가 그 값을 100으로 바꾼다!!
}

int main()
{
    int hp = 1;
    SetHp(&hp); // 지역변수 hp의 주소가 매개변수 hp로 전달된다!!!!
    cout << hp << endl; // 지역변수 hp가 100으로 세팅되었다!

    // 변수 = 바구니 = 메모리(주소)공간에 이름을 붙인 것!
    // 변수에 접근하려 할 때, 컴파일러가 찰떡같이 알아듣고 해당 주소(data, stack, heap)에 접근해준다
    // 부족한 점? : { } 외부에서 스택 메모리(지역변수)!!에 접근을 못함!!!!
    // 특정 메모리를 강제로 조작할 수 있는 수단 -> 포인터
    int number = 1;

    // TYPE* 변수이름;
    // 일단 2가지 요소
    // - TYPE
    // - *
    
    // * //

    // 포인터
    // 바구니는 바구니
    // ["주소"를 저장하는 바구니!!!!]
    // 변수 선언할 때 *가 등장했다 -> 포인터 타입임.
    // 참고) 포인터라는 바구니는 "8바이트(64비트)" or 4바이트(32비트) "고정 크기"!!
    int* ptr = &number; // &변수이름 : 변수의 주소를 가져와라!!
    // ptr은 number를 가리키고 있다.
    // 어떤 변수의 주소를 가지고 있다 == 어떤 변수를 가리키고 있다!!!!

    // 근데 남의 주소를 갖고 뭘 하라는거지?
    // *포인터변수이름 : [주소를 저장하는 바구니]가 가리키는/갖고있는 주소로 가라 or 주소의 변수가 되어라!!!!
    // 포탈을 타고 들어있는 주소 위치로 순간이동 한다고 생각해보자.
    int value = *ptr;
    *ptr = 2;
    cout << number << endl;

    // *이 여러번 등장하니 헷갈리는데, 사용 시점에 따라서 구분해서 기억하자!!!!!!!!!!!!!!!!!!!!
    // - 변수 선언 시 : [주소를 저장하는 바구니]임을 표시
    // - 사용할 때 : 포탈을 타고 해당 주소로 순간이동한다

    // TYPE //

    // *앞에 TYPE은 왜 붙여줄까? (어차피 프로그램 비트에 따라 고정 크기인데?)
    // 그 주소에 찾아 가면 뭐가 있는데?!!
    // ex) 청첩장의 주소 = 예식장 주소
    // ex) 명함에 있는 주소 = 회사 주소
    // 어떻게 그 메모리의 비트를 분석할지! 타입을 알려줘야 함!!
    // 주소를 따라가면 TYPE형 데이터가 있다고 가정한다는 뜻!!!!

    // 타입이 불일치하는 경우
    long long* ptr2 = (long long*)&number; // 캐스팅으로 에러를 없애봄 (int의 주소를 long long의 주소라고 침!)
                                           // 이것이 네트워크나 통신에서 불가피할 수도 있음   
    *ptr2 = 0x0000AABBCCDDEEFF;
    // number주소부터 +4까지 0xCCDDEEFF 가 들어갔으며 signed int로 읽는다
    // 상위 비트인 0x0000AABB 는 그 다음 주소(+4~+8)에 들어갔다! // 의도치 않은 에러 발생 가능!!!

    return 0;
}