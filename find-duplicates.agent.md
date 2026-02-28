<!DOCTYPE html>
<!-- saved from url=(0038)https://linux.die.net/man/5/ssh_config -->
<html lang="en"><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>ssh_config(5): OpenSSH SSH client config files - Linux man page</title>
<!--<base href="https://linux.die.net/man/5/ssh_config">--><base href=".">
<link rel="canonical" href="https://linux.die.net/man/5/ssh_config">
<link rel="stylesheet" type="text/css" href="./ssh_config(5)_ OpenSSH SSH client config files - Linux man page_files/white.css">
<link rel="shortcut icon" href="https://linux.die.net/favicon.ico" type="image/x-icon">
<meta name="viewport" content="width=device-width,initial-scale=1">
<meta name="description" content="ssh(1) obtains configuration data from the following sources in the following order:">
<script src="./ssh_config(5)_ OpenSSH SSH client config files - Linux man page_files/f.txt"></script><script type="text/javascript" async="" src="./ssh_config(5)_ OpenSSH SSH client config files - Linux man page_files/ga.js.download"></script><script type="text/javascript">
<!--
var _gaq = _gaq || [];_gaq.push(['_setAccount', 'UA-50820-6']);_gaq.push(['_trackPageview']);
window.google_analytics_uacct = 'UA-50820-6';
// -->
</script>
<meta http-equiv="origin-trial" content="AlK2UR5SkAlj8jjdEc9p3F3xuFYlF6LYjAML3EOqw1g26eCwWPjdmecULvBH5MVPoqKYrOfPhYVL71xAXI1IBQoAAAB8eyJvcmlnaW4iOiJodHRwczovL2RvdWJsZWNsaWNrLm5ldDo0NDMiLCJmZWF0dXJlIjoiV2ViVmlld1hSZXF1ZXN0ZWRXaXRoRGVwcmVjYXRpb24iLCJleHBpcnkiOjE3NTgwNjcxOTksImlzU3ViZG9tYWluIjp0cnVlfQ=="><meta http-equiv="origin-trial" content="Amm8/NmvvQfhwCib6I7ZsmUxiSCfOxWxHayJwyU1r3gRIItzr7bNQid6O8ZYaE1GSQTa69WwhPC9flq/oYkRBwsAAACCeyJvcmlnaW4iOiJodHRwczovL2dvb2dsZXN5bmRpY2F0aW9uLmNvbTo0NDMiLCJmZWF0dXJlIjoiV2ViVmlld1hSZXF1ZXN0ZWRXaXRoRGVwcmVjYXRpb24iLCJleHBpcnkiOjE3NTgwNjcxOTksImlzU3ViZG9tYWluIjp0cnVlfQ=="><meta http-equiv="origin-trial" content="A9nrunKdU5m96PSN1XsSGr3qOP0lvPFUB2AiAylCDlN5DTl17uDFkpQuHj1AFtgWLxpLaiBZuhrtb2WOu7ofHwEAAACKeyJvcmlnaW4iOiJodHRwczovL2RvdWJsZWNsaWNrLm5ldDo0NDMiLCJmZWF0dXJlIjoiQUlQcm9tcHRBUElNdWx0aW1vZGFsSW5wdXQiLCJleHBpcnkiOjE3NzQzMTA0MDAsImlzU3ViZG9tYWluIjp0cnVlLCJpc1RoaXJkUGFydHkiOnRydWV9"><meta http-equiv="origin-trial" content="A93bovR+QVXNx2/38qDbmeYYf1wdte9EO37K9eMq3r+541qo0byhYU899BhPB7Cv9QqD7wIbR1B6OAc9kEfYCA4AAACQeyJvcmlnaW4iOiJodHRwczovL2dvb2dsZXN5bmRpY2F0aW9uLmNvbTo0NDMiLCJmZWF0dXJlIjoiQUlQcm9tcHRBUElNdWx0aW1vZGFsSW5wdXQiLCJleHBpcnkiOjE3NzQzMTA0MDAsImlzU3ViZG9tYWluIjp0cnVlLCJpc1RoaXJkUGFydHkiOnRydWV9"><meta http-equiv="origin-trial" content="A1S5fojrAunSDrFbD8OfGmFHdRFZymSM/1ss3G+NEttCLfHkXvlcF6LGLH8Mo5PakLO1sCASXU1/gQf6XGuTBgwAAACQeyJvcmlnaW4iOiJodHRwczovL2dvb2dsZXRhZ3NlcnZpY2VzLmNvbTo0NDMiLCJmZWF0dXJlIjoiQUlQcm9tcHRBUElNdWx0aW1vZGFsSW5wdXQiLCJleHBpcnkiOjE3NzQzMTA0MDAsImlzU3ViZG9tYWluIjp0cnVlLCJpc1RoaXJkUGFydHkiOnRydWV9"></head>

<body>
<div id="bg">
<div id="logo">
<a href="https://www.die.net/"><img src="./ssh_config(5)_ OpenSSH SSH client config files - Linux man page_files/logo.svg" alt="die.net" width="120" height="120" onerror="this.onerror=null; this.src=&#39;/style/logo.png&#39;"></a>
</div>
<div id="content">

<!-- google_ad_section_start -->
<h1>ssh_config(5) - Linux man page</h1>
<h2>Name</h2>

<p><b>ssh_config</b> - OpenSSH SSH client configuration files
</p><h2>Synopsis</h2>

<p><b>~/.ssh/config</b>

</p><p><b>/etc/ssh/ssh_config</b>
</p><dl compact="">
<dd>

<h2>Description</h2>
</dd></dl>

<p><b><a href="https://linux.die.net/man/1/ssh">ssh</a></b>(1) obtains configuration data from the following sources in the following order:
</p><pre class="code">1. command-line options</pre>

<dl compact="">
<dd>2. user's configuration file (<i>~/.ssh/config</i>)<br>
3. system-wide configuration file (<i>/etc/ssh/ssh_config</i>)
<p>For each parameter, the first obtained value will be used. The configuration files contain sections separated by ''Host'' specifications, and that section
is only applied for hosts that match one of the patterns given in the specification. The matched host name is the one given on the command line.

</p><p>Since the first obtained value for each parameter is used, more host-specific declarations should be given near the beginning of the file, and general
defaults at the end.
</p><p>The configuration file has the following format:
</p><p>Empty lines and lines starting with '#' are comments. Otherwise a line is of the format ''keyword arguments''. Configuration options may be separated by
whitespace or optional whitespace and exactly one '='; the latter format is useful to avoid the need to quote whitespace when specifying configuration options
using the <b>ssh</b>, <b>scp</b>, and <b>sftp -o</b> option. Arguments may optionally be enclosed in double quotes (") in order to represent arguments
containing spaces.
</p><p>The possible keywords and their meanings are as follows (note that keywords are case-insensitive and arguments are case-sensitive):
</p><p><b>Host</b>' Restricts the following declarations (up to the next <b>Host</b> keyword) to be only for those hosts that match one of the patterns given after
the keyword. If more than one pattern is provided, they should be separated by whitespace. A single '*' as a pattern can be used to provide global defaults for
all hosts. The host is the <i>hostname</i> argument given on the command line (i.e. the name is not converted to a canonicalized host name before matching).

</p><p>See <i>PATTERNS</i> for more information on patterns.
</p><p><b>AddressFamily</b><br>
Specifies which address family to use when connecting. Valid arguments are ''any'', ''inet'' (use IPv4 only), or ''inet6'' (use IPv6 only).
</p><p><b>BatchMode</b><br>
If set to ''yes'', passphrase/password querying will be disabled. This option is useful in scripts and other batch jobs where no user is present to supply the
password. The argument must be ''yes'' or ''no''. The default is ''no''.
</p><p><b>BindAddress</b><br>
Use the specified address on the local machine as the source address of the connection. Only useful on systems with more than one address. Note that this
option does not work if <b>UsePrivilegedPort</b> is set to ''yes''.
</p><p><b>ChallengeResponseAuthentication</b><br>
Specifies whether to use challenge-response authentication. The argument to this keyword must be ''yes'' or ''no''. The default is ''yes''.
</p><p><b>CheckHostIP</b><br>
If this flag is set to ''yes'', <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) will additionally check the host IP address in the <i>known_hosts</i> file. This allows ssh to detect if a host key
changed due to DNS spoofing. If the option is set to ''no'', the check will not be executed. The default is ''yes''.
</p><p><b>Cipher</b><br>
Specifies the cipher to use for encrypting the session in protocol version 1. Currently, ''blowfish'', ''3des'', and ''des'' are supported. <i>des</i> is only
supported in the <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) client for interoperability with legacy protocol 1 implementations that do not support the <i>3des</i> cipher. Its use is strongly
discouraged due to cryptographic weaknesses. The default is ''3des''.
</p><p><b>Ciphers</b><br>
Specifies the ciphers allowed for protocol version 2 in order of preference. Multiple ciphers must be comma-separated. The supported ciphers are ''3des-cbc'',
''aes128-cbc'', ''aes192-cbc'', ''aes256-cbc'', ''aes128-ctr'', ''aes192-ctr'', ''aes256-ctr'', ''arcfour128'', ''arcfour256'', ''arcfour'', ''blowfish-cbc'',
and ''cast128-cbc''. The default is:
</p><p>aes128-ctr,aes192-ctr,aes256-ctr,arcfour256,arcfour128,<br>
aes128-cbc,3des-cbc,blowfish-cbc,cast128-cbc,aes192-cbc,<br>
aes256-cbc,arcfour
</p></dd></dl>
<pre class="code"><b>       ClearAllForwardings</b></pre>

<dl compact="">
<dd>Specifies that all local, remote, and dynamic port forwardings specified in the configuration files or on the command line be cleared. This option is
primarily useful when used from the <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) command line to clear port forwardings set in configuration files, and is automatically set by <b><a href="https://linux.die.net/man/1/scp">scp</a></b>(1) and <b><a href="https://linux.die.net/man/1/sftp">sftp</a></b>(1).
The argument must be ''yes'' or ''no''. The default is ''no''.
<p><b>Compression</b><br>
Specifies whether to use compression. The argument must be ''yes'' or ''no''. The default is ''no''.
</p><p><b>CompressionLevel</b><br>
Specifies the compression level to use if compression is enabled. The argument must be an integer from 1 (fast) to 9 (slow, best). The default level is 6,
which is good for most applications. The meaning of the values is the same as in <b><a href="https://linux.die.net/man/1/gzip">gzip</a></b>(1). Note that this option applies to protocol version 1 only.

</p><p><b>ConnectionAttempts</b><br>
Specifies the number of tries (one per second) to make before exiting. The argument must be an integer. This may be useful in scripts if the connection
sometimes fails. The default is 1.
</p><p><b>ConnectTimeout</b><br>
Specifies the timeout (in seconds) used when connecting to the SSH server, instead of using the default system TCP timeout. This value is used only when the
target is down or really unreachable, not when it refuses the connection.
</p><p><b>ControlMaster</b><br>
Enables the sharing of multiple sessions over a single network connection. When set to ''yes'', <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) will listen for connections on a control socket
specified using the <b>ControlPath</b> argument. Additional sessions can connect to this socket using the same <b>ControlPath</b> with <b>ControlMaster</b> set
to ''no'' (the default). These sessions will try to reuse the master instance's network connection rather than initiating new ones, but will fall back to
connecting normally if the control socket does not exist, or is not listening.
</p><p>Setting this to ''ask'' will cause ssh to listen for control connections, but require confirmation using the SSH_ASKPASS program before they are accepted
(see <b><a href="https://linux.die.net/man/1/ssh-add">ssh-add</a></b>(1) for details). If the <b>ControlPath</b> cannot be opened, ssh will continue without connecting to a master instance.
</p><p>X11 and <b><a href="https://linux.die.net/man/1/ssh-agent">ssh-agent</a></b>(1) forwarding is supported over these multiplexed connections, however the display and agent forwarded will be the one belonging to the
master connection i.e. it is not possible to forward multiple displays or agents.
</p><p>Two additional options allow for opportunistic multiplexing: try to use a master connection but fall back to creating a new one if one does not already
exist. These options are: ''auto'' and ''autoask''. The latter requires confirmation like the ''ask'' option.
</p><p><b>ControlPath</b><br>
Specify the path to the control socket used for connection sharing as described in the <b>ControlMaster</b> section above or the string ''none'' to disable
connection sharing. In the path, '%l' will be substituted by the local host name, '%h' will be substituted by the target host name, '%p' the port, and '%r' by
the remote login username. It is recommended that any <b>ControlPath</b> used for opportunistic connection sharing include at least %h, %p, and %r. This
ensures that shared connections are uniquely identified.
</p><p><b>DynamicForward</b><br>
Specifies that a TCP port on the local machine be forwarded over the secure channel, and the application protocol is then used to determine where to connect to
from the remote machine.
</p><p>The argument must be [<i><br>
bind_address</i>:]<i>port</i>. IPv6 addresses can be specified by enclosing addresses in square brackets or by using an alternative syntax: [<i><br>
bind_address</i>/]<i>port</i>. By default, the local port is bound in accordance with the <b>GatewayPorts</b> setting. However, an explicit <i>bind_address</i>
may be used to bind the connection to a specific address. The <i>bind_address</i> of ''localhost'' indicates that the listening port be bound for local use
only, while an empty address or '*' indicates that the port should be available from all interfaces.
</p><p>Currently the SOCKS4 and SOCKS5 protocols are supported, and <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) will act as a SOCKS server. Multiple forwardings may be specified, and additional
forwardings can be given on the command line. Only the superuser can forward privileged ports.
</p><p><b>EnableSSHKeysign</b><br>
Setting this option to ''yes'' in the global client configuration file <i>/etc/ssh/ssh_config</i> enables the use of the helper program <b><a href="https://linux.die.net/man/8/ssh-keysign">ssh-keysign</a></b>(8) during
<b>HostbasedAuthentication</b>. The argument must be ''yes'' or ''no''. The default is ''no''. This option should be placed in the non-hostspecific section.
See <b><a href="https://linux.die.net/man/8/ssh-keysign" rel="nofollow">ssh-keysign</a></b>(8) for more information.
</p><p><b>EscapeChar</b><br>
Sets the escape character (default: '~'). The escape character can also be set on the command line. The argument should be a single character, '^' followed by
a letter, or ''none'' to disable the escape character entirely (making the connection transparent for binary data).
</p><p><b>ExitOnForwardFailure</b><br>
Specifies whether <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) should terminate the connection if it cannot set up all requested dynamic, tunnel, local, and remote port forwardings. The argument
must be ''yes'' or ''no''. The default is ''no''.
</p><p><b>ForwardAgent</b><br>
Specifies whether the connection to the authentication agent (if any) will be forwarded to the remote machine. The argument must be ''yes'' or ''no''. The
default is ''no''.
</p><p>Agent forwarding should be enabled with caution. Users with the ability to bypass file permissions on the remote host (for the agent's Unix-domain socket)
can access the local agent through the forwarded connection. An attacker cannot obtain key material from the agent, however they can perform operations on the
keys that enable them to authenticate using the identities loaded into the agent.
</p><p><b>ForwardX11</b><br>
Specifies whether X11 connections will be automatically redirected over the secure channel and DISPLAY set. The argument must be ''yes'' or ''no''. The default
is ''no''.
</p><p>X11 forwarding should be enabled with caution. Users with the ability to bypass file permissions on the remote host (for the user's X11 authorization
database) can access the local X11 display through the forwarded connection. An attacker may then be able to perform activities such as keystroke monitoring if
the <b>ForwardX11Trusted</b> option is also enabled.
</p><p><b>ForwardX11Trusted</b><br>
If this option is set to ''yes'', remote X11 clients will have full access to the original X11 display.
</p><p>If this option is set to ''no'', remote X11 clients will be considered untrusted and prevented from stealing or tampering with data belonging to trusted X11
clients. Furthermore, the <b><a href="https://linux.die.net/man/1/xauth">xauth</a></b>(1) token used for the session will be set to expire after 20 minutes. Remote clients will be refused access after this time.

</p><p>The default is ''no''.
</p><p>See the X11 SECURITY extension specification for full details on the restrictions imposed on untrusted clients.
</p><p><b>GatewayPorts</b><br>
Specifies whether remote hosts are allowed to connect to local forwarded ports. By default, <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) binds local port forwardings to the loopback address. This
prevents other remote hosts from connecting to forwarded ports. <b>GatewayPorts</b> can be used to specify that ssh should bind local port forwardings to the
wildcard address, thus allowing remote hosts to connect to forwarded ports. The argument must be ''yes'' or ''no''. The default is ''no''.
</p><p><b>GlobalKnownHostsFile</b><br>
Specifies a file to use for the global host key database instead of <i>/etc/ssh/ssh_known_hosts</i>.
</p><p><b>GSSAPIAuthentication</b><br>
Specifies whether user authentication based on GSSAPI is allowed. The default is ''no''. Note that this option applies to protocol version 2 only.

</p><p><b>GSSAPIKeyExchange</b><br>
Specifies whether key exchange based on GSSAPI may be used. When using GSSAPI key exchange the server need not have a host key. The default is ''no''. Note
that this option applies to protocol version 2 only.
</p><p><b>GSSAPIClientIdentity</b><br>
If set, specifies the GSSAPI client identity that ssh should use when connecting to the server. The default is unset, which means that the default identity
will be used.
</p><p><b>GSSAPIDelegateCredentials</b><br>
Forward (delegate) credentials to the server. The default is ''no''. Note that this option applies to protocol version 2 connections using GSSAPI.

</p><p><b>GSSAPIRenewalForcesRekey</b><br>
If set to ''yes'' then renewal of the client's GSSAPI credentials will force the rekeying of the ssh connection. With a compatible server, this can delegate
the renewed credentials to a session on the server. The default is ''no''.
</p><p><b>GSSAPITrustDns</b><br>
Set to ''yes to indicate that the DNS is trusted to securely canonicalize'' the name of the host being connected to. If ''no, the hostname entered on the''
command line will be passed untouched to the GSSAPI library. The default is ''no''. This option only applies to protocol version 2 connections using GSSAPI.

</p><p><b>HashKnownHosts</b><br>
Indicates that <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) should hash host names and addresses when they are added to <i>~/.ssh/known_hosts</i>. These hashed names may be used normally by <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1)
and <b><a href="https://linux.die.net/man/8/sshd">sshd</a></b>(8), but they do not reveal identifying information should the file's contents be disclosed. The default is ''no''. Note that existing names and
addresses in known hosts files will not be converted automatically, but may be manually hashed using <b><a href="https://linux.die.net/man/1/ssh-keygen">ssh-keygen</a></b>(1).
</p><p><b>HostbasedAuthentication</b><br>
Specifies whether to try rhosts based authentication with public key authentication. The argument must be ''yes'' or ''no''. The default is ''no''. This option
applies to protocol version 2 only and is similar to <b>RhostsRSAAuthentication</b>.
</p><p><b>HostKeyAlgorithms</b><br>
Specifies the protocol version 2 host key algorithms that the client wants to use in order of preference. The default for this option is: ''ssh-rsa,ssh-dss''.

</p><p><b>HostKeyAlias</b><br>
Specifies an alias that should be used instead of the real host name when looking up or saving the host key in the host key database files. This option is
useful for tunneling SSH connections or for multiple servers running on a single host.
</p><p><b>HostName</b><br>
Specifies the real host name to log into. This can be used to specify nicknames or abbreviations for hosts. The default is the name given on the command line.
Numeric IP addresses are also permitted (both on the command line and in <b>HostName</b> specifications).
</p><p><b>IdentitiesOnly</b><br>
Specifies that <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) should only use the authentication identity files configured in the <b>ssh_config</b> files, even if <b><a href="https://linux.die.net/man/1/ssh-agent" rel="nofollow">ssh-agent</a></b>(1) offers more identities.
The argument to this keyword must be ''yes'' or ''no''. This option is intended for situations where ssh-agent offers many different identities. The default is
''no''.
</p><p><b>IdentityFile</b><br>
Specifies a file from which the user's RSA or DSA authentication identity is read. The default is <i>~/.ssh/identity</i> for protocol version 1, and
<i>~/.ssh/id_rsa</i> and <i>~/.ssh/id_dsa</i> for protocol version 2. Additionally, any identities represented by the authentication agent will be used for
authentication.
</p><p>The file name may use the tilde syntax to refer to a user's home directory or one of the following escape characters: '%d' (local user's home directory),
'%u' (local user name), '%l' (local host name), '%h' (remote host name) or '%r' (remote user name).
</p><p>It is possible to have multiple identity files specified in configuration files; all these identities will be tried in sequence.
</p><p><b>KbdInteractiveAuthentication</b><br>
Specifies whether to use keyboard-interactive authentication. The argument to this keyword must be ''yes'' or ''no''. The default is ''yes''.

</p><p><b>KbdInteractiveDevices</b><br>
Specifies the list of methods to use in keyboard-interactive authentication. Multiple method names must be comma-separated. The default is to use the server
specified list. The methods available vary depending on what the server supports. For an OpenSSH server, it may be zero or more of: ''bsdauth'', ''pam'', and
''skey''.
</p><p><b>LocalCommand</b><br>
Specifies a command to execute on the local machine after successfully connecting to the server. The command string extends to the end of the line, and is
executed with the user's shell. The following escape character substitutions will be performed: '%d' (local user's home directory), '%h' (remote host name),
'%l' (local host name), '%n' (host name as provided on the command line), '%p' (remote port), '%r' (remote user name) or '%u' (local user name). This directive
is ignored unless <b>PermitLocalCommand</b> has been enabled.
</p><p><b>LocalForward</b><br>
Specifies that a TCP port on the local machine be forwarded over the secure channel to the specified host and port from the remote machine. The first argument
must be [<i><br>
bind_address</i>:]<i>port</i> and the second argument must be <i>host</i>:<i>hostport</i>. IPv6 addresses can be specified by enclosing addresses in square
brackets or by using an alternative syntax: [<i><br>
bind_address</i>/]<i>port</i> and <i>host</i>/<i>hostport</i>. Multiple forwardings may be specified, and additional forwardings can be given on the command
line. Only the superuser can forward privileged ports. By default, the local port is bound in accordance with the <b>GatewayPorts</b> setting. However, an
explicit <i>bind_address</i> may be used to bind the connection to a specific address. The <i>bind_address</i> of ''localhost'' indicates that the listening
port be bound for local use only, while an empty address or '*' indicates that the port should be available from all interfaces.
</p><p><b>LogLevel</b><br>
Gives the verbosity level that is used when logging messages from <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1). The possible values are: QUIET, FATAL, ERROR, INFO, VERBOSE, DEBUG, DEBUG1, DEBUG2,
and DEBUG3. The default is INFO. DEBUG and DEBUG1 are equivalent. DEBUG2 and DEBUG3 each specify higher levels of verbose output.
</p><p><b>MACs</b>' Specifies the MAC (message authentication code) algorithms in order of preference. The MAC algorithm is used in protocol version 2 for data
integrity protection. Multiple algorithms must be comma-separated. The default is:
</p><p>hmac-md5,hmac-sha1,<a href="mailto:umac-64@openssh.com">umac-64@openssh.com</a>,<br>
hmac-ripemd160,hmac-sha1-96,hmac-md5-96
</p></dd></dl>
<pre class="code"><b>       NoHostAuthenticationForLocalhost</b></pre>

<dl compact="">
<dd>This option can be used if the home directory is shared across machines. In this case localhost will refer to a different machine on each of the machines
and the user will get many warnings about changed host keys. However, this option disables host authentication for localhost. The argument to this keyword must
be ''yes'' or ''no''. The default is to check the host key for localhost.
<p><b>NumberOfPasswordPrompts</b><br>
Specifies the number of password prompts before giving up. The argument to this keyword must be an integer. The default is 3.
</p><p><b>PasswordAuthentication</b><br>
Specifies whether to use password authentication. The argument to this keyword must be ''yes'' or ''no''. The default is ''yes''.
</p><p><b>PermitLocalCommand</b><br>
Allow local command execution via the <b>LocalCommand</b> option or using the <b>!</b><i>command</i> escape sequence in <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1). The argument must be ''yes'' or
''no''. The default is ''no''.
</p><p><b>Port</b>' Specifies the port number to connect on the remote host. The default is 22.
</p><p><b>PreferredAuthentications</b><br>
Specifies the order in which the client should try protocol 2 authentication methods. This allows a client to prefer one method (e.g.
<b>keyboard-interactive</b>) over another method (e.g. <b>password</b>) The default for this option is: ''<br>
gssapi-with-mic, hostbased, publickey, keyboard-interactive, password''.
</p><p><b>Protocol</b><br>
Specifies the protocol versions <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) should support in order of preference. The possible values are '1' and '2'. Multiple versions must be comma-separated.
The default is ''2,1''. This means that ssh tries version 2 and falls back to version 1 if version 2 is not available.
</p><p><b>ProxyCommand</b><br>
Specifies the command to use to connect to the server. The command string extends to the end of the line, and is executed with the user's shell. In the command
string, '%h' will be substituted by the host name to connect and '%p' by the port. The command can be basically anything, and should read from its standard
input and write to its standard output. It should eventually connect an <b><a href="https://linux.die.net/man/8/sshd" rel="nofollow">sshd</a></b>(8) server running on some machine, or execute <b>sshd -i</b> somewhere. Host key
management will be done using the HostName of the host being connected (defaulting to the name typed by the user). Setting the command to ''none'' disables
this option entirely. Note that <b>CheckHostIP</b> is not available for connects with a proxy command.
</p><p>This directive is useful in conjunction with <b><a href="https://linux.die.net/man/1/nc">nc</a></b>(1) and its proxy support. For example, the following directive would connect via an HTTP proxy at 192.0.2.0:

</p><p>ProxyCommand /usr/bin/nc -X connect -x 192.0.2.0:8080 %h %p
</p></dd></dl>
<pre class="code"><b>       PubkeyAuthentication</b></pre>

<dl compact="">
<dd>Specifies whether to try public key authentication. The argument to this keyword must be ''yes'' or ''no''. The default is ''yes''. This option applies to
protocol version 2 only.
<p><b>RekeyLimit</b><br>
Specifies the maximum amount of data that may be transmitted before the session key is renegotiated. The argument is the number of bytes, with an optional
suffix of 'K', 'M', or 'G' to indicate Kilobytes, Megabytes, or Gigabytes, respectively. The default is between '1G' and '4G', depending on the cipher. This
option applies to protocol version 2 only.
</p><p><b>RemoteForward</b><br>
Specifies that a TCP port on the remote machine be forwarded over the secure channel to the specified host and port from the local machine. The first argument
must be [<i><br>
bind_address</i>:]<i>port</i> and the second argument must be <i>host</i>:<i>hostport</i>. IPv6 addresses can be specified by enclosing addresses in square
brackets or by using an alternative syntax: [<i><br>
bind_address</i>/]<i>port</i> and <i>host</i>/<i>hostport</i>. Multiple forwardings may be specified, and additional forwardings can be given on the command
line. Privileged ports can be forwarded only when logging in as root on the remote machine.
</p><p>If the <i>port</i> argument is '0', the listen port will be dynamically allocated on the server and reported to the client at run time.
</p><p>If the <i>bind_address</i> is not specified, the default is to only bind to loopback addresses. If the <i>bind_address</i> is '*' or an empty string, then
the forwarding is requested to listen on all interfaces. Specifying a remote <i>bind_address</i> will only succeed if the server's <b>GatewayPorts</b> option
is enabled (see <b><a href="https://linux.die.net/man/5/sshd_config">sshd_config</a></b>(5)).
</p><p><b>RhostsRSAAuthentication</b><br>
Specifies whether to try rhosts based authentication with RSA host authentication. The argument must be ''yes'' or ''no''. The default is ''no''. This option
applies to protocol version 1 only and requires <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) to be setuid root.
</p><p><b>RSAAuthentication</b><br>
Specifies whether to try RSA authentication. The argument to this keyword must be ''yes'' or ''no''. RSA authentication will only be attempted if the identity
file exists, or an authentication agent is running. The default is ''yes''. Note that this option applies to protocol version 1 only.
</p><p><b>SendEnv</b><br>
Specifies what variables from the local <b><a href="https://linux.die.net/man/7/environ">environ</a></b>(7) should be sent to the server. Note that environment passing is only supported for protocol 2. The server
must also support it, and the server must be configured to accept these environment variables. Refer to <b>AcceptEnv</b> in <b><a href="https://linux.die.net/man/5/sshd_config" rel="nofollow">sshd_config</a></b>(5) for how to configure
the server. Variables are specified by name, which may contain wildcard characters. Multiple environment variables may be separated by whitespace or spread
across multiple <b>SendEnv</b> directives. The default is not to send any environment variables.
</p><p>See <i>PATTERNS</i> for more information on patterns.
</p><p><b>ServerAliveCountMax</b><br>
Sets the number of server alive messages (see below) which may be sent without <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) receiving any messages back from the server. If this threshold is reached
while server alive messages are being sent, ssh will disconnect from the server, terminating the session. It is important to note that the use of server alive
messages is very different from <b>TCPKeepAlive</b> (below). The server alive messages are sent through the encrypted channel and therefore will not be
spoofable. The TCP keepalive option enabled by <b>TCPKeepAlive</b> is spoofable. The server alive mechanism is valuable when the client or server depend on
knowing when a connection has become inactive.
</p><p>The default value is 3. If, for example, <b>ServerAliveInterval</b> (see below) is set to 15 and <b>ServerAliveCountMax</b> is left at the default, if the
server becomes unresponsive, ssh will disconnect after approximately 45 seconds. This option applies to protocol version 2 only.
</p><p><b>ServerAliveInterval</b><br>
Sets a timeout interval in seconds after which if no data has been received from the server, <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) will send a message through the encrypted channel to
request a response from the server. The default is 0, indicating that these messages will not be sent to the server. This option applies to protocol version 2
only.
</p><p><b>SmartcardDevice</b><br>
Specifies which smartcard device to use. The argument to this keyword is the device <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) should use to communicate with a smartcard used for storing the
user's private RSA key. By default, no device is specified and smartcard support is not activated.
</p><p><b>StrictHostKeyChecking</b><br>
If this flag is set to ''yes'', <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1) will never automatically add host keys to the <i>~/.ssh/known_hosts</i> file, and refuses to connect to hosts whose host
key has changed. This provides maximum protection against trojan horse attacks, though it can be annoying when the <i>/etc/ssh/ssh_known_hosts</i> file is
poorly maintained or when connections to new hosts are frequently made. This option forces the user to manually add all new hosts. If this flag is set to
''no'', ssh will automatically add new host keys to the user known hosts files. If this flag is set to ''ask'', new host keys will be added to the user known
host files only after the user has confirmed that is what they really want to do, and ssh will refuse to connect to hosts whose host key has changed. The host
keys of known hosts will be verified automatically in all cases. The argument must be ''yes'', ''no'', or ''ask''. The default is ''ask''.
</p><p><b>TCPKeepAlive</b><br>
Specifies whether the system should send TCP keepalive messages to the other side. If they are sent, death of the connection or crash of one of the machines
will be properly noticed. However, this means that connections will die if the route is down temporarily, and some people find it annoying.
</p><p>The default is ''yes'' (to send TCP keepalive messages), and the client will notice if the network goes down or the remote host dies. This is important in
scripts, and many users want it too.
</p><p>To disable TCP keepalive messages, the value should be set to ''no''.
</p><p><b>Tunnel</b><br>
Request <b>tun</b>(4) device forwarding between the client and the server. The argument must be ''yes'', ''point-to-point'' (layer 3), ''ethernet'' (layer 2), or
''no''. Specifying ''yes'' requests the default tunnel mode, which is ''point-to-point''. The default is ''no''.
</p><p><b>TunnelDevice</b><br>
Specifies the <b>tun</b>(4) devices to open on the client (<i>local_tun</i>) and the server (<i>remote_tun</i>).
</p><p>The argument must be <i>local_tun</i>[:<i>remote_tun</i>]. The devices may be specified by numerical ID or the keyword ''any'', which uses the next
available tunnel device. If <i>remote_tun</i> is not specified, it defaults to ''any''. The default is ''any:any''.
</p><p><b>UsePrivilegedPort</b><br>
Specifies whether to use a privileged port for outgoing connections. The argument must be ''yes'' or ''no''. The default is ''no''. If set to ''yes'', <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1)
must be setuid root. Note that this option must be set to ''yes'' for <b>RhostsRSAAuthentication</b> with older servers.
</p><p><b>User</b>' Specifies the user to log in as. This can be useful when a different user name is used on different machines. This saves the trouble of having
to remember to give the user name on the command line.
</p><p><b>UserKnownHostsFile</b><br>
Specifies a file to use for the user host key database instead of <i>~/.ssh/known_hosts</i>.
</p><p><b>VerifyHostKeyDNS</b><br>
Specifies whether to verify the remote key using DNS and SSHFP resource records. If this option is set to ''yes'', the client will implicitly trust keys that
match a secure fingerprint from DNS. Insecure fingerprints will be handled as if this option was set to ''ask''. If this option is set to ''ask'', information
on fingerprint match will be displayed, but the user will still need to confirm new host keys according to the <b>StrictHostKeyChecking</b> option. The
argument must be ''yes'', ''no'', or ''ask''. The default is ''no''. Note that this option applies to protocol version 2 only.
</p><p>See also <i>VERIFYING HOST KEYS</i> in <b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1).
</p><p><b>VisualHostKey</b><br>
If this flag is set to ''yes'', an ASCII art representation of the remote host key fingerprint is printed in addition to the hex fingerprint string at login
and for unknown host keys. If this flag is set to ''no'', no fingerprint strings are printed at login and only the hex fingerprint string will be printed for
unknown host keys. The default is ''no''.
</p><p><b>XAuthLocation</b><br>
Specifies the full pathname of the <b><a href="https://linux.die.net/man/1/xauth" rel="nofollow">xauth</a></b>(1) program. The default is <i>/usr/bin/xauth</i>.
</p><h2>Patterns</h2>
</dd></dl>

<p>A <i>pattern</i> consists of zero or more non-whitespace characters, '*' (a wildcard that matches zero or more characters), or '?' (a wildcard that matches
exactly one character). For example, to specify a set of declarations for any host in the ''.co.uk'' set of domains, the following pattern could be
used:
</p><dl compact="">
<dt>Host *.co.uk
</dt></dl>

<p>The following pattern would match any host in the 192.168.0.[0-9] network range:
</p><dl compact="">
<dt>Host 192.168.0.?
</dt></dl>

<p>A <i>pattern-list</i> is a comma-separated list of patterns. Patterns within pattern-lists may be negated by preceding them with an exclamation mark ('!').
For example, to allow a key to be used from anywhere within an organisation except from the ''dialup'' pool, the following entry (in authorized_keys) could be
used:
</p><dl compact="">
<dt>from="!*.dialup.example.com,*.example.com"
</dt></dl>
<h2>Files</h2>
<pre class="code">~/.ssh/config</pre>

<dl compact="">
<dd>This is the per-user configuration file. The format of this file is described above. This file is used by the SSH client. Because of the potential for
abuse, this file must have strict permissions: read/write for the user, and not accessible by others.
<p>/etc/ssh/ssh_config<br>
Systemwide configuration file. This file provides defaults for those values that are not specified in the user's configuration file, and for those users who do
not have a configuration file. This file must be world-readable.
</p><h2>See Also</h2>
</dd></dl>

<p><b><a href="https://linux.die.net/man/1/ssh" rel="nofollow">ssh</a></b>(1)
</p><h2>Authors</h2>

<p>OpenSSH is a derivative of the original and free ssh 1.2.12 release by Tatu Ylonen. Aaron Campbell, Bob Beck, Markus Friedl, Niels Provos, Theo de Raadt and
Dug Song removed many bugs, re-added newer features and created OpenSSH. Markus Friedl contributed the support for SSH protocol versions 1.5 and 2.0.

</p><p>BSD April 14, 2013 BSD

<!-- google_ad_section_end -->
</p><h2>Referenced By</h2>
<b><a href="https://linux.die.net/man/3/brlapi_tty" rel="nofollow">brlapi_tty</a></b>(3),
<b><a href="https://linux.die.net/man/1/darcs" rel="nofollow">darcs</a></b>(1),
<b><a href="https://linux.die.net/man/1/duplicity" rel="nofollow">duplicity</a></b>(1),
<b><a href="https://linux.die.net/man/1/gsissh" rel="nofollow">gsissh</a></b>(1),
<b><a href="https://linux.die.net/man/8/gsissh-keysign" rel="nofollow">gsissh-keysign</a></b>(8),
<b><a href="https://linux.die.net/man/8/gsisshd" rel="nofollow">gsisshd</a></b>(8),
<b><a href="https://linux.die.net/man/5/gsisshd_config" rel="nofollow">gsisshd_config</a></b>(5),
<b><a href="https://linux.die.net/man/1/pssh" rel="nofollow">pssh</a></b>(1),
<b><a href="https://linux.die.net/man/5/task-sync" rel="nofollow">task-sync</a></b>(5)
<div id="adbottom">
<script async="" src="./ssh_config(5)_ OpenSSH SSH client config files - Linux man page_files/f(1).txt"></script>
<ins class="adsbygoogle" style="display:inline-block;width:336px;height:280px" data-ad-client="ca-pub-5823754184406795" data-ad-slot="8789940313" data-adsbygoogle-status="done"><div id="aswift_0_host" style="border: none; height: 280px; width: 336px; margin: 0px; padding: 0px; position: relative; visibility: visible; background-color: transparent; display: inline-block;"></div></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>
</div>

</div>
<div id="menu">
<dl>
<dt>Site Search</dt>
<dd>
<form id="cse-search-box-menu" action="https://www.die.net/search/">
<input name="q" type="text" size="10">
<input type="hidden" name="sa" value="Search">
<input type="hidden" name="ie" value="ISO-8859-1">
<input type="hidden" name="cx" value="partner-pub-5823754184406795:54htp1rtx5u">
<input type="hidden" name="cof" value="FORID:9">
</form>
<script type="text/javascript">
<!--
document.forms["cse-search-box-menu"].action = "https://www.die.net/search/";
// -->
</script>
</dd></dl>

<dl>
<dt>Library</dt>
<dd><a href="https://linux.die.net/">linux docs</a></dd>
<dd><a href="https://linux.die.net/man/">linux man pages</a></dd>
</dl>
<dl>
<dt>Toys</dt>
<dd><a href="https://www.die.net/earth/">world sunlight</a></dd>
<dd><a href="https://www.die.net/moon/">moon phase</a></dd>
</dl>


<dl>
<dt><a href="https://linux.die.net/man/5/"><img src="./ssh_config(5)_ OpenSSH SSH client config files - Linux man page_files/back.gif" alt="Back" width="20" height="22"></a></dt><dd></dd>
</dl>
</div></div>
<script type="text/javascript">
<!--
if (top.location != self.location) top.location = self.location;
if (/[?&][pq]=/.test(document.referrer)) document.write(unescape("%3Cscript src='/style/highlight.js' type='text/javascript'%3E%3C/script%3E"));
function googleTranslateElementInit() {new google.translate.TranslateElement({pageLanguage: 'en', floatPosition: google.translate.TranslateElement.FloatPosition.TOP_RIGHT, gaTrack: true, gaId: 'UA-50820-6'});}
if (!/^en/i.test(window.navigator.userLanguage||window.navigator.language)) document.write(unescape("%3Cscript src='//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit' type='text/javascript'%3E%3C/script%3E"));
(function() {
var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
})();
// -->
</script>
<script>(function(){function c(){var b=a.contentDocument||a.contentWindow.document;if(b){var d=b.createElement('script');d.innerHTML="window.__CF$cv$params={r:'9d4d1bf09bb8e75b',t:'MTc3MjI1MjIxMw=='};var a=document.createElement('script');a.src='/cdn-cgi/challenge-platform/scripts/jsd/main.js';document.getElementsByTagName('head')[0].appendChild(a);";b.getElementsByTagName('head')[0].appendChild(d)}}if(document.body){var a=document.createElement('iframe');a.height=1;a.width=1;a.style.position='absolute';a.style.top=0;a.style.left=0;a.style.border='none';a.style.visibility='hidden';document.body.appendChild(a);if('loading'!==document.readyState)c();else if(window.addEventListener)document.addEventListener('DOMContentLoaded',c);else{var e=document.onreadystatechange||function(){};document.onreadystatechange=function(b){e(b);'loading'!==document.readyState&&(document.onreadystatechange=e,c())}}}})();</script><iframe height="1" width="1" style="position: absolute; top: 0px; left: 0px; border: none; visibility: hidden;" src="./ssh_config(5)_ OpenSSH SSH client config files - Linux man page_files/saved_resource.html"></iframe>

<ins class="adsbygoogle adsbygoogle-noablate" data-ad-hi="true" data-adsbygoogle-status="done" style="display: none !important;" data-ad-status="unfilled"><div id="aswift_1_host" style="border: none; height: 0px; width: 0px; margin: 0px; padding: 0px; position: relative; visibility: visible; background-color: transparent; display: inline-block;"><iframe id="aswift_1" name="aswift_1" style="left:0;position:absolute;top:0;border:0;width:undefinedpx;height:undefinedpx;min-height:auto;max-height:none;min-width:auto;max-width:none;" sandbox="allow-forms allow-popups allow-popups-to-escape-sandbox allow-same-origin allow-scripts allow-top-navigation-by-user-activation" frameborder="0" marginwidth="0" marginheight="0" vspace="0" hspace="0" allowtransparency="true" scrolling="no" allow="attribution-reporting; run-ad-auction" src="./ssh_config(5)_ OpenSSH SSH client config files - Linux man page_files/ads.html" data-google-container-id="a!2" tabindex="0" title="Advertisement" aria-label="Advertisement" data-load-complete="true"></iframe></div></ins><iframe src="./ssh_config(5)_ OpenSSH SSH client config files - Linux man page_files/aframe.html" width="0" height="0" style="display: none;"></iframe></body><iframe id="google_esf" name="google_esf" src="./ssh_config(5)_ OpenSSH SSH client config files - Linux man page_files/zrt_lookup_fy2021.html" style="display: none;"></iframe></html>