/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/mnt/EVO/ASN1-C-ITS/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_InformationQualityV1_H_
#define	_InformationQualityV1_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum InformationQualityV1 {
	InformationQualityV1_unavailable	= 0,
	InformationQualityV1_lowest	= 1,
	InformationQualityV1_highest	= 7
} e_InformationQualityV1;

/* InformationQualityV1 */
typedef long	 InformationQualityV1_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_InformationQualityV1_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_InformationQualityV1;
asn_struct_free_f InformationQualityV1_free;
asn_struct_print_f InformationQualityV1_print;
asn_constr_check_f InformationQualityV1_constraint;
ber_type_decoder_f InformationQualityV1_decode_ber;
der_type_encoder_f InformationQualityV1_encode_der;
xer_type_decoder_f InformationQualityV1_decode_xer;
xer_type_encoder_f InformationQualityV1_encode_xer;
oer_type_decoder_f InformationQualityV1_decode_oer;
oer_type_encoder_f InformationQualityV1_encode_oer;
per_type_decoder_f InformationQualityV1_decode_uper;
per_type_encoder_f InformationQualityV1_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _InformationQualityV1_H_ */
#include "asn_internal.h"
