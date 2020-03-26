//
//  ex16.c
//  learnc
//
//  Created by Burns, Adam on 21/11/17.
//  Copyright © 2017 Burns, Adam. All rights reserved.
//

#include <stdio.h> // printf()
#include <assert.h> // assert()
#include <stdlib.h> // malloc(), free()
#include <string.h> // strdup()

// a struct is set of variables stored in one block of memory
// its a compound data type
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create (char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person)); // allocate provided size of bytes of uninitialized storage.
                                                   // returns pointer to allocated space, it can't be freed if that
                                                   // pointer is lost
    
    // assert() is a macro, if true do nothing, if false then display an error on stderr
    // NULL is a special macro which means "unset of invalid pointer"
    assert(who != NULL);
    
    // note because 'who' is a pointer, we need to use '->' to access its properties.
    // if it was just a standard variable (eg struct Person myPerson;) we would use
    // a '.' instead, eg myPerson.age = 50
    
    who->name = strdup(name); // string_duplicate(), returns a pointer to a duplicate of the pointed at string.
                             // it's like malloc() but for strings. (which means it needs to be manually freed)
    who->age = age;
    who->height = height;
    who->weight = weight;
    
    return who;
}

void Person_destroy (struct Person *who)
{
    assert(who != NULL);
    
    free(who->name); // deallocates space allocated by malloc (or other memory functions)
    // we need to manually free 'name' as its allocated space by strdup()
    // failing to free either of these causes a memory leak
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight:%d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main2 (int argc, char *argv[])
{
    // make two
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);
    
    // make one on the stack rather than in random memory
    struct Person my_person;
    my_person.name = "Test";
    my_person.age = 10;
    my_person.height = 100;
    my_person.weight = 1000;
    printf("my_person is at memory location %p:\n", &my_person);
    Person_print(&my_person);
    
    // print them out, and print the memory location the memory is allocated to
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);
    
    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);
    
    // adjust attributes
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);
    
    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);
    
    // destroy to release memory
    Person_destroy(joe);
    Person_destroy(frank);
    
//    Person_print(NULL);
//    Person_destroy(NULL);
    
    return 0;
}





























