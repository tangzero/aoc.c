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
    if (c_bool(call(predicate, c)))
      return new (Char, c);
  }
  return new (Char);
}

var last(var self, var predicate) {
  foreach (c in reverse(str_to_array(self))) {
    if (c_bool(call(predicate, c)))
      return c;
  }
  return new (Char);
}

var stars_with(var self, var prefix) {
  if (len(self) < len(prefix))
    return False;
  for (size_t i = 0; i < len(prefix); i++) {
    if (!eq(get_char(self, i), get_char(prefix, i)))
      return False;
  }
  return True;
}

var ends_with(var self, var suffix) {
  if (len(self) < len(suffix))
    return False;
  for (size_t i = 0; i < len(suffix); i++) {
    if (!eq(get_char(self, len(self) - len(suffix) + i), get_char(suffix, i)))
      return False;
  }
  return True;
}
