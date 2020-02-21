
all:lib 
	mkdir -p ./lib
	mv *.so ./lib
	gcc -L./lib -Wl,-rpath=./lib -Wall -o program main.c -le_resistance -lresistance -lpower

lib:
	gcc -c -Wall -Werror -fpic e_resistance.c libresistance.c libpower.c
	gcc -shared -o libe_resistance.so e_resistance.o
	gcc -shared -o libresistance.so libresistance.o
	gcc -shared -o libpower.so libpower.o
clean:
	rm -f *.o lib/*.so
	rm -r lib

install:
	cp ./lib/*.so /usr/local/lib
	cp program /usr/local/bin 


uninstall:
	rm /usr/local/bin/program
	rm /usr/local/lib/libpower.so libresistance.so 
