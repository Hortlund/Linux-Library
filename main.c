#include "libresistance.h"
//include the rest of the header files for the functions we are creating 


int main(int argc, char *argv[]){

	//Variables for libresistance
	int count;
	float *array;
	char conn;

	float resistance;
	

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

	return 0;
}	
