#pragma once

#include "Cello.h"
#include "bool.h"
#include <ctype.h>

#define $C(X) $(Char, X)

struct Char {
  char value;
};

static char *Char_c_str(var self) {
  struct Char *c = self;
  return &(c->value);
}

static int64_t Char_c_int(var self) {
  struct Char *c = self;
  return c->value;
}

static int Char_show(var self, var out, int pos) {
  return print_to(out, pos, "'%s'", c_str(self));
}

var Char = Cello(Char, Instance(C_Str, Char_c_str), Instance(C_Int, Char_c_int),
                 Instance(Show, Char_show));

var get_char(var self, size_t index) {
  if (index >= len(self))
    return new (Char);
  char c = *(c_str(self) + index);
  return new (Char, $C(c));
}

var is_alpha(var args) {
  struct Char *c = (type_of(args) == Tuple) ? get(args, $I(0)) : args;
  return new (Bool, $T(isalpha(c->value)));
}

var is_digit(var args) {
  struct Char *c = (type_of(args) == Tuple) ? get(args, $I(0)) : args;
  return new (Bool, $T(isdigit(c->value)));
}
