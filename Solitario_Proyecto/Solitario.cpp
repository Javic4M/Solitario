#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

// Estructuras
struct Carta {
    string numero;
    string color;
    string cara;
    bool mostrar = false;
};

struct Nodo {
    Carta *contenido;
    Nodo *nodoSiguiente;
    Nodo *nodoAnterior;
};


// Lista
class Lista {
    private:
        Nodo *nodoInicial;
        Nodo *nodoFinal;
        int longitud = 0;

    public:
        Lista();
        void ingresarDato(string contenido);
        void eliminar();
        Nodo* obtenerNodoInicial();
        Nodo* obtenerNodoFinal();
        int obtenerLongitud();
        bool estaVacia();
};

Lista::Lista() {}

void Lista::ingresarDato(string contenido) {
    Carta *carta = new Carta();
    carta->cara = contenido;

    for (int i = 0; i < contenido.size(); i++) {

        if (i == 0) {
            carta->numero = contenido[i];
        } else if (i == 3) {
            carta->color = contenido[i];
        }
    }

    if (longitud == 0) {
        nodoFinal = new Nodo();
        nodoFinal->contenido = carta;
        nodoInicial = nodoFinal;
    } else {
        Nodo *nuevo = new Nodo();
        nuevo->contenido = carta;
        nodoFinal->nodoSiguiente = nuevo;
        nuevo->nodoAnterior = nodoFinal;
        nodoFinal = nuevo;
    }
    longitud++;
}

void Lista::eliminar() {
    if (estaVacia()) {
        cout << "La Lista esta Vacia" << endl;
    } else if (longitud == 1) { 
        nodoInicial = nodoFinal = NULL;
    } else {
        nodoFinal = nodoFinal->nodoAnterior;
        nodoFinal->nodoSiguiente = NULL;
    }
    longitud--;
}

Nodo* Lista::obtenerNodoInicial() {
    return nodoInicial;
}

Nodo* Lista::obtenerNodoFinal() {
    return nodoFinal;
}

int Lista::obtenerLongitud() {
    return longitud; 
}

bool Lista::estaVacia() {
    return longitud == 0;
}


// Juego
Lista* obtenerLista(int indice, Lista *lista_1, Lista *lista_2, Lista *lista_3, Lista *lista_4, Lista *lista_5, Lista *lista_6, Lista *lista_7) {
    Lista *listaAEnviar = new Lista();

    if (indice == 1) {
        listaAEnviar = lista_1;
    } else if (indice == 2) {
        listaAEnviar = lista_2;
    } else if (indice == 3) {
        listaAEnviar = lista_3;
    } else if (indice == 4) {
        listaAEnviar = lista_4;
    } else if (indice == 5) {
        listaAEnviar = lista_5;
    } else if (indice == 6) {
        listaAEnviar = lista_6;
    } else if (indice == 7) {
        listaAEnviar = lista_7;
    }
    return listaAEnviar;
}

Lista* obtenerPilaDeAs(int indice, Lista *a_1, Lista *a_2, Lista *a_3, Lista *a_4) {
    Lista *listaAEnviar = new Lista();

    if (indice == 1) {
        listaAEnviar = a_1;
    } else if (indice == 2) {
        listaAEnviar = a_2;
    } else if (indice == 3) {
        listaAEnviar = a_3;
    } else if (indice == 4) {
        listaAEnviar = a_4;
    }
    return listaAEnviar;
}

void insertarCartas(Lista *lista_1, Lista *lista_2, Lista *lista_3, Lista *lista_4, Lista *lista_5, Lista *lista_6, Lista *lista_7, Lista *cola_2) {
    Lista *listaAAgregar = new Lista();
    int dimensiones[7] = {1,2,3,4,5,6,7};
    int contador = 52, indice = 1;
    srand(time(NULL));
    string cartasTotales[52] = {"A<3R", "2<3R", "3<3R", "4<3R", "5<3R", "6<3R", "7<3R", "8<3R", "9<3R", "I<3R", "J<3R", "Q<3R", "K<3R",
                                "A)(N", "2)(N", "3)(N", "4)(N", "5)(N", "6)(N", "7)(N", "8)(N", "9)(N", "I)(N", "J)(N", "Q)(N", "K)(N",
                                "A<>R", "2<>R", "3<>R", "4<>R", "5<>R", "6<>R", "7<>R", "8<>R", "9<>R", "I<>R", "J<>R", "Q<>R", "K<>R",
                                "A!!N", "2!!N", "3!!N", "4!!N", "5!!N", "6!!N", "7!!N", "8!!N", "9!!N", "I!!N", "J!!N", "Q!!N", "K!!N"};
    
    listaAAgregar = obtenerLista(indice, lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7);

    while (contador != 24) {
        int num=rand()%52;

        if (cartasTotales[num] != "####") {
            if (listaAAgregar->obtenerLongitud() != dimensiones[indice - 1]) {
                listaAAgregar->ingresarDato(cartasTotales[num]);
                cartasTotales[num] = "####";
                contador--;
            } else {
                indice++;
                listaAAgregar->obtenerNodoFinal()->contenido->mostrar = true;
                listaAAgregar = obtenerLista(indice, lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7);
            }
        }
    }
    listaAAgregar->obtenerNodoFinal()->contenido->mostrar = true;
    bool salir = false;
    contador = 0;

    while (!salir) {      
        if (cartasTotales[contador] != "####") {
            cola_2->ingresarDato(cartasTotales[contador]);
        }
        if (contador == 51) {
            break;
        }
        contador++;
    }
}

string verificarAses(Lista *lista_1, Lista *lista_2, Lista *lista_3, Lista *lista_4, Lista *lista_5, Lista *lista_6, Lista *lista_7, Lista *cola_2) {
    Lista *listaAAgregar = new Lista();
    string a_Verificar = "";

    for (int i = 1; i <= 8; i++) {
        if (i < 8) {
            listaAAgregar = obtenerLista(i, lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7);
        } else {
            listaAAgregar = cola_2;
        }
        if (!listaAAgregar->estaVacia()) {
            if (listaAAgregar->obtenerNodoFinal()->contenido->numero == "A") {
                a_Verificar = listaAAgregar->obtenerNodoFinal()->contenido->cara;
                listaAAgregar->eliminar();

                if (!listaAAgregar->estaVacia()) {
                    listaAAgregar->obtenerNodoFinal()->contenido->mostrar = true;
                }
                break;
            }
        }
    }
    return a_Verificar;
}

void mostrarJuego(Lista *lista_1, Lista *lista_2, Lista *lista_3, Lista *lista_4, Lista *lista_5, Lista *lista_6, Lista *lista_7, Lista *cola_1, Lista *cola_2, Lista *a_1, Lista *a_2, Lista *a_3, Lista *a_4) {
    cout << endl;
    cout << "-------------------SOLITARIO-------------------" << endl;
    cout << "A(s):" << endl;
    for (int i = 1; i <= 4; i++) {
        Lista *pilaAMostrar = obtenerPilaDeAs(i, a_1, a_2, a_3, a_4);
        if (!pilaAMostrar->estaVacia()) {
            cout << " " << pilaAMostrar->obtenerNodoFinal()->contenido->cara << "  ";
        } else {
            cout << " ----  ";
        }
    }
    cout << endl << endl;
    cout << "Cartas Restantes:" << endl;

    for (int i = 1; i <= 2; i++) {
        Lista *colaAMostrar = new Lista();

        if (i == 1) {
            if (cola_2->estaVacia()) {
                colaAMostrar = new Lista();
            } else {
                colaAMostrar = cola_1;
            }
        } else if (i == 2) {
            if (cola_2->estaVacia()) {
                int longitud = cola_1->obtenerLongitud();

                for (int i = 0; i < longitud; i++) {
                    cola_2->ingresarDato(cola_1->obtenerNodoFinal()->contenido->cara);
                    cola_1->eliminar();
                }
                colaAMostrar = cola_2;
            } else {
                colaAMostrar = cola_2;
            }
        }

        if (!colaAMostrar->estaVacia()) {
            
            if (i == 1) {
                cout << " C(" << colaAMostrar->obtenerLongitud()  << ")" << ": ####   ";
            } else {
                cout << " C(" << colaAMostrar->obtenerLongitud()  << ")" << ": " << colaAMostrar->obtenerNodoFinal()->contenido->cara;
            }
        } else {
            cout << " C(0)" << ": ----   ";
        }
    }

    cout << endl << endl;
    cout << "Cartas:" << endl;

    Lista *listaAMostrar = new Lista();
    for (int i = 1; i < 8; i++) {
        Nodo *actual = new Nodo();
        listaAMostrar = obtenerLista(i, lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7);

        if (!listaAMostrar->estaVacia()) {
            actual = listaAMostrar->obtenerNodoInicial();
            cout << " - F(" << i << "): ";

            for (int i = 0; i < listaAMostrar->obtenerLongitud(); i++) {
                string elemento = "####";

                if (actual->contenido->mostrar == true) {
                    elemento = actual->contenido->cara;
                }
                cout << elemento << " ";
                actual = actual->nodoSiguiente;
            }
        } else {
            cout << " - F(" << i << "): ";
        }
        cout << endl;
        listaAMostrar = NULL;
    }
}

void verificarInsercionDeCarta2(Lista *listaARecibir, string& numeroSiguiente, string& colorSiguiente, string& tipo, bool& salir) {
    string ordenDeLasCartas[13] = {"K", "Q", "J", "I", "9", "8", "7", "6", "5", "4", "3", "2", "A"};

    for (int i = 12; i >= 0; i--) {
        if (listaARecibir->obtenerNodoFinal()->contenido->numero == ordenDeLasCartas[i]) {
            if (i == 0) {
                salir = true;
            } else {
                numeroSiguiente = ordenDeLasCartas[i - 1];

                if (listaARecibir->obtenerNodoFinal()->contenido->color == "R") {
                    colorSiguiente = "R";
                } else {
                    colorSiguiente = "N";
                }
            }
            string contenido = listaARecibir->obtenerNodoFinal()->contenido->cara;

            for (int i = 0; i < contenido.size(); i++) {
                if (i == 1 || i == 2) {
                    tipo += contenido[i];
                }
            }
            break;
        }
    }
}

void verificarInsercionDeCarta(Lista *listaARecibir, string& numeroSiguiente, string& colorSiguiente, bool& salir) {
    string ordenDeLasCartas[12] = {"K", "Q", "J", "I", "9", "8", "7", "6", "5", "4", "3", "2"};

    for (int i = 0; i < 12; i++) {
        if (listaARecibir->obtenerNodoFinal()->contenido->numero == ordenDeLasCartas[i]) {
            if (i == 11) {
                salir = true;
            } else {
                numeroSiguiente = ordenDeLasCartas[i + 1];

                if (listaARecibir->obtenerNodoFinal()->contenido->color == "R") {
                    colorSiguiente = "N";
                } else {
                    colorSiguiente = "R";
                }
            }
            break;
        }
    }
}

void iniciarPartida() {
    Lista *lista_1 = new Lista(), *lista_2 = new Lista(), *lista_3 = new Lista(), *lista_4 = new Lista(), *lista_5 = new Lista(), *lista_6 = new Lista(), *lista_7 = new Lista();
    Lista *a_1 = new Lista(), *a_2 = new Lista(), *a_3 = new Lista(), *a_4 = new Lista();
    Lista *cola_1 = new Lista(), *cola_2 = new Lista();
    insertarCartas(lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7, cola_2);
    bool salir = false;
    int opcion = 0;

    while (!salir) {
        string a_Verificar = verificarAses(lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7, cola_2);

        if (a_Verificar != "") {
            if (a_1->estaVacia()) {
                a_1->ingresarDato(a_Verificar);
            } else if (a_2->estaVacia()) {
                a_2->ingresarDato(a_Verificar);
            } else if (a_3->estaVacia()) {
                a_3->ingresarDato(a_Verificar);
            } else if (a_4->estaVacia()) {
                a_4->ingresarDato(a_Verificar);
            }
        }
        mostrarJuego(lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7, cola_1, cola_2, a_1, a_2, a_3, a_4);
        cout << endl;
        cout << "Seleccionar una Opcion:" << endl;
        cout << "   1. Voltear una Carta" << endl;
        cout << "   2. Tomar Carta(s)" << endl;
        cout << "   3. Guardar Carta" << endl;
        cout << "   4. Visualizar" << endl;
        cout << "   5. Regresar" << endl;
        cout << "   6. Salir" << endl;
        cin >> opcion;
        cout << endl;

        if (opcion == 1) {
            cola_1->ingresarDato(cola_2->obtenerNodoFinal()->contenido->cara);
            cola_2->eliminar();
        } else if (opcion == 2) {
            int opcion_1 = 0;

            cout << "Seleccionar de donde desea tomar la(s) Carta(s):" << endl;
            cout << "   1. De las Ases" << endl;
            cout << "   2. De la Pila de Cartas" << endl;
            cout << "   3. De las Filas" << endl;
            cin >> opcion_1;
            cout << endl;

            if (opcion_1 == 1) {
                int AsEmisor = 0, filaReceptor = 0;
                Lista *pilaAMandar = new Lista(), *listaARecibir = new Lista();
                bool salir = false;

                cout << "---------------------------------------------" << endl;
                cout << "Escriba un Numero en las siguiente Peticiones" << endl;
                cout << endl;
                cout << "Pila de las Ases para tomar la Carta: "; cin >> AsEmisor;
                cout << "Fila para depositar la Carta: "; cin >> filaReceptor;
                cout << "---------------------------------------------" << endl;

                if (AsEmisor >= 1 && AsEmisor <= 4 && filaReceptor >= 1 && filaReceptor <= 7) {
                    pilaAMandar = obtenerPilaDeAs(AsEmisor, a_1, a_2, a_3, a_4);
                    listaARecibir = obtenerLista(filaReceptor, lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7);

                    if (pilaAMandar->obtenerLongitud() == 1) {
                        cout << "\n++++++++++++++++++++++" << endl;
                        cout << "No puedes Quitar una A" << endl;
                        cout << "++++++++++++++++++++++" << endl;
                    } else {
                        if (!listaARecibir->estaVacia()) {
                            string numeroSiguiente = "", colorSiguiente = "";
                            verificarInsercionDeCarta(listaARecibir, numeroSiguiente, colorSiguiente, salir);

                            if (pilaAMandar->obtenerNodoFinal()->contenido->numero == numeroSiguiente && pilaAMandar->obtenerNodoFinal()->contenido->color == colorSiguiente) {
                                listaARecibir->ingresarDato(pilaAMandar->obtenerNodoFinal()->contenido->cara);
                                listaARecibir->obtenerNodoFinal()->contenido->mostrar = true;
                            } else {
                                cout << "\n++++++++++++++++++++++++++++++++++++++++" << endl;
                                cout << "Error, verifique las filas Seleccionadas" << endl;
                                cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
                                salir = true;
                            }

                            if (!salir) {
                                pilaAMandar->eliminar();
                                pilaAMandar->obtenerNodoFinal()->contenido->mostrar = true;
                            }
                        }
                    }
                } else {
                    cout << "\n++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "Error, verifique las filas Seleccionadas" << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
                }
            } else if (opcion_1 == 2) {
                int fila_1 = 0;
                cout << "--------------------------------------------------" << endl;
                cout << "Escriba la Fila donde desea Depositar la Carta: "; cin >> fila_1;
                cout << "--------------------------------------------------" << endl;

                if (fila_1 > 0 && fila_1 < 8) {
                    Lista *listaARecibir = new Lista();
                    string numeroSiguiente = "", colorSiguiente = "";
                    listaARecibir = obtenerLista(fila_1, lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7);
                    
                    if (!listaARecibir->estaVacia()) {
                        verificarInsercionDeCarta(listaARecibir, numeroSiguiente, colorSiguiente, salir);

                        if (cola_2->obtenerNodoFinal()->contenido->numero == numeroSiguiente && cola_2->obtenerNodoFinal()->contenido->color == colorSiguiente) {
                            listaARecibir->ingresarDato(cola_2->obtenerNodoFinal()->contenido->cara);
                            listaARecibir->obtenerNodoFinal()->contenido->mostrar = true;
                            
                            if (!cola_2->estaVacia()) {
                                cola_2->eliminar();
                                cola_2->obtenerNodoFinal()->contenido->mostrar = true;
                            }
                        } else {
                            cout << "\n++++++++++++++++++++++++++++++++++++++++++" << endl;
                            cout << "La Carta no cumple con el patron requerido" << endl;
                            cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
                        }
                    } else {
                        if (cola_2->obtenerNodoFinal()->contenido->numero == "K") {
                            listaARecibir->ingresarDato(cola_2->obtenerNodoFinal()->contenido->cara);
                            listaARecibir->obtenerNodoFinal()->contenido->mostrar = true;

                            if (!cola_2->estaVacia()) {
                                cola_2->eliminar();
                                cola_2->obtenerNodoFinal()->contenido->mostrar = true;
                            }
                        } else {
                            cout << "\n++++++++++++++++++++++++++++++++++" << endl;
                            cout << "No puedes Insertar esta Carta Aqui" << endl;
                            cout << "++++++++++++++++++++++++++++++++++" << endl;
                        }
                    }
                } else {
                    cout << "\n++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "La Fila seleccionada esta fuera de Rango" << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
                }
            } else if (opcion_1 == 3) {
                int filaEmisor = 0, filaReceptor = 0, largo = 0;
                Lista *listaAMandar = new Lista(), *listaARecibir = new Lista();
                bool exit = false;

                cout << "---------------------------------------------" << endl;
                cout << "Escriba un Numero en las siguiente Peticiones" << endl;
                cout << endl;
                cout << "Fila para tomar la(s) Carta(s): "; cin >> filaEmisor;
                cout << "Cantidad de Cartas a Tomar: "; cin >> largo;
                cout << "Fila para depositar la(s) Carta(s): "; cin >> filaReceptor;
                cout << "---------------------------------------------" << endl << endl;;
                
                if (filaEmisor != filaReceptor) {
                    if (filaEmisor > 0 && filaEmisor < 8 && filaReceptor > 0 && filaReceptor < 8) {
                        listaAMandar = obtenerLista(filaEmisor, lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7);
                        listaARecibir = obtenerLista(filaReceptor, lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7);

                        if (listaAMandar->obtenerLongitud() >= largo && largo > 0) {
                            if (!listaAMandar->estaVacia()) {
                                int indice = listaAMandar->obtenerLongitud() - largo, contador = 0;
                                Nodo *actual = listaAMandar->obtenerNodoInicial();

                                for (int i = 0; i < indice; i++) {
                                    actual = actual->nodoSiguiente;
                                }

                                if (!listaARecibir->estaVacia()) {
                                    if (actual->contenido->mostrar) {
                                        string numeroSiguiente = "", colorSiguiente = "";

                                        for (int i = 0; i < largo; i++) {
                                            verificarInsercionDeCarta(listaARecibir, numeroSiguiente, colorSiguiente, exit);

                                            if (actual->contenido->numero == numeroSiguiente && actual->contenido->color == colorSiguiente) {
                                                listaARecibir->ingresarDato(actual->contenido->cara);
                                                listaARecibir->obtenerNodoFinal()->contenido->mostrar = true;
                                                actual = actual->nodoSiguiente;
                                            } else {
                                                cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                                                cout << "La Carta no Cumple con el patron para juntarlas" << endl;
                                                cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                                                exit = true;
                                                break;
                                            }
                                        }

                                        if (!exit) {
                                            for (int i = 0; i < largo; i++) {
                                                listaAMandar->eliminar();
                                            }
                                            if (!listaAMandar->estaVacia()) {
                                                listaAMandar->obtenerNodoFinal()->contenido->mostrar = true;
                                            }
                                        }
                                    } else {
                                        cout << "\n++++++++++++++++++++++++++++++++++++++" << endl;
                                        cout << "No se puede trasladar Cartas Volteadas" << endl;
                                        cout << "++++++++++++++++++++++++++++++++++++++" << endl;
                                    }
                                } else {
                                    if (actual->contenido->numero == "K") {
                                        listaARecibir->ingresarDato(actual->contenido->cara);
                                        listaARecibir->obtenerNodoFinal()->contenido->mostrar = true;                         
                                    } else {
                                        cout << "\n+++++++++++++++++++++++++++++++" << endl;
                                        cout << "Solo puedes Colocar una Carta K" << endl;
                                        cout << "+++++++++++++++++++++++++++++++" << endl;
                                        exit = true;
                                    }

                                    if (!exit) {
                                        for (int i = 0; i < largo; i++) {
                                            listaAMandar->eliminar();
                                        }
                                        if (!listaAMandar->estaVacia()) {
                                            listaAMandar->obtenerNodoFinal()->contenido->mostrar = true;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (listaAMandar->estaVacia()) {
                                cout << "\n++++++++++++++++++" << endl;
                                cout << "La Fila esta Vacia" << endl;
                                cout << "++++++++++++++++++" << endl; 
                            } else {
                                cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                                cout << "No es posible tomar esa cantidad de Cartas de esta Fila" << endl;
                                cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl; 
                            }
                        }
                    } else {
                        cout << "\n++++++++++++++++++++++++++++++++++++++++" << endl;
                        cout << "Error, verifique las filas Seleccionadas" << endl;
                        cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
                    }
                } else {
                    cout << "\n++++++++++++++++++++++++++++++++++" << endl;
                    cout << "No puede Seleccionar la Misma Fila" << endl;
                    cout << "++++++++++++++++++++++++++++++++++" << endl;
                }
            } else {
                cout << "\n+++++++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "Numero fuera de Rango, Intentalo Nuevamente" << endl;
                cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
            }
        } else if (opcion == 3) {
            int AsReceptor = 0, filaARecibir = 0;
            Lista *pilaARecibir = new Lista(), *listaAMandar = new Lista();
            bool salir = false;

            cout << "---------------------------------------------" << endl;
            cout << "Escriba un Numero en las siguiente Peticiones" << endl;
            cout << endl;
            cout << "Fila para tomar la Carta: "; cin >> filaARecibir;
            cout << "Pila de Ases donde colocar la Carta: "; cin >> AsReceptor;
            cout << "---------------------------------------------" << endl << endl;

            if (AsReceptor >= 1 && AsReceptor <= 4 && filaARecibir >= 1 && filaARecibir <= 7) {
                pilaARecibir = obtenerPilaDeAs(AsReceptor, a_1, a_2, a_3, a_4);
                listaAMandar = obtenerLista(filaARecibir, lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7);

                if (!listaAMandar->estaVacia()) {
                    if (!pilaARecibir->estaVacia()) {
                        string numeroSiguiente = "", colorSiguiente = "", tipo = "", tipo2 = "";
                        verificarInsercionDeCarta2(pilaARecibir, numeroSiguiente, colorSiguiente, tipo, salir);

                        if (listaAMandar->obtenerNodoFinal()->contenido->numero == numeroSiguiente && listaAMandar->obtenerNodoFinal()->contenido->color == colorSiguiente) {
                            string contenido = listaAMandar->obtenerNodoFinal()->contenido->cara;

                            for (int i = 0; i < contenido.size(); i++) {
                                if (i == 1 || i == 2) {
                                    tipo2 += contenido[i];
                                }
                            }

                            if(tipo == tipo2) {
                                pilaARecibir->ingresarDato(listaAMandar->obtenerNodoFinal()->contenido->cara);
                                pilaARecibir->obtenerNodoFinal()->contenido->mostrar = true;
                            } else {
                                cout << "\n+++++++++++++++++++++++++++++++++++++++++" << endl;
                                cout << "La Carta no Cumple con el Patron Solitado" << endl;
                                cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
                                salir = true;
                            }
                        } else {
                            cout << "\n+++++++++++++++++++++++++++++++++++++++++" << endl;
                            cout << "La Carta no Cumple con el Patron Solitado" << endl;
                            cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
                            salir = true;
                        }

                        if (!salir) {
                            if (!listaAMandar->estaVacia()) {
                                listaAMandar->eliminar();
                                listaAMandar->obtenerNodoFinal()->contenido->mostrar = true;
                            }
                        }
                    } else {
                        cout << "Esta Vacia la Pila de As" << endl;
                    }
                } else {
                    cout << "\n++++++++++++++++++" << endl;
                    cout << "La Fila esta Vacia" << endl;
                    cout << "++++++++++++++++++" << endl;
                }
            } else {
                cout << "\n++++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "Error, verifique las filas Seleccionadas" << endl;
                cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
            }
        } else if (opcion == 4) {
            int filaAVisualizar = 0, posicion = 0;
            Lista *fila = new Lista();
            bool salir = false;

            cout << "---------------------------------------------" << endl;
            cout << "Escriba un Numero en las siguiente Peticiones" << endl;
            cout << endl;
            cout << "Fila donde quiere ver la Carta: "; cin >> filaAVisualizar;
            cout << "Posicion de la Carta de Izq a Der: "; cin >> posicion;
            cout << "---------------------------------------------" << endl;

            if (filaAVisualizar >= 1 && filaAVisualizar <= 8) {
                fila = obtenerLista(filaAVisualizar, lista_1, lista_2, lista_3, lista_4, lista_5, lista_6, lista_7);

                if (posicion >= 1 && posicion <= fila->obtenerLongitud()) {
                    Nodo *guia = fila->obtenerNodoInicial();                   
                    string valor = "";

                    for (int i = 1; i < posicion; i++) {
                        guia = guia->nodoSiguiente;
                    }
                    valor = guia->contenido->cara;     
                    cout << "\n+++++++++++++++++++++++++++++++++++++" << endl;    
                    cout << "La carta en esta posición es:   " << valor << endl;
                    cout << "+++++++++++++++++++++++++++++++++++++" << endl;
                } else {
                    cout << "\n+++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "Numero de la Posicion esta fuera de Rango" << endl;
                    cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
                }
            } else {
                cout << "\n++++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "El Numero de la fila esta fuera de Rango" << endl;
                cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
            }
        } else if (opcion == 5) {
            if (!cola_1->estaVacia()) {
                cola_2->ingresarDato(cola_1->obtenerNodoFinal()->contenido->cara);
                cola_1->eliminar();
            }
        } else if (opcion == 6) {
            salir = true;
        } else {
            cout << "\n+++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Numero fuera de Rango, Intentalo Nuevamente" << endl;
            cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
        }
    }
}

int main() {
    int opcion = 0;

    while (opcion != 2) {
        cout << endl;
        cout << "Menu Principal" << endl;
        cout << "   1. Iniciar Partida" << endl;
        cout << "   2. Salir" << endl;
        cin >> opcion;

        if (opcion == 1) {
            iniciarPartida();
        } else if (opcion != 2) {
            cout << "\n-------------------------------------------" << endl;
            cout << "Numero fuera de Rango, Intentalo Nuevamente" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
}

