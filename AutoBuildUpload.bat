::Lovely tool from mr ryan, love you my boy Xxx
:: anyways I made it more general so it can work on anyones PC as long as they have butler
::get butler from here if not

@echo off


cd %~dp0

echo ----------------------------------
echo Check Git Status
echo ----------------------------------
echo.
git status

echo.
echo ----------------------------------
echo Commiting the files changed
echo ----------------------------------
echo.

git commit -a -m "Automatic pre-Build Commit"

echo.
echo ----------------------------------
echo Pulling from the repository
echo ----------------------------------
echo.
git pull

echo.
echo ----------------------------------
echo Pushing to the repository
echo ----------------------------------
echo.
git push

cd C:\Program Files\Epic Games\UE_5.0\Engine\Build\BatchFiles

echo.
echo ----------------------------------
echo Build Game
echo ----------------------------------
echo.
::Call this command in order to allow the batch to continue running
call RunUAT.bat BuildCookRun -project="%~dp0Ultravile_Engine\Ultravile_Engine.uproject" -clientconfig=Development -platform=Win64 -cook -stage -pak -stagingdirectory="%~dp0Build" -package -build

echo.
echo ----------------------------------
echo Build Completed!
echo Zipping up the contents of the build 
echo ----------------------------------
echo.

cd %~dp0Build

set "dateTime=%date:/=-%" 

set "fileName=Ultravile %dateTime%"


:: Zip build file ready for upload
tar.exe acvf "%fileName%.zip" Windows

echo.
echo ----------------------------------
echo Push to Itch via butler.exe
echo ----------------------------------
echo.

%butler% push "%fileName%.zip" bananatower/ultravile:win-universal

echo.
echo ----------------------------------
echo Itch Build pushed via butler.exe
echo ----------------------------------
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo _______________________________________________________________________________________________________________________
echo "/$$$$$$$                                                          /$$$$$$$$                                          "
echo "| $$__  $$                                                        |__  $$__/                                         "
echo "| $$  \ $$  /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$          | $$  /$$$$$$  /$$  /$$  /$$  /$$$$$$   /$$$$$$ "
echo "| $$$$$$$  |____  $$| $$__  $$ |____  $$| $$__  $$ |____  $$         | $$ /$$__  $$| $$ | $$ | $$ /$$__  $$ /$$__  $$"
echo "| $$__  $$  /$$$$$$$| $$  \ $$  /$$$$$$$| $$  \ $$  /$$$$$$$         | $$| $$  \ $$| $$ | $$ | $$| $$$$$$$$| $$  \__/"
echo "| $$  \ $$ /$$__  $$| $$  | $$ /$$__  $$| $$  | $$ /$$__  $$         | $$| $$  | $$| $$ | $$ | $$| $$_____/| $$      "
echo "| $$$$$$$/|  $$$$$$$| $$  | $$|  $$$$$$$| $$  | $$|  $$$$$$$         | $$|  $$$$$$/|  $$$$$/$$$$/|  $$$$$$$| $$      "
echo "|_______/  \_______/|__/  |__/ \_______/|__/  |__/ \_______/         |__/ \______/  \_____/\___/  \_______/|__/      "
echo _______________________________________________________________________________________________________________________
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
TIMEOUT /T 10