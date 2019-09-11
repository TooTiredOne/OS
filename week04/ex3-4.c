#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char str [50];

  while(1)
  {
    printf("the-best-shell-eva> ");
    fgets(str, 20, stdin);

    if(strcmp(str, "q\n") == 0)
      break;

    system(str);
  }

  return 0;
}

/*
the-best-shell-eva> pwd
/home/tootiredone/Innopolis/2nd year/OSI/Labs/week04

the-best-shell-eva> ls
ex1  ex1.c  ex1.sh  ex2  ex2.c	ex3  ex3.c

the-best-shell-eva> pstree
systemd─┬─ModemManager───2*[{ModemManager}]
        ├─NetworkManager─┬─dhclient
        │                └─2*[{NetworkManager}]
        ├─accounts-daemon───2*[{accounts-daemon}]
        ├─acpid
        ├─avahi-daemon───avahi-daemon
        ├─bluetoothd
        ├─boltd───2*[{boltd}]
        ├─chrome─┬─2*[cat]
        │        ├─chrome─┬─chrome─┬─8*[chrome───10*[{chrome}]]
        │        │        │        ├─chrome───13*[{chrome}]
        │        │        │        ├─6*[chrome───11*[{chrome}]]
        │        │        │        ├─chrome───3*[{chrome}]
        │        │        │        ├─chrome───15*[{chrome}]
        │        │        │        └─chrome───12*[{chrome}]
        │        │        └─nacl_helper
        │        ├─chrome───6*[{chrome}]
        │        ├─chrome───7*[{chrome}]
        │        └─27*[{chrome}]
        ├─colord───2*[{colord}]
        ├─cron
        ├─cups-browsed───2*[{cups-browsed}]
        ├─cupsd
        ├─dbus-daemon
        ├─fwupd───4*[{fwupd}]
        ├─gdm3─┬─gdm-session-wor─┬─gdm-wayland-ses─┬─gnome-session-b─┬─gnome-shel+
        │      │                 │                 │                 ├─gsd-a11y-s+
        │      │                 │                 │                 ├─gsd-clipbo+
        │      │                 │                 │                 ├─gsd-color─+++
        │      │                 │                 │                 ├─gsd-dateti+
        │      │                 │                 │                 ├─gsd-housek+
        │      │                 │                 │                 ├─gsd-keyboa+
        │      │                 │                 │                 ├─gsd-media-+
        │      │                 │                 │                 ├─gsd-mouse─+++
        │      │                 │                 │                 ├─gsd-power─+++
        │      │                 │                 │                 ├─gsd-print-+
        │      │                 │                 │                 ├─gsd-rfkill+++
        │      │                 │                 │                 ├─gsd-screen+
        │      │                 │                 │                 ├─gsd-sharin+
        │      │                 │                 │                 ├─gsd-smartc+
        │      │                 │                 │                 ├─gsd-sound─+++
        │      │                 │                 │                 ├─gsd-wacom─+++
        │      │                 │                 │                 ├─gsd-xsetti+
        │      │                 │                 │                 └─3*[{gnome-+
        │      │                 │                 └─2*[{gdm-wayland-ses}]
        │      │                 └─2*[{gdm-session-wor}]
        │      ├─gdm-session-wor─┬─gdm-x-session─┬─Xorg───3*[{Xorg}]
        │      │                 │               ├─gnome-session-b─┬─blueman-appl+
        │      │                 │               │                 ├─gnome-shell─+++
        │      │                 │               │                 │             +++
        │      │                 │               │                 ├─gnome-softwa+
        │      │                 │               │                 ├─gsd-a11y-set+
        │      │                 │               │                 ├─gsd-clipboar+
        │      │                 │               │                 ├─gsd-color───+
        │      │                 │               │                 ├─gsd-datetime+++
        │      │                 │               │                 ├─gsd-disk-uti+
        │      │                 │               │                 ├─gsd-housekee+
        │      │                 │               │                 ├─gsd-keyboard+++
        │      │                 │               │                 ├─gsd-media-ke+
        │      │                 │               │                 ├─gsd-mouse───+
        │      │                 │               │                 ├─gsd-power───+
        │      │                 │               │                 ├─gsd-print-no+
        │      │                 │               │                 ├─gsd-rfkill──+++
        │      │                 │               │                 ├─gsd-screensa+
        │      │                 │               │                 ├─gsd-sharing─+++
        │      │                 │               │                 ├─gsd-smartcar+
        │      │                 │               │                 ├─gsd-sound───+
        │      │                 │               │                 ├─gsd-wacom───+
        │      │                 │               │                 ├─gsd-xsetting+
        │      │                 │               │                 ├─nautilus-des+
        │      │                 │               │                 ├─ssh-agent
        │      │                 │               │                 ├─update-notif+
        │      │                 │               │                 └─3*[{gnome-se+
        │      │                 │               └─2*[{gdm-x-session}]
        │      │                 └─2*[{gdm-session-wor}]
        │      └─2*[{gdm3}]
        ├─gnome-keyring-d───3*[{gnome-keyring-d}]
        ├─gsd-printer───2*[{gsd-printer}]
        ├─ibus-x11───3*[{ibus-x11}]
        ├─ibus-x11───2*[{ibus-x11}]
        ├─irqbalance───{irqbalance}
        ├─2*[kerneloops]
        ├─networkd-dispat───{networkd-dispat}
        ├─packagekitd───2*[{packagekitd}]
        ├─polkitd───2*[{polkitd}]
        ├─postgres───6*[postgres]
        ├─pulseaudio───2*[{pulseaudio}]
        ├─rsyslogd───3*[{rsyslogd}]
        ├─rtkit-daemon───2*[{rtkit-daemon}]
        ├─snapd───25*[{snapd}]
        ├─systemd─┬─(sd-pam)
        │         ├─at-spi-bus-laun─┬─dbus-daemon
        │         │                 └─3*[{at-spi-bus-laun}]
        │         ├─at-spi2-registr───2*[{at-spi2-registr}]
        │         ├─dbus-daemon
        │         ├─dconf-service───2*[{dconf-service}]
        │         ├─ibus-portal───2*[{ibus-portal}]
        │         ├─pulseaudio───2*[{pulseaudio}]
        │         └─xdg-permission-───2*[{xdg-permission-}]
        ├─systemd─┬─(sd-pam)
        │         ├─at-spi-bus-laun─┬─dbus-daemon
        │         │                 └─3*[{at-spi-bus-laun}]
        │         ├─at-spi2-registr───2*[{at-spi2-registr}]
        │         ├─atom───atom─┬─atom─┬─atom───25*[{atom}]
        │         │             │      └─atom───15*[{atom}]
        │         │             ├─atom───8*[{atom}]
        │         │             └─29*[{atom}]
        │         ├─dbus-daemon
        │         ├─dconf-service───2*[{dconf-service}]
        │         ├─evince───4*[{evince}]
        │         ├─evinced───2*[{evinced}]
        │         ├─evolution-addre─┬─evolution-addre───5*[{evolution-addre}]
        │         │                 └─4*[{evolution-addre}]
        │         ├─evolution-calen─┬─evolution-calen───8*[{evolution-calen}]
        │         │                 └─4*[{evolution-calen}]
        │         ├─evolution-sourc───3*[{evolution-sourc}]
        │         ├─ex3
        │         ├─gnome-shell-cal───5*[{gnome-shell-cal}]
        │         ├─gnome-terminal-─┬─bash───ex3───sh───pstree
        │         │                 └─3*[{gnome-terminal-}]
        │         ├─goa-daemon───3*[{goa-daemon}]
        │         ├─goa-identity-se───3*[{goa-identity-se}]
        │         ├─gvfs-afc-volume───3*[{gvfs-afc-volume}]
        │         ├─gvfs-goa-volume───2*[{gvfs-goa-volume}]
        │         ├─gvfs-gphoto2-vo───2*[{gvfs-gphoto2-vo}]
        │         ├─gvfs-mtp-volume───2*[{gvfs-mtp-volume}]
        │         ├─gvfs-udisks2-vo───2*[{gvfs-udisks2-vo}]
        │         ├─gvfsd─┬─gvfsd-dnssd───2*[{gvfsd-dnssd}]
        │         │       ├─gvfsd-network───3*[{gvfsd-network}]
        │         │       ├─gvfsd-trash───2*[{gvfsd-trash}]
        │         │       └─2*[{gvfsd}]
        │         ├─gvfsd-fuse───5*[{gvfsd-fuse}]
        │         ├─gvfsd-metadata───2*[{gvfsd-metadata}]
        │         ├─ibus-portal───2*[{ibus-portal}]
        │         ├─nautilus───11*[{nautilus}]
        │         ├─obexd
        │         └─xdg-permission-───2*[{xdg-permission-}]
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-resolve
        ├─systemd-timesyn───{systemd-timesyn}
        ├─systemd-udevd
        ├─thermald───{thermald}
        ├─udisksd───4*[{udisksd}]
        ├─unattended-upgr───{unattended-upgr}
        ├─upowerd───2*[{upowerd}]
        ├─whoopsie───2*[{whoopsie}]
        └─wpa_supplicant


the-best-shell-eva> man fork

        FORK(2)                    Linux Programmer's Manual                    FORK(2)

        NAME
               fork - create a child process

        SYNOPSIS
               #include <sys/types.h>
               #include <unistd.h>

               pid_t fork(void);

        DESCRIPTION
               fork()  creates  a  new process by duplicating the calling process.  The
               new process is referred to as the child process.  The calling process is
               referred to as the parent process.

               The  child process and the parent process run in separate memory spaces.
               At the time of fork() both memory spaces have the same content.   Memory
               writes, file mappings (mmap(2)), and unmappings (munmap(2)) performed by
               one of the processes do not affect the other.

               The child process is an exact duplicate of the parent process except for
               the following points:
         Manual page fork(2) line 1 (press h for help or q to quit)

the-best-shell-eva> mkdir folder23
the-best-shell-eva> ls
ex1  ex1.c  ex1.sh  ex2  ex2.c	ex3  ex3.c  folder23

the-best-shell-eva> rm -r folder23
the-best-shell-eva> ls
ex1  ex1.c  ex1.sh  ex2  ex2.c	ex3  ex3.c



*/
