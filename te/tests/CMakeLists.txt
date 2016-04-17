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

# Unit Tests need access to private implementation interface in order to test it
get_target_property(TE_INCLUDE_DIRS freettcn::te INCLUDE_DIRECTORIES)
include_directories(${TE_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})

add_executable(te_tests ${SOURCE_FILES})
target_link_libraries(te_tests 
        freettcn::te
        Threads::Threads ${GTEST_BOTH_LIBRARIES})
add_test(te_tests te_tests)
