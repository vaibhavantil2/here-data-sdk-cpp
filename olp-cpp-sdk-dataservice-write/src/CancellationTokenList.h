/*
 * Copyright (C) 2019 HERE Europe B.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 * License-Filename: LICENSE
 */

#pragma once

#include <mutex>
#include <tuple>
#include <vector>

#include <olp/core/client/OlpClient.h>

namespace olp {
namespace dataservice {
namespace write {

class CancellationTokenList {
 public:
  void AddTask(int id, olp::client::CancellationToken token);
  void CancelAll();
  int GetNextId() const;
  void RemoveTask(int id);

 private:
  std::vector<int> GetTaskIdList() const;

  mutable std::mutex mut_;
  std::vector<std::tuple<int, olp::client::CancellationToken>> tokenList_;
};

}  // namespace write
}  // namespace dataservice
}  // namespace olp
