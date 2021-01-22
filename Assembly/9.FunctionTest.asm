%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp ; for correct debugging
    
    ; 함수 (프로시저 procedure, 서브루틴 subroutine)
    
    ;call PRINT_MSG ; 함수 호출
    
    mov eax, 10
    mov ebx, 15
    call MAX
    PRINT_DEC 4, ecx
    NEWLINE
    
    xor rax, rax
    ret ; main함수를 종료
    
    
PRINT_MSG:
    PRINT_STRING msg
    NEWLINE
    ret ; 함수를 종료, call한 위치 다음으로 돌아간다.

; ex) 두 값중 더 큰 값을 반환하는 max    
; 입력값을 어떻게 받고 출력값은 어떻게 반환할까?
; 일단 eax와 ebx에 입력값, ecx에 반환값으로 할 수도 있다. 
MAX:
    call PRINT_MSG
    cmp eax, ebx
    jg L1
    mov ecx, ebx
    jmp L2
L1:
    mov ecx, eax
L2:
    ret
    
; 그런데 인자가 10개라면 어떻게 할까?
; - 레지스터 개수가 부족해질 수도
; - eax, ebx, ecx에 이미 중요한 값이 있으면 어떻게 할까?
; .data나 .bss 사용하면?
; - 인자를 도대체 몇개를 할당해야 하지.. 
; - 여러겹으로 깊게 호출할 경우 인자를 함수끼리 돌려쓰는 것도 불가능!!

; 다른 메모리 구조가 필요하다
; - 꿈이 유효한 동안에는 그 꿈의 영역을 유지시켜줘야 함 (유효 범위의 개념이 있다)
; - 꿈이 끝나면 부숴버려도 됨 (메모리 공간 정리의 개념이 있다)
; 꿈에서도 또 꿈을 꿀 수 있다는 것을 고려해야 함! (유동적으로 유효 범위가 확장 가능)

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
    
