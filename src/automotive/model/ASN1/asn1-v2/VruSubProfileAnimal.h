/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "ETSI-ITS-CDD.asn"
 */

#ifndef	_VruSubProfileAnimal_H_
#define	_VruSubProfileAnimal_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum VruSubProfileAnimal {
	VruSubProfileAnimal_unavailable	= 0,
	VruSubProfileAnimal_wild_animal	= 1,
	VruSubProfileAnimal_farm_animal	= 2,
	VruSubProfileAnimal_service_animal	= 3,
	VruSubProfileAnimal_max	= 15
} e_VruSubProfileAnimal;

/* VruSubProfileAnimal */
typedef long	 VruSubProfileAnimal_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_VruSubProfileAnimal_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_VruSubProfileAnimal;
extern const asn_INTEGER_specifics_t asn_SPC_VruSubProfileAnimal_specs_1;
asn_struct_free_f VruSubProfileAnimal_free;
asn_struct_print_f VruSubProfileAnimal_print;
asn_constr_check_f VruSubProfileAnimal_constraint;
ber_type_decoder_f VruSubProfileAnimal_decode_ber;
der_type_encoder_f VruSubProfileAnimal_encode_der;
xer_type_decoder_f VruSubProfileAnimal_decode_xer;
xer_type_encoder_f VruSubProfileAnimal_encode_xer;
oer_type_decoder_f VruSubProfileAnimal_decode_oer;
oer_type_encoder_f VruSubProfileAnimal_encode_oer;
per_type_decoder_f VruSubProfileAnimal_decode_uper;
per_type_encoder_f VruSubProfileAnimal_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _VruSubProfileAnimal_H_ */
#include "asn_internal.h"
