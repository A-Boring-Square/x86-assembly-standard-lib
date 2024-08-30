; io64.inc - 64-bit Windows I/O operations
%ifndef IO64_INC
%define IO64_INC

%include "windows.inc"
%include "kernel32.inc"

; Define some constants for I/O operations
%define STD_INPUT -10
%define STD_OUTPUT -11
%define STD_ERROR -12

; Procedures for I/O operations
%macro GetStdHandleProc 1
%define HANDLE_TYPE %1
    mov rax, HANDLE_TYPE
    call GetStdHandle
    ; Return value is in RAX
    ret
%endmacro

%macro WriteFileProc 5
%define HANDLE %1
%define BUFFER %2
%define BYTES_TO_WRITE %3
%define BYTES_WRITTEN %4
%define OVERLAPPED %5
    mov rax, HANDLE
    mov rcx, BUFFER
    mov rdx, BYTES_TO_WRITE
    mov r8, BYTES_WRITTEN
    mov r9, OVERLAPPED
    call WriteFile
    ; Return value is in RAX (non-zero if successful)
    ; Number of bytes written is available at [BYTES_WRITTEN]
    ret
%endmacro

%macro ReadFileProc 5
%define HANDLE %1
%define BUFFER %2
%define BYTES_TO_READ %3
%define BYTES_READ %4
%define OVERLAPPED %5
    mov rax, HANDLE
    mov rcx, BUFFER
    mov rdx, BYTES_TO_READ
    mov r8, BYTES_READ
    mov r9, OVERLAPPED
    call ReadFile
    ; Return value is in RAX (non-zero if successful)
    ; Number of bytes read is available at [BYTES_READ]
    ; Return the pointer to BUFFER
    mov rax, BUFFER
    ret
%endmacro

%macro CloseHandleProc 1
%define HANDLE %1
    mov rax, HANDLE
    call CloseHandle
    ; Return value is in RAX (non-zero if successful)
    ret
%endmacro

%endif
