#pragma once

#include "Cello.h"
#include "char.h"

#define lines(self) split(self, $C('\n'))

var str_to_array(var self) {
  var arr = new (Array, Char);
  for (size_t i = 0; i < len(self); i++) {
    push(arr, get_char(self, i));
  }
  return arr;
}

var split(var self, var delimiter) {
  var parts = new (Array, String);
  var part = new (String);
  for (size_t i = 0; i < len(self); i++) {
    var c = get_char(self, i);
    if (eq(c, delimiter)) {
      push(parts, part);
      part = new (String);
      continue;
    }
    concat(part, c);
  }
  if (len(part) > 0)
    push(parts, part);
  return parts;
}

var first(var self, var predicate) {
  foreach (c in str_to_array(self)) {
    if (eq(call(predicate, c), $T(true)))
      return new (Char, c);
  }
  return new (Char);
}

var last(var self, var predicate) {
  foreach (c in reverse(str_to_array(self))) {
    if (eq(call(predicate, c), $T(true)))
      return c;
  }
  return new (Char);
}
