#### CONFIGURATION ####
$qt_path = "C:\Qt\5.4\mingw491_32"
$mingw_path = "C:\Qt\Tools\mingw491_32"
$build_path = "C:\Documents and Settings\aroquemaurel\Documents"
$repo_path = "C:\Documents and Settings\aroquemaurel\Documents\FactDev"
$nb_process = 3



$make_path = $mingw_path + "\bin\mingw32-make.exe "
$qmake_path = $qt_path + "\bin\qmake.exe"
$make_nbprocess = "-j"+$nb_process

cd $build_path


#### COMPILATION ####
# Create build folder
mkdirIfNotExist build
cd build

# QMake execution
call  ($qmake_path + """" +$repo_path + "\FactDev.pro"" -r -spec win32-g++")

# Make clean, just in case
call ($make_path+" clean")

# Make of FactDev.dll
cd src
call ($make_path+ $make_nbprocess)

cp release/FactDev.dll . #Move FactDev.dll in write location
cd ../app
call ($make_path+ $make_nbprocess)

#### Copy dll files ####
cd release
# Copy plugins folders
copyPlugin "imageformats"
copyPlugin "platforms"
copyPlugin "sqldrivers"

# Copy dll 
copyQtDll "icudt53"
copyQtDll "icuin53"
copyQtDll "icuuc53"
copyQtDll "libgcc_s_dw2-1"
copyQtDll "libstdc++-6"
copyQtDll "libwinpthread-1"
copyQtDll "Qt5Concurrent"
copyQtDll "Qt5Core"
copyQtDll "Qt5Gui"
copyQtDll "Qt5PrintSupport"
copyQtDll "Qt5Sql"
copyQtDll "Qt5Widgets"

call ("cp ../FactDev.dll .") # Copy FactDev.dll




#C:\Qt\5.4\mingw491_32\plugins
#18:43:51: Débute : "C:\Qt\5.4\mingw491_32\bin\qmake.exe" C:\Users\Aroquemaurel\Documents\FactDev\FactDev.pro -r -spec win32-g++
# cd vers src
# make -j3
# copie de la lib factdev vers app/../src
# cd vers app
# make -j3
# Copie des fichiers sql vers app
# Copie des dll vers app
# Copie de FactDev.dll vers app
# Copie des Modules Qt vers app
# Rename app to FactDev
# Execution de machintruc pour faire un installeur
# pause


function call
{
    iex $args[0]  
}

function mkdirIfNotExist
{
    $dir = $args[0]
    $ret = Test-Path $dir 
    if (-not $ret) {
       mkdir $dir
    } 
}

function copyPlugin 
{
    $plugin_name = $args[0]
    mkdirIfNotExist $plugin_name
    call ("cp "+$qt_path+"\plugins\"+$plugin_name+"\*.dll "+$plugin_name)
    call ("rm """+$plugin_name+"/*d.dll""")
}

function copyQtDll 
{
    $dll_name = $args[0]
    call ("cp "+$qt_path+"\bin\"+$dll_name+".dll .")
}