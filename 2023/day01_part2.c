#include "Cello.h"
#include "helpers/char.h"
#include "helpers/io.h"
#include "helpers/string.h"

var find_number(var numbers, var iterable) {
  var number = new (String);
  foreach (c in iterable) {
    if (c_bool(is_digit(c)))
      return new (Char, c);
    concat(number, c);
    int i = '1';
    foreach (n in numbers) {
      if (c_bool(ends_with(number, n)))
        return new (Char, $C(i));
      i++;
    }
  }
  throw(Exception, "No number found");
  return NULL;
}

var first_number(var line) {
  var numbers =
      new (Array, String, $S("one"), $S("two"), $S("three"), $S("four"),
           $S("five"), $S("six"), $S("seven"), $S("eight"), $S("nine"));
  return find_number(numbers, str_to_array(line));
}

var last_number(var line) {
  var numbers =
      new (Array, String, $S("eno"), $S("owt"), $S("eerht"), $S("ruof"),
           $S("evif"), $S("xis"), $S("neves"), $S("thgie"), $S("enin"));
  return find_number(numbers, reverse(str_to_array(line)));
}

int get_calibration_value(var line) {
  var value = new (String);
  concat(value, first_number(line));
  concat(value, last_number(line));
  var number = new (Int);
  look_from(number, value, 0);
  return c_int(number);
}

int main(int argc, char **argv) {
  println("---------------");
  println("Day 01 - Part 2");
  println("---------------");

  int answer = 0;
  foreach (line in lines(read_all($S("day01.txt")))) {
    answer += get_calibration_value(line);
  }
  println("Answer: %i", $I(answer));

  return 0;
}
