%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; 쉬프트(shift) 연산, 논리(logical) 연산
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    shl eax, 3 ; 8bit를 왼쪽으로 민다. (상위 비트 날라감) 
    PRINT_HEX 4, eax ; 34567800
    NEWLINE
    shr eax, 8 ; 8bit를 오른쪽으로 민다. (하위 비트 날라감)
    PRINT_HEX 4, eax ; 00345678
    NEWLINE
    ; 2로 곱하기/나누기에 활용 (양수끼리 or 음수끼리 일 때!)
    ; 게임서버에서 64bit의 ObjectID를 만들 때 해당 자리수의 값으로 객체를 분류
    
    
    
    xor rax, rax
    ret
    
    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
;section .data   

    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    num resb 1
    
