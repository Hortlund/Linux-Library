#include <stdio.h>
#include <stdlib.h>

#include "libresistance.h"
//include the rest of the header files for the functions we are creating 


int main(int argc, char *argv[]){

	//Variables for libresistance
	int count;
	float *array;
	char conn;
	

	//printf("Ange spänningskälla i V: ");
	printf("Ange koppling[S | P]: ");
	scanf("%c", &conn);
	while(conn != 'S' && conn != 'P'){
		getchar();
		printf("Ange S eller P: ");
		scanf("%c", &conn);
	}
        scanf("%c", &conn);
	printf("Antal komponenter: ");
	scanf("%d", &count);
	array = (float *)malloc(sizeof(count));
	for(int i = 0; i < count; i++){
		printf("komponent %d i ohm: ", i + 1);
		scanf("%f", &array[i]);
	}

	printf("%0.2f",calc_resistance(count, conn, array));
	/*	
	for(int i = 0; i < count; i++){
                printf("%0.2f", array[i]);
        }
	*/


}	
