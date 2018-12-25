test:
	make build;
	make run;
	make clean;

build:
	g++ *.c -std=c++11 -o xrandr-ncurses-app -lncurses;

run:
	./xrandr-ncurses-app;

clean:
	-rm xrandr-ncurses-app;
