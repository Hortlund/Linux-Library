#include "libresistance.h"

float calc_resistance(int count, char conn, float *array){
	float sumOhm = 0, tempOhm = 0, divideOhm = 0;

	if(array != NULL){
		if(conn != 'S' && conn != 'P'){
        	        return -1;
        	}
		if(conn == 'S'){
			for(int i = 0; i < count; i++){
				sumOhm += array[i];
			}
			return sumOhm;
		}
		else if(conn == 'P'){
			for(int i = 0; i < count; i++){
				if(array[i]!=0)
					tempOhm += (1 / array[i]);
				else
					return 0
			}
			divideOhm = 1 / tempOhm;
			sumOhm = divideOhm;
			return sumOhm;
		}
	}	
		return 0;
}
