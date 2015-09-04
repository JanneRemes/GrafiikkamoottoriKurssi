COMPILER=g++

FREEGLUT_ROOT=../freeglut_win
SDL_ROOT=../SDL-1.2.15_win
WINLIB= -lmingw32 -lSDLmain -lSDL -lopengl32 #These has to be in this order! 
WINCOMPILER=i686-w64-mingw32-g++


all: compile run

compile:
	$(COMPILER) main.cpp -o opengl `sdl-config --libs --cflags` -lGL -lGLU
	$(WINCOMPILER) main.cpp -o opengl.exe -L$(SDL_ROOT)/lib/ -I$(SDL_ROOT)/include $(WINLIB)
	cp $(FREEGLUT_ROOT)/bin/*.dll .
	cp $(SDL_ROOT)/bin/*.dll .
run:
	@echo -----------------------------------------
	@echo Usage:
	@echo 
	@echo ./opengl

clean:
	rm  *~
