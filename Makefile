all: build

build:
	g++ *.cpp -o tape_sort

clean:
	rm *.o