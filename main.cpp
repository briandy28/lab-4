#include <iostream>

#include "enrutadores.h"

using namespace std;

int main()
{   vector<vector<int>>aux;
    vector<Enrutadores> nodos;          //se guardan todos los nodos de la red en un vector
    int n = 4;                          //Cantidad de nodos iniciales cargados desde el archivo. La 1ra columna es el nombre de nodo
    int opc, posicion=n, i;

    //Se realiza esta accion para cada nodo de la red
    for(int j=0;j<n;j++)
    {
        Enrutadores nodo;
        nodos.push_back(nodo);
    }

    for(i=0; i<n; i++){
        nodos[i].cargarTopologia();
        nodos[i].setCant_nodos(n);
        aux=nodos[i].buscarRuta();
        nodos[i].setRuta_corta(aux);
    }

    do{
        cout<<"************ MENU ************"<<endl;
        cout << "1. Agregar un nuevo nodo. " << endl;
        cout << "2. Remover un nodo actual. " << endl;
        cout << "3. Cargar nueva topologia desde un archivo. " << endl;
        cout << "4. Conocer el costo de envio de un paquete desde un origen a uno destino. " << endl;
        cout << "5. Conocer la ruta de envio desde un origen a uno destino. " << endl;
        cout << "6. Generar una red aleatoria. "<<endl;
        cout << "7. Imprimir Topologia de la red. "<<endl;
        cout << "8. SALIR. "<<endl;
        cout<<endl;
        cout << "Seleccione una opcion: " << endl;
        cin>>opc;

        if (opc == 1){
            Enrutadores nodo;
            nodos.push_back(nodo);
            n++;
            nodos[0].setCant_nodos(n);
            nodos[0].agregarNodo(nodos[0],n);

            for(i=1; i<n; i++){
                nodos[i].setCant_nodos(n);
                nodos[i].setTopologia(nodos[0].getTopologia());          //Aca se agrega el nodo y los costos a la matriz topologia
            }

            for(i=0; i<n; i++){
                nodos[i].setRuta_corta(nodos[i].buscarRuta());     //Se actualiza la tabla de enrutamiento de todos los nodos

            }
            nodos[0].imprimirTopologia(nodos[0].getCant_nodos());

        }else if(opc == 2){
            //Se debe llamar a la funcion eliminarNodo
            int eliminar;
            cout<<"Imgrese el numero de nodo a elminar"<<endl;
            cin>>eliminar;
            for (i=0; i<n; i++){
                nodos[i].eliminarNodo(eliminar-1);
            }
        }else if(opc == 3){
            int lon=nodos.size();
            nodos.clear();
            for(int j=0;j<lon;j++)
            {
                Enrutadores nodo;
                nodos.push_back(nodo);
            }
            for(int j=0;j<lon;j++)
            {
                nodos[j].cargarTopologia();
            }

        }else if(opc == 4){
            nodos[0].costoEnvio(nodos[0]);

        }else if(opc == 5){
         vector<vector<string>>tem;
         tem=nodos[0].getCaminos();
         nodos[0].getCaminos();
         int cant=nodos[0].getCaminos().size();
         cout<< "    ";
             for (int i=0;i<cant;i++)
             {
                 cout<<"N"<<i+1<<" ";
             }
             cout<<endl;
             for (int i = 0; i < cant; i++)
             {   cout<<"N"<<i+1<<"  ";
                 for (int j = 0; j < cant; j++)
                 {
                     cout<<tem[i][j]<<"  ";
                 }
                 cout<<endl;
             }

        }else if(opc == 6){
        nodos.clear();
        int numdeno;
        cout<<"cuantos nodos quiere en su red:  ";
        cin>>numdeno;
        for(int j=0;j<numdeno;j++)
        {
            Enrutadores nodo;
            nodos.push_back(nodo);
        }
        for(int j=0;j<numdeno;j++)
        {
            nodos[j].redaleatoria(numdeno);
        }
        nodos[0].imprimirTopologia(numdeno);


        }else if(opc == 7){
            nodos[0].imprimirTopologia(nodos[0].getCant_nodos());
        }else if(opc == 8){
            break;
        }else{
            cout<<"OPCION INVALIDA"<<endl;
        }
    }while(opc != 8);

    return 0;
}
