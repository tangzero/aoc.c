#include "Cello.h"
#include "helpers/io.h"
#include "helpers/string.h"

int get_valid_game_id(var line, var max_values) {
  var game_n_subsets = split(line, $C(':'));
  var game = get(game_n_subsets, $I(0));
  var subsets = get(game_n_subsets, $I(1));

  var id = new (Int);
  scan_from(game, 0, "Game %d", id);

  foreach (cubes in split(subsets, $C(';'))) {
    foreach (cube in split(cubes, $C(','))) {
      var quantity = new (Int);
      var color = new (String);
      scan_from(cube, 0, "%d %s", quantity, color);
      if (gt(quantity, get(max_values, color)))
        throw(Exception, "Invalid game");
    }
  }
  return c_int(id);
}

int main(int argc, char **argv) {
  println("---------------");
  println("Day 02 - Part 1");
  println("---------------");

  var max_values = new (Table, String, Int);
  set(max_values, $S("red"), $I(12));
  set(max_values, $S("green"), $I(13));
  set(max_values, $S("blue"), $I(14));

  int answer = 0;
  foreach (line in lines(read_all($S("day02.txt")))) {
    try answer += get_valid_game_id(line, max_values);
    catch (Exception) continue;
  }
  println("Answer: %d", $I(answer));

  return 0;
}
