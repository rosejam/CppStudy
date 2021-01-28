%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; 반복문 (while for do-while)
    ; 특정 조건을 만족할 때까지 반복해서 실행
    
    ; 어셈블리에서는 분기문으로 구현
    
    mov ecx, 10 ; 반복 조건
    
LABEL_LOOP:
    PRINT_STRING msg
    NEWLINE
    dec ecx ; sub ecx, 1 과 동일하지만 좀더 빠름!
    cmp ecx, 0
    jne LABEL_LOOP
    
    ; 연습 문제) 1에서 100까지의 합을 구하는 프로그램
    ; sol1) 1부터
    mov eax, 100
    xor ebx, ebx ; mov ebx, 0 과 동일한데 빠름
    xor ecx, ecx
    
LABEL_SUM:
    inc ecx ; add ecx, 1 와 동일하지만 좀더 빠름!
    add ebx, ecx
    
    cmp ecx, eax
    jne LABEL_SUM ; 위에 cmp가 곧바로 와야 플래그 판별 가능!!
    
    PRINT_DEC 2, ebx
    NEWLINE
    
    ; sol2) 100부터
    xor ebx, ebx
    mov ecx, 100
    
LABEL_SUM2:
    add ebx, ecx
    dec ecx
    
    cmp ecx, 0
    jne LABEL_SUM2
    
    PRINT_DEC 2, ebx
    NEWLINE
    
    ; 어셈블리 차원에서 반복문 문법도 있다
    ; loop [라벨]
    ; - ecx에 반복 횟수 
    ; - loop할때 마다 exc 1감소 -> 0이 아니면 라벨로 이동/0이면 빠져나감
    xor ebx, ebx
    mov ecx, 100
    
LABEL_LOOP_SUM: ; loop 내부에서 ecx를 건들면 반복횟수도 변경됨..
    add ebx, ecx ; loop 내부가 1줄 이상이면 short jump is out of range 에러 발생. 다른 코드 추가해야함
    loop LABEL_LOOP_SUM ; dec ecx와 cmp ecx, 0과 jne LABEL_LOOP_SUM이 포함된 것!!
    
    PRINT_DEC 2, ebx
    NEWLINE
    
    xor rax, rax
    ret
    
    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
section .data
    msg db 'Hello World', 0x00
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    num resb 1
    
