# TOR SUPPORT IN DLG CORE

It is possible to run DreamLedger Core as a Tor onion service, and connect to such services.

The following directions assume you have a Tor proxy running on port 9050. Many
distributions default to having a SOCKS proxy listening on port 9050, but others
may not. In particular, the Tor Browser Bundle defaults to listening on port 9150.
See [Tor Project FAQ:TBBSocksPort](https://www.torproject.org/docs/faq.html.en#TBBSocksPort)
for how to properly configure Tor.


## 1. Run DreamLedger Core behind a Tor proxy

The first step is running DreamLedger Core behind a Tor proxy. This will already anonymize all
outgoing connections, but more is possible.

	-proxy=ip:port  Set the proxy server. If SOCKS5 is selected (default), this proxy
	                server will be used to try to reach .onion addresses as well.
	                You need to use -noonion or -onion=0 to explicitly disable
	                outbound access to onion services.

	-onion=ip:port  Set the proxy server to use for Tor onion services. You do not
	                need to set this if it's the same as -proxy. You can use -onion=0
	                to explicitly disable access to onion services.
	                Note: Only the -proxy option sets the proxy for DNS requests;
	                with -onion they will not route over Tor, so use -proxy if you
	                have privacy concerns.

	-listen         When using -proxy, listening is disabled by default. If you want
	                to manually configure an onion service (see section 3), you'll
	                need to enable it explicitly.

	-connect=X      When behind a Tor proxy, you can specify .onion addresses instead
	-addnode=X      of IP addresses or hostnames in these parameters. It requires
	-seednode=X     SOCKS5. In Tor mode, such addresses can also be exchanged with
	                other P2P nodes.

	-onlynet=onion  Make outgoing connections only to .onion addresses. Incoming
	                connections are not affected by this option. This option can be
	                specified multiple times to allow multiple network types, e.g.
	                ipv4, ipv6 or onion. If you use this option with values other
	                than onion you *cannot* disable onion connections; outgoing onion
	                connections will be enabled when you use -proxy or -onion. Use
	                -noonion or -onion=0 if you want to be sure there are no outbound
	                onion connections over the default proxy or your defined -proxy.

An example how to start the client if the Tor proxy is running on local host on
port 9050 and only allows .onion nodes to connect:

	./dreamledgerd -onion=127.0.0.1:9050 -onlynet=onion -listen=0 -addnode=ssapp53tmftyjmjb.onion

In a typical situation, this suffices to run behind a Tor proxy:

	./dreamledgerd -proxy=127.0.0.1:9050

## 2. Automatically create a DreamLedger Core onion service

DreamLedger Core makes use of Tor's control socket API to create and destroy
ephemeral onion services programmatically. This means that if Tor is running and
proper authentication has been configured, DreamLedger Core automatically creates an
onion service to listen on. The goal is to increase the number of available
onion nodes.

This feature is enabled by default if DreamLedger Core is listening (`-listen`) and
it requires a Tor connection to work. It can be explicitly disabled with
`-listenonion=0`. If it is not disabled, it can be configured using the
`-torcontrol` and `-torpassword` settings.

To see verbose Tor information in the dreamledgerd debug log, pass `-debug=tor`.

### Control Port

You may need to set up the Tor Control Port. On Linux distributions there may be
some or all of the following settings in `/etc/tor/torrc`, generally commented
out by default (if not, add them):

```
ControlPort 9051
CookieAuthentication 1
CookieAuthFileGroupReadable 1
```

Add or uncomment those, save, and restart Tor (usually `systemctl restart tor`
or `sudo systemctl restart tor` on most systemd-based systems, including recent
Debian and Ubuntu, or just restart the computer).

On some systems (such as Arch Linux), you may also need to add the following
line:

```
DataDirectoryGroupReadable 1
```

### Authentication

Connecting to Tor's control socket API requires one of two authentication
methods to be configured: cookie authentication or dreamledgerd's `-torpassword`
configuration option.

#### Cookie authentication

For cookie authentication, the user running dreamledgerd must have read access to
the `CookieAuthFile` specified in the Tor configuration. In some cases this is
preconfigured and the creation of an onion service is automatic. Don't forget to
use the `-debug=tor` dreamledgerd configuration option to enable Tor debug logging.

If a permissions problem is seen in the debug log, e.g. `tor: Authentication
cookie /run/tor/control.authcookie could not be opened (check permissions)`, it
can be resolved by adding both the user running Tor and the user running
dreamledgerd to the same Tor group and setting permissions appropriately.

On Debian-derived systems, the Tor group will likely be `debian-tor` and one way
to verify could be to list the groups and grep for a "tor" group name:

```
getent group | cut -d: -f1 | grep -i tor
```

You can also check the group of the cookie file. On most Linux systems, the Tor
auth cookie will usually be `/run/tor/control.authcookie`:

```
TORGROUP=$(stat -c '%G' /run/tor/control.authcookie)
```

Once you have determined the `${TORGROUP}` and selected the `${USER}` that will
run dreamledgerd, run this as root:

```
usermod -a -G ${TORGROUP} ${USER}
```

Then restart the computer (or log out) and log in as the `${USER}` that will run
dreamledgerd.

#### `torpassword` authentication

For the `-torpassword=password` option, the password is the clear text form that
was used when generating the hashed password for the `HashedControlPassword`
option in the Tor configuration file.

The hashed password can be obtained with the command `tor --hash-password
password` (refer to the [Tor Dev
Manual](https://2019.www.torproject.org/docs/tor-manual.html.en) for more
details).


## 3. Manually create a DreamLedger Core onion service

If you configure your Tor system accordingly, it is possible to make your node also
reachable from the Tor network. Add these lines to your /etc/tor/torrc (or equivalent
config file): *Needed for Tor version 0.2.7.0 and older versions of Tor only. For newer
versions of Tor see [Section 4](#4-automatically-listen-on-tor).*

	HiddenServiceDir /var/lib/tor/dreamledger-service/
	HiddenServicePort 16816 127.0.0.1:9996
	HiddenServicePort 26816 127.0.0.1:19996

The directory can be different of course, but virtual port numbers should be equal to
your dreamledgerd's P2P listen port (16816 by default), and target addresses and ports
should be equal to binding address and port for inbound Tor connections (127.0.0.1:9996 by default).

	-externalip=X   You can tell DreamLedger Core about its publicly reachable address using
	                this option, and this can be a .onion address. Given the above
	                configuration, you can find your .onion address in
	                /var/lib/tor/dreamledger-service/hostname. For connections
	                coming from unroutable addresses (such as 127.0.0.1, where the
	                Tor proxy typically runs), .onion addresses are given
	                preference for your node to advertise itself with.

	-listen         You'll need to enable listening for incoming connections, as this
	                is off by default behind a proxy.

	-discover       When -externalip is specified, no attempt is made to discover local
	                IPv4 or IPv6 addresses. If you want to run a dual stack, reachable
	                from both Tor and IPv4 (or IPv6), you'll need to either pass your
	                other addresses using -externalip, or explicitly enable -discover.
	                Note that both addresses of a dual-stack system may be easily
	                linkable using traffic analysis.

In a typical situation, where you're only reachable via Tor, this should suffice:

	./dreamledgerd -proxy=127.0.0.1:9050 -externalip=ssapp53tmftyjmjb.onion -listen

(obviously, replace the .onion address with your own). It should be noted that you still
listen on all devices and another node could establish a clearnet connection, when knowing
your address. To mitigate this, additionally bind the address of your Tor proxy:

	./dreamledgerd ... -bind=127.0.0.1

If you don't care too much about hiding your node, and want to be reachable on IPv4
as well, use `discover` instead:

	./dreamledgerd ... -discover

and open port 16816 on your firewall (or use port mapping, i.e., `-upnp` or `-natpmp`).

If you only want to use Tor to reach .onion addresses, but not use it as a proxy
for normal IPv4/IPv6 communication, use:

	./dreamledgerd -onion=127.0.0.1:9050 -externalip=ssapp53tmftyjmjb.onion -discover


## 3.1. List of known DreamLedger Core Tor relays

- 3dnj6le7i2dgzqtj7tth5zoiscmoddovzswdl5pjy5pnyllevxhb3uyd.onion
- cmhr5r3lqhy7ic2ebeil66ftcz5u62zq5qhbfdz53l6sqxljh7zxntyd.onion
- k532fqvgzqotj6epfw3rfc377elrj3td47ztad2tkn6vwnw6nhxacrqd.onion
- nqvpq3urtggxybor6wlf5odzanfqcitg5m7xjo2w25bj7tl2g54te6yd.onion
- oabd4mxviavh2xhlv4xidbqswsrqvmcnkpfwfwhjgy4w2dmlaoulxwad.onion
- qpcfsys2rqguha4vahdq6lbx7flc2fivrdicwxqtvh5okujrh6ami3ad.onion
- v7ttoiov7rc5aut64nfomyfwxt424ihufwvr5ilf7moeg3fwibjpjcqd.onion
- yjos5hcumgpgggm37xjmgjfzzhbjo6a7phyavutfzkh6qrlnozvajuad.onion

## 4. Privacy recommendations

- Do not add anything but DreamLedger Core ports to the onion service created in section 3.
  If you run a web service too, create a new onion service for that.
  Otherwise it is trivial to link them, which may reduce privacy. Onion
  services created automatically (as in section 2) always have only one port
  open.
