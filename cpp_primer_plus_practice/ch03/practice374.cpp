#include <iostream>

int main(void) {
  const int SIXTY = 60;
  const int TWENTY_FOUR = 24;
  long long seconds;
  std::cout << "Enter the number of seconds: ";
  std::cin >> seconds;
  int day, hour, minute, second;
  long long tmp = seconds;
  second = tmp % SIXTY;
  tmp /= SIXTY;

  minute = tmp % SIXTY;
  tmp /= SIXTY;

  hour = tmp % SIXTY;
  day = tmp / TWENTY_FOUR;

  std::cout << seconds << " seconds = ";
  std::cout << day << " days, ";
  std::cout << hour << " hours, ";
  std::cout << minute << " minutes, ";
  std::cout << second << " seconds.\n";
  return 0;
}
