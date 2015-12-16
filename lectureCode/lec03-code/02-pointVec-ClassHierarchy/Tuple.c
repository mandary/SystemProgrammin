#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "Tuple.h"

Tuple tuple_new() {
  Tuple t = (Tuple)malloc(1 * sizeof(struct tuple_st));
  if ( t == NULL ) return NULL;
  t->x = t->y = 0.0;
  return t;
}

void tuple_delete(Tuple t) {
  free(t);
}

char *tuple_toString(const Tuple t) {
  char *resultStr;
  asprintf( &resultStr, "Tuple(%lf, %lf)", t->x, t->y );
  return resultStr;
}

Tuple _tuple_add(Tuple this, const Tuple that) {
  this->x += that->x;
  this->y += that->y;
  return this;
}
