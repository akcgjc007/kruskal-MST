CC := g++
p := 10
n := 10
PY := python3

all:
	$(CC) main.cpp
	./a.out $(n) $(p)
	@echo "\n"
plot:
	# rm -rf data.txt
	$(PY) plot.py

clean:
	rm -rf a.out