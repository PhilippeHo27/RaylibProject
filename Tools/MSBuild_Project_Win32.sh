#!/bin/bash
source ./Utils.sh

PROJECT_NAME=RaylibBasic

msbuild_project vcvars32 Win32 Debug

press_to_continue