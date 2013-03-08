//friendly.c
//Friendly Numbers program

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUBOUND 10000

int *divisors(int x){
  int *ds = (int *) calloc (x,sizeof(int));
	int dc = 0;
	for (int i = 1; i <= x; ++i) {
		if(x % i == 0){
			ds[dc++] = i;
		}
	}
	return ds;
}

int numdivisors(int x){
	int dc = 0;
	for (int i = 1; i <= x; ++i) {
		if(x % i == 0){
			dc++;
		}
	}
	return dc;
}

int dsum (int *xs, int size){
	int result = 0;
	for(int i=0; i < size; ++i){
		result += xs[i];
	}
	return result;
}

float abundancy(int x){
	float dasum = (float)dsum(divisors(x),numdivisors(x));
    float xf = (float)x;
	float result = dasum / xf;
	return result;
}

bool aref(int a, int b){
	return abundancy(a) == abundancy(b);
}

int *smaller_friends(int x){
	int *friends = (int *) calloc (x,sizeof(int));
	int index=0;
	for(int i=1; i<x; ++i){
		if(aref(i,x)){
			friends[index++] = i;
		}
	}
	return friends;
}

int *matching(float a, int ub){
	int *matches = (int *) calloc (ub+1,sizeof(int));
	int index=0;
	for(int i=1; i<=ub; ++i){
		if(abundancy(i) == a){
			matches[index++] = i;
		}
	}
	return matches;
}

int main(int argc, char **argv){
	if(argc == 2){
		int a = atoi(argv[1]);
		printf("Abundancy is %f\n",abundancy(a));
	}
	if(argc == 3){
		int a = atoi(argv[2]);
		if(!strcmp(argv[1],"abundancy")){
			printf("Abundancy is %f\n",abundancy(a));
		}
		else if(!strcmp(argv[1],"friends")){
			int *friends = (int *) calloc (a,sizeof(int));
			friends = smaller_friends(a);
			if(friends[0] == 0){
				printf("No friends smaller than %d found.\n",a);
			}
			else {
				printf("Friends smaller than %d: %d",a,friends[0]);
				for(int i=1; i<a && friends[i] != 0; ++i){
					printf(", %d",friends[i]);
				}
				printf(".\n");
			}
		}
		else if(!strcmp(argv[1],"search")){
			int *matches = (int *) calloc (LUBOUND,sizeof(int));
            float aa = abundancy(a);
			matches = matching(aa,LUBOUND);
			if(matches[0] == 0){
				printf("No friends of %d found.\n",a);
			}
			else {
				printf("Numbers with abundancy %d: %d",a,matches[0]);
				for(int i=1; i<=LUBOUND && matches[i] != 0; ++i){
					printf(", %d",matches[i]);
				}
				printf(".\n");
			}
		}
		else {
			int a = atoi(argv[1]);
			int b = atoi(argv[2]);
			if(aref(a,b)) { printf("Friendly!\n"); }
			else { printf("Not friendly!\n"); }
		}
	}
	if(argc == 4){
		int b = atoi(argv[3]);
		if(!strcmp(argv[1],"friendly")){
    		int a = atoi(argv[2]);
			if(aref(a,b)) { printf("Friendly!\n"); }
			else { printf("Not friendly!\n"); }
		}
		else if(!strcmp(argv[1],"search")){
    		float a = atof(argv[2]);
			int *matches = (int *) calloc (b,sizeof(int));
			matches = matching(a,b);
			if(matches[0] == 0){
				printf("No numbers with abundancy %f smaller than %d found.\n",a,b);
			}
			else {
				printf("Numbers with abundancy %f: %d",a,matches[0]);
				for(int i=1; i<=b && matches[i] != 0; ++i){
					printf(", %d",matches[i]);
				}
				printf(".\n");
			}
		}
	}
	return(0);
}
