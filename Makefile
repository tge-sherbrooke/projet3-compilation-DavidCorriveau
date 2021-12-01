wpi:	main.c	gpio-wpi.c
	gcc main.c gpio-wpi.c -lwiringPi -o main

libc:	main.c	gpio-libc.c 
	gcc main.c gpio-libc.c -o main
