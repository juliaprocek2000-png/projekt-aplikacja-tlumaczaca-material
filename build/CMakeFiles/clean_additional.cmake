# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\RedaktorAI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\RedaktorAI_autogen.dir\\ParseCache.txt"
  "RedaktorAI_autogen"
  )
endif()
