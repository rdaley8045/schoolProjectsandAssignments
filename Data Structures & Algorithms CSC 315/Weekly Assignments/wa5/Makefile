HEATMAP_SRC = heatMap.cpp application.cpp function.cpp

HASHTABLE_SRC = hashTable.cpp

MAIN_SRC = main.cpp

HEATMAP_OBJS = $(HEATMAP_SRC:.cpp=.o)

HASHTABLE_OBJS = $(HASHTABLE_SRC:.cpp=.o)

MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

CXXFLAGS = -lstdc++fs -Wall -g
LIBS = -lGL -lX11 -lpng -lstdc++fs -lpthread

#GNU C/C++ compiler
GCC = g++

#GNU C/C++ linker
LINK = g++

all: heatMap main

heatMap: $(HEATMAP_OBJS) $(HASHTABLE_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

main: $(MAIN_OBJ) $(HASHTABLE_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.d core heatMap main

tar:
	tar cvf HashTable.tar $(HEATMAP_SRC) $(HASHTABLE_SRC) $(MAIN_SRC) Makefile *.h

debug: CXXFLAGS = -DDEBUG -g -Wall
debug: main

help:
	@echo " make heatMap    - build the heatMap visualization"
	@echo " make main       - build the simple main executable"
	@echo " make clean      - remove .o .d core main heatMap"
	@echo " make tar        - bundle everything up into a tarball"
	@echo " make help       - this message"

-include $(HEATMAP_SRC HASHTABLE_SRC MAIN_SRC:.cpp=.d)

%.d: %.cpp
	@set -e ; rm -rf $@; $(GCC) -MM $< $(CXXFLAGS) > $@
