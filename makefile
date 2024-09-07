CC = g++
CFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
CVER = -std=c++17
INC = -Iinclude/SDL2
LIB =  -Llib
SDL2 = $(INC) $(LIB)
SRC = PGUI_TestSource/
PGUI = PeakyGUI/src/
MAINSRC = $(SRC)init_window.cpp $(SRC)_main.cpp $(SRC)event.cpp
PGUISRC = $(PGUI)pgui_button.cpp $(PGUI)pgui_call.cpp $(PGUI)pgui_component.cpp $(PGUI)pgui_draw.cpp $(PGUI)pgui_item.cpp $(PGUI)pgui_event.cpp $(PGUI)pgui_primitives.cpp
EXEC_NAME = bin/win

pgui:
	$(CC) $(CVER) $(MAINSRC) $(PGUISRC) $(SDL2) $(CFLAGS) -o $(EXEC_NAME)
