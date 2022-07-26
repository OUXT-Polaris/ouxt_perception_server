#ifndef PERCEPTION__VISIBILITY_CONTROL_H_
#define PERCEPTION__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define PERCEPTION_EXPORT __attribute__ ((dllexport))
    #define PERCEPTION_IMPORT __attribute__ ((dllimport))
  #else
    #define PERCEPTION_EXPORT __declspec(dllexport)
    #define PERCEPTION_IMPORT __declspec(dllimport)
  #endif
  #ifdef PERCEPTION_BUILDING_LIBRARY
    #define PERCEPTION_PUBLIC PERCEPTION_EXPORT
  #else
    #define PERCEPTION_PUBLIC PERCEPTION_IMPORT
  #endif
  #define PERCEPTION_PUBLIC_TYPE PERCEPTION_PUBLIC
  #define PERCEPTION_LOCAL
#else
  #define PERCEPTION_EXPORT __attribute__ ((visibility("default")))
  #define PERCEPTION_IMPORT
  #if __GNUC__ >= 4
    #define PERCEPTION_PUBLIC __attribute__ ((visibility("default")))
    #define PERCEPTION_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define PERCEPTION_PUBLIC
    #define PERCEPTION_LOCAL
  #endif
  #define PERCEPTION_PUBLIC_TYPE
#endif

#endif  // PERCEPTION__VISIBILITY_CONTROL_H_
