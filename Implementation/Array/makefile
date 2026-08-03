ex1.o : imp.o app.o
	g++ imp.o app.o -o ex1
imp.o : imp.cpp header.h
	g++ -c imp.cpp
app.o : app.cpp header.h
	g++ -c app.cpp
