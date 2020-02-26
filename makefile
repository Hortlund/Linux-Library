
all:
	gcc -c -Wall -Werror -fpic libcomponent.c libresistance.c libpower.c
	gcc -shared -o libcomponent.so libcomponent.o
	gcc -shared -o libresistance.so libresistance.o
	gcc -shared -o libpower.so libpower.o
	mkdir -p ./lib
	mv *.so ./lib
	gcc -L./lib -Wl,-rpath=./lib -Wall -o electrotest main.c -lcomponent -lresistance -lpower

lib:
	gcc -c -Wall -Werror -fpic libcomponent.c libresistance.c libpower.c
	gcc -shared -o libcomponent.so libcomponent.o
	gcc -shared -o libresistance.so libresistance.o
	gcc -shared -o libpower.so libpower.o


clean:
	rm -f *.o lib/*.so
	rm -r lib
	rm electrotest

install:
	cp ./lib/*.so /usr/local/lib
	cp electrotest /usr/local/bin
	ldconfig
	gcc -Wall -o electrotest main.c -lcomponent -lresistance -lpower


uninstall:
	rm /usr/local/bin/electrotest
	rm /usr/local/lib/libpower.so 
	rm /usr/local/lib/libcomponent.so 
	rm /usr/local/lib/libresistance.so
