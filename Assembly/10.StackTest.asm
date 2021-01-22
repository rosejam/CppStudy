%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; 스택 메모리, 스택 프레임
    
    ; 레지스터는 다양한 용도로 사용
    ; - a b c d 범용 레지스터
    ; - 포인터 레지스터 (포인터 = 위치를 가리키는 주소값)
    ; -- ip (Instruction Pointer) : 다음 수행 명령어의 위치
    ; -- sp (Stack Pointer) : 현재 스택 top 위치 (일종의 cursor)
    ; -- bp (Base Pointer) : 스택 상대주소 계산용
    
    push 1
    push 2
    push 3
    
    pop rax ; pop한것을 rax에 넣어준다.
    pop rbx
    pop rcx
    
    xor rax, rax
    ret ; main함수를 종료
    

; [따라서!] 스택(stack)이라는 메모리 영역을 사용
; 함수가 사용하는 일종의 메모장 (변수/인자들 저장)
; - 매개 변수 전달
; - 돌아갈 주소 관리

    
    ; 초기화 된 데이터
    ; [변수이름] [크기] ['초기값']
    ; [크기] : db(1byte)/dw(2byte)/dd(4byte)/dq(8byte)
section .data
    msg db 'Hello World', 0x00
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] : resb(1byte)/resw(2byte)/resd(4byte)/resq(8byte)
section .bss
    num resb 10
    
