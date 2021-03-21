CC := g++

all:
	$(CC) main.cpp
	./a.out

clean:
	rm -rf a.out