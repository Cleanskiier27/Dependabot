# networkbusteros Software Suite

## Overview
networkbusteros is a cross-platform automation and cloud service suite for Windows, Node.js, and PowerShell. It includes:
- PowerShell module loader
- Node.js service loader
- Cloud server (nb-cloudone-server)
- Easy install wizard
- Smoke test utility

## Components

### PowerShell
- `networkbusteros-powershell-service.ps1`: Imports all PowerShell modules.
- `install-wizard.ps1`: Guides installation and service startup.

### Node.js
- `networkbusteros-node-service.js`: Loads JSON and other services.
- `nb-cloudone-server.js`: Simple HTTP cloud server.
- `nb-cloudone-smoketest.js`: Smoke test for cloud server.

## Installation
1. Clone the repository:
   ```
   git clone https://github.com/Cleanskiier27/Modules.git
   cd Modules/networkbusteros
   ```
2. Run the install wizard:
   ```
   powershell -ExecutionPolicy Bypass -File install-wizard.ps1
   ```

## Usage
- Start the cloud server:
  ```
  node nb-cloudone-server.js
  ```
- Run the smoke test:
  ```
  node nb-cloudone-smoketest.js
  ```

## Requirements
- Windows 10/11
- PowerShell 5.1+
- Node.js 14+

## Optional: Hyper-V
To use Hyper-V, enable the Windows feature and install management tools.

## License
MIT
