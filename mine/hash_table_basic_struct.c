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

t_key_value_pair *hash_table;
int hash_table_length;
int num_items_inserted;
int fill_percentage;

void free_memory () {
    printf("Freeing memory\n");

    if (hash_table != NULL) {
        free(hash_table);
    }
}

void reset_table (new_length) {
    free_memory();

    printf("Resetting table to size %d\n", new_length);

    // allocate an array of array of key/value pairs
    hash_table = (t_key_value_pair *)malloc(sizeof(t_key_value_pair) * new_length);
    hash_table_length = new_length;

    // clear the malloc'd memory of garbage
    for (int i = 0; i < hash_table_length; i++) {
        hash_table[i].key = EMPTY;
        hash_table[i].value = EMPTY;
    }

    num_items_inserted = 0;
    fill_percentage = 0;
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
    int existing_key = hash_table[hashed_key].key;

    if (existing_key == EMPTY) {
        hash_table[hashed_key].key = key;
        hash_table[hashed_key].value = value;

        num_items_inserted++;
        update_fill_percentage();

        printf("Succeeded inserting hashed key: %d, key: %d, value: %d, num items: %d, fill percentage: %d%%\n", hashed_key, key, value, num_items_inserted, fill_percentage);

        return SUCCESS;
    } else {
        printf(">>> Failed inerting, collision occured with hashed key: %d, key: %d, value: %d\n", hashed_key, key, value);

        // chaining or some other means needed to handle collisions. for now, just show an error and continue

        return FAILURE;
    }
}

int get_item (key) {
    int hashed_key = hash_key(key);
    int value = hash_table[hashed_key].value;

    if (value == EMPTY) {
        printf(">>> Failed getting item with hashed key: %d, EMPTY value found!\n", hashed_key);
        return FAILURE;
    } else {
        printf("Succeeded getting item with hashed key: %d, key: %d, value: %d\n", hashed_key, key, value);
        return SUCCESS;
    }
}

void render_table () {
    printf("Table values: [ ");

    for (int i = 0; i < hash_table_length; i++) {
        printf("index:%d key:%d value:%d, ", i, hash_table[i].key, hash_table[i].value);
    }

    printf("]\n");
}

void resize_table(new_length) {
    printf("Resizing table. Before resize: \n");
    render_table();

    // first, copy the existing data
    t_key_value_pair *copied_hash_table = (t_key_value_pair *)malloc(sizeof(t_key_value_pair) * hash_table_length);

    for (int i = 0; i < hash_table_length; i++)
    {
        // dont copy the pointer reference, copy the actual values by value
        copied_hash_table[i].key = hash_table[i].key;
        copied_hash_table[i].value = hash_table[i].value;
    }

    int old_hash_table_length = hash_table_length;

    // then, resize the table
    reset_table(new_length);

    // then rehash each item
    for (int i = 0; i < old_hash_table_length; i++)
    {
        if (copied_hash_table[i].key != EMPTY) {
            insert_item(copied_hash_table[i].key, copied_hash_table[i].value);
        }
    }

    printf("After resize: \n");
    render_table();
}

int main (int argc, char *argv[]) {
    reset_table(5);
    render_table();

    insert_item(0, 55555);
    insert_item(88, 88888);

    get_item(0);
    get_item(5);
    get_item(88);

    render_table();

    resize_table(10);

    free_memory();

    return 0;
}
