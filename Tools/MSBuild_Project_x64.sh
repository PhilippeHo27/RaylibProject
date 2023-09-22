#!/bin/bash
source ./Utils.sh

PROJECT_NAME=RaylibBasic

msbuild_project vcvars64 x64 Release

press_to_continue
