#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL) {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (newh == NULL || q == NULL) {
        return false;
    }

    // Allocate space and copy the string
    newh->value = malloc(sizeof(char) * (strlen(s) + 1));
    strncpy(newh->value, s, strlen(s) + 1);

    newh->next = q->head;
    q->head = newh;

    // first time
    if (q->tail == NULL) {
        q->tail = q->head;
    }

    q->size += 1;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newt;  // newt means new element in tail
    newt = malloc(sizeof(list_ele_t));
    if (q == NULL || newt == NULL) {
        return false;
    }

    newt->value = malloc(sizeof(char) * strlen(s) + 1);
    strncpy(newt->value, s, strlen(s) + 1);
    newt->next = NULL;
    if (q->tail == NULL) {
        q->tail = newt;
        q->head = newt;
    } else {
        q->tail->next = newt;
        q->tail = newt;
    }

    q->size += 1;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    if (q == NULL || q->head == NULL) {
        return false;
    }
    if (sp != NULL) {
        strncpy(sp, q->head->value, bufsize - 1);
    }
    list_ele_t *tmp;
    tmp = q->head;
    q->head = q->head->next;
    tmp->next = NULL;
    free(tmp->value);
    free(tmp);

    q->size -= 1;
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
    if (q == NULL || q->head == NULL) {
        return;
    }
    list_ele_t *prev, *now, *next;
    prev = q->head;
    now = q->head->next;
    if (now == NULL) {  // there is only one element in queue
        return;
    }

    next = q->head->next->next;

    // swap head and tail
    q->head = q->tail;
    q->tail = prev;

    prev->next = NULL;
    now->next = prev;
    while (next != NULL) {
        prev = now;
        now = next;
        next = now->next;

        now->next = prev;
    }
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
