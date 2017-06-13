start: main.o stack.o tree.o parser.o task.o
	gcc -o start main.o stack.o tree.o parser.o task.o

main.o: main.c stack.h tree.h parser.h token.h
	gcc -c main.c

stack.o: stack.c stack.h token.h
	gcc -c stack.c

tree.o: tree.c tree.h parser.h parser.h stack.h
	gcc -c tree.c

parser.o: parser.c parser.h stack.h
	gcc -c parser.c

task.o: task.c task.h
	gcc -c task.c

clean:
	rm -rf *.o start
