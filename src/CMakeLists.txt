project(token)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_subdirectory(secp256k1)

add_contract( token token token.cpp )
target_link_libraries(token secp256k1)

target_include_directories( token PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( token ${CMAKE_SOURCE_DIR}/../ricardian )

