#include "trk.h"


int ots ()
{
//std::cout<< testing_VERSION_MINOR <<std::endl;

#ifdef USE_MYLIB
printf("trk v %d.%d",testing_VERSION_MAJOR,testing_VERSION_MINOR);
giolib();
#endif

}

