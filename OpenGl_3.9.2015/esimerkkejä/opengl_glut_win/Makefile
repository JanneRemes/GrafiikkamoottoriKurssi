#Sources got from https://msdn.microsoft.com/en-us/library/windows/desktop/ms738545%28v=vs.85%29.aspx
FREEGLUT_ROOT=../freeglut_win
COMPILER=i686-w64-mingw32-g++ -I$(FREEGLUT_ROOT)/include -L$(FREEGLUT_ROOT)/lib


all: compile run

compile:
#	$(COMPILER) main.cpp -E -o main.i
	$(COMPILER) main.cpp -o opengl.exe -lopengl32 -lglu32 -lgdi32 -lfreeglut
	cp $(FREEGLUT_ROOT)/bin/*.dll .

run:
	@echo -----------------------------------------
	@echo Usage:
	@echo 
	@echo wine opengl.exe

clean:
	rm *.exe *~
