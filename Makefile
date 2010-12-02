CC = g++ -g
SDL_CONFIG = sdl-config
exec = game
OPENGL = -lGL -lGLU
SRC_DIR := src
INCL_DIR := include
OBJ_DIR := objs

# MinGW
ifdef WINDOWS
exec := $(exec).exe
CC = i586-mingw32msvc-g++
SDL_CONFIG = /usr/i586-mingw32msvc/bin/sdl-config
OPENGL = -lopengl32 -lglu32
endif

CFLAGS = `$(SDL_CONFIG) --cflags`
LDFLAGS = `$(SDL_CONFIG) --libs` -lSDL_image $(OPENGL) -lm -lSDL_mixer 
headers = $(wildcard $(INCL_DIR)/*.h)
sources = $(wildcard $(SRC_DIR)/*.cpp)
objects = $(sources:.cpp=.o)

all: $(exec)

$(exec): $(objects)
	$(CC) -o $(exec) $(objects) $(CFLAGS) $(LDFLAGS)

%.o: %.cpp $(headers)
	$(CC) $(CFLAGS) -c $< -o $@
	
.PHONY: clean
clean:
	rm -f *~ $(objects) $(exec)
