#include "libresistance.h"
#include "libe_resistance.h"
//include the rest of the header files for the functions we are creating 


int main(int argc, char *argv[]){

	//Variables for libresistance
	int count;
	float *array;
	char conn;

<<<<<<< HEAD
	//Variables for e_resistance
	float array[3] = {1.0, 1.0, 1.0};
	float *arraypek = array;
	int raknare = 0;
=======
	float resistance;
	
>>>>>>> 89f95470478bef6e7a8e352080b836a00f460954

	//printf("Ange spänningskälla i V: ");
	printf("Ange koppling[S | P]: ");
	scanf("%c", &conn);
	while(conn != 'S' && conn != 'P'){
		getchar();
		printf("Ange S eller P: ");
		scanf("%c", &conn);
	}
	printf("Antal komponenter: ");
	scanf("%d", &count);
	array = (float *)malloc(sizeof(count));
	for(int i = 0; i < count; i++){
		printf("komponent %d i ohm: ", i + 1);
		scanf("%f", &array[i]);
	}
	resistance = calc_resistance(count, conn, array);
	printf("Ersättningsresistans: %0.f ohm\n", resistance);
	free(array);

<<<<<<< HEAD
	printf("%0.2f",calc_resistance(count, conn, array));
	/*	
	for(int i = 0; i < count; i++){
                printf("%0.2f", array[i]);
        }
	*/
	
	//Funktioncall and printouts of e_resistance.
	/*int count = e_resistance(ERSATTNINGSRESISTANS, arraypek);
	printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
	while(raknare<count){
		printf("%.2f" ", ", array[i]);
		ŕaknare++;
	}
	raknare = 0;*/


=======
	return 0;
>>>>>>> 89f95470478bef6e7a8e352080b836a00f460954
}	
