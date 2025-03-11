
#[derive(Debug, PartialEq)] // 自动派生 `Debug` 和 `PartialEq`
pub struct Version {
    pub major: u16,
    pub minor: u16,
    pub patch: u16,
    pub pre_version: Option<u8>, // pre_version 作为 u8
    pub build: Option<u8>,       // build 也作为 u8
}

impl Version {
    fn from_cargo_version() -> Self {
        let version_str = env!("CARGO_PKG_VERSION");

        let parts: Vec<&str> = version_str.split('+').collect();
        let version_parts = parts[0].split('-').collect::<Vec<&str>>();

        // 解析 MAJOR.MINOR.PATCH
        let version_numbers: Vec<u16> = version_parts[0]
            .split('.')
            .filter_map(|s| s.parse::<u16>().ok())
            .collect();

        let major = *version_numbers.get(0).unwrap_or(&0);
        let minor = *version_numbers.get(1).unwrap_or(&0);
        let patch = *version_numbers.get(2).unwrap_or(&0);

        // 解析预版本信息
        let pre_version = if version_parts.len() > 1 {
            match version_parts[1] {
                "alpha" => Some(0xA),
                "beta" => Some(0xB),
                "final" => Some(0xF),
                _ => None, // 如果是其他值，则返回 None
            }
        } else {
            None
        };

        // 解析构建元数据
        let build = if parts.len() > 1 {
            parts[1].parse::<u8>().ok() // 尝试将构建元数据解析为 u8
        } else {
            None
        };

        Version {
            major,
            minor,
            patch,
            pre_version,
            build,
        }
    }

    fn display(&self) -> String {
        let name: &str = env!("CARGO_PKG_NAME");
        format!("{} Version: {}.{}.{} (PreVersion: {:X} BuildNumber: {})", name, self.major, self.minor, self.patch, self.pre_version.unwrap_or(0x0), self.build.unwrap_or(0x0))
    }
}

pub fn get_version() -> Version {
    Version::from_cargo_version()
}

fn cal_hexnumber_from_version(version: &Version) -> u64 {
    // 将版本号的各个部分组合成一个64位整数
    // 使用位运算将每个部分放到合适的位置
    (version.major as u64) << 24
        | (version.minor as u64) << 16
        | (version.patch as u64) << 8
        | (version.pre_version.unwrap_or(0xA) as u64) << 4
        | (version.build.unwrap_or(0x0) as u64)
}

pub fn hexversion() -> u64 {
    let version = get_version();
    cal_hexnumber_from_version(&version)
}

pub fn version() -> String {
    Version::from_cargo_version().display()
}

mod test {
    use super::{cal_hexnumber_from_version, get_version, Version};

    #[test]
    fn compile_hexversion() {
        let version = Version {
            major: 0,
            minor: 1,
            patch: 0,
            pre_version:  Some(0xA),
            build: Some(1),
        };
        let hexversion = cal_hexnumber_from_version(&version);
        assert_eq!(hexversion, 0x000100A1);
    }

    #[test]
    fn equal_version() {
        let version = get_version();
        assert_eq!(
            version,
            Version {
                major: 0,
                minor: 1,
                patch: 0,
                pre_version: Some(0xA),
                build: Some(1)
            }
        );
    }
}
