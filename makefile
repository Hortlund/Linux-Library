
all:lib 
	mkdir -p ./lib
	mv *.so ./lib
	gcc -L./lib -Wl,-rpath=./lib -Wall -o program main.c -lcomponent -lresistance -lpower
lib:
	gcc -c -Wall -Werror -fpic libcomponent.c libresistance.c libpower.c
	gcc -shared -o libcomponent.so libcomponent.o
	gcc -shared -o libresistance.so libresistance.o
	gcc -shared -o libpower.so libpower.o
clean:
	rm -f *.o lib/*.so
	rm -r lib
	rm program

install:
	cp ./lib/*.so /usr/local/lib
	cp program /usr/local/bin 


uninstall:
	rm /usr/local/bin/program
	rm /usr/local/lib/libpower.so 
	rm /usr/local/lib/libcomponent.so 
	rm /usr/local/lib/libresistance.so
