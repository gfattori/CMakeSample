add_library(giolib SHARED giolib.cpp)

install (TARGETS giolib DESTINATION bin)
install (FILES giolib.h DESTINATION include)
