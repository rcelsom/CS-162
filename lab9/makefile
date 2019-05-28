####################################################################
#Program Name:Makefile
#Author: Robert Elsom
#Date: 3/2/2019
#Description: Makefile for lab 9
###################################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall			#turns on all warnings
CXXFLAGS += -pedantic-errors		#strictly enforce standard and generate errors if violated
CXXFLAGS += -g         			#debugging information
#CXXFLAGS += -03			#OPTIMIZATION MODE, LEAVE OFF	
LDFLAGS = -lboost_date_time


EXECUTABLE_NAME = lab9

OBJS = main.o Queue.o Stack.o	validInt.o

SRCS = main.cpp Queue.cpp Stack.cpp validInt.cpp

HEADERS = Queue.hpp Stack.hpp validInt.hpp




$(EXECUTABLE_NAME): ${OBJS} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o $(EXECUTABLE_NAME)


#takes any cpp file and build a .o file , @: is wildcard for every file name
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

#Clean
clean: 
	rm $(OBJS) $(EXECUTABLE_NAME)



#would have to input every dependecy like this of not using code above
#main.o: main.cpp
#	$(CXX) -c main.cpp

#determinate.o: determinate.cpp determinate.hpp
#	$(CXX) -c determinate.cpp



