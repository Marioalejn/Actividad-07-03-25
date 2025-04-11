#include <stdio.h>

struct materia {
	char nombre[50];
	float calificacion;
	int creditos;
};
void modificar_promedio(struct materia *a){
	int n;
	printf("Ingresa que promedio quieres modificar: \n
	.1-Progra\n2-Calculo\n3-Fisica: ");
	scanf("%i", &n);
	n--;
	
	float dato;
	printf("Ingresa el nuevo promedio de %s: ", a[n].nombre);
	scanf("%f", &dato);
	a[n].calificacion = dato;
	float promedio = (a[0].calificacion + a[1].calificacion + a[2].calificacion)/3;
	printf("Nuevo calificacion %.2f, dandonos un promedio de: %.2f", a[n].calificacion, promedio);
}

int main(){
	
	struct materia segundo[3] = {
		{"Progra est", 40.8, 8},
		{"Calculo", 90.5, 8},
		{"Fisica", 76.9, 4}	
	};
	
	modificar_promedio(&segundo);

	return 0;
}
