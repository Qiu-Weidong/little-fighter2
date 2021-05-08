CC      := g++
BUILD   := build
LF      := $(BUILD)/lf.exe
SRC     := $(wildcard src/*.cpp)
SFMLLIB := SFML/lib
SFMLINC := SFML/include
SFMLBIN := SFML\bin
        
all: $(LF)

$(LF) : $(BUILD) $(SRC)
	$(CC) -o $@ $(SRC) -I $(SFMLINC) -L $(SFMLLIB) -lsfml-graphics -lsfml-window -lsfml-system 

$(BUILD):
	mkdir $(BUILD)
	copy $(SFMLBIN)\*.dll $(BUILD)


run: $(LF)
	./$(LF)

clean:
	rd /s/q $(BUILD)
