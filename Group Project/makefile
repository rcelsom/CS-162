

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
LDFLAGS = .lboost_date_time

OBJS = main.o Ant.o Doodlebug.o Critter.o Game.o Menu.o

SRCS = main.cpp Ant.cpp Doodlebug.cpp Critter.cpp Game.cpp Menu.cpp

HEADERS = Ant.hpp Doodlebug.hpp Critter.hpp Game.hpp Menu.hpp

playgame: ${OBJS} ${SRCS}
	${CXX} ${CXXFLAGS} ${SRCS} -o playgame
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
		
clean:
	-rm ${OBJS} playgame
			
