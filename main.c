#include "gpio.h"      

void main( int argc, char **argv)
{
    setgpio(argv[1], argv[2]);
}