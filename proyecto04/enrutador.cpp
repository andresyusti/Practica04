#include "enrutador.h"

bool enrutador::agregar_enlace(char nombre, int costo){

    bool condicion=false;
    if(router.find(nombre)==router.end()){
            router.insert( pair<char, int>(nombre, costo));
            condicion=true;
    }
    return condicion;
}

bool enrutador::eliminar_enlace(char nombre){

    bool condicion=false;
    if(router.find(nombre)!=router.end()){
            router.erase(nombre);
            condicion=true;
    }
    return condicion;
}

bool enrutador::modificar_enlace(char nombre, int costo){

    bool condicion=false;
    if(router.find(nombre)!=router.end()){
            router[nombre]=costo;
            condicion=true;
    }
    return condicion;
}

void enrutador::imprimir_valores(){

    for(it=router.begin();it!=router.end();it++) cout << it->second << "\t";
}
void enrutador::imprimir_tabla(){
    for(it=router.begin();it!=router.end();it++) cout << it->first << ":\t" << it->second << endl;
}

int enrutador::numero_menor(int menor){
    int Nmenor=999999, letra;
    for (it=router.begin();it!=router.end();it++){
        if (it->second!=-1){
            if(Nmenor<it->second){
                router[it->first]=it->second+menor;
            }
        }
    }
    menor+=Nmenor;
    return menor, letra;
}
