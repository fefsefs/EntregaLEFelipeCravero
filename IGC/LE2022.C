#include <stdio.h>
#include <math.h>
#define TAM 10
// DECLARACION DE ESTRUCTURAS, VARIABLES Y PROTOTIPOS
struct persona{
    float Altura;
    float Peso;
    float Edad;
    float GrasaCorporal;
    float Porcentajes[TAM];
    int Genero;
}P;

int Continuar = 0;
int c,i,j,temp;

float CalculoParaMujeres (float, float, float, float);
float CalculoParaHombres (float, float, float, float);
//----------------------------------------------------
int main()
{
    //DO WHILE PARA LA INTRODUCCION DE LOS DATOS PARA LA ESTRUCUTURA
    do{
        printf("Bienvenido, insertar La altura en metros\n");
        scanf("%f", &P.Altura);
        printf("Ahora su peso en kilos\n");
        scanf("%f", &P.Peso);
        printf("Ahora su edad en años\n");
        scanf("%f", &P.Edad);
        printf("Ahora Genero, 1 para hombre, 0 para mujer\n");
        scanf("%d", &P.Genero);
        if (P.Genero == 1)
        {
            P.GrasaCorporal = CalculoParaHombres(P.Altura, P.Peso, P.Edad, P.GrasaCorporal);
            for(c = 0; c++; c < 10)
            {
                P.Porcentajes[c] = P.GrasaCorporal;
            }
        }
        else if (P.Genero == 0)
        {
            P.GrasaCorporal = CalculoParaMujeres(P.Altura, P.Peso, P.Edad, P.GrasaCorporal);
            for(c = 0; c++; c < 10)
            {
                P.Porcentajes[c] = P.GrasaCorporal;
            }
        }
        else printf("No se inserto una opcion apta");
        printf("¿Desea continuar insertando datos? 1 para ver el orden, 0 para seguir insertando hasta un maximo de 10\n");
        scanf ("%d", &Continuar);
    }while(Continuar == 0);
    //----------------------------------------------------
    //SI CONTINUAR ENTRA EN 1 SE SALE DEL DO WHILE PARA COMENZAR EL BUBBLESORT Y ORDENAR DE MENOR A MAYOR
    //LOS PORCENTAJES
    printf("orden de menor a mayor de los porcentajes:\n");

    for (i=1; i<TAM; i++){

        for (j=0; j<(TAM-1); j++){

            if (P.Porcentajes[j] > P.Porcentajes[j+1]){

                temp = P.Porcentajes[j];

                P.Porcentajes[j] = P.Porcentajes[j+1];

                P.Porcentajes[j+1] = temp;
            }
        }
    }
    for(i=0;i<TAM;i++)printf("%f \t",P.Porcentajes[i]);
    //----------------------------------------------------
    return 0;
}
//CONTENIDO DE LAS VARIBLES PARA EL CALCULO DEL IGC
float CalculoParaMujeres (float Altura,float Peso,float Edad,float GrasaCorporal){
    float IMC = Peso/pow(Altura, 2);
    GrasaCorporal = 1.2 * IMC + 0.23 * Edad - 5.4;
    printf("Grasa Corporal: %f (Los resultados no son exactos)\n", GrasaCorporal);
    return GrasaCorporal;
}
float CalculoParaHombres (float Altura,float Peso,float Edad,float GrasaCorporal){
    float IMC = Peso/pow(Altura, 2);
    GrasaCorporal = 1.2 * IMC + 0.23 * Edad - 10.8 - 5.4;
    printf("Grasa Corporal: %f (Los resultados no son exactos)\n", GrasaCorporal);
    return GrasaCorporal;
}
//----------------------------------------------------



