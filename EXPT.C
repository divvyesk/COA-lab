#include<stdio.h>
#include<stdlib.h>


char count=0;

void main(){
	int choice=0;
	
	while(1){
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){

			case 1:
				if(count>4)
					printf("Maximum size reached");
				else{
				count++;
				asm mov ah,01H
				asm mov ch,00H
				asm mov cl,01H + count
				asm INT 10H
				}
				break;



				case 2:if(count<=0){
					printf("Already Minimum Size!!");
				}
				else {
					count--;
					asm mov ah,01H
					asm mov ch,00H
					asm mov cl,00H+count
					asm INT 10H
				}
				break;

				case 3:
					asm mov ah,01H
					asm mov ch,01H
					asm mov cl,00H
					asm INT 10H

					break;

					case 4:exit(EXIT_SUCCESS);

		}

	}
}
