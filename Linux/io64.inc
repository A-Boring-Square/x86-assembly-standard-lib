; io64.inc - 64-bit Linux I/O operations
%ifndef IO64_LINUX_INC
%define IO64_LINUX_INC

%include "linux64.inc"

; Define file descriptor constants
%define STD_INPUT 0
%define STD_OUTPUT 1
%define STD_ERROR 2

; Macros for I/O operations
%macro WriteFileProc 3
%define FD %1
%define BUFFER %2
%define LENGTH %3
    mov rax, 1                ; sys_write
    mov rdi, FD               ; file descriptor
    mov rsi, BUFFER           ; buffer
    mov rdx, LENGTH           ; length
    syscall
    ; Return value is in RAX (number of bytes written or error code)
    ret
%endmacro

%macro ReadFileProc 3
%define FD %1
%define BUFFER %2
%define LENGTH %3
    mov rax, 0                ; sys_read
    mov rdi, FD               ; file descriptor
    mov rsi, BUFFER           ; buffer
    mov rdx, LENGTH           ; length
    syscall
    ; Return value is in RAX (number of bytes read or error code)
    ; Return the pointer to BUFFER
    mov rax, BUFFER
    ret
%endmacro

%macro CloseFileProc 1
%define FD %1
    mov rax, 3                ; sys_close
    mov rdi, FD               ; file descriptor
    syscall
    ; Return value is in RAX (0 on success, -1 on error)
    ret
%endmacro

%endif
