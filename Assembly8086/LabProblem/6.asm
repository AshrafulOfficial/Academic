.model small
.stack 100h
.data
a db 'Enter Number1: $'
b db 10,13,'Enter Number2: $'
c db 10,13,'The reverse from stack: $'
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,a
    int 21h
    
    mov ah,1
    int 21h
    push ax
    
    mov ah,9
    lea dx,b
    int 21h
    
    mov ah,1
    int 21h
    push ax
    
    mov ah,9
    lea dx,c
    int 21h
    
    pop ax
    mov ah,2
    mov dl,al
    int 21h
    
    pop ax
    mov ah,2
    mov dl,al
    int 21h
    
    exit:
    mov ah,4ch
    int 21h
    
    main endp
end main
    