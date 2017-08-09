#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "array" for configuration ""
set_property(TARGET array APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(array PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libarray.so"
  IMPORTED_NO_SONAME_NOCONFIG "TRUE"
  )

list(APPEND _IMPORT_CHECK_TARGETS array )
list(APPEND _IMPORT_CHECK_FILES_FOR_array "${_IMPORT_PREFIX}/lib/libarray.so" )

# Import target "projArunner" for configuration ""
set_property(TARGET projArunner APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(projArunner PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/projArunner"
  )

list(APPEND _IMPORT_CHECK_TARGETS projArunner )
list(APPEND _IMPORT_CHECK_FILES_FOR_projArunner "${_IMPORT_PREFIX}/bin/projArunner" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
