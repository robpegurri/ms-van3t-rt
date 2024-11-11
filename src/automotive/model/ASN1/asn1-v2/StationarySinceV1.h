/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "ITS-Container.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_StationarySinceV1_H_
#define	_StationarySinceV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum StationarySinceV1 {
	StationarySinceV1_lessThan1Minute	= 0,
	StationarySinceV1_lessThan2Minutes	= 1,
	StationarySinceV1_lessThan15Minutes	= 2,
	StationarySinceV1_equalOrGreater15Minutes	= 3
} e_StationarySinceV1;

/* StationarySinceV1 */
typedef long	 StationarySinceV1_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_StationarySinceV1_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_StationarySinceV1;
extern const asn_INTEGER_specifics_t asn_SPC_StationarySinceV1_specs_1;
asn_struct_free_f StationarySinceV1_free;
asn_struct_print_f StationarySinceV1_print;
asn_constr_check_f StationarySinceV1_constraint;
ber_type_decoder_f StationarySinceV1_decode_ber;
der_type_encoder_f StationarySinceV1_encode_der;
xer_type_decoder_f StationarySinceV1_decode_xer;
xer_type_encoder_f StationarySinceV1_encode_xer;
oer_type_decoder_f StationarySinceV1_decode_oer;
oer_type_encoder_f StationarySinceV1_encode_oer;
per_type_decoder_f StationarySinceV1_decode_uper;
per_type_encoder_f StationarySinceV1_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _StationarySinceV1_H_ */
#include "asn_internal.h"
