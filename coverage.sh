#!/bin/bash
# -*- coding: UTF8 -*-
. ./coverage.cfg

lcov --capture --directory ../src --output-file coverage.info
lcov -r coverage.info $qtFolder/\* /usr/include/\* $projectFolder/src/gui/\* $buildFolder/src/\* -o coverage.info 
genhtml coverage.info -o $projectFolder/fact-team.github.io/coverage | tail -n3 > $projectFolder/FactDev/fact-team.github.io/coverage/logs/`date +"%Y-%m-%d"`.log
