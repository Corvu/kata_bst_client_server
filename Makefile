all: server client

server: bst
	g++ -Iinclude/ src/server.cpp binary_tree.o -o server

client:
	g++ src/client.cpp -o client

bst:
	g++ -Iinclude/ -c src/binary_tree.cpp

clean:
	rm client server binary_tree.o