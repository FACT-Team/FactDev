cd ../fact-team.github.io/
echo "#### GENERATE DOXYGEN ####"
git checkout master
cd ..
make clean && rm ui_*
doxygen >> /dev/null 2> fact-team.github.io/doc/doxygen.log
cd fact-team.github.io/doc/latex
echo "#### COMPILATION OF LATEX DOXYGEN####"
#make -j9 
cd ..
git add . >> /dev/null
git commit -a -m "[Travis] Generate Doxygen" >> /dev/null
