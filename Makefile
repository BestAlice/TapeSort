all: build

build:
	g++ *.cpp -o sort_tape

clean:
	rm *.o