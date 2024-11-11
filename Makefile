all: bin/testListArray bin/testNode bin/testListLinked
# Compilar testListArray
bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

# Compilar testNode
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

# Compilar testListLinked
bin/testListLinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h Node.h

# Regla clean (para limpiar los archivos generados)
clean:
	rm -r *.o *.gch bin

