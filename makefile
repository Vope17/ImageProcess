main: main.c imageProcessing.o info.o
	gcc main.c imageProcessing.o info.o -o main

gdb: main.c imageProcessing.o
	gcc -g main.c imageProcessing.o info.o -o main

imageProcessing.o: imageProcessing.c
	gcc -c imageProcessing.c

info.o: info.c
	gcc -c info.c

clean:
	del *.o main.exe
