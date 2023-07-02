CC := g++
CFLAGS := -Iinclude/ -std=c++2a

all: server client

server: bst
	$(CC) $(CFLAGS) src/server.cpp binary_tree.o -o server

client:
	$(CC) $(CFLAGS) src/client.cpp -o client

bst:
	$(CC) $(CFLAGS) -c src/binary_tree.cpp

clean:
	rm client server binary_tree.o