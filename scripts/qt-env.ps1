# qt-env.psi
# Dot-source this file (". .\scripts\qt-env.ps1") at the sstart of a Qt session
# to add Qt's MinGW compiler and Qt's runtime DLLs to PATH.

$env:PATH = "C:\Qt\Tools\mingw1310_64\bin;" + $env:PATH
$env:PATH = "C:\Qt\6.11.0\mingw_64\bin;" + $env:PATH

Write-Host "Qt environment configured (GCC 13.1.0, Qt 6.11.0)"




