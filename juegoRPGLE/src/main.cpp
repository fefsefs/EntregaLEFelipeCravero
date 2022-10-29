#include "Libreria.hpp"

#define DEFAULT 0
// estados de menu principal
#define ESTADO_ATAQUE 1
#define ESTADO_MENU 2
#define ESTADO_TERMINAR 3
// estados menu config
#define ESTADO_BORRAR 4
#define ESTADO_DEFINIR_STATS 5
#define ESTADO_DEFINIR_CLASE 6
#define ESTADO_TERMINAR_CONFIG 7
#define ESTADO_GUARDAR 8
// estados de clase elegida
#define ESTADO_ARCHER 'A'
#define ESTADO_WARRIOR 'W'
#define ESTADO_MAGE 'M'

int estadoActual;
int estadoMenu;
int terminarJuego;
char estadoClaseActual = ' ';
bool tempAsigBool;
bool tempMenuConfig;
bool tempPrimerInicio;
bool flagAsigClase;

int main()
{
    // Personajes character1;
    Archer Archer1;
    Warrior Warrior1;
    Mage Mage1;

    estadoActual = ESTADO_MENU;
    estadoMenu = ESTADO_DEFINIR_CLASE;
    // SWITCH MAYOR, LO USO PARA PELEAR, IR AL MENU Y TERMINAR
    do
    {
        initPrint();
        if (tempPrimerInicio == 1)
        {
            Clear();
            cout << "Bienvenido al Menu Principal" << endl
                 << "Insertar: " << endl
                 << "[1] para Jugar" << endl
                 << "[2] para ir al menu de configuracion del personaje" << endl
                 << "[3] para cerrar el juego:" << endl;
            cin >> estadoActual;
        }
        switch (estadoActual)
        {
        // ESTADO DE PELEA
        case ESTADO_ATAQUE:
            cout << "Vida actual de monstruo = " << vidaMonstruo << endl;
            // SWITCH PARA ATACAR SEGUN LA CLASE QUE USAS
            switch (estadoClaseActual)
            {
            case ESTADO_ARCHER:
                Archer1.DispararF();
                cuentaDeMuertes++;
                monstruoMuerto = 0;
                break;
            case ESTADO_WARRIOR:
                Warrior1.Golpear();
                cuentaDeMuertes++;
                monstruoMuerto = 0;
                break;
            case ESTADO_MAGE:
                Mage1.DispararFB();
                cuentaDeMuertes++;
                monstruoMuerto = 0;
                break;
            default:
                break;
            }
            break;
        // ESTADO MENU
        case ESTADO_MENU:
            do
            {
                cout << "Bienvenido al menu " << endl
                     << "[4] para Borrar el personaje" << endl
                     << "[5] para definir las stats" << endl
                     << "[6] para definir la clase" << endl
                     << "[7] para salir de la configuracion del personaje:" << endl
                     << "[8] para guardar en un archivo La config de tu personaje" << endl;
                cin >> estadoMenu;
                // SWITCH PARA CAMBIAR DE COSA PARA HACER EN EL MENU, BORRAR, DEFINIR STATS, DEFINIR CLASE
                switch (estadoMenu) //%%ERROR%% el switch no lee la asignacion de antes estadoMenu = ESTADO_DEFINIR_CLASE
                {
                // ESTADO PARA BORRAR PJ
                case ESTADO_BORRAR:
                    cout << "desea borrar los datos del personaje? 1 si, 0 no: ";
                    cin >> tempBool;
                    switch (estadoClaseActual)
                    {
                    case ESTADO_ARCHER:
                        Archer1.Borrar(tempBool);
                        break;
                    case ESTADO_MAGE:
                        Mage1.Borrar(tempBool);
                        break;
                    case ESTADO_WARRIOR:
                        Warrior1.Borrar(tempBool);
                        break;
                    }

                    break;
                // ESTADO PARA DEFINIR STATS
                case ESTADO_DEFINIR_STATS:
                    if (estadoClaseActual == ESTADO_ARCHER || estadoClaseActual == ESTADO_MAGE || estadoClaseActual == ESTADO_WARRIOR)
                    {
                        do
                        {
                            if (estadoClaseActual == ESTADO_ARCHER)
                            {
                                Archer1.Nombrar();
                                Archer1.Definirstats();
                            }
                            if (estadoClaseActual == ESTADO_WARRIOR)
                            {
                                Warrior1.Nombrar();
                                Warrior1.Definirstats();
                            }
                            if (estadoClaseActual == ESTADO_MAGE)
                            {
                                Mage1.Nombrar();
                                Mage1.Definirstats();
                            }
                            cout << "desea distribuir de vuelta las stats? 1 si, 0 no : " << endl;
                            cin >> tempBool;
                            if (tempBool == 1)
                            {
                                cout << "asigne de vuelta las stats y el nombre " << endl;
                                tempAsigBool = 0;
                            }
                            else
                            {
                                tempAsigBool = 1;
                            }
                        } while (tempAsigBool == 0);
                    }
                    else
                    {
                        cout << "No definiste una clase todavia" << endl;
                    }
                    break;
                // ESTADO PARA DEFINIR CLASE
                case ESTADO_DEFINIR_CLASE:
                    do
                    {
                        cout << "que clase quiere asignarle a su personaje? A para archer, M para mage, W para warrior: " << endl;
                        cin >> estadoClaseActual;
                        if (estadoClaseActual == 'A' || estadoClaseActual == 'M' || estadoClaseActual == 'W')
                        {
                            flagAsigClase = 1;
                            cout << "Clase asignada correctamete" << endl;
                        }
                        else
                        {
                            cout << "Insertar devuelta" << endl;
                        }
                    } while (flagAsigClase != 1);
                    break;
                case ESTADO_GUARDAR:
                    switch (estadoClaseActual)
                    {
                    case ESTADO_ARCHER:
                        Archer1.guardarTXT();
                        break;
                    case ESTADO_MAGE:
                        Mage1.guardarTXT();
                        break;
                    case ESTADO_WARRIOR:
                        Warrior1.guardarTXT();
                        break;
                    }
                    cout << "clase guardada " << endl;
                    break;
                case ESTADO_TERMINAR_CONFIG:
                    cout << "saliendo del la configuracion...";
                    tempMenuConfig = 1;
                    break;
                // DEFAULT
                default:
                    cout << "Insertar devuelta";
                    break;
                }
            } while (tempMenuConfig == 0);
            break;
        case ESTADO_TERMINAR:
            cout << "Saliendo del juego...";
            terminarJuego = 1;
            break;
        default:
            cout << "Insertar devuelta" << endl;
            break;
        }
        tempPrimerInicio = 1;
    } while (terminarJuego == 0);

    return 0;
}

/*
NOTAS******************************************************
Preguntar al profe como poder crear instancias de clases segun lo que el usuario ingreso, principalmente para poder encapsular los personajes en diferentes instancias IDEA:
ovejero Rintin= new ovejero;
FECHAS*****************************************************
SABADO 11/6: CREE Y DEFINI METODOS DE LA CLASE PERSONAJES, FALTA PENSAR QUE PONER EN EL MAIN PARA EL COMPORTAMIENTO DEL JUEGO. NO SE SI HACER UNA MAQUINA DE ESTADOS O NO
VIERNES 24/6: CREE EL MAIN Y ME DECIDI POR TOMAR VARIOS SWITCH CASE Y ANIDARLOS PARA HACER LA NAVEGACION EN LOS MENUES DEL JUEGO
FALTA DEFINIR LOS METODOS ESPECIFICOS DE LAS CLASES HEREDADAS Y TERMINAR LA NAVEGACION DE LOS MENUES.
*/
