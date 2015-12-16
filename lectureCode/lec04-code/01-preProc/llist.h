#ifndef LLIST_H
#define LLIST_H

//------------------------------------------------------------
// preprocessor package
//------------------------------------------------------------

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// We're going to create llist implementations customized
// to hold data of particular types.  The client specifies
// the type, and the client causes the specialized code
// to be created and compiled.  That means the full
// llist implementation must be available to the client.
// (It's all in this .h file.)

#define CREATE_LLIST_TYPE(t,s)                                           \
typedef struct llist_node_t_ ## s {                                      \
  struct llist_node_t_ ## s  *next;                                      \
  t data;                                                                \
} LList_node_ ## s;                                                      \
typedef LList_node_ ## s *LList_ ## s;                                   \
                                                                         \
LList_ ## s  LList_ ## s ## _init(LList_ ## s *pList) {                  \
 assert(pList != NULL);                                                  \
 *pList = NULL;                                                          \
 return *pList;                                                          \
}                                                                        \
                                                                         \
bool LList_ ## s ## _isEmpty(const LList_ ## s pList) {                  \
  return pList == NULL;                                                  \
}                                                                        \
                                                                         \
LList_ ## s LList_ ## s ## _push(LList_ ## s *pList, t data) {           \
  assert(pList != NULL);                                                 \
  LList_node_ ## s *pNode = (LList_node_ ## s *)malloc(sizeof(LList_node_ ## s )); \
  if ( pNode == NULL ) return NULL;                                      \
  pNode->next = *pList;                                                  \
  pNode->data = data;                                                    \
  *pList = pNode;                                                        \
  return *pList;                                                         \
}                                                                        \
                                                                         \
t LList_ ## s ## _pop(LList_ ## s *pList) {                              \
  assert(pList != NULL);                                                 \
  if ( *pList == NULL ) return 0;                                        \
  t result = (*pList)->data;                                             \
  LList_node_ ## s *pTemp = (*pList)->next;                              \
  free((*pList));                                                        \
  *pList = pTemp;                                                        \
  return result;                                                         \
}                                                                        \
                                                                         \
typedef bool (*LList_ ## s ## _map_callback)(t el);                      \
LList_ ## s LList_ ## s ## _map(const LList_ ## s list, LList_ ## s ## _map_callback callback) { \
  for ( LList_node_ ## s *pNode = list; pNode != NULL; pNode = pNode->next ) {   \
    if ( callback(pNode->data) ) break;                                  \
  }                                                                      \
  return list;                                                           \
}
#endif // LLIST_H
