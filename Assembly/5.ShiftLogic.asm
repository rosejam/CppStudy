%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; ����Ʈ(shift) ����, ��(logical) ����
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    shl eax, 3 ; 8bit�� �������� �δ�. (���� ��Ʈ ����) 
    PRINT_HEX 4, eax ; 34567800
    NEWLINE
    shr eax, 8 ; 8bit�� ���������� �δ�. (���� ��Ʈ ����)
    PRINT_HEX 4, eax ; 00345678
    NEWLINE
    ; 2�� ���ϱ�/�����⿡ Ȱ�� (������� or �������� �� ��!)
    ; ���Ӽ������� 64bit�� ObjectID�� ���� �� �ش� �ڸ����� ������ ��ü�� �з�
    
    
    
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
    
