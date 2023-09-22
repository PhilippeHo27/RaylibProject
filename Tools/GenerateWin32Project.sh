echo "Cmake generate project"

TARGET_NAME="Build"

# v141 -> VS 2017
# v142 -> VS 2019
# v143 -> VS 2022
TARGET_IDE=v143

# Platform x64 or Win32
TARGET_PLATFORM=Win32

source ./Utils.sh

# Go to parent directory
cd ..

FIND_TARGET="$(find ./ -maxdepth 1 -type d  -name $TARGET_NAME | wc -l)"
echo "step 1  - find $TARGET_NAME folder"
if [ $FIND_TARGET -eq 0 ]; then
	mkdir $TARGET_NAME
	echo " -> $TARGET_NAME created"
else 
	echo " -> $TARGET_NAME already exist"
fi

echo "step 2 - clear $TARGET_NAME folder"
rm -Rf $TARGET_NAME/* >/dev/null 2>&1

if [ $? -ne 0 ]; then
	echo $?
 	echo "Cannot clear folder"
 	read -rsp $'Press any key to continue...\n' -n1 key # pause hack
	exit 1
else
	echo " -> $TARGET_NAME cleared"
fi

echo "step 3 - generate project in $TARGET_NAME folder"
pushd $TARGET_NAME/
	cmake -A $TARGET_PLATFORM -T $TARGET_IDE ../
popd
#make -b ./Build
press_to_continue