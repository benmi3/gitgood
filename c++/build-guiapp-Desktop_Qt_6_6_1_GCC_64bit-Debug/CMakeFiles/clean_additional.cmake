# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/guiapp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/guiapp_autogen.dir/ParseCache.txt"
  "guiapp_autogen"
  )
endif()
