use pyo3::prelude::*;

use hcz::version::hexversion;

/// Formats the sum of two numbers as string.
#[pyfunction]
fn sum_as_string(a: usize, b: usize) -> PyResult<String> {
    Ok((a + b).to_string())
}

/// A Python module implemented in Rust.
#[pymodule]
fn pyhcz(m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add("hexversion", hexversion())?;
    m.add_function(wrap_pyfunction!(sum_as_string, m)?)?;
    Ok(())
}
