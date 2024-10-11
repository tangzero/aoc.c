#pragma once

#include "Cello.h"

#define $T(X) $(Bool, X)
#define True new (Bool, $T(true))
#define False new (Bool, $T(false))

struct Bool {
  char value;
};

static int Bool_show(var self, var out, int pos) {
  struct Bool *b = self;
  if (b->value)
    return print_to(out, pos, "true");
  return print_to(out, pos, "false");
}

var Bool = Cello(Bool, Instance(Show, Bool_show));

#define c_bool(X) (*(struct Bool *)X).value
