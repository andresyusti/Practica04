#include <red.h>

using namespace std;

int main()
{
    red net;
    string archivo_natural= "archivo.txt";
    int decision=1, costo=0;
    char enrutador1, enrutador2;


    while(decision!=0){
        cout << "\nIngresar:\n1. Ver tablas de enrutadores.\n2. Ver tabla de un enrutador.\n3. Agregar enrutador.\n4. Eliminar enrutador.";
        cout << "\n5. Conectar o desconectar enrutadores.\n6. Conocer costo de envio.\n7. agregar enrutadores atraves de un archivo.";
        cout << "\nSeleccion una opcion: ";
        cin >> decision;
        switch (decision){
            case 1:{
                cout << "\nTabla de conexiones:\n\n";
                net.tabla_conexiones();
            }
            break;

            case 2:{
                cout << "\nIngresar el enrutador que quiera visualizar: "; cin >> enrutador1;
                net.tabla_conexiones_enrutador(enrutador1);
            }
            break;

            case 3:{
                cout << "\nIngresar el nombre del nuevo enrutador: ";
                cin >> enrutador1;
                net.agregar_enrutador(enrutador1, true);
            }
            break;

            case 4:{
                cout << "\nIngresar el nombre del enrutador a eliminar: ";
                cin >> enrutador1;
                if(!net.eliminar_enrutador(enrutador1)) cout << "El enrutador ingresado no existe.\n";

            }
            break;

            case 5:{
                cout << "\nnombre del primer enrutador: "; cin >> enrutador1;
                cout << "nombre del segundo enrutador: "; cin >> enrutador2;
                cout << "costo del enlace o si quiere desconectaro ponga -1: "; cin >> costo;
                if(!net.conectar_enrutadores(enrutador1, enrutador2, costo)) cout << "Uno de los dos enrutadores no existe.\n";
            }
            break;

            case 6:{
                cout << "Ingresar enrutador inicial: "; cin >> enrutador1;
                cout << "ingresar enrutador final: "; cin >> enrutador2;

            }
            break;

            case 7:{
                net.leer_archivo(archivo_natural);
            }
            break;

        }
    }

    return 0;
}
