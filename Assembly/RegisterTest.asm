%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    ;write your code here
    
    ; mov аб <- ©Л
    ; mov reg1, cst
    ; mov reg1, reg2
    
    mov eax, 0x1234
    mov rbx, 0x12345678
    mov cl, 0xff
    
    mov al, 0x00
    mov rax, rdx
    
    
    xor rax, rax
    ret
    
section .data
    