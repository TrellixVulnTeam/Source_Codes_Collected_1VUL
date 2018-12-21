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

#include "ps-plus/server/udf/simple_udf.h"
#include "ps-plus/server/slice.h"

namespace ps {
namespace server {
namespace udf {

class TransSlice : public SimpleUdf<Slices, TensorSlices*> {
 public:
  virtual Status SimpleRun(UdfContext* ctx, const Slices& slices, TensorSlices* result) const {
    result->slice_size = slices.slice_size;
    result->slice_id = slices.slice_id;
    result->dim_part = slices.dim_part;
    result->tensor = *(slices.variable->GetData());
    return Status::Ok();
  }
};

SIMPLE_UDF_REGISTER(TransSlice, TransSlice);

}
}
}

