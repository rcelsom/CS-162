####################################################################
#Program Name:Makefile
#Author: Robert Elsom
#Date: 1/27/2019
#Description: Makefile for lab 4
####################################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall			#turns on all warnings
CXXFLAGS += -pedantic-errors		#strictly enforce standard and generate errors if violated
CXXFLAGS += -g         			#debugging information
#CXXFLAGS += -03			#OPTIMIZATION MODE, LEAVE OFF	
LDFLAGS = -lboost_date_time


EXECUTABLE_NAME = lab4

OBJS =Person.o Instructor.o Student.o Building.o University.o validInt.o validStr.o validDbl.o main.o

SRCS = Person.cpp Instructor.cpp Student.cpp Building.cpp University.cpp validInt.cpp validStr.cpp validDbl.cpp main.cpp

HEADERS = Person.hpp Instructor.hpp Student.hpp Building.hpp University.hpp validInt.hpp validStr.hpp validDbl.hpp




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



