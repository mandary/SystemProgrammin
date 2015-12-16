//------------------------------------------------
// void* package
//------------------------------------------------

#include <stdlib.h>
#include <assert.h>

#include "llist.h"

typedef struct llist_node_t {
  struct llist_node_t *next;
  void *data;
} LList_node_priv, *LList_priv;


// Initializes an LList
LList LList_init(LList *pList) {
  assert(pList != NULL);
  *pList = NULL;
  return *pList;
}


LList LList_push(LList *pListPub, void *data) {
  LList_priv *pList = (LList_priv*)pListPub;
  assert(pList != NULL);
  LList_node_priv *pNode = (LList_node_priv*)malloc(sizeof(LList_node_priv));
  if ( pNode == NULL ) return NULL;
  pNode->next = *pList;
  pNode->data = data;
  *pList = pNode;
  return *pList;
}

void* LList_pop(LList *pListPub) {
  LList_priv *pList = (LList_priv*)pListPub;
  assert(pList != NULL);
  if ( *pList == NULL ) return NULL;
  void *result = (*pList)->data;
  LList_node_priv *pTemp = (*pList)->next;
  free((*pList));
  *pList = pTemp;
  return result;
}

bool LList_isEmpty(const LList pList) {
  return pList == NULL;
}

LList LList_map(const LList list, LList_map_callback callback) {
  for ( LList_node_priv *pNode = list; pNode != NULL; pNode = pNode->next ) {
    if ( callback(pNode->data) ) break;
  }
  return list;
}
