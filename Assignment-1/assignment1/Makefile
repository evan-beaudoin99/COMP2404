all: a1

OBJS = Tester.o Reservation.o Date.o Rental.o Category.o HomeShare.o main.o

a1: $(OBJS) 
	g++ -g $(OBJS) -o a1

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc

HomeShare.o: HomeShare.cc HomeShare.h
	g++ -c HomeShare.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -c Reservation.cc

Rental.o: Rental.cc Rental.h
	g++ -c Rental.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Category.o: Category.cc Category.h
	g++ -c Category.cc

main.o: main.cc Tester.h HomeShare.h Rental.h Category.h 
	g++ -c main.cc

clean:
	rm -f *.o a1