file(REMOVE_RECURSE
  "bin/libraylib.dll"
  "bin/libraylib.dll.manifest"
  "bin/libraylib.pdb"
  "lib/libraylib.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/raylib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
