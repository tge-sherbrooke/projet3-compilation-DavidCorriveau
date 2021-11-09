#include <wirinPi.h>

main(int argc, char **argv)
{
    wiringPiSetupGpio();
    pinMode(argv[1],OUTPUT);
    if(argv[2] == "on")
    {
        digitalWrite(argv[1],1);
    }
    else if (argv[2] == "off")
    {
        digitalWrite(argv[1],0);
    }
}

