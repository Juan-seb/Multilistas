#include <iostream>
#include "lista.h"
#include <string>
using namespace std;

struct  posgrado{
    string nombrePosgrado;
    string tematica;
    string universidad;
};

struct profesor{
    string nombre;
    string pregrado;
    string uPregrado;
    Lista<posgrado> pos;
};

struct asignatura{
    string nombre;
    int semestre;
    Lista<profesor> prof;
};

struct carrera{
    string nombreCarrera;
    string coordinador;
    string ubicacion;
    Lista<asignatura> asig;
};

struct facultad{
    string nombreFacultad;
    string nombreDecano;
    string ubicacion;
    int telefono;
    Lista<carrera> carreras;
};

int main(int argc, char** argv) {

    int id,longitud;
    string clasificacion;

    posgrado auxP;
    profesor auxProf;
    asignatura auxAsig;
    carrera auxCar;
    Lista<facultad> universidad;

    cin>>longitud;
    for (int i = 0; i < longitud; ++i) {
        cout<<"Ingrese nombre de la facultad:"<<endl;
    }

    /*ejemplo *e1 = new ejemplo;
    e1->n = 2;
    e1->hola = "Adios";
    Lista<ejemplo> lista1;
    lista1.insertarElemento(*e1,"Nada");*/

    //lista1.mostrar();
    return 0;
}