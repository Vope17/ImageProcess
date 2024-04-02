main: main.c imageProcessing.o
	gcc main.c imageProcessing.o -o main

imageProcessing.o: imageProcessing.c
	gcc -c imageProcessing.c

clean:
	del *.o main.exe