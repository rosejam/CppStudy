%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; ����Ʈ(shift) ����, ��(logical) ����
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    shl eax, 8 ; 8bit�� �������� �δ�. (���� ��Ʈ ����) 
    PRINT_HEX 4, eax ; 34567800
    NEWLINE
    shr eax, 8 ; 8bit�� ���������� �δ�. (���� ��Ʈ ����)
    PRINT_HEX 4, eax ; 00345678
    NEWLINE
    ; 2�� ���ϱ�/�����⿡ Ȱ�� (������� or �������� �� ��!!)
    ; ���Ӽ������� 64bit�� ObjectID�� ���� �� �ش� �ڸ����� ������ ��ü�� �з�
    
    ; ��/��Ʈ ����
    ; not and or xor
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    ; 0001 0100 = 0x14
    and al, bl ; al = al and bl
    PRINT_HEX 1, al
    NEWLINE
    
    ; 1110 1011 = 0xeb
    not al
    PRINT_HEX 1, al
    NEWLINE
    
    ; ���� ��� : bitflag! (Ư�� �ǹ̸� ���� ��ġ ��Ʈ�� �� üũ)
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    NEWLINE
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    ; ������ ������ xor �ι��ϸ� �ڱ��ڽ����� �ǵ��ƿ��� Ư��
    ; ��ȣ�п��� �����ϴ�! (value xor ���key) ��Ī Ű ��ȣ��� ��� 
    
    ; mov al, 0�� ���� ��� 0�� ���� �Ͱ� ������ �ξ� ����!!
    xor al, al
    PRINT_HEX 1, al
    
    xor rax, rax ; a���ý��Ϳ� main�Լ��� ���ϰ��� �־��ش�. (�������� 0)
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
    
