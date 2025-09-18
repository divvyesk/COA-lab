
data segment
msg1 db 0dh, 0ah, "Enter first bcd number $"
msg2 db 0dh,0ah,"Enter second bcd number $"
msg3 db 0dh,0ah, "Result of 2 bcd numbers is $"
data ends

code segment
ASSUME cs:code, ds:Data
start:
    mov ax,data
    mov ds,ax

    mov dx, OFFSET msg1
    mov ah,09h
    int 21h

    mov ah,01h
    int 21h

    sub al,30h

    mov cl,04h
    ROL al,cl
    mov bl,al
    
    mov ah,01h
    int 21h

    sub al,30h
    add bl,al

    mov dx, OFFSET msg2
    mov ah,09h
    int 21h

    mov ah,01h
    int 21h

    sub al, 30h

    mov cl,04h
    ROL al,cl
    mov bh,al

    mov ah,01h
    int 21h

    sub al,30h
    add bh,al

    

    mov dx, OFFSET msg3
    mov ah,09h
    int 21h
    mov al,bh
    add al,bl

    daa
    mov bh,al

    jnc down
    mov dl,31h
    mov ah,02h
    int 21h

    down:
    mov cl,04h
    mov al,bh

    and al, 0F0h
    ROR al,cl
    add al,30h

    mov dl,al
    mov ah,02h
    int 21h

    mov al,bh
    and al, 0Fh 
    add al,30h

    mov dl,al
    mov ah,02h
    int 21h

    mov ah,4ch
    int 21h

code ends
END start



