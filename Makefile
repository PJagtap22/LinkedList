CC = g++ 
CFLAG = 

main.exe: main.o Dll.o 
    $(CC) $(CFLAG) -o main.exe main.o Dll.o

Dll.o: main.cpp Dll.h
    $(cc) $(CFLAG) -c main1.cpp

Dll.o: Dll.cpp Dll.h
    $(CC) $(CFLAG) -c Dll.cpp

Clean :
    rm -f main.exe *o

     