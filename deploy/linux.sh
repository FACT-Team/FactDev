#!/bin/bash
# -*- coding: UTF8 -*-

#### CONFIGURATION ####
qt_path="/opt/Qt/5.3/gcc_64"
make_path="make"
build_path="/home/aroquemaurel/projets/qt/build-factdev-release"
repo_path="/home/aroquemaurel/projets/qt/FactDev"
nb_process=3


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
eval "$qt_path/bin/qmake $repo_path/FactDev.pro -config release -r -spec linux-g++"

echo "--- Make clean ---"
eval "$make_path clean" #Just in case…

# Make 
echo "--- Make ---"
eval "$make_path -j$nb_process"

#### Copy files ####
echo "### Copy files and lib"

# Internal files
echo "--- Copy FactDev library ---"
eval "cp $build_path/src/*.so.* $build_path/app"
eval "cp $repo_path/deploy/FactDev.sh $build_path/app"
eval "chmod +x $build_path/app/FactDev.sh"
eval "cp -r $repo_path/src/sql $build_path/app"

# Qt library
echo "--- copy Qt libraries ---"
copy_Qt_lib libicuuc
copy_Qt_lib libicui18n
copy_Qt_lib libicudata
copy_Qt_lib libQt5Core
copy_Qt_lib libQt5Gui
copy_Qt_lib libQt5PrintSupport
copy_Qt_lib libQt5Sql
copy_Qt_lib libQt5Widgets
copy_Qt_lib libQt5DBus 

copy_Qt_plugin imageformats
copy_Qt_plugin platforms
copy_Qt_plugin sqldrivers
copy_Qt_plugin printsupport

eval "rm $build_path/app/*prl"
eval "rm $build_path/app/*la"

#### CREATE TARBALL ####
echo "--- Create FactDev tarball FactDev.tar.gz ---"
eval "cd $build_path/"
mv app FactDev
tar -czvf FactDev.tar.gz FactDev 
