file(GLOB_RECURSE libsrc *.h *.cpp *.hpp *.inl *.c *.cc *.m)

add_custom_target (common SOURCES ${libsrc})
