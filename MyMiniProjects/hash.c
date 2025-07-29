#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct Pair{
    char *key;
    int value;
    struct Pair *next;
} Pair;

unsigned int hash(const char *str){
    unsigned int hash = 0;
    while(*str)  hash = hash * 31 + *str++;
    printf("hash >>>> %u ", hash);
    return hash;
} 

struct Pair* hash_table[TABLE_SIZE] = {NULL};

void insert(const char* key, int value){
    unsigned int index = hash(key) % TABLE_SIZE;

    printf("%s >>>> index = %d\n", key, index);

    struct Pair *new_pair = malloc(sizeof(struct Pair));
    new_pair->key = strdup(key);
    new_pair->value = value;

    new_pair->next = hash_table[index];
    hash_table[index] = new_pair;
}

int get(const char* key){
    unsigned int index = hash(key) % TABLE_SIZE;
    struct Pair* node = hash_table[index];
    while (node){
        printf(">>>> %d\n", node->value);
        if(strcmp(node->key, key) == 0)return node->value;
        node = node->next;
    }
    return -1;
}

void print_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("[%d] -> ", i);
        struct Pair* node = hash_table[i];
        while(node){
            printf("(%s: %d)\n", node->key, node->value);
            node = node->next;
        }
        printf("NULL\n");
    }
}

void delete(const char *key){
    unsigned int index = hash(key) % TABLE_SIZE;
    struct Pair *node = hash_table[index];
    struct Pair *del= NULL;
    while (node) {
        if (strcmp(node->key, key) == 0) {
            if (del) {
                del->next = node->next;
            } else {
                hash_table[index] = node->next;
            }
            free(node->key);
            free(node);
            return;
        }
        del = node;
        node = node->next;
    }
}

int main(){
    insert("apple", 5);
    insert("key3", 15);
    insert("data", 20);
    insert("melon", 13);
    insert("pinapple", 21);
    insert("avocado", 23);
    insert("kiwi", 33);
    insert("mango", 25);
    insert("peach", 3);
    insert("banana", 7);


    printf(" apple %d", get("apple"));
    printf(" apple %d", get("banana"));
    
    print_table();

    //printf(" apple %d", get("orange"));

    //delete("banana");
    //printf("banana %d\n", get("banana"));

    return 0;
}


