/* DO NOT EDIT. This file is generated from applets.src.h */
/* vi: set sw=4 ts=4: */
/*
 * applets.h - a listing of all busybox applets.
 *
 * If you write a new applet, you need to add an entry to this list to make
 * busybox aware of it.
 */

/*
name  - applet name as it is typed on command line
help  - applet name, converted to C (ether-wake: help = ether_wake)
main  - corresponding <applet>_main to call (bzcat: main = bunzip2)
l     - location to install link to: [/usr]/[s]bin
s     - suid type:
        BB_SUID_REQUIRE: will complain if busybox isn't suid
        and is run by non-root (applet_main() will not be called at all)
        BB_SUID_DROP: will drop suid prior to applet_main()
        BB_SUID_MAYBE: neither of the above
        (every instance of BB_SUID_REQUIRE and BB_SUID_MAYBE
        needs to be justified in comment)
        NB: please update FEATURE_SUID help text whenever you add/remove
        BB_SUID_REQUIRE or BB_SUID_MAYBE applet.
*/

#if defined(PROTOTYPES)
# define APPLET(name,l,s)                    int name##_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
# define APPLET_ODDNAME(name,main,l,s,help)  int main##_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
# define APPLET_NOEXEC(name,main,l,s,help)   int main##_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
# define APPLET_NOFORK(name,main,l,s,help)   int main##_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;

#elif defined(NAME_MAIN)
# define APPLET(name,l,s)                    name name##_main
# define APPLET_ODDNAME(name,main,l,s,help)  name main##_main
# define APPLET_NOEXEC(name,main,l,s,help)   name main##_main
# define APPLET_NOFORK(name,main,l,s,help)   name main##_main

#elif defined(MAKE_USAGE) && ENABLE_FEATURE_VERBOSE_USAGE
# define APPLET(name,l,s)                    MAKE_USAGE(#name, name##_trivial_usage name##_full_usage)
# define APPLET_ODDNAME(name,main,l,s,help)  MAKE_USAGE(#name, help##_trivial_usage help##_full_usage)
# define APPLET_NOEXEC(name,main,l,s,help)   MAKE_USAGE(#name, help##_trivial_usage help##_full_usage)
# define APPLET_NOFORK(name,main,l,s,help)   MAKE_USAGE(#name, help##_trivial_usage help##_full_usage)

#elif defined(MAKE_USAGE) && !ENABLE_FEATURE_VERBOSE_USAGE
# define APPLET(name,l,s)                    MAKE_USAGE(#name, name##_trivial_usage)
# define APPLET_ODDNAME(name,main,l,s,help)  MAKE_USAGE(#name, help##_trivial_usage)
# define APPLET_NOEXEC(name,main,l,s,help)   MAKE_USAGE(#name, help##_trivial_usage)
# define APPLET_NOFORK(name,main,l,s,help)   MAKE_USAGE(#name, help##_trivial_usage)

#elif defined(MAKE_LINKS)
# define APPLET(name,l,c)                    LINK l name
# define APPLET_ODDNAME(name,main,l,s,help)  LINK l name
# define APPLET_NOEXEC(name,main,l,s,help)   LINK l name
# define APPLET_NOFORK(name,main,l,s,help)   LINK l name

#elif defined(MAKE_SUID)
# define APPLET(name,l,s)                    SUID s l name
# define APPLET_ODDNAME(name,main,l,s,help)  SUID s l name
# define APPLET_NOEXEC(name,main,l,s,help)   SUID s l name
# define APPLET_NOFORK(name,main,l,s,help)   SUID s l name

#else
  static struct bb_applet applets[] = { /*    name, main, location, need_suid */
# define APPLET(name,l,s)                    { #name, #name, l, s },
# define APPLET_ODDNAME(name,main,l,s,help)  { #name, #main, l, s },
# define APPLET_NOEXEC(name,main,l,s,help)   { #name, #main, l, s, 1 },
# define APPLET_NOFORK(name,main,l,s,help)   { #name, #main, l, s, 1, 1 },
#endif

#if ENABLE_INSTALL_NO_USR
# define BB_DIR_USR_BIN BB_DIR_BIN
# define BB_DIR_USR_SBIN BB_DIR_SBIN
#endif


IF_AR(APPLET(ar, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UNCOMPRESS(APPLET(uncompress, BB_DIR_BIN, BB_SUID_DROP))
IF_GUNZIP(APPLET(gunzip, BB_DIR_BIN, BB_SUID_DROP))
IF_GUNZIP(APPLET_ODDNAME(zcat, gunzip, BB_DIR_BIN, BB_SUID_DROP, zcat))
IF_BUNZIP2(APPLET(bunzip2, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_BUNZIP2(APPLET_ODDNAME(bzcat, bunzip2, BB_DIR_USR_BIN, BB_SUID_DROP, bzcat))
IF_UNLZMA(APPLET(unlzma, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UNLZMA(APPLET_ODDNAME(lzcat, unlzma, BB_DIR_USR_BIN, BB_SUID_DROP, lzcat))
IF_LZMA(APPLET_ODDNAME(lzma, unlzma, BB_DIR_USR_BIN, BB_SUID_DROP, lzma))
IF_UNXZ(APPLET(unxz, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UNXZ(APPLET_ODDNAME(xzcat, unxz, BB_DIR_USR_BIN, BB_SUID_DROP, xzcat))
IF_XZ(APPLET_ODDNAME(xz, unxz, BB_DIR_USR_BIN, BB_SUID_DROP, xz))
IF_BZIP2(APPLET(bzip2, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CPIO(APPLET(cpio, BB_DIR_BIN, BB_SUID_DROP))
IF_DPKG(APPLET(dpkg, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_DPKG_DEB(APPLET_ODDNAME(dpkg-deb, dpkg_deb, BB_DIR_USR_BIN, BB_SUID_DROP, dpkg_deb))
IF_GZIP(APPLET(gzip, BB_DIR_BIN, BB_SUID_DROP))
IF_LZOP(APPLET(lzop, BB_DIR_BIN, BB_SUID_DROP))
IF_LZOP(APPLET_ODDNAME(lzopcat, lzop, BB_DIR_USR_BIN, BB_SUID_DROP, lzopcat))
IF_LZOP(APPLET_ODDNAME(unlzop, lzop, BB_DIR_USR_BIN, BB_SUID_DROP, unlzop))
IF_RPM(APPLET(rpm, BB_DIR_BIN, BB_SUID_DROP))
IF_RPM2CPIO(APPLET(rpm2cpio, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TAR(APPLET(tar, BB_DIR_BIN, BB_SUID_DROP))
IF_UNZIP(APPLET(unzip, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_DATE(APPLET(date, BB_DIR_BIN, BB_SUID_DROP))
IF_HOSTID(APPLET_NOFORK(hostid, hostid, BB_DIR_USR_BIN, BB_SUID_DROP, hostid))
IF_GROUPS(APPLET_NOEXEC(groups, id, BB_DIR_USR_BIN, BB_SUID_DROP, groups))
IF_ID(    APPLET_NOEXEC(id,     id, BB_DIR_USR_BIN, BB_SUID_DROP, id    ))
IF_SHUF(APPLET_NOEXEC(shuf, shuf, BB_DIR_USR_BIN, BB_SUID_DROP, shuf))
IF_SYNC(APPLET_NOFORK(sync, sync, BB_DIR_BIN, BB_SUID_DROP, sync))
IF_TOUCH(APPLET_NOFORK(touch, touch, BB_DIR_BIN, BB_SUID_DROP, touch))
IF_TRUNCATE(APPLET_NOFORK(truncate, truncate, BB_DIR_USR_BIN, BB_SUID_DROP, truncate))
IF_UNLINK(APPLET(unlink, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_BASE64(APPLET(base64, BB_DIR_BIN, BB_SUID_DROP))
IF_USERS(APPLET_ODDNAME(users, who, BB_DIR_USR_BIN, BB_SUID_DROP, users))
IF_WHO(  APPLET(  who, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_AWK(APPLET_NOEXEC(awk, awk, BB_DIR_USR_BIN, BB_SUID_DROP, awk))
IF_CMP(APPLET(cmp, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_DIFF(APPLET(diff, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_ED(APPLET(ed, BB_DIR_BIN, BB_SUID_DROP))
IF_PATCH(APPLET(patch, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SED(APPLET(sed, BB_DIR_BIN, BB_SUID_DROP))
IF_VI(APPLET(vi, BB_DIR_BIN, BB_SUID_DROP))
IF_FIND(APPLET_NOEXEC(find, find, BB_DIR_USR_BIN, BB_SUID_DROP, find))
IF_GREP(APPLET(grep, BB_DIR_BIN, BB_SUID_DROP))
IF_FEATURE_GREP_EGREP_ALIAS(APPLET_ODDNAME(egrep, grep, BB_DIR_BIN, BB_SUID_DROP, egrep))
IF_FEATURE_GREP_FGREP_ALIAS(APPLET_ODDNAME(fgrep, grep, BB_DIR_BIN, BB_SUID_DROP, fgrep))
IF_XARGS(APPLET_NOEXEC(xargs, xargs, BB_DIR_USR_BIN, BB_SUID_DROP, xargs))
IF_BOOTCHARTD(APPLET(bootchartd, BB_DIR_SBIN, BB_SUID_DROP))
IF_HALT(APPLET(halt, BB_DIR_SBIN, BB_SUID_DROP))
IF_HALT(APPLET_ODDNAME(poweroff, halt, BB_DIR_SBIN, BB_SUID_DROP, poweroff))
IF_HALT(APPLET_ODDNAME(reboot, halt, BB_DIR_SBIN, BB_SUID_DROP, reboot))
IF_INIT(APPLET(init, BB_DIR_SBIN, BB_SUID_DROP))
IF_FEATURE_INITRD(APPLET_ODDNAME(linuxrc, init, BB_DIR_ROOT, BB_SUID_DROP, linuxrc))
IF_MESG(APPLET(mesg, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UNIT_TEST(APPLET(unit, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_ADD_SHELL(   APPLET_ODDNAME(add-shell   , add_remove_shell, BB_DIR_USR_SBIN, BB_SUID_DROP, add_shell   ))
IF_REMOVE_SHELL(APPLET_ODDNAME(remove-shell, add_remove_shell, BB_DIR_USR_SBIN, BB_SUID_DROP, remove_shell))
IF_CONSPY(APPLET(conspy, BB_DIR_BIN, BB_SUID_DROP))
IF_CROND(APPLET(crond, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_I2CGET(APPLET(i2cget, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_I2CSET(APPLET(i2cset, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_I2CDUMP(APPLET(i2cdump, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_I2CDETECT(APPLET(i2cdetect, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_NANDWRITE(APPLET(nandwrite, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_NANDDUMP(APPLET_ODDNAME(nanddump, nandwrite, BB_DIR_USR_SBIN, BB_SUID_DROP, nanddump))
IF_RFKILL(APPLET(rfkill, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SETSERIAL(APPLET(setserial, BB_DIR_BIN, BB_SUID_DROP))
IF_TASKSET(APPLET(taskset, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UBIATTACH(APPLET_ODDNAME(ubiattach, ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubiattach))
IF_UBIDETACH(APPLET_ODDNAME(ubidetach, ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubidetach))
IF_UBIMKVOL(APPLET_ODDNAME(ubimkvol, ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubimkvol))
IF_UBIRMVOL(APPLET_ODDNAME(ubirmvol, ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubirmvol))
IF_UBIRSVOL(APPLET_ODDNAME(ubirsvol, ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubirsvol))
IF_UBIUPDATEVOL(APPLET_ODDNAME(ubiupdatevol, ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubiupdatevol))
IF_WALL(APPLET(wall, BB_DIR_USR_BIN, BB_SUID_REQUIRE))
IF_DEPMOD(APPLET(depmod, BB_DIR_SBIN, BB_SUID_DROP))
IF_INSMOD(APPLET(insmod, BB_DIR_SBIN, BB_SUID_DROP))
IF_LSMOD(APPLET(lsmod, BB_DIR_SBIN, BB_SUID_DROP))
IF_MODINFO(APPLET(modinfo, BB_DIR_SBIN, BB_SUID_DROP))
IF_MODPROBE_SMALL(APPLET(modprobe, BB_DIR_SBIN, BB_SUID_DROP))
IF_MODPROBE_SMALL(APPLET_ODDNAME(depmod, modprobe, BB_DIR_SBIN, BB_SUID_DROP, depmod))
IF_MODPROBE_SMALL(APPLET_ODDNAME(insmod, modprobe, BB_DIR_SBIN, BB_SUID_DROP, insmod))
IF_MODPROBE_SMALL(APPLET_ODDNAME(lsmod, modprobe, BB_DIR_SBIN, BB_SUID_DROP, lsmod))
IF_MODPROBE_SMALL(APPLET_ODDNAME(rmmod, modprobe, BB_DIR_SBIN, BB_SUID_DROP, rmmod))
IF_MODPROBE(APPLET(modprobe, BB_DIR_SBIN, BB_SUID_DROP))
IF_RMMOD(APPLET(rmmod, BB_DIR_SBIN, BB_SUID_DROP))
IF_NBDCLIENT(APPLET_ODDNAME(nbd-client, nbdclient, BB_DIR_USR_SBIN, BB_SUID_DROP, nbdclient))
IF_PING(APPLET(ping, BB_DIR_BIN, BB_SUID_MAYBE))
IF_PING6(APPLET(ping6, BB_DIR_BIN, BB_SUID_MAYBE))
IF_WGET(APPLET(wget, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_WHOIS(APPLET(whois, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_IOSTAT(APPLET(iostat, BB_DIR_BIN, BB_SUID_DROP))
IF_LSOF(APPLET(lsof, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_MPSTAT(APPLET(mpstat, BB_DIR_BIN, BB_SUID_DROP))
IF_NMETER(APPLET(nmeter, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_PMAP(APPLET(pmap, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_POWERTOP(APPLET(powertop, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_PSTREE(APPLET(pstree, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_PWDX(APPLET(pwdx, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SMEMCAP(APPLET(smemcap, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_ASH(APPLET(ash, BB_DIR_BIN, BB_SUID_DROP))
IF_FEATURE_SH_IS_ASH(APPLET_ODDNAME(sh, ash, BB_DIR_BIN, BB_SUID_DROP, sh))
IF_FEATURE_BASH_IS_ASH(APPLET_ODDNAME(bash, ash, BB_DIR_BIN, BB_SUID_DROP, bash))
IF_CTTYHACK(APPLET(cttyhack, BB_DIR_BIN, BB_SUID_DROP))
IF_HUSH(APPLET(hush, BB_DIR_BIN, BB_SUID_DROP))
IF_MSH(APPLET(msh, BB_DIR_BIN, BB_SUID_DROP))
IF_FEATURE_SH_IS_HUSH(APPLET_ODDNAME(sh, hush, BB_DIR_BIN, BB_SUID_DROP, sh))
IF_FEATURE_BASH_IS_HUSH(APPLET_ODDNAME(bash, hush, BB_DIR_BIN, BB_SUID_DROP, bash))
IF_BLOCKDEV(APPLET(blockdev, BB_DIR_SBIN, BB_SUID_DROP))
IF_FATATTR(APPLET(fatattr, BB_DIR_BIN, BB_SUID_DROP))
IF_FSTRIM(APPLET(fstrim, BB_DIR_SBIN, BB_SUID_DROP))
IF_MDEV(APPLET(mdev, BB_DIR_SBIN, BB_SUID_DROP))
IF_REV(APPLET(rev, BB_DIR_BIN, BB_SUID_DROP))
IF_UEVENT(APPLET(uevent, BB_DIR_SBIN, BB_SUID_DROP))
IF_UDHCPC6(APPLET(udhcpc6, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TEST(APPLET_NOFORK([,  test, BB_DIR_USR_BIN, BB_SUID_DROP, test))
IF_TEST(APPLET_NOFORK([[, test, BB_DIR_USR_BIN, BB_SUID_DROP, test))
IF_ACPID(APPLET(acpid, BB_DIR_SBIN, BB_SUID_DROP))
IF_ADDGROUP(APPLET(addgroup, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_ADDUSER(APPLET(adduser, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_ADJTIMEX(APPLET(adjtimex, BB_DIR_SBIN, BB_SUID_DROP))
IF_ARP(APPLET(arp, BB_DIR_SBIN, BB_SUID_DROP))
IF_ARPING(APPLET(arping, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_BASENAME(APPLET_NOFORK(basename, basename, BB_DIR_USR_BIN, BB_SUID_DROP, basename))
IF_BBCONFIG(APPLET(bbconfig, BB_DIR_BIN, BB_SUID_DROP))
IF_BEEP(APPLET(beep, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_BLKID(APPLET(blkid, BB_DIR_SBIN, BB_SUID_DROP))
IF_BRCTL(APPLET(brctl, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_CAL(APPLET(cal, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CAT(APPLET_NOFORK(cat, cat, BB_DIR_BIN, BB_SUID_DROP, cat))
IF_CATV(APPLET(catv, BB_DIR_BIN, BB_SUID_DROP))
IF_CHAT(APPLET(chat, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_CHATTR(APPLET(chattr, BB_DIR_BIN, BB_SUID_DROP))
IF_CHCON(APPLET(chcon, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CHGRP(APPLET_NOEXEC(chgrp, chgrp, BB_DIR_BIN, BB_SUID_DROP, chgrp))
IF_CHMOD(APPLET_NOEXEC(chmod, chmod, BB_DIR_BIN, BB_SUID_DROP, chmod))
IF_CHOWN(APPLET_NOEXEC(chown, chown, BB_DIR_BIN, BB_SUID_DROP, chown))
IF_CHPASSWD(APPLET(chpasswd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_CHPST(APPLET(chpst, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CHROOT(APPLET(chroot, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_CHRT(APPLET(chrt, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CHVT(APPLET(chvt, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CKSUM(APPLET_NOEXEC(cksum, cksum, BB_DIR_USR_BIN, BB_SUID_DROP, cksum))
IF_CLEAR(APPLET(clear, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_COMM(APPLET(comm, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CP(APPLET_NOEXEC(cp, cp, BB_DIR_BIN, BB_SUID_DROP, cp))
/* Needs to be run by root or be suid root - needs to change /var/spool/cron* files: */
IF_CRONTAB(APPLET(crontab, BB_DIR_USR_BIN, BB_SUID_REQUIRE))
IF_CRYPTPW(APPLET(cryptpw, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CUT(APPLET_NOEXEC(cut, cut, BB_DIR_USR_BIN, BB_SUID_DROP, cut))
IF_DC(APPLET(dc, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_DD(APPLET_NOEXEC(dd, dd, BB_DIR_BIN, BB_SUID_DROP, dd))
IF_DEALLOCVT(APPLET(deallocvt, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_DELGROUP(APPLET_ODDNAME(delgroup, deluser, BB_DIR_USR_SBIN, BB_SUID_DROP, delgroup))
IF_DELUSER(APPLET(deluser, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_DEVFSD(APPLET(devfsd, BB_DIR_SBIN, BB_SUID_DROP))
IF_DEVMEM(APPLET(devmem, BB_DIR_SBIN, BB_SUID_DROP))
IF_DF(APPLET(df, BB_DIR_BIN, BB_SUID_DROP))
IF_DHCPRELAY(APPLET(dhcprelay, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_DIRNAME(APPLET_NOFORK(dirname, dirname, BB_DIR_USR_BIN, BB_SUID_DROP, dirname))
IF_DMESG(APPLET(dmesg, BB_DIR_BIN, BB_SUID_DROP))
IF_DNSD(APPLET(dnsd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_HOSTNAME(APPLET_ODDNAME(dnsdomainname, hostname, BB_DIR_BIN, BB_SUID_DROP, dnsdomainname))
IF_DOS2UNIX(APPLET_NOEXEC(dos2unix, dos2unix, BB_DIR_USR_BIN, BB_SUID_DROP, dos2unix))
IF_DU(APPLET(du, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_DUMPKMAP(APPLET(dumpkmap, BB_DIR_BIN, BB_SUID_DROP))
IF_DUMPLEASES(APPLET(dumpleases, BB_DIR_USR_BIN, BB_SUID_DROP))
//IF_E2FSCK(APPLET(e2fsck, BB_DIR_SBIN, BB_SUID_DROP))
//IF_E2LABEL(APPLET_ODDNAME(e2label, tune2fs, BB_DIR_SBIN, BB_SUID_DROP, e2label))
IF_ECHO(APPLET_NOFORK(echo, echo, BB_DIR_BIN, BB_SUID_DROP, echo))
IF_EJECT(APPLET(eject, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_ENV(APPLET_NOEXEC(env, env, BB_DIR_USR_BIN, BB_SUID_DROP, env))
IF_ENVDIR(APPLET_ODDNAME(envdir, chpst, BB_DIR_USR_BIN, BB_SUID_DROP, envdir))
IF_ENVUIDGID(APPLET_ODDNAME(envuidgid, chpst, BB_DIR_USR_BIN, BB_SUID_DROP, envuidgid))
IF_ETHER_WAKE(APPLET_ODDNAME(ether-wake, ether_wake, BB_DIR_USR_SBIN, BB_SUID_DROP, ether_wake))
IF_EXPAND(APPLET(expand, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_EXPR(APPLET(expr, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_FAKEIDENTD(APPLET(fakeidentd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FALSE(APPLET_NOFORK(false, false, BB_DIR_BIN, BB_SUID_DROP, false))
IF_FBSET(APPLET(fbset, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FBSPLASH(APPLET(fbsplash, BB_DIR_SBIN, BB_SUID_DROP))
IF_FDFLUSH(APPLET_ODDNAME(fdflush, freeramdisk, BB_DIR_BIN, BB_SUID_DROP, fdflush))
IF_FDFORMAT(APPLET(fdformat, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FDISK(APPLET(fdisk, BB_DIR_SBIN, BB_SUID_DROP))
IF_FGCONSOLE(APPLET(fgconsole, BB_DIR_USR_BIN, BB_SUID_DROP))
/* Benefits from suid root: better access to /dev/BLOCKDEVs: */
IF_FINDFS(APPLET(findfs, BB_DIR_SBIN, BB_SUID_MAYBE))
IF_FLASH_ERASEALL(APPLET(flash_eraseall, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FLASH_LOCK(APPLET_ODDNAME(flash_lock, flash_lock_unlock, BB_DIR_USR_SBIN, BB_SUID_DROP, flash_lock))
IF_FLASH_UNLOCK(APPLET_ODDNAME(flash_unlock, flash_lock_unlock, BB_DIR_USR_SBIN, BB_SUID_DROP, flash_unlock))
IF_FLASHCP(APPLET(flashcp, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FLOCK(APPLET(flock, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_FOLD(APPLET_NOEXEC(fold, fold, BB_DIR_USR_BIN, BB_SUID_DROP, fold))
IF_FREE(APPLET(free, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_FREERAMDISK(APPLET(freeramdisk, BB_DIR_SBIN, BB_SUID_DROP))
IF_FSCK(APPLET(fsck, BB_DIR_SBIN, BB_SUID_DROP))
//IF_E2FSCK(APPLET_ODDNAME(fsck.ext2, e2fsck, BB_DIR_SBIN, BB_SUID_DROP, fsck_ext2))
//IF_E2FSCK(APPLET_ODDNAME(fsck.ext3, e2fsck, BB_DIR_SBIN, BB_SUID_DROP, fsck_ext3))
IF_FSCK_MINIX(APPLET_ODDNAME(fsck.minix, fsck_minix, BB_DIR_SBIN, BB_SUID_DROP, fsck_minix))
IF_FSYNC(APPLET_NOFORK(fsync, fsync, BB_DIR_BIN, BB_SUID_DROP, fsync))
IF_FTPD(APPLET(ftpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FTPGET(APPLET_ODDNAME(ftpget, ftpgetput, BB_DIR_USR_BIN, BB_SUID_DROP, ftpget))
IF_FTPPUT(APPLET_ODDNAME(ftpput, ftpgetput, BB_DIR_USR_BIN, BB_SUID_DROP, ftpput))
IF_FUSER(APPLET(fuser, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_GETENFORCE(APPLET(getenforce, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_GETOPT(APPLET(getopt, BB_DIR_BIN, BB_SUID_DROP))
IF_GETSEBOOL(APPLET(getsebool, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_GETTY(APPLET(getty, BB_DIR_SBIN, BB_SUID_DROP))
IF_HD(APPLET_NOEXEC(hd, hexdump, BB_DIR_USR_BIN, BB_SUID_DROP, hd))
IF_HDPARM(APPLET(hdparm, BB_DIR_SBIN, BB_SUID_DROP))
IF_HEAD(APPLET_NOEXEC(head, head, BB_DIR_USR_BIN, BB_SUID_DROP, head))
IF_HEXDUMP(APPLET_NOEXEC(hexdump, hexdump, BB_DIR_USR_BIN, BB_SUID_DROP, hexdump))
IF_HOSTNAME(APPLET(hostname, BB_DIR_BIN, BB_SUID_DROP))
IF_HTTPD(APPLET(httpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_HWCLOCK(APPLET(hwclock, BB_DIR_SBIN, BB_SUID_DROP))
IF_IFCONFIG(APPLET(ifconfig, BB_DIR_SBIN, BB_SUID_DROP))
IF_IFUPDOWN(APPLET_ODDNAME(ifdown, ifupdown, BB_DIR_SBIN, BB_SUID_DROP, ifdown))
IF_IFENSLAVE(APPLET(ifenslave, BB_DIR_SBIN, BB_SUID_DROP))
IF_IFPLUGD(APPLET(ifplugd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_IFUPDOWN(APPLET_ODDNAME(ifup, ifupdown, BB_DIR_SBIN, BB_SUID_DROP, ifup))
IF_INETD(APPLET(inetd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_INOTIFYD(APPLET(inotifyd, BB_DIR_SBIN, BB_SUID_DROP))
IF_INSTALL(APPLET(install, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_IONICE(APPLET(ionice, BB_DIR_BIN, BB_SUID_DROP))
#if ENABLE_FEATURE_IP_ADDRESS \
 || ENABLE_FEATURE_IP_ROUTE \
 || ENABLE_FEATURE_IP_LINK \
 || ENABLE_FEATURE_IP_TUNNEL \
 || ENABLE_FEATURE_IP_RULE
IF_IP(APPLET(ip, BB_DIR_SBIN, BB_SUID_DROP))
#endif
IF_IPADDR(APPLET(ipaddr, BB_DIR_SBIN, BB_SUID_DROP))
IF_IPCALC(APPLET(ipcalc, BB_DIR_BIN, BB_SUID_DROP))
IF_IPCRM(APPLET(ipcrm, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_IPCS(APPLET(ipcs, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_IPLINK(APPLET(iplink, BB_DIR_SBIN, BB_SUID_DROP))
IF_IPROUTE(APPLET(iproute, BB_DIR_SBIN, BB_SUID_DROP))
IF_IPRULE(APPLET(iprule, BB_DIR_SBIN, BB_SUID_DROP))
IF_IPTUNNEL(APPLET(iptunnel, BB_DIR_SBIN, BB_SUID_DROP))
IF_KBD_MODE(APPLET(kbd_mode, BB_DIR_BIN, BB_SUID_DROP))
IF_KILL(APPLET(kill, BB_DIR_BIN, BB_SUID_DROP))
IF_KILLALL(APPLET_ODDNAME(killall, kill, BB_DIR_USR_BIN, BB_SUID_DROP, killall))
IF_KILLALL5(APPLET_ODDNAME(killall5, kill, BB_DIR_USR_SBIN, BB_SUID_DROP, killall5))
IF_KLOGD(APPLET(klogd, BB_DIR_SBIN, BB_SUID_DROP))
IF_LAST(APPLET(last, BB_DIR_USR_BIN, BB_SUID_DROP))
//IF_LENGTH(APPLET_NOFORK(length, length, BB_DIR_USR_BIN, BB_SUID_DROP, length))
IF_LESS(APPLET(less, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SETARCH(APPLET_ODDNAME(linux32, setarch, BB_DIR_BIN, BB_SUID_DROP, linux32))
IF_SETARCH(APPLET_ODDNAME(linux64, setarch, BB_DIR_BIN, BB_SUID_DROP, linux64))
IF_LN(APPLET_NOEXEC(ln, ln, BB_DIR_BIN, BB_SUID_DROP, ln))
IF_LOAD_POLICY(APPLET(load_policy, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_LOADFONT(APPLET(loadfont, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_LOADKMAP(APPLET(loadkmap, BB_DIR_SBIN, BB_SUID_DROP))
IF_LOGGER(APPLET(logger, BB_DIR_USR_BIN, BB_SUID_DROP))
/* Needs to be run by root or be suid root - needs to change uid and gid: */
IF_LOGIN(APPLET(login, BB_DIR_BIN, BB_SUID_REQUIRE))
IF_LOGNAME(APPLET_NOFORK(logname, logname, BB_DIR_USR_BIN, BB_SUID_DROP, logname))
IF_LOGREAD(APPLET(logread, BB_DIR_SBIN, BB_SUID_DROP))
IF_LOSETUP(APPLET(losetup, BB_DIR_SBIN, BB_SUID_DROP))
IF_LPD(APPLET(lpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_LPQ(APPLET_ODDNAME(lpq, lpqr, BB_DIR_USR_BIN, BB_SUID_DROP, lpq))
IF_LPR(APPLET_ODDNAME(lpr, lpqr, BB_DIR_USR_BIN, BB_SUID_DROP, lpr))
IF_LS(APPLET_NOEXEC(ls, ls, BB_DIR_BIN, BB_SUID_DROP, ls))
IF_LSATTR(APPLET(lsattr, BB_DIR_BIN, BB_SUID_DROP))
IF_LSPCI(APPLET(lspci, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_LSUSB(APPLET(lsusb, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_MAKEDEVS(APPLET(makedevs, BB_DIR_SBIN, BB_SUID_DROP))
IF_MAKEMIME(APPLET(makemime, BB_DIR_BIN, BB_SUID_DROP))
IF_MAN(APPLET(man, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_MATCHPATHCON(APPLET(matchpathcon, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_MD5SUM(APPLET_NOEXEC(md5sum, md5_sha1_sum, BB_DIR_USR_BIN, BB_SUID_DROP, md5sum))
IF_MICROCOM(APPLET(microcom, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_MKDIR(APPLET_NOFORK(mkdir, mkdir, BB_DIR_BIN, BB_SUID_DROP, mkdir))
IF_MKFS_VFAT(APPLET_ODDNAME(mkdosfs, mkfs_vfat, BB_DIR_SBIN, BB_SUID_DROP, mkfs_vfat))
IF_MKFS_EXT2(APPLET_ODDNAME(mke2fs, mkfs_ext2, BB_DIR_SBIN, BB_SUID_DROP, mkfs_ext2))
IF_MKFIFO(APPLET_NOEXEC(mkfifo, mkfifo, BB_DIR_USR_BIN, BB_SUID_DROP, mkfifo))
IF_MKFS_EXT2(APPLET_ODDNAME(mkfs.ext2, mkfs_ext2, BB_DIR_SBIN, BB_SUID_DROP, mkfs_ext2))
//IF_MKE2FS(APPLET_ODDNAME(mkfs.ext3, mke2fs, BB_DIR_SBIN, BB_SUID_DROP, mkfs_ext3))
IF_MKFS_MINIX(APPLET_ODDNAME(mkfs.minix, mkfs_minix, BB_DIR_SBIN, BB_SUID_DROP, mkfs_minix))
IF_MKFS_REISER(APPLET_ODDNAME(mkfs.reiser, mkfs_reiser, BB_DIR_SBIN, BB_SUID_DROP, mkfs_reiser))
IF_MKFS_VFAT(APPLET_ODDNAME(mkfs.vfat, mkfs_vfat, BB_DIR_SBIN, BB_SUID_DROP, mkfs_vfat))
IF_MKNOD(APPLET_NOEXEC(mknod, mknod, BB_DIR_BIN, BB_SUID_DROP, mknod))
IF_CRYPTPW(APPLET_ODDNAME(mkpasswd, cryptpw, BB_DIR_USR_BIN, BB_SUID_DROP, mkpasswd))
IF_MKSWAP(APPLET(mkswap, BB_DIR_SBIN, BB_SUID_DROP))
IF_MKTEMP(APPLET(mktemp, BB_DIR_BIN, BB_SUID_DROP))
IF_MORE(APPLET(more, BB_DIR_BIN, BB_SUID_DROP))
/* On full-blown systems, requires suid for user mounts.
 * But it's not unthinkable to have it available in non-suid flavor on some systems,
 * for viewing mount table.
 * Therefore we use BB_SUID_MAYBE instead of BB_SUID_REQUIRE: */
IF_MOUNT(APPLET(mount, BB_DIR_BIN, IF_DESKTOP(BB_SUID_MAYBE) IF_NOT_DESKTOP(BB_SUID_DROP)))
IF_MOUNTPOINT(APPLET(mountpoint, BB_DIR_BIN, BB_SUID_DROP))
IF_MT(APPLET(mt, BB_DIR_BIN, BB_SUID_DROP))
IF_MV(APPLET(mv, BB_DIR_BIN, BB_SUID_DROP))
IF_NAMEIF(APPLET(nameif, BB_DIR_SBIN, BB_SUID_DROP))
IF_NC(APPLET(nc, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_NETSTAT(APPLET(netstat, BB_DIR_BIN, BB_SUID_DROP))
IF_NICE(APPLET(nice, BB_DIR_BIN, BB_SUID_DROP))
IF_NOHUP(APPLET(nohup, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_NSLOOKUP(APPLET(nslookup, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_NTPD(APPLET(ntpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_OD(APPLET(od, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_OPENVT(APPLET(openvt, BB_DIR_USR_BIN, BB_SUID_DROP))
//IF_PARSE(APPLET(parse, BB_DIR_USR_BIN, BB_SUID_DROP))
/* Needs to be run by root or be suid root - needs to change /etc/{passwd,shadow}: */
IF_PASSWD(APPLET(passwd, BB_DIR_USR_BIN, BB_SUID_REQUIRE))
IF_PGREP(APPLET(pgrep, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_PIDOF(APPLET(pidof, BB_DIR_BIN, BB_SUID_DROP))
IF_PIPE_PROGRESS(APPLET(pipe_progress, BB_DIR_BIN, BB_SUID_DROP))
IF_PIVOT_ROOT(APPLET(pivot_root, BB_DIR_SBIN, BB_SUID_DROP))
IF_PKILL(APPLET_ODDNAME(pkill, pgrep, BB_DIR_USR_BIN, BB_SUID_DROP, pkill))
IF_POPMAILDIR(APPLET(popmaildir, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_PRINTENV(APPLET_NOFORK(printenv, printenv, BB_DIR_BIN, BB_SUID_DROP, printenv))
IF_PRINTF(APPLET_NOFORK(printf, printf, BB_DIR_USR_BIN, BB_SUID_DROP, printf))
IF_PS(APPLET(ps, BB_DIR_BIN, BB_SUID_DROP))
IF_PSCAN(APPLET(pscan, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_PWD(APPLET_NOFORK(pwd, pwd, BB_DIR_BIN, BB_SUID_DROP, pwd))
IF_RAIDAUTORUN(APPLET(raidautorun, BB_DIR_SBIN, BB_SUID_DROP))
IF_RDATE(APPLET(rdate, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_RDEV(APPLET(rdev, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_READAHEAD(APPLET(readahead, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_READLINK(APPLET(readlink, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_READPROFILE(APPLET(readprofile, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_REALPATH(APPLET(realpath, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_REFORMIME(APPLET(reformime, BB_DIR_BIN, BB_SUID_DROP))
IF_RENICE(APPLET(renice, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_RESET(APPLET(reset, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_RESIZE(APPLET(resize, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_RESTORECON(APPLET_ODDNAME(restorecon, setfiles, BB_DIR_SBIN, BB_SUID_DROP, restorecon))
IF_RM(APPLET_NOFORK(rm, rm, BB_DIR_BIN, BB_SUID_DROP, rm))
IF_RMDIR(APPLET_NOFORK(rmdir, rmdir, BB_DIR_BIN, BB_SUID_DROP, rmdir))
IF_ROUTE(APPLET(route, BB_DIR_SBIN, BB_SUID_DROP))
IF_RTCWAKE(APPLET(rtcwake, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_RUN_PARTS(APPLET_ODDNAME(run-parts, run_parts, BB_DIR_BIN, BB_SUID_DROP, run_parts))
IF_RUNCON(APPLET(runcon, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_RUNLEVEL(APPLET(runlevel, BB_DIR_SBIN, BB_SUID_DROP))
IF_RUNSV(APPLET(runsv, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_RUNSVDIR(APPLET(runsvdir, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_RX(APPLET(rx, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SCRIPT(APPLET(script, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SCRIPTREPLAY(APPLET(scriptreplay, BB_DIR_BIN, BB_SUID_DROP))
IF_SELINUXENABLED(APPLET(selinuxenabled, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SENDMAIL(APPLET(sendmail, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SEQ(APPLET_NOFORK(seq, seq, BB_DIR_USR_BIN, BB_SUID_DROP, seq))
IF_SESTATUS(APPLET(sestatus, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SETARCH(APPLET(setarch, BB_DIR_BIN, BB_SUID_DROP))
IF_SETCONSOLE(APPLET(setconsole, BB_DIR_SBIN, BB_SUID_DROP))
IF_SETENFORCE(APPLET(setenforce, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SETFILES(APPLET(setfiles, BB_DIR_SBIN, BB_SUID_DROP))
IF_SETFONT(APPLET(setfont, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SETKEYCODES(APPLET(setkeycodes, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SETLOGCONS(APPLET(setlogcons, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SETSEBOOL(APPLET(setsebool, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SETSID(APPLET(setsid, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SETUIDGID(APPLET_ODDNAME(setuidgid, chpst, BB_DIR_USR_BIN, BB_SUID_DROP, setuidgid))
IF_SHA1SUM(APPLET_NOEXEC(sha1sum, md5_sha1_sum, BB_DIR_USR_BIN, BB_SUID_DROP, sha1sum))
IF_SHA3SUM(APPLET_NOEXEC(sha3sum, md5_sha1_sum, BB_DIR_USR_BIN, BB_SUID_DROP, sha3sum))
IF_SHA256SUM(APPLET_NOEXEC(sha256sum, md5_sha1_sum, BB_DIR_USR_BIN, BB_SUID_DROP, sha256sum))
IF_SHA512SUM(APPLET_NOEXEC(sha512sum, md5_sha1_sum, BB_DIR_USR_BIN, BB_SUID_DROP, sha512sum))
IF_SHOWKEY(APPLET(showkey, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SLATTACH(APPLET(slattach, BB_DIR_SBIN, BB_SUID_DROP))
/* Do not make this applet NOFORK. It breaks ^C-ing of pauses in shells: */
IF_SLEEP(APPLET(sleep, BB_DIR_BIN, BB_SUID_DROP))
IF_SOFTLIMIT(APPLET_ODDNAME(softlimit, chpst, BB_DIR_USR_BIN, BB_SUID_DROP, softlimit))
IF_SORT(APPLET_NOEXEC(sort, sort, BB_DIR_USR_BIN, BB_SUID_DROP, sort))
IF_SPLIT(APPLET(split, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_START_STOP_DAEMON(APPLET_ODDNAME(start-stop-daemon, start_stop_daemon, BB_DIR_SBIN, BB_SUID_DROP, start_stop_daemon))
IF_STAT(APPLET(stat, BB_DIR_BIN, BB_SUID_DROP))
IF_STRINGS(APPLET(strings, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_STTY(APPLET(stty, BB_DIR_BIN, BB_SUID_DROP))
/* Needs to be run by root or be suid root - needs to change uid and gid: */
IF_SU(APPLET(su, BB_DIR_BIN, BB_SUID_REQUIRE))
IF_SULOGIN(APPLET(sulogin, BB_DIR_SBIN, BB_SUID_DROP))
IF_SUM(APPLET(sum, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SV(APPLET(sv, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SVLOGD(APPLET(svlogd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SWAPONOFF(APPLET_ODDNAME(swapoff, swap_on_off, BB_DIR_SBIN, BB_SUID_DROP, swapoff))
IF_SWAPONOFF(APPLET_ODDNAME(swapon, swap_on_off, BB_DIR_SBIN, BB_SUID_DROP, swapon))
IF_SWITCH_ROOT(APPLET(switch_root, BB_DIR_SBIN, BB_SUID_DROP))
IF_BB_SYSCTL(APPLET(sysctl, BB_DIR_SBIN, BB_SUID_DROP))
IF_SYSLOGD(APPLET(syslogd, BB_DIR_SBIN, BB_SUID_DROP))
IF_TAC(APPLET_NOEXEC(tac, tac, BB_DIR_USR_BIN, BB_SUID_DROP, tac))
IF_TAIL(APPLET(tail, BB_DIR_USR_BIN, BB_SUID_DROP))
/* IF_TC(APPLET(tc, BB_DIR_SBIN, BB_SUID_DROP)) */
IF_TCPSVD(APPLET_ODDNAME(tcpsvd, tcpudpsvd, BB_DIR_USR_BIN, BB_SUID_DROP, tcpsvd))
IF_TEE(APPLET(tee, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TELNET(APPLET(telnet, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TELNETD(APPLET(telnetd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_TEST(APPLET_NOFORK(test, test, BB_DIR_USR_BIN, BB_SUID_DROP, test))
#if ENABLE_FEATURE_TFTP_GET || ENABLE_FEATURE_TFTP_PUT
IF_TFTP(APPLET(tftp, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TFTPD(APPLET(tftpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
#endif
IF_TIME(APPLET(time, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TIMEOUT(APPLET(timeout, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TOP(APPLET(top, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TR(APPLET(tr, BB_DIR_USR_BIN, BB_SUID_DROP))
/* Needs socket(AF_INET, SOCK_RAW, IPPROTO_ICMP), therefore BB_SUID_MAYBE: */
IF_TRACEROUTE(APPLET(traceroute, BB_DIR_USR_BIN, BB_SUID_MAYBE))
IF_TRACEROUTE6(APPLET(traceroute6, BB_DIR_USR_BIN, BB_SUID_MAYBE))
IF_TRUE(APPLET_NOFORK(true, true, BB_DIR_BIN, BB_SUID_DROP, true))
IF_TTY(APPLET(tty, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TTYSIZE(APPLET(ttysize, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TUNCTL(APPLET(tunctl, BB_DIR_SBIN, BB_SUID_DROP))
IF_TUNE2FS(APPLET(tune2fs, BB_DIR_SBIN, BB_SUID_DROP))
IF_UDHCPC(APPLET(udhcpc, BB_DIR_SBIN, BB_SUID_DROP))
IF_UDHCPD(APPLET(udhcpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_UDPSVD(APPLET_ODDNAME(udpsvd, tcpudpsvd, BB_DIR_USR_BIN, BB_SUID_DROP, udpsvd))
IF_UMOUNT(APPLET(umount, BB_DIR_BIN, BB_SUID_DROP))
IF_UNAME(APPLET(uname, BB_DIR_BIN, BB_SUID_DROP))
IF_UNEXPAND(APPLET_ODDNAME(unexpand, expand, BB_DIR_USR_BIN, BB_SUID_DROP, unexpand))
IF_UNIQ(APPLET(uniq, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UNIX2DOS(APPLET_NOEXEC(unix2dos, dos2unix, BB_DIR_USR_BIN, BB_SUID_DROP, unix2dos))
IF_UPTIME(APPLET(uptime, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_USLEEP(APPLET_NOFORK(usleep, usleep, BB_DIR_BIN, BB_SUID_DROP, usleep))
IF_UUDECODE(APPLET(uudecode, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UUENCODE(APPLET(uuencode, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_VCONFIG(APPLET(vconfig, BB_DIR_SBIN, BB_SUID_DROP))
/* Needs to be run by root or be suid root - needs to change uid and gid: */
IF_VLOCK(APPLET(vlock, BB_DIR_USR_BIN, BB_SUID_REQUIRE))
IF_VOLNAME(APPLET(volname, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_WATCH(APPLET(watch, BB_DIR_BIN, BB_SUID_DROP))
IF_WATCHDOG(APPLET(watchdog, BB_DIR_SBIN, BB_SUID_DROP))
IF_WC(APPLET(wc, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_WHICH(APPLET(which, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_WHOAMI(APPLET_NOFORK(whoami, whoami, BB_DIR_USR_BIN, BB_SUID_DROP, whoami))
IF_YES(APPLET_NOFORK(yes, yes, BB_DIR_USR_BIN, BB_SUID_DROP, yes))
IF_ZCIP(APPLET(zcip, BB_DIR_SBIN, BB_SUID_DROP))

#if !defined(PROTOTYPES) && !defined(NAME_MAIN) && !defined(MAKE_USAGE) \
	&& !defined(MAKE_LINKS) && !defined(MAKE_SUID)
};
#endif

#undef APPLET
#undef APPLET_ODDNAME
#undef APPLET_NOEXEC
#undef APPLET_NOFORK
