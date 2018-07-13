#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//não esquecer do -lm para compilar

double f (double x) {
    return (cos(x)-x);
}

int SolucaoPontoFixo (double *x0, double prec) {
	double dx, x;
    int it = 0;

	while (dx > prec) {
		x = f(x) ;
		dx = fabs(x-*x0);
		*x0 = x;
		it++;		
		printf ("%ld\t %d\n", *x0, it);	
	}
	return(it);
}	

int main(int argc, char **argv) {
	double x, x0, prec;

	x0 = atof(argv[1]);
	prec = atof(argv[2]);
	printf("\nRaiz = %.10g em %d iterações \n", x0, SolucaoPontoFixo(&x0, prec));
	return 0;
}