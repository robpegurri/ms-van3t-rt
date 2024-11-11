/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "ITS-Container.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TemperatureV1_H_
#define	_TemperatureV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TemperatureV1 {
	TemperatureV1_equalOrSmallerThanMinus60Deg	= -60,
	TemperatureV1_oneDegreeCelsius	= 1,
	TemperatureV1_equalOrGreaterThan67Deg	= 67
} e_TemperatureV1;

/* TemperatureV1 */
typedef long	 TemperatureV1_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_TemperatureV1_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_TemperatureV1;
asn_struct_free_f TemperatureV1_free;
asn_struct_print_f TemperatureV1_print;
asn_constr_check_f TemperatureV1_constraint;
ber_type_decoder_f TemperatureV1_decode_ber;
der_type_encoder_f TemperatureV1_encode_der;
xer_type_decoder_f TemperatureV1_decode_xer;
xer_type_encoder_f TemperatureV1_encode_xer;
oer_type_decoder_f TemperatureV1_decode_oer;
oer_type_encoder_f TemperatureV1_encode_oer;
per_type_decoder_f TemperatureV1_decode_uper;
per_type_encoder_f TemperatureV1_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _TemperatureV1_H_ */
#include "asn_internal.h"
