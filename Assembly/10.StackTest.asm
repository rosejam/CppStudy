%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; �Լ� (���ν��� procedure, �����ƾ subroutine)
    
    ;call PRINT_MSG ; �Լ� ȣ��
    
    mov eax, 10
    mov ebx, 15
    call MAX
    PRINT_DEC 4, ecx
    NEWLINE
    
    xor rax, rax
    ret ; main�Լ��� ����
    
    
PRINT_MSG:
    PRINT_STRING msg
    NEWLINE
    ret ; �Լ��� ����, call�� ��ġ �������� ���ư���.

; ex) �� ���� �� ū ���� ��ȯ�ϴ� max    
; �Է°��� ��� �ް� ��°��� ��� ��ȯ�ұ�?
; �ϴ� eax�� ebx�� �Է°�, ecx�� ��ȯ������ �� ���� �ִ�. 
MAX:
    call PRINT_MSG ; �Լ� �ȿ��� �ٸ� �Լ��� ȣ��
    cmp eax, ebx
    jg L1
    mov ecx, ebx
    jmp L2
L1:
    mov ecx, eax
L2:
    ret
    
; �׷��� ���ڰ� 10����� ��� �ұ�?
; - �������� ������ �������� ����
; - eax, ebx, ecx�� �̹� �߿��� ���� ������ ��� �ұ�?
; .data�� .bss ����ϸ�?
; - ���ڸ� ����ü ��� �Ҵ��ؾ� ����.. 
; - ���������� ��� ȣ���� ��� ���ڸ� �Լ����� �������� �͵� �Ұ���!!

; �ٸ� �޸� ������ �ʿ��ϴ�
; - ���� ��ȿ�� ���ȿ��� �� ���� ������ ����������� �� (��ȿ ������ ������ �ִ�)
; - ���� ������ �ν������� �� (�޸� ���� ������ ������ �ִ�)
; �޿����� �� ���� �� �� �ִٴ� ���� ����ؾ� ��! (���������� ��ȿ ������ Ȯ�� ����)

; [����!] ����(stack)�̶�� �޸� ������ ���
; �Լ��� ����ϴ� ������ �޸���
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
    
