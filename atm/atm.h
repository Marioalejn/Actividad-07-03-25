#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    struct user{
	    float cantidad[3]; //cantidad es el dinero inicial que se estará manipulando
	    char nip[5];
        int NoCliente;
        char nombre[40];
	}usuario[3]; //Solo 1 porque tenemos solo 1 usuario por el momento

    void limpiar() {
        #ifdef _WIN32
            system("cls");  // Windows
        #else
            system("clear");  // Linux y macOS
        #endif
    }

    void usuario_seleccion(int *u){
        do{
            printf("Ingresa el usuario que quieres usar (1-3): ");//u de usuario
            scanf("%i", u);
            while (getchar() != '\n');
            
        }while(!(*u <= 3 && *u >=1));
        (*u)--;
        limpiar();
    }

    void cuenta_seleccion(int *n){
        do{
            printf("Ingresa la cuenta que quieres usar (1-3): ");
            scanf("%i", n);
            while (getchar() != '\n');
        }while(!(*n <= 3 && *n >=1));
        (*n)--; //para que se pueda usar en los arreglos 
        limpiar();
    }

    void nip_seleccion(char nip[5]){
        printf("Ingresa tu NIP (solo se leerán 4 caracteres): ");
        scanf("%4s", nip);
        while (getchar() != '\n'); // Limpiar el búfer
        limpiar();
        /*printf("Ingresa tu NIP (solo se leerán 4 caracteres): ");
        scanf("%4s", usuario[*u].nip);
        while (getchar() != '\n'); // Limpiar el búfer
        limpiar();*/
    }

    void verificacion_nip(char nip[5], int *verificador){
	    int contador_nip = 3; //Veces que va a verificar al NIP
	    char nip2[5];
	    
	    do{
    	    printf("Ingresa tu NIP: ");
    	    scanf("%4s", nip2); //A los arreglos no se les pone & en scanf
    	    while (getchar() != '\n');
    	    
    	    if(strcmp(nip, nip2) == 0){
    	        *verificador = 1;
    	        printf("\033[1;32mNIP correcto\033[0m\n");
    	        printf("---------------------------------\n");
    	    }
    	    else{
    	        contador_nip--;
    	        printf("\033[1;31mNIP incorrecto (%i intentos restantes)\033[0m\n", contador_nip);
    	    }
	    }while(contador_nip > 0 && *verificador == 0);//El verificador para que cuando sea correcto ya salga
	    
	    if(contador_nip == 0 && *verificador == 0){
	        printf("\033[1;31mIntenta de nuevo cuando sepas tu contraseña...\033[0m\n");
	    }
	}
	    
    void consultar_saldo(float *cantidad, int *verificador,int n, int u){ //Se pasa *verificador para que solo lo tenga que hacer una vez
        if(*verificador == 0){
            verificacion_nip(usuario[u].nip,verificador); //Como tenemos *verificador, usamos " " en vez de "&" para mandar la dirección de la variable, no del puntero
        }
        if(*verificador == 1){
        printf("Su saldo es: \033[1;32m%.2f\n\033[0m", *cantidad);
        }
    }
    
	void depositar(float *cantidad, int *verificador, int n, int u){
	    if(*verificador == 0){
            verificacion_nip(usuario[u].nip,verificador);
        }

        if(*verificador == 1){
    		float saldo;
    		printf("Ingresa la cantidad a depositar: ");
    		scanf("%f", &saldo);
    		if(saldo > 0){
    			*cantidad += saldo;
    			printf("\033[1;32mDeposito correcto\033[0m\n");
    		}
    		else{
    			printf("\033[1;31mIngresa un valor positivo\033[0m\n");
    		}
        }
	}
	
	void retirar(float *cantidad, int *verificador, int n, int u){
	    if(*verificador == 0){
            verificacion_nip(usuario[u].nip,verificador);
        }
        
        if(*verificador == 1){
    	    float retiro;
    	    printf("Ingresa la cantidad que quieres retirar: ");
    	    scanf("%f", &retiro);
    	    if(retiro <= *cantidad){
    	    	//printf("%f", *cantidad);
    	        *cantidad -= retiro;
    	        printf("\033[1;32mRetiro realizado con exito.\033[0m\n");
    	        //printf("%f\n", *cantidad);
    	    }
    	    else{
    	        printf("mVuelve a intentarlo con una cantidad menor o igual a tu salario (\033[1;31m%.2f\033[0m)\n", usuario[0].cantidad[n]);
    	    }
        }
	}
	
	
	void guardar_saldo(int u) {
	    int i;
        FILE *archivo = fopen("saldo.txt", "w");
        if (archivo) {
            for(i=0;i<3;i++){
                fprintf(archivo, "%.2f %.2f %.2f ", usuario[i].cantidad[0], usuario[i].cantidad[1], usuario[i].cantidad[2]);
            }
            fclose(archivo);
            
        } 
        else {
            printf("\033[1;31mError al guardar el saldo.\033[0m\n");
        }
    }

    void cargar_saldo() {
        FILE *archivo = fopen("saldo.txt", "r");
        if (archivo) {
            if (fscanf(archivo, "%f %f %f %f %f %f %f %f %f", &usuario[0].cantidad[0], &usuario[0].cantidad[1], &usuario[0].cantidad[2], &usuario[1].cantidad[0], &usuario[1].cantidad[1], &usuario[1].cantidad[2], &usuario[2].cantidad[0], &usuario[2].cantidad[1], &usuario[2].cantidad[2]) != 9) {
                usuario[0].cantidad[0] = 1000;
                usuario[0].cantidad[1] = 1000;
                usuario[0].cantidad[2] = 900;
                usuario[1].cantidad[0] = 900;
                usuario[1].cantidad[1] = 900;
                usuario[1].cantidad[2] = 900;
                usuario[2].cantidad[0] = 800;
                usuario[2].cantidad[1] = 800;
                usuario[2].cantidad[2] = 800;
            }
            fclose(archivo);
        } 
        else {
            usuario[0].cantidad[0] = 1000;
            usuario[0].cantidad[1] = 1000;
            usuario[0].cantidad[2] = 900;
            usuario[1].cantidad[0] = 900;
            usuario[1].cantidad[1] = 900;
            usuario[1].cantidad[2] = 900;
            usuario[2].cantidad[0] = 800;
            usuario[2].cantidad[1] = 800;
            usuario[2].cantidad[2] = 800;
        }
    }
    
    void llenar_datos() {
        // Usuarios
        strcpy(usuario[0].nombre, "Guadalupe sin_apellido");
        usuario[0].NoCliente = 1;
 
        strcpy(usuario[1].nombre, "Jose torres");
        usuario[1].NoCliente = 2;

        strcpy(usuario[2].nombre, "Juan Martinez");
        usuario[2].NoCliente = 3;
    }
