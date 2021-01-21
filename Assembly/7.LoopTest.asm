%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; �б⹮ (if / ifelse)
    ; Ư�� ���ǿ� ���� �ڵ� �帧�� �����ϴ� ��

    ; ���� üũ(�� ��) -> �帧
    
    ; CMP dst, src (dst�� �������� ��)
    ; �񱳸� �� ������� Flag Register(eflag)�� ����
    ; (���� / ��� ����� �������͵� �ִ�)
    
    ; JMP [label] �ø���
    ; JMP : "������" jump
    ; JE : JumpEquals ������ jump
    ; JNE : JumpNotEquals �ٸ��� jump
    ; JG : JumpGreater ũ�� jump
    ; JGE : JumpGreaterEquals ũ�ų� ������ jump
    ; JL
    ; JLE
    
    ; �� ���ڰ� ������ 1, �ƴϸ� 0�� ����ϴ� ���α׷�
    
    mov rax, 10
    mov rbx, 20
    
    cmp rax, rbx
    
    je LABEL_EQUAL
    
    ; je�� ���� ������ ���ߴٸ�, ���� �ʴٴ� �ǹ�
    mov rcx, 0
    jmp LABEL_EQUAL_END
    
LABEL_EQUAL: 
    mov rcx, 1
    
LABEL_EQUAL_END:
    PRINT_HEX 1, rcx
    NEWLINE
    
    ; ���� ���� : � ����(1~10)�� ¦���� 1, Ȧ���� 0�� ����ϴ� ���α׷�
    ; ������ ����
    ; div reg
    ; - div b1 => ax / bl (al�� ah������)
    mov ax, 91
    mov bl, 2
    div bl
    
    cmp ah, 0 ; sol2) xor al, 0x01 �ϰ� �״�� ����ص� ��!
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
    
    ; �ʱ�ȭ �� ������
    ; [�����̸�] [ũ��] [�ʱⰪ]
    ; [ũ��] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
;section .data   

    
    ; �ʱ�ȭ ���� ���� ������
    ; [�����̸�] [ũ��] [����]
    ; [ũ��] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    num resb 1
    
