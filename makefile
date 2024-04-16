main: main.c imageProcessing.o
	gcc -o main.c imageProcessing.o -o main

gdb: main.c imageProcessing.o
	gcc -g main.c imageProcessing.o -o main

imageProcessing.o: imageProcessing.c
	gcc -c imageProcessing.c

clean:
	del *.o main.exe
