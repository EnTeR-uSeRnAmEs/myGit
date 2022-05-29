/*
 * unordered_map.c
 *
 *  Created on: May 20, 2021
 *      Author: adrian-estelio
 */

//原来unsigned int为size_t，但在IntelliSense设置为64位时报错，故做更改

#include "unordered_map.h"
#include <stdio.h>
#include <stdlib.h>

unordered_map_t *new_unordered_map(unsigned int size) {
  unordered_map_t *new_hash_table =
      (unordered_map_t *)malloc(sizeof(unordered_map_t));
  new_hash_table->size_ = size;
  new_hash_table->hash_table_ = (item_t **)calloc(size, sizeof(item_t));
  return new_hash_table;
}

void delete_map(unordered_map_t *unordered_map) {

  for (unsigned int i = 0; i < unordered_map->size_; i++) {
    item_t *current = unordered_map->hash_table_[i];
    while (current != NULL) {
      item_t *next = (item_t *)current->next_;
      free(current);
      current = next;
    }
  }
  free(unordered_map->hash_table_);
  free(unordered_map);
}
int unordered_map_insert(unordered_map_t *unordered_map, int key, int value) {

  item_t *item = (item_t *)malloc(sizeof(item_t));
  item->value_ = value;
  item->key_ = key;
  item->next_ = NULL;

  int hash_number = key % unordered_map->size_;

  item_t *current = unordered_map->hash_table_[hash_number];
  if (current == NULL) {
    unordered_map->hash_table_[hash_number] = item;
  } else {
    while (current->next_ != NULL) {
      current = (item_t *)current->next_;
    }
    current->next_ = (struct item_t *)item;
  }
  return 0;
}

int *unordered_map_find(unordered_map_t *unordered_map, int key) {

  int hash_number = key % unordered_map->size_;

  item_t *current = unordered_map->hash_table_[hash_number];

  if (current == NULL) {
    return NULL;
  }

  while (current->next_ != NULL && current->key_ != key) {
    current = (item_t *)current->next_;
  }

  int *i = &current->value_;
  return i;
}
