#Name: Chris Murphy
#Date:3/1/18
#Assignment: Chebyshev
#File name: makefile

CXX = /usr/bin/g++
CXXFLAGS = -std=c++11 -g -Wall -W -pedantic-errors

OBJECTS = driver.o

#Suffix rules
.SUFFIXES: .cpp

.cpp.o: $<
	${CXX} -c ${CXXFLAGS} $< -o $@

default: all

all: driver

#Dependencies
driver: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@

driver.o: driver.cpp array newton nodegen HCfunc interpol poleval cheberr argerr OOB sizeerr

array: array.h array.hpp

newton: newton.h newton.hpp

nodegen: nodegen.h nodegen.hpp

HCfunc: HCfunc.h HCfunc.hpp

interpol: interpol.h interpol.hpp

poleval: poleval.h poleval.hpp

cheberr: cheberr.h cheberr.hpp

argerr: argerr.h

OOB: OOB.h

sizeerr: sizeerr.h

clean:
	-@rm core
	-@rm driver
	-@rm ${OBJECTS}