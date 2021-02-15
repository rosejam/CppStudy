#include <iostream>
using namespace std;

void SetNumber(int* a)
{
    *a = 1;
}

void SetMessage(const char* tmp) // msg
{
    // tmp[ Bye주소 ] ------> Bye주소[B][y][e][\0]
    tmp = "Bye"; // 매개변수 tmp가 Hello주소를 가리키다가 Bye주소를 가리키게 됨!!!

    // *a = 'B';
    // *(a + 1) = 'y';
    // a[2] = 'e';
}

void SetMessage(const char** pp) // pp = &msg
{
    // pp[ &msg ] -----> msg[ Bye주소 ] ------> Bye주소[B][y][e][\0]
    *pp = "Bye"; // main의 지역변수 msg가 Bye의 시작주소를 가리키게 됨!!!
}
void SetMessage2(const char*& rp) // rp = msg
{
    // rp[ &msg ] -----> msg[ Wow주소 ] ------> Wow주소[B][y][e][\0]
    rp = "Wow"; // main의 지역변수 msg가 Wow의 시작주소를 가리키게 됨!!!
}

int main()
{
    int a = 0;
    SetNumber(&a);
    // cout << a << endl; // 1

    // msg[ Hello주소 ] -----> (.rodata영역) Hello주소[H][e][l][l][o][\0]
    const char* msg = "Hello";
    
    // [매개변수][RET][지역변수(msg = Hello주소)] [매개변수(tmp = Hello주소)][RET][지역변수]
    SetMessage(msg);
    cout << msg << endl; // 그대로 Hello를 가리키는 msg


    // (const char**) pp[ 주소1 ] -----> (const char*) 주소1[ 주소2 ] -----> (const char) 주소2[ ](1바이트 바구니) !!!! 
    //                 pp[ &msg ] ----->             msg[ Hello주소 ] ----->          Hello주소[H][e][l][l][o][\0]
    const char** pp = &msg; // 포인터의 주소를 넣는다
    
    // [매개변수][RET][지역변수(msg = Hello주소)] [매개변수(&msg)][RET][지역변수]
    SetMessage(&msg);
    cout << msg << endl;

    // 혼동스럽다?
    // 그냥 양파까기라고 생각하면 된다. 
    // 오른쪽에 있는 *부터 까면서 순간이동하면 어떤 바구니가 있는지 타고 가면 됨
    // (const char*)* pp2;

    // [매개변수][RET][지역변수(msg = Hello주소)] [매개변수(&msg)][RET][지역변수]
    SetMessage2(msg); // SetMessage(&msg) 와 완전히 동일!!!!
    cout << msg << endl;

    return 0;
}