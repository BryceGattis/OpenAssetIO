// SPDX-License-Identifier: Apache-2.0
// Copyright 2013-2022 The Foundry Visionmongers Ltd
#include <pybind11/stl.h>

#include <openassetio/managerAPI/Host.hpp>

#include "../_openassetio.hpp"

void registerHost(const py::module& mod) {
  using openassetio::hostAPI::HostInterfacePtr;
  using openassetio::managerAPI::Host;
  using openassetio::managerAPI::HostPtr;

  py::class_<Host, HostPtr>(mod, "Host", py::is_final())
      .def(py::init<HostInterfacePtr>(), py::arg("hostInterface").none(false))
      .def("identifier", &Host::identifier)
      .def("displayName", &Host::displayName)
      .def("info", &Host::info);
}