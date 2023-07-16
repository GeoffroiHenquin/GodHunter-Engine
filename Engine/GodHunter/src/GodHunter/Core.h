#pragma once

#ifdef GH_PLATFORM_WINDOWS
# ifdef GH_BUILD_SHAREDLIB
#   define GODHUNTER_API  __declspec( dllexport )
# else
#   define GODHUNTER_API  __declspec( dllimport )
# endif
#else
# define GODHUNTER_API
#endif