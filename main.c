 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 #include<windows.h>
 #include "method.h"

int i,j;

// check the password ~_~
void main() {
	char pass [10],ch;
	system("color 4F");
	printf("\n\t\t\t\t\tEnter your password : ");	
	for(i=0;i<4;i++)
	{
		ch = getch();
		pass[i] = ch;
		ch = '*' ;
		printf("%c",ch);
	}
	pass[i] = '\0';
	
		
	if (strcmp(pass,"nael")==0){
		system("color 4A");
		printf("\n\t\t\t\t\tLogin successful!\n\t\t\t\t\tLOADING ");
		for(i=0 ; i<10 ; i++){
			delay(100000000);
			printf("--");
			delay(100000000);
			printf("\b");
		}
		system("cls");
		menu();
	}
	else{
		system("color 4C");
		printf("\n\n\t\t\t\t\t\tWrong password\a");
		try_again:
			printf("\n\t\t\t\t\tEnter 1 to try again OR 0 to exit : ");
			scanf("%d",&main_exit);
			if (main_exit == 1){
				system("cls");
				main();
			}
			else if (main_exit == 0) {
				system("cls");
				system("color 40");				
				printf("\n\t\t\t\t\tGOOD BYE ");
				for(i=0 ; i<10 ; i++){
					delay(100000000);
					printf("--");
					delay(100000000);
					printf("\b");
				}
				exit(1);
			}
			else {
				system("cls");
				system("color 4E");
				printf("\n\t\t\t\t\tInvalid choice *_*");
				delay(1000000000);
				goto try_again;
			}
	}
	return ;
}
