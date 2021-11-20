#include <fcntl.h>      // Pour uttiliser la fonction open
#include <string.h>     // Pour utiliser les fonction avec les strings
#include <unistd.h>     // Pour uttiliser les fonctions write, close et sleep

#define LONGUEUR 40     // Longeur des tableaux qui n'ont aucune valeur au début pour éviter des erreurs en exécutant le programme

void main( int argc, char **argv)
{
    char export[] = "/sys/class/gpio/export";       // String qui contient l'endroit du fichier où on export le gpio voulu
    char unexport[] = "/sys/class/gpio/unexport";   // String qui contient l'endroit du ficheir où on unexport le gpio voulu
    char gpio[] = "/sys/class/gpio/gpio";           // String qui contient le début de l'endroit du fichier où l'on peut changer les paramètre d'un gpio
    char direction[] = "/direction";                // String qui contient la fin de l'endroit du fichier où l'on peut changer le gpio voulu en entrée ou sortie
    char valeur[] = "/value";                       // String qui contient la fin de l'endroit du fichier où l'on peut changer l'état du gpio voulu
    char fichierDirection[LONGUEUR] = " ";          // String qui va contenir l'endroit du fichier pour changer le gpio voulu en entrée ou sortie
    char fichierValeur[LONGUEUR] = " ";             // String qui va contenir l'endroit du fichier pour changer l'état du gpio voulu
    int fd = 0;                                     // Variable qui représente le numéro du fichier ouvert par la fonction open

    fd = open(export, O_WRONLY);            // Ouvre le fichier d'export des gpio
    write(fd, argv[1], strlen(argv[1]));    // Écrit le numéro du gpio voulu dans ce fichier pour l'exporté
    fd = close(fd);                         // Ferme ce fichier

    sleep(1);                               // Délai de 1s, car les nouveaux paramètres des gpio ne changeront pas à cause que ce serait trop vite sans délai

    strcpy(fichierDirection,gpio);          // Assemble une string qui contient l'endroit du fichier pour changer le gpio voulu en entrée ou sortie
    strcat(fichierDirection,argv[1]);
    strcat(fichierDirection,direction);

    fd = open(fichierDirection, O_WRONLY);  // Ouvre le fichier pour changer le gpio en entrée ou sortie
    write(fd,"out",strlen("out"));          // Écrit out dans ce fichier pour mettre le gpio voulu en sortie
    fd = close(fd);                         // Ferme ce fichier

    strcpy(fichierValeur,gpio);             // Assemble une string qui contient l'endroit du fichier pour changer l'état du gpio voulu
    strcat(fichierValeur,argv[1]);
    strcat(fichierValeur,valeur);

    if(strcmp(argv[2],"on") == 0)           // Si en paramètre on a écrit "on"
    {

        fd = open(fichierValeur, O_WRONLY); // Ouvre le fichier pour changer l'état du gpio voulu
        write(fd,"1", strlen("1"));         // Écrit 1 dans ce fichier pour mettre le gpio sur un niveau haut
        fd = close(fd);                     // Ferme ce fichier
    }
    else if (strcmp(argv[2],"off") == 0)    // Si en paramètre on a écrit "off"
    {
        fd = open(fichierValeur, O_WRONLY); // Ouvre le fichier pour changer l'état du gpio voulu
        write(fd,"0", strlen("0"));         // Écrit 0 dans ce fichier pour mettre le gpio sur un niveau bas
        fd = close(fd);                     // Ferme ce fichier
    }

    fd = open(unexport, O_WRONLY);          // Ouvre le fichier pour unexport les gpio
    write(fd,argv[1],strlen(argv[1]));      // Écrit le numéro du gpio voulu pour l'unexport 
    fd = close(fd);                         // Ferme ce fichier

}