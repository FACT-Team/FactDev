cd ../tests
echo "#### COVERAGE ####"
lcov --capture --directory ../src --output-file coverage.info >> /dev/null
lcov -r coverage.info ~/Qt5.2.0/5.2.0/gcc_64/\* /usr/include/\* /home/travis/build/FACT-Team/FactDev/src/gui/\* /home/travis/build/FACT-Team/FactDev/src/moc_\* /home/travis/build/FACT-Team/FactDev/src/ui_\* /home/travis/build/FACT-Team/FactDev/src/qrc_\* /home/travis/build/FACT-Team/FactDev/src/mainwindow.\* /home/travis/build/FACT-Team/FactDev/src/\*.h -o coverage.info | tail -n3
coveralls-lcov coverage.info >> /dev/null

