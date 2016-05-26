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

#include "basic.h"
#include <gtest/gtest.h>
#include <cmath>

using namespace freettcn;

TEST(SimpleBasicTypesAndValues, floatNotANumber) { ASSERT_EQ(true, std::isnan(not_a_number)); }
TEST(SimpleBasicTypesAndValues, floatInfinity) { ASSERT_EQ(true, std::isinf(infinity)); }

TEST(BasicStringTypesAndValues, bitstringExample1)
{
  const auto exp = bitstring_t{false, true, true, false, true};
  ASSERT_EQ(exp, "01101"_B);
}

TEST(BasicStringTypesAndValues, bitstring2Values)
{
  const auto exp = bitstring_t{false, true};
  ASSERT_EQ(exp, "01"_B);
}

TEST(BasicStringTypesAndValues, hexstringExample2)
{
  const auto exp = hexstring_t{0xA, 0xB, 0x0, 0x1, 0xD};
  ASSERT_EQ(exp, "AB01D"_H);
  ASSERT_EQ(exp, "ab01d"_H);
  ASSERT_EQ(exp, "Ab01D"_H);
}

TEST(BasicStringTypesAndValues, octetstringExample3)
{
  const auto exp = octetstring_t{0xFF, 0x96};
  ASSERT_EQ(exp, "FF96"_O);
  ASSERT_EQ(exp, "ff96"_O);
  ASSERT_EQ(exp, "Ff96"_O);
}

TEST(BasicStringTypesAndValues, charstringExample4)
{
  const auto exp = charstring_t{'"', 'a', 'b', '"', 'c', 'd', '"'};
  ASSERT_EQ(exp, "\"ab\"cd\""_ch);
}

TEST(BasicStringTypesAndValues, char) { ASSERT_EQ(U'\u0171', get_char(0, 0, 1, 113)); }

TEST(BasicStringTypesAndValues, universalCharstringExample5)
{
  const auto exp = universal_charstring_t{U"the Braille character \u2830 looks like this"};
  ASSERT_EQ(exp, U"the Braille character "_u_ch + get_char(0, 0, 40, 48) + U" looks like this"_u_ch);
}

TEST(DISABLED_BasicStringTypesAndValues, universalCharstringExample6)
{
  // TODO implement "char (U4E2D, U56FD)"
  FAIL();
}

TEST(DISABLED_AccessingIndividualStringElements, Example1)
{
  auto my_bit_string = "11110111"_B;
  //  my_bit_string[4] = "1"_B;
  ASSERT_EQ("11111111"_B, my_bit_string);
}

TEST(DISABLED_AccessingIndividualStringElements, Example2)
{
  bitstring_t my_bitstring_a, my_bitstring_b, my_bitstring_c;
  my_bitstring_a = "010"_B;
  //  my_bitstring_a[1] = "11"_B; //causes an error as only individual elements can be accessed

  my_bitstring_b = "1"_B;
  //  my_bitstring_b[4] = "1"_B; //causes an error as the index is larger than the length of the lhs

  my_bitstring_c = ""_B;
  //  my_bitstring_c[0] = "1"_B; // value of my_bitstring_c is '1'B
  ASSERT_EQ("1"_B, my_bitstring_c);
  //  my_bitstring_c[1] = "0"_B; // value of my_bitstring_c is '10'B
  ASSERT_EQ("10"_B, my_bitstring_c);
}
