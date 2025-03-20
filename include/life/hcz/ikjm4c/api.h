#ifndef LIFE_HCZ_IKJM4C_API_H_
#define LIFE_HCZ_IKJM4C_API_H_

// clang-format off
#if defined(IKJM4C_EXPORT_API)
#   if defined(_MSC_VER) // MSVC
#       define IKJM4C_API __declspec(dllexport)
#   elif defined(__MINGW32__) || defined(__MINGW64__) // MinGW
#       define IKJM4C_API __declspec(dllexport)
#   elif defined(__clang__) // Clang on macOS or Linux
#       define IKJM4C_API __attribute__ ((visibility ("default")))
#   elif defined(__GNUC__) // GCC on Linux
#       define IKJM4C_API __attribute__((visibility("default")))
#   else
#       define IKJM4C_API 
#   endif
#else
#   if defined(_MSC_VER) // MSVC
#       define IKJM4C_API __declspec(dllimport)
#   elif defined(__MINGW32__) || defined(__MINGW64__) // MinGW
#       define IKJM4C_API __declspec(dllimport)
#   elif defined(__clang__) // Clang on macOS or Linux
#       define IKJM4C_API
#   elif defined(__GNUC__) // GCC on Linux
#       define IKJM4C_API
#   else
#       define IKJM4C_API 
#   endif
#endif

#if defined(_MSC_VER) // MSVC
#   define IKJM4C_INNER
#elif defined(__MINGW32__) || defined(__MINGW64__) // MinGW
#   define IKJM4C_INNER
#elif defined(__clang__) // Clang on macOS
#   define IKJM4C_INNER __attribute__((visibility("hidden")))
#elif defined(__GNUC__) // GCC on Linux
#   define IKJM4C_INNER __attribute__((visibility("hidden")))
#else
#   define IKJM4C_INNER __attribute__((visibility("hidden")))
#endif
// clang-format on

#endif // LIFE_HCZ_IKJM4C_API_H_
