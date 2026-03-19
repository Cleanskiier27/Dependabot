# networkbusteros Easy Install Wizard
# This script guides the user through installing and running networkbusteros services

Write-Host "Welcome to the networkbusteros Easy Install Wizard!" -ForegroundColor Cyan

# Step 1: Install Node.js if not present
if (-not (Get-Command node -ErrorAction SilentlyContinue)) {
    Write-Host "Node.js is not installed. Please download and install Node.js from https://nodejs.org/ before continuing." -ForegroundColor Yellow
    Read-Host "Press Enter to continue after installing Node.js"
}
else {
    Write-Host "Node.js is installed." -ForegroundColor Green
}

# Step 2: Run PowerShell service loader
Write-Host "Running PowerShell service loader..." -ForegroundColor Cyan
powershell -ExecutionPolicy Bypass -File networkbusteros-powershell-service.ps1

# Step 3: Run Node.js service loader
Write-Host "Running Node.js service loader..." -ForegroundColor Cyan
node networkbusteros-node-service.js

# Step 4: Optionally start cloud server
$startCloud = Read-Host "Do you want to start the nb-cloudone-server? (y/n)"
if ($startCloud -eq 'y') {
    Write-Host "Starting nb-cloudone-server..." -ForegroundColor Cyan
    Start-Process node -ArgumentList 'nb-cloudone-server.js'
    Write-Host "nb-cloudone-server started on port 8080."
}
else {
    Write-Host "Cloud server not started."
}

Write-Host "networkbusteros installation complete!" -ForegroundColor Green
