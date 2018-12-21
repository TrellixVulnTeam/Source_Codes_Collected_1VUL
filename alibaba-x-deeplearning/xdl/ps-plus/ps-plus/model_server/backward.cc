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

#include "ps-plus/model_server/backward.h"

#include <vector>
#include <string>

namespace ps {
namespace modelserver {

Status BackwardCache::Get(BackwardRun factory, const std::string& spec, std::unique_ptr<BackwardCache>* cache) {
  std::unordered_map<std::string, std::string> map = StringUtils::ParseMap(spec);
  cache->reset(GetPlugin<BackwardRegistry>(map["name"])->Create());
  return cache->get()->Init(factory, map);
}

}
}
