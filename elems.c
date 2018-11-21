/*Elems, por Juan Ureña.
El programa recibe una lista de parámetros,
intentará sacar la variable de entorno de cada
parámetro. El resultado de cada una se imprimirá,
separando cada valor (valores separados por los
dos puntos). En el caso de que se pase un 
parámetro que no es varible de entorno, el 
programa acabará con error mostrando un warning*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>

/*Definimos elemento para trozear*/
 
char Corte[]=":";

enum{
Inicio=1
};

/*Recibira una cadena y mostrará subcadenas
cortando por el elemento indicado*/
void
write_sentence(char *sentence)
{
    char* token;
	while ((token = strtok_r(sentence, Corte, &sentence))) {
        printf("%s\n", token);
	}
}

int
main(int argc, char *argv[])
{
char *word;

/*Bucle para recorrer todos los argumentos,
sacando el valor de estaas*/
	for(int x=Inicio; x<argc; x++){ 
		word=getenv(argv[x]);
		if (word){
		
			write_sentence(word);
		}else{
		
			warnx("%s%s%s", "ERROR: var '",argv[x], "' does not exist");
			exit(EXIT_FAILURE);
		}
		
	}
/*No debemos liberar la memoria, ya que apunta
nuestro puntero a una informacion de las variables 
de entorno del ordernador, ajenos a nuestro
programa. Y segun lla documentacion no se debe 
modificar. Si borramos la memoria, borrariamo el 
contenido de la variable de entorno*/
	exit(EXIT_SUCCESS);
}
