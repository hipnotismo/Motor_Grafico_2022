#ifndef EXPORT_H

#ifdef ENGINE_EXPORT
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

#endif