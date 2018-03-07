#include <ctype.h>    // for isspace()
#include <stdbool.h>  // for bool, true, false
#include <stdio.h>

int main(void) {
  char c;               // read in character
  int low_ct = 0;       // number of lowercase characters
  int up_ct = 0;        // number of uppercase characters
  int dig_ct = 0;       // number of digits
  int n_words = 0;      // number of words
  int punc_ct = 0;      // number of punctuation marks
  bool inword = false;  // == true if c is in a word
  printf("Enter text to be analyzed (EOF to terminate):\n");
  while ((c = getchar()) != EOF) {
    if (islower(c)) {
      low_ct++;
    } else if (isupper(c)) {
      up_ct++;
    } else if (isdigit(c)) {
      dig_ct++;
    } else if (ispunct(c)) {
      punc_ct++;
    }
    if (!isspace(c) && !inword) {
      inword = true;  // starting a new word
      n_words++;      // count word
    }
    if (isspace(c) && inword) {
      inword = false;  // reached end of word
    }
  }
  printf(
      "\nwords = %d, lowercase = %d, uppercase = %d, "
      "digits = %d, punctuation = %d\n",
      n_words, low_ct, up_ct, dig_ct, punc_ct);
  return 0;
}