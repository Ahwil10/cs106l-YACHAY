# Makefile for Retail Data Analytics CLI App

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Iinclude
SRC := src/main.cpp
TARGET := retail_app.exe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

run:
	./$(TARGET) --file=data.csv

clean:
	del /f /q $(TARGET) 2>nul || rm -f $(TARGET)
