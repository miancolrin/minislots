/*
Pequeño programa en C que emula una tragaperras.

Se generan 3 numeros aleatorios entre 0 y 6
Dependiendo de la combinación de esos tres números habrá premio o no
Al final nos sale la ganancia.

Creado por @miancolrin

Versión 0.0.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

void displaySlots(char slot1, char slot2, char slot3);
void genAleatorios(int *aleatorio1, int *aleatorio2, int *aleatorio3);
void asignarAleatorios(int aleatorio1, int aleatorio2, int aleatorio3, char *slot1, char *slot2, char *slot3);

int main(){
	
	//Juego de caracteres
	setlocale(LC_CTYPE, "Spanish");
	
	//Título de consola
	SetConsoleTitle("minislots");
	
	//Color de consola
	system("color 60");
	
	//Números aleatorios que defienen la figura que sale
	int	aleatorio1, aleatorio2, aleatorio3;
	char slot1, slot2, slot3;
	char continuar;
	
	
	
	do{
		system("cls");
		
		genAleatorios(&aleatorio1, &aleatorio2, &aleatorio3);
		
		asignarAleatorios(aleatorio1, aleatorio2, aleatorio3, &slot1, &slot2, &slot3);
		
		displaySlots(slot1, slot2, slot3);
		
		printf("\n\nPREMIO: ");
		
		if(slot1 == slot2 && slot2 == slot3){
			printf("PREMIO GORDO!!!");
		}
		else if(slot1 == slot2 && slot2 != slot3){
			printf("PREMIO MEDIO");
		}
		else if(slot1 != slot2 && slot2 == slot3){
			printf("PREMIO PEQUEÑO");
		}
		else{
			printf("NADA. Más suerte otra vez.");
		}
		
		printf("\n\n\nPresione cualquier tecla para jugar, N para salir\n\n");
		continuar = getch();
		if(continuar == 'N' || continuar == 'n'){
			break;
		}
		
		
	}while(continuar != 'S' && continuar != 'S');
	
	system("cls");
	printf("Muchas gracias por usar este software.");
	printf("\n\nRecuerde: el juego puede producir ludopatía\n\n");
	printf("Presione cualquier tecla para salir\n\n\n");
	system("pause > nul");
	
}

void genAleatorios(int *aleatorio1, int *aleatorio2, int *aleatorio3){
	
	srand (time(NULL));
	
	int al1 = rand() %6;
	int al2 = rand() %6;
	int al3 = rand() %6;
	
	*aleatorio1 = al1;
	*aleatorio2 = al2;
	*aleatorio3 = al3;
	
	return;

}

void asignarAleatorios(int aleatorio1, int aleatorio2, int aleatorio3, char *slot1, char *slot2, char *slot3){
	
	//Aleatorio1
	if(aleatorio1 == 0){
		*slot1 = 'A';
	}
	else if(aleatorio1 == 1){
		*slot1 = 'B';
	}
	else if(aleatorio1 == 2){
		*slot1 = 'C';
	}
	else if(aleatorio1 == 3){
		*slot1 = 'D';
	}
	else if(aleatorio1 == 4){
		*slot1 = 'E';
	}
	else if(aleatorio1 == 5){
		*slot1 = 'F';
	}
	
	//Aleatorio2
	if(aleatorio2 == 0){
		*slot2 = 'A';
	}
	else if(aleatorio2 == 1){
		*slot2 = 'B';
	}
	else if(aleatorio2 == 2){
		*slot2 = 'C';
	}
	else if(aleatorio2 == 3){
		*slot2 = 'D';
	}
	else if(aleatorio2 == 4){
		*slot2 = 'E';
	}
	else if(aleatorio2 == 5){
		*slot2 = 'F';
	}
	
	//Aleatorio3
	if(aleatorio3 == 0){
		*slot3 = 'A';
	}
	else if(aleatorio3 == 1){
		*slot3 = 'B';
	}
	else if(aleatorio3 == 2){
		*slot3 = 'C';
	}
	else if(aleatorio3 == 3){
		*slot3 = 'D';
	}
	else if(aleatorio3 == 4){
		*slot3 = 'E';
	}
	else if(aleatorio3 == 5){
		*slot3 = 'E';
	}
	
	return;
	
}

void displaySlots(char slot1, char slot2, char slot3){
	
	system("cls");
	
	printf("#################"); printf("\t\t\t\t#######TABLA DE PREMIOS#######\n");
	printf("## %c ## %c ## %c ##", slot1, slot2, slot3); printf("\t\t\t\t## X X X    PREMIO GORDO    ##\n");
	printf("#################"); printf("\t\t\t\t## X X -    PREMIO MEDIO    ##\n");
	printf("\t\t\t\t\t\t## - X X    PREMIO PEQUEÑO  ##");
	printf("\t\t\t\t\t\t\t\t\t\t##############################");
	
}
