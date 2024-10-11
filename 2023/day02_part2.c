#include "Cello.h"
#include "helpers/io.h"
#include "helpers/string.h"

int power_of_minimum_set(var line) {
  var game_n_subsets = split(line, $C(':'));
  var subsets = get(game_n_subsets, $I(1));

  var minimun = new (Table, String, Int);
  set(minimun, $S("red"), $I(0));
  set(minimun, $S("green"), $I(0));
  set(minimun, $S("blue"), $I(0));

  foreach (cubes in split(subsets, $C(';'))) {
    foreach (cube in split(cubes, $C(','))) {
      var quantity = new (Int);
      var color = new (String);
      scan_from(cube, 0, "%d %s", quantity, color);
      if (gt(quantity, get(minimun, color))) {
        // TODO: looks like a bug with Cello's Table
        rem(minimun, color); // need to remove the key first
        set(minimun, color, quantity);
      }
    }
  }

  int power = 1;
  foreach (color in minimun)
    power *= c_int(get(minimun, color));
  return power;
}

int main(int argc, char **argv) {
  println("---------------");
  println("Day 02 - Part 2");
  println("---------------");

  int answer = 0;
  foreach (line in lines(read_all($S("day02.txt")))) {
    answer += power_of_minimum_set(line);
  }
  println("Answer: %d", $I(answer));

  return 0;
}
