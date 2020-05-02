#include "Matriz2D.h"
#include "Secuencia.h"

using namespace std;

int main(){
  int entrada_switch, fils, cols, valor_defecto, fils_sub, cols_sub, indice;
  TipoBaseMatriz cambiar_valor, valor_entrada;
  TipoBaseSecuencia int_input;
  char input;

  bool salir_main = false;
  bool vacia, flag_f, flag_i, salida;

  bool check_filas, check_columnas, run;

  Matriz2D * matriz_main = new Matriz2D(2);
  Matriz2D * matriz_clonar = new Matriz2D();

  Secuencia * secuencia_main = new Secuencia();

  vacia = matriz_main -> EstaVacia();

  cout << "Bienvenido al programa de Demo de Matriz2D\n";
  cout << "Por defecto se crea una matriz cuadrada\n";
  while (!salir_main) {
    cout << "Introduzca una opcion\n"
         << "1.  Crea una matriz2D\n"
         << "2.  Modificar una posicion de la matriz\n"
         << "3.  Clona la matriz\n"
         << "4.  Verificacion de matrices iguales\n"
         << "5.  SubMatriz\n"
         << "6.  Aniade Fila\n"
         << "7.  Inserta Fila\n"
         << "8   Secuencia Fila\n"
         << "9   Secuencia Columna\n"
         << "8.  Elimina fila\n"
         << "9.  Elimina columna\n"
         << "0. Salir\n";

    if (!vacia){
      cout << "\nEstado de la matriz\n"
           << "-------------------------------------------------------------\n"
           << matriz_main -> ToString()
           << "-------------------------------------------------------------\n"
           << "Command: ";
    } else {
      cout << "-------------------------------------------------------------\n"
      << "Command: ";
    }

    cin >> entrada_switch;
    switch(entrada_switch){
      case 1:
        cout << "El valor de filas y columnas debe estar por encima de 0\n";
        cout << "En caso de dejar el numero 0 no podras hacer nada\n";
        cout << "Introduzca el numero de filas\n";
        cin >> fils;
        cout << "Introduzca el numero de columnas\n";
        cin >> cols;
        cout << "Introduzca el valor por defecto\n";
        cin >> valor_defecto;

        if (matriz_main -> EstaVacia()){
          matriz_main = new Matriz2D(fils, cols, valor_defecto);
        }
        else {
          delete matriz_main; // Llama al destructor
          matriz_main = new Matriz2D(fils, cols, valor_defecto);
        }
        vacia = matriz_main -> EstaVacia();

      break;

      case 2:
        cout << "Introduzca el numero de filas\n";
        cin >> fils;
        cout << "Introduzca el numero de columnas\n";
        cin >> cols;
        cout << "Introduzca el valor a cambiar\n";
        cin >> cambiar_valor;


        check_filas = fils >= 0 && fils <= matriz_main -> NumFilas();
        check_columnas = cols >= 0 && cols <= matriz_main -> NumColumnas();

        // Tambien comprobamos que no este vacia si lo esta da una condicion
        // false
        run = check_filas && check_columnas && !matriz_main -> EstaVacia();

        if (run){
            matriz_main -> Valor (fils, cols) = cambiar_valor;
        }
        else if (matriz_main -> EstaVacia()){
          cout << "\nLa matriz esta vacia!!\n";
        }
        else {
          cout << "\nError de acceso a filas y columnas no permitidas!!\n";
        }

      break;

      case 3:
        // Se comprueba si el origen esta vacio, porque de lo contrario, no
        // tiene sentido ejecutar la funcion de clonacion
        if(!matriz_main -> EstaVacia()){
          delete matriz_clonar;
          matriz_clonar = new Matriz2D (*matriz_main);
        }
        else {
          cout << "La matriz de origen no ha sido creada!\n";
        }
      break;

      case 4:
        if (!matriz_main -> EstaVacia() && !matriz_clonar -> EstaVacia()){
          if(matriz_main -> SonIguales(*matriz_clonar)){
            cout << "\nSon iguales\n";
            cout << "Mostrando...\n"
            << "-----------------------Matriz 1------------------------------\n"
            << matriz_main -> ToString() << endl
            << "-----------------------Matriz 2------------------------------\n"
            << matriz_clonar -> ToString() << endl;
          }
          else {
            cout << "\nNo son iguales\n"
             << "Mostrando...\n"
             << "-----------------------Matriz 1------------------------------\n"
             << matriz_main -> ToString() << endl
             << "-----------------------Matriz 2------------------------------\n"
             << matriz_clonar -> ToString() << endl;
          }
        }
        else {
          cout << "La matriz principal no ha sido creada\n"
               << "o la matriz de clonacion no ha sido clonada\n";
        }
      break;

      case 5:
      if (!matriz_main -> EstaVacia()){
        cout << "Introduzca el numero de filas desde donde quieres copiar\n";
        cin >> fils;
        cout << "Introduzca el numero de columnas desde donde quieres copiar\n";
        cin >> cols;
        cout << "Introduzca el numero de filas de la submatriz\n";
        cin >> fils_sub;
        cout << "Introduzca el numero de columnas de la submatriz\n";
        cin >> cols_sub;

        delete matriz_clonar;

        // Lo cargo con el Constructor de copia para que pueda manipular
        // el objeto en tiempo de ejecucion
        matriz_clonar = \
        new Matriz2D(matriz_main -> SubMatriz (fils, cols, fils_sub, cols_sub));

        if (matriz_clonar -> EstaVacia()){
          cout << "Has superado los limites de la matriz original\n";
        }
        else {
          cout << "\nSubmatriz\n";
          cout << "Mostrando...\n"
          << "-----------------------Matriz 1------------------------------\n"
          << matriz_main -> ToString() << endl
          << "-----------------------Matriz 2------------------------------\n"
          << matriz_clonar -> ToString() << endl;
        }
      }
      else {
        cout << "La matriz principal no ha sido creada\n";
      }
      break;

      case 6:
        if (!matriz_main -> EstaVacia()){
            // Verificamos el estado de la secuencia

            if (!secuencia_main -> EstaVacia()){
                delete secuencia_main;
                secuencia_main = new Secuencia(matriz_main -> NumColumnas());
            }
            else {
                secuencia_main = new Secuencia(matriz_main -> NumColumnas());
            }
            // Recogemos los datos para la secuencia
            cout << "Introduzca los datos. Para salir escriba FIN:\n";
            salida = false;
            do {
                cin >> input;

                // Primero comprobamos que se escriba FIN o fin en su defecto
                if (input == 'F' || input == 'f'){
                  flag_f = true;
                }
                else if (input == 'I' || input == 'i' && flag_f){
                  flag_i = true;
                }
                else if (input == 'N' || input == 'n' && flag_i && flag_f){
                  salida = true;
                }
                else {
                    // En el caso falso se hace la comprobacion de precondiciones
                    flag_f = flag_i = false;
                    int_input = input - '0';

                    //Comprobamos que no sobrepase la capacidad
                    if (secuencia_main -> TotalUtilizados() <
                            secuencia_main -> Capacidad()){
                                    secuencia_main -> Aniade(int_input);
                    }
                    else {
                        salida = true; // Si la sobrepasa salimos
                    }
                }

            } while (!salida);

            cout << "Datos introducidos:\n"
                 <<secuencia_main -> ToString();

            matriz_main -> Aniade (*secuencia_main);
        }
        else {
            cout << "No has creado la Matriz del main!!\n";
        }

      break;

      case 7:
      if (!matriz_main -> EstaVacia()){
          // Verificamos el estado de la secuencia

          if (!secuencia_main -> EstaVacia()){
              delete secuencia_main;
              secuencia_main = new Secuencia(matriz_main -> NumColumnas());
          }
          else {
              secuencia_main = new Secuencia(matriz_main -> NumColumnas());
          }
          // Recogemos los datos para la secuencia
          cout << "Introduzca los datos. Para salir escriba FIN:\n";
          salida = false;
          do {
              cin >> input;

              // Primero comprobamos que se escriba FIN o fin en su defecto
              if (input == 'F' || input == 'f'){
                flag_f = true;
              }
              else if (input == 'I' || input == 'i' && flag_f){
                flag_i = true;
              }
              else if (input == 'N' || input == 'n' && flag_i && flag_f){
                salida = true;
              }
              else {
                  // En el caso falso se hace la comprobacion de precondiciones
                  flag_f = flag_i = false;
                  int_input = input - '0';

                  //Comprobamos que no sobrepase la capacidad
                  if (secuencia_main -> TotalUtilizados() <
                          secuencia_main -> Capacidad()){
                                  secuencia_main -> Aniade(int_input);
                  }
                  else {
                      salida = true; // Si la sobrepasa salimos
                  }
              }

          } while (!salida);

          cout << "Datos introducidos:\n"
               <<secuencia_main -> ToString();
          cout << "Introduzca ahora la fila donde quieras insertar la secuencia"
              << endl;

          cin >> indice;
          matriz_main -> Inserta (indice, *secuencia_main);
      }
      else {
          cout << "No has creado la Matriz del main!!\n";
      }
      break;

      case 8:
          if (!matriz_main -> EstaVacia()){
            cout << "Elige la fila para poner en la secuencia\n";
            cin >> fils;

            if (!secuencia_main -> EstaVacia()){
                delete secuencia_main;
            }

            secuencia_main = new Secuencia(matriz_main -> Fila(fils));

            cout << "Estado de la secuencia nueva\n"
                 << "Valores de la secuencia: "
                 << secuencia_main -> TotalUtilizados() << endl
                 << secuencia_main -> ToString() << endl;
          }
          else {
              cout << "No has creado la Matriz del main!!\n";
          }
     break;

     case 9:
         if (!matriz_main -> EstaVacia()){
           cout << "Elige la columna para poner en la secuencia\n";
           cin >> cols;

           if (!secuencia_main -> EstaVacia()){
               delete secuencia_main;
           }

           secuencia_main = new Secuencia(matriz_main -> Fila(cols));

           cout << "Estado de la secuencia nueva\n"
                << "Valores de la secuencia: "
                << secuencia_main -> TotalUtilizados() << endl
                << secuencia_main -> ToString() << endl;
         }
         else {
             cout << "No has creado la Matriz del main!!\n";
         }
    break;

      case 10:
        if (!matriz_main -> EstaVacia()){
          cout << "Elige la fila a borrar\n";
          cin >> fils;

          matriz_main -> EliminaFila(fils);
        }
      break;

      case 11:
        if (!matriz_main -> EstaVacia()){
          cout << "Elige la fila a borrar\n";
          cin >> cols;

          matriz_main -> EliminaColumna(cols);
        }

      case 0:
        // El Destructor se carga por defecto
        cout << "Bye!";
        return 0;
       break;
    } // End switch
  } // End while
} // End main
