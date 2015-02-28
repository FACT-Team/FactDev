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

# Create build folder
$ret = Test-Path "build"
if (-not $ret) {
   mkdir build
} 
cd build

# QMake execution
call  ($qmake_path + """" +$repo_path + "\FactDev.pro"" -r -spec win32-g++")

# Make clean, just in case
call ($make_path+" clean")

# Make of FactDev.dll
cd src
call ($make_path+ $make_nbprocess)

cd ../app
call ($make_path+ $make_nbprocess)

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