wpi:	main.c	gpio-wpi.c
	gcc main.c gpio-wpi.c -l wiringPi -o main

libc:	main.c	gpio-libc.c 
	gcc main.c gpio-libc.c -o main
