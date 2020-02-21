
all: lib
	mkdir -p ./lib
	mv *.so ./lib
	gcc -L./lib -Wl,-rpath=./lib -Wall -o test main.c -lcomponent -lresistance -lpower
lib:
	gcc -c -Wall -Werror -fpic libcomponent.c libresistance.c libpower.c
	gcc -shared -o libcomponent.so libcomponent.o
	gcc -shared -o libresistance.so libresistance.o
	gcc -shared -o libpower.so libpower.o
clean:
	rm -f *.o lib/*.so
	rm -r lib

install:
	cp *.so /usr/local/lib
	cp program /usr/local/bin 


uninstall:
	rm program /usr/local/bin
	rm *.so /usr/local/bin
