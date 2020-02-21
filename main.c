#include "libresistance.h"
#include "libcomponent.h"
#include "libpower.h" 


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

	//Variables for libpower
	int voltage;
	float power;

	printf("Ange spänningskälla i V: ");
	scanf("%d", &voltage);
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
	printf("Ersättningsresistans: \n%.1f ohm\n", resistance);
	free(array);

	//printf("%0.2f",calc_resistance(count, conn, array));
	/*	
	for(int i = 0; i < count; i++){
                printf("%0.2f", array[i]);
        }
	*/
	
	//Functioncall and printouts for libpower.
	power = calc_power_r(voltage, resistance);
	printf("Effekt:\n%.2f W\n", power);

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
