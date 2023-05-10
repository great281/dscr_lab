FLAGS = -Wall -g

all: lab5

lab5: lab5.o graph.o stack.o

lab5.o: lab5.c
	$(CC) -c $(FLAGS) -o $@ $^

graph.o: graph.c
	$(CC) -c $(FLAGS) -o $@ $^

stack.o: stack.c
	$(CC) -c $(FLAGS) -o $@ $^

clean:
	find -name '*.o' -exec $(RM) '{}' \;