#ifndef CONFIG_H
#define CONFIG_H

typedef struct config
{

	double (*method)(double (*function)(double*),double * ,double * ,int *);
	double a, b;
	int n;
	double (*f) (double *);

		
} config;


struct config get_config (char * path);

double trap_(double (*function)(double*),double * ,double * ,int *);
double sim_(double (*function)(double*),double * ,double * ,int *);
double rect_(double (*function)(double*),double * ,double * ,int *);

double f0_ (double* );
double f1_ (double* );

#endif
