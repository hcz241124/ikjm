use pyo3::prelude::*;

use hcz::version::get_version as py_get_version;
use hcz::version::hexversion;
use hcz::version::version as py_version;

#[pyfunction]
pub fn version() -> PyResult<String> {
    Ok(py_version())
}

/// Version code description
/// 
/// https://semver.org/lang/zh-CN/
#[pyclass]
#[derive(Debug, PartialEq)]
pub struct PyVersion {
    /// Interface broken update
    major: u16,
    /// Function update
    minor: u16,
    /// Bug fix
    patch: u16,
    /// Alpha | Beta | Final(Release)
    pre_version: u8,
    /// CI/CD build count
    build: u8,
}

#[pymethods]
impl PyVersion {
    #[getter]
    fn major(&self) -> u16 {
        self.major
    }

    #[getter]
    fn minor(&self) -> u16 {
        self.minor
    }

    #[getter]
    fn patch(&self) -> u16 {
        self.patch
    }

    #[getter]
    fn pre_version(&self) -> u8 {
        self.pre_version
    }

    #[getter]
    fn build(&self) -> u8 {
        self.build
    }

    /// 实现 __str__ 方法，使其返回人类可读的字符串表示
    pub fn __str__(&self) -> PyResult<String> {
        Ok(format!(
            "{}.{}.{}-{}+{}",
            self.major, self.minor, self.patch, self.pre_version, self.build
        ))
    }
}

#[pyfunction]
pub fn get_version() -> PyVersion {
    let ver = py_get_version();
    PyVersion {
        major: ver.major,
        minor: ver.minor,
        patch: ver.patch,
        pre_version: ver.pre_version.unwrap_or(0),
        build: ver.build.unwrap_or(0),
    }
}

#[pymodule]
pub fn core(m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add("hexversion", hexversion())?;
    m.add_function(wrap_pyfunction!(version, m)?)?;
    m.add_function(wrap_pyfunction!(get_version, m)?)?;
    m.add_class::<PyVersion>()?;
    Ok(())
}
