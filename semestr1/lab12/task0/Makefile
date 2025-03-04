CC = gcc
CFLAGS = -Wall -Iapp -Ibackground -Ipipes -Wno-main -Wno-unused-variable

task0: app/main.o background/background.o  pipes/read_pipe.o pipes/write_pipe.o
	$(CC) -o task0 app/main.o background/background.o pipes/read_pipe.o pipes/write_pipe.o

app/main.o: app/main.c
	$(CC) $(CFLAGS) -c app/main.c -o app/main.o

background/background.o:  background/background.c
	$(CC) $(CFLAGS) -c background/background.c -o background/background.o

pipes/read_pipe.o: pipes/read_pipe.c
	$(CC) $(CFLAGS) -c pipes/read_pipe.c -o pipes/read_pipe.o

pipes/write_pipe.o: pipes/write_pipe.c
	$(CC) $(CFLAGS) -c pipes/write_pipe.c -o pipes/write_pipe.o

clean:
	rm -f app/*.o background/*.o pipes/*.o task0
