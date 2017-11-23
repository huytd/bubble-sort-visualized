# Visualized Bubble Sort

A program to visualize bubble sort algorithm and create animated GIF. This is the result:

![](bubble.gif)

**Required ImageMagick to be installed.**

For image optimization, I'm using [gifsicle](https://www.lcdf.org/gifsicle/), but you can just remove it from `Makefile` if you don't need small size GIF.

To run the algorithm and generate GIF:

```
make run
```

For grayscaled version (using PGM format), please check commit `8ffae00`. The current version using Plain PPM format.
