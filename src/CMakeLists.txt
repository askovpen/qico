find_package(FLEX REQUIRED)

find_package(BISON REQUIRED)

if (${PERLLIBS_FOUND})
  set(perl_SRC perl.c)
endif (${PERLLIBS_FOUND})

set(qico_SOURCES call.c clserv.c config.c crc.c daemon.c 
emsi.c freq.c ftn.c globals.c hydra.c janus.c log.c 
ls_zglue.c ls_zmodem.c ls_zreceive.c ls_zsend.c main.c md5q.c 
modem.c nodelist.c outbound.c protfm.c qconf.c qipc.c 
queue.c qslib.c session.c slists.c tcp.c tools.c tty.c 
binkp.c ${perl_SRC}
)

set(qctl_SOURCES qctl.c clserv.c md5q.c qslib.c)

set(qcc_SOURCES qcc.c clserv.c md5q.c qslib.c)

flex_target(lexer flaglex.l "${CMAKE_CURRENT_BINARY_DIR}/flaglex.c")
bison_target(parser flagexp.y "${CMAKE_CURRENT_BINARY_DIR}/flaglexp.c")
add_executable(qico ${qico_SOURCES}
	"${CMAKE_CURRENT_BINARY_DIR}/flaglex.c"
	"${CMAKE_CURRENT_BINARY_DIR}/flaglexp.c"
)
if (${PERLLIBS_FOUND})
	target_link_libraries(qico ${PERL_LIBRARY})
endif (${PERLLIBS_FOUND})

add_executable(qctl ${qctl_SOURCES})
add_executable(qcc ${qcc_SOURCES})
target_link_libraries(qcc ${CURSES_NCURSES_LIBRARY} ${CURSES_EXTRA_LIBRARY})