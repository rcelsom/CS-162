####################################################################
#Program Name:Makefile
#Author: Robert Elsom
#Date: 1/22/2019
#Description: Makefile for project2
####################################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall			#turns on all warnings
CXXFLAGS += -pedantic-errors		#strictly enforce standard and generate errors if violated
CXXFLAGS += -g         			#debugging information
#CXXFLAGS += -03			#OPTIMIZATION MODE, LEAVE OFF	
LDFLAGS = -lboost_date_time


EXECUTABLE_NAME = project2

OBJS =Zoo.o Penguin.o Tiger.o Turtle.o Animal.o  validInt.o validStr.o main.o

SRCS = Zoo.cpp Penguin.cpp Tiger.cpp Turtle.cpp Animal.cpp validInt.cpp validStr.cpp main.cpp

HEADERS = Zoo.hpp Penguin.hpp Tiger.hpp Turtle.hpp Animal.hpp validInt.hpp validStr.hpp 




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



