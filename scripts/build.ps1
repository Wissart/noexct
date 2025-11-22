param(
    [string]$Config = "Release",
    [string]$Generator = "",
    [string]$Architecture = "x64",
    [switch]$Clean = $false,
    [string[]]$Options = @()
)

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectRoot = Split-Path -Parent $ScriptDir

Write-Host "Building C++ project with CMake..." -ForegroundColor White
& "$ScriptDir\configure.ps1" -Config $Config -Generator $Generator -Architecture $Architecture -Clean:$Clean -Options $Options

if($LASTEXITCODE -ne 0){
    exit $LASTEXITCODE
}

$BuildDir = Join-Path $ProjectRoot "build"
Set-Location $BuildDir

Write-Host "Building project..." -ForegroundColor White
cmake --build . --config $Config

if($LASTEXITCODE -ne 0) {
    Set-Location $ProjectRoot
    Write-Host "Build failed!" -ForegroundColor Red
    exit 1
}

Set-Location $ProjectRoot
Write-Host "Build completed successfully!" -ForegroundColor Green
