#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define N 200
#define false 0
#define true 1

//Funci�n para encontrar la cadena
int strcmp2(char*, char*);
int isIdentifier(char*);
char* substring(char [], int, int);
char* strcpyMV(char*);
int aux=0;
int main(){
///Variables
	FILE *archivo = NULL,*reserva = NULL;//File, uno para el programa y otro para palabras reservadas
	int i,j,rows,nReservadas,*nLine;//Contador auxiliar, lo usamos en los for y en otras cosas
	char *content;//Arreglo donde almacenaremos el contenido del archivo
	char **cntFile,**cntRes;//Matriz din�mica
	printf("Objetivo: Programa que muestre las l%cneas del c%cdigo que contengan palabras reservadas\n",161,162);
	
	
	
///Archivo del programa
	archivo = fopen("Programa.txt","r");//Abrimos el archivo
	if(archivo==NULL){//En caso de que haya error
    	printf("No se puede abrir el fichero. \n");
    	exit(1);
	}
	rewind(archivo);//Regresamos el cursor al inicio del archivo
	content = (char*)malloc(N*sizeof(char));//Asignamos el tama�o al arreglo
	//Ahora recuperamos el contenido en nuestro arreglo
	i=0;
	printf("\t***Archivo con el programa original***\n-----------------------------------------------\n");
	while (feof(archivo) == 0){
 		fgets(content,N*sizeof(char),archivo);
 		i++;//Por cada linea incrementamos el contador
 		printf("%s",content);
 	}
 	//Asignamos tama�o a nuestra matriz, con el n�mero de filas
 	i--;
 	cntFile = (char**)malloc(i*sizeof(char*));
 	if(cntFile==NULL)
 		exit(1);
	rewind(archivo);//Regresamos el cursor al inicio del archivo
 	//Asginamos el tama�o a cada fila
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
 	//Asginamos el tama�o a cada fila
 	i=0;
 	while (feof(archivo) == 0){
 		fgets(content,N*sizeof(char),archivo);
 		//Asignamos el contenido
 		strcpy(cntFile[i],content);
 		//strcat(cntFile[i],""+'\0');
 		i++;//Por cada linea incrementamos el contador, termina con el valor de las filas
 	}
 	rows=i;//Guardamos el n�mero de filas
	//Cerramos archivo
	fclose(archivo);
	
	
	
///Match con identificadores
	///Imprimimos las l�neas con identificadores
	printf("\n\t***Lineas con identificadores***\n-----------------------------------------------\n");
	for(i=0;i<rows;i++) 
		if(isIdentifier(cntFile[i])==true) {
			printf("%s",cntFile[i]);
		}
	///Liberamos memoria din�mica
	free(content);
	free(cntFile);
	return 0;
}
int strcmp2(char* cadena, char* palabra){//Devuelve -1 si la cadena no se encuentra
    int i, j = 0;
    for(i=0;i<strlen(cadena);i++){
        if(palabra[j] == cadena[i]){
            ++j;
            if(j == strlen(palabra))
                return (2 + i - j);
        }
        else j = 0;
    }
    return -1;
}
int isDec(char* cadena){//Eval�a si es una declaraci�n, devuelve -1 si no lo es
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
int isIdentifier(char* cad){//Eval�a si es o no un identificador
	char cadena[N];
	aux++;
    int i,flag=false,tam=strlen(cad)-1;
    //Copiamos la cadena
    for(i=0;i<tam;i++){
    	cadena[i]=cad[i];
	}
	cadena[tam]='\0';
	//printf("%s\n",cadena);
    if(tam<=3){//Omitimos
    	/*for(i=0;i<tam;i++)
    		printf("�%c",cadena[i]);
    	printf("\n");*/
		flag=false;
	}else{
		if(isDec(cadena)!=-1){//Si tiene el tipo de dato como char, int, etc.
	    	i=isDec(cadena)+1;//Empezar�a en el espacio despues de la palabra ejemplo char 
	    	////////////////////////////////////////////////////////////////////////////?
	    	if( (tolower(cadena[i])>='a' && tolower(cadena[i])<='z') || cadena[i]=='_' ){
	    		//printf("\nEmpieza bien");
	    		flag = true;
		    	for(;i<tam-1;i++){
		    		if( (tolower(cadena[i])>='a' && tolower(cadena[i])<='z') || cadena[i]=='_' || (tolower(cadena[i])>='0' && tolower(cadena[i])<='9')){
						
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
char* substring(char s[],int p, int l) {
   	char *sub;
	sub = (char*)malloc(N*sizeof(char));//Asignamos el tama�o al arreglo
   	int c = 0;
   
   	while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   	}
   	sub[c] = '\0';
   	return sub;
}





