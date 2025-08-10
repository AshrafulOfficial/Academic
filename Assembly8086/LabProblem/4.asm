.model
.stack 100h
.data
a db 'Enter a bit Pattern: $'
b db 10,13,'The Reverse Pattern: $'
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,a
    int 21h
    
read_loop:
    mov ah,1
    int 21h
    cmp al,13
    je reverse
    
    cmp al,'0'
    jb read_loop
    
    cmp al,'1'
    ja read_loop
    
    push ax
    
    jmp read_loop
reverse:
    mov ah,9
    lea dx,b
    int 21h
print_reverse:
    cmp sp,100h
    je exit
    
    pop ax
    mov ah,2
    mov dl,al
    int 21h
    
    jmp print_reverse
exit:
    mov ah,4ch
    int 21h
    main endp
end main
    