#include <stdio.h>
#include <string.h>

struct producto{
	char nombre[50];
	float precio;
	int stock;
};

void buscar(struct producto a[50], int num_productos){
	char libro[50];
	printf("Ingresa el nombre del libro con la primera letra en mayusculas: ");
	fgets(libro, sizeof(libro), stdin);
	libro[strcspn(libro, "\n")] = '\0';


	int decision = 0,i;
	for(i=0;i<num_productos;i++){
		if (strcmp(libro, a[i].nombre)==0){
			printf("Nombre: %s\n", a[i].nombre);
			printf("Precio: %.2f\n", a[i].precio);
			printf("Stock: %i\n", a[i].stock);
			decision = 1;
		}
	}
	if (decision == 0){
		printf("No se encontro el libro en cuestion\n");
	}
}

void anadir(int *num_productos, struct producto a[50]){
	printf("Ingresa el nombre del libro: ");
	fgets(a[*num_productos].nombre , sizeof(a[*num_productos].nombre), stdin);
	a[*num_productos].nombre[strcspn(a[*num_productos].nombre, "\n")] = '\0';
	
	printf("Ingresa el precio del libro: ");
	scanf("%f", &a[*num_productos].precio);
	
	printf("Ingresa el stock del libro: ");
	scanf("%i", &a[*num_productos].stock);
	while (getchar() != '\n');  

	printf("\n\n");
	(*num_productos)++;
}

int main(){
	struct producto libros[50] = {
		{"El principito", 99.0, 100},
		{"Harry potter 1", 127.99, 78},
		{"El paradigma", 159.0, 3}
	};
	int num_productos = 3;
	buscar(libros, num_productos);
	anadir(&num_productos, libros);
	buscar(libros, num_productos);
	
}
