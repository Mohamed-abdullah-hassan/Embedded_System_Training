; Calling an assembly function from a c file.
; the main() function which is writen in c calls a function in assembly called myFunc()

		AREA	|.text|,CODE,READONLY,ALIGN=2			; The |.text| directive tels the assembler that following code will be called by C code
		THUMB
		ALIGN
		EXPORT		myFunc

myFunc
		mov		r0, #121
		; str		r0, [r0]
		bx		lr
		ALIGN
		end
		
