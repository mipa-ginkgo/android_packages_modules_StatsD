/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "PullResultReceiver.h"

using namespace android::binder;
using namespace android::util;
using namespace std;

namespace android {
namespace os {
namespace statsd {

PullResultReceiver::PullResultReceiver(
        std::function<void(int32_t, bool, const vector<android::util::StatsEvent>&)> pullFinishCb)
    : pullFinishCallback(std::move(pullFinishCb)) {
}

Status PullResultReceiver::pullFinished(int32_t atomTag, bool success,
                                        const vector<StatsEvent>& output) {
    pullFinishCallback(atomTag, success, output);
    return Status::ok();
}

PullResultReceiver::~PullResultReceiver() {
}

}  // namespace statsd
}  // namespace os
}  // namespace android