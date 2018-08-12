#include <iostream>

using namespace std;
struct box {
  char maker[40];
  float height;
  float width;
  float length;
  float volume;
};

void print_box(const box);

void set_volume(box *);

int main() {
  box *b = new box;
  cout << "Enter the box maker: ";
  cin >> b->maker;
  cout << "Enter the box height: ";
  cin >> b->height;
  cout << "Enter the box width: ";
  cin >> b->width;
  cout << "Enter the box length: ";
  cin >> b->length;

  set_volume(b);

  print_box(*b);

  delete b;
  return 0;
}

void print_box(const box b) {
  cout << "The box maker is " << b.maker << ", height: " << b.height
       << ", width: " << b.width << ", length: " << b.length
       << ", volume: " << b.volume << endl;
}

void set_volume(box *b) { b->volume = b->height * b->width * b->length; }
