#pragma once

#ifdef _WIN32
# ifdef BUILD_SHAREDLIB
#   define GODHUNTER_API  __declspec( dllexport )
# else
#   define GODHUNTER_API  __declspec( dllimport )
# endif
#else
# define GODHUNTER_API
#endif