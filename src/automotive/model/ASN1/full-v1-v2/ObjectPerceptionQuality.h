/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "ETSI-ITS-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_ObjectPerceptionQuality_H_
#define	_ObjectPerceptionQuality_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ObjectPerceptionQuality {
	ObjectPerceptionQuality_noConfidence	= 0,
	ObjectPerceptionQuality_fullConfidence	= 15
} e_ObjectPerceptionQuality;

/* ObjectPerceptionQuality */
typedef long	 ObjectPerceptionQuality_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ObjectPerceptionQuality_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ObjectPerceptionQuality;
asn_struct_free_f ObjectPerceptionQuality_free;
asn_struct_print_f ObjectPerceptionQuality_print;
asn_constr_check_f ObjectPerceptionQuality_constraint;
ber_type_decoder_f ObjectPerceptionQuality_decode_ber;
der_type_encoder_f ObjectPerceptionQuality_encode_der;
xer_type_decoder_f ObjectPerceptionQuality_decode_xer;
xer_type_encoder_f ObjectPerceptionQuality_encode_xer;
jer_type_encoder_f ObjectPerceptionQuality_encode_jer;
oer_type_decoder_f ObjectPerceptionQuality_decode_oer;
oer_type_encoder_f ObjectPerceptionQuality_encode_oer;
per_type_decoder_f ObjectPerceptionQuality_decode_uper;
per_type_encoder_f ObjectPerceptionQuality_encode_uper;
per_type_decoder_f ObjectPerceptionQuality_decode_aper;
per_type_encoder_f ObjectPerceptionQuality_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ObjectPerceptionQuality_H_ */
#include "asn_internal.h"
