
FILES = main.c random.c resources.c error.c graphics.c entity.c vector.c input.c interface.c
OBJS = main.o random.o resources.o error.o graphics.o entity.o vector.o input.o interface.o
BINARY = Abyss
CFLAGS = -lm -lSDL2 -lSDL2_image -lSDL2_ttf -I ../include/

binary: $(OBJS)
	gcc $(OBJS) $(CFLAGS) -o $(BINARY)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

debug:
	gcc $(FILES) $(CFLAGS) -g -o $(BINARY)

run:
	./$(BINARY)

clean:
	rm -f $(BINARY) $(OBJS)