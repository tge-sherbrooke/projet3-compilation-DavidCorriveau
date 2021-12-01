wpi:	main.c	gpio-wpi.c
	gcc main.c gpio-wpi.c -o main -lwiringPi

libc:	main.c	gpio-libc.c
	gcc main.c gpio-libc.c -o main