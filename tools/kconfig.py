#!/usr/bin/env python3
############################################################################
# tools/kconfig.py
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
############################################################################

import argparse
import os

try:
    from kconfiglib import Kconfig
    from menuconfig import menuconfig
except ModuleNotFoundError:
    print("Please execute the following command to install dependencies:")
    print("sudo apt install python3-kconfiglib")
    exit()

def merge_configs(args):
    kconf = Kconfig(args.input, suppress_traceback=True)

    kconf.warn_assign_undef = True
    kconf.warn_assign_override = True
    kconf.warn_assign_redun = True

    if args.menuconfig:
        menuconfig(kconf)

    if os.path.exists(args.output):
        kconf.load_config(args.output, replace=False)

    # generate .config file
    res = kconf.write_config(filename=args.output, save_old=False)
    print(f".config result: {res}")

    # kconf.write_config(args.output)
    # generate C header file
    if args.output_c_header != None:
        res = kconf.write_autoconf(args.output_c_header)
        print(f"c header result: {res}")


if __name__ == "__main__":

    # Kconfig file, and output file 
    ProjectPath = os.environ.get("PROJECT_PATH")

    if ProjectPath is None:
        ProjectPath = "."

    parser = argparse.ArgumentParser(description="Collect the Kconfig file to generate .config file and  C header file")

    parser.add_argument(
        "-o", "--output", required=False, default=os.path.join(ProjectPath, ".config"), help="Output configuration file"
    )

    parser.add_argument(
        "-i", "--input", required=False, default=os.path.join(ProjectPath, "Kconfig"), help="Input Kconfig configuration files"
    )

    parser.add_argument(
        "-O", "--output_c_header", required=False, default=None, help="Output C header file"
    )

    parser.add_argument(
        "-m", "--menuconfig", required=False, default=False, action="store_true", help="Run menuconfig"
    )
    args = parser.parse_args()

    merge_configs(args)
