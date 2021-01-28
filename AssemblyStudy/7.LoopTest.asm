%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; �ݺ��� (while for do-while)
    ; Ư�� ������ ������ ������ �ݺ��ؼ� ����
    
    ; ����������� �б⹮���� ����
    
    mov ecx, 10 ; �ݺ� ����
    
LABEL_LOOP:
    PRINT_STRING msg
    NEWLINE
    dec ecx ; sub ecx, 1 �� ���������� ���� ����!
    cmp ecx, 0
    jne LABEL_LOOP
    
    ; ���� ����) 1���� 100������ ���� ���ϴ� ���α׷�
    ; sol1) 1����
    mov eax, 100
    xor ebx, ebx ; mov ebx, 0 �� �����ѵ� ����
    xor ecx, ecx
    
LABEL_SUM:
    inc ecx ; add ecx, 1 �� ���������� ���� ����!
    add ebx, ecx
    
    cmp ecx, eax
    jne LABEL_SUM ; ���� cmp�� ��ٷ� �;� �÷��� �Ǻ� ����!!
    
    PRINT_DEC 2, ebx
    NEWLINE
    
    ; sol2) 100����
    xor ebx, ebx
    mov ecx, 100
    
LABEL_SUM2:
    add ebx, ecx
    dec ecx
    
    cmp ecx, 0
    jne LABEL_SUM2
    
    PRINT_DEC 2, ebx
    NEWLINE
    
    ; ����� �������� �ݺ��� ������ �ִ�
    ; loop [��]
    ; - ecx�� �ݺ� Ƚ�� 
    ; - loop�Ҷ� ���� exc 1���� -> 0�� �ƴϸ� �󺧷� �̵�/0�̸� ��������
    xor ebx, ebx
    mov ecx, 100
    
LABEL_LOOP_SUM: ; loop ���ο��� ecx�� �ǵ�� �ݺ�Ƚ���� �����..
    add ebx, ecx ; loop ���ΰ� 1�� �̻��̸� short jump is out of range ���� �߻�. �ٸ� �ڵ� �߰��ؾ���
    loop LABEL_LOOP_SUM ; dec ecx�� cmp ecx, 0�� jne LABEL_LOOP_SUM�� ���Ե� ��!!
    
    PRINT_DEC 2, ebx
    NEWLINE
    
    xor rax, rax
    ret
    
    ; �ʱ�ȭ �� ������
    ; [�����̸�] [ũ��] [�ʱⰪ]
    ; [ũ��] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
section .data
    msg db 'Hello World', 0x00
    
    ; �ʱ�ȭ ���� ���� ������
    ; [�����̸�] [ũ��] [����]
    ; [ũ��] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    num resb 1
    
