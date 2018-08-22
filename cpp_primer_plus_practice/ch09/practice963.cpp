#include <cstring>
#include <iostream>

const int LEN = 2;
struct chaff {
  char dross[20];
  int slag;
};

static void show(const chaff *arr);

chaff buffer[LEN];

int main() {
  chaff *arr = new chaff[LEN];
  strcpy(arr[0].dross, "test");
  arr[0].slag = 22;
  strcpy(arr[1].dross, "test 12");
  arr[1].slag = 12;
  chaff *buffer1 = new (buffer) chaff[LEN];

  strcpy(buffer1[0].dross, arr[0].dross);
  buffer1[0].slag = arr[0].slag;
  strcpy(buffer1[1].dross, arr[1].dross);
  buffer1[1].slag = arr[1].slag;
  show(buffer1);
  delete[] arr;
  return 0;
}

static void show(const chaff *arr) {
  for (int i = 0; i < LEN; i++) {
    std::cout << "chaff[" << i << "]" << std::endl;
    std::cout << "dross: " << arr[i].dross << std::endl;
    std::cout << "slag: " << arr[i].slag << std::endl;
  }
}
