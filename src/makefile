
FILES = main.c random.c resources.c

exec: $(FILES)
	gcc $(FILES) -I ../include/ -lm -o exec -lSDL2

run: 
	./exec
clean:
	rm exec