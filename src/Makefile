DIR := ${CURDIR}

ifndef FF_ROOT 
# FF_ROOT		= ${DIR}
FF_ROOT		= ${HOME}/fastflow
endif

CXX			= g++ -std=c++2a 
CXX11		= g++-11 -std=c++2a
INCLUDES	= -I $(FF_ROOT) 
CXXFLAGS  	= -g # -DBLOCKING_MODE -DFF_BOUNDED_BUFFER

LDFLAGS 	= -pthread
OPTFLAGS	= -finline-functions -w -DNDEBUG -O3

PRELDFLAGS 	= LD_PRELOAD=${DIR}/jemalloc/lib/libjemalloc.so.2

TARGETS 	=	build/Sequential_Implementation \
				build/Threads_Implementation \
				build/ff_Implementaion

.PHONY: all clean

.SUFFIXES: .cpp 

all: $(TARGETS)

build/Sequential_Implementation:Sequential_Implementation.cpp
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -o $@ $^ $(LDFLAGS)

build/Threads_Implementation:Threads_Implementation.cpp
	$(CXX11) $(CXXFLAGS) $(OPTFLAGS) -o $@ $^ $(LDFLAGS)
	
build/ff_Implementaion:ff_Implementaion.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OPTFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf build/*