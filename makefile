CC=g++
CFLAGS=-c -std=c++11 -Wall
LDFLAGS=
LDLIBS=-lboost_chrono -lboost_system

SRCPATH=$(CURDIR)/TestProject
SOURCES=$(wildcard $(SRCPATH)/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=FiboCalc

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) ${LDLIBS} -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
