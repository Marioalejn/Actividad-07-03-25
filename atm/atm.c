#include "atm1.h"

int main(){
	int n = 1,u = 1,opcion, verificador = 0; //Verificador es para el NIP, si es correcto se cambia a 1.;
	llenar_datos();
	limpiar();
	usuario_seleccion(&u);
	cuenta_seleccion(&n);
	cargar_saldo(); //función que toma del txt para cambiar el valor de cantidad
	nip_seleccion(usuario[u].nip);
	
	

	do{
		printf("\n");
        printf("=================================\n");
        printf("|   \033[1;34m Usuario: %i\033[0m  \033[1;37m│\033[0m  \033[1;36mCuenta: %i\033[0m  |\n", u+1, n+1);
        printf("=================================\n");
        printf("|     \033[1;32m  CAJERO AUTOMÁTICO \033[0m     |\n");
        printf("=================================\n");
        printf("|  [1]  Consultar saldo        |\n");
        printf("|  [2]  Depositar dinero       |\n");
        printf("|  [3]  Retirar dinero         |\n");
        printf("|  [4]  Salir                  |\n");
        printf("=================================\n");
        printf("Seleccione una opción: ");
		scanf("%d", &opcion);
		limpiar();
		
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

