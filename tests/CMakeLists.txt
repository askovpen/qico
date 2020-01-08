
include_directories(                                                                                                                                                                                         
  ${CMAKE_CURRENT_BINARY_DIR}                                                                                                                                                                                
)
flex_target(lexer ../src/flaglex.l "${CMAKE_CURRENT_BINARY_DIR}/flaglex.c")                                                                                                                                         
bison_target(parser ../src/flagexp.y "${CMAKE_CURRENT_BINARY_DIR}/flaglexp.c" DEFINES_FILE "${CMAKE_CURRENT_BINARY_DIR}/flagexp.h")

find_package(CMocka)
include_directories(${CMOCKA_INCLUDE_DIR})
if (${PERLLIBS_FOUND})                                                                                                                                                                                       
  set(perl_SRC ../src/perl.c)                                                                                                                                                                                       
endif (${PERLLIBS_FOUND})

set(test1_src test1.c
../src/call.c 
../src/clserv.c 
../src/config.c 
../src/crc.c 
../src/daemon.c 
../src/emsi.c 
../src/freq.c 
../src/ftn.c 
../src/globals.c 
../src/hydra.c 
../src/janus.c 
../src/log.c 
../src/ls_zglue.c 
../src/ls_zmodem.c 
../src/ls_zreceive.c 
../src/ls_zsend.c 
../src/md5q.c 
../src/modem.c 
../src/nodelist.c 
../src/outbound.c 
../src/protfm.c 
../src/qconf.c 
../src/qipc.c 
../src/queue.c 
../src/qslib.c 
../src/session.c 
../src/slists.c 
../src/tcp.c 
../src/tools.c 
../src/tty.c 
../src/binkp.c
"${CMAKE_CURRENT_BINARY_DIR}/flaglex.c"
"${CMAKE_CURRENT_BINARY_DIR}/flaglexp.c"
${perl_SRC}
)
ADD_DEFINITIONS(-g -DDEBUG -D_DEBUG)
add_executable(test1 ${test1_src})
TARGET_LINK_LIBRARIES(test1 ${CMOCKA_LIBRARY} dl)
if (${PERLLIBS_FOUND})                                                                                                                                                                                       
target_link_libraries(test1 ${PERL_LIBRARY} -lpthread)                                                                                                                                                                
endif (${PERLLIBS_FOUND})

add_test(test1 ${CMAKE_CURRENT_BINARY_DIR}/test1)