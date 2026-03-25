# Copyright (C) Kumo inc. and its affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
###########################################################################
# below are examples, after initialization, modify it to your own.
###########################################################################
###kmcmake_example

goose_cc_extension(
        NAMESPACE ${PROJECT_NAME}
        NAME freedom
        SOURCES
        freedom_extension.cc
        DEPS
        goose_platform
        ABI_TYPE
        "CPP"
        CXXOPTS
        ${KMCMAKE_CXX_OPTIONS}
        PLINKS
        ${KMCMAKE_DEPS_LINK}
        PUBLIC
)

kmcmake_cc_binary(
        NAMESPACE ${PROJECT_NAME}
        NAME freedom
        SOURCES
        shell.cc
        CXXOPTS
        ${KMCMAKE_CXX_OPTIONS}
        LINKS
        goose::goose_shell_static
        goose::goose_static
        freedom::goose_freedom
        goose::autocomplete_static
        ${KMCMAKE_DEPS_LINK}
        LINKOPTS
        ${KMCMAKE_STATIC_BIN_OPTION}
)

kmcmake_cc_binary(
        NAMESPACE ${PROJECT_NAME}
        NAME fc
        SOURCES
        fc.cc
        CXXOPTS
        ${KMCMAKE_CXX_OPTIONS}
        LINKS
        goose::goose_static
        freedom::goose_freedom
        ${KMCMAKE_DEPS_LINK}
        LINKOPTS
        ${KMCMAKE_STATIC_BIN_OPTION}
)


###kmcmake_example