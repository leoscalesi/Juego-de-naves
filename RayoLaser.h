#ifndef RAYOLASER_H_INCLUDED
#define RAYOLASER_H_INCLUDED


//Clase en desarrollo.Es para los rayos laser que disparara el Jefe.

class RayoLaser{

    int x,y;

public:

    RayoLaser(int _x,int _y):x(_x),y(_y){}
    int X(){return x;}
    int Y(){return y;}
    void dibujar();
    void mover();
    void borrar();
    void colision(Nave&);
    bool detectaLimiteInferior();

};


void RayoLaser::dibujar(){

     gotoxy(x,y);printf("%c",186);
     gotoxy(x,y + 1);printf("%c",186);
     gotoxy(x,y + 2);printf("%c",186);
}


void RayoLaser::mover(){

    borrar();   //PRIMERO BORRAMOS
                           //PARA QUE VAYA CAYENDO

    if(y < SCREEN_HEIGHT - 5){          //CUANDO LLEGA AL LIMITE INFERIOR (y > 45) QUE VUELVA A CAER DESDE ARRIBA AL AZAR

         y++;

     }

     dibujar();
}


void RayoLaser::borrar(){


     gotoxy(x,y);printf(" ");
     gotoxy(x,y + 1);printf(" ");
     gotoxy(x,y + 2);printf(" ");
}

void RayoLaser::colision(Nave& nave){    //PASO POR REFERENCIA A UN OBJETO NAVE PORQUE LE VOY A HACER CAMBIOS

     if(x >= nave.X() && x < nave.X()+6 && y >= nave.Y() && y <= nave.Y()+2){    //CONDICION QUE EVALUA TENIENDO EN CUENTA EL TAMAÑO DE LA NAVE CUANDO HAY COLISION CON EL ASTEROIDE

          Beep(400,100);
          Sleep(500); // PARA QUE CADA VEZ QUE TOQUEN A LA NAVE SE NOTE MAS.
          nave.restarCorazones();   //IMPORTANTE PORQUE ACA VEO COMO SE COMUNICAN NAVE Y ASTEROIDE
          nave.pintar(); //PARA QUE NO SE BORRE PARTE DE LA NAVE CUANDO LA TOCA EL ASTEROIDE
          nave.pintarCorazones();  //ACTUALIZO CORAZONES

     }

}


bool RayoLaser::detectaLimiteInferior(){

     if(y == SCREEN_HEIGHT - 8)return true;
     return false;
}

#endif // RAYOLASER_H_INCLUDED
