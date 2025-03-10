#include "atm.h"

int main(){
	int n,u;
	limpiar();
	printf("Ingresa el usuario que quieres usar (1-3): ");//u de usuario
	scanf("%i", &u);
	u--;
	while (getchar() != '\n');
	printf("Ingresa la cuenta que quieres usar (1-3): ");
	scanf("%i", &n);
	n--; //para que se pueda usar en los arreglos 
	
	int opcion, verificador = 0; //Verificador es para el NIP, si es correcto se cambia a 1.
	cargar_saldo(&usuario[u].cantidad[n], n); //función que toma del txt para cambiar el valor de cantidad
	
	
	printf("Ingresa tu NIP (solo se leerán 4 caracteres): ");
	scanf("%4s", usuario[u].nip);
	while (getchar() != '\n'); // Limpiar el búfer



	do{
		printf("\n---Cajero automatico---\n");
		printf("1) Consultar saldo.\n");
		printf("2) Depositar dinero.\n");
		printf("3) Retirar dinero.\n");
		printf("4) Salir del programa.\n");
		scanf("%d", &opcion);
		
		switch (opcion){
		case 1 : 
			 consultar_saldo(&usuario[u].cantidad[n], &verificador, n, u);
			 break;
		case 2: 
			depositar(&usuario[u].cantidad[n], &verificador, n, u);
			break;
		case 3: 
			retirar(&usuario[u].cantidad[n], &verificador, n, u);
			break;
		case 4:
		    printf("Saliendo del programa... ¡Gracias por su confianza!\n");
		    //guardar_saldo(&usuario[u].cantidad[n],n); //se guarde la cantidad en el txt al cerrar el archivo
		    guardar_saldo(u);
			break;
		default:
			printf("Ingresa una opcion adecuada...\n");
			break;
		}
	}while(opcion != 4);
	
		
	return 0;
}

