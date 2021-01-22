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
    
    push 1 ; 8byte�� 1�� ���������ӿ� �ִ´�.
    push 2
    push 3
    
    pop rax ; pop�Ѱ��� -> rax�� �־��ش�.
    pop rbx
    pop rcx
    
    xor rax, rax
    ret ; main�Լ��� ����
    

; [����!] ����(stack)�̶�� �޸� ������ ���
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
    
