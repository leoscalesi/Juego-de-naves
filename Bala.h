#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED

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






#endif // BALA_H_INCLUDED
