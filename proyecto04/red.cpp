#include "red.h"



void red::tabla_conexiones(){
    enrutador router;
    cout <<"\t";
    for(it=net.begin();it!=net.end();it++){
        cout << it->first << "\t";
    }
    cout << "\n\n";
    for(it=net.begin();it!=net.end();it++){
        cout << it ->first << "\t";
        router=it->second;
        router.imprimir_valores();
        cout << "\n\n";
    }
}

void red::tabla_conexiones_enrutador(char nombre){
    enrutador router;
    router=net[nombre];
    router.imprimir_tabla();
}

void red::agregar_enrutador(char nombre, bool cond){

    enrutador router;
    char nombre_enlace;
    int valor_enlace;

    if(net.find(nombre)==net.end()){
        router.agregar_enlace(nombre, 0);
        for(it=net.begin();it!=net.end();it++){
            router.agregar_enlace(it->first,-1);
            it->second.agregar_enlace(nombre,-1);
        }

    if (cond==true){
         while(true){
             cout << "Ingrese el nombre del nodo con el que quiere enlazar o ponga * si quiere salir: ";
             cin >> nombre_enlace;
             if (nombre_enlace=='*') break;
             else{
                 cout << "Ingrese el valor del enlace: ";
                 cin >> valor_enlace;
                 if(!(router.modificar_enlace(nombre_enlace, valor_enlace))) cout << "El nodo no existe" << endl;
                 else net[nombre_enlace].modificar_enlace(nombre, valor_enlace);
             }
          }
    }

        net.insert(pair<char, enrutador>(nombre, router));
    }
}

bool red::eliminar_enrutador(char nombre){
    enrutador router;
    bool verificar=false;
    if(net.find(nombre)!=net.end()){
        verificar=true;
        net.erase(nombre);
        for (it=net.begin();it!=net.end();it++){
            router=it->second;
            router.eliminar_enlace(nombre);
            net[it->first]=router;
        }
    }

    return verificar;

}

bool red::conectar_enrutadores(char nombre1, char nombre2, int costo){
    enrutador router;
    bool verificar=false;
    if(net.find(nombre1)!=net.end() and net.find(nombre2)!=net.end()){
        verificar=true;
        router=net[nombre1];
        router.modificar_enlace(nombre2, costo);
        net[nombre1]=router;
        router=net[nombre2];
        router.modificar_enlace(nombre1, costo);
        net[nombre2]=router;
    }
    return verificar;
}

void red::leer_archivo(string archivo){
    string linea, nodos;
    fstream lectura;
    enrutador router;
    lectura.open(archivo,fstream::in|fstream::binary);
    while(lectura.good()){
        linea=lectura.get();
        nodos.append(linea);
    }
    lectura.close();
    nodos.pop_back();

    int pos=0;

    for(int num=0 ;pos!=-1;num++){
        string nodo1,nodo2,costo;
        char nodos1, nodos2;

        pos = nodos.find(' ');
        nodo1 = nodos.substr(0,pos);
        pos = nodos.find(' ',pos+1);
        nodo2 = nodos.substr(0,pos);
        nodo2 = nodo2.substr(nodo1.size()+1);
        pos = nodos.find('\r');
        costo = nodos.substr(0,pos);
        costo = costo.substr(nodo1.size()+nodo2.size()+2);

        int costodomod = stoi(costo, nullptr, 10);
        nodos1=nodo1[0];
        nodos2=nodo2[0];
        if(net.find(nodos1)==net.end())  agregar_enrutador(nodos1, false);
        if(net.find(nodos2)==net.end())  agregar_enrutador(nodos2, false);

        conectar_enrutadores(nodos1, nodos2, costodomod);

        pos = nodos.find('\n');
        nodos = nodos.substr(pos+1);
}

}



/*void red::ruta_corta(char nombre1, char nombre2){
    enrutador router;
    int menor=0, letra=nombre1;
    while(true){
        router=net[letra];
        menor, letra=router.numero_menor(menor);
        if(letra==nombre2) break;
    }

}*/


