use pyo3::prelude::*;

use hcz::version::hexversion;
use hcz::version::version as py_version;

#[pyfunction]
fn version() -> PyResult<String> {
    Ok(py_version())
}

/// A Python module implemented in Rust.
#[pymodule]
fn pyhcz(m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add("hexversion", hexversion())?;
    m.add_function(wrap_pyfunction!(version, m)?)?;
    Ok(())
}
