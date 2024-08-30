; math64.inc - 64-bit Windows Math operations
%ifndef MATH64_INC
%define MATH64_INC

%include "windows.inc"
%include "kernel32.inc"
%include "float.inc"

; Constants for mathematical operations
%define LOG_BASE_10 10.0
%define LOG_BASE_E 2.718281828459045
%define PI 3.141592653589793

; Macros for mathematical operations
%macro SinProc 1
%define ANGLE %1
    movsd xmm0, [ANGLE]
    call sin
    ; Return value is in XMM0
    ret
%endmacro

%macro CosProc 1
%define ANGLE %1
    movsd xmm0, [ANGLE]
    call cos
    ; Return value is in XMM0
    ret
%endmacro

%macro LogProc 2
%define BASE %1
%define VALUE %2
    movsd xmm0, [VALUE]
    movsd xmm1, [BASE]
    call log
    ; Return value is in XMM0
    ret
%endmacro

%macro Log10Proc 1
%define VALUE %1
    movsd xmm0, [VALUE]
    call log10
    ; Return value is in XMM0
    ret
%endmacro

%macro ExpProc 1
%define EXPONENT %1
    movsd xmm0, [EXPONENT]
    call exp
    ; Return value is in XMM0
    ret
%endmacro

%endif
