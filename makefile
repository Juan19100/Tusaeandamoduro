#MACROS
CC=gcc
CFLAGS=-Wall -g -pedantic
CLIBS=-lscreen -L.

.PHONY=clean

all: hormiguero

ex:
	./hormiguero hormiguero.dat
runv:
	valgrind --leak-check=full ./hormiguero hormiguero.dat
#ENLAZAMOS LOS ARCHIVOS PARA CREAR EL EJECUTABLE HORMIGUERO
hormiguero: command.o game_loop.o game.o graphic_engine.o set.o space.o game_reader.o player.o object.o enemy.o
	$(CC) -o$@ $^ $(CLIBS)

space_test: space_test.o space.o set.o
	$(CC) -o$@ $^ $(CLIBS)
	
set_test : set_test.o set.o
	$(CC) -o$@ $^ $(CLIBS)

enemy_test : enemy_test.o enemy.o set.o
	$(CC) -o$@ $^ $(CLIBS)
#LOS ARCHIVOS .O
game_reader.o: game_reader.c game_reader.h game.h command.h space.h types.h player.h object.h
	$(CC) $(CFLAGS) -c $< 

command.o: command.c command.h
	$(CC) $(CFLAGS) -c $< 

game_loop.o: game_loop.c graphic_engine.h game.h command.h space.h types.h player.h object.h
	$(CC) $(CFLAGS) -c $<

game.o: game.c game.h command.h space.h types.h player.h object.h game_reader.h enemy.h
	$(CC) $(CFLAGS) -c $<

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h space.h types.h player.h object.h libscreen.h
	$(CC) $(CFLAGS) -c $<

space.o: space.c space.h types.h set.h
	$(CC) $(CFLAGS) -c $< 

player.o: player.c types.h player.h
	$(CC) $(CFLAGS) -c $<

enemy.o: enemy.c types.h object.h enemy.h
	$(CC) $(CFLAGS) -c $<

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c $<

space_test.o: space_test.c space.h types.h space_test.h test.h
	$(CC) $(CFLAGS) -c $<

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c $<

set_test.o: set_test.c set.h types.h set_test.h test.h
	$(CC) $(CFLAGS) -c $<

enemy_test.o: enemy_test.c types.h enemy_test.h set.h enemy.h
	$(CC) $(CFLAGS) -c $<
	
inventory.o: inventory.c inventory.h set.h types.h
	$(CC) $(CFLAGS) -c $<
	
#LIMPIEZA
clean:
	rm *.o 

