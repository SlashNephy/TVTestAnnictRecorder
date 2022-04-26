use std::cell::Cell;
use std::sync::atomic::{AtomicI32, Ordering};
use tvtest::enumflags2::BitFlag;
use tvtest::api::PluginApi;
use tvtest::{export_plugin, TVTestEventHandler, TVTestPlugin};
use tvtest::plugin::{PluginFlag, PluginInfo, PluginKind};
use tvtest::version::{DEFAULT_API_VERSION, Version};
use tvtest::win32::{IntoRustString, UnsafeIntoRustString, WideStringPtr};

pub struct AnnictRecorderPlugin {
    api: PluginApi,
}

impl TVTestPlugin for AnnictRecorderPlugin {
    fn new(api: PluginApi) -> Self {
        AnnictRecorderPlugin {
            api,
        }
    }

    fn get_api_version() -> Version {
        DEFAULT_API_VERSION
    }

    fn get_info() -> PluginInfo {
        PluginInfo {
            kind: PluginKind::Normal,
            flags: PluginFlag::empty(),
            name: "Example".into(),
            copyright: "© 2021 @SlashNephy <spica@starry.blue>".into(),
            description: "TVTestSDK-rs のサンプルプラグイン".into(),
        }
    }

    fn initialize(&self) -> bool {
        true
    }

    fn finalize(&self) -> bool {
        true
    }
}

impl TVTestEventHandler for AnnictRecorderPlugin {
}

export_plugin!(AnnictRecorderPlugin);
