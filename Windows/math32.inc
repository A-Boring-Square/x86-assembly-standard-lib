; math32.inc - 32-bit Windows Math operations
%ifndef MATH32_INC
%define MATH32_INC

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
    fld qword [ANGLE]
    fsin
    fstp qword [ANGLE]
    ; Return value is in ST(0)
    ret
%endmacro

%macro CosProc 1
%define ANGLE %1
    fld qword [ANGLE]
    fcos
    fstp qword [ANGLE]
    ; Return value is in ST(0)
    ret
%endmacro

%macro LogProc 2
%define BASE %1
%define VALUE %2
    fld qword [VALUE]
    fld qword [BASE]
    fyl2x
    ; Return value is in ST(0)
    ret
%endmacro

%macro Log10Proc 1
%define VALUE %1
    fld qword [VALUE]
    fld1
    fild dword [LOG_BASE_10]
    fyl2x
    ; Return value is in ST(0)
    ret
%endmacro

%macro ExpProc 1
%define EXPONENT %1
    fld qword [EXPONENT]
    fexp
    fstp qword [EXPONENT]
    ; Return value is in ST(0)
    ret
%endmacro

%endif
