param(
    [string]$Command = "build",
    [string]$Config = "Release",
    [string[]]$Options = @(),
    [switch]$Help = $false
)


$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path

if($Help){
    Write-Host @"
C++ Project Build Script

Available comands:
    build       - Build the project
    dev         - Development build
    configure   - Configure CMake
    examples    - Run examples

Usage:
    .\run.ps1 build -Config Debug
    .\run.ps1 dev
    .\run.ps1 configure -Options @("OPTION_1=ON", "OPTION_2=ON")
    .\run.ps1 examples
"@ -ForegroundColor Cyan
    exit 0
}

switch($Command.ToLower()){
    "build"{
        & "$ScriptDir\build.ps1" -Config $Config
    }
    "dev"{
        & "$ScriptDir\dev.ps1" -Config $Config
    }
    "configure"{
        & "$ScriptDir\configure.ps1" -Config $Config -Options $Options
    }
    "examples"{
        & "$ScriptDir\examples.ps1" -Config $Config
    }
    default {
        Write-Host "Unknown command: $Command" -ForegroundColor Red
        Write-Host "Use -Help to see available commands" -ForegroundColor Yellow
        exit 1
    }
}