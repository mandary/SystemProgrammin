#ifndef LLIST_H
#define LLIST_H

//------------------------------------------------
// void* package
//------------------------------------------------

#include <stdbool.h>

// We're going to hide the implementation from clients.
// We declare just enough information to let the client
// code compile, without revealing the details of the
// key structures.

typedef void * LList;

// What does this next prototype imply about how 
// we intend the user of our package to create LLists?
LList LList_init(LList *pList);

bool LList_isEmpty(const LList pList);

// This simple implementation never tries to free any user 
// data.  We simply store whatever we are given when
// push is called, and return it when pop is called.
LList LList_push(LList *pList, void *data);
void* LList_pop(LList *pList);  // returns NULL if the list is empty

// Iterate over the elements of the list, handing each one
// to the callback function.  That function can return false
// to continue the iteration, and true to stop.

typedef bool (*LList_map_callback)(void *el);
LList LList_map(const LList list, LList_map_callback callback);

#endif // LLIST_H
