.DEFAULT_GOAL = run

clean:
	rm -f bubble bubble.gif

build: clean
	gcc bubble.c -o bubble

run: build
	./bubble | convert -delay 1x30 ppm:- gif:- | gifsicle -O3 > bubble.gif
