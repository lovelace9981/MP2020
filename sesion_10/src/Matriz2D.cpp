// Fichero de implementacion de la clase Matriz2D

#include "Matriz2D.h"

//---------- Funciones privadas de Asignacion y Eliminacion de memoria------
void Matriz2D :: ReservaMemoria (int nfils, int ncols){
  // Aunque sea 0 el tamanio de fils y cols, se almacena para los comprobadores
  fils = nfils;
  cols = ncols;

  // Si es igual a 0 no hacemos nada para reservar memoria
  // Necesitamos la Precondicion aqui porque de lo contrario la matriz,
  // no recibe el fils y cols por defecto
  if(nfils > DEFAULT_FILS_COL && ncols > DEFAULT_FILS_COL){
    datos = new TipoBaseMatriz * [nfils];

    for (int i = 0; i < nfils; i++){
      datos[i] = new TipoBaseMatriz [ncols];
    }
  }
}

void Matriz2D :: LiberaMemoria (void){
  // Borramos las columnas asignadas por fila
  for (int i = 0; i < fils; i++){
    delete datos[i];
  }
  // Borramos el vector de punteros de fila
  delete datos;
}

//-------- Metodo privado de clonacion de matrices a nivel profundo ------------
void Matriz2D :: Clona (const Matriz2D & origen) {
  // Hacemos la copia profunda desde origen

  // Memcpy implementation
  int n_fils = origen.NumFilas();
  int n_cols = origen.NumColumnas();

  // Copiamos fila por fila
  for (int i = 0; i < n_fils; i++){
      memcpy (datos[i], origen.datos[i], n_cols * sizeof(TipoBaseMatriz));
  }

  /* Old implementation with pointers
  for (int i = 0; i < fils; i++){
    for (int j = 0; j < cols; j++){
      datos[i][j] = origen.datos[i][j];
    }
  }
  */
}



//-------------------Constructores -----------------------------------
// Sin arg
Matriz2D :: Matriz2D (void) {
  fils = 0;
  cols = 0;
}
// 1 arg
// Delegating on C++11
Matriz2D :: Matriz2D (int cuadrada) : Matriz2D(cuadrada, cuadrada){};

// 2 arg fils, cols
Matriz2D :: Matriz2D (int nfils, int ncols) {
  ReservaMemoria (nfils, ncols);
}

// 3 arg fils, cols, init
Matriz2D :: Matriz2D (int nfils, int ncols, int valor){
  ReservaMemoria (nfils, ncols);
  Ecualiza (valor);
}
//------------------- Constructor de copia--------------------------
Matriz2D :: Matriz2D (const Matriz2D & origen) {
    LiberaMemoria(); // Limpia el estado nuevo de la memoria
    ReservaMemoria (origen.fils, origen.cols);
    Clona (origen);
}
//--------------------Destructor-----------------------------------
Matriz2D :: ~Matriz2D (void) {
    LiberaMemoria ();
}

// ------------------ Metodo de elimina todos los datos de una matriz ----------

void Matriz2D :: EliminaTodos (void) {
    LiberaMemoria();
    ReservaMemoria(fils, cols);
}

//------------------Funciones de E/S -------------------------------
string Matriz2D :: ToString (void) {
  string return_string;
  int fils = NumFilas();
  int cols = NumColumnas();

  // Hacemos el tablero de " " 0 1 2 3 4 5 6 7 8 9
  //                        0
  //                        1
  return_string += "  ";

  for (int j = 0; j < cols; j++){
    return_string += to_string(j);
    return_string += " ";
  }

  return_string += "\n";

  for (int i = 0; i < fils; i++){
      return_string += to_string(i);
      return_string += " ";

      for (int j = 0; j < cols; j++){
        return_string += to_string(datos[i][j]);
        return_string += " ";
      }

      return_string += "\n";
    }

  return return_string;
}


int Matriz2D :: NumFilas (void) const {
  return fils;
}


int Matriz2D :: NumColumnas (void) const {
  return cols;
}

void Matriz2D :: Ecualiza (TipoBaseMatriz valor) {
  int fils = NumFilas();
  int cols = NumColumnas();

  for (int i = 0; i < fils; i++){
    for (int j = 0; j < cols; j++){
      datos[i][j] = valor;
    }
  }
}



TipoBaseMatriz & Matriz2D::Valor (int num_fila, int num_col) {
    return datos[num_fila][num_col];
}

//-----------------Funciones de borrado de columnas o filas--------
void Matriz2D :: EliminaFila (int num_fila) {
  int fila_copia = 0;
  TipoBaseMatriz ** copia_datos;

  // Generamos la nueva base de punteros
  copia_datos = new TipoBaseMatriz * [fils - 1];

  for (int i = 0; i < fils - 1; i++){
    copia_datos[i] = new TipoBaseMatriz [cols];
  }


  // Hacemos la copia profunda en las otras direcciones de la matriz
  for (int i = 0; i < fils; i++){
    if (i != num_fila){
      // Hacemos comprobacion de que copie mientras la columna no sea esa
      for (int j = 0; j < cols; j++){
          copia_datos[fila_copia][j] = datos[i][j];
      }

      fila_copia++;
    }
  }

  // Liberamos la memoria usada con i filas del heap
  // Borramos las columnas asignadas por fila
  for (int i = 0; i < fils; i++){
    delete datos[i];
  }
  // Borramos el vector de punteros de fila
  delete datos;

  fils = fils - 1;

  // Asignamos el puntero con los datos
  datos = copia_datos;
}

void Matriz2D :: EliminaColumna (int num_col) {
  int col_copia = 0;

  TipoBaseMatriz ** copia_datos;

  // Generamos la nueva base de punteros
  copia_datos = new TipoBaseMatriz * [fils];

  for (int i = 0; i < fils - 1; i++){
    copia_datos[i] = new TipoBaseMatriz [cols - 1];
  }


  // Hacemos la copia profunda en las otras direcciones de la matriz
  for (int i = 0; i < fils; i++){
      // Hacemos comprobacion de que copie mientras la columna no sea esa
      for (int j = 0; j < cols; j++){
        if (j != num_col){
          copia_datos[i][col_copia] = datos[i][j];
          col_copia++;
        }
      }
      // Restauramos col_copia
      col_copia = 0;
    }

  // Liberamos la memoria usada con i filas del heap
  // Borramos las columnas asignadas por fila
  for (int i = 0; i < fils; i++){
    delete datos[i];
  }
  // Borramos el vector de punteros de fila
  delete datos;

  cols = cols - 1;

  // Asignamos el puntero con los datos
  datos = copia_datos;
}



//---------------- Funciones de comprobacion ----------------------
bool Matriz2D :: EstaVacia(void) {
    bool vacia = fils == DEFAULT_FILS_COL && cols == DEFAULT_FILS_COL;

    return vacia;
}

  //Hacemos la funcion const para que se quede constancia de que no
  // se modifica
  bool Matriz2D :: SonIguales(const Matriz2D & otra) const {
    int fils_una = fils;
    int fils_otra = otra.fils;
    int cols_una = cols;
    int cols_otra = otra.cols;

    bool check_f_c, check_datos;

    check_datos = true;

    check_f_c = fils_una == fils_otra && cols_otra == cols_una;

    if (check_f_c){
      // Comprobamos que los datos sean iguales
      for (int i = 0; i < fils_una && check_datos; i++){
        for (int j = 0; j < cols_una && check_datos; j++){
          check_datos = datos[i][j] == otra.datos[i][j];
        }
      }
      // Retorna que la matriz es igual o que no es igual solo por los datos.
      return check_datos;
    }
    else {
      // Retorna que la matriz no es igual solo por las fil y cols
      return check_f_c;
    }
  }

  Matriz2D Matriz2D :: SubMatriz (int fil_inic, int col_inic, int num_filas, \
    int num_cols){

    int fil_original = NumFilas();
    int cols_original = NumColumnas();
    int i_resultado, j_resultado;

    bool check_f_c, check_i_resultado, check_j_resultado;

    i_resultado = j_resultado = 0;

    check_f_c = fil_inic <= fil_original && fil_inic >= DEFAULT_FILS_COL &&
    col_inic <= fil_original && col_inic >= DEFAULT_FILS_COL;

    if (check_f_c){
      Matriz2D resultado (num_filas, num_cols);

      //Comprobando condicion inicial
      check_j_resultado = j_resultado < num_cols;
      check_i_resultado = i_resultado < num_filas;

      for (int i = fil_inic; i < fil_original && check_i_resultado; i++){
        for (int j = col_inic; j < cols_original && check_j_resultado; j++){
          resultado.Valor(i_resultado, j_resultado) = Valor(i, j);

         j_resultado++;

         check_j_resultado = j_resultado < num_cols;
        }
        //Reiniciamos el contador a cero para rerecorrer la matriz.
        j_resultado = 0;
        check_j_resultado = true;
        //Incrementamos la fila
        i_resultado++;
        check_i_resultado = i_resultado < num_filas;
      }

      return resultado;
    }
    else {
      // Creamos matriz por defecto 0 0
      Matriz2D resultado;
      return resultado;
    }
}


// implementacion de la clase secuencia.

void Matriz2D :: Aniade (const Secuencia & fila_nueva) {
    TipoBaseMatriz ** p_vector_filas;
    int n_filas_original = NumFilas();
    int n_filas_final = n_filas_original + 1;
    int n_cols_totales = NumColumnas();

    // Usamos constructor de copia para tener una copia nueva usable
    Secuencia * sec_copia = new Secuencia (fila_nueva);

    // Comprobando que el tamanio de fila sea el correcto
    if (n_cols_totales == sec_copia -> TotalUtilizados()){
        // Comprobamos que sea el mismo tipo de dato por su tamanio
        if (sizeof(TipoBaseMatriz) == sizeof(TipoBaseSecuencia)){
            // Regeneramos el vector con una fila mas
            p_vector_filas = new TipoBaseMatriz *  [fils + 1];

            for (int i = 0; i < n_filas_final; i++){
                p_vector_filas[i] = new TipoBaseMatriz [n_cols_totales];
            }

            // Copia profunda hasta fil

            for (int i = 0; i < n_filas_original; i++){
                for (int j = 0; j < n_cols_totales; j++){
                    p_vector_filas[i][j] = datos[i][j];
                }
            }

            // Borramos la reserva de memoria antigua
            LiberaMemoria();
            // Enlazamos el vector de vectores a datos
            datos = p_vector_filas;
            // Comenzamos la copia profunda en la fila
            for (int j = 0; j < n_cols_totales; j++){
                datos[fils][j] = sec_copia -> Valor(j);
            }

            // Aumentamos el numero de filas para que sea hasta 3 desde 0 1 2
            fils = n_filas_final;
        }
    }
    // Borramos la copia realizada de la secuencia llamando a su destructor
    delete sec_copia;
}

void Matriz2D :: Inserta (int indice, const Secuencia & fila_nueva){
    TipoBaseMatriz ** p_vector_filas;
    int n_filas_original = NumFilas();
    int n_filas_final = n_filas_original + 1;
    int n_cols_totales = NumColumnas();
    int contador_filas = 0;
    // Usamos constructor de copia para tener una copia nueva usable
    Secuencia * sec_copia = new Secuencia (fila_nueva);

    // Comprobando que el tamanio de fila sea el correcto
    if (n_cols_totales == sec_copia -> TotalUtilizados()){
        // Comprobamos que sea el mismo tipo de dato por su tamanio
        if (sizeof(TipoBaseMatriz) == sizeof(TipoBaseSecuencia)){
            // Regeneramos el vector con una fila mas para la insercion
            p_vector_filas = new TipoBaseMatriz * [n_filas_final];

            for (int i = 0; i < n_filas_final; i++){
                p_vector_filas[i] = new TipoBaseMatriz [n_cols_totales];
            }

            // Copia profunda hasta fil desplazando la fila a insertar

            // Como funciona el algoritmo
            // Tenemos un indice que vale n; lo que hace el algoritmo
            // al evaluar las filas i es que si son iguales a indice
            // copia la secuencia
            // Si no son iguales, copia los datos correspondientes de
            // la fila actual de la antigua matriz.
            // Es decir si:
            // insertamos en 1
            // fila
            // 0 lo que sea 0
            // 1 lo que sea 1
            // Despues
            // fila
            // 0 lo que sea 0 al evaluar que no es la fila donde se inserta
            // 1 lo que sea insertado
            // 1+1 lo que sea 1 antiguo
            // contador_filas es el contador de respaldo para poder copiar
            // las i filas antiguas
            for (int i = 0; i < n_filas_final; i++){
                if (i == indice){
                    for (int j = 0; j < n_cols_totales; j++){
                        // Comenzamos la copia profunda en la fila
                        p_vector_filas[i][j] = sec_copia -> Valor(j);
                    }
                }
                else {
                    for  (int j = 0; j < n_cols_totales; j++){
                        p_vector_filas[i][j] = datos[contador_filas][j];
                    }
                    contador_filas++;
                }
            }

            // Borramos la reserva de memoria antigua
            LiberaMemoria();
            // Enlazamos el vector de vectores a datos
            datos = p_vector_filas;
            // Aumentamos el numero de filas para que sea hasta 3 desde 0 1 2
            fils = n_filas_final;
        }
    }
    // Borramos la copia realizada de la secuencia llamando a su destructor
    delete sec_copia;
}


// Devuelve una fila concreta
Secuencia Matriz2D :: Fila (int indice){
    Secuencia * return_secuencia = new Secuencia(NumColumnas());

    for (int j = 0; j < NumColumnas(); j++){
        return_secuencia -> Aniade(datos[indice][j]);
    }

    return *return_secuencia;
}

Secuencia Matriz2D :: Columna (int indice){
    Secuencia * return_secuencia = new Secuencia(NumFilas());

    for (int i = 0; i < NumFilas(); i++){
        return_secuencia -> Aniade(datos[i][indice]);
    }

    return *return_secuencia;
}
