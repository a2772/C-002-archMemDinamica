#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define N 200
#define false 0
#define true 1

//Función para encontrar la cadena
int strcmp2(char*, char*);
int isIdentifier(char*);
int aux=0;
int main(){
///Variables
	FILE *archivo = NULL,*reserva = NULL;//File, uno para el programa y otro para palabras reservadas
	int i,j,rows,nReservadas,*nLine;//Contador auxiliar, lo usamos en los for y en otras cosas
	char *content;//Arreglo donde almacenaremos el contenido del archivo
	char **cntFile,**cntRes;//Matriz dinámica
	printf("Objetivo: Programa que muestre las l%cneas del c%cdigo que contengan palabras reservadas\n",161,162);
	
	
	
///Archivo del programa
	archivo = fopen("Programa.txt","r");//Abrimos el archivo
	if(archivo==NULL){//En caso de que haya error
    	printf("No se puede abrir el fichero. \n");
    	exit(1);
	}
	rewind(archivo);//Regresamos el cursor al inicio del archivo
	content = (char*)malloc(N*sizeof(char));//Asignamos el tamaño al arreglo
	//Ahora recuperamos el contenido en nuestro arreglo
	i=0;
	printf("\t***Archivo con el programa original***\n-----------------------------------------------\n");
	while (feof(archivo) == 0){
 		fgets(content,N*sizeof(char),archivo);
 		i++;//Por cada linea incrementamos el contador
 		printf("%s",content);
 	}
 	//Asignamos tamaño a nuestra matriz, con el número de filas
 	i--;
 	cntFile = (char**)malloc(i*sizeof(char*));
 	if(cntFile==NULL)
 		exit(1);
	rewind(archivo);//Regresamos el cursor al inicio del archivo
 	//Asginamos el tamaño a cada fila
 	i=0;
 	while (feof(archivo) == 0){
 		fgets(content,N*sizeof(char),archivo);
 		cntFile[i]=(char*)malloc(sizeof(content)*sizeof(char));//Asignamos la fila
 		if(cntFile[i]==NULL)
 			exit(1);
 		//Asignamos el contenido
 		i++;//Por cada linea incrementamos el contador, termina con el valor de las filas
 	}
 	rewind(archivo);//Regresamos el cursor al inicio del archivo
 	//Asginamos el tamaño a cada fila
 	i=0;
 	while (feof(archivo) == 0){
 		fgets(content,N*sizeof(char),archivo);
 		//Asignamos el contenido
 		strcpy(cntFile[i],content);
 		//strcat(cntFile[i],""+'\0');
 		i++;//Por cada linea incrementamos el contador, termina con el valor de las filas
 	}
 	rows=i;//Guardamos el número de filas
	//Cerramos archivo
	fclose(archivo);
	
	
	
///Match con identificadores
	///Imprimimos las líneas con identificadores
	printf("\n\t***Lineas con identificadores***\n-----------------------------------------------\n");
	for(i=0;i<rows;i++) {
		if(isIdentifier(cntFile[i])==true) {
			//printf("%s",cntFile[i]);
			printf("TRUE");
		}else{
			printf("FALSE");
		}
	}
	///Liberamos memoria dinámica
	free(content);
	free(cntFile);
	return 0;
}
int strcmp2(char* cadena, char* palabra){//Devuelve -1 si la cadena no se encuentra
    int i, j = 0,tam=strlen(cadena)-1;
    for(i=0;i<tam;i++){
        if(palabra[j] == cadena[i]){
            ++j;
            if(j == tam)
                return (2 + i - j);
        }
        else j = 0;
    }
    return -1;
}
int isDec(char* cadena){//Evalúa si es una declaración, devuelve -1 si no lo es
    int flag=-1;
    if(strcmp2(cadena,"char")!=-1){
    	flag=4;
	}else if(strcmp2(cadena,"int")!=-1){
		flag=3;
	}else if(strcmp2(cadena,"long")!=-1){
		flag=4;
	}else if(strcmp2(cadena,"double")!=-1){
		flag=6;
	}else if(strcmp2(cadena,"float")!=-1){
		flag=5;
	}else if(strcmp2(cadena,"short")!=-1){
		flag=5;
	}
    return flag;
}
int isIdentifier(char* cad){//Evalúa si es o no un identificador
	char cadena[200];
	strcpy(cadena,cad);
	aux++;
    int i,flag=false,tam=strlen(cadena)-1;
	printf("%i)lenght: %i\n",aux,tam);
    if(tam<=3){//Omitimos
    	for(i=0;i<tam;i++)
    		printf("°%c",cadena[i]);
    	printf("\n");
	}else{
		if(isDec(cadena)!=-1){//Si tiene el tipo de dato como char, int, etc.
	    	i=isDec(cadena)+1;//Empezaría en el espacio despues de la palabra ejemplo char 
	    	////////////////////////////////////////////////////////////////////////////?
	    	//printf("\nPalabra de declaracion correcta");
	    	if( (tolower(cadena[i])>='a' && tolower(cadena[i])<='z') || cadena[i]=='_' ){
	    		//printf("\nEmpieza bien");
	    		flag = true;
		    	for(;i<tam-1;i++){
		    		if( (tolower(cadena[i])>='a' && tolower(cadena[i])<='z') || cadena[i]=='_' || (tolower(cadena[i])>='0' && tolower(cadena[i])<='9')){
		    			//printf("\nIdentificador valido");
					}else{
						flag=false;
						break;
					}
				}
				
			}
		}
	}
    return flag;
}







