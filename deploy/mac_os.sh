#!/bin/sh

#### CONFIGURATION ####
qt_path="/Applications/Qt5.4.1/5.4/clang_64/"
make_path="make"
build_path="/Users/cedricrohaut/FACT-Team/build-factdev-release"
repo_path="/Users/cedricrohaut/FACT-Team/FactDev"
nb_process=7

#### UTILS FUNCTIONS ####
function copy_Qt_lib {
	eval "cp -v $qt_path/lib/$1.* $build_path/app/"
}

function copy_Qt_plugin {
	eval "cp -rv $qt_path/plugins/$1 $build_path/app/"
}

function mkdir_if_not_exists {
	if [ ! -d "$1" ]; then
		mkdir $1
	fi
}

mkdir_if_not_exists $build_path
cd "$build_path"

#### COMPILATION ####
echo "#### COMPILATION ####"

# QMake execution
echo "--- QMake execution ---"
eval "$qt_path/bin/qmake $repo_path/FactDev.pro -config release -r -spec macx-clang CONFIG+=x86_64" 

echo "--- Make clean ---"
#eval "$make_path clean" #Just in case…

# Make 
echo "--- Make ---"
eval "$make_path -j$nb_process"

#### Copy files ####
echo "### Copy files and lib"

# Internal files
echo "--- Copy FactDev library ---"
cd $build_path
cp -r src/*.dylib app/
cd app
eval "cd $build_path/app"
eval "cp $qt_path/bin/macdeployqt ." 
./macdeployqt app.app
cp libFactDev.1.dylib app.app/Contents/Frameworks/
./macdeployqt app.app
eval "cp -r $repo_path/src/sql app.app/Contents/MacOS"
mv app.app FactDev.app
eval "zip -r FactDev.zip FactDev.app"
