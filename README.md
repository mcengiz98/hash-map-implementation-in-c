# (Mostly) Generic Hash Table Implementation in C

This is a (mostly) generic hash table implementation in C. It is based on the [Jacob Sorber's](https://www.youtube.com/@JacobSorber) [video](https://www.youtube.com/watch?v=2Ti5yvumFTU).

## Types 

- hashtable: if a key used multiple times, it will not be overwritten. Placed in the next available slot.
- hashtable_external: if a key used multiple times, it will be overwritten. Placed in the same slot.

## Hashed Struct
This repo uses person struct as an example. You can change it to whatever you want. Just change the 'defaults.h' file.

~~~c
typedef struct
{
    char name[MAX_NAME];
    int age;
} person;
~~~

## Usage

### hashtable

If you want to use the hashtable, you can use the following functions:

~~~c
#include <stdio.h>
#include "hashtable_lib.h"
#include "defaults.h"


int main(void){
    person *hash_table[TABLE_SIZE];
    init_hash_table(hash_table);

    person lisa = {.name = "Lisa", .age = 26};
    hash_table_insert(&lisa, hash_table);
    person jennie = {.name = "Jennie", .age = 27};
    hash_table_insert(&jennie, hash_table);
    person rose = {.name = "Rose", .age = 26};
    hash_table_insert(&rose, hash_table);
    person jisoo = {.name = "Jisoo", .age = 28};
    hash_table_insert(&jisoo, hash_table);
    person sakura = {.name = "Sakura", .age = 25};
    hash_table_insert(&sakura, hash_table);
    person chaewon = {.name = "Chaewon", .age = 23};
    hash_table_insert(&chaewon, hash_table);
    person yunjin = {.name = "Yunjin", .age = 22};
    hash_table_insert(&yunjin, hash_table);;
    person kazuha = {.name = "Kazuha", .age = 23};
    hash_table_insert(&kazuha, hash_table);
    person eunChae = {.name = "EunChae", .age = 16};
    hash_table_insert(&eunChae, hash_table);
    person mustafa = {.name = "Mustafa", .age = 25};
    hash_table_insert(&mustafa, hash_table);
    
    hash_table_delete("Mustafa", hash_table);

    print_hash_table(hash_table);
}
~~~

The output will be:

~~~c
0       Chaewon     
1       Rose        
2       Jisoo       
3       Sakura      
4       Yunjin      
5       Kazuha      
6       Jennie      
7       EunChae     
8       ---<deleted>
9       Lisa
~~~

### hashtable_external

If you want to use the hashtable_external, you can use the following functions:

~~~c
#include <stdio.h>
#include "hashtable_external_lib.h"
#include "defaults_external.h"

int main(void){
    person *hash_table[TABLE_SIZE];
    init_hash_table(hash_table);

    person lisa = {.name = "Lisa", .age = 26};
    hash_table_insert(&lisa, hash_table);
    person jennie = {.name = "Jennie", .age = 27};
    hash_table_insert(&jennie, hash_table);
    person rose = {.name = "Rose", .age = 26};
    hash_table_insert(&rose, hash_table);
    person jisoo = {.name = "Jisoo", .age = 28};
    hash_table_insert(&jisoo, hash_table);
    person sakura = {.name = "Sakura", .age = 25};
    hash_table_insert(&sakura, hash_table);
    person chaewon = {.name = "Chaewon", .age = 23};
    hash_table_insert(&chaewon, hash_table);
    person yunjin = {.name = "Yunjin", .age = 22};
    hash_table_insert(&yunjin, hash_table);;
    person kazuha = {.name = "Kazuha", .age = 23};
    hash_table_insert(&kazuha, hash_table);
    person eunChae = {.name = "EunChae", .age = 16};
    hash_table_insert(&eunChae, hash_table);
    person mustafa = {.name = "Mustafa", .age = 25};
    hash_table_insert(&mustafa, hash_table);
    
    hash_table_delete("Mustafa", hash_table);

    print_hash_table(hash_table);
}
~~~

The output will be:

~~~c
0       Yunjin - Chaewon -
1       Sakura - Rose -
2       Jisoo -
3       ---
4       EunChae -
5       Kazuha -
6       Jennie -
7       ---
8       ---
9       Lisa -
~~~