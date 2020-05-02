#Makefile de la sesion 10
#Autor Pedro Antonio Mayorgas Parejo
#Macros

BIN = bin
OBJ = obj
SRC = src
INCLUDE = include
LIB = lib

all: III_Demo-Matriz2D
	@echo La sesion 10 ha sido creada
#Ejercicio 2
III_Demo-Matriz2D: $(BIN)/III_Demo-Matriz2D
	@echo La implementacion de demo de la clase Matriz2D ha sido compilada!!

$(BIN)/III_Demo-Matriz2D: $(OBJ)/III_Demo-Matriz2D.o \
	 $(LIB)/libMatriz2D.a
	 g++ --std=c++11 -o $(BIN)/III_Demo-Matriz2D \
	  $(OBJ)/III_Demo-Matriz2D.o -lMatriz2D -L./$(LIB)

$(OBJ)/III_Demo-Matriz2D.o: $(SRC)/III_Demo-Matriz2D.cpp \
	$(INCLUDE)/Matriz2D.h
	g++ --std=c++11 -c -o $(OBJ)/III_Demo-Matriz2D.o $(SRC)/III_Demo-Matriz2D.cpp \
	-I./$(INCLUDE)

$(LIB)/libMatriz2D.a: $(OBJ)/Matriz2D.o $(OBJ)/Secuencia.o
	ar rvs $(LIB)/libMatriz2D.a $(OBJ)/Matriz2D.o $(OBJ)/Secuencia.o

$(OBJ)/Matriz2D.o: $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h \
	$(INCLUDE)/Secuencia.h
	g++ --std=c++11 -c -o  $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp -I./$(INCLUDE)

$(OBJ)/Secuencia.o: $(SRC)/Secuencia.cpp $(INCLUDE)/Secuencia.h
	g++ --std=c++11 -c -o $(OBJ)/Secuencia.o $(SRC)/Secuencia.cpp -I./$(INCLUDE)


mr_proper: clean_obj clean_lib clean_bin

clean_bin:
	rm $(BIN)/III_Demo-Matriz2D
clean_lib:
	rm $(LIB)/libMatriz2D.a
clean_obj:
	rm $(OBJ)/Matriz2D.o
	rm $(OBJ)/Secuencia.o
	rm $(OBJ)/III_Demo-Matriz2D.o
