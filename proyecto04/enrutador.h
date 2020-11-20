#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include<fstream>
#include<ostream>
using namespace std;


class enrutador
{

private:
    map<char,int> router;
    map<char,int>::iterator it;

public:
    bool agregar_enlace(char nombre, int costo);
    bool eliminar_enlace(char nombre);
    bool modificar_enlace(char nombre, int costo);
    void imprimir_valores();
    void imprimir_tabla();
    int numero_menor(int menor);
};

#endif // ENRUTADOR_H
