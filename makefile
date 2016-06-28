OUT = ishab
CXX = g++
SDL = -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_ttf

OBJECTS = ${sources:.cpp=.o}
SOURCES = main.cpp StateManager.cpp Graphics.cpp Entity.cpp Area.cpp Sprite.cpp GameEngine.cpp Player.cpp


all: $(OUT)
$(OUT): $(OBJECTS)
	$(CXX) -o ${OUT} ${SOURCES} ${SDL}


clean: 
	rm -rf *.o ${OUT}
