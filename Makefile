.DEFAULT_GOAL = optimize

clean:
	rm -f bubble bubble.gif

build: clean
	gcc bubble.c -o bubble

run: build
	./bubble | convert -delay 1x30 ppm:- gif:- > bubble.gif

optimize: run
	convert -fuzz 10% -layers Optimize bubble.gif bubble.gif
