#MACROS
CC=gcc
CFLAGS=-Wall -g -pedantic
CLIBS=-lscreen -L.

.PHONY=clean

all: hormiguero
#ENLAZAMOS LOS ARCHIVOS PARA CREAR EL EJECUTABLE HORMIGUERO
hormiguero: command.o game_loop.o game.o graphic_engine.o space.o game_reader.o
	$(CC) -o$@ $^ $(CLIBS)

#LOS ARCHIVOS .O
game_reader.o: game_reader.c game_reader.h game.h command.h space.h types.h
	$(CC) $(CFLAGS) -c $< 

command.o: command.c command.h
	$(CC) $(CFLAGS) -c $< 

game_loop.o: game_loop.c graphic_engine.h game.h command.h
	$(CC) $(CFLAGS) -c $<

game.o: game.c game.h
	$(CC) $(CFLAGS) -c $<

graphic_engine.o: graphic_engine.c graphic_engine.h libscreen.h command.h space.h types.h
	$(CC) $(CFLAGS) -c $<

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -c $< 

#LIMPIEZA
clean:
	rm *.o 

