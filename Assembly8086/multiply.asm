.model small
.stack 100h
.code
main proc
    mov al,2
    mov bl,3
    mul bl    ;al=al*bl
    
    mov ah,2
    mov dl,al
    add dl,48
    int 21h
    
    main endp
end main