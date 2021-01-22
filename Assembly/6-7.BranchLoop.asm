%include "io64.inc"

section .text
global CMAIN
CMAIN:

    mov ecx, 100
    mov bl , 2

LOP:
    mov ax, cx
    PRINT_DEC 1, ax
    NEWLINE
    div bl
    
    cmp ah, 0
    je LABEL_EVEN
    
    ; LABEL_ODD
    mov eax, 0
    jmp LABEL_EVEN_ODD
    
LABEL_EVEN:
    mov eax, 1
    
LABEL_EVEN_ODD:
    PRINT_DEC 1, eax
    NEWLINE
    NEWLINE
    sub cx, 1
    cmp cx, -1
    je END
    jmp LOP
    
END:
    xor rax, rax
    ret
