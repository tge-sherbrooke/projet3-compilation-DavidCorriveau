wpi:	main.c	gpio-wpi.c
	sudo gcc main.c gpio-wpi.c -o main -I/usr/local/include -L/usr/local/lib -lwiringPi

libc:	main.c	gpio-libc.c
	sudo gcc main.c gpio-libc.c -o main