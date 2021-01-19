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
    
    ; �������� <- �޸�   
    ; mov rax, a ; a��� ������ "�ּҰ�"�� rax�� ����!!!!
    ; mov rax, [a] ; a��� ���� "���� ��"�� rax�� ����! (a�ּҰ� ���� ��ġ���� 8Byte(raxũ��)��ŭ�� ���ӵ� �޸� ���ΰ�!!!)
    mov al, [a]
    
    mov [a], byte 0x55 ; ����� ũ�⸦ ����� ���� ������ ���� ������ ��!
    mov [a], word 0x6666; a��� ���� "��"�� word��� ���� ����! (a�ּҰ� ���� ��ġ���� 2Byte(wordũ��)��ŭ�� ���ӵ� �޸� ���ο�!!!)
    
    ; �޸� <- ��������
    mov [a], cl
    
    xor rax, rax
    ret
    
    ; ������ ���� �� ���
    ; ������ �׳� �����͸� �����ϴ� �ٱ��� [ ]
    ; - ó���� �ٱ��� ����ϰڴ� ���� (�̸��� ũ�� ����)
    
    ; �޸𸮿��� ������ �� �ֵ��� �ּ�(������)�� �ִ�
    ; 
    
    ; �ʱ�ȭ �� ������
    ; [�����̸�] [ũ��] [�ʱⰪ]
    ; [ũ��] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
section .data
    a db 0x11
    b dw 0x2222
    c dd 0x33333333
    d dq 0x4444444444444444
    
    ; �ʱ�ȭ ���� ���� ������
    ; [�����̸�] [ũ��] [����]
    ; [ũ��] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    e resb 10
    
