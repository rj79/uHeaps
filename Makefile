all:
	g++ -c src/*.cpp -Iinclude
	g++ *.o -o testapp

clean:
	rm -f *.o
	rm -f testapp

