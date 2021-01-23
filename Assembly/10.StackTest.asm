%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; bp�� sp ������ �������� ; for correct debugging
    
    ; ���� �޸�, ���� ������
    
    ; �������ʹ� �پ��� �뵵�� ���
    ; - a b c d ���� ��������
    ; - ������ �������� (������ = ��ġ�� ����Ű�� �ּҰ�)
    ; -- ip (Instruction Pointer) : ���� ���� ��ɾ��� ��ġ -> �޸��� code������ ����Ų��
    ; -- sp (Stack Pointer) : ���� ���� top ��ġ (������ cursor)
    ; -- bp (Base Pointer) : ���� ����ּ� ����
    
    push rax
    push rbx
    push 1 ; 8byte�� 1�� ���������ӿ� �ִ´�.
    push 2
    
    call MAX
    PRINT_DEC 8, rax
    NEWLINE
    
    ;pop rax ; pop�� 2�� -> rax�� �־��ش�.
    ;pop rbx
    ; push �ι� �س��� �Ÿ� pop �ι� ��� sp�� 16�� ���� �ذ��� �� �ִ�!!!
    add rsp, 16
    pop rbx
    pop rax
            
    xor rax, rax
    ret ; main�Լ��� ����
    
MAX: ; ���� ���������� ���� �� ���� �� �� ū ���� rax�� �ִ´�.
    push rbp ; ����
    mov rbp, rsp ; ����
    
    mov rax, [rbp+16] ; 2
    mov rbx, [rbp+24] ; 1
    
    cmp rax, rbx
    jg L1
    mov rax, rbx
L1:

    pop rbp ; ����
    ret
    

; [!] ����(stack)�̶�� �޸� ������ ���
; �Լ��� ����ϴ� ������ �޸��� (����/���ڵ� ����)
; - �Ű� ���� ����
; - ���ư� �ּ� ����

    
    ; �ʱ�ȭ �� ������
    ; [�����̸�] [ũ��] ['�ʱⰪ']
    ; [ũ��] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
section .data
    msg db 'Hello World', 0x00
    
    ; �ʱ�ȭ ���� ���� ������
    ; [�����̸�] [ũ��] [����]
    ; [ũ��] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    num resb 10
    
