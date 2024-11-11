/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "ETSI-ITS-CDD.asn"
 */

#ifndef	_VruSpecificExteriorLights_H_
#define	_VruSpecificExteriorLights_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum VruSpecificExteriorLights {
	VruSpecificExteriorLights_unavailable	= 0,
	VruSpecificExteriorLights_backFlashLight	= 1,
	VruSpecificExteriorLights_helmetLight	= 2,
	VruSpecificExteriorLights_armLight	= 3,
	VruSpecificExteriorLights_legLight	= 4,
	VruSpecificExteriorLights_wheelLight	= 5
} e_VruSpecificExteriorLights;

/* VruSpecificExteriorLights */
typedef BIT_STRING_t	 VruSpecificExteriorLights_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_VruSpecificExteriorLights_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_VruSpecificExteriorLights;
asn_struct_free_f VruSpecificExteriorLights_free;
asn_struct_print_f VruSpecificExteriorLights_print;
asn_constr_check_f VruSpecificExteriorLights_constraint;
ber_type_decoder_f VruSpecificExteriorLights_decode_ber;
der_type_encoder_f VruSpecificExteriorLights_encode_der;
xer_type_decoder_f VruSpecificExteriorLights_decode_xer;
xer_type_encoder_f VruSpecificExteriorLights_encode_xer;
oer_type_decoder_f VruSpecificExteriorLights_decode_oer;
oer_type_encoder_f VruSpecificExteriorLights_encode_oer;
per_type_decoder_f VruSpecificExteriorLights_decode_uper;
per_type_encoder_f VruSpecificExteriorLights_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _VruSpecificExteriorLights_H_ */
#include "asn_internal.h"
