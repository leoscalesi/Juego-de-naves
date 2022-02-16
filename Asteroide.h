#ifndef ASTEROIDE_H_INCLUDED
#define ASTEROIDE_H_INCLUDED

#include <stdlib.h>  //ACA ESTA LA FUNCION rand()


class Asteroide{

      int x,y;

   public:

       Asteroide(int _x,int _y);
       int X(){ return x;}
       int Y(){ return y;}
       void pintar();
       void mover();
       void borrar();
       void colision(class Nave&);

};

Asteroide::Asteroide(int _x,int _y): x(_x),y(_y){}

void Asteroide::pintar(){

    gotoxy(x,y); printf("%c",184);
}


void Asteroide::mover(){

    gotoxy(x,y); printf(" ");   //PRIMERO BORRAMOS
    y++;                        //PARA QUE VAYA CAYENDO

    if(y > SCREEN_HEIGHT - 5){          //CUANDO LLEGA AL LIMITE INFERIOR (y > 45) QUE VUELVA A CAER DESDE ARRIBA AL AZAR

           x = rand()% (SCREEN_WIDTH-10) + 10;      //PARTO DESDE 10 EN x Y OBTENGO NUMEROS HASTA SCREEN_WIDTH + 10, POR ESO DEBO RESTAR 10.
           y = 4;
     }
     pintar();

     //HASTA ACA EL ASTEROIDE CAE AL AZAR PERO FALTA PROGRAMAR LAS COLISIONES
}

//DETECTA COLISION ASTEROIDE NAVE
void Asteroide::colision(class Nave& nave){    //PASO POR REFERENCIA A UN OBJETO NAVE PORQUE LE VOY A HACER CAMBIOS

     if(x >= nave.X() && x < nave.X()+6 && y >= nave.Y() && y <= nave.Y()+2){    //CONDICION QUE EVALUA TENIENDO EN CUENTA EL TAMAÑO DE LA NAVE CUANDO HAY COLISION CON EL ASTEROIDE

          Beep(400,100);
          Sleep(500); // PARA QUE CADA VEZ QUE TOQUEN A LA NAVE SE NOTE MAS.
          nave.restarCorazones();   //IMPORTANTE PORQUE ACA VEO COMO SE COMUNICAN NAVE Y ASTEROIDE
          nave.pintar(); //PARA QUE NO SE BORRE PARTE DE LA NAVE CUANDO LA TOCA EL ASTEROIDE
          nave.pintarCorazones();  //ACTUALIZO CORAZONES

          x = rand()% (SCREEN_WIDTH-10) + 10;   // EL ASTEROIDE VUELVE ARRIBA
          y = 4;
     }

}


void Asteroide::borrar(){

     gotoxy(x,y); printf(" ");
}




#endif // ASTEROIDE_H_INCLUDED
