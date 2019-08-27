
FILES = main.c random.c resources.c error.c graphics.c

exec: $(FILES)
	gcc $(FILES) -I ../include/ -lm -o exec -lSDL2 -lSDL2_image -Wall

debug:
	gcc $(FILES) -I ../include/ -lm -o exec -lSDL2 -lSDL2_image -g
run: 
	./exec
clean:
	rm exec