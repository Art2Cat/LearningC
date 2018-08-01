#include <cctype>
#include <iostream>
#include <string>

int main(void) {
  using namespace std;

  cout << "Enter words (q to quit): ";

  string word;
  char first_ch;
  int other = 0, vowel = 0, consonant = 0;

  cin >> word;
  while (word != "q") {
    first_ch = word[0];
    if (isalpha(first_ch)) {
      switch (tolower(first_ch)) {
      case 'a':
        vowel++;
        break;
      case 'e':
        vowel++;
        break;
      case 'i':
        vowel++;
        break;
      case 'o':
        vowel++;
        break;
      case 'u':
        vowel++;
        break;
      default:
        consonant++;
      }
    } else
      other++;
    cin >> word;
  }

  cout << vowel << " words beginning with vowels" << endl;
  cout << consonant << " words beginning with consonants" << endl;
  cout << other << " others" << endl;

  return 0;
}
