all:
	gcc turtleExample.c -L./Linux -lglfw3 -ldl -lm -lX11 -lglad -lGL -lGLU -lpthread -DOS_LINUX -o turtleExample.o
win:
	gcc turtleExample.c -L./Windows -lglfw3 -lopengl32 -lgdi32 -lglad -lole32 -luuid -DOS_WINDOWS -o turtleExample.exe
val:
	gcc turtleExample.c -L./Linux -lglfw3 -ldl -lm -lX11 -lglad -lGL -lGLU -lpthread -g -DOS_LINUX -o turtleExample.o
clean:
	rm turtleExample.o