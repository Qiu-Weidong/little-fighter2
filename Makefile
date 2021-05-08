CC      := g++
BUILD   := build
LF      := $(BUILD)/lf.exe
SRC     := $(wildcard src/*.cpp)
OBJS    := $(addprefix $(BUILD)/,$(notdir $(SRC:.cpp=.o)) )
SFMLLIB := SFML/lib
SFMLINC := SFML/include
        
all: $(LF)

$(LF): $(BUILD) $(OBJS)
	$(CC) -o $@ $(OBJS) -L $(SFMLLIB) -lsfml-graphics -lsfml-window -lsfml-system 

$(BUILD):
	mkdir $(BUILD)
	copy SFML\bin\*.dll $(BUILD)

$(BUILD)/%.o:src/%.cpp
	$(CC) -o $@ -c $< -I $(SFMLINC)


run: $(LF)
	./$(LF)

clean:
	rd /s/q $(BUILD)
