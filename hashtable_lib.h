#ifndef HASHTABLE_LIB_H
#define HASHTABLE_LIB_H

#include "defaults.h"
#include <stdbool.h>

unsigned int hash(char *name);
void init_hash_table(HASH_STRUCT *hash_table[]);
void print_hash_table(HASH_STRUCT *hash_table[]);
bool hash_table_insert(HASH_STRUCT *s, HASH_STRUCT *hash_table[]);
HASH_STRUCT *hash_table_lookup(HASH_STRUCT_ELEMENT_TYPE *key, HASH_STRUCT *hash_table[]);
HASH_STRUCT *hash_table_delete(HASH_STRUCT_ELEMENT_TYPE *key, HASH_STRUCT *hash_table[]);

#endif // HASHTABLE_LIB_H