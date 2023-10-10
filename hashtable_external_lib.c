#include <stdio.h>
#include "hashtable_external_lib.h"
#include "defaults_external.h"
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
        else
        {
            printf("\t%lli\t", i);
            HASH_STRUCT *tmp = hash_table[i];
            while (tmp != NULL)
            {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
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
    s->next = hash_table[index];
    hash_table[index] = s;
    return true;
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
    HASH_STRUCT *tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->HASH_STRUCT_ELEMENT, key, TABLE_SIZE) != 0)
    {
        tmp = tmp->next;
    }
    return tmp;
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
    HASH_STRUCT *tmp = hash_table[index];
    HASH_STRUCT *prev = NULL;
    while (tmp != NULL && strncmp(tmp->HASH_STRUCT_ELEMENT, key, TABLE_SIZE) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return NULL;
    if (prev == NULL)
        hash_table[index] = tmp->next;
    else
        prev->next = tmp->next;
    return tmp;
}
