
programa: main.o libcomplexo.a
     gcc -o complexo main.o -L. -lcomplexo -lcomplexo -lm

main.o: main.c complexo.h
     gcc -c main.c

libcomplexo.a: complexo.o
     ar rcsv libcomplexo.a complexo.o

complexo.o: complexo.c complexo.h
     gcc -c complexo.c

clean:
     rm -f *.o