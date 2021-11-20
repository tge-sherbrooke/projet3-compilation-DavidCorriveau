#include <wiringPi.h>   // pour utiliser les fonctions liées au GPIO
#include <string.h>     // pour utiliser strcmp()
#include <stdlib.h>     // pour utiliser atoi()


void setgpio(char *pin, char *etat)
{
    int pinInt = atoi(pin);    // Prend le premier argument (numéro de la pin) et la met dans une variable integer
    wiringPiSetupGpio();        // initialisation pour que les gpio fonctionnent
    pinMode(pinInt, OUTPUT);       // met la pin en mode sortie
    if(strcmp(etat,"on") == 0)   // si on veut que la pin soit à on
    {
        digitalWrite(pinInt, HIGH);    // met la pin à on
    }
    else if (strcmp(etat,"off") == 0)    // si on veut que la pin soit à off
    {
        digitalWrite(pinInt, LOW);     // met la pin à off
    }
}