.model
.stack 100h
.data
a db 10,13,'Even Number $'
b db 10,13,'Odd Number $'
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,1
    int 21h
    sub al,48
    
    test al,1
    jz print_even
    
    print_odd:
    mov ah,9
    lea dx,b
    int 21h
    jmp exit
    
    print_even:
    mov ah,9
    lea dx,a
    int 21h
    jmp exit
    
    exit:
    mov ah,4ch
    int 21h
    main endp
end main