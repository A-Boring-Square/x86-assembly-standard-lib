; io32.inc - 32-bit Linux I/O operations
%ifndef IO32_LINUX_INC
%define IO32_LINUX_INC

%include "linux32.inc"

; Define file descriptor constants
%define STD_INPUT 0
%define STD_OUTPUT 1
%define STD_ERROR 2

; Macros for I/O operations
%macro WriteFileProc 3
%define FD %1
%define BUFFER %2
%define LENGTH %3
    mov eax, 4                ; sys_write
    mov ebx, FD               ; file descriptor
    mov ecx, BUFFER           ; buffer
    mov edx, LENGTH           ; length
    int 0x80                  ; syscall interrupt
    ; Return value is in EAX (number of bytes written or error code)
    ret
%endmacro

%macro ReadFileProc 3
%define FD %1
%define BUFFER %2
%define LENGTH %3
    mov eax, 3                ; sys_read
    mov ebx, FD               ; file descriptor
    mov ecx, BUFFER           ; buffer
    mov edx, LENGTH           ; length
    int 0x80                  ; syscall interrupt
    ; Return value is in EAX (number of bytes read or error code)
    ; Return the pointer to BUFFER
    mov eax, BUFFER
    ret
%endmacro

%macro CloseFileProc 1
%define FD %1
    mov eax, 6                ; sys_close
    mov ebx, FD               ; file descriptor
    int 0x80                  ; syscall interrupt
    ; Return value is in EAX (0 on success, -1 on error)
    ret
%endmacro

%endif
