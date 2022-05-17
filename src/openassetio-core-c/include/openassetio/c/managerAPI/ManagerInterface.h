// SPDX-License-Identifier: Apache-2.0
// Copyright 2013-2022 The Foundry Visionmongers Ltd
#pragma once

#include "../namespace.h"

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @addtogroup CAPI C API
 * @{
 */

/**
 * Opaque handle type representing a @fqref{managerAPI::ManagerInterface}
 * "ManagerInterface" instance.
 */
// NOLINTNEXTLINE(modernize-use-using)
typedef struct OPENASSETIO_NS(managerAPI_SharedManagerInterface_t) *
    OPENASSETIO_NS(managerAPI_SharedManagerInterface_h);

/**
 * @}
 */
#ifdef __cplusplus
}
#endif
