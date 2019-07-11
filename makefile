# Set this variable to the name of the group that is allowed to restart apache.
webadmingroup = nobody

all: red5ctl

red5ctl:
	gcc red5ctl.c -o red5ctl

install: red5ctl
	install -m 6550 -g $(webadmingroup) -o root red5ctl /usr/local/bin

.PHONY: install

clean:
	rm red5ctl
