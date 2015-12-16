#ifndef TUPLE_H
#define TUPLE_H

// This is the base class definition.

typedef struct tuple_st {
  double x;
  double y;
} * Tuple;

Tuple tuple_new();
void  tuple_delete(Tuple t);
char *tuple_toString(const Tuple t);

// Think of this method as "protected" --
// By common convention, the leading '_' in the name
// indicates it's "for internal use only."
Tuple _tuple_add(Tuple this, const Tuple that);

#endif // TUPLE_H
