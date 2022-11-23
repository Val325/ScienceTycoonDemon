# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "D:/Program/raylib/Sourse;D:/Program/raylib/Sourse/bin")
set(CPACK_CMAKE_GENERATOR "MinGW Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "D:/Program/CMake/share/cmake-3.25/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "Mygame built using CMake")
set(CPACK_DMG_SLA_USE_RESOURCE_FILE_LICENSE "ON")
set(CPACK_GENERATOR "ZIP;TGZ")
set(CPACK_INSTALL_CMAKE_PROJECTS "D:/Program/raylib/Sourse/bin;Mygame;ALL;/")
set(CPACK_INSTALL_PREFIX "C:/Program Files (x86)/Mygame")
set(CPACK_MODULE_PATH "D:/Program/raylib/Sourse/raylib/cmake")
set(CPACK_NSIS_DISPLAY_NAME "raylib 4.2.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
set(CPACK_NSIS_PACKAGE_NAME "raylib 4.2.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "D:/Program/gcc/bin/objcopy.exe")
set(CPACK_OBJDUMP_EXECUTABLE "D:/Program/gcc/bin/objdump.exe")
set(CPACK_OUTPUT_CONFIG_FILE "D:/Program/raylib/Sourse/bin/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "D:/Program/raylib/Sourse/raylib/src/../README.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Simple and easy-to-use library to enjoy videogames programming")
set(CPACK_PACKAGE_FILE_NAME "raylib-4.2.0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "raylib 4.2.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "raylib 4.2.0")
set(CPACK_PACKAGE_NAME "raylib")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Humanity")
set(CPACK_PACKAGE_VERSION "4.2.0")
set(CPACK_PACKAGE_VERSION_MAJOR "")
set(CPACK_PACKAGE_VERSION_MINOR "")
set(CPACK_PACKAGE_VERSION_PATCH "")
set(CPACK_READELF_EXECUTABLE "D:/Program/gcc/bin/readelf.exe")
set(CPACK_RESOURCE_FILE_LICENSE "D:/Program/raylib/Sourse/raylib/src/../LICENSE")
set(CPACK_RESOURCE_FILE_README "D:/Program/CMake/share/cmake-3.25/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "D:/Program/raylib/Sourse/raylib/src/../README.md")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "ON")
set(CPACK_SOURCE_GENERATOR "7Z;ZIP")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "D:/Program/raylib/Sourse/bin/CPackSourceConfig.cmake")
set(CPACK_SOURCE_ZIP "ON")
set(CPACK_SYSTEM_NAME "win64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "win64")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "D:/Program/raylib/Sourse/bin/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
