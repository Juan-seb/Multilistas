#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template<class T>
struct Nodo {
    int id;
    T info;
    Nodo<T> *sig_cabeza;
};

template<class T>
class Lista {

private:
    Nodo<T> *lista;

    Nodo<T> obtenerPrimero();

    bool borrarNodos(int);

    int tam;


public:
    Lista() {
        lista = NULL;
        tam = 0;
    };

    int listaVacia();

    void insertarElemento(T, int);

    void modificarDatos(int, T);

    void mostrar();

    void borrarDatoMultilista(int);
};

template<class T>
int Lista<T>::listaVacia() {
    if (tam > 0) {
        return tam;
    } else {
        return tam;
    }
}

template<class T>
Nodo<T> Lista<T>::obtenerPrimero() {
    return lista;
}

template<class T>
void Lista<T>::insertarElemento(T infoNueva, int id) {

    Nodo<T> *nuevo_nodo = new Nodo<T>;
    nuevo_nodo->info = infoNueva;

    Nodo<T> *aux1 = &*lista;
    Nodo<T> *aux2;

    while (aux1 != NULL) {
        aux2 = aux1;
        aux1 = aux1->sig_cabeza;
    }

    if (lista == aux1) {
        lista = nuevo_nodo;
    } else {
        aux2->sig_cabeza = nuevo_nodo;
    }
    nuevo_nodo->sig_cabeza = aux1;
    tam++;
}

template<class T>
void Lista<T>::modificarDatos(int idBus, T infoNueva) {

    Nodo<T> *actual = new Nodo<T>;
    actual = lista;
    bool continuar = true;

    while ((actual != NULL) && continuar) {
        if ((actual->id == idBus) && continuar) {
            cout << "Modificando datos de facultad:" << endl;
            actual->info.nombreFacultad = infoNueva.nombreFacultad;
            actual->info.nombreDecano = infoNueva.nombreDecano << endl;
            actual->info.ubicacion = infoNueva.ubicacion;
            actual->info.telefono = infoNueva.telefono;
            continuar = false;
        } else {
            Nodo<T> *actualCarrera = new Nodo<T>;
            actualCarrera = actual->info.carreras.obtenerPrimero();
            while ((actualCarrera != NULL) && continuar) {
                if (actualCarrera->id == idBus) {
                    cout << "Modificando datos de carrera carrera:" << endl;
                    actualCarrera->info.nombreCarrera = infoNueva.nombreCarrera;
                    actualCarrera->info.coordinador = infoNueva.coordinador;
                    actualCarrera->info.ubicacion = infoNueva.ubicacion;
                    continuar = false;
                } else {
                    Nodo<T> *actualAsig = new Nodo<T>;
                    actualAsig = actualCarrera->info.asig.obtenerPrimero();
                    while ((actualAsig != NULL) && continuar) {
                        if (actualAsig->id == idBus) {
                            cout << "Modificando datos para la asignatura:" << endl;
                            actualAsig->info.nombre = infoNueva.nombre;
                            actualAsig->info.semestre = infoNueva.semestre;
                            continuar = false;
                        } else {
                            Nodo<T> *actualProf = new Nodo<T>;
                            actualProf = actualAsig->info.prof.obtenerPrimero();
                            while ((actualProf != NULL) && continuar) {
                                if (actualProf->id == idBus) {
                                    cout << "Modificando datos del docente:" << endl;
                                    actualProf->info.nombre = infoNueva.nombre;
                                    actualProf->info.pregrado = infoNueva.pregrado;
                                    actualProf->info.uPregrado = infoNueva.uPregrado;
                                    continuar = false;
                                } else {
                                    Nodo<T> *actualPos = new Nodo<T>;
                                    actualPos = actualProf->info.pos.obtenerPrimero();
                                    while ((actualPos != NULL) && continuar) {
                                        if (actualPos->id == idBus) {
                                            cout << "Modificando datos de posgrados:" << endl;
                                            actualPos->info.nombrePosgrado = infoNueva.nombrePosgrado;
                                            actualPos->info.tematica = infoNueva.tematica;
                                            actualPos->info.universidad = infoNueva.universidad;
                                            continuar = false;
                                        }
                                        actualPos = actualPos->sig_cabeza;
                                    }
                                }
                                actualProf = actualProf->sig_cabeza;
                            }
                        }
                        actualAsig = actualAsig->sig_cabeza;
                    }
                }
                actualCarrera = actualCarrera->sig_cabeza;
            }
        }
        cout << "Los datos no han sido encontrados en la facultad" << actual->info.nombreFacultad << endl;
        actual = actual->sig_cabeza;
    }
    if (continuar) {
        cout << "Los datos no fueron encontrados, sin modificaciones" << endl;
    }
}

template<class T>
void Lista<T>::mostrar() {
    Nodo<T> *actual = new Nodo<T>;
    actual = lista;

    while ((actual != NULL)) {
        cout << "Datos de la facultad:" << endl;
        cout << actual->info.nombreFacultad << endl;
        cout << actual->info.nombreDecano << endl;
        cout << actual->info.ubicacion << endl;
        cout << actual->info.telefono << endl;
        cout << endl;
        cout << endl;

        Nodo<T> *actualCarrera = new Nodo<T>;
        actualCarrera = actual->info.carreras.obtenerPrimero();

        while (actualCarrera != NULL) {
            cout << "Datos carrera:" << endl;
            cout << actualCarrera->info.nombreCarrera << endl;
            cout << actualCarrera->info.coordinador << endl;
            cout << actualCarrera->info.ubicacion << endl;
            cout << endl;
            cout << endl;

            Nodo<T> *actualAsig = new Nodo<T>;
            actualAsig = actualCarrera->info.asig.obtenerPrimero();

            while (actualAsig != NULL) {
                cout << "Asignatura carrera:" << endl;
                cout << actualAsig->info.nombre << endl;
                cout << actualAsig->info.semestre << endl;
                cout << endl;
                cout << endl;

                Nodo<T> *actualProf = new Nodo<T>;
                actualProf = actualAsig->info.prof.obtenerPrimero();
                while (actualProf != NULL) {
                    cout << "Docentes que dictan la asignatura:" << endl;
                    cout << actualProf->info.nombre << endl;
                    cout << actualProf->info.pregrado << endl;
                    cout << actualProf->info.uPregrado << endl;
                    cout << endl;
                    cout << endl;

                    Nodo<T> *actualPos = new Nodo<T>;
                    actualPos = actualProf->info.pos.obtenerPrimero();
                    if (actualPos == NULL) {
                        cout << "El docente no tiene datos de posgrado" << endl;
                    } else {
                        while (actualPos != NULL) {
                            cout << "Datos encontrados para el posgrado:" << endl;
                            cout << actualPos->info.nombrePosgrado << endl;
                            cout << actualPos->info.tematica << endl;
                            cout << actualPos->info.universidad << endl;

                            actualPos = actualPos->sig_cabeza;
                        }
                    }
                    actualProf = actualProf->sig_cabeza;
                }
                actualAsig = actualAsig->sig_cabeza;
            }
            actualCarrera = actualCarrera->sig_cabeza;
        }
        cout << "Mostrando datos de la siguiente facultad:" << endl;

        actual = actual->sig_cabeza;
    }
}

template<class T>
bool Lista<T>::borrarNodos(int idDel) {
    if (lista != NULL) {
        Nodo<T> *aux_borrar;
        Nodo<T> *anterior;
        aux_borrar = lista;

        while ((aux_borrar != NULL) && (aux_borrar->id == idDel)) {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->sig_cabeza;
        }

        if (aux_borrar == NULL) {
            cout << "No existe el dato a borrar" << endl;
            return false;
        } else {
            if (anterior == NULL) {
                lista = lista->sig_cabeza;
                delete aux_borrar;
                return true;
            } else {
                anterior->sig_cabeza = aux_borrar->sig_cabeza;
                delete aux_borrar;
                return true;
            }
        }

    }
}

template<class T>
void Lista<T>::borrarDatoMultilista(int idDel) {
    if (lista != NULL) {
        Nodo<T> *actual = new Nodo<T>;
        bool continuar = true;
        actual = lista;

        while ((actual != NULL) && continuar) {

            Lista<T> *actualCarreraLista;
            actualCarreraLista = actual->info.carreras;

            if (actualCarreraLista->borrarDatoMultilista(idDel)) {
                cout << "Elemento borrado" << endl;
                continuar = false;
            }

            Nodo<T> *actualCarrera = new Nodo<T>;
            actualCarrera = actual->info.carreras.obtenerPrimero();

            while (actualCarrera != NULL) {
                Lista<T> *actualAsigLista;
                actualAsigLista = actualCarrera->info.asig;

                if (actualAsigLista->borrarDatoMultilista(idDel)) {
                    cout << "Elemento borrado" << endl;
                    continuar = false;
                }

                Nodo<T> *actualAsig = new Nodo<T>;
                actualAsig = actualCarrera->info.asig.obtenerPrimero();

                while (actualAsig != NULL) {
                    Lista<T> *actualProfLista;
                    actualProfLista = actualAsig->info.prof;

                    if (actualProfLista->borrarDatoMultilista(idDel)) {
                        cout << "Elemento borrado" << endl;
                        continuar = false;
                    }

                    Nodo<T> *actualProf = new Nodo<T>;
                    actualProf = actualAsig->info.prof.obtenerPrimero();

                    while (actualProf != NULL) {

                        Lista<T> *actualPosLista;
                        actualPosLista = actualProf->info.pos;

                        if (actualPosLista->listaVacia() > 0) {
                            if (actualPosLista->borrarDatoMultilista(idDel)) {
                                cout << "Elemento borrado" << endl;
                                continuar = false;
                            }
                        }
                        actualProf = actualProf->sig_cabeza;
                    }
                    actualAsig = actualAsig->sig_cabeza;
                }
                actualCarrera = actualCarrera->sig_cabeza;
            }
            actual = actual->sig_cabeza;
        }

    }
}

#endif