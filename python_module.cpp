#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include <sstream>
#include <SO3.h>
#include <SE3.h>
#include <ceres-factors/Parameterizations.h>
#include <ceres-factors/Factors.h>

using namespace Eigen;
namespace py = pybind11;

PYBIND11_MODULE(PyCeresFactors, m)
{
    m.doc() = "Python binding module for custom Ceres factors.";

    // SO3 Factors
    m.def("SO3Parameterization", &SO3Parameterization::Create);
    m.def("SO3Factor", &SO3Factor::Create);

    // SE3 Factors
    m.def("SE3Parameterization", &SE3Parameterization::Create);
    m.def("RelSE3Factor", &RelSE3Factor::Create);
    m.def("SE3ReprojectionFactor",&SE3ReprojectionFactor::Create);

    // Specific Sensor Factors
    m.def("RangeFactor", &RangeFactor::Create);
    m.def("AltFactor", &AltFactor::Create);

    // Calibration Factors
    m.def("TimeSyncAttFactor", &TimeSyncAttFactor::Create);
    m.def("SO3OffsetFactor", &SO3OffsetFactor::Create);
    m.def("SE3OffsetFactor", &SE3OffsetFactor::Create);
}
