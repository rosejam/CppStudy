%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; bp와 sp 포인터 레지스터 ; for correct debugging
    
    ; 스택 메모리, 스택 프레임
    
    ; 레지스터는 다양한 용도로 사용
    ; - a b c d 범용 레지스터
    ; - 포인터 레지스터 (포인터 = 위치를 가리키는 주소값)
    ; -- ip (Instruction Pointer) : 다음 수행 명령어의 위치 -> 메모리의 code영역을 가리킨다
    ; -- sp (Stack Pointer) : 현재 스택 top 위치 (일종의 cursor)
    ; -- bp (Base Pointer) : 스택 상대주소 계산용
    
    ; 레지스터 백업
    push rax 
    push rbx
    
    push 1 ; 8byte의 1를 스택프레임에 넣는다.
    push 2
    
    call MAX ; rax, rbx 레지스터를 사용한다.
    PRINT_DEC 8, rax ; rax에 리턴값을 받아온다!!
    NEWLINE
    
    ;pop rax ; pop한 2를 rax에 넣어준다.
    ;pop
    ; push 두번 해놓은 거를 pop 두번하는 대신 sp에 16을 더해 해결할 수 있다!!
    add rsp, 16
    
    ; 레지스터 복원
    pop rbx
    pop rax 

    xor rax, rax
    ret
    
    
MAX: ; 스택 프레임으로 받은 두 인자 중 더 큰 값을 rax에 넣는다
    push rbp ; 1. 이전 bp 저장!
    mov rbp, rsp ; 2. 지금 sp위치를 새로운 bp로 함!
    
    mov rax, [rbp+16] ; 2 (main에서 push하여 전달한 인자!)
    mov rbx, [rbp+24] ; 1 (main에서 push하여 전달한 인자!)
    cmp rax, rbx
    jg L1
    mov rax, rbx
L1:

    pop rbp ; 3. 이전 bp 복원!
    ret
    

; [!] 스택(stack)이라는 메모리 영역을 사용
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
    
