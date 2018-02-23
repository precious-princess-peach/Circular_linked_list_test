main.o: main.C
	g++ main.C -o main.o

run: main.o
	./main.o

clean:
	rm -f *.o