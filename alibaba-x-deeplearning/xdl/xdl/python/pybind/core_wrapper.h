/* Copyright (C) 2016-2018 Alibaba Group Holding Limited

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef XDL_PYTHON_LIB_CORE_WRAPPER_H_
#define XDL_PYTHON_LIB_CORE_WRAPPER_H_

#include "pybind11/pybind11.h"

#include <string>

namespace xdl {
namespace python_lib {

void CorePybind(pybind11::module& m);

}  // namespace python_lib
}  // namespace xdl

#endif  // XDL_PYTHON_LIB_CORE_WRAPPER_H_

