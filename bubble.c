#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DATA_LENGTH  20
#define IMAGE_WIDTH  500
#define IMAGE_HEIGHT 50
#define ENDING_DELAY 50

int* gen_data(int length) {
  int* data = (int*)malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++) {
    data[i] = rand() % 255;
  }
  return data;
}

void draw_frame(int* data, int length, int width, int height, int highlight) {
  int block_width = width / length;
  printf("P3\n%d %d\n255\n", width, height);
  for (int h = 0; h < height; h++) {
    for (int i = 0; i < length; i++) {
      int r = data[i], g = data[i], b = data[i];
      if (highlight == i) {
        if (h <= block_width || h >= height - block_width) {
          r = 255; g = b = 0;
        }
      }
      for (int c = 0; c < block_width; c++) {
        printf("%d %d %d \t", r, g, b);
      }
    }
    printf("\n");
  }
}

void swap(int* data, int from, int to) {
  int temp = data[from];
  data[from] = data[to];
  data[to] = temp;
}

void bubble_sort(int* data, int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - i; j++) {
      if (data[j] > data[j+1]) {
        swap(data, j, j+1);
        draw_frame(data, length, IMAGE_WIDTH, IMAGE_HEIGHT, j+1);
      }
    }
  }
}

int main() {
  time_t t;
  srand((unsigned) time(&t));

  int* inputs = gen_data(DATA_LENGTH);
  bubble_sort(inputs, DATA_LENGTH);

  for (int i = 0; i < ENDING_DELAY; i++) {
    draw_frame(inputs, DATA_LENGTH, IMAGE_WIDTH, IMAGE_HEIGHT, -1);
  }

  return 0;
}
