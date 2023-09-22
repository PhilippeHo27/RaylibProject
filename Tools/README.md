# RaylibProjBasic
## Generate Solution
### Prerequisite
    1. Install MSYS terminal toolkit -> https://www.msys2.org/
    2. Install latest CMake version -> https://cmake.org/download/  

### Generate project
* Execute **GenerateWin32Project** (32 bit) or **GenerateX64Project** (64 bit) in a MSYS or MINGW terminal
* Open generated solution in Build directory

## Build Solution
### Prerequisite
* Project need to be generated with GenerateWin32Project (32 bit) or GenerateX64Project (64 bit) in a MSYS or MINGW terminal
### Build
* Execute **MSBuild_Project_Win32.sh** (for 32 bit project) or **MSBuild_Project_x64.sh** (for 64 bit project) in a MSYS or MINGW terminal
