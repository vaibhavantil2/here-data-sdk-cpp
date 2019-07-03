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

#include <chrono>
#include "ThreadSafeQueue.h"

namespace olp {
namespace dataservice {
namespace write {
using PartitionTimestampQueue =
    ThreadSafeQueue<std::chrono::system_clock::time_point>;

std::chrono::milliseconds CalculateTimeSinceOldestPartition(
    const PartitionTimestampQueue& queue);

void PushPartitionTimestamps(PartitionTimestampQueue& queue, size_t size);

}  // namespace write
}  // namespace dataservice
}  // namespace olp
