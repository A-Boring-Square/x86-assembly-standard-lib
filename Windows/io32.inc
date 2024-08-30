; io32.inc - 32-bit Windows I/O operations
%ifndef IO32_INC
%define IO32_INC

%include "windows.inc"
%include "kernel32.inc"

; Define some constants for I/O operations
%define STD_INPUT -10
%define STD_OUTPUT -11
%define STD_ERROR -12

; Procedures for I/O operations
%macro GetStdHandleProc 1
%define HANDLE_TYPE %1
    mov eax, HANDLE_TYPE
    call GetStdHandle
    ; Return value is in EAX
    ret
%endmacro

%macro WriteFileProc 5
%define HANDLE %1
%define BUFFER %2
%define BYTES_TO_WRITE %3
%define BYTES_WRITTEN %4
%define OVERLAPPED %5
    mov eax, HANDLE
    mov ecx, BUFFER
    mov edx, BYTES_TO_WRITE
    mov ebx, BYTES_WRITTEN
    mov esi, OVERLAPPED
    call WriteFile
    ; Return value is in EAX (non-zero if successful)
    ; Number of bytes written is available at [BYTES_WRITTEN]
    ret
%endmacro

%macro ReadFileProc 5
%define HANDLE %1
%define BUFFER %2
%define BYTES_TO_READ %3
%define BYTES_READ %4
%define OVERLAPPED %5
    mov eax, HANDLE
    mov ecx, BUFFER
    mov edx, BYTES_TO_READ
    mov ebx, BYTES_READ
    mov esi, OVERLAPPED
    call ReadFile
    ; Return value is in EAX (non-zero if successful)
    ; Number of bytes read is available at [BYTES_READ]
    ; Return the pointer to BUFFER
    mov eax, BUFFER
    ret
%endmacro

%macro CloseHandleProc 1
%define HANDLE %1
    mov eax, HANDLE
    call CloseHandle
    ; Return value is in EAX (non-zero if successful)
    ret
%endmacro

%endif
