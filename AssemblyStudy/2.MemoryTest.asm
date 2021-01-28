%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; 8 bit = 1 byte -> b
    ; 16 bit = 2 byte = 1 word -> w
    ; 32 bit = 4 byte = 2 dword -> d
    ; 64 bit = 8 byte = 1 qword -> q
    
    mov eax, 0x1234
    mov rbx, 0x12345678
    mov cl, 0xff
    
    mov al, 0x00
    
    ; 레지스터 <- 메모리   
    ; mov rax, a ; a라는 변수의 "주소값"이 rax에 들어간다!!!!
    ; mov rax, [a] ; a라는 변수 "안의 값"이 rax에 들어간다! (a주소값 시작 위치부터 8Byte(rax크기)만큼의 연속된 메모리 전부가!!!)
    mov al, [a]
    
    mov [a], byte 0x55 ; 상수의 크기를 명시해 주지 않으면 빌드 에러가 뜸!
    mov [a], word 0x6666; a라는 변수 "안"에 word상수 값이 들어간다! (a주소값 시작 위치부터 2Byte(word크기)만큼의 연속된 메모리 전부에!!!)
    
    ; 메모리 <- 레지스터
    mov [a], cl
    
    xor rax, rax
    ret
    
    ; 변수의 선언 및 사용
    ; 변수는 그냥 데이터를 저장하는 바구니 [ ]
    ; - 처음에 바구니 사용하겠다 선언 (이름과 크기 지정)
    
    ; 메모리에는 구분할 수 있도록 주소(번지수)가 있다
    ; 
    
    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
section .data
    a db 0x11
    b dw 0x2222
    c dd 0x33333333
    d dq 0x4444444444444444
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    e resb 10
    
