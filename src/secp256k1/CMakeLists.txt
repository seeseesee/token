project(secp256k1)

include_directories("/usr/local/Cellar/gmp/6.1.2_2/include")
link_directories("/usr/local/Cellar/gmp/6.1.2_2/lib")

add_library(secp256k1 STATIC
  upstream/src/secp256k1.c
)

target_include_directories(secp256k1
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src/modules/aggsig
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src/modules/bulletproofs
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src/modules/commitment
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src/modules/ecdh
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src/modules/generator
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src/modules/rangeproof
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src/modules/recovery
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src/modules/schnorrsig
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src/modules/surjection
        ${CMAKE_CURRENT_SOURCE_DIR}/upstream/src/modules/whitelist
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${GMP_INCLUDE_DIR}
)

target_compile_definitions(secp256k1 PRIVATE HAVE_CONFIG_H=1)

target_link_libraries(secp256k1 ${GMP_LIBRARIES})
install( TARGETS secp256k1 
   RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
   LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
   ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
)
