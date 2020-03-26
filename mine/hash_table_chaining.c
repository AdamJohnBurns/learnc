#include <stdio.h>
#include <stdlib.h>

#define NUM_PAIRS 10

#define EMPTY -1

#define SUCCESS 1
#define FAILURE 2

typedef struct {
    int key;
    int value;
} t_key_value_pair;

typedef struct {
    t_key_value_pair *key_value;
} t_array_of_key_values;

t_array_of_key_values *hash_table;
int hash_table_length;
int num_items_inserted;
int fill_percentage;

void free_memory () {
    printf("Freeing memory\n");

    if (hash_table != NULL) {
        for (int i = 0; i < hash_table_length; i++) {
            free(hash_table[i].key_value);
        }

        free(hash_table);
    }
}

void reset_table (new_length) {
    free_memory();

    printf("Resetting table to size %d\n", new_length);

    // TODO get this memory setup right. i dont think t_array_of_key_values is needed at all.

    hash_table = (t_array_of_key_values *)malloc(sizeof(t_array_of_key_values) * new_length);
    hash_table_length = new_length;

    for (int i = 0; i < hash_table_length; i++) {
        hash_table[i].key_value = (t_key_value_pair *)malloc(sizeof(t_key_value_pair) * NUM_PAIRS);
        for (int j = 0; j < NUM_PAIRS; j++) {
            // use the arrow when using a pointer
            // use the dot for array syntax
            hash_table[i].key_value[j].key = EMPTY;
            hash_table[i].key_value[j].value = EMPTY;
        }
    }

    num_items_inserted = 0;
    fill_percentage = 0;
}

void resize_table (new_length) {
    // first, copy the existing data
    // int *copied_hash_table = (int *)malloc(sizeof(int) * hash_table_length);

    // for (int i = 0; i < hash_table_length; i++) {
    //     copied_hash_table[i] = hash_table[i];
    // }

    // then, resize the table
    // reset_table(new_length);

    // then rehash each item
    // ? need old length?
}

int hash_key (key) {
    int hashed_key = key % hash_table_length;
    //printf("Generated hashed key: %d, from key: %d\n", hashed_key, key);
    return hashed_key;
}

void update_fill_percentage () {
    fill_percentage = 100 * num_items_inserted / hash_table_length;
}

int insert_item (key, value) {
    int hashed_key = hash_key(key);
    t_key_value_pair *entry = hash_table[hashed_key].key_value;

    // TODO handle collision insertion
    if (entry->key == EMPTY) {
        entry->key = key;
        entry->value = value;

        num_items_inserted++;
        update_fill_percentage();

        printf("Succeeded inserting hashed key: %d, key: %d, value: %d, num items: %d, fill percentage: %d%%\n", hashed_key, key, value, num_items_inserted, fill_percentage);

        return SUCCESS;
    } else {
        printf(">>> Failed inerting, collision occured with hashed key: %d, key: %d, value: %d\n", hashed_key, key, value);
        return FAILURE;
    }
}

// int get_item (key) {
//     int hashed_key = hash_key(key);
//     int value = hash_table[hashed_key];

//     if (value == EMPTY) {
//         printf(">>> Failed getting item with hashed key: %d, EMPTY value found!\n", hashed_key);
//         return FAILURE;
//     } else {
//         printf("Succeeded getting item with hashed key: %d, key: %d, value: %d\n", hashed_key, key, value);
//         return SUCCESS;
//     }
// }

void render_table () {
    printf("Table values: [ ");

    t_key_value_pair *key_value;
    for (int i = 0; i < hash_table_length; i++) {
        key_value = hash_table[i].key_value;

        // TODO render more than the first
        if (key_value != NULL) {
            if (key_value->key == EMPTY) {
                printf("EMPTY, ");
            } else {
                printf("key:%d value:%d, ", key_value->key, key_value->value);
            }
        } else {
            printf("Invalid memory for key value pair");
        }
    }

    printf("]\n");
}

int main (int argc, char *argv[]) {
    reset_table(5);

    insert_item(0, 55555);
    // insert_item(88, 88888);

    // get_item(0);
    // get_item(5);
    // get_item(88);

    render_table();

    free_memory();

    return 0;
}
