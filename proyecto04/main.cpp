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
        cout << "\n8. Generar nodos ramdon.\nSeleccion una opcion: ";
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
                net.ruta_corta(enrutador1,enrutador2);

            }
            break;

            case 7:{
                net.leer_archivo(archivo_natural);
            }
            break;

            case 8:{
                int numero_generar, i, l1, l2;
                string nuevo_archivo;
                string numero;
                cout << "ingresar la cantidad de nodos que desea generar, maximo 20: ";
                cin >> numero_generar;
                char letra1[numero_generar], letra2[numero_generar];
                srand(time(NULL));


                for (i=0;i<=numero_generar;i++){
                    letra1[i]=((rand()%(25))+65);
                    letra2[i]=((rand()%(25))+65);
                }

                for (i=0;i<=(numero_generar*10);i++){
                //if (letra1==letra2) letra2=(rand()%(25))+65;
                numero=to_string(rand()%(101));
                l1=rand()%(numero_generar);
                l2=rand()%(numero_generar);
                if (letra1[l1]!=letra2[l2]) nuevo_archivo=nuevo_archivo+letra1[l1]+' '+letra2[l2]+' '+numero;
                if (i!=numero_generar*10) nuevo_archivo+='\n';
                }
                fstream k("nuevo archivo.txt", fstream::out | fstream::binary);
                //k.write(nuevo_archivo.c_str(), nuevo_archivo.length());
                k<<nuevo_archivo;
                k.close();
                net.leer_archivo("nuevo archivo.txt");
            }
            break;

        }
    }

    return 0;
}
