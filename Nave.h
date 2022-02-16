#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED

#include <conio.h>    //AQUI SE ENCUENTRA kbhit()
#include "FuncionesGlobales.h"

//MACROS QUE DEFINEN QUE NUMERO LE CORRESPONDE A CADA TECLA

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


class Nave{

      int x,y;   //LO CORRECTO ES QUE LAS COORDENADAS SEAN DE TIPO float.
      int corazones;
      int vidas;

   public:

      Nave(int _x,int _y,int _corazones,int _vidas);
      int X(){ return x;}   //PARA ACCEDER A ESTOS ATRIBUTOS DESDE EL ASTEROIDE.
      int Y(){ return y;}
      int VIDAS() { return vidas;}
      void restarCorazones() {corazones --;}
      void pintar();
      void borrar();
      void mover();
      void pintarCorazones();
      void morir();

};


Nave::Nave(int _x,int _y,int _corazones,int _vidas): x(_x),y(_y),corazones(_corazones),vidas(_vidas){}  //OTRA FORMA DE ASIGNAR VALORES A LOS CONSTRUCTORES.


void Nave::pintar(){

      //DIBUJAMOS LA NAVE EN 3 LINEAS.
      gotoxy(x,y);  printf("  %c",30); //IMPRIME EN PANTALLA EL CARACTER CORRESPONDIENTE AL NUMERO 30 EN ascii.
      gotoxy(x,y+1); printf(" %c%c%c",40,207,41);  //y+1 DICE QUE NOS DESPLAZAMOS 1 UNIDAD HACIA ABAJO EN EL EJE y.
      gotoxy(x,y+2); printf("%c%c %c%c",30,190,190,30);

}


void Nave::borrar(){

       gotoxy(x,y);printf("         ");  //PONGO TANTOS CARACTERES EN BLANCO NECESITE PARA CUBRIR EL ANCHO QUE QUIERO BORRAR(EL ANCHO DE LA NAVE).
       gotoxy(x,y+1);printf("         ");
       gotoxy(x,y+2);printf("         ");
}


void Nave::mover(){

      if(kbhit()){   //DETECTA SI SE PRESIONO ALGUNA TECLA CUALQUIERA DEL TECLADO.

            char tecla = getch();   //ME DICE Y GUARDA QUE TECLA SE PRESIONO.
            borrar();
            if(tecla == IZQUIERDA && x > 9) x--;//CON LA FUNCION PINTAR LIMITES YA ARMADA, PUEDO AGREGAR EN LOS CONDICIONALES QUE NO SE PASE DE ESOS LIMITES.
            if(tecla == DERECHA && x + 9 < SCREEN_WIDTH  ) x++;//x+6 PORQUE SE REFIERE AL ANCHO DE LA NAVE.
            if(tecla == ARRIBA && y > 4) y--;
            if(tecla == ABAJO && y + 7 < SCREEN_HEIGHT) y++;    //y+3 PORQUE SE REFIERE AL ALTO DE LA NAVE.

            //TESTEO QUE SE RESTEN EFECTIVAMENTE LOS CORAZONES FRENTE A UN EVENTO (EN ESTE CASO AL PRESIONAR LA TECLA E).
            if(tecla == 'e')corazones--;

            pintar();
            pintarCorazones();
      }
}

 void Nave::pintarCorazones(){

      gotoxy(60,2); printf("Vidas %d",vidas);
      gotoxy(70,2); printf("Salud");  //MUESTRO EN ESTA POSICION LA PALABRA Salud.
      gotoxy(80,2); printf("      ");

      for(int i=0;i < corazones;i++){   //IMPRIMO 3 CORAZONES (SU CANTIDAD VENDRA DEFINIDA EN EL CONSTRUCTOR DE LA NAVE).

        gotoxy(80+i,2); printf("%c",3);
      }
}


void Nave::morir(){

     if(corazones == 0){
        //PRIMERO BORRO LA NAVE.
        borrar();
        //ANIMACION QUE REPRESENTA LA EXPLOSION DE LA NAVE.
        gotoxy(x,y); printf("   **   ");
        gotoxy(x,y+1); printf("  ****  ");
        gotoxy(x,y+2); printf("   **   ");
        Sleep(200);

        borrar(); //AHORA DEBE BORRAR LA ANIMACION DE LA EXPLOSION.

        gotoxy(x,y); printf(" * ** *");
        gotoxy(x,y+1); printf("  ****  ");
        gotoxy(x,y+2); printf(" * ** *");
        Sleep(200);

        borrar();  //AHORA DEBE BORRAR LA OTRA ANIMACION DE LA EXPLOSION.

        vidas--;    //PERDIO UNA VIDA.
        corazones = 3;   //RESETEO LOS CORAZONES A 3 NUEVAMENTE.
        pintarCorazones();
        pintar();        //DIBUJO NUEVAMENTE LA NAVE.

     }

}


#endif // NAVE_H_INCLUDED
