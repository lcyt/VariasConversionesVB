/*
 Bueno compañeros aqui os dejo el ejercicio del desglose en C. En C es mas dificil sacar la parte entera
 del sueldo, ya que se tiene que declarar como double al no existir el tipo moneda como en visual basic.
 Por ello se da problemas de precision.Para solventar este problema he tratado el sueldo como un puntero 
 a un string, y con la ayuda de la funcion strtok localizo la posicion donde se encuentra la "," o "."
 y puedo partir esta cadena en dos, separando de esta forma la parte entera de la parte decimal.
 El problema surge que no se puede trasformar el puntero de string (parte entera y decimal) mediante la 
 funcion conocida como atoi, ya que se interpreta como codigo ascill, para ello encontre
 por internet el algoritmo que vereis mas abajo. Nada mas, Saludos!!! y que paseis buen verano
 yo es que me aburria mucho y por eso lo he echo jajaja
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// declaramos variables e inicializamos las mismas
char rep;
int correcto=-1;
char nombre[40];
char sueldo [10];
char *entero;
char *decimal;
int enteros;
int decimales;
int max;
int i;
int a,b,c,d,e;
int tam;
int digito;
int billete500=0,billete200=0,billete100=0,billete50=0,billete20=0,billete10=0,billete5=0;
int monedas2=0,monedas1=0,monedas50=0,monedas20=0,monedas10=0,monedas5=0;
int monedas2c=0,monedas1c=0;  
int centinela=1;
int main(){  
    while (centinela==1){ // bucle que se ejecuta siempre que se quiere hacer un nuevo desglose
        correcto=-1;
        while (correcto==-1){ // bucle que se realiza mientras los datos no son correctos
            // inicio de variables
            billete500=0,billete200=0,billete100=0,billete50=0,billete20=0,billete10=0,billete5=0;
            monedas2=0,monedas1=0,monedas50=0,monedas20=0,monedas10=0,monedas5=0;
            monedas2c=0,monedas1c=0;
            max=0;
            a=0,b=0,c=0,d=0,e=0;
            // introduce nombre del trabajador
            printf( "Introduce el nombre del trabajador..." ); 
            scanf( "%s", &nombre ); 
            //introduce el sueldo del mismo
            printf( "Introduce el sueldo del trabajador en formato  xxxx.yy..." ); 
            scanf( "%s", &sueldo );
            // introduce el billete mas alto en el desglose
            printf( "Introduce el billete mas alto que desea.." ); 
            scanf( "%i", &max );
            // se guarda en el buffer de entero de tipo char, desde el principio hasta una "," o "."
            entero = strtok(sueldo,",""." );
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
                    a=-1; // variable de control
                }
                else{
                    a=1; // variable de control
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
                if (digito>48){
                    // si dicho codigo es mayor de 48, significa que no es numero sino letra o otro caracter especial
                    printf("el numero introducido no es correcto (no introduzca letras,solo numeros)\n");
                    b=-1; // variable de control
                }
                else{
                    b=1; // variable de control
               }
                decimales += digito * pow(10.0, tam - i);
            }
            if (decimales>=100){ // si es mayor que 100, significa que se ha introducido mas de dos decimales, cosa que no esta permitida
                printf("el numero introducido no es correcto (solo esta permitido dos decimales)\n");
                c=-1; // variable de control
            }
            else{
                c=1; // variable de control
            }
            // si se mete un biellete como maximo que no esta contemplado, tiene que dar error
            if ((max!=500) &&(max!=200) &&(max!=100) &&(max!=50) && (max!=20) &&( max!=10) && (max!=5)  && (max!=2) &&( max!=1)){
                printf("El billete utilizado como maximo no es correcto (500,200,100,50,20,10,5,2,1)\n");
                d=-1; // variable de control
            }
            else{
                d=1; // variable de control
            }
            if ((a!=-1)&&(b!=-1)&&(c!=-1)&&(d!=-1)){    // if para poder chequear las variables de control
                 correcto=1;
            }
            else{
                correcto=-1;
            }
        }
        // comienza el calculo del desglose, se comienza por la parte enetera
        if (max==500){
            // se calcula el numero de billetes
            billete500=enteros/500; 
            // se calcula el resto
            enteros=enteros -(billete500*500);
            // se establece el nuevo maximo
            max=200;
        }
        if (max==200){
              // se calcula el numero de billetes
            billete200=enteros/200;
            // se calcula el resto
            enteros=enteros -(billete200*200);
            // se establece el nuevo maximo
            max=100;
        }
        if (max==100){
            // se calcula el numero de billetes
            billete100=enteros/100;
            // se calcula el resto
            enteros=enteros -(billete100*100);
            // se establece el nuevo maximo
            max=50;
        }
        if (max==50){
            // se calcula el numero de billetes
            billete50=enteros/50;
            // se calcula el resto
            enteros=enteros -(billete50*50);
            // se establece el nuevo maximo
            max=20;
        }
        if (max==20){
            // se calcula el numero de billetes
            billete20=enteros/20;
            // se calcula el resto
            enteros=enteros -(billete20*20);
            // se establece el nuevo maximo
            max=10;
        }
        if (max==10){
            // se calcula el numero de billetes
            billete10=enteros/10;
            // se calcula el resto
            enteros=enteros -(billete10*10);
            // se establece el nuevo maximo
            max=5;
        }
        if (max==5){
            // se calcula el numero de billetes
            billete5=enteros/5;
            // se calcula el resto
            enteros=enteros -(billete5*5);
            // se establece el nuevo maximo
            max=2;
        }
        if (max==2){
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
        printf("El trabajador %s , el desglose de su sueldo es\n",nombre);
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
        getchar();
        // preguntamos si se desea realizar un nuevo desglose
        while (1){
            printf( "\nDesea calcular otro desglose (s/n)... " ); 
            scanf( "%c", &rep );
            if (rep=='s'|| rep=='S'){
                centinela== 1;
                break;
            }
            if (rep=='n'|| rep=='N'){
                centinela=-1;
                break;
            }
            else{
                printf( "La respuesta no es correcta (S/N)\n " );
                getchar();
     
            }
        }
    }
    printf( "FIN DE PROGRAMA\n " );
} 

