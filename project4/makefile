####################################################################
#Program Name:Makefile
#Author: Robert Elsom  
#Date: 2/21/2019
#Description: Makefile for project 4
####################################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall			#turns on all warnings
CXXFLAGS += -pedantic-errors		#strictly enforce standard and generate errors if violated
CXXFLAGS += -g         			#debugging information
#CXXFLAGS += -03			#OPTIMIZATION MODE, LEAVE OFF	
LDFLAGS = -lboost_date_time


EXECUTABLE_NAME = project4

OBJS = validStr.o Harry_Potter.o Barbarian.o Blue_Men.o Medusa.o Vampire.o Character.o Game.o Queue.o main.o validInt.o 

SRCS = validStr.cpp Harry_Potter.cpp Barbarian.cpp Blue_Men.cpp Medusa.cpp Vampire.cpp Character.cpp Game.cpp Queue.cpp main.cpp validInt.cpp 

HEADERS = validStr.hpp Harry_Potter.hpp Barbarian.hpp Blue_Men.hpp Medusa.hpp Vampire.hpp Character.hpp Game.hpp Queue.hpp validInt.hpp 




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



