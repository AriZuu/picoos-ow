#
# Copyright (c) 2019, Ari Suutari <ari@stonepile.fi>.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#  3. The name of the author may not be used to endorse or promote
#     products derived from this software without specific prior written
#     permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
# INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.

include_guard(GLOBAL)

set(OWCOMMON ../OneWire/common)
set(OWLIB ../OneWire/lib)
set(SRC
    ${OWCOMMON}/crcutil.c
    ${OWCOMMON}/owerr.c
    ${OWCOMMON}/temp10.c
    ${OWCOMMON}/findtype.c)

if(PORT STREQUAL "unix")

list(APPEND SRC 
       ${OWLIB}/userial/Link/Linux/linuxlnk.c
       ${OWLIB}/userial/owllu.c
       ${OWLIB}/userial/owsesu.c
       ${OWLIB}/userial/ds2480ut.c
       ${OWLIB}/userial/ownetu.c
       ${OWLIB}/userial/owtrnu.c)

else()

list(APPEND SRC
       ${OWLIB}/general/ownet.c
       ${OWLIB}/general/owtran.c
       gpio_lnk.c
       gpio_ses.c)

endif()


add_peer_directory(${PICOOS_DIR})
add_peer_directory(../picoos-micro)
add_library(picoos-ow STATIC ${SRC})

target_include_directories(picoos-ow
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${OWCOMMON}
  PRIVATE ${OWLIB}/userial)

target_compile_definitions(picoos-ow PRIVATE SMALL_MEMORY_TARGET MAX_PORTNUM=1)
target_link_libraries(picoos-ow picoos-micro picoos)
