all: bin/testListArray bin/testNode bin/testListLinked
# Compilar testListArray
bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -Wall -o bin/testListArray testListArray.cpp

# Compilar testNode
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -Wall -o bin/testNode testNode.cpp

# Compilar testListLinked
bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -Wall -o bin/testListLinked testListLinked.cpp

# Regla clean (para limpiar los archivos generados)
clean:
	rm -rf bin *.o *.gch

