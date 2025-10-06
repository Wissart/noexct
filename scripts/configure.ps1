param(
    [string]$Config = "Debug",
    [string]$Generator = "",
    [string]$Architecture = "x64",
    [switch]$Clean = $false,
    [string[]]$Options = @()
)

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectRoot = Split-Path -Parent $ScriptDir
$BuildDir = Join-Path $ProjectRoot "build"


Write-Host "Configuring Cmake project..." -ForegroundColor White
Write-Host "Project Root: $ProjectRoot" -ForegroundColor White
Write-Host "Build Type: $Config" -ForegroundColor White

if(-not $Generator){
    $helpOutput = cmake --help 2>&1

    $inSection = $false
    $defaultGenerator = $null

    foreach ($line in $helpOutput) {
        $trimmed = $line.Trim()
        
        if ($trimmed -eq "Generators") {
            $inSection = $true
            continue
        }
        
        if ($inSection -and $trimmed -match "^\*\s*(.+?)\s*=") {
            $generatorName = $matches[1].Trim()
        }
    }

    $Generator = $generatorName
}
Write-Host "Generator: $Generator" -ForegroundColor White

if($Clean -and (Test-Path $BuildDir)) {
    Write-Host "Cleaning build directory..." -ForegroundColor White
    Remove-Item -Recurse -Force $BuildDir
}

if(!(Test-Path $BuildDir)) {
    New-Item -ItemType Directory -Path $BuildDir | Out-Null 
}

Set-Location $BuildDir

$CMakeArgs = @("-G", $Generator, "-A", $Architecture, "-DCMAKE_BUILD_TYPE=$Config")

foreach($option in $Options){
    $CMakeArgs += "-D$option"
}

$CMakeArgs += $ProjectRoot

Write-Host "CMake command: cmake $CMakeArgs" -ForegroundColor Gray
cmake @CMakeArgs

if($LASTEXITCODE -ne 0){
    Write-Host "Configuration failed!" -ForegroundColor Red
    exit 1
}

Write-Host "Configuration completed successfully!" -ForegroundColor Green