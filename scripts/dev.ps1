param(
    [string]$Config = "Debug",
    [string]$Generator = "",
    [string]$Architecture = "x64"
)

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectRoot = Split-Path -Parent $ScriptDir

Write-Host "Development Build - $Config configuration with extra features" -ForegroundColor White

& "$ScriptDir\build.ps1" -Config "Debug" -Generator $Generator -Architecture $Architecture -Clean:$false

if($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

Write-Host "Development build completed!" -ForegroundColor Green

