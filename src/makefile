
FILES = main.c random.c resources.c

exec: $(FILES)
	gcc $(FILES) -I ../include/ -lm -o exec -lSDL2 -Wall

debug:
	gcc $(FILES) -I ../include/ -lm -o exec -lSDL2 -g
run: 
	./exec
clean:
	rm exec