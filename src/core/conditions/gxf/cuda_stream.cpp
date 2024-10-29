/*
 * SPDX-FileCopyrightText: Copyright (c) 2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "holoscan/core/conditions/gxf/cuda_stream.hpp"

#include <string>

#include "holoscan/core/component_spec.hpp"

namespace holoscan {

CudaStreamCondition::CudaStreamCondition(const std::string& name,
                                         nvidia::gxf::CudaStreamSchedulingTerm* term)
    : GXFCondition(name, term) {}

nvidia::gxf::CudaStreamSchedulingTerm* CudaStreamCondition::get() const {
  return static_cast<nvidia::gxf::CudaStreamSchedulingTerm*>(gxf_cptr_);
}

void CudaStreamCondition::setup(ComponentSpec& spec) {
  spec.param(receiver_,
             "receiver",
             "Queue channel",
             "The receiver on which data will be available oncethe stream completes.");
}

}  // namespace holoscan
