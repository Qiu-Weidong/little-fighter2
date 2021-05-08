CC      := g++
BUILD   := build
LF      := $(BUILD)/lf.exe
SRC     := $(wildcard src/*.cpp)
INC     := $(wildcard src/*.h)
SFMLLIB := SFML/lib
SFMLINC := SFML/include
SFMLBIN := SFML\bin
DEBUG   := -g 
        
all: $(LF)

$(LF) : $(BUILD) $(SRC) $(INC)
	$(CC) -o $@ $(DEBUG) $(SRC) -I $(SFMLINC) -L $(SFMLLIB) -lsfml-graphics -lsfml-window -lsfml-system 

$(BUILD):
	mkdir $(BUILD)
	copy $(SFMLBIN)\*.dll $(BUILD)


run: $(LF)
	./$(LF)

clean:
	rd /s/q $(BUILD)
