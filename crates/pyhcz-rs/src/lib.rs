use pyo3::prelude::*;
use pyo3::wrap_pymodule;
use pyo3::types::PyDict;

mod py_version;


/// A Python module implemented in Rust.
#[pymodule]
fn pyhcz(py: Python<'_>, m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add_wrapped(wrap_pymodule!(py_version::core))?;


    // Inserting to sys.modules allows importing submodules nicely from Python
    // e.g. from maturin_starter.submodule import SubmoduleClass

    let sys = PyModule::import(py, "sys")?;
    let sys_modules: Bound<'_, PyDict> = sys.getattr("modules")?.downcast_into()?;
    sys_modules.set_item("pyhcz.core", m.getattr("core")?)?;

    Ok(())
}
