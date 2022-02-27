# Juego-de-naves

Juego de naves utilizando la consola de comando.

Dando mis primeros pasos en el desarrollo de videojuegos, en este caso tenemos un juego de naves simple. En este caso, tomo como base el juego desarrollado en el siguiente link: https://www.youtube.com/watch?v=X6lMTEIzjys&list=PLpOqH6AE0tNj8W0EGpoGG2CEMDJTt4ihZ&index=1 Partiendo de dicha base, decidi hacerle agregados que se me fueron ocurriendo.

La tematica original del juego presentado en el link es el manejo de una nave que dispara, y debe destruir la mayor cantidad de asteroides posible, sumando puntos por cada asteroide destruido.

Decidi agregarle ademas lo siguiente:

Guardado de puntaje maximo en un archivo mediante manejo de la libreria fstream.

Ver puntaje maximo desde el menu principal.

Debido a que los asteroides caen constantemente, no estamos obligados a mover la nave hacia arriba y hacia abajo. Para darle mas interaccion al usuario, decidi agregar un nuevo enemigo llamado Ovni, el cual no puede destruirse, y que obliga a que la nave se mueva tambien hacia arriba y hacia abajo en la pantalla.

Sonidos a los disparos.

Pantalla de juego terminado con una melodia ultra basica hecha por mi.

Melodia inicial al comenzar el juego.

Ademas decidi agregar un modo de juego mas en el menu, en el cual aparezca un Jefe de nivel, al lograr un cierto puntaje.

Las clases con las que trabajo son las siguientes:

Class Nave, que incluye los siguientes metodos:

                                                Nave(int _x,int _y,int _corazones,int _vidas);
                                                
                                                int X(){ return x;}   
                                                
                                                int Y(){ return y;}
                                                
                                                int VIDAS() { return vidas;}
                                                
                                                void restarCorazones() {corazones --;}
                                                
                                                void pintar();
                                                
                                                void borrar();
                                                
                                                void mover();
                                                
                                                void pintarCorazones();
                                                
                                                void morir();
Esta clase representa a la Nave que el jugador manejara durante el juego.

Class Asteroide, que incluye los siguientes metodos:

                                                   Asteroide(int _x,int _y);
                                                   
                                                   int X(){ return x;}
                                                   
                                                   int Y(){ return y;}
                                                   
                                                   void pintar();
                                                   
                                                   void mover();
                                                   
                                                   void borrar();
                                                   
                                                   void colision(class Nave&);
Esta clase representa a los asteroides que la nave debe destruir para asi sumar el maximo puntaje posible.

Class Bala, que incluye los siguientes metodos:

                                                    Bala(int _x,int _y);
                                                    
                                                    int X(){ return x;}   
                                                    
                                                    int Y(){ return y;}
                                                    
                                                    void mover();
                                                    
                                                    bool detectaLimiteSuperiorBala();
Esta clase representa la bala que dispara la nave.

Class Menu, que incluye un solo metodo: static void mostrar();

Debido a que la clase Menu no guardara ningun estado interno (decision que decidi tomar yo), decido declarar el metodo mostrar como static, de esta forma no necesito instanciar un objeto de la clase Menu, para llamar a este metodo, ya que lo hago directamente de esta forma: Menu::mostrar()

Class Juego, que incluye un solo metodo: static void jugar();

En esta clase se encuentra el main loop del juego.

Class Ovni, que incluye los siguientes metodos:

                                                Ovni(int _x,int _y):x(_x),y(_y){}
                                                
                                                int X(){return x;}
                                                
                                                int Y(){return y;}
                                                
                                                void dibujar();
                                                
                                                void borrar();
                                                
                                                void mover();
                                                
                                                bool detectaLimiteDerecho();

                                                bool colisionNave(Nave&);
Class Jefe, que incluye los siguientes metodos:

                                               Jefe(int _x,int _y,int _dx):x(_x),y(_y),dx(_dx){}

                                               int X(){return x;}

                                               int Y(){return y;}

                                               void dibujar();

                                               void borrar();

                                               void mover();

                                               void morir();

                                               void mensajeJefeDerrotado();
Por ultimo, tengo un archivo llamado FuncionesGlobales.h, en el cual tengo metodos que no entraban en ninguna de las clases que mencione mas arriba, por lo que decidi dejarlos como funciones globales. Dire algo respecto a esto en el apartado Que cambiaria a mi juego?. En este archivo tengo las siguientes funciones:

                                           void ocultarCursor()
                                           
                                           int leerPuntajeArchivo()
                                           
                                           void guardarPuntajeArchivo(int p)
                                           
                                           void verMaximaPuntuacion()
                                           
                                           void pintarLimites()
                                           
                                           void melodiaListoParaJugar()
                                           
                                           void pintarListoParaJugar()
                                           
                                           void melodiaJuegoTerminado()
Dicho esto, tenemos un juego basico funcionando.

Conclusiones: En mi afan de seguir incursionando en el desarrollo de videojuegos, veo como muy positivo este primer juego, ya que partiendo de una base ya hecha, pude agregarle cosas que se me fueron ocurriendo, y cambiando algunas de las que ya estaban hechas. Fue un camino de aprendizaje, que seguire aplicando en otros juegos que estoy haciendo. Desarrollar un juego es como un juego en si mismo, es bastante divertido observar comportamientos inesperados, pero super interesantes.

Que cambiaria a mi juego? Muchas cosas! Pero solo por mencionar algunas, en vez de tener un archivo con funciones globales, podria hacer una Clase Auxiliar en la cual meter esos metodos que no encajan en las clases ya armadas por ejemplo. Otra cosa que me hace mucho ruido despues de seguir investigando y leyendo acerca de SFML (con la cual comenzare a incursionar mas adelante) es lo sucio que quedo el main loop. Si bien funciona, se volvera super dificil de leer y extenso si la aplicacion sigue creciendo. Ni hablar de la repeticion de codigo, otra cosa grave que debera cambiar a futuro.
