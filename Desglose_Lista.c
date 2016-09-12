#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
//#include <malloc.h>
struct _desglose {
    char nombre[100];
    char apellido1[100];
    char apellido2[100];
    char sueldo[10];
    int dni;
    int max;
    struct _desglose *siguiente;
};
 
struct _desglose *primero, *ultimo;
char nombre[100];
char apellido1[100];
char apellido2[100];
char sueldo [10];
char correcto;
char otro;
char *entero;
char *decimal;
int enteros;
int decimales;
int tam;
int digito;
int rep;
int max;
int dni;
char var [8];
int dnib=48420975;
int maxb;
int variable=48420975;
char nombreb[100];
char apellido1b[100];
char apellido2b[100];
char sueldob[10];
int centinela=1;
int billete500=0,billete200=0,billete100=0,billete50=0,billete20=0,billete10=0,billete5=0;
int monedas2=0,monedas1=0,monedas50=0,monedas20=0,monedas10=0,monedas5=0;
int monedas2c=0,monedas1c=0;
int billete500T=0,billete200T=0,billete100T=0,billete50T=0,billete20T=0,billete10T=0,billete5T=0;
int monedas2T=0,monedas1T=0,monedas50T=0,monedas20T=0,monedas10T=0,monedas5T=0;
int monedas2cT=0,monedas1cT=0;
void Nuevo_trabajador(){
    centinela=1;
        while (centinela==1){
        // introduce nombre del trabajador
        printf( "Introduce el nombre del trabajador..." ); 
        fflush(stdin);
        scanf( "%s", &nombre ); 
    //    fflush(stdin);
        // introduce primer apellido del trabajador
        printf( "Introduce el primer apellido del trabajador..." ); 
        fflush(stdin);
        scanf( "%s", &apellido1);
      //  fflush(stdin);
        // introduce segundo apeellido del trabajador
        printf( "Introduce el segundo apellido del trabajador..." ); 
        fflush(stdin);
        scanf( "%s", &apellido2 );
   //     fflush(stdin);
        // introduce el dni del trabajador
        printf( "Introduce el D.N.I. del trabajador (sin letra)..." );
        fflush(stdin);
        scanf( "%i", &dni ); 
    //    fflush(stdin);
        //introduce el sueldo del mismo
        printf( "Introduce el sueldo del trabajador en formato  xxxx.yy..." );
        fflush(stdin);
        scanf( "%s", &sueldo );
    //    fflush(stdin);
        // introduce el billete mas alto en el desglose
        printf( "Introduce el billete mas alto que desea.." ); 
        fflush(stdin);
        scanf( "%i", &max );
    //    fflush(stdin);
        printf("El nombre del trabajador es...%s %s %s\n",nombre,apellido1,apellido2);
        printf("El sueldo del trabajador es...%s\n",sueldo);
        printf("El D.N.I. del trabajador es..%i\n",dni);
        printf("El Billete mas grande es %i\n",max);
        while (1){
            getchar();
            printf( "Son los datos correctos (s/n)  " ); 
            scanf( "%c", &correcto );
            if (correcto=='s'|| correcto=='S'){
                centinela=-1;
                struct _desglose *nuevo;
                /* reservamos memoria para el nuevo elemento */
                nuevo = (struct _desglose *) malloc (sizeof(struct _desglose));                
                (*nuevo->nombre) = (char *) malloc (100 * sizeof (char));
                strcpy (nuevo->nombre,nombre);
                (*nuevo->apellido1) = (char *) malloc (100 * sizeof (char));
                strcpy (nuevo->apellido1,apellido1);
                (*nuevo->apellido2) = (char *) malloc (100 * sizeof (char));
                strcpy (nuevo->apellido2,apellido2);
                (*nuevo->sueldo) = (char *) malloc (100 * sizeof (char));
                strcpy (nuevo->sueldo,sueldo);              
                nuevo->dni=dni;
                nuevo->max=max;           
                if (nuevo==NULL) printf( "No hay memoria disponible!\n");
                nuevo->siguiente = NULL; 
                /* ahora metemos el nuevo elemento en la lista. lo situamos
                al final de la lista */
                /* comprobamos si la lista está vacía. si primero==NULL es que no
                hay ningún elemento en la lista. también vale ultimo==NULL */
                if (primero==NULL) {
                    printf( "Primer elemento\n");
                    primero = nuevo;
                    ultimo = nuevo;
                }
                else {
                    /* el que hasta ahora era el último tiene que apuntar al nuevo */
                    ultimo->siguiente = nuevo;
                    /* hacemos que el nuevo sea ahora el último */
                    ultimo = nuevo;
                }
                break;
            }
            if (correcto=='n'|| correcto=='N'){
                centinela=1;
                break;
            }
            else{
                printf( "La respuesta no es correcta (S/N)\n " );
                getchar();
     
            }
        }
    }      
}

void Calcular_desglose(){
    printf( "Introduce el D.N.I. del trabajador (sin letra)..." );
    fflush(stdin);
    scanf( "%i", &dnib ); 
    struct _desglose *aux=NULL; /* lo usamos para recorrer la lista */
  
    int i; 
    i=0;
    aux = primero;
    while (aux!=NULL) {
        i++;
        if (aux->dni==dnib){
            break;
        }
        else{
            aux = aux->siguiente;
        }
    }
    if (i==0) printf( "\nLa lista está vacía!!\n" );
    entero = strtok(aux->sueldo,",""." );
    // se guarda en el buffer decimal de tipo char, desde "," o "." hasta el final
    decimal = strtok(NULL,"," ".");
    // se trasforma de tipo char, a tipo enetero
    enteros = 0;
    tam  = strlen(entero);  /* Longitud de la cadena recibida */
    digito;
    i=0;
    for (i = tam ; i > 0; --i) {
        digito = (int) (entero[i - 1] - 48);// esto es porque viene en codigo ascill
        if (digito>48){
            // si dicho codigo es mayor de 48, significa que no es numero sino letra o otro caracter especial
            printf("el numero introducido no es correcto (no introduzca letras,solo numeros)\n");
        }
        enteros += digito * pow(10.0, tam - i);
    }
    // se trasforma de tipo char, a tipo enetero
    decimales = 0;
    tam  = strlen(decimal);  /* Longitud de la cadena recibida */
    digito=0;
    i=0;
    for (i = tam ; i > 0; --i) {
        digito = (int) (decimal[i - 1] - 48);// esto es porque viene en codigo ascill
        decimales += digito * pow(10.0, tam - i);
    }
    //comienza el calculo del desglose, se comienza por la parte enetera
    if (aux->max==500){
        // se calcula el numero de billetes
        billete500=enteros/500; 
            // se calcula el resto
        enteros=enteros -(billete500*500);
        // se establece el nuevo maximo
        aux->max=200;
    }
    if (aux->max==200){
       // se calcula el numero de billetes
        billete200=enteros/200;
       // se calcula el resto
        enteros=enteros -(billete200*200);
       // se establece el nuevo maximo
        aux->max=100;
    }
    if (aux->max==100){
        // se calcula el numero de billetes
        billete100=enteros/100;
        // se calcula el resto
        enteros=enteros -(billete100*100);
        // se establece el nuevo maximo
        aux->max=50;
    }
    if (aux->max==50){
        // se calcula el numero de billetes
        billete50=enteros/50;
        // se calcula el resto
        enteros=enteros -(billete50*50);
       // se establece el nuevo maximo
        aux->max=20;
    }
    if (aux->max==20){
       // se calcula el numero de billetes
        billete20=enteros/20;
       // se calcula el resto
        enteros=enteros -(billete20*20);
       // se establece el nuevo maximo
        aux->max=10;
    }
    if (aux->max==10){
        // se calcula el numero de billetes
        billete10=enteros/10;
       // se calcula el resto
        enteros=enteros -(billete10*10);
        // se establece el nuevo maximo
        aux->max=5;
    }
    if (aux->max==5){
       // se calcula el numero de billetes
        billete5=enteros/5;
       // se calcula el resto
        enteros=enteros -(billete5*5);
       // se establece el nuevo maximo
        aux->max=2;
    }
    if (aux->max==2){
       // se calcula el numero de monedas
        monedas2=enteros/2;
       // se calcula el resto
        enteros=enteros -(monedas2*2);
      // el resto seran las monedas de 1 euro que faltan
        monedas1=enteros;
    }
  // seguimos con el desglose, ahora con la parte decimal que dara las monedas de centimos correspondientes
  // se calcula el numero de monedas
    monedas50=decimales/50;
    // se calcula el resto
    decimales=decimales -(monedas50*50);
  // se calcula el numero de monedas
    monedas20=decimales/20;
  // se calcula el resto
    decimales=decimales -(monedas20*20);
  // se calcula el numero de monedas
    monedas10=decimales/10;
 // se calcula el resto
    decimales=decimales -(monedas10*10);
  // se calcula el numero de monedas
    monedas5=decimales/5;
  // se calcula el resto
    decimales=decimales -(monedas5*5);
  // se calcula el numero de monedas
    monedas2c=decimales/2;
   // se calcula el resto
    decimales=decimales -(monedas2c*2);
   // el resto seran las monedas de 1 centimo que faltan
    monedas1c=decimales;
 // imprimimos el desglose
    printf("El trabajador %s %s %s, el desglose de su sueldo es\n",aux->nombre,aux->apellido1,aux->apellido2);
    printf("El numero billetes de 500 ..%i\n",billete500);
    printf("El numero billetes de 200 ..%i\n",billete200);
    printf("El numero billetes de 100 ..%i\n",billete100); 
    printf("El numero billetes de 50 ..%i\n",billete50); 
    printf("El numero billetes de 20 ..%i\n",billete20); 
    printf("El numero billetes de 10 ..%i\n",billete10); 
    printf("El numero billetes de 5 ..%i\n",billete5); 
    printf("El numero de monedas de 2 euros..%i\n",monedas2); 
    printf("El numero de monedas de 1 euros..%i\n",monedas1);  
    printf("El numero de monedas de 0,50 euros..%i\n",monedas50); 
    printf("El numero de monedas de 0,20 euros..%i\n",monedas20); 
    printf("El numero de monedas de 0,10 euros..%i\n",monedas10);
    printf("El numero de monedas de 0,05 euros..%i\n",monedas5); 
    printf("El numero de monedas de 0,02 euros..%i\n",monedas2c);
    printf("El numero de monedas de 0,01 euros..%i\n",monedas1c); 
 }


void Borrar_Lista(){
    struct _desglose *auxi=primero;
    struct _desglose *aux2=NULL;
	
	if(auxi==NULL){
		printf("La lista de trabajadores se encuentra vacia.\n");
	}
        else{
            while(auxi!=NULL){
            if(auxi->siguiente==NULL){
                primero=NULL;
                free(auxi->nombre);
                free(auxi->apellido1);
                free(auxi->apellido2);
                free(auxi->sueldo);
                break;
            }
            else{
                aux2=auxi->siguiente;
                free(auxi->nombre);
                free(auxi->apellido1);
                free(auxi->apellido2);
                free(auxi->sueldo);
                auxi=aux2;
                primero=aux2;
            }
        }
    }	
}

void Calcular_Desglose_Total(){
    billete500T=0,billete200T=0,billete100T=0,billete50T=0,billete20T=0,billete10T=0,billete5T=0;
    monedas2T=0,monedas1T=0,monedas50T=0,monedas20T=0,monedas10T=0,monedas5T=0;
    monedas2cT=0,monedas1cT=0;
    struct _desglose *auxiliar=NULL; /* lo usamos para recorrer la lista */  
    int j; 
    j=0;
    int i;
    auxiliar = primero;
    while (auxiliar!=NULL) {
        billete500=0,billete200=0,billete100=0,billete50=0,billete20=0,billete10=0,billete5=0;
        monedas2=0,monedas1=0,monedas50=0,monedas20=0,monedas10=0,monedas5=0;
        monedas2c=0,monedas1c=0;
        
        j++;
        entero = strtok(auxiliar->sueldo,",""." );
        // se guarda en el buffer decimal de tipo char, desde "," o "." hasta el final
        decimal = strtok(NULL,"," ".");
        // se trasforma de tipo char, a tipo enetero
        enteros = 0;
        tam  = strlen(entero);  /* Longitud de la cadena recibida */
        digito;
        i=0;
        for (i = tam ; i > 0; --i) {
            digito = (int) (entero[i - 1] - 48);// esto es porque viene en codigo ascill
            if (digito>48){
                // si dicho codigo es mayor de 48, significa que no es numero sino letra o otro caracter especial
                printf("el numero introducido no es correcto (no introduzca letras,solo numeros)\n");
            }
            enteros += digito * pow(10.0, tam - i);
        }
        // se trasforma de tipo char, a tipo enetero
        decimales = 0;
        tam  = strlen(decimal);  /* Longitud de la cadena recibida */
        digito=0;
        i=0;
        for (i = tam ; i > 0; --i) {
            digito = (int) (decimal[i - 1] - 48);// esto es porque viene en codigo ascill
            decimales += digito * pow(10.0, tam - i);
        }
        //comienza el calculo del desglose, se comienza por la parte enetera
        if (auxiliar->max==500){
            // se calcula el numero de billetes
            billete500=enteros/500; 
            // se calcula el resto
            enteros=enteros -(billete500*500);
            billete500T=billete500T+billete500;
            // se establece el nuevo maximo
            auxiliar->max=200;
        }
        if (auxiliar->max==200){
            // se calcula el numero de billetes
            billete200=enteros/200;
            // se calcula el resto
            enteros=enteros -(billete200*200);
            billete200T=billete200T+billete200;
            // se establece el nuevo maximo
            auxiliar->max=100;
        }
        if (auxiliar->max==100){
            // se calcula el numero de billetes
            billete100=enteros/100;
            // se calcula el resto
            enteros=enteros -(billete100*100);
            billete100T=billete100T+billete100;
            // se establece el nuevo maximo
            auxiliar->max=50;
        }
        if (auxiliar->max==50){
            // se calcula el numero de billetes
            billete50=enteros/50;
            // se calcula el resto
            enteros=enteros -(billete50*50);
            billete50T=billete50T+billete50;
            // se establece el nuevo maximo
            auxiliar->max=20;
        }   
        if (auxiliar->max==20){
            // se calcula el numero de billetes
            billete20=enteros/20;
            // se calcula el resto
            enteros=enteros -(billete20*20);
             billete20T=billete20T+billete20;
            // se establece el nuevo maximo
            auxiliar->max=10;
        }
        if (auxiliar->max==10){
            // se calcula el numero de billetes
            billete10=enteros/10;
            // se calcula el resto
            enteros=enteros -(billete10*10);
             billete10T=billete10T+billete10;
            // se establece el nuevo maximo
            auxiliar->max=5;
        }
        if (auxiliar->max==5){
            // se calcula el numero de billetes
            billete5=enteros/5;
            // se calcula el resto
            enteros=enteros -(billete5*5);
             billete5T=billete5T+billete5;
            // se establece el nuevo maximo
            auxiliar->max=2;
        }
        if (auxiliar->max==2){
            // se calcula el numero de monedas
            monedas2=enteros/2;
            // se calcula el resto
            enteros=enteros -(monedas2*2);
             monedas2T=monedas2T+monedas2;
            // el resto seran las monedas de 1 euro que faltan
            monedas1=enteros;
            monedas1T=monedas1T+monedas1;
        }
        // seguimos con el desglose, ahora con la parte decimal que dara las monedas de centimos correspondientes
        // se calcula el numero de monedas
        monedas50=decimales/50;
        // se calcula el resto
        decimales=decimales -(monedas50*50);
        monedas50T=monedas50T+monedas50;
        // se calcula el numero de monedas
        monedas20=decimales/20;
        // se calcula el resto
        decimales=decimales -(monedas20*20);
        monedas20T=monedas20T+monedas20;
        // se calcula el numero de monedas
        monedas10=decimales/10;
        // se calcula el resto
        decimales=decimales -(monedas10*10);
        monedas10T=monedas10T+monedas10;
        // se calcula el numero de monedas
        monedas5=decimales/5;
        // se calcula el resto
        decimales=decimales -(monedas5*5);
        monedas5T=monedas5T+monedas5;
        // se calcula el numero de monedas
        monedas2c=decimales/2;
        // se calcula el resto
        decimales=decimales -(monedas2c*2);
        monedas2cT=monedas2cT+monedas2c;
        // el resto seran las monedas de 1 centimo que faltan
        monedas1c=decimales;
        monedas1cT=monedas1cT+monedas1c;
        // imprimimos el desglose
        printf("El trabajador %s %s %s, ",auxiliar->nombre,auxiliar->apellido1,auxiliar->apellido2);
        printf("con D.N.I. %i el desglose de su sueldo es\n",auxiliar->dni);
        printf("El numero billetes de 500 ..%i\n",billete500);
        printf("El numero billetes de 200 ..%i\n",billete200);
        printf("El numero billetes de 100 ..%i\n",billete100); 
        printf("El numero billetes de 50 ..%i\n",billete50); 
        printf("El numero billetes de 20 ..%i\n",billete20); 
        printf("El numero billetes de 10 ..%i\n",billete10); 
        printf("El numero billetes de 5 ..%i\n",billete5); 
        printf("El numero de monedas de 2 euros..%i\n",monedas2); 
        printf("El numero de monedas de 1 euros..%i\n",monedas1);  
        printf("El numero de monedas de 0,50 euros..%i\n",monedas50); 
        printf("El numero de monedas de 0,20 euros..%i\n",monedas20); 
        printf("El numero de monedas de 0,10 euros..%i\n",monedas10);
        printf("El numero de monedas de 0,05 euros..%i\n",monedas5); 
        printf("El numero de monedas de 0,02 euros..%i\n",monedas2c);
        printf("El numero de monedas de 0,01 euros..%i\n",monedas1c);
        printf("*************************************************************\n");
    auxiliar = auxiliar->siguiente;
    }
    printf("El numero de billetes de 500 total ..%i\n",billete500T);
    printf("El numero de billetes de 200 total ..%i\n",billete200T);
    printf("El numero de billetes de 100 total ..%i\n",billete100T); 
    printf("El numero de billetes de 50 total ..%i\n",billete50T); 
    printf("El numero de billetes de 20 total ..%i\n",billete20T); 
    printf("El numero de billetes de 10 total ..%i\n",billete10T); 
    printf("El numero de billetes de 5 total ..%i\n",billete5T); 
    printf("El numero total de monedas de 2 euros..%i\n",monedas2T); 
    printf("El numero total de monedas de 1 euros..%i\n",monedas1T);  
    printf("El numero total de monedas de 0,50 euros..%i\n",monedas50T); 
    printf("El numero total de monedas de 0,20 euros..%i\n",monedas20T); 
    printf("El numero total de monedas de 0,10 euros..%i\n",monedas10T);
    printf("El numero total de monedas de 0,05 euros..%i\n",monedas5T); 
    printf("El numero total de monedas de 0,02 euros..%i\n",monedas2cT);
    printf("El numero total de monedas de 0,01 euros..%i\n",monedas1cT);
    if (j==0) printf( "\nLa lista está vacía!!\n" );
}

int main(){ 
    while (1){
        printf("*****************MENU DE OPCIONES****************\n");
        printf("Introduccir un nuevo trabajador (opcion 1 )\n");
        printf("Calcular el desglose de un trabajador (opcion 2 )\n");
        printf("Borrar lista de trabajadores (opcion 3 )\n");
        printf("Calcular los desgloses de todos los trabajadores (opcion 4 )\n");
        printf( "Introduzca la opcion deseada..." ); 
        scanf( "%i", &rep ); 
        switch ( rep ) {
            case 1:
                Nuevo_trabajador();
                //    printf("La opcion  es  1");
                break;
            case 2:{
                Calcular_desglose();
              //  printf(" el dni es..",dni);
                break;
            }
            case 3:
              Borrar_Lista();
     //           printf("La opcion  es 3");
                break;
            case 4:
              Calcular_Desglose_Total();
        //        printf("La opcion  es 4");
                break;
            default:
                printf("La opcion no es correcta (introduzca 1,2,3,4,)\n");
                break;
        }
     
    }
    
    
}

