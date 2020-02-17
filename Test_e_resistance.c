#include <stdio.h>
#include <stdlib.h>

float E_serie[12]={0.1, 0.12, 0.15, 0.18, 0.22, 0.27, 0.33, 0.39, 0.47, 0.56, 0.68, 0.82};

int e_resistance(float orig_resistance, float *res_array){
	int count = 0;
	float resistans = orig_resistance;
	float counter=10000000000.0;
	float *Pek = E_serie;
	int i = 0;
	while(counter > 0.1){
		counter = counter*0.1;
		for (i=11; i>-1; i--){
			if(resistans >= Pek[i]*counter){
				res_array[0] = Pek[i]*counter;
				break;
			}
		}
		if(res_array[0] == Pek[i]*counter){
			break;
		}
	
	}
	if(res_array[0] == orig_resistance){
		return 1;
	}
	else{
		counter = 10000000000.0;
		resistans = orig_resistance - res_array[0];
		while(counter > 0.1){
			counter = counter*0.1;
			for (i=11; i>-1; i--){
				if(resistans >= Pek[i]*counter){
					res_array[1] = Pek[i]*counter;
					break;
				}
			}
			if(res_array[1] == Pek[i]*counter){
				break;
			}
		}
		count = 2;
	}
	if(res_array[0]+res_array[1] == orig_resistance){
		return 2;
	}
	else{
		counter = 10000000000.0;
		resistans = resistans - res_array[1];
		while(counter > 0.1){
			counter = counter*0.1;
			for (i=11; i>-1; i--){
				if(resistans >= Pek[i]*counter){
					res_array[2] = Pek[i]*counter;
					break;
				}
			}
			if(res_array[2] == Pek[i]*counter){
				break;
			}
		}
		count = 3;
	}
return count;
}

int main() {
	float array[3]={1.0, 1.0 , 1.0};
	float *arraypek=array;
	float resistance = 1398.0;
	int i = 0;
	int count = e_resistance(resistance, arraypek);	
	
	printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
	while(i<count){
		printf("%.2f" ", ", array[i]);
		i++;
	}
	
return 0;
}
