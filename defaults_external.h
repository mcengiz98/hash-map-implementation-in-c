#ifndef DEFAULTS_H
#define DEFAULTS_H

#ifndef MAX_NAME
#define MAX_NAME 256
#endif // MAX_NAME

#ifndef TABLE_SIZE
#define TABLE_SIZE 10
#endif // TABLE_SIZE

#if defined(HASH_STRUCT) && defined(HASH_STRUCT_ELEMENT) && defined(HASH_STRUCT_ELEMENT_TYPE)
#else
typedef struct person
{
    char name[MAX_NAME];
    int age;
    struct person *next;
} person;
#define HASH_STRUCT person
#define HASH_STRUCT_ELEMENT name
#define HASH_STRUCT_ELEMENT_TYPE char
#endif // HASH_STRUCT

#endif // DEFAULTS_H