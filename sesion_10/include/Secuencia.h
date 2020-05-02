#ifndef CLASS_SECUENCIA_TIPOBASE
#define CLASS_SECUENCIA_TIPOBASE

#include <string>
using namespace std;

/***************************************************************************/
// Definiciones de tipos --> Dejar activo un solo bloque

// Tipo de los elementos de la Secuencia

#define INT							// Para usarlo con #ifdef

#ifdef INT
    typedef int TipoBaseSecuencia;		// Tipo de los elementos de la secuencia
    #define ANCHO_SECUENCIA 5
    #define VALOR_DEF_SECUENCIA 0
#endif


#ifdef DOUBLE
    typedef double TipoBaseSecuencia;	// Tipo de los elementos de la secuencia
    #define DOUBLE						// Para usarlo con #ifdef
    #define ANCHO_SECUENCIA 6
    #define DECIMALES_SECUENCIA 2
    #define VALOR_DEF_SECUENCIA 0.0
#endif

class Secuencia {

private:

	// Núm.casillas disponibles (capacidad) por defecto
    static const int TAMANIO = 50;

	// Si el porcentaje de casillas usadas > PORC_PETICION --> Crecimiento
    static const int PORC_PETICION = 75;
	// La capacidad aumenta PORC_CRECIMIENTO sobre la capacida actual
    static const int PORC_CRECIMIENTO = 10;
	// El valor mínimo de casillas para el crecimiento será MIN_CRECIMIENTO
    static const int MIN_CRECIMIENTO = 5;

	// Si el porcentaje de casillas usadas < PORC_REDUCCION --> Decrecimiento
    static const int PORC_REDUCCION = 50;
	// La capacidad queda PORC_EXTRA sobre la ocupación actual
    static const int PORC_EXTRA = 20;


	// "vector_privado" es un puntero a un array dinámico de
	// datos "TipoBaseSecuencia"
    TipoBaseSecuencia * vector_privado;

    // PRE: 0 <= capacidad
    int capacidad; // Núm.casillas ocupadas

    // PRE: 0 <= total_utilizados <= capacidad
    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructores
	// Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
	// Si se llama con un argumento, su valor será la capacidad inicial.
	// POST: La secuencia creada estará vacía (EstaVacia()== true)

    Secuencia (int la_capacidad=TAMANIO);

    /***********************************************************************/
    // Constructor de copia

    Secuencia (const Secuencia & otro);

    /***********************************************************************/
    // Destructor

    ~Secuencia (void);

    /***********************************************************************/


    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados (void) const;

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void) const;

    /***********************************************************************/
    // Devuelve "true" si la secuencia está vacía (total_utilizados == 0)

	bool EstaVacia (void) const;

    /***********************************************************************/
    // "Vacía" completamente la secuencia
	// POST: Capacidad() == TAMANIO.
	// POST: EstaVacia() == true

	void EliminaTodos();

    /***********************************************************************/
    // Añade un elemento ("nuevo") a la secuencia.
    // El nuevo elemento se coloca al final del vector.

    void Aniade (const TipoBaseSecuencia nuevo);

    /***********************************************************************/
    // Devuelve una referencia al elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    TipoBaseSecuencia & Valor (const int indice);

    /***********************************************************************/
    // Copia profunda.
    // Parámetros:
    //      otra (referencia), objeto que sirve de modelo para la copia.

    void Clona (const Secuencia & otra);

    /***********************************************************************/
    // Eliminar el contenido de la "casilla" cuya posición es "indice".
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice);

    /***********************************************************************/
    // Inserta el valor "nuevo" en la posición dada por "indice".
    // "Desplaza" todos los enteros una posición a la derecha antes de
	// copiar en "indice" en valor "nuevo".
	// PRE: 0 <= indice < total_utilizados

	void Inserta (int indice, TipoBaseSecuencia nuevo);

    /***********************************************************************/
    // Compone un string con todos los caracteres que están
    // almacenados en la secuencia y lo devuelve.

    string ToString();

    /***********************************************************************/

private:

    /***********************************************************************/

	// Pide memoria para guardar "num_casillas" datos

	void ReservarMemoria (const int num_casillas);

    /***********************************************************************/
	// Libera memoria

	void LiberarMemoria (void);

    /***********************************************************************/
	// Copiar datos desde otro objeto de la clase
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const Secuencia & otro);

	/***********************************************************************/
	// Redimensiona el vector dinámico y copia los datos en el nuevo almacén.
	//
	// Pedirá memoria adicional si el número de casillas usadas es superior
	// al "PROC_PETICION" de la capacidad actual. El número de casillas
	// adicionales será el "PORC_CRECIMIENTO" de la capacidad actual.

	void Redimensionar (void);

    /***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

#endif
