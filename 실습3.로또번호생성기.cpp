#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Sort(int numbers[], int count)
{
    for (int i=0; i<count; i++)
    {
        // i번 인덱스가 최소값을 가진다고 가정
        int min = i;

        // i번 뒤에서 진짜 최소 인덱스를 찾는다
        for (int j=i+1; j<count; j++)
        {
            if(numbers[j] < numbers[min])
                min = j;
        }

        // i번과 최소를 스왑한다
        if (i != min)
            Swap(numbers[i], numbers[min]);
    }
}

void ChooseLotto(int numbers[], int count)
{
    // 랜덤으로 1~45 사이의 숫자 6개를 골라주세요! (단, 중복이 없어야 함)
    srand((unsigned)time(0)); // 시드 설정

    int i=0;
    while(i < count)
    {
        int randValue = 1 + (rand() % 45); // 1~45
        
        // 이미 찾은 값이 아니라고 가정
        bool found = false;
        for (int j=0; j<i; j++) // (i가 0이면 실행되지 않음)
        {
            // 이미 찾은 값인 경우
            if (numbers[j] == randValue)
            {
                found = true;
                break;
            }
        }
        // 이미 찾은 값이 아닌 경우
        if(!found)
        {
            numbers[i] = randValue;
            i++;
        }
    }
    
    Sort(numbers, count);
}

int main()
{
    // 1) Swap 함수 만들기
    int a = 1;
    int b = 2;
    Swap(&a, &b);
    // cout << a << " " << b << endl;
    Swap(a, b);
    // cout << a << " " << b << endl;

    // 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
    int numbers[6] = { 1, 42, 3, 15, 5, 6 };

    // int size1 = sizeof(numbers); // 6*4
    // int size2 = sizeof(int); // 4
    Sort( numbers, sizeof(numbers)/sizeof(int) ); // 배열과 배열의 길이 전달

    // 3) 로또 번호 생성기
    ChooseLotto( numbers, sizeof(numbers)/sizeof(int) );

    // 행운의 로또 앱 완성!
    for(int i=0; i<6; i++)
        cout << numbers[i] << endl;

    return 0;
}