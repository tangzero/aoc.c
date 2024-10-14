#pragma once

#include <ctype.h>

#include "Cello.h"

#define $C(X) $(Char, X)

struct Char
{
    char value;
};

static char *Char_c_str(var self)
{
    struct Char *c = self;
    return &(c->value);
}

static int64_t Char_c_int(var self)
{
    struct Char *c = self;
    return c->value;
}

static int Char_show(var self, var out, int pos)
{
    return print_to(out, pos, "'%s'", c_str(self));
}

var Char = Cello(Char, Instance(C_Str, Char_c_str), Instance(C_Int, Char_c_int), Instance(Show, Char_show));

var get_char(var self, size_t index)
{
    if (index >= len(self))
        throw(Exception, "index out of bounds. len=%d, index=%d", $I(len(self)), $I(index));
    char c = *(c_str(self) + index);
    return new (Char, $C(c));
}

bool is_alpha(var self)
{
    struct Char *c = self;
    return isalpha(c->value);
}

bool is_digit(var self)
{
    struct Char *c = self;
    return isdigit(c->value);
}
