#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <list>    //PARA TRABAJAR CON EL LISTADO DE BALAS
#include <stdlib.h>
#include <ctime>
#include "FuncionesGlobales.h"
#include "Nave.h"
#include "Bala.h"
#include "Asteroide.h"
#include "Ovni.h"
#include "Jefe.h"


class Juego{

public:

    static void jugar();

};

void Juego::jugar(){


       srand(time( NULL ));

       ocultarCursor();

       pintarLimites();


       Nave nave(SCREEN_WIDTH/2,SCREEN_HEIGHT - 7,3,3);
       nave.pintar();
       nave.pintarCorazones();   //PARA QUE SE VEA EN LA PRIMER ITERACION.

       //pintarListoParaJugar();


        //CREO UN OBJETO LISTA PARA LAS BALAS, CON PUNTEROS A BALA,PARA FACILITAR LA CREACION DE OBJETOS CON EL OPERADOR new.
        list<Bala*> Balas;
        //CREO UN ITERADOR PARA RECORRER LA LISTA.
        list<Bala*>::iterator it;

        list<Asteroide*> Asteroides;

        //CADA OBJETO DE ESTA LISTA ESTA REPRESENTADO POR EL ITERADOR.
        list<Asteroide*>::iterator ita;
        //AHORA QUE SABEMOS USAR LISTAS PODEMOS CREAR UNA LISTA DE ASTEROIDES TAMBIEN Y ELIMINAR LAS LLAMADAS INDIVIDUALES.


        list <Ovni*> ovnis;

        list<Ovni*>::iterator itovni;  //SOLO UN OVNI QUE AL LLEGAR A LOS LIMITES DE LA PANTALLA SE DESTRUYE, CREANDOSE OTRO EN UN RANGO DETERMINADO DE LA PANTALLA (DE LA MITAD DEL ALTO
                                        //DE LA PANTALLA PARA ABAJO .

        //CREO UN OBJETO LISTA PARA LAS BALAS, CON PUNTEROS A BALA,PARA FACILITAR LA CREACION DE OBJETOS CON EL OPERADOR new.
        list<Bala*> BalasJefe;
        //CREO UN ITERADOR PARA RECORRER LA LISTA.
        list<Bala*>::iterator itbalasjefe;


        //AGREGO 5 ASTEROIDES A LA LISTA EN POSICIONES EN x E y AL AZAR.
        for(int i = 0; i < 5;i++){

            Asteroides.push_back(new Asteroide(rand()% (SCREEN_WIDTH-10) + 10,rand()% (SCREEN_HEIGHT-4) + 4));
        }

        bool gameover = false;
        int puntos = 0;

        int cont = 0;

        Jefe jefe(SCREEN_WIDTH/2 - 12,5,1);

        //jefe.dibujar();



        while(!gameover){


        //Beep(10,200); //SONIDO AMBIENTAL, POR AHORA NO PORQUE TAPA LOS DEMAS SONIDOS.

        cont ++;

        if(cont == 600){  // PARA QUE TARDE EN APARECER EL PRIMER OVNI. Y DESPUES DE ESO APARECE SIEMPRE. SI PONGO MODULOS APARECEN VARIOS OVNIS DEPENDIENDO DE LA COMBINACION DE MODULOS QUE PONGA, USAR PARA LA VERSION CON BOSSES.

               ovnis.push_back(new Ovni(10,rand()% (SCREEN_HEIGHT - 5 - SCREEN_HEIGHT/2) + SCREEN_HEIGHT/2));
        }


        for(itovni = ovnis.begin();itovni != ovnis.end();itovni++){

               (*itovni)->dibujar();
               (*itovni)->mover();

                if((*itovni)->detectaLimiteDerecho()){ //SI LLEGA AL BORDE DE LA PANTALLA ELIMINO ESE OVNI DE LA LISTA Y CREO OTRO.
                    (*itovni)->borrar();
                    delete(*itovni);
                    itovni = ovnis.erase(itovni);

                    ovnis.push_back(new Ovni(10,rand()% (SCREEN_HEIGHT - 5 - SCREEN_HEIGHT/2) + SCREEN_HEIGHT/2)); //ESTA CONDICION DEL random ES PORQUE LOS OVNIS DEBEN APARECER DEL MEDIO DE LA PANTALLA PARA ABAJO NOMAS
                                                                                                                // Y ADEMAS QUE NO SUPERE EL LIMITE INFERIOR, POR ESO EL -5.
               }
        }


        for(itovni = ovnis.begin();itovni != ovnis.end();itovni++){   //COLISION OVNI NAVE.

               (*itovni)->dibujar();

               if((*itovni)->colisionNave(nave)){ //SI TOCA A LA NAVE ELIMINO ESE OVNI DE LA LISTA Y CREO OTRO.

                    (*itovni)->borrar();
                    delete(*itovni);
                    itovni = ovnis.erase(itovni);

                    ovnis.push_back(new Ovni(10,rand()% (SCREEN_HEIGHT - 5 - SCREEN_HEIGHT/2) + SCREEN_HEIGHT/2));

                }
        }


        //ESCRIBO PUNTOS EN PANTALLA Y QUE SE VEA INICIALMENTE CON 0 PUNTOS.
        gotoxy(9,2), printf("Puntos %d",puntos);

        //DISPARO   VER COMO TRANSFORMARLO EN UN METODO DE LA CLASE BALA, LO INTENTE PERO LA BALA NO SUBE.
        if(kbhit()){

           char tecla = getch();
           if(tecla == 'g'){
               Balas.push_back(new Bala(nave.X() + 2,nave.Y() - 1));  //AGREGA UNA BALA A LA LISTA, EN LA MISMA POSICION EN LA QUE ESTA LA NAVE EN ESE MOMENTO, SUMANDO EN X 2 PARA QUE SALGA DEL MEDIO DE LA NAVE, Y RESTANDO 1 EN Y PARA QUE PAREZCA QUE LA BALA SALE DE LA NAVE).
               Beep(300,20); //CADA BALA EMITE SONIDO.
           }
        }

        //RECORREMOS LA LISTA DESDE EL PRINCIPIO HASTA EL FINAL MOVIENDO A CADA BALA, DEBIDO QUE PASO PUNTEROS A OBJETOS, DEBO LLAMAR AL METODO CON EL OPERADOR FLECHA, Y COMO QUIERO EL CONTENIDO DERREFERENCIO EL PUNTERO AL LLAMAR AL METODO).

        for(it = Balas.begin();it != Balas.end();it++){

               (*it)->mover();

               //AHORA CONTROLO SI LA BALA LLEGO AL LIMITE SUPERIOR

               if((*it)->detectaLimiteSuperiorBala()){    //SI DA true DEBO ELIMINAR LA BALA SEGUN LA CONDICION DENTRO DE ESTE METODO.

                    //BORRO LA BALA PRIMERO SITUANDOME EN LAS COORDENADAS DE LA BALA.

                    gotoxy((*it)->X(),(*it)->Y()); printf(" ");  //LA BALA ATRAVIESA EL LIMITE, SUPERIOR Y SE ROMPE EL JUEGO, PORQUE DEBO ELIMINAR FISICAMENTE DE LA LISTA A LA BALA.
                    delete(*it);  //SI DEJO SOLO EL delete EL ITERADOR DE LA LISTA SE INVALIDA, Y ROMPE EL JUEGO
                    //ENTONCES DEBO USAR EL METODO erase DE list(QUE SE ENCARGA DE RETORNAR UN PUNTERO A LA NUEVA LOCACION DEL ELEMENTO QUE SIGUE AL ULTIMO ELEMENTO BORRADO EN LA LISTA) YA SI NO PERDER EL HILO DE LA ITERACION.
                    it = Balas.erase(it);
               }
        }


        //ITERO LA LISTA DE ASTEROIDES Y LOS MUESTRO

        for(ita = Asteroides.begin();ita != Asteroides.end();ita++){

            (*ita)->mover();
            (*ita)->colision(nave);
        }


        //RECORRO LA LISTA DE ASTEROIDES Y LA DE LAS BALAS Y COMPARO SUS COORDENADAS PARA VER SI HUBO COLISION.
        //VER COMO REEMPLAZO EL DOBLE for.

        //DEBEMOS CONSIDERAR LOS DOS CASOS EN LOS QUE PUEDE HABER COLISION TOMANDO EL EJE y.
        for(ita = Asteroides.begin();ita != Asteroides.end();ita++){
            for(it = Balas.begin();it != Balas.end();it++){

                  //EN EL EJE x DEBEN COINCIDIR LAS COORDENADAS TANTO DE LA BALA COMO DEL ASTEROIDE.
                  //EN EL EJE y HAY DOS CASOS A CONSIDERAR, ANALIZANDO QUE EN CADA ITERACION TANTO EL ASTEORIDE COMO LA BALA SE DESPLAZAN 1 FRAME.
                  //EL PRIMER CASO CONSIDERA EL MENOS TRIVIAL EN EL QUE NO HABRIA COLISION EN TEORIA, Y LUEGO EL CASO MAS SIMPLE, EN EL QUE SI HAY COLISION EVIDENTE.
                  if((*ita)->X() == (*it)->X() && ((*ita)->Y()+1 == (*it)->Y() || (*ita)->Y() == (*it)->Y())){

                        //ELIMINO LA BALA OBTENIENDO SUS COORDENADAS.

                        gotoxy((*it)->X(),(*it)->Y()); printf(" ");
                        delete(*it);
                        it = Balas.erase(it);

                        //ELIMINO EL ASTEROIDE OBTENIENDO SUS COORDENADAS, PRIMERO CREANDO OTRO QUE LO REEMPLACE.

                        Asteroides.push_back(new Asteroide(rand()% (SCREEN_WIDTH-10) + 10,rand()% (SCREEN_HEIGHT-4) + 4));
                        gotoxy((*ita)->X(),(*ita)->Y()); printf(" ");
                        delete(*ita);
                        ita = Asteroides.erase(ita);

                        puntos += 5;

                  }
            }

        }





        // LUCHA CONTRA EL JEFE. PRIMERO SE DEBE BORRAR TODO DE LA PANTALLA, EXCEPTO NAVE Y SUS DISPAROS (BORRAR ASTEROIDES Y OVNIS)
        // PARA LUCHAR CONTRA EL JEFE EL PUNTAJE DEBE SER DE 100.
        // -------------------------------------------------------------------------------------------------------------------------

        if(puntos == 5){    //FUNCIONA, DESPUES CAMBIARLE A 100 PUNTOS.

            for(ita = Asteroides.begin();ita != Asteroides.end();ita++){

                (*ita)->borrar();
                gotoxy((*ita)->X(),(*ita)->Y()); printf(" ");
                delete(*ita);
                ita = Asteroides.erase(ita);
            }


            for(itovni = ovnis.begin();itovni != ovnis.end();itovni++){   //COLISION OVNI NAVE.

                (*itovni)->borrar();
                //gotoxy((*itovni)->X(),(*itovni)->Y()); //printf(" ");

                delete(*itovni);
                itovni = ovnis.erase(itovni);
            }

            jefe.mover();

            if(cont%5 == 0 && cont%7 == 0){

                BalasJefe.push_back(new Bala(jefe.X() ,jefe.Y() + 5));
            }


            for(itbalasjefe = BalasJefe.begin();itbalasjefe != BalasJefe.end();itbalasjefe++){

               (*itbalasjefe)->moverBalaJefe();

                if((*itbalasjefe)->detectaLimiteInferiorBalaJefe()){    //SI DA true DEBO ELIMINAR LA BALA SEGUN LA CONDICION DENTRO DE ESTE METODO.

                    //BORRO LA BALA PRIMERO SITUANDOME EN LAS COORDENADAS DE LA BALA.

                    gotoxy((*itbalasjefe)->X(),(*itbalasjefe)->Y()); printf(" ");  //LA BALA ATRAVIESA EL LIMITE, SUPERIOR Y SE ROMPE EL JUEGO, PORQUE DEBO ELIMINAR FISICAMENTE DE LA LISTA A LA BALA.
                    delete(*itbalasjefe);  //SI DEJO SOLO EL delete EL ITERADOR DE LA LISTA SE INVALIDA, Y ROMPE EL JUEGO
                    //ENTONCES DEBO USAR EL METODO erase DE list(QUE SE ENCARGA DE RETORNAR UN PUNTERO A LA NUEVA LOCACION DEL ELEMENTO QUE SIGUE AL ULTIMO ELEMENTO BORRADO EN LA LISTA) YA SI NO PERDER EL HILO DE LA ITERACION.
                    itbalasjefe = BalasJefe.erase(itbalasjefe);
               }

            }


        }




        nave.morir();
        nave.mover();

        Sleep(50);


        if(nave.VIDAS() == 0){

              gameover = true;
        }

    }//FIN while.


    Sleep(2000);
    system("cls");

    gotoxy(SCREEN_WIDTH/2,SCREEN_HEIGHT/2); printf("JUEGO TERMINADO");
    melodiaJuegoTerminado();

    Sleep(1000);

    system("cls");

    int maximopuntaje = leerPuntajeArchivo();
    if (puntos > maximopuntaje) guardarPuntajeArchivo(puntos);


}










#endif // JUEGO_H_INCLUDED
