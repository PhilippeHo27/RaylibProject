#!/bin/bash

press_to_continue()
{
  read -rsp $'Press any key to continue...\n' -n1 key # pause hack
}

setup_win_short_path()
{
  fsutil 8dot3name query
  echo "----------------------------------------------------------------"
  echo "If 8dot3name is disabled (set to 1) execute as admin the script:"
  echo " -> SetVisualStudioShortPath.bat"
  echo "----------------------------------------------------------------"

  #cmd '/c SetVisualStudioShortPath.bat'
}

setup_msbuild()
{
  VS_VERSION=2022
  VS_DISTRIBUTION=Community
  VS_SHORT_NAME=MICROS~4 # depend on SetVisualStudioShortPath.bat cmd

  # VCVARXX.bat name
  local d="$1" 
  VCVARXX_PATH="C:\PROGRA~1\\$VS_SHORT_NAME\\$VS_VERSION\\$VS_DISTRIBUTION\\VC\Auxiliary\Build\\$d.bat"
  if [ -z "$VCVARSXX" ]
  then
    echo "\$VCVARSXX set to $VCVARXX_PATH"
    export VCVARSXX=$VCVARXX_PATH
  else
    echo $VCVARSXX
  fi

  # Platform name
  local p="$2" 
  echo "\$MSBUILD_TARGET set to $p"
  export MSBUILD_TARGET=$p

  # Config name
  local c="$3" 
  echo "\$MSBUILD_CONFIG set to $c"
  export MSBUILD_CONFIG=$c

  # Compiler
  MSBUILD_PATH="/C/PROGRA~1/$VS_SHORT_NAME/$VS_VERSION/$VS_DISTRIBUTION/MSBuild/Current/Bin"
  NEW_PATH=$MSBUILD_PATH:$PATH
  export PATH=$NEW_PATH
  #printenv | grep --color "\bPATH\b" | tr ':' $'\n'
}

msbuild_project()
{
  local d="$1"
  [[ -z $d ]] && { echo "${FUNCNAME}(): vcvarXX.bat name not specified"; press_to_continue; exit 1; }

  local p="$2"
  [[ -z $p ]] && { echo "${FUNCNAME}(): platform (x64|Win32) not specified"; press_to_continue; exit 1; }

  local c="$3"
  [[ -z $c ]] && { echo "${FUNCNAME}(): configuration(Debug|Release) not specified"; press_to_continue; exit 1; }

  echo "1. Setup Environment"
  echo "--------------------" 
  setup_win_short_path
  setup_msbuild $d $p $c
  echo
  echo "2. launch build"
  echo "---------------" 
  pushd ../Build
      cmd '/c %VCVARSXX% && msbuild /p:Configuration=%MSBUILD_CONFIG% /p:Platform=%MSBUILD_TARGET% RaylibBasic.sln -fl -flp:logfile=RaylibBasic_MSBuild.log;verbosity=n'
  popd
}
