%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; 분기문 (if / ifelse)
    ; 특정 조건에 따라서 코드 흐름을 제어하는 것

    ; 조건 체크(비교 등) -> 흐름
    
    ; CMP dst, src (dst를 기준으로 비교)
    ; 비교를 한 결과물은 Flag Register(eflag)에 저장
    ; (상태 / 결과 저장용 레지스터도 있다)
    
    ; JMP [label] 시리즈
    ; JMP : "무조건" jump
    ; JE : JumpEquals 같으면 jump
    ; JNE : JumpNotEquals 다르면 jump
    ; JG : JumpGreater 크면 jump
    ; JGE : JumpGreaterEquals 크거나 같으면 jump
    ; JL
    ; JLE
    
    ; 두 숫자가 같으면 1, 아니면 0을 출력하는 프로그램
    
    mov rax, 10
    mov rbx, 20
    
    cmp rax, rbx
    
    je LABEL_EQUAL
    
    ; je에 의해 점프를 안했다면, 같지 않다는 의미
    mov rcx, 0
    jmp LABEL_EQUAL_END
    
LABEL_EQUAL: 
    mov rcx, 1
    
LABEL_EQUAL_END:
    PRINT_HEX 1, rcx
    NEWLINE
    
    ; 연습 문제 : 어떤 숫자(1~10)가 짝수면 1, 홀수면 0을 출력하는 프로그램
    ; 나누기 연산
    ; div reg
    ; - div b1 => ax / bl (al몫 ah나머지)
    mov ax, 91
    mov bl, 2
    div bl
    
    cmp ah, 0 ; sol2) xor al, 0x01 하고 그대로 출력해도 됨!
    je LABEL_EVEN
    
    mov rcx, 0
    jmp LABEL_EVEN_END
    
LABEL_EVEN:
    mov rcx, 1
    
LABEL_EVEN_END:
    PRINT_HEX 1, rcx
    NEWLINE
    
    
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
    
