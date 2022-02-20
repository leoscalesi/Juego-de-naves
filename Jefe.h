#ifndef JEFE_H_INCLUDED
#define JEFE_H_INCLUDED


#include "FuncionesGlobales.h"


class Jefe{

    //LOS DISPAROS DEBEN SER EL CARACTER 4(DIAMANTE).
    int x,y;
    int dx;

public:

    Jefe(int _x,int _y,int _dx):x(_x),y(_y),dx(_dx){}
    int X(){return x;}
    int Y(){return y;}
    void dibujar();
    void borrar();
    void mover();
    void morir();
    void mensajeJefeDerrotado();

};


void Jefe::dibujar(){

      //CUERPO
     gotoxy(x,y);printf("%c",4);

     gotoxy(x - 1,y + 1);printf("%c",4);
     gotoxy(x + 1,y + 1);printf("%c",4);

     gotoxy(x - 2,y + 2);printf("%c",4);
     gotoxy(x - 1,y + 2);printf("%c",4);
     gotoxy(x + 1,y + 2);printf("%c",4);
     gotoxy(x + 2,y + 2);printf("%c",4);

     gotoxy(x - 3,y + 3);printf("%c",4);
     gotoxy(x - 2,y + 3);printf("%c",4);
     gotoxy(x + 2,y + 3);printf("%c",4);
     gotoxy(x + 3,y + 3);printf("%c",4);

     gotoxy(x - 4,y + 4);printf("%c",4);
     gotoxy(x - 3,y + 4);printf("%c",4);
     gotoxy(x + 3,y + 4);printf("%c",4);
     gotoxy(x + 4,y + 4);printf("%c",4);

     //OJOS
     gotoxy(x - 2,y + 5);printf("%c",169);
     gotoxy(x + 2,y + 5);printf("%c",169);

     //TENTACULOS

     gotoxy(x - 2,y + 6);printf("%c",41);
     gotoxy(x - 3,y + 7);printf("%c",40);
     gotoxy(x - 2,y + 8);printf("%c",41);
     gotoxy(x - 3,y + 9);printf("%c",40);
     gotoxy(x - 2,y + 10);printf("%c",41);
     gotoxy(x - 3,y + 11);printf("%c",40);

     gotoxy(x + 2,y + 6);printf("%c",41);
     gotoxy(x + 3,y + 7);printf("%c",40);
     gotoxy(x + 2,y + 8);printf("%c",41);
     gotoxy(x + 3,y + 9);printf("%c",40);
     gotoxy(x + 2,y + 10);printf("%c",41);
     gotoxy(x + 3,y + 11);printf("%c",40);

     gotoxy(x - 3,y + 6);printf("%c",41);
     gotoxy(x - 4,y + 7);printf("%c",40);
     gotoxy(x - 3,y + 8);printf("%c",41);
     gotoxy(x - 4,y + 9);printf("%c",40);

     gotoxy(x + 3,y + 6);printf("%c",41);
     gotoxy(x + 4,y + 7);printf("%c",40);
     gotoxy(x + 3,y + 8);printf("%c",41);
     gotoxy(x + 4,y + 9);printf("%c",40);

     //BOCA

     gotoxy(x ,y + 6);printf("%c",64);


}


void Jefe::borrar(){

       //CUERPO
     gotoxy(x,y);printf(" ");

     gotoxy(x - 1,y + 1);printf(" ");
     gotoxy(x + 1,y + 1);printf(" ");

     gotoxy(x - 2,y + 2);printf(" ");
     gotoxy(x - 1,y + 2);printf(" ");
     gotoxy(x + 1,y + 2);printf(" ");
     gotoxy(x + 2,y + 2);printf(" ");

     gotoxy(x - 3,y + 3);printf(" ");
     gotoxy(x - 2,y + 3);printf(" ");
     gotoxy(x + 2,y + 3);printf(" ");
     gotoxy(x + 3,y + 3);printf(" ");

     gotoxy(x - 4,y + 4);printf(" ");
     gotoxy(x - 3,y + 4);printf(" ");
     gotoxy(x + 3,y + 4);printf(" ");
     gotoxy(x + 4,y + 4);printf(" ");

     //OJOS
     gotoxy(x - 2,y + 5);printf(" ");
     gotoxy(x + 2,y + 5);printf(" ");

     //TENTACULOS

     gotoxy(x - 2,y + 6);printf(" ");
     gotoxy(x - 3,y + 7);printf(" ");
     gotoxy(x - 2,y + 8);printf(" ");
     gotoxy(x - 3,y + 9);printf(" ");
     gotoxy(x - 2,y + 10);printf(" ");
     gotoxy(x - 3,y + 11);printf(" ");

     gotoxy(x + 2,y + 6);printf(" ");
     gotoxy(x + 3,y + 7);printf(" ");
     gotoxy(x + 2,y + 8);printf(" ");
     gotoxy(x + 3,y + 9);printf(" ");
     gotoxy(x + 2,y + 10);printf(" ");
     gotoxy(x + 3,y + 11);printf(" ");

     gotoxy(x - 3,y + 6);printf(" ");
     gotoxy(x - 4,y + 7);printf(" ");
     gotoxy(x - 3,y + 8);printf(" ");
     gotoxy(x - 4,y + 9);printf(" ");

     gotoxy(x + 3,y + 6);printf(" ");
     gotoxy(x + 4,y + 7);printf(" ");
     gotoxy(x + 3,y + 8);printf(" ");
     gotoxy(x + 4,y + 9);printf(" ");

     //BOCA

     gotoxy(x ,y + 6);printf(" ");


}



void Jefe::mover(){

     borrar();

     x+=dx;

     if(y >= 4 && y <= SCREEN_HEIGHT/2 - 9){  //FUNCIONA BIEN, SOLO PROBAR CON EL DIBUJO DESEADO QUE ANDE, CON EL MAL PADRE ANDA.

        y++;


     }

     if(x+dx == 13 || x+dx == 80){

        dx = -dx;
     }

     dibujar();
}


void Jefe::morir(){

     borrar();

     gotoxy(x,y);printf("*");

     gotoxy(x - 1,y + 1);printf("*");
     gotoxy(x + 1,y + 1);printf("*");

     gotoxy(x - 2,y + 2);printf("*");
     gotoxy(x - 1,y + 2);printf("*");
     gotoxy(x + 1,y + 2);printf("*");
     gotoxy(x + 2,y + 2);printf("*");

     gotoxy(x - 3,y + 3);printf("*");
     gotoxy(x - 2,y + 3);printf("*");
     gotoxy(x + 2,y + 3);printf("*");
     gotoxy(x + 3,y + 3);printf("*");

     gotoxy(x - 4,y + 4);printf("*");
     gotoxy(x - 3,y + 4);printf("*");
     gotoxy(x + 3,y + 4);printf("*");
     gotoxy(x + 4,y + 4);printf("*");

     //OJOS
     gotoxy(x - 2,y + 5);printf("*");
     gotoxy(x + 2,y + 5);printf("*");

     //TENTACULOS

     gotoxy(x - 2,y + 6);printf("*");
     gotoxy(x - 3,y + 7);printf("*");
     gotoxy(x - 2,y + 8);printf("*");
     gotoxy(x - 3,y + 9);printf("*");
     gotoxy(x - 2,y + 10);printf("*");
     gotoxy(x - 3,y + 11);printf("*");

     gotoxy(x + 2,y + 6);printf("*");
     gotoxy(x + 3,y + 7);printf("*");
     gotoxy(x + 2,y + 8);printf("*");
     gotoxy(x + 3,y + 9);printf("*");
     gotoxy(x + 2,y + 10);printf("*");
     gotoxy(x + 3,y + 11);printf("*");

     gotoxy(x - 3,y + 6);printf("*");
     gotoxy(x - 4,y + 7);printf("*");
     gotoxy(x - 3,y + 8);printf("*");
     gotoxy(x - 4,y + 9);printf("*");

     gotoxy(x + 3,y + 6);printf("*");
     gotoxy(x + 4,y + 7);printf("*");
     gotoxy(x + 3,y + 8);printf("*");
     gotoxy(x + 4,y + 9);printf("*");

     //BOCA

     gotoxy(x ,y + 6);printf("*");

     Sleep(1200);

     borrar();

}


void Jefe::mensajeJefeDerrotado(){

     gotoxy(SCREEN_WIDTH/2,SCREEN_HEIGHT/2); printf("Felicidades");
     gotoxy(SCREEN_WIDTH/2,SCREEN_HEIGHT/2 + 1); printf("Has ganado!!!");

}



#endif // JEFE_H_INCLUDED
