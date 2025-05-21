
CXX=g++
CXXFLAGS=-std=c++11 -pthread
INCLUDE=-Iinclude

SRC=src/main.cpp src/Client.cpp src/Server.cpp src/User.cpp src/Factory.cpp
OBJ=$(SRC:.cpp=.o)

all:
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(SRC) -o chatapp
