// FreeTTCN is a free compiler and execution environment for TTCN-3 language.
//
// Copyright (C) 2016 Mateusz Pusz
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "freettcn/types.h"
#include "gsl.h"
#include <cassert>
#include <cstdint>
#include <limits>
#include <vector>

namespace gsl {

template <std::ptrdiff_t Extent = dynamic_range>
using cu32zstring = basic_zstring<const char32_t, Extent>;
}

namespace freettcn {

// Simple basic types and values

using integer_t = Tinteger;
using float_t = Tfloat;
using boolean_t = Tboolean;
enum class verdicttype_t : std::int8_t { pass, fail, inconc, none, error };

static_assert(std::numeric_limits<float_t>::has_quiet_NaN, "not_a_number not available for Tfloat type");
static_assert(std::numeric_limits<float_t>::has_infinity, "infinity not available for Tfloat type");
static_assert(std::numeric_limits<float_t>::is_iec559, "-infinity not available for TFloat type");
constexpr float_t not_a_number = std::numeric_limits<float_t>::quiet_NaN();
constexpr float_t infinity = std::numeric_limits<float_t>::infinity();

// Basic string types and values

using bitstring_t = std::vector<bool>;

inline bitstring_t operator"" _B(gsl::czstring<> txt, std::size_t len)
{
  bitstring_t str;
  str.reserve(len);
  for(auto i = 0U; i < len; ++i) {
    str.push_back(txt[i] - 48 != 0);
  }
  return str;
}

using hexstring_t = std::vector<std::uint8_t>;

inline hexstring_t operator"" _H(gsl::czstring<> txt, std::size_t len)
{
  hexstring_t str;
  str.reserve(len);
  for(auto i = 0U; i < len; ++i) {
    char substr[] = {txt[i], '\0'};
    str.push_back(static_cast<std::uint8_t>(std::stoul(&substr[0], nullptr, 16)));
  }
  return str;
}

using octetstring_t = std::vector<std::uint8_t>;

inline octetstring_t operator"" _O(gsl::czstring<> txt, std::size_t len)
{
  assert(len % 2 == 0);
  octetstring_t str;
  str.reserve(len / 2);
  for(auto i = 0U; i < len / 2; ++i) {
    char substr[] = {txt[2 * i], txt[2 * i + 1], '\0'};
    str.push_back(static_cast<std::uint8_t>(std::stoul(&substr[0], nullptr, 16)));
  }
  return str;
}

using charstring_t = std::string;

inline charstring_t operator"" _ch(gsl::czstring<> txt, std::size_t len) { return charstring_t{txt, len}; }

inline char32_t get_char(int group, int plane, int row, int cell)
{
  return static_cast<char32_t>((group << 24) + (plane << 16) + (row << 8) + cell);
}

using universal_charstring_t = std::u32string;

inline universal_charstring_t operator"" _u_ch(gsl::cu32zstring<> txt, std::size_t len)
{
  return universal_charstring_t{txt, len};
}

template <class... T>
class subtype_list {
};

}  // namespace freettcn
