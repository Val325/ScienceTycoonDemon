file(REMOVE_RECURSE
  "bin/libjson.dll"
  "bin/libjson.dll.manifest"
  "bin/libjson.pdb"
  "lib/libjson.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/json.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
