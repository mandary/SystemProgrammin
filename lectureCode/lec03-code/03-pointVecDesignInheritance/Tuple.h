#ifndef TUPLE_H
#define TUPLE_H

typedef struct tuple_st *Tuple;

// Function pointers for virtual functions (delete and toString).
struct tuple_vtable_st {
  void (*delete)(Tuple t);
  char *(*toString)(const Tuple t);
};

// The storage occupied by a Tuple object
typedef struct tuple_st {
  struct tuple_vtable_st *vtable;
  double x;
  double y;
} * Tuple;

// These methods are not "virtual" -- they cannot be dynamically
// dispatched.
Tuple  tuple_new();
// The leading '_' in these names means "intended for internal use".
// We can't make them private, though (i.e., can't omit them
// from this .h file) because the subclass(s) need to invoke them.
void  _tuple_constructor(Tuple t);
Tuple _tuple_add(Tuple this, const Tuple that);

#endif // TUPLE_H
