.model small
.stack 100h
.code
main proc
    mov ah,2
    mov dl,7
    int 21h
    
    main endp
end main