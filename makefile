students: student.o date.o address.o main.o
	g++ -g date.o student.o address.o main.o -o students

main.o: main.cpp student.h address.h date.h
	g++ -c -g main.cpp

student.o: student.h address.h date.h student.cpp
	g++ -c -g student.cpp

address.o: address.h address.cpp
	g++ -c -g address.cpp

date.o: date.h date.cpp
	g++ -c -g date.cpp

clean:
	rm *.o
	rm students

debug: students
	gdb students

run: students
	./students

valgrind: students
	valgrind --leak-check=full ./students
