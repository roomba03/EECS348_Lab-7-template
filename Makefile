CC := gcc

football.exe: football_main.c football.c football.h
	$(CC) -Wall -Wextra -Werror -o football.exe football_main.c football.c

temperature.exe: temperature_main.c temperature.c temperature.h
	$(CC) -Wall -Wextra -Werror -o temperature.exe temperature_main.c temperature.c

clean:
	rm -f football.exe
	rm -f temperature.exe