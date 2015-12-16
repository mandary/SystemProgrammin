#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "Tuple.h"

//--------------------------------------------------
// We start with definitions of the virtual functions.
// We use 'static' to restrict the scope of their names
// to this file, since no client code should invoke them
// directly.  We start the names with '_' to indicate to
// human readers that these routines are for internal use.
//--------------------------------------------------
static void _delete(Tuple t) {
  free(t->vtable);
  free(t);
}

static char *_toString(const Tuple t) {
  char *resultStr;
  asprintf( &resultStr, "Tuple(%lf, %lf)", t->x, t->y );
  return resultStr;
}

//--------------------------------------------------
// The tuple class has two virtual functions, delete
// and toString.
//--------------------------------------------------
static struct tuple_vtable_st TUPLE_CLASS_VTABLE =
  { .delete = _delete,
    .toString = _toString
  };

//--------------------------------------------------
// We separate creating a new instance into two parts:
// 1. allocating memory (the new routine below)
// 2. initializing that memory (the constructor routine)
// That's so that the memory initialization method can
// be called by subclass code when a new instance of
// the subclass is created.
//--------------------------------------------------

void _tuple_constructor(Tuple t) {
  t->x = 0.0;
  t->y = 0.0;
}

Tuple tuple_new() {
  Tuple t = (Tuple)malloc(1 * sizeof(*t));
  if ( t == NULL ) return NULL;
  t->vtable = &TUPLE_CLASS_VTABLE;
  _tuple_constructor(t);
  return t;
}

// A Tuple method that cannot be overridden.
// (We intend it to be "protected" -- available
// to subclasses, but not for use by general client code.)
Tuple _tuple_add(Tuple this, const Tuple that) {
  this->x += that->x;
  this->y += that->y;
  return this;
}

