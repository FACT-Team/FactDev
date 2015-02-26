cd ../fact-team.github.io/
echo "#### GENERATE DOXYGEN ####"
git checkout master
cd ..
doxygen >> /dev/null 2> fact-team.github.io/doc/doxygen.log
cd fact-team.github.io/doc/latex
echo "#### COMPILATION OF LATEX DOXYGEN####"
make -j9 >> /dev/null 2> /dev/null
cd ..
git add . >> /dev/null
git commit -a -m "[Travis] Generate Doxygen" >> /dev/null
