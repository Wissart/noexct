param(
    [string]$Config = "Release",
    [switch]$Configure = $false
)

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectRoot = Split-Path -Parent $ScriptDir
$BuildDir = Join-Path $ProjectRoot "build"
$ExamplesDir = Join-Path $BuildDir "examples/$Config"

if($Configure -or !(Test-Path $ExamplesDir)){
    Write-Host "Configuring project before build examples..." -ForegroundColor White
    & "$ScriptDir\build.ps1" -Config $Config -Clean:$false -Options @("NOEXCT_BUILD_EXAMPLES=ON")
    if($LASTEXITCODE -ne 0){
        exit $LASTEXITCODE
    }
}

if(!(Test-Path $BuildDir)){
    Write-Host "Build directory not found. Run build.ps1 first" -ForegroundColor Red
    exit 1
}

Write-Host "Runing examples..." -ForegroundColor White
Write-Host "Project Root: $ProjectRoot" -ForegroundColor Gray
Write-Host "Examples directory: $ExamplesDir" -ForegroundColor Gray


Set-Location $ExamplesDir

$Examples = Get-ChildItem -Filter "*.exe" -Name

foreach($example in $Examples) {
    $examplePath = Join-Path $ExamplesDir $example

    Write-Host ""
    Write-Host "$example running..." -ForegroundColor White

    & $examplePath
}

Set-Location $ProjectRoot
