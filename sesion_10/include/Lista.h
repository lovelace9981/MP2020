#ifndef LISTA
#define LISTA

#include <string>
#include "GeneradorAleatorioEnteros.h"


#define VALOR_DEF 0.0

using namespace std;


/***************************************************************************/
// Definiciones de tipos
typedef double TipoBase;

// Cada nodo de la lista es de tipo "Nodo"

struct Nodo {
   TipoBase info;
   Nodo *sig;
};

typedef Nodo * PNodo; 	// Para los punteros a nodos
typedef Nodo * Lista;	  // Para la lista


/***************************************************************************/
/***************************************************************************/
// Crea una lista enlazada con "num_nodos" nodos. Inicializa todos los nodos
// a un valor com�n, el indicado en el par�metro "valor".
// La funcionalidad ser�a similar a la de un constructor.
// Par�metros:
//  	num_nodos, n�mero de nodos que se van a crear.
//		valor, valor com�n que se copiar� en las casillas.
// Devuelve: un dato de tipo Lista.
//
// PRE: num_nodos >= 0
// NOTA: Si num_nodos==0 la lista queda vac�a.

Lista CreaLista (int num_nodos=0, TipoBase valor=VALOR_DEF);

// Con el generador de numeros aleatorios
Lista CreaListaAleatoria (int num_nodos=0, int min=0, int max=100);


// "Destruye" una lista y la deja en un estado no �til (vac�a).
// La funcionalidad ser�a similar a la de un destructor.
// Par�metros:
//		l (referencia), la lista que va a "destruirse".
// POST: La matriz queda vac�a (todos sus campos a cero)

void DestruyeLista (Lista & l);

// Devuelve el n�mero de nodos de una lista
// Par�metros:
//		l (referencia), la lista que va a procesarse.
// Devuelve: n�mero de nodos de la lista

int NumElementos (const Lista & l);

// Consulta si una lista est� vac�a (sin nodos)
// Par�metros:
//		l (referencia), la lista que va a procesar.
// Devuelve: true, si la lista est� vac�a

bool EstaVacia (const Lista & l);

// Devuelve un string con el resultado de ``serializar'' una lista.
// Par�metros:
//		l (referencia), la lista que va a procesar.

string ToString (const Lista & l);

// Consulta � modifica el valor de un nodo dado por su posici�n.
// Si se utiliza como rvalue se emplea para consulta. Si se utiliza como
// lvalue se emplea para modificaci�n.
//
// PRE: 1<=pos<int NumElementos (l)

TipoBase & Valor (const Lista & l, int pos);

// Elimina todos los valores.
// Al finalizar, NumElementos(l)==0 EstaVacia(l)==true.
// La lista, aunque vac�a, sigue ``activa''.

void  EliminaTodos (Lista & l);

// A�ade (al final de la lista) un nodo con el valor indicado en "valor".
//
// Par�metros:
// 		l (referencia), lista resultante.
//		valor, el valor que se a�ade a la lista "l"

void Aniade (Lista & l, TipoBase valor);

// Comprueba si una lista est� ordenada.
// Par�metros:
//	l (referencia) lista a comprobar
// Devuelve: true, si la lista est� ordenada

bool EstaOrdenada (const Lista l);

// Ordena una lista (algoritmo de seleccion).
// Par�metros:
//	l (referencia) lista a ordenar.

void OrdenaSeleccion (Lista & l);
// Ordena una lista (algoritmo Bubble Sort o intercambio)
void OrdenaIntercambio (Lista & l);
// Ordena una lista por el algoritmo de insercion
void OrdenaInsercion(Lista & l);

// Accede a todos los datos de la lista y los iguala al valor indicado
// Param:
// l (referencia de lista)
// valor (valor en TipoBase *Double) o por defecto
void Ecualiza (Lista & l, TipoBase valor = VALOR_DEF);

// Comprueba si la lista esta vacia
// Param:
// l const ref

bool EstaVacia (const Lista & l);

// Clona una matriz en otra
// Param:
// destino -> matriz que recibe la clonacion
// origen -> matriz de origen registrada como constante

void Clona (Lista & destino, const Lista & origen);

// Comprobacion de dos Listas SonIguales
// Param
// una -> una lista
// otra -> otra lista

bool SonIguales (const Lista & una, const Lista & otra);

// Realizacion de una sublista
// Param
// resultado -> destino de la sublista
// original -> origen de la lista
// pos_inic -> posicion inicial *contando desde 1 no desde 0
// num_nodos -> numero de nodos de la lista resultado
void Sublista (Lista & resultado, const Lista & original, int pos_inic,
	int num_nodos);

// Relleno de listas con numeros aleatorios
// Param
// l -> lista
// min -> minimo entero generador aleatorio
// max -> maximo entero generador aleatorio
void RellenaAleatoriamente (Lista & l, int min, int max);


// Realizado para el ejercicio 18
// Elimina un nodo
// Param
// l -> lista
// pos -> posicion
void Elimina (Lista & l, int pos);

// Inserta un nodo
// Param
// l -> lista
// pos -> posicion
// Si pos > num_nodos lista -> se hace un Aniade

void Inserta (Lista & l, TipoBase valor, int pos);

// Invierte una lista
// Param
// l -> lista

void Invierte (Lista & l);
#endif
