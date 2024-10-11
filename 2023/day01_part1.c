#include "Cello.h"
#include "helpers/io.h"
#include "helpers/string.h"

int get_calibration_value(var line) {
  var value = new (String);
  concat(value, first(line, $(Function, is_digit)));
  concat(value, last(line, $(Function, is_digit)));
  var number = new (Int);
  look_from(number, value, 0);
  return c_int(number);
}

int main(int argc, char **argv) {
  println("---------------");
  println("Day 01 - Part 1");
  println("---------------");

  int answer = 0;
  foreach (line in lines(read_all($S("day01.txt")))) {
    answer += get_calibration_value(line);
  }
  println("Answer: %i", $I(answer));

  return 0;
}
