all: binary.o name.o title.o principals.o main.o common.o
	gcc binary.o common.o name.o title.o principals.o main.o -g -o a3	

binary.o: binary.c common.h
	gcc -Wall -ansi -pedantic -c -g binary.c -o binary.o

common.o: common.c binary.h common.h name.h title.h principals.h
	gcc -Wall -ansi -pedantic -c -g common.c -o common.o

name.o: name.c binary.h common.h
	gcc -Wall -ansi -pedantic -c -g name.c -o name.o

title.o: title.c binary.h common.h
	gcc -Wall -ansi -pedantic -c -g title.c -o title.o

principals.o: principals.c binary.h common.h
	gcc -Wall -ansi -pedantic -c -g principals.c -o principals.o

main.o: main.c binary.h common.h name.h title.h principals.h
	gcc -Wall -ansi -pedantic -c -g main.c -o main.o

clean:
	rm *.o
