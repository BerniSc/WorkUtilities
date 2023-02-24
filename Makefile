COMPILER = g++
OUTPUT_FILE = output
SRC = FileHelper.cpp
OPTIONS = -O3 -std=c++17 -Wall

LIBS =

$(OUTPUT_FILE) : $(SRC)
		$(COMPILER) $(SRC) $(OPTIONS) -o $(OUTPUT_FILE) $(LIBS)