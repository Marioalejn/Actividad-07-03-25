#include <stdio.h>
#include <string.h>
    struct user{
	    float cantidad[3]; //cantidad es el dinero inicial que se estará manipulando
	    char nip[5];
	}usuario[1]; //Solo 1 porque tenemos solo 1 usuario por el momento
	    
    void consultar_saldo(float *cantidad, int *verificador,int n){ //Se pasa *verificador para que solo lo tenga que hacer una vez
        if(*verificador == 0){
            verificacion_nip(usuario[0].nip,verificador); //Como tenemos *verificador, usamos " " en vez de "&" para mandar la dirección de la variable, no del puntero
        }
        if(*verificador == 1){
        printf("Su saldo es: %.2f\n", *cantidad);
        }
    }
    
	void depositar(float *cantidad, int *verificador, int n){
	    if(*verificador == 0){
            verificacion_nip(usuario[0].nip,verificador);
        }

        if(*verificador == 1){
    		float saldo;
    		printf("Ingresa la cantidad a depositar: ");
    		scanf("%f", &saldo);
    		if(saldo > 0){
    			*cantidad += saldo;
    			printf("Deposito correcto\n");
    		}
    		else{
    			printf("Ingresa un valor positivo\n");
    		}
        }
	}
	
	void retirar(float *cantidad, int *verificador, int n){
	    if(*verificador == 0){
            verificacion_nip(usuario[0].nip,verificador);
        }
        
        if(*verificador == 1){
    	    float retiro;
    	    printf("Ingresa la cantidad que quieres retirar: ");
    	    scanf("%f", &retiro);
    	    if(retiro <= *cantidad){
    	    	printf("%f", *cantidad);
    	        *cantidad -= retiro;
    	        printf("Retiro realizado con exito.\n");
    	        printf("%f", *cantidad);
    	    }
    	    else{
    	        printf("Vuelve a intentarlo con una cantidad menor o igual a tu salario (%.2f)\n", usuario[0].cantidad[n]);
    	    }
        }
	}
	
	void verificacion_nip(char nip[5], int *verificador){
	    int contador_nip = 3; //Veces que va a verificar al NIP
	    char nip2[5];
	    
	    do{
    	    printf("Ingresa tu NIP: \n");
    	    scanf("%4s", nip2); //A los arreglos no se les pone & en scanf
    	    while (getchar() != '\n');
    	    
    	    if(strcmp(usuario[0].nip, nip2) == 0){
    	        *verificador = 1;
    	    }
    	    else{
    	        contador_nip--;
    	        printf("NIP incorrecto (%i intentos restantes)\n", contador_nip);
    	    }
	    }while(contador_nip > 0 && *verificador == 0);//El verificador para que cuando sea correcto ya salga
	    
	    if(contador_nip == 0 && *verificador == 0){
	        printf("Intenta de nuevo cuando sepas tu contraseña...\n");
	    }
	}
	
	void guardar_saldo() {
        FILE *archivo = fopen("saldo.txt", "w");
        if (archivo) {
            fprintf(archivo, "%.2f %.2f %.2f", usuario[0].cantidad[0], usuario[0].cantidad[1], usuario[0].cantidad[2]);
            fclose(archivo);
        } 
        else {
            printf("Error al guardar el saldo.\n");
        }
    }

    void cargar_saldo() {
        FILE *archivo = fopen("saldo.txt", "r");
        if (archivo) {
            if (fscanf(archivo, "%f %f %f", &usuario[0].cantidad[0], &usuario[0].cantidad[1], &usuario[0].cantidad[2]) != 3) {
                usuario[0].cantidad[0] = 1000;
                usuario[0].cantidad[1] = 1000;
                usuario[0].cantidad[2] = 1000;
            }
            fclose(archivo);
        } 
        else {
            usuario[0].cantidad[0] = 1000;
            usuario[0].cantidad[1] = 1000;
            usuario[0].cantidad[2] = 1000;
        }
    }
    
    void limpiar() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Linux y macOS
    #endif
}
