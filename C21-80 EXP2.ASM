DATA SEGMENT 
    MSG DB ODH, OAH, "-- -- -- -- OF DF IF TF SF ZF -- AF-- PF -- CF$"
    NEWL DB ODH, OAH, 0AH, "$"
    FAG DW ?
DATA ENDS

CODE SEGMENT
        ASSUME CS: CODE, DS: DATA
        START:
        MOV AX, DATA
        MOV DS, AX

        MOV DX, OFFSET MSG
        MOV AH, 09H
        INT 21H

        MOV DX, OFFSET NEWL
        MOV AH, 09H
        INT 21H

        PUSHF
        POP BX

        MOV FLAG, 10H
        MOV BX, 8000H

        LOOPS:
            MOV AX, FLAG
            AND AX, BX
            JZ ZERO
            MOV DL, 31H
            MOV AH, 02H
            INT 21H
            JMP SPACE

        ZERO:
            MOV DL, 30H
            MOV AH, 02H
            INT 21H
        
        SPACE:
            MOV DL, ''
            MOV AH, 02H
            INT 21H
        
            MOV AH, 02H
            INT 21H

            ROR BX, 1
            LOOP LOOPS
            
            MOV AH, 4CH
            INT 21H

CODE ENDS
END START
