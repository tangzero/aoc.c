#pragma once
#include "Cello.h"

var read_all(var filename) {
  var content = new (String);
  with(f in new (File, filename, $S("r"))) {
    sseek(f, 0, SEEK_END);
    ssize_t size = stell(f);
    resize(content, size);
    sseek(f, 0, SEEK_SET);
    sread(f, c_str(content), size);
  }
  return content;
}
