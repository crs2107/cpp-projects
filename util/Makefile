SRC = $(shell pwd)
#_parentDIR := $(SRC)/..
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -lpthread
# LINKDIR = Library Sources

#LIB_TYPE = {static,shared}
LIB_TYPE = $(LIB)

ifeq ($(LIB_TYPE),shared)
   LIB_EXT = so
else
   LIB_EXT = a
endif

OBJECTS = $(addsuffix .o, $(basename $(wildcard *.cpp)))
HEADERS = $(wildcard *.h)

ifeq ($(shell uname),Linux)
	OS = linux
endif
ifeq ($(shell uname | head -c 6),CYGWIN)
	OS = Cygwin
endif

TARGET := util-$(OS).$(LIB_EXT)

# SUB_DIR = $(patsubst %,$(SRC)/%,$(LINKDIR))
# EXT_OBJECTS = $(patsubst %,$(SRC)/%/*-$(OS).$(LIB_EXT),$(LINKDIR))

default : target

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

$(OBJECTS) : $(HEADERS)

target: $(OBJECTS)
	ld -r -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(TARGET) $(OBJECTS)
