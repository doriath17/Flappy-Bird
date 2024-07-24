CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++20 

SFML = /home/kepler17/cpp/GameDev/SFML-2.6.1
ILIB = -I $(SFML)/include
LLIB = -L $(SFML)/lib -lsfml-graphics -lsfml-window -lsfml-system

OBJ = src/obj/main.o src/obj/bird.o src/obj/pipes.o \
src/obj/mainwindow.o src/obj/txtrrecord.o

app: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LLIB)

src/obj/bird.o: src/bird.cpp header/bird.hpp header/birds_and_pipes.hpp 
	$(CXX) $(CXXFLAGS) $(ILIB) -I header -o $@ -c $<

src/obj/pipes.o: src/pipes.cpp header/pipes.hpp header/birds_and_pipes.hpp
	$(CXX) $(CXXFLAGS) $(ILIB) -I header -o $@ -c $<

src/obj/mainwindow.o: src/mainwindow.cpp header/birds_and_pipes.hpp
	$(CXX) $(CXXFLAGS) $(ILIB) -I header -o $@ -c $<

src/obj/txtrrecord.o: src/txtrrecord.cpp header/birds_and_pipes.hpp
	$(CXX) $(CXXFLAGS) $(ILIB) -I header -o $@ -c $<

src/obj/main.o: src/main.cpp header/birds_and_pipes.hpp
	$(CXX) $(CXXFLAGS) $(ILIB) -I header -o $@ -c $<

clean:
	rm src/obj/*.o

## touch all
ta: 
	touch src/*.cpp
	touch header/*.hpp

folders:
	mkdir header src src/obj