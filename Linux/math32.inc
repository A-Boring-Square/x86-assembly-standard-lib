; math32.inc - 32-bit Linux Math operations
%ifndef MATH32_LINUX_INC
%define MATH32_LINUX_INC

%include "linux32.inc"
%include "math.inc"

; Constants for mathematical operations
%define PI 3.141592653589793

; Macros for mathematical operations
%macro SinProc 1
%define ANGLE %1
    fld qword [ANGLE]
    fsin
    ; Return value is in ST(0)
    ret
%endmacro

%macro CosProc 1
%define ANGLE %1
    fld qword [ANGLE]
    fcos
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
    fldln2
    fyl2x
    ; Return value is in ST(0)
    ret
%endmacro

%macro ExpProc 1
%define EXPONENT %1
    fld qword [EXPONENT]
    fld1
    fyl2x
    ; Return value is in ST(0)
    ret
%endmacro

%endif
