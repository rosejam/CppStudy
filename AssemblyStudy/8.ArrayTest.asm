%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; 배열과 주소
    
    ; 배열 : 동일한 타입의 데이터 묶음
    ; - 배열을 구성하는 각 값을 배열 요소(element)라고 함
    ; - 배열의 위치를 가리키는 숫자를 인덱스(index)라고 함

    ; [시작 주소 + 인덱스*데이터크기]
    
    mov rax, a
    
    ; 연습문제 : a배열의 모든 데이터 출력해보기 
    xor ecx, ecx
LABEL_PRINT_A:
    PRINT_HEX 1, [a+ecx] ; a시작 주소에서 ecx(byte!!!!)만큼 옆에 있는 메모리에 저장된 값
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne LABEL_PRINT_A
    
    ; b배열도 출력해보기
    xor ecx, ecx
LABEL_PRINT_B:
    PRINT_HEX 2, [b+ecx*2] ; b시작 주소에서 2*ecx(byte!!!!)만큼 옆에 있는 메모리에 저장된 값 ; c언어에서는 data type을 보고 자동으로 해줌!
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne LABEL_PRINT_B
    
    xor rax, rax
    ret
    
    ; 초기화 된 데이터
    ; [변수이름] [크기] ['초기값']
    ; [크기] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
section .data
    msg db 'Hello World', 0x00
    a db 0x01, 0x02, 0x03, 0x04, 0x05 ; 1byte * 5개 = 5byte
    b times 5 dw 1 ; 2byte(초기값은 1) * 5개 =10byte
    
    ; 이런 식으로 맵을 이차원 배열로 표현할 수 있음
    map1 db '#########', 0x00
    map2 db '#   #   #', 0x00
    map3 db '#       #', 0x00
    map4 db '#########', 0x00
    
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    num resb 10 ; 1byte(값은 0) * 10개 = 10byte
    
