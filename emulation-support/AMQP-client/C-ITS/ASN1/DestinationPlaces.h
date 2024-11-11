/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "GDD"
 * 	found in "/mnt/EVO/ASN1-C-ITS/GDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_DestinationPlaces_H_
#define	_DestinationPlaces_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DestinationPlace;

/* DestinationPlaces */
typedef struct DestinationPlaces {
	A_SEQUENCE_OF(struct DestinationPlace) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DestinationPlaces_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DestinationPlaces;
extern asn_SET_OF_specifics_t asn_SPC_DestinationPlaces_specs_1;
extern asn_TYPE_member_t asn_MBR_DestinationPlaces_1[1];
extern asn_per_constraints_t asn_PER_type_DestinationPlaces_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DestinationPlace.h"

#endif	/* _DestinationPlaces_H_ */
#include "asn_internal.h"
