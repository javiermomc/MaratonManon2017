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

int height=25, width = 100;
int yMonitoPasada, yMonitoActual, yManzanita=12;
int input;
int arrows=3;
int win=0;
// if win = 1 you win the game, if is 2 you lose

void printDude(){

printf(" @ \n");
printf("-|->\n");
printf("] [\n");

}

void printMonito(int y){
	gotoxy(0, yMonitoPasada);
	printf("   \n    \n   \n");
	gotoxy(0, y);	
	printDude();
	yMonitoPasada=y;
}

void shootArrow(){
	int y =yMonitoActual+1;
	if(y==yManzanita){
		for(int x = 3; x<92; x++){
			gotoxy(x,y) printf(">>--->>");
			Sleep(10);
			gotoxy(x,y) printf("       ");
		}
		win=1;
	}else{
		for(int x = 3; x<93; x++){
			gotoxy(x,y) printf(">>--->>");
			Sleep(10);
			gotoxy(x,y) printf("       ");
		}
	}
	arrows--;
}

void moveMonito(){
	if(kbhit()){
		input = getch();
		if(input==80&&yMonitoActual<height-3)yMonitoActual++;
		if(input==72&&yMonitoActual>0)yMonitoActual--;
		if(input==13)shootArrow();
		printMonito(yMonitoActual);	
	}
}

void gameStatus(){
	if (win == 1){
		system("cls");
		gotoxy(50,13); printf("You Win!");	
	}
	else if(arrows==0){
		system("cls");
		gotoxy(50,13); printf("You Lose!");
		win=2;
	}
}

main(){
	gotoxy(width-1, yManzanita);
	printf("*");
	printMonito(yMonitoActual);
	while(win==0){
		moveMonito();
		gameStatus();
	}
}

