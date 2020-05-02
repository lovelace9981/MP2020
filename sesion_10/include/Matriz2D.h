// Fichero de cabecera de Matriz2D
// Autor: Pedro Antonio Mayorgas Parejo


#ifndef MATRIZ2D
#define MATRIZ2D

#include <iostream>
#include <string>
#include <cstring>

#include "Secuencia.h"

#define DEFAULT_FILS_COL 0

using namespace std;

//-------------------- Definiendo la clase  ------------------------------------

typedef int TipoBaseMatriz;

class Matriz2D {
private:
    int fils;
    int cols;
    TipoBaseMatriz ** datos;

    //---------- Funciones privadas de Asignacion y Eliminacion de memoria------
    void ReservaMemoria (int nfils, int ncols);
    void LiberaMemoria (void);
    void Clona (const Matriz2D & origen);

public:
    //-------------------Constructores -----------------------------------
    // Sin arg
    Matriz2D (void);
    // 1 arg, matriz cuadrada
    Matriz2D (int cuadrada);
    // 2 arg fils, cols
    Matriz2D (int nfils, int ncols);
    // 3 arg fils, cols, init
    Matriz2D (int nfils, int ncols, int valor);
    //------------------- Constructor de copia--------------------------
    Matriz2D (const Matriz2D & origen);
    //--------------------Destructor-----------------------------------
    ~Matriz2D (void);

    // -------------------- Eliminacion de la matriz2D ----------------
    void EliminaTodos(void);

    //------------------Funciones de E/S -------------------------------
    string ToString (void);
    int NumFilas (void) const;
    int NumColumnas (void) const;
    void Ecualiza (TipoBaseMatriz valor);

    TipoBaseMatriz & Valor (int num_fila, int num_col);

    //-----------------Funciones de borrado de columnas o filas--------
    void EliminaFila (int num_fila);
    void EliminaColumna (int num_col);
    //---------------- Funciones de comprobacion ----------------------
    bool EstaVacia(void);
    bool SonIguales(const Matriz2D & otra) const;

    //----------------- Creacion de matrices --------------------------
    Matriz2D SubMatriz (int fil_inic, int col_inic, int num_filas, \
      int num_cols);

    // Metodos trabajados con la clase secuencia
    void Aniade (const Secuencia & fila_nueva);
    void Inserta (int indice, const Secuencia & fila_nueva);
    Secuencia Fila (int indice);
    Secuencia Columna (int indice);

};
#endif
