# get IDF version for comparison
set(idf_version "${IDF_VERSION_MAJOR}.${IDF_VERSION_MINOR}")

idf_build_get_property(target IDF_TARGET)

# set sources
set(srcs
  src/mp3_file.cpp
  src/pdm_sound_player.cpp
)

set(include_dirs
  inc
)

set(requires
    driver
)

idf_component_register(
  SRCS ${srcs}
  INCLUDE_DIRS ${include_dirs}
  REQUIRES ${requires}
)
