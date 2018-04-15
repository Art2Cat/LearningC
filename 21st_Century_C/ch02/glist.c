#include <glib.h>
#include <stdio.h>

GList *list;

int main(void) {
  list = g_list_append(list, "a");
  list = g_list_append(list, "a");
  list = g_list_append(list, "a");
  for (; list != NULL; list = list->next) {
    printf("%s\n", (char *)list->data);
  }
  return 0;
}
