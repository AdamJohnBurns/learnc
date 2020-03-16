/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// problem, got right into implementation without planning the algorithm
// sort it out logically first, write last
/*void printNode (char* message, struct ListNode* node) {
    printf(message);

    if (node != NULL) {
        printf(" %d\n", node->val);
    } else {
        printf(" NULL\n");
    }
}

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *currentNode = head;
    struct ListNode *nextNode = NULL;
    struct ListNode *previousNode = NULL;
    
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->val = 0;
    newNode->next = NULL;
    
    while (currentNode != NULL) {
        printNode("previousNode =", previousNode);
        printNode("currentNode =", currentNode);
        printNode("nextNode =", nextNode);
        printNode("newNode =", newNode);
        printf("---\n");
        
        previousNode = currentNode;
        if (currentNode->next != NULL) 
            nextNode = currentNode->next->next;
        currentNode = currentNode->next;
        
        newNode->val = currentNode->val;
        newNode->next = previousNode;
        
        // currentNode->next = previousNode;
    }
    
    return newNode;
}*/


// 1. start with overall strategy
// 2. develop a big picture, basic algorithm
// 3. test the algorithm logically
// 4. implement 

// strategy: iteration through list of nodes

// algorithm:
//      if there's no next node from head, return
//      current = head->next
//      previous at head
//      WHILE theres still a next node
//          save previous node
//          save next node
//          current node next becomes previous node
//          move to saved next
// test:
//      1->2->3->4->5->NULL
//      current = 2
//      previous = 1
//      LOOP 1
//          previous = 2
//          next = 3
//          current->next = 2
//          current = 3


/*
algorithm2:

get initial previous node
LOOP
    save next node
    set current node next to previous node
    save current as previous
    move to next node
    if no next node, break

TEST
    start 1
    previous = null
    LOOP 1
        saved next 2
        nodeNext = previous (null)
        previous = current 1
        current = saved next 2
        current ok, continue
    LOOP 2
        saved next 3
        nodeNext = previous (1)
        previous = current (2)
        current = saved next 3
        current ok, continue
*/

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *previousNode = NULL,
        *currentNode = head,
        *nextNode = NULL;

    if (currentNode == NULL || currentNode->next == NULL) return head;

    do {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        
        if (nextNode == NULL) break;
        
        currentNode = nextNode;
    } while (currentNode != NULL);

    return currentNode;
}




