/*Generating random numbers*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LENGTH 100

int generateRandom(int start, int end);
double generateDRand(double start, double end);

int main(int argc, char *argv[]){
	int arrayRandom[ARR_LENGTH], i;
	float arrRand[ARR_LENGTH];

	srand(time(NULL));

	printf("Imprimiendo números aleatorios:\n");
	
	for(i = 0; i < ARR_LENGTH; i++){
		arrayRandom[i] = generateRandom(-50, 50);
		printf("arrayRandom[%d] = %d\n", i, arrayRandom[i]);
	}
	
	printf("Imprimiendo aleatorios con decimales:\n");
	for(i = 0; i < ARR_LENGTH; i++){
                arrRand[i] = generateRandom(10, 100);
                printf("arrRand[%d] = %f\n", i, arrRand[i]);
        }

	return 0;
}

int generateRandom(int start, int end){
	return rand() % (end-start+1) + start;
}

double generateDRand(double start, double end){
	return drand48() * (end-start) + end;
}
