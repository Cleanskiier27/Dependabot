# Open an SSH tunnel to the deployment host defined in environment variables.
# Usage: .\scripts\open_ssh_tunnel.ps1 [-LocalPort <port>] [-RemoteTarget <host:port>] [-RemoteBindPort <port>] [-LocalTarget <host:port>]

param (
    [string]$LocalPort = "",
    [string]$RemoteTarget = "",
    [string]$RemoteBindPort = "",
    [string]$LocalTarget = ""
)

$User = $env:DEPLOY_USER
$HostName = $env:DEPLOY_HOST
$Port = $env:DEPLOY_PORT

if (-not $User -or -not $HostName) {
    Write-Host "Please set DEPLOY_USER and DEPLOY_HOST environment variables." -ForegroundColor Red
    exit 1
}
if (-not $Port) { $Port = "22" }

$SshArgs = @("-D", "1080", "-N", "-p", "$Port")

if ($LocalPort -and $RemoteTarget) {
    Write-Host "Adding Local Port Forwarding: localhost:$LocalPort -> $RemoteTarget"
    $SshArgs += "-L"
    $SshArgs += "$($LocalPort):$($RemoteTarget)"
}

if ($RemoteBindPort -and $LocalTarget) {
    Write-Host "Adding Remote Port Forwarding: remote:$RemoteBindPort -> $LocalTarget"
    $SshArgs += "-R"
    $SshArgs += "$($RemoteBindPort):$($LocalTarget)"
}

Write-Host "Opening SSH Dynamic Port Forwarding (SOCKS5) on localhost:1080 to $HostName..."
& ssh $SshArgs "$User@$HostName"