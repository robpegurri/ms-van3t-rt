/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/mnt/EVO/ASN1-C-ITS/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_SpeedValueV1_H_
#define	_SpeedValueV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SpeedValueV1 {
	SpeedValueV1_standstill	= 0,
	SpeedValueV1_oneCentimeterPerSec	= 1,
	SpeedValueV1_unavailable	= 16383
} e_SpeedValueV1;

/* SpeedValueV1 */
typedef long	 SpeedValueV1_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_SpeedValueV1_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_SpeedValueV1;
asn_struct_free_f SpeedValueV1_free;
asn_struct_print_f SpeedValueV1_print;
asn_constr_check_f SpeedValueV1_constraint;
ber_type_decoder_f SpeedValueV1_decode_ber;
der_type_encoder_f SpeedValueV1_encode_der;
xer_type_decoder_f SpeedValueV1_decode_xer;
xer_type_encoder_f SpeedValueV1_encode_xer;
oer_type_decoder_f SpeedValueV1_decode_oer;
oer_type_encoder_f SpeedValueV1_encode_oer;
per_type_decoder_f SpeedValueV1_decode_uper;
per_type_encoder_f SpeedValueV1_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _SpeedValueV1_H_ */
#include "asn_internal.h"
