@echo off  

echo Deleting Binaries folder...  
if exist "Binaries" rd /s /q "Binaries"  

echo Deleting Intermediate folder...  
if exist "Intermediate" rd /s /q "Intermediate"  

echo Deleting Visual Studio solution files...  
del /q *.sln  

exit