// Copyright (C) 2026 Kumo inc. and its affiliates. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <goose/shell/shell.h>
#include <goose/goose.h>
#include <goose/extension/autocomplete/autocomplete_extension.h>
#include <goose/extension/httpfs/httpfs_extension.h>
#include  <freedom/freedom_extension.h>

namespace goose {
    /// user need impl this function
    void init_extensions() {
        goose::UserConfig::instance().alter_string = "FD";
        auto rs = enable_extension_autoload("autocomplete", [](Goose &db) {
            db.LoadStaticExtension<AutocompleteExtension>();
            return ExtensionLoadResult::LOADED_EXTENSION;
        });
        TURBO_UNUSED(rs);
        rs = enable_extension_autoload("freedom", [](Goose &db) {
            db.LoadStaticExtension<FreedomExtension>();
            return ExtensionLoadResult::LOADED_EXTENSION;
        });
        TURBO_UNUSED(rs);
    }
} // namespace goose
