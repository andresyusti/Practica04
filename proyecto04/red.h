#ifndef RED_H
#define RED_H

#include <enrutador.h>

class red
{

private:
    map<char,enrutador> net;
    map<char,enrutador>::iterator it;
    map<char,int> net_corto;
    map<char,int>::iterator itc;
    map<char, int> router_suma;
    map<char, int>::iterator its;

public:
   int getNumero(char numero, map<char, int> &router_suma);
   void cambiar_numero(char letra, int numero1, int numero2, map<char, int> &router_suma);
   void sumar_numero(char letra, char numero, map<char, int> &router_suma);
   void leer_archivo(string archivo);
   void agregar_enrutador(char nombre, bool cond);
   bool eliminar_enrutador(char nombre);
   void tabla_conexiones();
   void tabla_conexiones_enrutador(char nombre);
   bool conectar_enrutadores(char nombre1, char nombre2, int costo);
   void ruta_corta(char nombre1, char nombre2);

};

#endif // RED_H
