cmake_minimum_required(VERSION 2.8.6)

project (qico C)

include(CheckTypeSize)
include(CheckIncludeFiles)
include(CheckIncludeFile)
include(CheckSymbolExists)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    "src"
)

CHECK_TYPE_SIZE(char SIZEOF_CHAR)
CHECK_TYPE_SIZE(short SIZEOF_SHORT)
CHECK_TYPE_SIZE(int SIZEOF_INT)
CHECK_TYPE_SIZE(long SIZEOF_LONG)

CHECK_INCLUDE_FILES("stdarg.h;stdlib.h;stddef.h;string.h" STDC_HEADERS)
CHECK_INCLUDE_FILE("sys/types.h" HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILE("sys/time.h" HAVE_SYS_TIME_H)
CHECK_INCLUDE_FILE("stdlib.h" HAVE_STDLIB_H)
CHECK_INCLUDE_FILE("errno.h" HAVE_ERRNO_H)
CHECK_INCLUDE_FILE("netinet/in.h" HAVE_NETINET_IN_H)
CHECK_INCLUDE_FILE("netdb.h" HAVE_NETDB_H)
CHECK_INCLUDE_FILE("fcntl.h" HAVE_FCNTL_H)
CHECK_INCLUDE_FILE("utime.h" HAVE_UTIME_H)
CHECK_INCLUDE_FILE("syslog.h" HAVE_SYSLOG_H)
CHECK_INCLUDE_FILE("termios.h" HAVE_TERMIOS_H)
CHECK_INCLUDE_FILE("termio.h" HAVE_TERMIO_H)
CHECK_INCLUDE_FILE("unistd.h" HAVE_UNISTD_H)
CHECK_INCLUDE_FILE("dirent.h" HAVE_DIRENT_H)
CHECK_INCLUDE_FILE("sys/socket.h" HAVE_SYS_SOCKET_H)
check_include_file (sys/time.h       HAVE_SYS_TIME_H)
check_include_file (time.h           HAVE_TIME_H)
check_include_file (ncurses.h           HAVE_NCURSES_H)
CHECK_INCLUDE_FILES("sys/time.h;time.h" TIME_WITH_SYS_TIME)
check_include_file (sys/stat.h       HAVE_SYS_STAT_H)
check_include_file (arpa/inet.h       HAVE_ARPA_INET_H)

check_symbol_exists(mvvline ncurses.h CURS_HAVE_MVVLINE)

set(DEFAULT_SPEED 9600 CACHE STRING "default modem speed" FORCE)
set(TCP_SPEED 115200 CACHE STRING "tcp speed" FORCE)
set(MAX_STRING 512 CACHE STRING "Maximum length of standard string" FORCE)
set(MAX_NODELIST 32 CACHE STRING "Maximum length of nodelist" FORCE)
set(CONFIG "/etc/qico.conf" CACHE STRING "specifies config filename" FORCE)
set(HAVE_SYSLOG_FAC_NAMES 1 CACHE STRING "have facility names" FORCE)
set(HAVE_SYSLOG_PRI_NAMES 1 CACHE STRING "have priority names" FORCE)
set(PACKAGE_NAME ${CMAKE_PROJECT_NAME})
set(PACKAGE_VERSION 0.59.2)

set (CURSES_NEED_WIDE TRUE)
include(FindCurses)
include(FindPerlLibs)
if (${PERLLIBS_FOUND})
	set(WITH_PERL 1)
	include_directories(${PERL_INCLUDE_PATH})
endif (${PERLLIBS_FOUND})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake.h ${CMAKE_CURRENT_BINARY_DIR}/config.h)

add_subdirectory(src)
#add_subdirectory(tests)

