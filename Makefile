all: unittests

unittests:
	pio test -e unittest

clean:
	rm testapp src/*.o