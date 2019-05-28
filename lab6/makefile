####################################################################
#Program Name:Makefile
#Author: Robert Elsom
#Date: 1/10/2019
#Description: Makefile for project1
####################################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall			#turns on all warnings
CXXFLAGS += -pedantic-errors		#strictly enforce standard and generate errors if violated
CXXFLAGS += -g         			#debugging information
#CXXFLAGS += -03			#OPTIMIZATION MODE, LEAVE OFF	
LDFLAGS = -lboost_date_time


EXECUTABLE_NAME = lab6

OBJS = main.o linkedList.o Node.o Menu.o validInt.o

SRCS = main.cpp linkedList.cpp Node.cpp Menu.cpp validInt.cpp

HEADERS = linkedList.hpp Node.hpp Menu.hpp validInt.hpp 




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



