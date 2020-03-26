#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1

#define SUCCESS 1
#define FAILURE 2

int *hash_table;
int hash_table_length;
int num_items_inserted;
int fill_percentage;

void free_memory () {
    if (hash_table != NULL) {
        free(hash_table);
    }
}

void reset_table (new_length) {
    printf("Resetting table to size %d\n", new_length);

    free_memory();

    hash_table = (int*)malloc(sizeof(int) * new_length);
    hash_table_length = new_length;
    for (int i = 0; i < hash_table_length; i++) {
        hash_table[i] = EMPTY;
    }

    num_items_inserted = 0;
    fill_percentage = 0;
}

// hashing is one way, you can't unhash a value
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

    if (hash_table[hashed_key] == EMPTY) {
        hash_table[hashed_key] = value;
        num_items_inserted++;
        update_fill_percentage();
        printf("Succeeded inserting hashed key: %d, key: %d, value: %d, num items: %d, fill percentage: %d%%\n", hashed_key, key, value, num_items_inserted, fill_percentage);
        return SUCCESS;
    } else {
        printf(">>> Failed inerting, collision occured with hashed key: %d, key: %d, value: %d\n", hashed_key, key, value);
        return FAILURE;
    }
}

int get_item (key) {
    int hashed_key = hash_key(key);
    int value = hash_table[hashed_key];

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

    int value;
    for (int i = 0; i < hash_table_length; i++) {
        value = hash_table[i];
        if (value == EMPTY) {
            printf("EMPTY, ");
        } else {
            printf("%d, ", value);
        }
    }

    printf("]\n");
}

int main (int argc, char *argv[]) {
    reset_table(5);

    insert_item(0, 55555);
    insert_item(88, 88888);

    get_item(0);
    get_item(5);
    get_item(88);

    render_table();

    printf("------\n");

    reset_table(10);

    insert_item(5, 55555);
    insert_item(88, 88888);
    insert_item(902, 99999);
    insert_item(5555, 5555555);

    get_item(10000);
    get_item(5);
    get_item(902);

    render_table();

    free_memory();

    return 0;
}
