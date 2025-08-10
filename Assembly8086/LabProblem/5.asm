.model small
.stack 100h
.data
a db 'Enter a String: $'
b db 10,13,'Reverse String is: $'
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,a
    int 21h
    
read_string:
    mov ah,1
    int 21h
    
    cmp al,13
    je reverse
    
    push ax
    jmp read_string
reverse:
    mov ah,9
    lea dx,b
    int 21h
reverse_print:
    cmp sp,100h
    je exit
    
    pop ax
    mov ah,2
    mov dl,al
    int 21h
    
    jmp reverse_print
exit:
    mov ah,4ch
    int 21h
    main endp
end main