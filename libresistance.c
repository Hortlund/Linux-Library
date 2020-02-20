#include "libresistance.h"

float calc_resistance(int count, char conn, float *array){
	float sumOhm = 0, tempOhm = 0, divideOhm = 0;

	if(conn == 'S'){
		for(int i = 0; i < count; i++){
			sumOhm += array[i];
		}
		return sumOhm;
	}
	else if(conn == 'P'){
		for(int i = 0; i < count; i++){
			tempOhm += (1 / array[i]);
		}
		divideOhm = 1 / tempOhm;
		sumOhm = divideOhm;
		return sumOhm;
	}
	if(!isdigit(count)){ 
                return -1;
        }
        else if(!isalpha(conn)){
                return -1;
        }
        else if(conn != 'S' && conn != 'P'){
                return -1;
        }
	return 0;
}
