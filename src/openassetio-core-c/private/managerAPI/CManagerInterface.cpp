// SPDX-License-Identifier: Apache-2.0
// Copyright 2013-2022 The Foundry Visionmongers Ltd

#include <stdexcept>

#include "CManagerInterfaceAdapter.hpp"

#include "../errors.hpp"
#include "../handles/InfoDictionary.hpp"

namespace openassetio {
inline namespace OPENASSETIO_VERSION {
namespace managerAPI {

constexpr size_t kStringBufferSize = 500;

CManagerInterfaceAdapter::CManagerInterfaceAdapter(OPENASSETIO_NS(managerAPI_CManagerInterface_h)
                                                       handle,
                                                   OPENASSETIO_NS(managerAPI_CManagerInterface_s)
                                                       suite)
    : handle_{handle}, suite_{suite} {}

CManagerInterfaceAdapter::~CManagerInterfaceAdapter() { suite_.dtor(handle_); }

Str CManagerInterfaceAdapter::identifier() const {
  // Buffer for error message.
  char errorMessageBuffer[kStringBufferSize];
  // Error message.
  OPENASSETIO_NS(StringView)
  errorMessage{kStringBufferSize, errorMessageBuffer, 0};

  // Return value string buffer.
  char outBuffer[kStringBufferSize];
  // Return value.
  OPENASSETIO_NS(StringView) out{kStringBufferSize, outBuffer, 0};

  // Execute corresponding suite function.
  const OPENASSETIO_NS(ErrorCode) errorCode = suite_.identifier(&errorMessage, &out, handle_);

  // Convert error code/message to exception.
  errors::throwIfError(errorCode, errorMessage);

  return {out.data, out.size};
}

Str CManagerInterfaceAdapter::displayName() const {
  // Buffer for error message.
  char errorMessageBuffer[kStringBufferSize];
  // Error message.
  OPENASSETIO_NS(StringView)
  errorMessage{kStringBufferSize, errorMessageBuffer, 0};

  // Return value string buffer.
  char outBuffer[kStringBufferSize];
  // Return value.
  OPENASSETIO_NS(StringView) out{kStringBufferSize, outBuffer, 0};

  // Execute corresponding suite function.
  const OPENASSETIO_NS(ErrorCode) errorCode = suite_.displayName(&errorMessage, &out, handle_);

  // Convert error code/message to exception.
  errors::throwIfError(errorCode, errorMessage);

  return {out.data, out.size};
}

InfoDictionary CManagerInterfaceAdapter::info() const {
  // Buffer for error message.
  char errorMessageBuffer[kStringBufferSize];
  // Error message.
  OPENASSETIO_NS(StringView)
  errorMessage{kStringBufferSize, errorMessageBuffer, 0};

  // Return value.
  InfoDictionary infoDict{};
  OPENASSETIO_NS(InfoDictionary_h) infoDictHandle = handles::InfoDictionary::toHandle(&infoDict);

  // Execute corresponding suite function.
  const OPENASSETIO_NS(ErrorCode) errorCode = suite_.info(&errorMessage, infoDictHandle, handle_);

  // Convert error code/message to exception.
  errors::throwIfError(errorCode, errorMessage);

  return infoDict;
}
}  // namespace managerAPI
}  // namespace OPENASSETIO_VERSION
}  // namespace openassetio
