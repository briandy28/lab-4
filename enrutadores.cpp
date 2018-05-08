#include "enrutadores.h"


Enrutadores::Enrutadores()
{

}

int Enrutadores::getCant_nodos() const
{
    return cant_nodos;
}
vector<vector<int> > Enrutadores::getTopologia() const
{
    return topologia;
}
vector<vector<int> > Enrutadores::getRuta_corta() const
{
    return ruta_corta;
}

void Enrutadores::setCant_nodos(int value)
{
    cant_nodos = value;
}
void Enrutadores::setTopologia(const vector<vector<int> > &value)
{
    topologia = value;
}
void Enrutadores::setRuta_corta(const vector<vector<int> > &value)
{
    ruta_corta = value;
}

vector<vector<string> > Enrutadores::getCaminos() const
{
    return caminos;
}

void Enrutadores::setCaminos(const vector<vector<string> > &value)
{
    caminos = value;
}

void Enrutadores::redaleatoria(int no)
{
    vector<vector<int>> aux2;

    int num, infinito=no-1;
    srand(time(NULL));
    num = rand();
    std::vector< std::vector<int> > vec( no, std::vector<int>(no) ) ; // 3x3, all zeroes

       for( std::size_t r = 0 ; r < vec.size() ; ++r )
       {

           for( std::size_t c = 0 ; c < vec.size() ; ++c )
           {   num=1+rand()%(101-1);
               if(r==c){vec[r][c]=0;}
               if(c==infinito){vec[r][c]=32767; infinito--;}
               else{vec[r][c] = num ;
                   vec[c][r]=num;}
           }
       }
       for( std::size_t r = 0 ; r < vec.size() ; ++r )
       {

           for( std::size_t c = 0 ; c < vec.size() ; ++c )
           {
               if(r==c){vec[r][c]=0;}

           }
       }


//    for (int i = 0; i < no; i++)
//    {   num=1+rand()%(101-1);
//        for (int j = 0; j < no; j++)
//        {
//            aux[i][j].reverse_iterator=2;

//            if(i==j){interno.push_back(0);
//}
//        }
//    }
//    for(int i = no;i>=0;i--)
//    {    colm++;
//        aux[i].insert(colm,32767);
//        colm++;

//    }

    this->setTopologia(vec);
    this->setCant_nodos(no);
    aux2=this->buscarRuta();
    this->setRuta_corta(aux2);

}

void Enrutadores::imprimirTopologia(int cant)
{   cout<< "    ";
    for (int i=0;i<cant;i++)
    {
        cout<<"N"<<i+1<<" ";
    }
    cout<<endl;
    for (int i = 0; i < cant; i++)
    {   cout<<"N"<<i+1<<"  ";
        for (int j = 0; j < cant; j++)
        {
            cout<<ruta_corta[i][j]<<"  ";
        }
        cout<<endl;
    }

}

void Enrutadores::cargarTopologia()
{
    //debo contar la cantidad de nodos que hay en la red
    vector<int> costo;
    string  entrada;
    vector<vector<char>>x;
    int numero=0;
    char tem;
    string b;

    ifstream lectura;
    lectura.open("rutas.txt");

    while(!lectura.eof())
    {
        getline(lectura,entrada);
        for(int k=0; k<entrada.length(); k++){
            if(entrada[k]=='\n'){
                numero=int(tem);
                numero-=48;
                costo.push_back(numero);
            }
            if(entrada[k]==' '){

                numero=int(tem);
                numero-=48;
                costo.push_back(numero);
                tem='00';
                tem=tem-48;
            }
            else{
                b=entrada[k];
                if(entrada[k]!=' '){
                tem=entrada[k];}
            }
    }
        topologia.push_back(costo);
        costo.clear();

    }
    lectura.close();
    for (int i = 0; i < topologia.size(); i++) {
        for (int j = 0; j < topologia.size(); j++)
        {
            if (topologia[i][j]==-1){ topologia[i][j]=32767;}
        }
    }

}

vector<vector<int>> Enrutadores::buscarRuta()           //vector<vector<int>> tabla, int cant_nodos
{
    vector< vector<int> > ruta_Mas_Corta ;
//  vector<vector<string>> temcaminos;
    vector<string>tem;
    ruta_Mas_Corta=this->topologia;
    int k,i,j, aux,b,longi;
//    char num1, num2;
//   string camino, le="s";
    longi=ruta_Mas_Corta.size();
    for(k = 0; k < cant_nodos; k++)
    {
        for(i = 0; i < cant_nodos; i++)
        {
            for(j = 0; j < cant_nodos; j++)
            {
                b=ruta_Mas_Corta[i][k];
                aux = ruta_Mas_Corta[i][k] + ruta_Mas_Corta[k][j];
                if(ruta_Mas_Corta[i][j] > aux)
                {
//                    num1=int(i);
//                    num2=int(k);
                    ruta_Mas_Corta[i][j] = aux;
//                    camino+="N";
//                    camino+=num1;
//                    camino+="-";
//                    camino+="N";
//                    camino+=num2;
//                    camino+="-";
//                    camino+="N";
//                    camino+=num2;
//                    camino+="-";
//                    camino+="N";
//                    camino+=num1;
//                    temcaminos[i][j]=camino;
//                    num1='00';
//                    num1-=48;
//                    num2='00';
//                    num2-=48;
//                    camino.clear();
                }
            }
        }
    }
    return ruta_Mas_Corta;
//    this->setCaminos(temcaminos);
}

void Enrutadores::agregarNodo(Enrutadores nodo,int no)
{
    vector<vector<int>> matrizAux;
    vector<int> costo;
    int valor,l;
    cout<<"Ingrese los costos de conexion con los nodos actuales de la red"<<endl;
    cout<<"Si los nodos no tienen coneccion directa por favor agregar -1"<<endl;

    matrizAux = nodo.getTopologia();
    l=matrizAux.size();
    for(int i=0; i<l+1; i++){
        if(i==(no-1))
        {
            valor=0;
            costo.push_back(valor);
            break;
        }
        else
        {
        cout<<"Costo de conexion con el nodo "<<i+1<<": ";
        cin>>valor;
        if(valor==-1){valor=32767;} 
        costo.push_back(valor);
        }
        matrizAux[i].push_back(costo[i]);
    }
    matrizAux.push_back(costo);
    cout << "Se agrego correctamente el nodo" << endl;
    this->setTopologia(matrizAux);

}

void Enrutadores::eliminarNodo(int eliminar){

    vector<vector<int>> matrizAux;
    matrizAux = this->getRuta_corta();

    for (int i=0; i<matrizAux.size(); i++){
        for(int k=0; k<matrizAux[i].size();k++){
            if(k==eliminar){
                //Se debe eliminar esta posicion de topologia
                matrizAux[i].erase(matrizAux[i].begin()+k);
                break;
            }
        }
        //}
    }
     matrizAux.erase (matrizAux.begin()+eliminar);
    int k= matrizAux.size();
    this->setCant_nodos(k);
    this->setRuta_corta(matrizAux);
}

void Enrutadores::costoEnvio(Enrutadores nodo){
    int origen, destino, k, i;
    bool band=true;
    vector<vector<int>> matrizAux;
    matrizAux = nodo.getRuta_corta();
    cout<<"Ingrese el numero de nodo de origen"<<endl;
    cin>>origen;
    cout<<"Ingrese el numero de nodo de destino"<<endl;
    cin>>destino;

    if(origen > nodo.getCant_nodos()){
        cout<<"La red no tiene actualmente el numero nodo origen ingresado."<<endl;
        band=false;
    }
    if(destino > nodo.getCant_nodos()){
        cout<<"La red no tiene actualmente el numero nodo destino ingresado."<<endl;
        band=false;
    }

    if(band){       //Si origen y destino existen en la red
        for(i=0; i<nodo.getCant_nodos(); i++){       //Se recorre las filas hasta encontrar el nodo origen
            if(origen-1 == i){
                for(k=0; k< nodo.getCant_nodos(); k++){     //Se recorre las filas hasta encontrar el nodo destino
                    if(destino-1 == k){
                        cout<<"el costo de envio desde el nodo "<< origen << " hasta el modo "<<destino<<" es: "<<matrizAux[i][k]<<endl;
                    }
                }
            }
        }
    }

}

