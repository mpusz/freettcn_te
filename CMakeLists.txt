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

cmake_minimum_required(VERSION 3.2)
project(freettcn_te C CXX)

# add GoogleTest target
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
add_library(GoogleTest INTERFACE IMPORTED)
set_property(TARGET GoogleTest PROPERTY
        INTERFACE_INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS})
set_property(TARGET GoogleTest PROPERTY
        INTERFACE_LINK_LIBRARIES Threads::Threads ${GTEST_BOTH_LIBRARIES})

# add GSL target
add_subdirectory(src/external/GSL EXCLUDE_FROM_ALL)

# compilers-specific configuration
include(cmake/compilers.cmake OPTIONAL)

# add freettcn code
add_subdirectory(src/te)
