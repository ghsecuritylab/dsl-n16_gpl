#PPPD := $(shell /usr/sbin/pppd --version 2>&1 | grep version)
#PPPD := $(patsubst pppd,,$(PPPD))
#PPPD := $(patsubst version,,$(PPPD))
#PPPD := $(strip $(PPPD))

default:  plugin pptpd
client:  plugin
server: default

module:
	echo Building kernel module
	(cd kernel/driver; make )

plugin: pppd_plugin/Makefile
	echo Building pppd plugin
	(cd pppd_plugin; make)

pptpd: pptpd-1.3.3/Makefile
	echo Building pptpd
	(cd pptpd-1.3.3; make)

pppd_plugin/Makefile: pptpd-1.3.3/Makefile
	(cd pppd_plugin; ./configure --host=mips-linux)

pptpd-1.3.3/Makefile:
	(cd pptpd-1.3.3; ./configure --host=mips-linux --enable-bcrelay)

module_install: module
	(cd kernel/driver; make install)

plugin_install: plugin
	install -D pppd_plugin/src/.libs/pptp.so.0.0.0 $(INSTALLDIR)/accel-pptpd/usr/lib/pppd/pptp.so
	$(STRIP) $(INSTALLDIR)/accel-pptpd/usr/lib/pppd/pptp.so

client_install:  plugin_install

server_install: server 
	install -D pptpd-1.3.3/pptpd $(INSTALLDIR)/accel-pptpd/usr/sbin/pptpd
	install -D pptpd-1.3.3/bcrelay $(INSTALLDIR)/accel-pptpd/usr/sbin/bcrelay
	install -D pptpd-1.3.3/pptpctrl $(INSTALLDIR)/accel-pptpd/usr/sbin/pptpctrl
	$(STRIP) $(INSTALLDIR)/accel-pptpd/usr/sbin/pptpd
	$(STRIP) $(INSTALLDIR)/accel-pptpd/usr/sbin/bcrelay
	$(STRIP) $(INSTALLDIR)/accel-pptpd/usr/sbin/pptpctrl

clean:
	(cd kernel/driver; make clean)
	(cd pppd_plugin; make clean) || true
	(cd pptpd-1.3.3; make clean) || true

distclean:
	(cd kernel/driver; make clean)
	(cd pppd_plugin; make distclean)
	(cd pptpd-1.3.3; make distclean) || true
