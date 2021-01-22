%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; �迭�� �ּ�
    
    ; �迭 : ������ Ÿ���� ������ ����
    ; - �迭�� �����ϴ� �� ���� �迭 ���(element)��� ��
    ; - �迭�� ��ġ�� ����Ű�� ���ڸ� �ε���(index)��� ��

    ; [���� �ּ� + �ε���*������ũ��]
    
    mov rax, a
    
    ; �������� : a�迭�� ��� ������ ����غ��� 
    xor ecx, ecx
LABEL_PRINT_A:
    PRINT_HEX 1, [a+ecx] ; a���� �ּҿ��� ecx(byte!!!!)��ŭ ���� �ִ� �޸𸮿� ����� ��
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne LABEL_PRINT_A
    
    ; b�迭�� ����غ���
    xor ecx, ecx
LABEL_PRINT_B:
    PRINT_HEX 2, [b+ecx*2] ; b���� �ּҿ��� 2*ecx(byte!!!!)��ŭ ���� �ִ� �޸𸮿� ����� �� ; c������ data type�� ���� �ڵ����� ����!
    NEWLINE
    inc ecx
    cmp ecx, 5
    jne LABEL_PRINT_B
    
    xor rax, rax
    ret
    
    ; �ʱ�ȭ �� ������
    ; [�����̸�] [ũ��] ['�ʱⰪ']
    ; [ũ��] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
section .data
    msg db 'Hello World', 0x00
    a db 0x01, 0x02, 0x03, 0x04, 0x05 ; 1byte * 5�� = 5byte
    b times 5 dw 1 ; 2byte(�ʱⰪ�� 1) * 5�� =10byte
    
    ; �̷� ������ ���� ������ �迭�� ǥ���� �� ����
    map1 db '#########', 0x00
    map2 db '#   #   #', 0x00
    map3 db '#       #', 0x00
    map4 db '#########', 0x00
    
    
    ; �ʱ�ȭ ���� ���� ������
    ; [�����̸�] [ũ��] [����]
    ; [ũ��] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    num resb 10 ; 1byte(���� 0) * 10�� = 10byte
    
