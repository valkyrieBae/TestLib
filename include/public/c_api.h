#ifndef ANALYTICS_MOBILE_CONSOLE_MEASUREMENT_PUBLIC_C_API_H_
#define ANALYTICS_MOBILE_CONSOLE_MEASUREMENT_PUBLIC_C_API_H_

#include <stdint.h>
#if defined(_WIN32)
#ifdef ANALYTICS_DLL
#define ANALYTICS_API __declspec(dllexport)
#else
#define ANALYTICS_API __declspec(dllimport)
#endif
#else
#define ANALYTICS_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

namespace goog::poc {

typedef struct ItemParamOpaque ItemParam;

ANALYTICS_API int TestMain();

ANALYTICS_API ItemParam* ItemParamCreate();

ANALYTICS_API void ItemParamDestroy(ItemParam* item_param);

ANALYTICS_API void ItemParamAddString(ItemParam* item_param, const char* name,
                                      const char* value);

ANALYTICS_API void ItemParamAddInt(ItemParam* item_param, const char* name,
                                   int64_t value);

ANALYTICS_API void ItemParamAddDouble(ItemParam* item_param, const char* name,
                                      double value);

ANALYTICS_API int64_t InsertEvent(ItemParam* item_param);

}  // namespace goog::poc

#ifdef __cplusplus
}
#endif

#endif  // ANALYTICS_MOBILE_CONSOLE_MEASUREMENT_PUBLIC_C_API_H_
