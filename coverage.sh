#!/bin/bash
# -*- coding: UTF8 -*-

lcov --capture --directory ../src --output-file coverage.info
lcov -r coverage.info /opt/Qt/\* /usr/include/\* ~/projets/qt/FactDev/src/gui/\* ~/projets/qt/build-FactDev-Desktop_Qt_5_3_GCC_64bit-Debug/src/\* -o coverage.info 
echo `date` >> tests.log
genhtml coverage.info -o ../../FactDev/fact-team.github.io/out | tail -n3 > ../../FactDev/fact-team.github.io/coverage/logs/`date +"%Y-%m-%d"`.log
echo '' >> tests.log
echo '' >> tests.log
