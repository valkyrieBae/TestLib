#ifndef ANALYTICS_MOBILE_CONSOLE_MEASUREMENT_PUBLIC_C_PLUSPLUS_API_H_
#define ANALYTICS_MOBILE_CONSOLE_MEASUREMENT_PUBLIC_C_PLUSPLUS_API_H_

#include <cstdint>
#include <string>
#include <unordered_map>
#include <variant>

#include "c_api.h"

namespace goog::poc {

class PlusClient {
 public:
  using PrimitiveParameter = std::variant<int64_t, double, std::string>;
  using ItemParameter = std::unordered_map<std::string, PrimitiveParameter>;

  int64_t PlusInsertEvent(const ItemParameter& item_parameter) {
    ItemParam* item_param = ItemParamCreate();
    for (const auto& [name, value] : item_parameter) {
      if (std::holds_alternative<int64_t>(value)) {
        ItemParamAddInt(item_param, name.c_str(), std::get<int64_t>(value));
      } else if (std::holds_alternative<double>(value)) {
        ItemParamAddDouble(item_param, name.c_str(), std::get<double>(value));
      } else if (std::holds_alternative<std::string>(value)) {
        ItemParamAddString(item_param, name.c_str(),
                           std::get<std::string>(value).c_str());
      }
    }
    int64_t return_val = InsertEvent(item_param);
    ItemParamDestroy(item_param);
    return return_val;
  }
};
}  // namespace goog::poc

#endif  // ANALYTICS_MOBILE_CONSOLE_MEASUREMENT_PUBLIC_C_PLUSPLUS_API_H_
