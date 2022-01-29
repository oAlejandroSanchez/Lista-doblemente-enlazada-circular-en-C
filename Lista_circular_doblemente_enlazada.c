//Definición de librerías
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

//Definición de variables
typedef struct _Nodo{
	
	struct _Nodo *anterior;
	char *nombre;
	char numero_de_cuenta[9];
	char edad[2];
	struct _Nodo *siguiente;
	
}Lista;

Lista *lista_principio = NULL;
Lista *lista_final = NULL;

//Definición de funciones secundarias
void Menu(void);
void Inciso_a(void);
Lista *Ingresar_elementos(Lista *,Lista *);

void Inciso_b(void);
void Menu_mostrar_elementos(void);
void lista_ordenada(void);
void lista_orden_inverso(void);

void Inciso_c(void);

void Inciso_d(void);
void Eliminar_elementos(void);
void Eliminacion_por_delante(void);
void Eliminacion_por_detras(void);
void Eliminacion_hecha(void);

int Inciso_e(void);

void Opcion_invalida(void);

//Función principal
int main(void){
	
	char opcion;
	
	do{
		
		Menu();
		
		printf("\n\n\nApriete 'N' para salir del programa: ");
		fflush(stdin);
		scanf("%c", &opcion);
		
	}while(opcion != 'N');
	
	return 0;
	
}

//Muestra en pantalla el menú de opciones del programa principal
void Menu(void){
	
	char opcion;
	
	system("cls");
	
	printf("\t\tBASE DE DATOS.\n\n");
	printf("Elige una de las siguientes opciones: ");
	printf("\na)Ingresar datos.");
	printf("\nb)Mostrar datos.");
	printf("\nc)Eliminar la base de datos.");
	printf("\nd)Eliminar elementos de la base de datos.");
	printf("\ne)Salir.");
	
	printf("\n\nOpci%cn: ", 162);
	fflush(stdin);
	scanf("%c", &opcion);
	
	opcion = tolower(opcion);
	
	switch(opcion){
		
		case 'a':{
			
			Inciso_a();
			
			break;
		}
		case 'b':{
			
			Inciso_b();
			
			break;
		}
		case 'c':{
			
			Inciso_c();
			
			break;
		}
		case 'd':{
			
			Inciso_d();
			
			break;
		}
		case 'e':{
			
			Inciso_e();
			
			break;
		}
		default:{
			
			Opcion_invalida();
			
			break;
		}
		
	}
	
}

//La función del inciso (a), permite al usuario ingresar elementos
//a la base de datos
void Inciso_a(void){
	
	Lista *nodo_auxiliar = (Lista *)malloc(sizeof(Lista));
	Lista *lista_auxiliar;
	char cuenta,anios;
	int maximo = 0;
	
	system("cls");
	
	printf("\t\tINGRESAR DATOS.\n\n");
	printf("Ingresa los siguientes datos: ");
	
	printf("\nNombre: ");
	nodo_auxiliar->nombre = (char *)malloc(sizeof(char)*100);
	fflush(stdin);
	scanf("%[^\n]s",nodo_auxiliar->nombre);
	
	printf("\nN%cmero de cuenta: ", 163);
	fflush(stdin);
	while(((cuenta = getchar()) != '\n') && (maximo < 9)){
		
		if((cuenta == '0') || (cuenta == '1') || (cuenta == '2') || (cuenta == '3') || (cuenta == '4') || (cuenta == '5') || (cuenta == '6') || (cuenta == '7') || (cuenta == '8') || (cuenta == '9')){
			
			nodo_auxiliar->numero_de_cuenta[maximo++] = cuenta;
			
		}else{
			
			continue;
			
		}
		
	}
	
	nodo_auxiliar->numero_de_cuenta[maximo] = '\0';
	maximo = 0;
	
	printf("\nEdad: ");
	fflush(stdin);
	while(((anios = getchar()) != '\n') && (maximo < 2)){
			
		if((anios == '0') || (anios == '1') || (anios == '2') || (anios == '3') || (anios == '4') || (anios == '5') || (anios == '6') || (anios == '7') || (anios == '8') || (anios == '9')){
			
			nodo_auxiliar->edad[maximo++] = anios;
			
		}else{
			
			continue;
			
		}
		
	}
	
	nodo_auxiliar->edad[maximo] = '\0';
	
	printf("\n\n\nLos datos ingresados fueron: ");
	printf("\nNombre: %s", nodo_auxiliar->nombre);
	printf("\nN%cmero de cuenta: %s", 163, nodo_auxiliar->numero_de_cuenta);
	printf("\nEdad: %s\n", nodo_auxiliar->edad);
	
	if(lista_principio == NULL){
		
		lista_auxiliar = lista_final;
		lista_final = Ingresar_elementos(nodo_auxiliar,lista_auxiliar);
		lista_principio = lista_final;
		
	}else{
		
		lista_auxiliar = lista_final;
		lista_final = Ingresar_elementos(nodo_auxiliar,lista_auxiliar);
		lista_principio->anterior = lista_final;
		lista_final->siguiente = lista_principio;
		
	}
	
}

//Esta función acomoda todos los elementos ingresado en una lista circular
//doblemente enlazada
Lista *Ingresar_elementos(Lista *nodo_auxiliar,Lista *lista_auxiliar){
	
	if(lista_auxiliar == NULL){
		
		lista_auxiliar = nodo_auxiliar;
		lista_auxiliar->anterior = lista_auxiliar;
		lista_auxiliar->siguiente = lista_auxiliar;
		
	}else{
		
		lista_auxiliar->siguiente = nodo_auxiliar;
		nodo_auxiliar->anterior = lista_auxiliar;
		lista_auxiliar = nodo_auxiliar;
		
	}
	
	return(lista_auxiliar);
	
}

//La función del inciso (b) verifica si la lista se encuentra vacía, en caso de no ser así
//se manda a llamar otra función para que muestre los datos contenidos dentro de la lista.
void Inciso_b(void){
	
	system("cls");
	
	printf("\t\tMOSTRAR DATOS.\n\n");
	
	if(lista_principio == NULL){
		
		printf("\n\n\n\t\t**************************************************\n");
		printf("\t\t*                                                *\n");
		printf("\t\t*  No hay elementos dentro de la base de datos.  *\n");
		printf("\t\t*                                                *\n");
		printf("\t\t**************************************************\n");
		
	}else{
		
		Menu_mostrar_elementos();
		
	}
		
}

//Esta función desplega un menú de opciones, permitiendole al usuario elegir en que
//forma desea que se muestren los datos ingresados en la lista.
void Menu_mostrar_elementos(void){
	
	char opcion;
	
	printf("Elige una de las siguientes opciones: \n");
	printf("\na)Mostrar elementos ordenados.");
	printf("\nb)Mostrar elementos en orden inverso.");
	
	printf("\n\nOpci%cn: ", 162);
	fflush(stdin);
	scanf("%c", &opcion);
	
	opcion = tolower(opcion);
	
	switch(opcion){
		
		case 'a':{
			
			lista_ordenada();
			
			break;
		}
		case 'b':{
			
			lista_orden_inverso();
			
			break;
		}
		default:{
			
			Opcion_invalida();
			
			break;
		}
		
	}
	
}

//Esta función secundaria muestra en pantalla los datos ingresados hasta el momento
//en la lista en el orden en que fueron ingresados.
void lista_ordenada(void){
	
	system("cls");
	
	Lista *mostrar_elementos;
	
	mostrar_elementos = lista_principio;
	
	do{
		
		printf("Nombre: %s\n", mostrar_elementos->nombre);
		printf("N%cmero de cuenta: %s\n", 163, mostrar_elementos->numero_de_cuenta);
		printf("Edad: %s\n\n", mostrar_elementos->edad);
		printf("******************************************************************\n");
		mostrar_elementos = mostrar_elementos->siguiente;
		
	}while(mostrar_elementos != lista_principio);
	
}

//Esta función secundaria muestra en pantalla los datos ingresados hasta el momento
//en la lista en orden inverso.
void lista_orden_inverso(void){
	
	system("cls");
	
	Lista *mostrar_elementos;
	
	mostrar_elementos = lista_final;
	
	do{
		
		printf("Nombre: %s\n", mostrar_elementos->nombre);
		printf("N%cmero de cuenta: %s\n", 163, mostrar_elementos->numero_de_cuenta);
		printf("Edad: %s\n\n", mostrar_elementos->edad);
		printf("******************************************************************\n");
		mostrar_elementos = mostrar_elementos->anterior;
		
	}while(mostrar_elementos != lista_final);
		
}

//La función del inciso (c) elimina toda la base de datos obtenida en la lista
void Inciso_c(void){
	
	system("cls");
	
	if(lista_principio == NULL){
		
		printf("\n\n\n\t\t**********************************************\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*    La base de datos se encuentra vac%ca.    *\n", 161);
		printf("\t\t*                                            *\n");
		printf("\t\t**********************************************\n");
		
	}else{
		
		lista_principio = NULL;
		lista_final = lista_principio;
		
		printf("\n\n\n\t\t*********************************************\n");
		printf("\t\t*                                           *\n");
		printf("\t\t*   Base de datos eliminada exitosamente.   *\n");
		printf("\t\t*                                           *\n");
		printf("\t\t*********************************************\n");
		
	}
	
}

//La función del inciso (d) verifica si la lista se encuentra vacía, en caso de que no sea así
//se manda a llamar una función secundaria que eliminará un elemento de la lista
void Inciso_d(void){
	
	if(lista_principio == NULL){
		
		system("cls");
		
		printf("\n\n\n\t\t**********************************************\n");
		printf("\t\t*                                            *\n");
		printf("\t\t*    La base de datos se encuentra vac%ca     *\n", 161);
		printf("\t\t*                                            *\n");
		printf("\t\t**********************************************\n");
		
	}else{
		
		Eliminar_elementos();
		
	}
	
}

//Esta función muestra en pantalla un menú, el usuario puede elegir en donde se hace la eliminación
//puede realizarse por delante o por detras de la lista
void Eliminar_elementos(void){
	
	char opcion;
	
	system("cls");
	
	printf("\t\tELIMINAR ELEMENTOS.\n\n");
	printf("Elige una de las siguientes opciones: ");
	printf("\na)Eliminar elementos por delante de la lista.");
	printf("\nb)Eliminar elementos por detras de la lista.");
	
	printf("\n\nOpci%cn: ", 162);
	fflush(stdin);
	scanf("%c", &opcion);
	
	opcion = tolower(opcion);
	
	switch(opcion){
		
		case 'a':{
			
			Eliminacion_por_delante();
			Eliminacion_hecha();
			
			break;
		}
		case 'b':{
			
			Eliminacion_por_detras();
			Eliminacion_hecha();
			
			break;
		}
		default:{
			
			Opcion_invalida();
			
			break;
		}
		
	}
	
}

//La eliminación se hace por delante de la lista
void Eliminacion_por_delante(void){
	
	if(lista_principio == lista_final){
		
		lista_principio = NULL;
		lista_final = lista_principio;
		
	}else{
		
		Lista *eliminar_elementos = NULL;
		
		eliminar_elementos = lista_principio;
		lista_principio = lista_principio->siguiente;
		lista_principio->anterior = lista_final;
		lista_final->siguiente = lista_principio;
		free(eliminar_elementos);
				
	}
	
}

//La eliminación se hace por detras de la lista
void Eliminacion_por_detras(void){
	
	if(lista_final == lista_principio){
		
		lista_principio = NULL;
		lista_final = lista_principio;
		
	}else{
		
		Lista *eliminar_elementos;
		
		eliminar_elementos = lista_final;
		lista_final = lista_final->anterior;
		lista_final->siguiente = lista_principio;
		lista_principio->anterior = lista_final;
		free(eliminar_elementos);
		
	}
	
}

//Muetsra un mensaje en la pantalla de que la eliminación se ha completado
//exitosamente
void Eliminacion_hecha(void){
	
	system("cls");
	
	printf("\n\n\n\t\t************************************************\n");
	printf("\t\t*                                              *\n");
	printf("\t\t*  Se ha eliminado un elemento correctamente.  *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t************************************************\n");
	
}

//Esta función le permite al usuario finalizar el programa principal
int Inciso_e(void){
	
	exit(1);
	
}

//En caso de que el usuario se equivoque al introducir una opción se mostrará
//en la pantalla un mensaje avisandole que lo intente de nuevo.
void Opcion_invalida(void){
	
	system("cls");
	
	printf("\n\n\n\t\t*************************************\n");
	printf("\t\t*                                   *\n");
	printf("\t\t*         Opci%cn inv%clida.          *\n", 162, 160);
	printf("\t\t*        Vuelve a intentarlo.       *\n");
	printf("\t\t*                                   *\n");
	printf("\t\t*************************************\n");
	
}
