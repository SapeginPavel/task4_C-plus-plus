# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\task4_f_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\task4_f_autogen.dir\\ParseCache.txt"
  "task4_f_autogen"
  )
endif()
