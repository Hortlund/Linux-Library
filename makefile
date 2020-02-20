
all: lib
	mkdir -p ./lib
	mv *.so ./lib
	gcc -L./lib -Wl,-rpath=./lib -Wall -o test main.c -le_resistance -lresistance
lib:
	gcc -c -Wall -Werror -fpic e_resistance.c libresistance.c
	gcc -shared -o libe_resistance.so e_resistance.o
	gcc -shared -o libresistance.so libresistance.o
clean:
	rm -f *.o lib/*.so
	rm -r lib

install:
	cp *.so /usr/local/lib
	cp program /usr/local/bin 


uninstall:
	rm program /usr/local/bin
	rm *.so /usr/local/bin
