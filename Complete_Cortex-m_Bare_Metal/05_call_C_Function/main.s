; Calling a c function from assembly code using ARM Procedure Call Standards "AAPCS" and Application Binary Interface "ABI"
; Also showing how to access global variables defiend in c code.


                AREA    DATA, ALIGN=2                               ; Telleing the assembler that the following line is for data 
                IMPORT  num                                         ; Now importing our symbol (num) address after its assigned by the linker
                AREA    |.text|,CODE,READONLY,ALIGN=2               ; Going to Code "executable" area to place our code.
                THUMB                                               ; The code will be in Thumb instruction
                IMPORT  myFunc                                      ; importing the function address defiend in c code
                EXPORT __main                                       ; Exporting our main function to be called out from reset handler routien

__main
        ldr     r1, =num                                            ; Placing the global variable (num) address ir R1
        mov     r0,#100
        str     r0,[r1]                                             ; Storing the value of R0 into variable (num)
        bl      myFunc                                              ; Calling the c function
        mov     r4, r0                                              ; The return of the function is placed in R0
        bl      .                                                   ; Dummy to halt the execution "branch to the same point" just like while(1);
		;bl		.
        ALIGN
        end
