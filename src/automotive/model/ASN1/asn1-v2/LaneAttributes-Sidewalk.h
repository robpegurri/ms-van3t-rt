/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in asn1/ISO19091.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_LaneAttributes_Sidewalk_H_
#define	_LaneAttributes_Sidewalk_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LaneAttributes_Sidewalk {
	LaneAttributes_Sidewalk_sidewalk_RevocableLane	= 0,
	LaneAttributes_Sidewalk_bicyleUseAllowed	= 1,
	LaneAttributes_Sidewalk_isSidewalkFlyOverLane	= 2,
	LaneAttributes_Sidewalk_walkBikes	= 3
} e_LaneAttributes_Sidewalk;

/* LaneAttributes-Sidewalk */
typedef BIT_STRING_t	 LaneAttributes_Sidewalk_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_LaneAttributes_Sidewalk_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_LaneAttributes_Sidewalk;
asn_struct_free_f LaneAttributes_Sidewalk_free;
asn_struct_print_f LaneAttributes_Sidewalk_print;
asn_constr_check_f LaneAttributes_Sidewalk_constraint;
ber_type_decoder_f LaneAttributes_Sidewalk_decode_ber;
der_type_encoder_f LaneAttributes_Sidewalk_encode_der;
xer_type_decoder_f LaneAttributes_Sidewalk_decode_xer;
xer_type_encoder_f LaneAttributes_Sidewalk_encode_xer;
jer_type_encoder_f LaneAttributes_Sidewalk_encode_jer;
oer_type_decoder_f LaneAttributes_Sidewalk_decode_oer;
oer_type_encoder_f LaneAttributes_Sidewalk_encode_oer;
per_type_decoder_f LaneAttributes_Sidewalk_decode_uper;
per_type_encoder_f LaneAttributes_Sidewalk_encode_uper;
per_type_decoder_f LaneAttributes_Sidewalk_decode_aper;
per_type_encoder_f LaneAttributes_Sidewalk_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _LaneAttributes_Sidewalk_H_ */
#include "asn_internal.h"
