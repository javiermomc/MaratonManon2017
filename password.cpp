#if defined(_WIN32) || defined(WIN32) // Windows-way ~
   #define WIN32_LEAN_AND_MEAN // para no incluir cosas innecesarias en windows.h
   #include <Windows.h>
   #define gotoxy(x,y) {COORD a;a.X = x; a.Y = y;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);}
#else // Linux-Way =)
   #include <ncurses.h>
   #define gotoxy(x,y) move(x,y)
#endif
#include <stdio.h>
#include <conio.h>
#include <string.h>

char name[16], password[16];
int error=0;
int passwordLen;
int espChar=0;
 
void getPassword(){
	char input;
	for(int i =0; i<16; i++)password[i]=0;
	for(int i=0; i<=15; i++){
		if(input!=13){
			input = getch();
			if(input!=13)
			printf("*");
			password[i]=input;
			passwordLen++;	
		}else{
			password[i]='\0';
			break;
		}
	}
	if(input==13)
		password[16]='\0';
}

 void checkPassword(){
 	while(strlen(password)<6){
 		gotoxy(11, 0);
 		printf("                 ");
 		gotoxy(11, 0);
 		getPassword();
 		gotoxy(0,1);
 		if(strlen(password)<6||(strlen(password)>15&&password[16]==0))printf("ERROR PASSWORD FUERA DE RANGO");
	 }
 }
 
int checkUpperCase(){
	int allMayus;
	int mayus;
	for(int i=0; i<passwordLen; i++){
		if(password[i]>=65&&password[i]<=90)mayus++;	
	}
	if(mayus==passwordLen-1)return 2;
	else if(mayus>0)return 1;
	return 0;
}

int checkNum(){
	int mayus=0;
	for(int i=0; i<passwordLen; i++){
		if(password[i]>=48&&password[i]<=57)mayus++;
		else if	(password[i]<65||password[i]>90){
//			printf("%d", espChar);j
			espChar++;
		}
	}
//	printf("%d",mayus);getche();

	if(mayus==passwordLen-1)return 2;
	else if(mayus>0)return 1;
	
	return 0;
}

main(){
	printf("Password: ");checkPassword();
	int up=checkUpperCase();
	int num = checkNum();
	int nivel;
	if(up==2||num==2||num==0||up==0)nivel=1;
	if(up==1||(up==0&&num==1)||(up==1&&num==1))nivel=2;
	if(espChar>0)nivel=3;
	if(up==1&&num==1)nivel=4;
	if(up==1&&num==1&&espChar>0)nivel=5;
	
	printf("Nivel %d", nivel);
	
	
	
}
