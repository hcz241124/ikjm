#ifndef HCZ_IKJM_CAPI_API_H
#define HCZ_IKJM_CAPI_API_H

#if defined(IKJM4C_EXPORT_API)
#if defined(WINDOWS_BUILD)
#define IKJM4C_API __declspec( dllexport )

#elif defined(MACOS_BUILD) 
#define IKJM4C_API __attribute__ ((visibility ("default")))

#else
#define IKJM4C_API 

#endif

#else

#if defined(WINDOWS_BUILD)
#define IKJM4C_API __declspec( dllimport )

#elif defined(MACOS_BUILD) 
#define IKJM4C_API 

#else
#define IKJM4C_API 

#endif

#endif
#endif // HCZ_IKJM_CAPI_API_H
