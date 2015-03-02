#!/bin/bash
# -*- coding: UTF8 -*-

qt_path="/opt/Qt/5.3/gcc_64"
make_path="make"
build_path="/home/aroquemaurel/projets/qt/build-factdev-release"
repo_path="/home/aroquemaurel/projets/qt/FactDev"

nb_process=3

#mkdir $build_path
cd "$build_path"
eval "$qt_path/bin/qmake $repo_path/FactDev.pro -r -spec linux-g++"

