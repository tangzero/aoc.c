#pragma once

#include "Cello.h"

#define $T(X) $(Bool, X)

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
