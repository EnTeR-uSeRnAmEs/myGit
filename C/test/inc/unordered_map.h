/*
 * unorderd_map.h
 *
 *  Created on: May 20, 2021
 *      Author: adrian-estelio
 */

#ifndef UNORDERED_MAP_H_
#define UNORDERED_MAP_H_

#include <stdlib.h>

typedef struct item_t {
  int value_;
  int key_;
  struct item_t *next_;
} item_t;

typedef struct unordered_map_t {
  item_t **hash_table_;
  unsigned int size_;
} unordered_map_t;

int unordered_map_insert(unordered_map_t *unordered_map, int key, int value);
unordered_map_t *new_unordered_map(unsigned int size);
void delete_map(unordered_map_t *unordered_map);
int *unordered_map_find(unordered_map_t *unordered_map, int key);
#endif /* UNORDERED_MAP_H_ */
