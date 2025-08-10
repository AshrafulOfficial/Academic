.model small
.stack 100h
.data
g db 'Enter the number(0-99): $'
a db 10,13,'The grade is: A+ $'
b db 10,13,'The grade is: A $ '
c db 10,13,'The grade is: B $'
d db 10,13,'The grade is: C $'
    input db 3
          db ?

.code
main proc
    mov ax, @data
    mov ds, ax

    mov ah, 9
    lea dx, g
    int 21h

    mov ah, 10
    lea dx,input
    int 21h
    
    mov cl,input[1]
    mov si,offset input+2
    xor ax,ax
    
    cmp cl,2
    jne exit
    
    mov al,[si]
    sub al,48
    mov bl,10
    mul bl
    mov bl,[si+1]
    sub bl,48
    add al,bl        

    cmp al, 80
    jge A1

    cmp al, 70
    jge B1

    cmp al, 60
    jge C1

    cmp al, 50
    jge D1

A1:
    mov ah, 9
    lea dx, a
    int 21h
    jmp exit

B1:
    mov ah, 9
    lea dx, b
    int 21h
    jmp exit

C1:
    mov ah, 9
    lea dx, c
    int 21h
    jmp exit

D1:
    mov ah, 9
    lea dx, d
    int 21h
    jmp exit

exit:
    mov ah, 4Ch
    int 21h

main endp
end main
