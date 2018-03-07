#include "MyList.h"
#include <stdio.h>
#include <stdlib.h>

static void copyToItem(Node node, Item *item);

static void copyToNode(Item item, Node *node);

static int compare(const Item item, const Item item1);

static int find(const List *list, const Item item1);

void initList(List *list) { *list = NULL; }

bool isEmpty(const List *list) {
  if (*list == NULL) {
    return false;
  } else {
    return true;
  }
}

bool addItem(List *list, Item item) {
  Node *new;
  Node *scan = *list;

  new = (Node *)malloc(sizeof(Node));
  if (new == NULL) {
    return false;
  }

  copyToNode(item, new);

  new->next = NULL;

  if (scan == NULL) {
    *list = new;
  } else {
    while (scan->next != NULL) {
      scan = scan->next;
    }
    scan->next = new;
  }

  return true;
}

bool removeItem(List *list, Item item) {
  Node *nodes = *list;
  int idx = indexItem(list, item);
  if (idx >= 0) {
    //        org = &nodes[idx];
    if (idx == 0) {
      //            free(org);
    } else if (idx == len(list) - 1) {
      Node *node1 = &nodes[idx - 1];
      node1->next = NULL;
    } else {
      Node *before = &nodes[idx - 1];
      Node *after = &nodes[idx + 1];
      before->next = after;
    }
  } else {
    return false;
  }

  return true;
}

Item popItem(List *list, Item item) { return item; }

bool containItem(const List *list, const Item item) { return true; }

unsigned int len(const List *list) {
  if (list == NULL) {
    return 0;
  }

  unsigned int count = 0;
  Node *node = *list;

  while (node != NULL) {
    ++count;
    node = node->next;
  }
  return count;
}

int indexItem(const List *list, const Item item) { return find(list, item); }

void removeAll(List *list) {}

static int find(const List *list, const Item item) {
  if (list == NULL) {
    return -1;
  }
  unsigned int low = 0;
  unsigned int high = len(list) - 1;
  const Node *nodes = *list;

  while (low <= high) {
    unsigned int mid = (low + high) / 2;
    const Node guess = nodes[mid];
    if (guess.item.iValue == item.iValue) {
      return mid;
    } else if (guess.item.iValue > item.iValue) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
}

static void copyToNode(Item item, Node *node) { node->item = item; }

int compare(const Item item, const Item item1) {
  int result;
  if (item.iValue > item1.iValue) {
    result = 1;
  } else if (item.iValue == item1.iValue) {
    result = 0;
  } else {
    result = -1;
  }
}