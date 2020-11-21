#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include<fstream>
#include<ostream>
#include <list>
#include <cstdlib>
#include<time.h>
using namespace std;


class enrutador
{

private:
    map<char,int> router;
    map<char,int>::iterator it;
    //map<char, int> router_suma;
    //map<char, int>::iterator its;

public:
    bool agregar_enlace(char nombre, int costo);
    bool eliminar_enlace(char nombre);
    bool modificar_enlace(char nombre, int costo);
    void imprimir_valores();
    void imprimir_tabla();
    string numero_menor(string camino, map<char, int> *router_suma);
};
#endif // ENRUTADOR_H
