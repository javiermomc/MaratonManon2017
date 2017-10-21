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

float calif1[10],calif2[10],calif3[10];
int mat[10];
int lenAl, error;
int on=0;
int finish=2;


int find(int valor){
	for(int i=0; i<lenAl; i++)if(valor==mat[i]){
		lenAl--;
		return 1;	
	}
	return 0;
}

void captura(){
	for(int i=0; i<10; i++){
		error=0;
		mat[lenAl]=1;
		while(mat[lenAl]<1000||mat[lenAl]>1999){
			error=find(mat[lenAl]);
			system("cls");
			gotoxy(0,0);	
			printf("*** CAPTURA DE CALIFICACIONES DEL ALUMNO %d*****\n\n",lenAl+1);
			if(error==1){
				gotoxy(0,1);
				printf("*** ERROR * MATRICULA FUERA DE RANGO O REPETIDA *****\n");
				error=0;
			}
			printf("Indique la matr%ccula del alumno : [     ]\n",161);
			printf("Indique la calificaci%cn 1       : [     ]\n",162); 
			printf("Indique la calificaci%cn 2       : [     ]\n",162); 
			printf("Indique la calificaci%cn 3       : [     ]\n",162); 
			printf("PARA TERMINAR COLOQUE UN CERO EN LA MATR%cCULA",161);	
			gotoxy(35,2);scanf("%d",&mat[lenAl]);  
			if(mat[lenAl]>=1000&&mat[lenAl]<=1999&&find(mat[lenAl])==0){
				gotoxy(0,1);
				printf("                                          ");
				calif1[lenAl]=-1;
				calif2[lenAl]=-1;
				calif3[lenAl]=-1;
				while(calif1[lenAl]>100||calif1[lenAl]<0){
					gotoxy(35,3);printf("     ");
					gotoxy(35,3);scanf("%f",&calif1[lenAl]);
				}
				while(calif2[lenAl]>100||calif2[lenAl]<0){
					gotoxy(35,4);printf("     ");
					gotoxy(35,4);scanf("%f",&calif2[lenAl]);
				}
				while(calif3[lenAl]>100||calif3[lenAl]<0){
					gotoxy(35,5);printf("     ");
					gotoxy(35,5);scanf("%f",&calif3[lenAl]);
				}
						
			}else
				 error=1;
			if(mat[lenAl]==0){
				i=20;
				break;	
			}
			
			if(mat[lenAl]!=0&&mat[lenAl]>=1000&&mat[lenAl]<=1999&&find(mat[lenAl])==0){
				lenAl++;
			}
		}
	}
}

void promedio(){
	float promedioActual, promedioGeneral;
	int aprobados=0;
	system("cls");
	printf("Matricula   Calif1   Calif2   Calif3   Promedio\n");
	printf("-----------------------------------------------\n");
	for(int i=0; i<lenAl; i++){
		promedioActual= (calif1[i]+calif2[i]+calif3[i])/3;
		promedioGeneral+=promedioActual;
		printf("%d         %.2f         %.2f         %.2f         %.2f\n", mat[i], calif1[i], calif2[i], calif3[i], promedioActual);
		if(promedioActual>=70)aprobados++;
	}
	printf("-----------------------------------------------\n");
	printf("EL PROMEDIO DEL GRUPO ES :                   %.2f\n",promedioGeneral/lenAl);
	printf("EL TOTAL DE APROBADOS ES :                   %d\n",aprobados);
	printf("EL TOTAL DE REPROBADOS ES :                  %d\n",lenAl-aprobados);
	
}

main(){
	captura();
	promedio();
}
