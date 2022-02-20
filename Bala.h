#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED


#include "Jefe.h"

class Bala{

      int x,y;

  public:

      Bala(int _x,int _y);
      int X(){ return x;}   //PARA ACCEDER A ESTOS ATRIBUTOS DESDE EL ASTEROIDE.
      int Y(){ return y;}
      void mover();
      void moverBalaJefe();
      bool detectaLimiteSuperiorBala();
      bool detectaLimiteInferiorBalaJefe();
      bool colisionBalaJefeNave(Nave&);
      bool detectaDanioBalaJefe(Jefe&);  //LE DEBO PASAR LAS COORD DEL JEFE.

};


Bala::Bala(int _x,int _y): x(_x),y(_y){}


void Bala::mover(){

      gotoxy(x,y); printf(" ");   //LO PRIMERO QUE HAGO ES BORRAR

      //if(y > 4) y--;    //PERMITO QUE SIGA SUBIENDO SI NO SOBREPASA EL LIMITE SUPERIOR
      //PERO AL AGREGAR EL METODO detectaLimiteSuperiorBala() SE PUEDE OMITIR ESE if Y QUEDARIA SOLO:

      y--;

      //DIBUJO LA BALA
      gotoxy(x,y); printf("*");

}


void Bala::moverBalaJefe(){

      gotoxy(x,y); printf(" ");   //LO PRIMERO QUE HAGO ES BORRAR

      //if(y > 4) y--;    //PERMITO QUE SIGA SUBIENDO SI NO SOBREPASA EL LIMITE SUPERIOR
      //PERO AL AGREGAR EL METODO detectaLimiteSuperiorBala() SE PUEDE OMITIR ESE if Y QUEDARIA SOLO:

      y++;

      //DIBUJO LA BALA
      gotoxy(x,y); printf("%c",254);

}


//DETECTA SI LA BALA LLEGO O NO AL LIMITE SUPERIOR
bool Bala::detectaLimiteSuperiorBala(){

     if(y == 4)return true;
     return false;
}


bool Bala::detectaLimiteInferiorBalaJefe(){

     if(y == SCREEN_HEIGHT - 5)return true;
     return false;
}


bool Bala::colisionBalaJefeNave(Nave& nave){

     if(x >= nave.X() && x < nave.X()+6 && y >= nave.Y() && y <= nave.Y()+2){    //CONDICION QUE EVALUA TENIENDO EN CUENTA EL TAMAÑO DE LA NAVE CUANDO HAY COLISION CON EL ASTEROIDE

          Beep(400,100);
          Sleep(500); // PARA QUE CADA VEZ QUE TOQUEN A LA NAVE SE NOTE MAS.
          nave.restarCorazones();   //IMPORTANTE PORQUE ACA VEO COMO SE COMUNICAN NAVE Y ASTEROIDE
          nave.pintar(); //PARA QUE NO SE BORRE PARTE DE LA NAVE CUANDO LA TOCA EL ASTEROIDE
          nave.pintarCorazones();  //ACTUALIZO CORAZONES

          return true;

    }

    return false;

}


bool Bala::detectaDanioBalaJefe(Jefe& jefe){

     if(x == jefe.X() && y == jefe.Y() || x == jefe.X() - 1 && y == jefe.Y() || x == jefe.X() + 1 && y == jefe.Y()){

        return true;
     }

     return false;
}



#endif // BALA_H_INCLUDED
