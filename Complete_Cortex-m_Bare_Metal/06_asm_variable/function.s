; Demo for creating a variable in assembly and modifieng it from both assembly and c codes

            AREA    DATA, ALIGN=2                           ; Indicating that we are using the data area "RAM" 
amount      SPACE   4                                       ; Reserve a space of 4 bytes in memory and label it with "amount" symbol
            EXPORT  amount                                  ; Exporting it to be accessed from outside the asm file.


            AREA    |.text|, CODE, READONLY, ALIGN = 2
            THUMB
            EXPORT  myFunc

myFunc
        ldr     r1, =amount                                 ; Load the address of the variable assigned by the linker
        mov     r0, #125
        str     r0, [r1]
        bx      lr
        align
        end
