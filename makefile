CXX = g++
CC = gcc
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -Werror

rpg: Artifact.cpp Artifact.hpp Book.cpp Book.hpp Character.cpp Character.hpp DiningHall.cpp DiningHall.hpp Entry.cpp Entry.cpp Honey.cpp Honey.cpp Ingredient.cpp Ingredient.hpp Item.cpp Item.hpp Kitchen.cpp Kitchen.hpp Lab.cpp Lab.hpp Library.cpp Library.hpp PC.cpp PC.hpp Room.cpp Room.hpp main.cpp
	${CXX} ${CXXFLAGS} main.cpp Artifact.cpp Book.cpp Character.cpp DiningHall.cpp Entry.cpp Honey.cpp Ingredient.cpp Item.cpp Kitchen.cpp Lab.cpp Library.cpp PC.cpp Room.cpp
