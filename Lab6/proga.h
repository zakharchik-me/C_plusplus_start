//
// Created by Anton Zakharov on 18.05.2022.
//

#pragma once

template <typename range, typename object>
bool none_of(range, range, bool (&func)(object));
template <typename range, typename object>
bool is_sorted(range, range, bool (&func)(object, object));
template <typename range, typename object>
object find_not(range, range, object);

#include "realize.cpp"