#include <stdio.h>
#include <stdlib.h>

#include "libresistance.h"

float calc_resistance(int count, char conn, float *array){
	float sumOhm = 0, tempOhm = 0, divideOhm = 0;
	if(conn == 'S'){
		for(int i = 0; i < count; i++){
			sumOhm += array[i];
		}
	}
	else{
		for(int i = 0; i < count; i++){
			tempOhm += (1 / array[i]);
		}
		divideOhm = 1 / tempOhm;
		sumOhm = divideOhm;
	}
	return sumOhm;


}
