#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
// DEFINO UN MACRO PARA SABER LAS STATS MAXIMAS A DISTRIBUIR
#define STATMAX 10
#define DANIO_MONSTRUO 1

using namespace std;

// DEFINO LAS VARIABLE TEMPORALES QUE VOY A USAR
char tempChar;
bool tempBool;
int tempIndex;
bool statFlag = 0;
char attkDelay;
int vidaMonstruo = 50;
int vidaAtaque = 0;
bool monstruoMuerto = 0;
int numAleatorio = 0;
int cuentaDeMuertes = 0;

int AleatorioAtaque(void);
void Clear(void);
void initPrint(void);
// CLASE PRINCIPAL, DONDE GUARDO LA VIDA, EL DANIO Y EL NOMBRE DE LOS PERSONAJES
class Personajes
{
protected:
    int vida;
    int danio;
    string Nombre;

public:
    Personajes(void){};

    void Nombrar(void);
    void Borrar(bool);
    void Definirstats(void);
    void guardarTXT(void);
};
// METODO PARA CAMBIAR NOMBRE
void Personajes::Nombrar(void)
{
    cout << "Ingrese el nombre de su personaje: ";
    cin >> Nombre;
}

// METODO PARA BORRAR STAS Y NOMBRE DE PJ
void Personajes::Borrar(bool YNBorrar)
{
    if (YNBorrar != 0)
    {
        bool chek;
        cout << "esta seguro? 1 si, 0 no" << endl;
        cin >> chek;
        if (chek == 1)
        {
            vida = 0;
            danio = 0;
            Nombre = " ";
            cout << "los datos de su personaje fueron borrados" << endl;
        }
    }
}

// METODO PARA LA INTERFAZ DE DEFINICION DE CARACTERISTICAS DE PJ (SE APLICAN CON EL CONTRUCTOR)
void Personajes::Definirstats(void)
{
    cout << "tiene 10 puntos para gastar" << endl;
    do
    {
        cout << "insertar la vida de su personaje" << endl;
        cin >> vida;
        if (1 <= vida <= 10)
        {
            cout << "La cantidad de vida a sido insertada ahora inserte el daño" << endl;
            cin >> danio;
            if (danio + vida == STATMAX)
            {
                cout << "La asignacion a sido terminada" << endl;
                statFlag = 1;
            }
            else
            {
                cout << "No ha insertado valores correctos" << endl;
            }
        }
    } while (statFlag != 1);
}
void Personajes::guardarTXT(void)
{
    ofstream file("..\\file\\Proyecto.txt", ios::app | ios::out);
    file << "Nombre del personaje: " << Nombre << endl;
    file << "Vida del personaje: " << vida << endl;
    file << "Daño del personaje: " << danio << endl;
    file << "Cuentas de muertes: " << cuentaDeMuertes << endl;
    file.close();
}
// MINI SECCION PARA DEFINIR FUNCIONES UTILES
int AleatorioAtaque(void)
{
    srand(time(NULL));
    int temp = rand() % 48;
    return temp;
}
void Clear()
{
    cout << "\x1B[2J\x1B[H";
}

void initPrint(void)
{
    Clear();
    std::cout << R"(            ____________ _____ _____    
            | ___ \ ___ \  __ \  __ \           
            | |_/ / |_/ / |  \/ |  \/             
            |    /|  __/| | __| | __             
            | |\ \| |   | |_\ \\ |_\ \         
            \\_| \_\_|   \____/\\____/ )"
              << std::endl;
}
// CLASES HEREDADAS PARA DEFINIR LA ORIENTACION DEL PJ***************************
class Archer : public Personajes
{
public:
    void DispararF(void);
};
// declaro ataque de la clase archer
void Archer::DispararF(void)
{
    cout << "El arquero dispara una flecha..." << endl;
    vidaAtaque = vida;
    // un tercio de chance, ataque normal
    do
    {
        Clear();
        numAleatorio = AleatorioAtaque();

        if (0 <= numAleatorio && numAleatorio <= 32)
        {
            vidaMonstruo -= danio;
            cout << "Tu ataque alcanzo el monstruo!, -" << danio << " Life Points, presione cualquier letra para continuar" << endl;
            cout << "Tu vida actual: " << vidaAtaque << "|| Vida del monstruo: " << vidaMonstruo << endl;
            cin >> attkDelay;
        }
        else if (33 <= numAleatorio && numAleatorio <= 44)
        {
            cout << "tu ataque fallo :(, presione cualquier letra para continuar" << endl;
            vidaAtaque--;
            cout << "Tu vida actual: " << vidaAtaque << "|| Vida del monstruo: " << vidaMonstruo << endl;
            cin >> attkDelay;
        }
        else
        {
            vidaMonstruo - danio * 2;
            cout << "Tu ataque fue un critico, -" << danio * 2 << " Life Points, presione cualquier letra para continuar" << endl;
            cout << "Tu vida actual: " << vidaAtaque << "|| Vida del monstruo: " << vidaMonstruo << endl;
            cin >> attkDelay;
        }
        cout << "Vida del monstruo :" << vidaMonstruo << endl;
        if (vidaMonstruo <= 0)
        {
            monstruoMuerto = 1;
            vidaAtaque = vida;
            vidaMonstruo = 50;
            cout << "Felicidades mataste al monstruo, presione cualquier letra para continuar" << endl;
            cin >> attkDelay;
        }
    } while (monstruoMuerto == 0);
}

class Warrior : public Personajes
{
public:
    void Golpear(void);
};
// declaro ataque de la clase warrior
void Warrior::Golpear(void)
{
    cout << "El guerrero empunia su hacha..." << endl;
    vidaAtaque = vida;
    // ataque normal
    do
    {
        Clear();
        numAleatorio = AleatorioAtaque();

        if (0 <= numAleatorio && numAleatorio <= 32)
        {
            vidaMonstruo -= danio;
            cout << "Tu ataque alcanzo el monstruo!, -" << danio << " Life Points, presione cualquier letra para continuar" << endl;
            cout << "Tu vida actual: " << vidaAtaque << "|| Vida del monstruo: " << vidaMonstruo << endl;
            cin >> attkDelay;
        }
        else if (33 <= numAleatorio && numAleatorio <= 46)
        {
            cout << "tu ataque fallo :( , presione cualquier letra para continuar" << endl;
            vidaAtaque--;
            cout << "Tu vida actual: " << vidaAtaque << "|| Vida del monstruo: " << vidaMonstruo << endl;
            cin >> attkDelay;
        }
        else
        {
            vidaMonstruo - danio * 2;
            cout << "Tu ataque fue un critico, -" << danio * 3 << " Life Points, presione cualquier letra para continuar" << endl;
            cout << "Tu vida actual: " << vidaAtaque << "|| Vida del monstruo: " << vidaMonstruo << endl;
            cin >> attkDelay;
        }
        cout << "Vida del monstruo :" << vidaMonstruo << endl;
        if (vidaMonstruo <= 0)
        {
            monstruoMuerto = 1;
            vidaAtaque = vida;
            vidaMonstruo = 50;
            cout << "Felicidades mataste al monstruo, presione cualquier letra para continuar" << endl;
            cin >> attkDelay;
        }
    } while (monstruoMuerto == 0);
}
class Mage : public Personajes
{
public:
    void DispararFB(void);
};
// declaro ataque de la clase mage
void Mage::DispararFB(void)
{
    cout << "El mago crea una bola de fuego..." << endl;
    vidaAtaque = vida;
    // un tercio de chance, ataque normal
    do
    {
        Clear();
        numAleatorio = AleatorioAtaque();

        if (0 <= numAleatorio && numAleatorio <= 32)
        {
            vidaMonstruo -= danio;
            cout << "La bola de fuego alcanzo el monstruo!, -" << danio << " Life Points, presione cualquier letra para continuar" << endl;
            cout << "Tu vida actual: " << vidaAtaque << "|| Vida del monstruo: " << vidaMonstruo << endl;
            cin >> attkDelay;
        }
        else if (33 <= numAleatorio && numAleatorio <= 40)
        {
            cout << "tu ataque fallo :( recibiste 1 de daño, presione cualquier letra para continuar" << endl;
            vidaAtaque--;
            cout << "Tu vida actual: " << vidaAtaque << "|| Vida del monstruo: " << vidaMonstruo << endl;
            cin >> attkDelay;
        }
        else
        {
            vidaMonstruo - danio * 2;
            cout << "Tu ataque fue un critico, -" << danio * 1.5 << " Life Points, presione cualquier letra para continuar" << endl;
            cout << "Tu vida actual: " << vidaAtaque << "|| Vida del monstruo: " << vidaMonstruo << endl;
            cin >> attkDelay;
        }
        cout << "Vida del monstruo :" << vidaMonstruo << endl;
        if (vidaMonstruo <= 0)
        {
            monstruoMuerto = 1;
            vidaAtaque = vida;
            vidaMonstruo = 50;
            cout << "Felicidades mataste al monstruo, presione cualquier letra para continuar" << endl;
            cin >> attkDelay;
        }
    } while (monstruoMuerto == 0);
}
// calse para numeros complejos con sobrecarga
class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() { cout << real << " + i" << imag << '\n'; }
};
//*******************************************************************************