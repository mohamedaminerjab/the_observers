prog:  enemie.o fonction.o main.o 
	gcc enemie.o main.o fonction.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
fonction.o:fonction.c
	gcc -c fonction.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
enemie.o:enemie.c
	gcc -c enemie.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g