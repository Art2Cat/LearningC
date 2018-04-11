#ifndef __KEYVAL_H
#define __KEYVAL_H

typedef struct keyval {
  char *key;
  void *value;
} keyval;

keyval *keyval_new(char *key, void *value);
keyval *keyval_copy(keyval const *in);
void keyval_free(keyval *in);
int keyval_mathes(keyval const *in, char const *key);

#endif
