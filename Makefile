
# FLAGS=-std
SRC=./src
TARGET=./bin
VPATH=src:include

all : func try class
.PHONY : all
func : func.cpp
	g++ -o ${TARGET}/func -std=c++11  ${SRC}/func.cpp

try : try.cpp
	g++ -o ${TARGET}/try -std=c++11 ${SRC}/try.cpp -I./include

class : class.cpp
	g++ -o ${TARGET}/class -std=c++11 ${SRC}/class.cpp -I./include



.PHONY: cleanall cleanfunc cleantry cleanclass
cleanall : 
	-rm -rf ${TARGET}/* libs/*.o

cleanfunc :
	-rm -rf ${TARGET}/func libs/func.o

cleanclass :
	-rm -rf ${TARGET}/class libs/class.o

cleantry :
	-rm -rf ${TARGET}/try libs/try.o

.PHONY: run
run:
	./bin/func

