#include <token.hpp>
#include <secp256k1.h>
ACTION token::hi( name nm ) {
	secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
}

EOSIO_DISPATCH( token, (hi) )