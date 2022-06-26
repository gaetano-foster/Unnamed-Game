SOURCES := $(shell find . -type f -iname "*.cc")
CCFLAGS := -Wall -Wno-deprecated -Wno-int-in-bool-context -flto -O3 -DUNICODE -std=c++17 `sdl2-config --cflags`
DEBUG_FLAGS := -g -Wall -Wno-deprecated -Wno-int-in-bool-context -flto -O0 -DUNICODE -std=c++17 `sdl2-config --cflags`
LIBS    := -L. -lm -lstdc++fs `sdl2-config --libs` -I./src/

all:
	clang++ -o ./a.out $(SOURCES) $(CCFLAGS) $(LIBS)

debug:
	clang++ -o ./a.out $(SOURCES) $(DEBUG_FLAGS) $(LIBS)
