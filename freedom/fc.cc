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

#include <iostream>
#include <memory>
#include <ostream>
#include <goose/goose.h>
#include  <freedom/freedom_extension.h>
#include <string>

int main(int argc, char **argv) {
    std::string fstr = "Kumo";
    if (argc > 1) {
        fstr = argv[1];
    }
    auto rs = goose::enable_extension_autoload("freedom", [](goose::Goose &db) {
        db.LoadStaticExtension<goose::FreedomExtension>();
        return goose::ExtensionLoadResult::LOADED_EXTENSION;
    });
    if (!rs.ok()) {
        std::cerr << rs.message() << std::endl;
        return 1;
    }

    goose::Goose db(nullptr);

    goose::Connection con(db);

    std::string query = "select freedom('" + fstr + "')";
    auto result = con.Query(query);
    result->Print();
    return 0;
}
