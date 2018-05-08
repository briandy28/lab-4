#ifndef ENRUTADORES_H
#define ENRUTADORES_H

#include <map>
#include <vector>
#include<string>
#include <iostream>
#include<istream>
#include <fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Enrutadores
{
public:
    Enrutadores();
    void cargarTopologia();
    void imprimirTopologia(int cant);
    void agregarNodo(Enrutadores nodo,int no);
    void eliminarNodo(int eliminar);
    void costoEnvio(Enrutadores nodo);
    int getCant_nodos() const;
    void setCant_nodos(int value);
    void setTopologia(const vector<vector<int> > &value);
    void setRuta_corta(const vector<vector<int> > &value);
    void setRuta_caminos(const vector<vector<int> > &value);
    void setCaminos(const vector<vector<string> > &value);
    void redaleatoria(int no);
    vector<vector<string> > getCaminos() const;
    vector<vector<int> > getTopologia() const;
    vector<vector<int> > getRuta_corta() const;
    vector< vector<int> > buscarRuta();


private:
    int cant_nodos;
    vector <vector <int>> topologia;
    vector <vector <int>> ruta_corta;
    vector <vector <string>> caminos;
};

#endif // ENRUTADORES_H
