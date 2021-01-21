%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    PRINT_STRING msg ; OS�������� �������ִ� ȭ�� ��� api�� SASM���� �̿��� ��
    
    xor rax, rax
    ret
    
    ; �ʱ�ȭ �� ������
    ; [�����̸�] [ũ��] [�ʱⰪ]
    ; [ũ��] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
section .data
    msg db 'Hello World', 0x00 ; 0x00���� ���ڿ� ���� ��Ÿ��
    
    a db 0x11, 0x11, 17, 0x11
    
    b dd 0x12345678, 0x45123411
    ; - �� ����� : ���� ��� �񱳿� ����
    ; - ��Ʋ ����� : ĳ���ÿ� ����
    
    ; �ʱ�ȭ ���� ���� ������
    ; [�����̸�] [ũ��] [����]
    ; [ũ��] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    e resb 10
    
