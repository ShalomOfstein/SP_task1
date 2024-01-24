CC = gcc
AR = ar
FLAGS = -Wall
OB_LOOP = basicClassification.o advancedClassificationLoop.o
OB_REC = basicClassification.o advancedClassificationRecursion.o

#compile and link all the files
all: loops recursives recursived loopd mains maindloop maindrec

#compile the libraries
loops: libclassloops.a
recursives: libclassrec.a
recursived: libclassesrec.so
loopd: libclassloops.so


#make the libraries:
libclassloops.a: $(OB_LOOP)
	$(AR) rcs libclassloops.a $(OB_LOOP)

libclassrec.a: $(OB_REC)
	$(AR) rcs libclassrec.a $(OB_REC)

libclassesrec.so: $(OB_REC)
	$(CC) -shared -o libclassesrec.so $(OB_REC)

libclassloops.so: $(OB_LOOP)
	$(CC) -shared -o libclassloops.so $(OB_LOOP)


#compile the different mains
mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o libclassloops.so

maindrec: main.o libclassesrec.so
	$(CC) $(FLAGS) -o maindrec main.o libclassesrec.so


#make the object files
main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c -o main.o

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c -o basicClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -o advancedClassificationLoop.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o


#to ensure that there isnt a "clean"/"all" file in the directory
.PHONY: clean all

#clean all the compiled files and leave the .txt/ .c / .h files
clean:
	rm -f *.o *.a *.so mains maindloop maindrec

