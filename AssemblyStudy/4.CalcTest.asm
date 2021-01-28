%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; GET_DEC 받을 byte크기, 저장할 위치
    GET_DEC 1, al; 레지스터에
    GET_DEC 1, num; 메모리의 num(의 주소 위치)에
    
    ; PRINT_DEC 출력할 byte크기, 저장된 위치
    ;PRINT_DEC 1, al
    ;NEWLINE
    ;PRINT_DEC 1, num
    
    ; 더하기 연산
    ; add a, b (a = a + b)
    ; a는 레지스터 or 메모리
    ; b는 레지스터 or 메모리 or 상수
    ; - 단! a, b 모두 메모리는 X
    
    ; 빼기 연산
    ; sub a, b (a = a - b)
    ; 예시는 생략
    
    add al, 1 ; 레지스터 + 상수
    PRINT_DEC 1, al
    NEWLINE
    
    ;mov rax, num 
    add al, [num] ; 레지스터 + 메모리(변수 안의 값)
    PRINT_DEC 1, al ; (더할 때 그냥 num을 쓰면 "주소값"이 더해져서 al의 범위(1byte) 초과, crash 발생!)
    NEWLINE
    
    mov bl, 3 ; 레지스터 + 레지스터
    add al, bl
    PRINT_DEC 1, al
    NEWLINE
    
    add [num], byte 1 ; 메모리(변수 안에) + 상수. (1의 크기(byte)를 지정 안해주면 에러!) 
    PRINT_DEC 1, [num]
    NEWLINE
    
    add [num], al ; 메모리(변수 안에) + 레지스터
    PRINT_DEC 1, [num]
    NEWLINE
    
    ; 곱하기 연산 
    ; mul reg
    ; - mul bl => al * bl
    ; -- 연산 결과를 ax에 저장
    ; - mul bx => ax * bx
    ; -- 연산 결과는 dx(상위 16비트) ax(하위 16비트)에 저장
    ; - mul ebx => eax * ebx
    ; -- 생략
    
    ; ex ) 5 * 8 은?
    mov ax, 0
    mov al, 5
    mov bl, 8
    mul bl
    PRINT_DEC 2, ax
    NEWLINE
    
    ; 나누기 연산
    ; div reg
    ; - div bl => ax / bl
    ; -- 연산 결과는 al(몫) ah(나머지)
    
    ; ex) 100 / 3 은?
    mov ax, 100
    mov bl, 3
    div bl
    PRINT_DEC 1, al ; 33
    NEWLINE
    mov al, ah ; ah를 PRINT_DEC로 출력할 수 없으므로 al에 옮겨서 출력
    PRINT_DEC 1, al ; 1
    
    
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
    
