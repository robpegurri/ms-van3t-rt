/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "ETSI-ITS-CDD.asn"
 */

#ifndef	_VruSubProfileBicyclist_H_
#define	_VruSubProfileBicyclist_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum VruSubProfileBicyclist {
	VruSubProfileBicyclist_unavailable	= 0,
	VruSubProfileBicyclist_bicyclist	= 1,
	VruSubProfileBicyclist_wheelchair_user	= 2,
	VruSubProfileBicyclist_horse_and_rider	= 3,
	VruSubProfileBicyclist_rollerskater	= 4,
	VruSubProfileBicyclist_e_scooter	= 5,
	VruSubProfileBicyclist_personal_transporter	= 6,
	VruSubProfileBicyclist_pedelec	= 7,
	VruSubProfileBicyclist_speed_pedelec	= 8,
	VruSubProfileBicyclist_max	= 15
} e_VruSubProfileBicyclist;

/* VruSubProfileBicyclist */
typedef long	 VruSubProfileBicyclist_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_VruSubProfileBicyclist_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_VruSubProfileBicyclist;
extern const asn_INTEGER_specifics_t asn_SPC_VruSubProfileBicyclist_specs_1;
asn_struct_free_f VruSubProfileBicyclist_free;
asn_struct_print_f VruSubProfileBicyclist_print;
asn_constr_check_f VruSubProfileBicyclist_constraint;
ber_type_decoder_f VruSubProfileBicyclist_decode_ber;
der_type_encoder_f VruSubProfileBicyclist_encode_der;
xer_type_decoder_f VruSubProfileBicyclist_decode_xer;
xer_type_encoder_f VruSubProfileBicyclist_encode_xer;
oer_type_decoder_f VruSubProfileBicyclist_decode_oer;
oer_type_encoder_f VruSubProfileBicyclist_encode_oer;
per_type_decoder_f VruSubProfileBicyclist_decode_uper;
per_type_encoder_f VruSubProfileBicyclist_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _VruSubProfileBicyclist_H_ */
#include "asn_internal.h"
