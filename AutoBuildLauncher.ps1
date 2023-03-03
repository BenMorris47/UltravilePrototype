
##Get the directory of the script
$ScriptDir=Split-Path -Parent $PSCommandPath

$BranchName = "main"


echo " "
echo ----------------------------------
echo "Check for branch Updates"
echo ----------------------------------
echo " "

#get the commit status of remote and local
$BranchLocal=git rev-parse $BranchName
$BranchRemote=git rev-parse origin/$BranchName

#Check that the branch is "in sync" with remote
if($BranchLocal -eq $BranchRemote){	
echo "No new build."
echo "Exiting!"
Start-Sleep -Seconds 3
exit
}
else
{
	echo "Updates Found."
	echo "Updating..."
	Start-Sleep -Seconds 3
	Start-Process (($ScriptDir) + "\AutoBuildUpload.bat")
	exit
}


