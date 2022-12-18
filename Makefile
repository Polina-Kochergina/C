compiler = gcc
compiler_f = gfortran
mem = -g -fsanitize=address
files_c=$(wildcard ./c/*.c)
files_f=$(wildcard ./c/*.f95)

main: $(patsubst ./c/%.c, %.o, $(files_c)) $(patsubst ./c/%.f95, %.o, $(files_f))
	$(compiler) $(mem) -O3 $^ -o $@ -Werror -lm

%.o: ./c/%.c
	$(compiler) -O3 -c $^ -o $@ -Werror -lm

%.o: ./c/%.f95
	$(compiler_f) -O3 -c $^ -o $@ -Werror

del:
	rm -f *.o *.mod main

res: main 
	./main

