#Sources got from https://msdn.microsoft.com/en-us/library/windows/desktop/ms738545%28v=vs.85%29.aspx

COMPILER=i686-w64-mingw32-g++


all: compile run

compile:
#	$(COMPILER) main.cpp -E -o main.i
	$(COMPILER) main.cpp -o opengl.exe -lopengl32 -lglu32 -lgdi32

run:
	@echo -----------------------------------------
	@echo Usage:
	@echo 
	@echo wine opengl.exe

clean:
	rm *.exe *~
