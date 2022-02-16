#ifndef JEFE_H_INCLUDED
#define JEFE_H_INCLUDED


#include "FuncionesGlobales.h"


class Jefe{

    //LOS DISPAROS DEBEN SER EL CARACTER 4(DIAMANTE).
    int x,y;
    int dx;

public:

    Jefe(int _x,int _y,int _dx):x(_x),y(_y),dx(_dx){}
    void dibujar();
    void borrar();
    void mover();

};


void Jefe::dibujar(){

      //SIMPLEMENTE PARA USAR DE MOLDE EL DIBUJO DE LA NAVE.
      /*
      gotoxy(x,y);  printf("  %c",30); //IMPRIME EN PANTALLA EL CARACTER CORRESPONDIENTE AL NUMERO 30 EN ascii.
      gotoxy(x,y+1); printf(" %c%c%c",40,207,41);  //y+1 DICE QUE NOS DESPLAZAMOS 1 UNIDAD HACIA ABAJO EN EL EJE y.
      gotoxy(x,y+2); printf("%c%c %c%c",30,190,190,30);
      */

      //LIMITE SUPERIOR DE LA NAVE.
      for (int i = 0;i < 24;i++){

         gotoxy(x+i,y); printf("%c",196);
      }

      //BORDES REDONDEADOS.
      gotoxy(SCREEN_WIDTH/2 - 15,y + 1); printf("%c",40);
      gotoxy(SCREEN_WIDTH/2 + 14,y + 1); printf("%c",41);

      //TURBINAS
      gotoxy(SCREEN_WIDTH/2 - 7,y - 1); printf("%c",30);
      gotoxy(SCREEN_WIDTH/2 + 6,y - 1); printf("%c",30);

      //LIMITE INFERIOR DE LA NAVE.
      for (int i = 0;i < 24;i++){

         gotoxy(x+i,y + 2); printf("%c",196);
      }

      //SIMBOLOS DE LAS ALAS.
      gotoxy(SCREEN_WIDTH/2 - 9,y + 1); printf("%c",174);
      gotoxy(SCREEN_WIDTH/2 + 9,y + 1); printf("%c",175);

      //CABINA.
      gotoxy(SCREEN_WIDTH/2,y + 1); printf("%c",3);


      //CAÑON IZQUIERDO.

      for (int i = 0;i < 3;i++){

         gotoxy(SCREEN_WIDTH/2 - 7,y + 3 + i); printf("%c",179);
      }

      for (int i = 0;i < 3;i++){

         gotoxy(SCREEN_WIDTH/2 - 6,y + 3 + i); printf("%c",179);
      }

      //CAÑON DERECHO.

      for (int i = 0;i < 3;i++){

         gotoxy(SCREEN_WIDTH/2 + 7,y + 3 + i); printf("%c",179);
      }

      for (int i = 0;i < 3;i++){

         gotoxy(SCREEN_WIDTH/2 + 6,y + 3 + i); printf("%c",179);
      }
}


void Jefe::borrar(){

      //LIMITE SUPERIOR DE LA NAVE.
      for (int i = 0;i < 24;i++){

         gotoxy(x+i,y); printf(" ");
      }

      //BORDES REDONDEADOS.
      gotoxy(SCREEN_WIDTH/2 - 15,y + 1); printf(" ");
      gotoxy(SCREEN_WIDTH/2 + 14,y + 1); printf(" ");

      //TURBINAS
      gotoxy(SCREEN_WIDTH/2 - 7,y - 1); printf(" ");
      gotoxy(SCREEN_WIDTH/2 + 6,y - 1); printf(" ");

      //LIMITE INFERIOR DE LA NAVE.
      for (int i = 0;i < 24;i++){

         gotoxy(x+i,y + 2); printf(" ");
      }

      //SIMBOLOS DE LAS ALAS.
      gotoxy(SCREEN_WIDTH/2 - 9,y + 1); printf(" ");
      gotoxy(SCREEN_WIDTH/2 + 9,y + 1); printf(" ");

      //CABINA.
      gotoxy(SCREEN_WIDTH/2,y + 1); printf(" ");


      //CAÑON IZQUIERDO.

      for (int i = 0;i < 3;i++){

         gotoxy(SCREEN_WIDTH/2 - 7,y + 3 + i); printf(" ");
      }

      for (int i = 0;i < 3;i++){

         gotoxy(SCREEN_WIDTH/2 - 6,y + 3 + i); printf(" ");
      }

      //CAÑON DERECHO.

      for (int i = 0;i < 3;i++){

         gotoxy(SCREEN_WIDTH/2 + 7,y + 3 + i); printf(" ");
      }

      for (int i = 0;i < 3;i++){

         gotoxy(SCREEN_WIDTH/2 + 6,y + 3 + i); printf(" ");
      }
}



void Jefe::mover(){

     borrar();

     x+=dx; //IGUAL SE ROMPE, PROBAR DE DIBUJAR SIN LOS for AL JEFE.

     if(y >= 4 && y <= SCREEN_HEIGHT/2 - 9){  //CUANDO APARECE SE MUEVE HACIA ABAJO.

        y++;
     }
     /*
     else{

         if(y <= SCREEN_HEIGHT/2 - 5 && y > SCREEN_HEIGHT/2 - 10) y--;  //COMO HAGO PARA QUE SUBA????

     }
     */
     //if(y >= SCREEN_HEIGHT/2 - 9) x++; //SI HAGO ESO SE ROMPE UNA PARTE DEL BOSS. INTERESANTE.


     dibujar();
}


#endif // JEFE_H_INCLUDED
