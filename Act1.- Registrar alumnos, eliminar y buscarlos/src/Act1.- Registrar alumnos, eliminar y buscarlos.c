/*
 ============================================================================
 Name        : menu.c
 Author      : David Flores Ruiz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Libería para cadenas

#define MAX 20

	typedef struct{
		int expediente;
		char nombre[20];
		int carrera;
		int edad;
	}Alumno;


	void altaAlumno (Alumno alumnos[MAX], int posicion, Alumno *arrApuntadores[]);

	void imprimirAlumnos(Alumno alumnos[MAX], Alumno *arrApuntadores[]);

	void eliminarAlumno (Alumno alumnos[MAX], Alumno *arrApuntadores[]);

	void buscarAlumno (Alumno alumnos[MAX], Alumno *arrApuntadores[]);

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int opcion;
	int posicion=0;
	Alumno alumnos[MAX];//Arreglo estático

	Alumno *arrApuntadores[MAX];

	for(int i=0; i<MAX; i++){
		arrApuntadores[i] = NULL;	//Inicializar el Arreglo de apuntadores en posiciones NULL
	}

	    do{
	        printf("\n1. Registrar nuevo alumno");
	        printf("\n2. Imprimir datos");
	        printf("\n3. Eliminar alumno");
	        printf("\n4. Buscar alumno\n \t -Por expediente \n \t -Por edad");
	        printf("\n5. Salir");

	        printf("\nEscoja su opción (1-5) la número válido:");
	        scanf("%d", &opcion);

	        switch(opcion)
	           {
	               case 1: altaAlumno (alumnos, posicion, arrApuntadores);
	               	   	   posicion++;
	                       break;

	               case 2: imprimirAlumnos (alumnos, arrApuntadores);
	                       break;

	               case 3: eliminarAlumno (alumnos, arrApuntadores);

	                       break;


	               case 4: buscarAlumno (alumnos, arrApuntadores);

	            	   	   break;

	               default:
	            	   if(opcion != 5)
	                       printf( "\n   Número NO válido, escoja de nuevo\n");
	           }

	    }while(opcion != 5);

	return EXIT_SUCCESS;
}

void altaAlumno (Alumno alumnos[MAX], int posicion, Alumno *arrApuntadores[]){
		Alumno *arrAlumno = alumnos;	//Declarar puntero local
		int auxExp;
		char auxNombre[20];
		int auxNum;
		int auxEdad;

		printf("Dame el numero de expediente:\n");
		scanf("%d", &auxExp);

		setbuf(stdin, 0);
		printf("Dame el nombre:\n");
		gets(auxNombre);

		printf("Dame el numero de carrera:\n");
		scanf("%d", &auxNum);

		setbuf(stdin, 0);
		printf("Dame la edad:\n");
		scanf("%d", &auxEdad);

		(arrAlumno + posicion)->expediente = auxExp;
		strcpy(((arrAlumno + posicion)->nombre),"");
		strcpy( ((arrAlumno + posicion)->nombre), auxNombre );
		(arrAlumno + posicion)->carrera = auxNum;
		(arrAlumno + posicion)->edad = auxEdad;

		arrApuntadores[posicion] = (arrAlumno + posicion);	//Ya no es NULL el Arreglo del main
	}

void imprimirAlumnos(Alumno alumnos[MAX], Alumno *arrApuntadores[]){
	Alumno *puntDezplaza = alumnos;
	printf("\nLos alumnos registrados al momento son:");
	for(int i=0; i < MAX; i++){
		if (arrApuntadores[i] != NULL)//IMPRIMIR SOLO LOS QUE NO APUNTEN A NULL
		{
			//printf("\n\n###NO ES NULL###");
			printf("\n\n*****Alumno %d*****", i+1);
			printf("\nExpediente: %d", (*(puntDezplaza + i)).expediente);//Notaciones para acceder al Contenido con Apuntador
			printf("\nNombre: %s", (puntDezplaza + i)->nombre);	//otra Notacion
			printf("\nCarrera: %d", (puntDezplaza + i)->carrera);
			printf("\nEdad: %d\n",(puntDezplaza + i)->edad);
		}
	}

}

void eliminarAlumno (Alumno alumnos[MAX], Alumno *arrApuntadores[]){
	Alumno *apunArr = alumnos;
	int expBorrar;
	printf("\nDame el num. de Expediente del Alumno que desea borrar:");
	scanf("%d", &expBorrar);
	for(int i=0; i < MAX; i++){
		if ((apunArr + i)->expediente == expBorrar)
		{
			arrApuntadores[i] = NULL;	//Por que no lo pude poner:	 (arrApuntadores + i)  =  NULL;
		}
	}
	printf("Alumno eliminado\n");
}

void buscarAlumno (Alumno alumnos[MAX], Alumno *arrApuntadores[]){
	Alumno *apunArr = alumnos;
	int numBusqueda; //Para buscar por 2 caminos diferentes!
	int numExpediente;
	int numEdad;
	printf("\nBuscar por expediente (presione 1)\n");
	printf("\nBuscar por edad (presione 2)\n");
	scanf("%d", &numBusqueda);

	if(numBusqueda == 1)
		{
			printf("Cual es el num de Expediente: ");
			scanf("%d", &numExpediente);
		}
	else
		if(numBusqueda == 2)
			{
				printf("Cual es la edad del alumno: ");
				scanf("%d", &numEdad);
			}

	int bandera = 0;

	for(int i=0; i < MAX; i++){
		if(numBusqueda == 1 && ((apunArr + i)->expediente == numExpediente) && (arrApuntadores[i] != NULL))
		{
			printf("\n****Alumno %d****", i+1);
			printf("\nEl número de expediente es: %d", (apunArr + i)->expediente);
			printf("\nEl nombre del alummno es: %s", (*(apunArr + i)).nombre);
			printf("\nEl numero de carrera del alumno es: %d", (apunArr + i)->carrera);
			printf("\nLa edad del alumno es: %d\n\n", (apunArr + i)->edad);
			bandera = 1;
		}
		else
			if(numBusqueda == 2 && ((apunArr + i)->edad == numEdad) && (arrApuntadores[i] != NULL))
			{
				printf("\n****Alumno %d****", i+1);
				printf("\nEl número de expediente es: %d", (apunArr + i)->expediente);
				printf("\nEl nombre del alummno es: %s", (*(apunArr + i)).nombre);
				printf("\nEl numero de carrera del alumno es: %d", (apunArr + i)->carrera);
				printf("\nLa edad del alumno es: %d\n\n", (apunArr + i)->edad);
				bandera = 1;
			}
	}

	if(numBusqueda == 1 || numBusqueda == 2)
					{
						if(bandera == 0)
							printf("\nNo se encontro ningun alumno en su búsqueda\n");
					}


}
