/*
 * SPDX-FileCopyrightText: Copyright (c) 2023-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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

#ifndef INCLUDE_HOLOSCAN_OPERATORS_HOLOVIZ_BUFFER_INFO_HPP
#define INCLUDE_HOLOSCAN_OPERATORS_HOLOVIZ_BUFFER_INFO_HPP

#include <string>

#include <holoviz/image_format.hpp>
#include "holoscan/operators/holoviz/holoviz.hpp"

#include "gxf/multimedia/video.hpp"

namespace holoscan::ops {

/// Buffer information, can be initialized either with a tensor or a video buffer
struct BufferInfo {
  /**
   * Initialize with tensor
   *
   * @param tensor
   * @param input_image_format if HolovizOp::ImageFormat::AUTO_DETECT then auto detect the image
   * format, else use the provided image format
   *
   * @return error code
   */
  gxf_result_t init(
      const nvidia::gxf::Handle<nvidia::gxf::Tensor>& tensor,
      HolovizOp::ImageFormat input_image_format = HolovizOp::ImageFormat::AUTO_DETECT);

  /**
   * Initialize with video buffer
   *
   * @param tensor
   * @param input_image_format if HolovizOp::ImageFormat::AUTO_DETECT then auto detect the image
   * format, else use the provided image format
   *
   * @return error code
   */
  gxf_result_t init(
      const nvidia::gxf::Handle<nvidia::gxf::VideoBuffer>& video,
      HolovizOp::ImageFormat input_image_format = HolovizOp::ImageFormat::AUTO_DETECT);

  uint32_t rank = 0;
  uint32_t components = 0;
  uint32_t width = 0;
  uint32_t height = 0;
  nvidia::gxf::PrimitiveType element_type = nvidia::gxf::PrimitiveType::kCustom;
  bool image_format_supported = false;
  HolovizOp::ImageFormat image_format = HolovizOp::ImageFormat::AUTO_DETECT;
  viz::ComponentSwizzle component_swizzle[4] = {viz::ComponentSwizzle::IDENTITY,
                                                 viz::ComponentSwizzle::IDENTITY,
                                                 viz::ComponentSwizzle::IDENTITY,
                                                 viz::ComponentSwizzle::IDENTITY};
  std::string name;
  /// points to the memory owned by either a tensor or video buffer
  const nvidia::byte* buffer_ptr = nullptr;
  nvidia::gxf::MemoryStorageType storage_type = nvidia::gxf::MemoryStorageType::kHost;
  uint64_t bytes_size = 0;
  nvidia::gxf::Tensor::stride_array_t stride{};
};

}  // namespace holoscan::ops

#endif /* INCLUDE_HOLOSCAN_OPERATORS_HOLOVIZ_BUFFER_INFO_HPP */
