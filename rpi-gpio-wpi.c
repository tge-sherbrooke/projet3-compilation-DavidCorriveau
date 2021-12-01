#include <wiringPi.h>   // pour utiliser les fonctions liées au GPIO
#include <stdlib.h>     // pour utiliser atoi()
#include <string.h>     // pour utiliser strcmp()

void main( int argc, char **argv ) 
{
    int pin = atoi(argv[1]);    // Prend le premier argument (numéro de la pin) et la met dans une variable integer
    wiringPiSetupGpio();        // initialisation pour que les gpio fonctionnent
    pinMode(pin, OUTPUT);       // met la pin en mode sortie
    if(strcmp(argv[2],"on") == 0)   // si on veut que la pin soit à on
    {
        digitalWrite(pin, HIGH);    // met la pin à on
    }
    else if (strcmp(argv[2],"off") == 0)    // si on veut que la pin soit à off
    {
        digitalWrite(pin, LOW);     // met la pin à off
    }
}

