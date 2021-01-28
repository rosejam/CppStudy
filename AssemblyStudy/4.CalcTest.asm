%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; GET_DEC ���� byteũ��, ������ ��ġ
    GET_DEC 1, al; �������Ϳ�
    GET_DEC 1, num; �޸��� num(�� �ּ� ��ġ)��
    
    ; PRINT_DEC ����� byteũ��, ����� ��ġ
    ;PRINT_DEC 1, al
    ;NEWLINE
    ;PRINT_DEC 1, num
    
    ; ���ϱ� ����
    ; add a, b (a = a + b)
    ; a�� �������� or �޸�
    ; b�� �������� or �޸� or ���
    ; - ��! a, b ��� �޸𸮴� X
    
    ; ���� ����
    ; sub a, b (a = a - b)
    ; ���ô� ����
    
    add al, 1 ; �������� + ���
    PRINT_DEC 1, al
    NEWLINE
    
    ;mov rax, num 
    add al, [num] ; �������� + �޸�(���� ���� ��)
    PRINT_DEC 1, al ; (���� �� �׳� num�� ���� "�ּҰ�"�� �������� al�� ����(1byte) �ʰ�, crash �߻�!)
    NEWLINE
    
    mov bl, 3 ; �������� + ��������
    add al, bl
    PRINT_DEC 1, al
    NEWLINE
    
    add [num], byte 1 ; �޸�(���� �ȿ�) + ���. (1�� ũ��(byte)�� ���� �����ָ� ����!) 
    PRINT_DEC 1, [num]
    NEWLINE
    
    add [num], al ; �޸�(���� �ȿ�) + ��������
    PRINT_DEC 1, [num]
    NEWLINE
    
    ; ���ϱ� ���� 
    ; mul reg
    ; - mul bl => al * bl
    ; -- ���� ����� ax�� ����
    ; - mul bx => ax * bx
    ; -- ���� ����� dx(���� 16��Ʈ) ax(���� 16��Ʈ)�� ����
    ; - mul ebx => eax * ebx
    ; -- ����
    
    ; ex ) 5 * 8 ��?
    mov ax, 0
    mov al, 5
    mov bl, 8
    mul bl
    PRINT_DEC 2, ax
    NEWLINE
    
    ; ������ ����
    ; div reg
    ; - div bl => ax / bl
    ; -- ���� ����� al(��) ah(������)
    
    ; ex) 100 / 3 ��?
    mov ax, 100
    mov bl, 3
    div bl
    PRINT_DEC 1, al ; 33
    NEWLINE
    mov al, ah ; ah�� PRINT_DEC�� ����� �� �����Ƿ� al�� �Űܼ� ���
    PRINT_DEC 1, al ; 1
    
    
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
    
