#include "libresistance.h"
#include "libe_resistance.h"
//include the rest of the header files for the functions we are creating 


int main(int argc, char *argv[]){

	//Variables for libresistance
	int count;
	float *array;
	char conn;

	//Variables for e_resistance
	float arrayE[3] = {1.0, 1.0, 1.0};
	float *arraypek = arrayE;
	int raknare = 0;

	float resistance;

	//printf("Ange spänningskälla i V: ");
	printf("Ange koppling[S | P]: ");
	scanf(" %c", &conn);
	printf("Antal komponenter: ");
	scanf("%d", &count);
	array = (float *)malloc(sizeof(count));
	for(int i = 0; i < count; i++){
		printf("komponent %d i ohm: ", i + 1);
		scanf("%f", &array[i]);
	}
	resistance = calc_resistance(count, conn, array);
	printf("Ersättningsresistans: \n%.0f ohm\n", resistance);
	free(array);

	//printf("%0.2f",calc_resistance(count, conn, array));
	/*	
	for(int i = 0; i < count; i++){
                printf("%0.2f", array[i]);
        }
	*/
	
	//Funktioncall and printouts of e_resistance.
	
	count = e_resistance(resistance, arraypek);
	printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");
	while(raknare<count){
		printf("%.0f\n", arrayE[raknare]);
		raknare++;
	}
	raknare = 0;

	return 0;
}	
