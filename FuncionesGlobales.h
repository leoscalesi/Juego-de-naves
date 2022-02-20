#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

#include <windows.h>
#include <fstream>  //PARA EL MANEJO DE ARCHIVOS.
#include "rlutil.h"


//CONSTANTES PARA QUE NO ROMPA FRENTE A DISTINTOS TAMAÑOS DE MONITORES.
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 36
#define WIN_WIDTH 70


//FUNCION QUE OCULTA EL CURSOR QUE APARECE AL LADO DE LA NAVE.
void ocultarCursor(){

      HANDLE hCon;    //MANIPULAMOS LA CONSOLA.
      hCon = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_CURSOR_INFO  cci;   //ESTRUCTURA QUE MANEJA LA APARIENCIA DEL CURSOR.
      cci.dwSize = 2;             //TAMAÑO DEL CURSOR.
      cci.bVisible = FALSE;       //PARA QUE NO SE MUESTRE EN PANTALLA.

      SetConsoleCursorInfo(hCon,&cci);    //PASAMOS cci POR REFERENCIA PORQUE VAMOS A MODIFICAR LOS DATOS.
}


//Funcion incluida en rlutil.h, y en conio.h, sin embargo
//a modo de practica la creamos de 0.



//AL INCLUIR LA LIBRERIA rlutil.h NO ES NECESARIO CREAR EL METODO gotoxy(), YA QUE ESTA LIBRERIA LO INCLUYE.
/*
void gotoxy(int x,int y){

      HANDLE hCon;    //MANIPULAMOS LA CONSOLA.
      hCon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;    //DECLARAMOS UN OBJETO DE TIPO COORDENADAS.
      dwPos.X = x;    //SETEAMOS LAS COORDENADAS.
      dwPos.Y = y;

      SetConsoleCursorPosition(hCon, dwPos);   //UBICAMOS EN LA CONSOLA LAS COORDENADAS.
}
*/

//FUNCION QUE DIBUJA LOS LIMITES EN PANTALLA.

/* //ANTIGUA FUNCION PARA DIBUJAR LIMITES, ANTES DE USAR LAS MACROS DE ANCHO Y ALTURA DE PANTALLA.
void pintarLimites(){

      for(int x = 2;x<194;x++){
        gotoxy(x,3);printf("%c",205);   //DEJO FIJO y Y AUMENTO DE A UNO EN x EN LA PARTE SUPERIOR.
        gotoxy(x,45);printf("%c",205);   //DEJO FIJO y Y AUMENTO DE A UNO EN x EN LA PARTE INFERIOR.
      }

       for(int y = 4;y<45;y++){
        gotoxy(2,y);printf("%c",186);   //DEJO FIJO x Y AUMENTO DE A UNO EN y A LA IZQUIERDA.
        gotoxy(194,y);printf("%c",186);   //DEJO FIJO x Y AUMENTO DE A UNO EN y A LA DERECHA.
      }

    //AHORA PINTAMOS LAS ESQUINAS

    gotoxy(2,3); printf("%c",201);   //ESQUINA SUPERIOR IZQUIERDA.
    gotoxy(2,45); printf("%c",200);   //ESQUINA INFERIOR IZQUIERDA.
    gotoxy(194,3); printf("%c",187);   //ESQUINA SUPERIOR DERECHA.
    gotoxy(194,45); printf("%c",188);   //ESQUINA INFERIOR DERECHA.
}

*/

int leerPuntajeArchivo(){

     //ABRO EL ARCHIVO CON UN OBJETO ifstream, GUARDANDO DICHO CONTENIDO EN UNA VARIABLE DEL TIPO ADECUADO.
     int puntajemaximo;
     ifstream archivo;
     archivo.open("PuntajeMaximo.txt");
     if(!archivo.is_open()){

        cout << "Error al leer el archivo";
        Sleep(2000);
        system("cls");
        return -1;
     }
     //CON EL OPERADOR DE EXTRACCION >> LEO EL CONTENIDO  Y LO GUARDO EN LA VARIABLE.
     archivo >> puntajemaximo;

     return puntajemaximo;
     archivo.close();
}

//p ES EL NUEVO MAXIMO
void guardarPuntajeArchivo(int p){

     ofstream archivo;
     archivo.open("PuntajeMaximo.txt");
     if(!archivo.is_open()){

        cout << "Error al leer el archivo";
        Sleep(2000);
        system("cls");
        return;
     }

     archivo << p;
     //EL flush SE HACE SOLAMENTE CON LOS ARCHIVOS DE SALIDA (ESCRITURA DE ARCHIVOS).
     archivo.flush();
     archivo.close();

}

void verMaximaPuntuacion(){

     int puntajemaximo = leerPuntajeArchivo();

     cout << "LA PUNTUACION MAS ALTA ES: " << puntajemaximo;

     Sleep(2000);
     system("cls");

}

void pintarLimites(){

     for(int x = 8 ; x < SCREEN_WIDTH;x++){
        gotoxy(x,3);printf("%c",205);   //DEJO FIJO y Y AUMENTO DE A UNO EN x EN LA PARTE SUPERIOR.
        gotoxy(x, SCREEN_HEIGHT - 4);printf("%c",205);   //DEJO FIJO y Y AUMENTO DE A UNO EN x EN LA PARTE INFERIOR.

      }

      for(int y = 4;y < SCREEN_HEIGHT - 4;y++){
        gotoxy(8,y);printf("%c",186);   //DEJO FIJO x Y AUMENTO DE A UNO EN y A LA IZQUIERDA.
        gotoxy(SCREEN_WIDTH,y);printf("%c",186);   //DEJO FIJO x Y AUMENTO DE A UNO EN y A LA DERECHA.
      }

       //AHORA PINTAMOS LAS ESQUINAS

      gotoxy(8,3); printf("%c",201);   //ESQUINA SUPERIOR IZQUIERDA.
      gotoxy(8,SCREEN_HEIGHT - 4); printf("%c",200);   //ESQUINA INFERIOR IZQUIERDA.
      gotoxy(SCREEN_WIDTH,3); printf("%c",187);   //ESQUINA SUPERIOR DERECHA.
      gotoxy(SCREEN_WIDTH,SCREEN_HEIGHT - 4); printf("%c",188);   //ESQUINA INFERIOR DERECHA.

}


void melodiaListoParaJugar(){

    Beep(1568,100);
    Beep(1568,100);
    Beep(1568,100);
    Beep(1245,500);
    Beep(1397,200);
    Beep(1397,200);
    Beep(1397,200);
    Beep(1175,500);

}


void pintarListoParaJugar(){

     gotoxy(SCREEN_WIDTH/2,SCREEN_HEIGHT/2); printf("Listo?");
     melodiaListoParaJugar();
     Sleep(200);
     gotoxy(SCREEN_WIDTH/2,SCREEN_HEIGHT/2); printf("      ");
     Sleep(100);
}


void melodiaJuegoTerminado(){

      Beep(400,200);
      Sleep(500);
      Beep(300,200);
      Sleep(500);
      Beep(200,1000);
}






#endif // FUNCIONESGLOBALES_H_INCLUDED
