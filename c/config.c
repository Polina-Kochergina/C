#include"../h/config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void separation (char* buffer, char* name, char* value)
{	
	int n = strlen(buffer) - 1;

	int is_right = 0;

	for (int i = 0; i < n; i++)
	{
		if (is_right == 0)
			name[i] = buffer[i]; 
		else
			value[i - is_right - 1] = buffer[i];

		if (buffer[i] == *"=")
			is_right = i;
	
	}
	name[is_right] = *"\0";
	printf("%s\n", name);
	value[n - is_right - 1] = *"\0";
	printf("%s\n", value);
    
}

void cleaning (char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
	if (str[i] == *" " || str[i] == *"\t")
	{	for (int j = 0; j < n-i; j++)
	 	*(str + i + j) = *(str + i + 1 + j);
	}
    }
}



config get_config (char * path)
{
	config cfg;
	FILE *file;
	file = fopen (path, "r");

	char buffer[256];
	int line = 0;
	int error = 0;

	while (fgets(buffer, 256, file)){
		
		char parameter[strlen(buffer) - 1];
		char value[strlen(buffer) - 1];
		char *endstr[strlen(value)];
		
		line ++;
		cleaning (buffer);
		if (buffer[0] == '#' || strcmp(buffer, "\n") == 0)
			continue;
		separation (buffer, parameter, value);
		

		if (strcmp(parameter, "a") == 0){
			cfg.a = strtod(value, endstr);
			printf("%f\n", cfg.a);
		}
	
		else if (strcmp(parameter, "b") == 0)
		{	
			
			cfg.b = strtod(value, endstr);
			printf("%f\n", cfg.b);
		}
		
		else if (strcmp(parameter, "method") == 0)
		{
			if (strcmp(value, "rect") == 0)
				cfg.method = rect_;
				
			else if (strcmp(value, "trap") == 0)
				cfg.method = trap_;
				
			else if (strcmp(value, "sim") == 0)
				cfg.method = sim_;
				
			else
				printf("unknown method %s\n", value);
			
		}
		
		else if (strcmp(parameter, "f") == 0)
		{
			if (strcmp(value, "f0") == 0)
				cfg.f = f0_;
			else if (strcmp(value, "f1") == 0)
				cfg.f = f1_;
			else
				printf("unknown function %s\n", value);
		}
		
		else if (strcmp(parameter, "n") == 0)
		{
			cfg.n = (int) strtod(value, endstr);
			printf("%d\n", cfg.n);
		}
		
		else 
			printf("unknown parameter %s\n", parameter);
	}
	

	return cfg;
}
