%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; 쉬프트(shift) 연산, 논리(logical) 연산
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    shl eax, 8 ; 8bit를 왼쪽으로 민다. (상위 비트 날라감) 
    PRINT_HEX 4, eax ; 34567800
    NEWLINE
    shr eax, 8 ; 8bit를 오른쪽으로 민다. (하위 비트 날라감)
    PRINT_HEX 4, eax ; 00345678
    NEWLINE
    ; 2로 곱하기/나누기에 활용 (양수끼리 or 음수끼리 일 때!!)
    ; 게임서버에서 64bit의 ObjectID를 만들 때 해당 자리수의 값으로 객체를 분류
    
    ; 논리/비트 연산
    ; not and or xor
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    ; 0001 0100 = 0x14
    and al, bl ; al = al and bl
    PRINT_HEX 1, al
    NEWLINE
    
    ; 1110 1011 = 0xeb
    not al
    PRINT_HEX 1, al
    NEWLINE
    
    ; 응용 사례 : bitflag! (특정 의미를 가진 위치 비트의 값 체크)
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    NEWLINE
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    ; 동일한 값으로 xor 두번하면 자기자신으로 되돌아오는 특성
    ; 암호학에서 유용하다! (value xor 비밀key) 대칭 키 암호등에서 사용 
    
    ; mov al, 0과 같이 모두 0을 넣은 것과 같지만 훨씬 빠름!!
    xor al, al
    PRINT_HEX 1, al
    
    xor rax, rax ; a레시스터에 main함수의 리턴값을 넣어준다. (정상종료 0)
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
    
