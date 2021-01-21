%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    PRINT_STRING msg ; OS차원에서 지원해주는 화면 출력 api를 SASM에서 이용한 것
    
    xor rax, rax
    ret
    
    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
section .data
    msg db 'Hello World', 0x00 ; 0x00으로 문자열 끝을 나타냄
    
    a db 0x11, 0x11, 17, 0x11
    
    b dd 0x12345678, 0x45123411
    ; - 빅 엔디언 : 숫자 대소 비교에 유리
    ; - 리틀 엔디언 : 캐스팅에 유리
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    e resb 10
    
