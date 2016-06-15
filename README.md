# BdwLib
BdwLib is a general purpose library written in C, it provides some utility 
functions for strings, files and the most commonly used data structures like 
simple and doubly-linked Lists, Stacks and Queues.

It's partially based on the functions offered by 
[GLib](https://developer.gnome.org/glib).

## Installation
Dependencies (package names may vary depending on your distribution):
* make (for project building)
* libtool (makedep)
* autoconf (makedep)
* automake (makedep)
* git (makedep, not necessary if you downloaded the source code)
* gtk-doc (optional, needed if you want to generate the API documentation)

Then, simply do:
```
	$ git clone https://github.com/badwolfie/bdwlib.git
	$ cd bdwlib
	$ ./autogen.sh --prefix=/usr --libdir=/usr/lib --sysconfdir=/etc
	$ make
	# make install
```

**Note:** Pass the option `--enable-gtk-doc` to autogen.sh if you want to 
generate the [API documentation](https://badwolfie.github.io/bdwlib/docs).

Or check the [releases page](https://github.com/badwolfie/bdwlib/releases) for 
distribution-based installation options.

--  
Copyright &copy; 2016 [Ian Hernandez](mailto:badwolfie@archlinux.info) | 
[License](https://www.gnu.org/licenses/gpl-3.0.html)

