# FreeTTCN is a free compiler and execution environment for TTCN-3 language.
#
# Copyright (C) 2016 Mateusz Pusz
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

set(SOURCE_FILES test_te.cpp)

get_target_property(TE_INCLUDES te INCLUDE_DIRECTORIES)
include_directories(${TE_INCLUDES})

add_executable(unit_tests ${SOURCE_FILES})
set_property(TARGET unit_tests PROPERTY CXX_STANDARD 14)
target_link_libraries(unit_tests te)

# import and add gtest
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(unit_tests ${GTEST_BOTH_LIBRARIES})
add_test(AllTests unit_tests)
