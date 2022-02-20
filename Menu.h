#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <cstdlib>
#include "FuncionesGlobales.h"
#include "Juego.h"


class Menu{

  public:

    //LA CLASE MENU NO NECESITA CONSERVAR NINGUN ESTADO INTERNO, DE MANERA QUE NO NECESITO INSTANCIAR OBJETOS DE DICHA CLASE, POR ESO USO static SUS METODOS.
    static void mostrar();

};


void Menu::mostrar(){

    bool salir=0;
    int opc;

    while(salir==0){

      cout << " ---------------------------- " << endl;
      cout << " MENU PRINCIPAL " << endl << endl;
      cout << endl << endl << endl << endl << endl;
      cout << " 1 - MODO INFINITO " << endl;
      cout << " 2 - DERROTA AL JEFE " << endl;
      cout << " 3 - VER MAXIMA PUNTUACION " << endl;
      cout  << endl << endl;
      cout << " 0 - SALIR DEL PROGRAMA " << endl << endl << endl;
      cout << " ---------------------------- " << endl;
      cout << " INGRESE OPCION: ";
      cin >> opc;

      system("cls");

      switch(opc){

      case 1:
      case 2:

        Juego::jugar(opc);

      break;

      case 3:

        verMaximaPuntuacion();   //FUNCION GLOBAL (PROBAR DE HACER EL MANEJO DE ARCHIVOS CON fstream).

      break;

      case 0:

        salir=1;

      break;

      }
    }
}



#endif // MENU_H_INCLUDED
