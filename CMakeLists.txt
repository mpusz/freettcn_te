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

# The project version number.
set(VERSION_MAJOR 0 CACHE STRING "Project major version number.")
set(VERSION_MINOR 0 CACHE STRING "Project minor version number.")
set(VERSION_PATCH 1 CACHE STRING "Project patch version number.")

# add dependencies
set(gtest_force_shared_crt ON CACHE BOOL "Use shared (DLL) run-time lib even when Google Test is built as static lib.")
add_subdirectory(src/external/googletest EXCLUDE_FROM_ALL)
target_include_directories(gtest_main PUBLIC src/external/googletest/include)
add_subdirectory(src/external/GSL EXCLUDE_FROM_ALL)

# compilers-specific configuration
include(cmake/compile_warnings.cmake OPTIONAL)

# add freettcn modules
add_subdirectory(src/te)

# install freettcn modules
install(EXPORT freettcn DESTINATION lib/freettcn
        NAMESPACE freettcn::
        CONFIGURATIONS Release)

add_subdirectory(doc)
