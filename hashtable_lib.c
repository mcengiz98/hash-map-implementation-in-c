#include <stdio.h>
#include "hashtable_lib.h"
#include "defaults.h"
#include <stdbool.h>
#include <string.h>

/**
 * @brief Hash function for hash table. If your HASH_STRUCT_ELEMENT_TYPE is not string or char, you should change the hash function.
 *
 * @param key : key to be hashed
 * @return unsigned int : hashed value
 */
unsigned int hash(HASH_STRUCT_ELEMENT_TYPE *key)
{
    size_t len = strlen(key);
    unsigned int hash_value = 0;
    for (size_t i = 0; i < len; ++i)
    {
        hash_value += key[i];
        hash_value *= key[i];
        hash_value %= TABLE_SIZE;
    }

    return hash_value;
}

/**
 * @brief Initialization function for hash table. This function initializes the hash table with NULL values.
 *
 * @param hash_table : HASH_STRUCT pointer array
 */
void init_hash_table(HASH_STRUCT *hash_table[])
{
    for (size_t i = 0; i < TABLE_SIZE; ++i)
    {
        hash_table[i] = NULL;
    }
}

/**
 * @brief Print function for hash table.
 *
 * @param hash_table : HASH_STRUCT pointer array
 */
void print_hash_table(HASH_STRUCT *hash_table[])
{
    for (size_t i = 0; i < TABLE_SIZE; ++i)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%lli\t---\n", i);
        }
        else if (hash_table[i] == DELETED_NODE)
        {
            printf("\t%lli\t---<deleted>\n", i);
        }
        else
        {
            printf("\t%lli\t%s\n", i, hash_table[i]->name);
        }
    }
}

/**
 * @brief Insertion function for hash table.
 *
 * @param s : HASH_STRUCT pointer to be inserted
 * @param hash_table : HASH_STRUCT pointer array
 * @return true : if insertion is successful
 * @return false : if insertion is not successful
 */
bool hash_table_insert(HASH_STRUCT *s, HASH_STRUCT *hash_table[])
{
    if (s == NULL)
        return false;
    int index = hash(s->HASH_STRUCT_ELEMENT);
    for (size_t i = 0; i < TABLE_SIZE; ++i)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = s;
            return true;
        }
    }

    return false;
}

/**
 * @brief Lookup function for hash table. This function searches for the key in the hash table. If your HASH_STRUCT_ELEMENT_TYPE is not string or char, you should change the strncmp function.
 *
 * @param key : key to be searched.
 * @param hash_table : HASH_STRUCT pointer array
 * @return HASH_STRUCT* : if key is found, returns the pointer to the HASH_STRUCT. If not, returns NULL.
 */
HASH_STRUCT *hash_table_lookup(HASH_STRUCT_ELEMENT_TYPE *key, HASH_STRUCT *hash_table[])
{
    int index = hash(key);
    for (size_t i = 0; i < TABLE_SIZE; ++i)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            return false;
        }
        if (hash_table[try] == DELETED_NODE)
        {
            continue;
        }
        if (strncmp(hash_table[try]->HASH_STRUCT_ELEMENT, key, TABLE_SIZE) == 0)
        {
            return hash_table[try];
        }
    }
    return NULL;
}

/**
 * @brief Delete function for hash table. If your HASH_STRUCT_ELEMENT_TYPE is not string or char, you should change the strncmp function.
 *
 * @param key : key to be deleted
 * @param hash_table : HASH_STRUCT pointer array
 * @return HASH_STRUCT* : if key is found, returns the pointer to the HASH_STRUCT. If not, returns NULL.
 */
HASH_STRUCT *hash_table_delete(HASH_STRUCT_ELEMENT_TYPE *key, HASH_STRUCT *hash_table[])
{
    int index = hash(key);
    for (size_t i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            return NULL;
        }
        if (hash_table[try] == DELETED_NODE)
        {
            continue;
        }
        if (strncmp(hash_table[try]->HASH_STRUCT_ELEMENT, key, TABLE_SIZE) == 0)
        {
            HASH_STRUCT *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}
