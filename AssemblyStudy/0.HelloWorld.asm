%include "io64.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here (주석)
    
    PRINT_STRING msg ;sasm 환경에서 제공하는 함수
    
    xor rax, rax
    ret
    
section .data
    msg db 'Hello World', 0x00