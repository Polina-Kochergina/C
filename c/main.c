#include<stdio.h>
#include"../h/config.h"

int main()
{
	double S;
	config cfg;
	char *path = "config.cfg";
	cfg = get_config (path);
	S = cfg.method (cfg.f, &cfg.a, &cfg.b, &cfg.n);
	printf("S = %lf\n", S);

	return 0;
}
