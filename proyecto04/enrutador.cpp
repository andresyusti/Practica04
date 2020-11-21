#include "enrutador.h"
#include "red.h"

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


string enrutador::numero_menor(string camino, map<char, int> *router_suma){
    //enrutador router_suma;
    int menor=router.begin()->first;
    char letra;
    red net;



    for (it=router.begin();it!=router.end();it++){
        if (camino.find(it->first)!=-1);
        else{
            if (router_suma->find(it->first)==router_suma->end()){
                router_suma->insert(pair<char,int>(it->first,it->second));
            }
            else{
                if (it->second!=-1){
                    int numero_prueba=net.getNumero(it->first, *router_suma);
                    if(net.getNumero(it->first, *router_suma)==-1) net.cambiar_numero(it->first, it->second, net.getNumero(camino.back(), *router_suma), *router_suma);
                    else if ((it->second+net.getNumero(camino.back(), *router_suma))<net.getNumero(it->first, *router_suma)){
                        net.cambiar_numero(it->first, it->second, net.getNumero(camino.back(), *router_suma), *router_suma);
                        //it->first, net.getNumero(camino.back(), *router_suma), *router_suma
                    }
                }
            }
        }
    }
    //its=router_suma->begin();its!=router_suma->end();its++
    for(auto its : *router_suma){
        if (camino.find(its.first)!=-1);
        else if (its.second==-1);
        else if (its.second<menor){
            menor=its.second;
            letra=its.first;
        }
    }
    camino.push_back(letra);

    return camino;
}
