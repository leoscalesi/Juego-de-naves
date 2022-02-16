#ifndef OVNI_H_INCLUDED
#define OVNI_H_INCLUDED

#include "FuncionesGlobales.h"
#include "Nave.h"


class Ovni{


      int x,y;

    public:

      Ovni(int _x,int _y):x(_x),y(_y){}
      int X(){return x;}
      int Y(){return y;}
      void dibujar();
      void borrar();
      void mover();
      bool detectaLimiteDerecho();

      bool colisionNave(Nave&);

};


void Ovni::dibujar(){    //MEJORAR CON UN for.

     //VENTANAS.

     gotoxy(x,y), printf("%c",169);
     gotoxy(x + 2,y), printf("%c",169);
     gotoxy(x + 4,y), printf("%c",169);

     //LIMITES VENTANAS.

     gotoxy(x,y + 1), printf("%c",196);
     gotoxy(x,y - 1), printf("%c",196);
     gotoxy(x + 1,y + 1), printf("%c",196);
     gotoxy(x + 1,y - 1), printf("%c",196);
     gotoxy(x + 2,y + 1), printf("%c",196);
     gotoxy(x + 2,y - 1), printf("%c",196);
     gotoxy(x + 3,y + 1), printf("%c",196);
     gotoxy(x + 3,y - 1), printf("%c",196);
     gotoxy(x + 4,y + 1), printf("%c",196);
     gotoxy(x + 4,y - 1), printf("%c",196);

     //ESQUINAS SUPERIORES.

     gotoxy(x - 1,y - 1), printf("%c",218);
     gotoxy(x + 5,y - 1), printf("%c",191);

     //ESQUINAS INFERIORES.

     gotoxy(x - 1,y + 1), printf("%c",192);
     gotoxy(x + 5,y + 1), printf("%c",217);

}


void Ovni::borrar(){

     //VENTANAS.

     gotoxy(x,y), printf(" ");
     gotoxy(x + 2,y), printf(" ");
     gotoxy(x + 4,y), printf(" ");

     //LIMITES VENTANAS.

     gotoxy(x,y + 1), printf(" ");
     gotoxy(x,y - 1), printf(" ");
     gotoxy(x + 1,y + 1), printf(" ");
     gotoxy(x + 1,y - 1), printf(" ");
     gotoxy(x + 2,y + 1), printf(" ");
     gotoxy(x + 2,y - 1), printf(" ");
     gotoxy(x + 3,y + 1), printf(" ");
     gotoxy(x + 3,y - 1), printf(" ");
     gotoxy(x + 4,y + 1), printf(" ");
     gotoxy(x + 4,y - 1), printf(" ");

     //ESQUINAS SUPERIORES.

     gotoxy(x - 1,y - 1), printf(" ");
     gotoxy(x + 5,y - 1), printf(" ");

     //ESQUINAS INFERIORES.

     gotoxy(x - 1,y + 1), printf(" ");
     gotoxy(x + 5,y + 1), printf(" ");

}


 void Ovni::mover(){

     borrar();

     x++;

     dibujar();

}


bool Ovni::detectaLimiteDerecho(){

    if(x + 6 == SCREEN_WIDTH){

        return true;
    }

    return false;

}


bool Ovni::colisionNave(Nave& nave){

     if(x + 4 == nave.X() - 1 && (y == nave.Y() || y == nave.Y() - 1 || y == nave.Y() + 1 || y == nave.Y() + 2 || y == nave.Y() - 2)) {  // SI ACA SOLO PROGRAMO EN x LA COLISION SE DETECTA UNA COLISION FALSA.
     //CONTINUAR CON LAS CONDICIONES. ASI COMO ESTA SOLO DETECTA LA COLISION CONTRA EL LADO IZQUIERDO DE LA NAVE. HACERLO CON MAYOR IGUAL O MENOR IGUAL.

        Beep(400,100);
        Sleep(500);
        nave.pintar();  //VA? PARA QUE NO SE BORRE LA NAVE?

        nave.restarCorazones();
        //Sleep(1000);
        return true;
     }

     return false;
}



#endif // OVNI_H_INCLUDED
